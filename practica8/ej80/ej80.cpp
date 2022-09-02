#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

/* 80) IDEM 60 PERO CON ARCHIVOS Y VECTORES
Se cuenta con un archivo binario de alumnos (no más de 70) con la siguiente información
	Nombre, Edad
Informar la edad promedio del curso y un listado con los nombres y edades de los alumnos cuya edad superó dicho promedio.
Nota: este ejercicio ya lo vimos sin archivos (todo trabajado con vector; pero la idea es poder tomar la información de archivo de manera que la misma sea permanente y no haya que cargarla cada vez al ejecutar el programa). 
La forma sugerida de resolución es cargar primero el archivo a un vector para luego poder controlar el promedio contra los datos del vector de manera de recorrer el archivo una sola vez.

Nota: recuerde no trabajar con strings en archivos binarios sino definir las cadenas de caracteres como vectores de caracteres, 
por ejemplo el campo nombre quedaría de la siguiente manera
char Nombre[20];    // 20 o la cantidad de caracteres deseada */

struct t_alu{
    char nomb[10];
    int edad;

};

void carg_vec(t_alu vec[],int &x){
    FILE *fl;
    fl=fopen("ej80.dat","rb");
    fread(&vec[x],sizeof(vec)[x],1,fl);
    while(!feof(fl)){
        x++;
        fread(&vec[x],sizeof(vec)[x],1,fl);
    }
    fclose(fl);

}

int calc_prom(t_alu vec[], int x){
    int sum=0; int prom; int z=0;
    for (int n=0;n<x;n++){
        sum+=vec[n].edad;
        z++;
    }
    prom=sum/z;
    return prom;
}

main(){
    int z=0;
    t_alu v_alu[70];
    carg_vec(v_alu, z);
    int prom=calc_prom(v_alu,z);
    cout << "Edad promedio del curso: " << prom << endl;
    for (int n=0;n<z;n++){
        if (v_alu[n].edad > prom){
            cout << v_alu[n].nomb << " supera la edad promedio" << endl;
        }
    }

    return 0;
}