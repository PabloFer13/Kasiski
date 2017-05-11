#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

map <string,vector<int>> sub;
int main() {

    string text;
    string aux;
    getline(cin,text);
    for(int i = 0; i < text.size()-2; i++){
        aux = text.substr(i,3);
        sub.find(aux) == sub.end() ? sub[aux].push_back(i) : sub.find(aux)->second.push_back(i);
    }
    for(map<string,vector<int>>::iterator ptr = sub.begin(); ptr != sub.end(); ++ptr){
        if(ptr->second.size() > 1){
            cout << ptr->first << " se repite: " << ptr->second.size() << endl;
            for(int i = 0; i < ptr->second.size(); i++){
                cout << ptr->second.at(i) << " -- ";
            }
            cout << endl;
        }
    }
    /** sub["abc"].push_back(5);
    sub.find("abc")->second.push_back(6);
    cout << sub["abc"][0] << '\n' << sub["abc"][1]; */
    return 0;
}