#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

/*a.1) código de vuelo (numérico o 4 caracteres, puede elegir)   a.2) cantidad de pasajes disponibles (3 dígitos)
Luego se cuenta con un archivo Pedidos.dat con los pedidos de los potenciales compradores y con el siguiente diseño de registro:
b.1) DNI del solicitante    b.2) código de vuelo  b.3) cantidad de pasajes solicitados

Se pide: 
1) Cada vez que a un solicitante se le pueden vender sus pasajes, imprimir en el momento la siguiente línea:
       DNI               Cant de pasajes vendidos     Código de Vuelo
   99999999                      999                                      XXXX
*/
struct t_vuelo{
    char dni[10];
    int cod;
    int psd;
    int psnv;
    int pac;
};

void print_vue(){
    t_vuelo tmp;
    FILE *fl;
    fl=fopen("ej81-vuelos.dat","rb");
    fread(&tmp,sizeof(tmp),1,fl);
    while(!feof(fl)){
        cout << "cod_vuelo: " << tmp.cod << " pasajes disp: " << tmp.psd << " pasajes no vend: " << tmp.psnv << endl;
    }
    fclose(fl);
}

void print_ped(){
    t_vuelo tmp;
    FILE *fl;
    fl=fopen("ej81-vuelos.dat","rb");
    fread(&tmp,sizeof(tmp),1,fl);
    while(!feof(fl)){
        cout << "dni: " << tmp.dni << " codv: " << tmp.cod << " pasajes a comprar: " << tmp.pac << endl;
    }
    fclose(fl);
}

void generar_archivo_pedidos(){
    t_vuelo tmp;
    FILE *fl;
    fl=fopen("ej81-pedidos.dat","wb");
    cout<<"Ingresar dni. (quit) para terminar" << endl;
    cin.ignore();
    cin.getline(tmp.dni,10);
    while(strcmp(tmp.dni,"quit") != 0){
        cout<<"Ingresar cod-vuelo "<<endl;
        cin>>tmp.cod;
        cout<<"Ingresar cant-compra "<<endl;
        cin>>tmp.pac;
        fwrite(&tmp,sizeof(tmp),1,fl);
        cout<<"Ingresar dni. (quit) para terminar" <<endl;
        cin.ignore();
        cin.getline(tmp.dni,10);
    }
    fclose(fl);
}


void generar_archivo_vuelos(){
    t_vuelo tmp;
    FILE *fl;
    fl=fopen("ej81-vuelos.dat","wb");
    cout<<"Ingresar cod. vuelo (0) para terminar" <<endl;
    cin>>(tmp.cod);
    while(tmp.cod != 0){
        cout<<"Ingresar psd "<<endl;
        cin>>tmp.psd;
        tmp.psnv=0;
        fwrite(&tmp,sizeof(tmp),1,fl);
        cout<<"Ingresar cod. vuelo (0) para terminar" <<endl;
        cin >> tmp.cod;
    }
    fclose(fl);
}

void carg_vuelos(t_vuelo vec[],int &x){
    FILE *fl;
    fl=fopen("ej81-vuelos.dat","rb");
    fread(&vec[x],sizeof(vec[x]),1,fl);
    while(!feof(fl)){
        x++;
        fread(&vec[x],sizeof(vec[x]),1,fl);
    }
    fclose(fl);

}

void carg_pedidos(t_vuelo vec[], int &x){
    FILE *fl;
    fl=fopen("ej81-pedidos.dat","rb");
    fread(&vec[x],sizeof(vec[x]),1,fl);
    while(!feof(fl)){
        x++;
        fread(&vec[x],sizeof(vec[x]),1,fl);
    }
    fclose(fl);

}

int buscar_cod_vuelo(t_vuelo vec[], int tp,  int cod){
    int x=0;
    while((x < tp+1) or (vec[x].cod != cod)) {
        x++;
    }
    return x;
}

void compras(t_vuelo vec_v[], int v, t_vuelo vec_p[], int p){
    int tmp;
    for (int x=0; x < p+1; x++){
        tmp = buscar_cod_vuelo(vec_v, v, vec_p[x].cod);
        if (vec_p[x].pac <= vec_v[tmp].psd){
            cout << "dni: " << vec_p[x].dni << " pasajes vendidos: " << vec_p[x].pac << " cod_vuelo: " << vec_p[x].cod << endl;
        }
        else{
            cout << "cantidad de pasajes no disponibles" << endl;
            vec_v[tmp].psnv+=vec_p[x].pac;
        }



    }
    for (int x=0; x<v+1; x++){
        if (vec_v[x].psnv !=0){
            cout << "cod_vuelo: " << vec_v[x].cod << " pasajes disponibles: " << vec_v[x].psd << " pasajes no vendidos por falta de disp: " << vec_v[x].psnv << endl;
        }
    }
}


int main(){
    int z=0; int y=0; int sw;
    t_vuelo v_vuelos[500];
    t_vuelo v_pedidos[500];
    
    cout << "1-cargar vec vuelos" << endl;
    cout << "2-cargar vec pedidos" << endl;
    cout << "3-procesar pedidos" << endl;
    cout << "4-generar_archivo_vuelos" << endl;
    cout << "5-generar_archivo_pedidos" << endl;
    cout << "6-imprimir_archivo_vuelos" << endl;
    cout << "7-imprimir_archivo_pedidos" << endl;
    cout << "8-salir" << endl;
    cin >> sw;
    while(sw!=8){
    switch(sw){
        case 1: 
        carg_vuelos(v_vuelos,z);
        cout << "ok" << endl;
        break;
        
        case 2: 
        carg_pedidos(v_pedidos, y);
        cout << "ok" << endl;
        break;
        
        case 3: 
        compras(v_vuelos,z,v_pedidos,y);
        break;
        
        case 4: 
        generar_archivo_vuelos();
        cout << "ok" << endl;
        break;
        
        case 5: 
        generar_archivo_pedidos();
        cout <<"ok"<<endl;
        break;

        case 6: 
        print_vue();
        cout <<"ok"<<endl;
        break;

        case 7: 
        print_ped();
        cout <<"ok"<<endl;
        break;
    }
    cout << "1-cargar vec vuelos" << endl;
    cout << "2-cargar vec pedidos" << endl;
    cout << "3-procesar pedidos" << endl;
    cout << "4-generar_archivo_vuelos" << endl;
    cout << "5-generar_archivo_pedidos" << endl;
    cout << "6-imprimir_archivo_vuelos" << endl;
    cout << "7-imprimir_archivo_pedidos" << endl;
    cout << "8-salir" << endl;
    cin >> sw;
    }
    
    return 0;
}