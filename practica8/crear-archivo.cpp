#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct datos{
    int alum;
    int edad;
    //int campo3;
};
void generar_archivo(){
    datos tmp;
    FILE *archivo_generado;
    archivo_generado=fopen("archivo producto.dat","wb");
    cout<<"Ingresar dato1, corta con CodP = 0" <<endl;
    cin>>tmp.alum;
    while(tmp.alum!=0){
        cout<<"Ingresar dato2 "<<tmp.edad<<endl;
        cin>>tmp.edad;
        //cout<<"Ingresar dato3 "<<tmp.campo3<<endl;
        //cin>>tmp.campo3;
        fwrite(&tmp,sizeof(tmp),1,archivo_generado);
        cout<<"Ingresar código de producto corta con CodP = 0" <<endl;
        cin>>tmp.alum;
    }
    fclose(archivo_generado);
}

main(){
    generar_archivo();
    return 0;
}