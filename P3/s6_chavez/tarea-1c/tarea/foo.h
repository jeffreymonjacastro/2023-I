#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool comparePairs(const pair<string, int>& a, const pair<string, int>& b);

struct Counter{
    vector<string> content; // Las palabras del html


    // Leer el html
    explicit Counter(const string& url){
        // todo: Código para leer el html como un archivo


        string richtext;

ifstream doc("../tarea/document.txt", ios::in);

        if (doc.is_open()) {
            string linea;

            while (getline(doc, linea))
                richtext += linea + " ";

            doc.close();

        } else {
            cout << "No se pudo abrir el archivo" << endl;
        }

        // todo: Para quitar todo lo que está arriba del <head>

        string newtext;

        auto it = richtext.begin();
        while (it != richtext.end()) {
            if (string(it, it+5) == "<body") {
                richtext.erase(richtext.begin(), it);
                break;
            }
            ++it;
        }


        // todo: Código para eliminar las etiquetas <html>

        bool pos = true;

        for (auto it = richtext.begin(); it != richtext.end(); it++) {
            if (*it == '<') {
                pos = false;
            } else if (pos) {
                if (*it == '\n' || *it == '\'')
                    newtext += " ";
                else
                    newtext += *it;
            } else if (*it == '>' && !pos) {
                pos = true;
            }
        }


        // todo: Código para leer solamente alfanuméricos con RegEx

        string prolijtext;

        regex pattern1("[a-z A-Z]");

        sregex_iterator iter1(newtext.begin(), newtext.end(), pattern1);
        sregex_iterator end1;

        while (iter1 != end1){
            prolijtext += iter1->str();
            iter1++;
        }

        // todo: Código para separar cada palabra del string y ponerlo en un vector con RegEx

        regex pattern2("\\s+");

        sregex_token_iterator iter2(prolijtext.begin(), prolijtext.end(), pattern2, -1);
        sregex_token_iterator end2;

        for (; iter2 != end2; ++iter2) {
            content.push_back(*iter2);
        }

        // todo: Código para poner en minúscula cada palabra del vector

        for (auto it = content.begin(); it != content.end(); it++)
            transform(it->begin(), it->end(), it->begin(),
                      [](char c) { return tolower(c); });
    }


    // Buscar la frecuencia de una palabra
    int operator()(string s){
        map<string, int> search_word;

        vector<string> conn = {"the", "for", "was", "and", "that", "but", "had", "you", "she", "all", "with", "could", "some", "from", "not", "can", "her", "just", "know", "would", "there", "what", "they"};

        for(auto it = content.begin(); it != content.end(); it++) {
            if(it->size() > 2 && find(conn.begin(), conn.end(), *it) == conn.end()) {
                search_word[*it]++;
            }
        }

        for (auto it = search_word.begin(); it != search_word.end(); it++){
            if (s == it->first){
                return it->second;
            }
        }

        return 0;
    }


    // Encontrar el ranking de los 5 primeros
    vector<string> ranking(){
        vector<string> v(5,"None");
        vector<string> conn = {"the", "for", "was", "and", "that", "but", "had", "you", "she", "all", "with", "could", "some", "from", "not", "can", "her", "just", "know", "would", "there", "what", "they"};

        map<string, int> word_count;

        for(auto it = content.begin(); it != content.end(); it++) {
            if(it->size() > 2 && find(conn.begin(), conn.end(), *it) == conn.end()) {
                word_count[*it]++;
            }
        }

        vector<pair<string,int>> ordered(word_count.begin(), word_count.end());

        sort(ordered.begin(), ordered.end(), comparePairs);


        for (int i = 0; i < 5; ++i) {
            v[i] = ordered[i].first;
        }

        return v;
    }
};