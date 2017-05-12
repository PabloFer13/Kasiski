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

int encuentra(char c, char *arr){
    int i = 0;
    while(arr[i] != c){
        i++;
    }
    return i;
}

int main() {

    string text;
    string aux;
    string clave = "";
    vector<int> distancias;
    bool bandera = true;
    int gcd, n, resp, fMax, mPos, a1,a2;
    int frecuencias[27];
    inicializa(frecuencias, 27);
    getline(cin,text);
    char letras[27];
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

    for(int i = 0; i < 27; i++){
        if(i == 14){
            letras[i] = 165;
        }else if(i > 14){
            letras[i] = 64 + i;
        }else{
            letras[i] = 65 + i;
        }
    }
    aux = "";
    //decodificar
    for(int i = 0; i < text.size(); i++){

        a1 = i % gcd;
        a1 = encuentra(clave[a1], letras);
        a2 = encuentra(text[i], letras);

        /*if(a2 > 14 && (a2-a1) < 14){
            a1--;
        }*/
        aux.push_back(letras[((a2 - a1) + 26) % 26]);
    }
    cout << aux;
    return 0;
}