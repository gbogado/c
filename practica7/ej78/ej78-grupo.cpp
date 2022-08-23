#include<iostream>
#include <stdio.h>
using namespace std;

struct tproducto{
    int codp;
    int stock;
    float punitario;

} ;

void generar_archivo(){
    tproducto rproducto;
    FILE *archivo_generado;
    archivo_generado=fopen("archivo producto.dat","wb");
    cout<<"Ingresar código de producto, corta con CodP = 0" <<endl;
    cin>>rproducto.codp;
    while(rproducto.codp!=0){
        cout<<"Ingrese precio unitario del producto numero "<<rproducto.codp<<endl;
        cin>>rproducto.punitario;
        cout<<"Ingrese stock del producto "<<rproducto.codp<<endl;
        cin>>rproducto.stock;
        fwrite(&rproducto,sizeof(rproducto),1,archivo_generado);
        cout<<"Ingresar código de producto corta con CodP = 0" <<endl;
        cin>>rproducto.codp;
    }
    fclose(archivo_generado);
}

void leer_archivo(){
    tproducto rproducto;
    FILE *archivo;
    archivo=fopen("archivo producto.dat","rb");
    if (archivo==NULL){
        cout<<"Archivo inexistente"<<endl;
    }
    else{
         cout << "Listado de Productos" << endl;
	     cout << "Cód " <<"Precio " << "Stk " << endl;
	     fread(&rproducto,sizeof(rproducto),1,archivo);
         while(!feof(archivo)){
         cout << rproducto.codp << "    " << rproducto.punitario << "   " << rproducto.stock <<endl;
         fread(&rproducto,sizeof(rproducto),1,archivo);
       }
    fclose(archivo);
    }
   
}


void CargaProds(tproducto vecrproducto[], int &n){
    tproducto rproducto;
    n=0;
    FILE *archivo1;
    archivo1=fopen("archivo producto.dat","rb");
   if (archivo1==NULL){
        cout<<"Archivo inexistente"<<endl;
    }
    fread(&rproducto,sizeof(rproducto),1,archivo1);
    while(!feof(archivo1)){
        vecrproducto[n]=rproducto;
        n++;
        fread(&rproducto,sizeof(rproducto),1,archivo1);
    }
    fclose(archivo1);
}


void Procesaventas(tproducto vecrproducto[], int n){
   int CodPro;    
   int CanPed;
   cout << "Ingresar código de producto corta con CodP = 0" << endl;;
   cin >> CodPro;
   while(CodPro!=0){
        int pos = 0;
        while((vecrproducto[pos].codp != CodPro) && (pos<n)) {
             pos++;
        }
        if (pos==n) {      
        cout << "El producto solicitado no existe" << endl;    
        }else{
        cout << "Ingrese cantidad pedida" << endl;
        cin >> CanPed;
            if(CanPed > vecrproducto[pos].stock){
                cout << "No puede entregarse el pedido por stk insuficiente" << endl;
            }else{
            cout << "El pedido solicitado cuesta $" << vecrproducto[pos].punitario*CanPed << endl; 
            vecrproducto[pos].stock-=CanPed;
            }
    } 
    cout << "Ingresar código de producto corta con CodP = 0 ";
    cin >> CodPro;
    }
}


void actualizar_archivo(tproducto vecrproducto[], int n){
    tproducto rproducto;
    FILE *archivo_actualizado;
    archivo_actualizado=fopen("archivo producto.dat","wb");
    for(int i=0;i<n;i++){
        rproducto.stock=vecrproducto[i].stock;
        fwrite(&rproducto,sizeof(rproducto),1,archivo_actualizado);
    }
    fclose(archivo_actualizado);
}


int main(){
    tproducto vecrproducto[30];
    int n;
    int op; 
    cout << "Elegir opción deseada" << endl;
    cout << "1-Generar Archivo" << endl;
    cout << "2-Leer Archivo" << endl;
    cout << "3-Cargar vector productos" << endl;
    cout << "4-Procesar ventas" << endl;
    cout << "5-Actualizar Archivo" << endl;
    cout << "6-Salir del programa" << endl;
    cin >> op;
    while(op!=6){
    switch(op){
        case 1: 
        generar_archivo();
        break;
        
        case 2: 
        leer_archivo();
        break;
        
        case 3: 
        CargaProds(vecrproducto, n);
        cout <<"Vector cargado"<<endl;
        break;
        
        case 4: 
        Procesaventas(vecrproducto,n);
        break;
        
        case 5: 
        actualizar_archivo(vecrproducto,n);
        cout <<"Archivo Actualizado"<<endl;
        break;
        
        default: 
        cout <<"ERROR! La opcion seleccionada es invalida"<<endl;
        break;
    }
    cout << "Elegir opción deseada" << endl;
    cout << "1-Generar Archivo" << endl;
    cout << "2-Leer Archivo" << endl;
    cout << "3-Cargar vector productos" << endl;
    cout << "4-Procesar ventas" << endl;
    cout << "5-Actualizar Archivo" << endl;
    cout << "6-Salir del programa" << endl;
    cin >> op;
    }
    
    cout<<"Muchas gracias por utilizar el programa"<<endl;
    
    return 0;
}