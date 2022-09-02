#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct t_alu{
    char nomb[10];
    int edad;
    //int campo3;
};
void generar_archivo(){
    //char h[]="quit";
    t_alu tmp;
    FILE *fl;
    fl=fopen("ej80.dat","wb");
    cout<<"Ingresar nombre. (quit) para terminar" <<endl;
    cin.getline(tmp.nomb,10);
    //cout << tmp.nomb << endl;
    //fflush(stdin);
    // tmp.nomb == "quit"
    while(strcmp(tmp.nomb,"quit") != 0){

        cout<<"Ingresar edad "<<endl;
        cin>>tmp.edad;
        //cout<<"Ingresar dato3 "<<endl;
        //cin>>tmp.campo3;
        fwrite(&tmp,sizeof(tmp),1,fl);
        cout<<"Ingresar nombre. (quit) para terminar" <<endl;
        cin.getline(tmp.nomb,10);
    }
    fclose(fl);
}

main(){
    generar_archivo();
    //cout << "done" << endl;
    return 0;
}