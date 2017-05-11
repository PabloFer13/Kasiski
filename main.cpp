#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map <string,vector<int>> sub;
int frecuencias[27];

void inicializa(int *arr, int tam){
    for(int i = 0; i < tam; i++){
        arr[i] = 0;
    }
}

int main() {

    string text;
    string aux;
    string clave = "";
    vector<int> distancias;
    bool bandera = true;
    int gcd, n, resp, fMax, mPos, resta;
    int frecuencias[27];
    inicializa(frecuencias, 27);
    getline(cin,text);
    for(int i = 0; i < text.size()-2; i++){
        aux = text.substr(i,3);
        sub.find(aux) == sub.end() ? sub[aux].push_back(i) : sub.find(aux)->second.push_back(i);
    }
    for(map<string,vector<int>>::iterator ptr = sub.begin(); ptr != sub.end(); ++ptr){
        if(ptr->second.size() > 1){
            for(int i = 1; i < ptr->second.size(); i++) {
                distancias.push_back(ptr->second.at(i) - ptr->second.at(i-1));
            }
        }
    }

    gcd = __gcd(distancias[distancias.size()-1], distancias[distancias.size() -2]);
    for(int i = distancias.size()-3; i >= 0; i--){
        gcd = __gcd(max(distancias[i], gcd), min(distancias[i], gcd));
    }
    
    n = 0;
    resp = gcd;
    while(resp--){
        bandera = true;
        fMax = 0;
        mPos = 0;
        for(int i = n; i < text.size(); i+= gcd){
            aux.clear();
            aux.push_back(text[i]);
            frecuencias[text[i] == '\245' ? 79-65 : text[i] >= 79 ? (text[i]+1) - 65 : text[i]-65]++;
//            text[i] == '\245' ? printf("Llega egne") : text[i] >= 79 ? printf("Si true segundo") : printf("false segundo");
        }
        for(int i = 0; i < 27 && bandera; i++){
            if(frecuencias[i] > 0){
                if(frecuencias[(i+4)%27] > 0){
                    if(frecuencias[(i+15)%27] > 0){
                        if((frecuencias[i]+frecuencias[(i+4)%27]+frecuencias[(i+15)%27]) > fMax){
                            fMax = (frecuencias[i]+frecuencias[(i+4)%27]+frecuencias[(i+15)%27]);
                            mPos = i;
                        }
                    }
                }
            }
        }
        n++;
        clave.push_back((79-65) == mPos ? '\245' : mPos >= 15 ? (mPos-1)+65 : mPos+65);
        inicializa(frecuencias, 27);
    }

    cout << clave << endl;

    for(int i = 0; i < text.size(); i++){
        bandera = false;
        if(clave[i%gcd] >= 79){
            resta = clave[i%gcd]+1-65;
        }else{
            resta = clave[i%gcd] - 65;
        }
        if(text[i] >= 79){
            text[i]++;
            bandera = true;
        }
        if(text[i] - resta < 65){
            text[i] += 27;
        }
        text[i] -= resta;
        if(bandera){
            text[i]--;
        }
        cout << text[i];
    }

    return 0;
}