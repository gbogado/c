#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct t_alu{
    char nomb[10];
    int edad;
};
void generar_archivo(){
    t_alu tmp;
    FILE *fl;
    fl=fopen("ej80.dat","wb");
    cout<<"Ingresar nombre. (quit) para terminar" <<endl;
    cin.ignore();
    cin.getline(tmp.nomb,10);
    while(strcmp(tmp.nomb,"quit") != 0){
        cout<<"Ingresar edad "<<endl;
        cin>>tmp.edad;
        fwrite(&tmp,sizeof(tmp),1,fl);
        cout<<"Ingresar nombre. (quit) para terminar" <<endl;
        cin.ignore();
        cin.getline(tmp.nomb,10);
    }
    fclose(fl);
}

void leer(){
    t_alu vec[50]; int x=0;
    FILE *fl;
    fl=fopen("ej80.dat", "rb");
    fread(&vec[x],sizeof(vec[x]),1,fl);
    while(!feof(fl)){
        x++;
        fread(&vec[x],sizeof(vec[x]),1,fl);
    }
    for (int y=0; y<x; y++){
        cout << "nom: " << vec[y].nomb << " edad: " << vec[y].edad << endl;
    }

}

main(){
    generar_archivo();
    leer();
    return 0;
}