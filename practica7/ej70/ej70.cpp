#include<iostream>
#include<fstream>
using namespace std;

//void printfl(){
//    ifstream fl;
//    fl.open(file_txt);

//}

int main(){
    string nom, ape, linea;
    ofstream fl;
    cout << "ing nombres. escriba un punto para salir "<<endl;
    fl.open("ej70.txt"); 
    cin >> nom ;
    while (nom !="."){
        cout << "ingrese apellido:"<<endl;
        cin >> ape;
        fl << nom << " " << ape << endl;
        cout << "ing nombres. escriba un punto para salir "<<endl;
        cin >> nom ;
    }
    fl.close();

    ifstream flr;
    flr.open("ej70.txt");
    while (!flr.eof()){
        getline (flr, linea);
        cout << linea << endl;
    }
    flr.close();
    cout << "byebye" << endl;
    return 0;
}

