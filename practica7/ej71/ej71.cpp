#include<iostream>
#include<fstream>
using namespace std;

void cargar_archivo(){
    int cant;
    string dni;
    ofstream flw;
    flw.open("ej71.txt");
    cout << "ing dni. escriba un punto para salir "<<endl;
    cin >> dni;
    while (dni !="."){
        cout << "cant. unidades a comprar" << endl;
        cin >> cant;
        if (cant > 10){
            flw << dni << " " << cant << endl;
            cout << "ing dni. escriba un punto para salir "<<endl;
            cin >> dni;
        }
        else{ 
            cout << "ing dni. escriba un punto para salir "<<endl;
            cin >> dni;
        }
    }
    flw.close();
}

void imprimir(){
    string tmp;
    ifstream flr;
    flr.open("ej71.txt");
    while(!flr.eof()){
    getline(flr, tmp);
    cout << tmp << endl;
    }
    flr.close();
}
int main(){
    cargar_archivo();
    imprimir();
return 0;
}