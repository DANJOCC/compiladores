/*
    Implementacion de una tabla de transiciones para la ejecución de un 
    automata finito deterministico para la validacion de  expresiones regular iguales a regex = a*b(c*|d)

*/


#include<iostream>
#include<fstream>
#include "./matrix.h"

using namespace std;

int main(){

    ifstream inputFile("text.txt");

    if(!inputFile.is_open()){
        cout<<"no se encontro el archivo";
        return 501;
    }

    string line;

    getline(inputFile,line); // obtencion de linea de entrada

    int validate=0; // Estado de validacion de la expresion regular 0 -> expresion no valida; 1 -> expresion valida

    string word=""; // Almacenamiento de expresion regular
    
    char car='$'; // Almacenamiento de caracter procesado
    
    int state=0; // estado del automata

    for (int i = 0; i < line.length(); i++)
    {
     
        car=line[i];
        
        if(   97>car || 122<car  || car==32 || car-97>NUMCAR-2||state==-1){ // validacion de expresion
         if(validate==1){
                 cout<<word<<endl;
         }
            //reinicio de variables

            word="";
            state=0;
            validate=0;
            car='g';
        
            continue;   
        }
       
       //cambio de estados

        state=matrix[state][car-97];
        validate=matrix[state][NUMCAR-1];
   
        // estado de error
        if(state==-1){
           i--;
            continue;
        }
        
       word+=line[i];
      

    }
     if(validate==1){
                 cout<<word<<endl;
        }
    return 0;
}