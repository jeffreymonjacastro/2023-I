#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Counter{
    vector<string> content;

    Counter(string url){
        // todo: Código para leer el html como un archivo

        string richtext;

        ifstream doc(url);

        if (doc.is_open()) {
            string linea;

            while (getline(doc, linea))
                richtext += linea + "\n";

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
                if (*it == '\n')
                    newtext += " ";
                else
                    newtext += *it;
            } else if (*it == '>' && !pos) {
                pos = true;
            }
        }


        // todo: Código para leer solamente alfanuméricos (y ') con RegEx

        string prolijtext;

        regex pattern1("[a-z A-Z \\']");

        sregex_iterator iter1(newtext.begin(), newtext.end(), pattern1);
        sregex_iterator end1;

        while (iter1 != end1){
            prolijtext += iter1->str();
            iter1++;
        }


        // todo: Código para separar cada palabra del string y ponerlo en un vector

        regex pattern2("\\s+");

        sregex_token_iterator iter2(prolijtext.begin(), prolijtext.end(), pattern2, -1);
        sregex_token_iterator end2;

        for (; iter2 != end2; ++iter2) {
            content.push_back(*iter2);
        }
    }

    // Buscar la frecuencia de una palabra
    int operator()(string s){
        map<string, int> search_word;

        string word;

        for(auto it = content.begin(); it != content.end(); it++) {
            if (word.begin() == word.end())
                break;

            for (auto it = word.begin(); it != word.end(); ++it)
                *it = tolower(*it);

            word_count[word]++;
        }

        for (const auto &w : word_count){
            cout << w.first << ": ";
            cout << w.second;
            cout << (w.second > 1 ? " veces" : " vez") << endl;
        }
        return -1;
    }

    vector<string> ranking(){
        // TODO
        vector<string> v(5,"None");
        return v;
    }
};