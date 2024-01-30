#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <cctype>

using namespace std;

string soloAlfanumericos(const string& input) {
    string resultado;

    for (char c : input) {
        if (isalnum(c)) {
            resultado.push_back(c);
        }
    }

    return resultado;
}

int main() {
    int n, q;
    cin>>n>>q;

    cin.ignore();

    vector<string> HRML(n);
    vector<string> querys(q);

    vector<vector<string>> hrml_words;
    vector<vector<string>> query_words;

    unordered_map<string, unordered_map<string, string>> hrml_map;

    for (int i = 0; i < n; i++) {
        getline(cin, HRML[i]);

        stringstream ss(HRML[i]);

        vector<string> words;
        string word;

        while (ss>>word)
            words.push_back(word);

        hrml_words.push_back(words);
    }

    for (int i = 0; i < hrml_words.size()/2; i++){
        string tag = hrml_words[i][0].substr(1, hrml_words[i][0].size());
        hrml_map[tag] = unordered_map<string, string>();

        for (int j = 1; j < hrml_words[i].size()-2; j+=3) {
            string attribute = hrml_words[i][j];
            string value = soloAlfanumericos(hrml_words[i][j+2]);

            hrml_map[tag][attribute] = value;
        }
    }

    for (int i = 0; i < q; i++) {
        getline(cin, querys[i]);
        stringstream ss(querys[i]);

        vector<string> words;
        string word;

        while(getline(ss, word, '.'))
            words.push_back(word);

        query_words.push_back(words);
    }

    for (int i = 0; i < query_words.size(); i++){
        stringstream ss(query_words[i].back());

        vector<string> words;
        string word;

        while(getline(ss, word, '~'))
            words.push_back(word);

        string tag = words[0];
        string attribute = words[1];

        if (hrml_map.find(tag) != hrml_map.end()) {
            if (hrml_map[tag].find(attribute) != hrml_map[tag].end()) {
                cout << hrml_map[tag][attribute] << endl;
            } else {
                cout << "Not Found!" << endl;
            }
        } else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}
