/*
    Implementacion de funciones de estado para la ejecución de un 
    automata finito deterministico para la validacion de  expresiones regular iguales a regex = a*b(c*|d)

*/

#include<iostream>
#include<fstream>
using namespace std;


string word=""; //almacenamiento de expresion valida


/*Funciones de estado*/
void q1(string, int);
void q2(string, int);
void q3(string, int);
void q4(string, int);
int AFD(string,int);




int main(){

    ifstream inputFile("text.txt");

    if(!inputFile.is_open()){
        cout<<"no se encontro el archivo";
        return 501;
    }

    string line=""; 

    getline(inputFile,line); // obtencion de linea de entrada

   bool flag=false;

    for (int i = 0; i < line.length(); i++)
    {
     
       
        
       if(AFD(line,i)>0){
        cout<<word<<" es valido"<<endl<<endl;
       }
       else{
        flag=true;
        cout<<"no es valido ";
       }

        //Paso a la siguiente expresion separa por espacio
       while(line[i]!=32){
            if(flag) cout<<line[i];
            
            if(i>=line.length()) break;

            if(line[i+1]==32&&flag) {flag=false; cout<<endl<<endl;}
            i++;
       }
      
        

    }
    
    return 0;
}

void q1(string line,int i){

    char a=line[i];
    
    if(a==97){
        word+=a;
        
        q1(line,i+1);
    }else if(a==98){
        word+=a;
        q2(line, i+1);
    }
    else{
        word="";
        throw -1;
    }
}
void q2(string line, int i){
    char a=line[i];
  
    if(a==99){
        word+=a;
        q3(line,i+1);
    }else if(a==100){
        word+=a;
        q4(line,i+1);
    }
    else{
        word="";
        throw -1;
    }
}
void q3(string line,int i){
  
    char a=line[i];
    if(a==99){
        word+=a;
        q3(line,i+1);
    }
    else{
       
        throw 1;
    }
}
void q4(string line, int i){


   throw 1;
}

int AFD(string line,int i){
    try{
        q1(line,i);
    }
    catch(int e){
        return e; // retorno de estado de validacion: -1 -> expresion no valida; 1 -> expresion valida
    }
    return 1;
}