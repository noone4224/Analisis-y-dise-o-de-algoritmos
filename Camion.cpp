#include <fstream>
#include<ctime>
#include <chrono>
#include <iomanip>
#include <queue>
#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
#include "time.h"
using namespace std;

int paradas(int distancia, int tanque, const int n, int * arrayKilometros, bool * arrayParadas){
    int i = 0;
    int kmRecorridos = 0;
    int paradas = 0;
    int ultima = 0;

    if(tanque < arrayKilometros[0]){
        return -1;
    }
    while((ultima + tanque < distancia) && (i <= n - 1)){
        kmRecorridos = arrayKilometros[i] - ultima;
        if(kmRecorridos > tanque){
            ultima = arrayKilometros[i-1];
            arrayParadas[i-1] = true;
            paradas++;
            kmRecorridos = 0;
        }
        i++;
    }

    if(ultima + tanque >= distancia){
        return paradas;
    } 
    else{
        return -1;
    }
}
int main(){
    int distancia = 1000;

    int tanque;
    cout<<"Dime la capacidad del tanque ";
    cin>>tanque;

    const int n = 10;
    string arrayNombres[n]={"Santa cruz", "Santo Thomas", "San Juan", "San Jose", "Entrada a cuernavaca", "Guerrero","Santa Maria","Rincon de la cocina","Periferico","Salida de cuernavaca"};
    int arrayKilometros[n] = {50,230,250,340,490,520,630,780,830,900};
    bool arrayParadas[n] = {false};
    int resultado = paradas(distancia, tanque, n, arrayKilometros, arrayParadas);
 
    cout << "Numero de paradas: " << resultado << endl;
    
    if (resultado > -1){
        for(int i = 0; i < n; i++){
            if (arrayParadas[i] == true){
                cout << "Parada en la gasolineria de " << arrayNombres[i] << "que esta en el kilometro " <<arrayKilometros[i]<< endl;
            }
        }
    } 
    else {
        cout << "El camion no puedo completar el viaje" << endl;
    }

    return 0;
}

