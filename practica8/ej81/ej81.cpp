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

void print_vue(t_vuelo vec[], int j){
    //t_vuelo tmp;
    cout << "ciclos a imprimir: " << j << endl;
    for (int x=0; x < j; x++){
        cout << "cod_vuelo: " << vec[x].cod << " pasajes disp: " << vec[x].psd << " pasajes no vend: " << vec[x].psnv << endl;
    }
}

void print_ped(t_vuelo vec[], int j){
    cout << "ciclos a imprimir: " << j << endl;
    for (int x=0; x < j; x++){
        cout << "dni: " << vec[x].dni << " codv: " << vec[x].cod << " pasajes a comprar: " << vec[x].pac << endl;
    }
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
    cout << "cantidad de registros: " << x << endl;
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
    cout << "cantidad de registros: " << x << endl;
}

int buscar_cod_vuelo(t_vuelo vec[], int tp,  int cod){
    int pos;
    /*while((x < tp) or (vec[x].cod != cod)) {
        x++;
    }*/

    for (int x=0; x <tp; x++){
        //cout << vec[x].cod << endl;
        if (cod == vec[x].cod){
            pos = x;
            break;
        }
    }
    //cout << "cod de vuelo: " << cod << " en la posicion: " << pos << " cod: " << vec[pos].cod << endl; 
    return pos;
}

void compras(t_vuelo vec_v[], int v, t_vuelo vec_p[], int p){
    int tmp;
    //cout << "tope vuelos: " << v << " tope pedidos: " << p << endl;
    for (int x=0; x < p; x++){
        //cout << "vuelta numero: " << x << endl;
        tmp = buscar_cod_vuelo(vec_v, v, vec_p[x].cod);
        //cout << "tmp posicion codigo de vuelo: " << tmp << endl;
        if (vec_p[x].pac <= vec_v[tmp].psd){
            cout << "dni: " << vec_p[x].dni << " pasajes vendidos: " << vec_p[x].pac << " cod_vuelo: " << vec_p[x].cod << endl;
        }
        else{
            cout << "cantidad de pasajes no disponibles" << endl;
            vec_v[tmp].psnv+=vec_p[x].pac;
        }
    }
    for (int x=0; x<v; x++){
        if (vec_v[x].psnv != 0){
            cout << "cod_vuelo: " << vec_v[x].cod << " pasajes disponibles: " << vec_v[x].psd << " pasajes no vendidos por falta de disp: " << vec_v[x].psnv - vec_v[x].psd << endl;
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
        print_vue(v_vuelos,z);
        cout <<"ok"<<endl;
        break;

        case 7: 
        print_ped(v_pedidos,y);
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