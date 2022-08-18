#include<iostream>
#include <stdio.h>
using namespace std;
//def struct
struct t_prod{
    string codp;
    int pu;
    int stk;
};

void cargar_vec(t_prod vec[], int &x){
    x=0;
    t_prod tmp;
    FILE *flcv;
    flcv=fopen("ej78.dat", "rb");
    while(!feof(flcv)){
        fread(&tmp,sizeof(tmp),1,flcv);
        vec[x].codp=tmp.codp;
        vec[x].pu=tmp.pu;
        vec[x].stk=tmp.stk;
        x++;
    }
    fclose(flcv);
}

void buscarenvec(){

}

void ventas(t_prod vec[], int &x){
    cout << "codigos de productos: " << endl;
    for (int z=0;z<x+1; z++){
        cout << vec[z].codp << " ";
    }
    string cod;
    int cant;
    cout << endl << "ingrese código de producto. 0 para finalizar" << endl;
    cin >> cod;
    while(cod!="0"){
        cout << "cantidad de productos a comprar" << endl;
        cin >> cant;
        //buscar codigo en vec
        for (int y=0; y<x+1; y++){
            if (cod==vec[y].codp){
                //check stock
                if (cant<= vec[y].stk){ 
                    vec[y].stk-=cant;
                    cout << "se vendieron " << cant << " " << "cod:"<< cod << "importe: " << vec[y].pu*cant << endl;
                }
                else{
                    cout << "stock no disponible" << endl;
                }
            }

        }
        cout << "codigos de productos: " << endl;
        for (int z=0;z<x+1; z++){
        cout << vec[z].codp << " ";
        }
        cout << endl << "ingrese código de producto. 0 para finalizar" << endl;
        cin >> cod;
    }
}

void actualizar(t_prod vec[], int n){
    t_prod tmp;
    FILE *fla;
    fla=fopen("ej78.dat", "wb");
    for (int x=0; x<n+1; x++){
        tmp.codp=vec[x].codp;
        tmp.pu=vec[x].pu;
        tmp.stk=vec[x].stk;
        fwrite(&tmp,sizeof(tmp),1,fla);
    }
    fclose(fla);
}

void imprimir(){
    t_prod tmp;
    FILE *fli;
    fli=fopen("ej78.dat","rb");
    cout << "cod.prod   |   Precio    |     stk-disp  " << endl;
    while(!feof(fli)){
        fread(&tmp,sizeof(tmp),1,fli);
        cout << tmp.codp << "       "<< tmp.pu << "       " << tmp.stk << endl;

    }
    fclose(fli);

}


void g_a(){
    t_prod tmp;
    FILE *flga;
    flga=fopen("ej78.dat","wb");
    cout<<"Ingresar codp. (0 salir)" <<endl;
    cin>>tmp.codp;
    while(tmp.codp!="0"){
        cout<<"ingresar pu"<<endl;
        cin>>tmp.pu;
        cout<<"Ingresar stk disp "<<endl;
        cin>>tmp.stk;
        fwrite(&tmp,sizeof(tmp),1,flga);
        cout<<"Ingresar código de producto corta con CodP = 0" <<endl;
        cin>>tmp.codp;
    }
    fclose(flga);
}


//Main
int main(){
    int n;
    //def V_prod
    t_prod v_prod[30];
    g_a();
    cargar_vec(v_prod, n);
    ventas(v_prod, n);
    actualizar(v_prod, n);
    imprimir();
    return 0;
}
