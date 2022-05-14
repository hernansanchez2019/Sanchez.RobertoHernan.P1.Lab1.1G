#include <stdio.h>
#include <stdlib.h>

#include "validaciones.h"
#include "tipo.h"
#include "colores.h"
#include "servicios.h"
#include "bicicletas.h"


#define TAMTIPO 4
#define TAMCO 5
#define TAMSER 4
#define TAMB 10

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;





typedef struct
{
    int id;             //(autoincremental)
    int idBicicleta;       //(debe existir) Validar
    int idServicio;      // (debe existir) Validar
    eFecha fecha;
    // (Validar día, mes y año)
} eTrabajo;


char menu();




int main()
{
    eTipo tipo[TAMTIPO]= //RODADO
    {
        {1000,"Rutera",29},
        {1001,"Carrera",28},
        {1002,"Mountain",27},
        {1003,"BMX",20}
    };


    eColor colores[TAMCO]=
    {
        {5000,"Gris"},
        {5001,"Blanco"},
        {5002,"Azul"},
        {5003,"Negro"},
        {5004,"Rojo"}

    };


    eServicio servicios[TAMSER]=
    {
        {20000,"Limpieza",30},
        {20001,"Parche",400},
        {20002,"Centrado",500},
        {20003,"Cadena",450}
    };

    eBicicleta bicicletas[TAMB];

    inicializarBicicletas(bicicletas,TAMB);

    char seguir='n';
    int proxIdBici= 3000;

    harddcodeBicicletas(bicicletas,TAMB,&proxIdBici,4);

    do
    {

        switch(menu())
        {
        case 'a':
             system("cls");
            altaBicicleta(bicicletas,TAMB,tipo,TAMTIPO,colores,TAMCO,&proxIdBici);
            system("pause");
            system("cls");
            break;


            break;
        case 'b':

            break;

        case 'c':

            system("cls");
            bajaBici(bicicletas,TAMB,tipo,TAMTIPO,colores,TAMCO,&proxIdBici);
            system("pause");
            system("cls");

            break;

        case 'd':

            system("cls");
            listarBicicletas(bicicletas,TAMB,tipo,TAMTIPO,colores,TAMCO);
            system("pause");
            system("cls");
            break;

        case 'e':

            system("cls");
            listarTipos(tipo,TAMTIPO);
            system("pause");
            system("cls");
            break;

        case 'f':
            system("cls");
            listarColores(colores,TAMCO);
            system("pause");
            system("cls");

            break;

        case 'g':

            system("cls");
            listarServicios(servicios,TAMSER);
            system("pause");
            system("cls");

            break;

        case 'h':

            break;

        case 'i':
            break;

        case 'j':

            seguir = 's';
            printf("PROGRAMA FINALIZADO !!!");
            break;

        }

    }
    while(seguir!='s');



    return 0;
}






char menu()
{

    char opcion;

    printf(" MENU DE OPCIONES:\n");
    printf("A. ALTA BICICLETA\n");
    printf("B. MODIFICAR BICICLETA: Se ingresara el id, permitiendo en un submenu modificar:Tipo ,Rodado\n");
    printf("C. BAJA BICICLETA: Se ingresara el id de la bicicleta y se realizara una baja logica.\n");
    printf("D. LISTAR BICICLETAS: Hacer un unico listado de todas las bicicletas ordenadas por tipo y rodado.\n");
    printf("E. LISTAR TIPOS\n");
    printf("F. LISTAR COLORES\n");
    printf("G. LISTAR SERVICIOS\n");
    printf("H. ALTA TRABAJO: Se dara de alta cada ocurrencia de trabajo pidiendole al usuario que elija una bicicleta y un Servicio\n");
    printf("I. LISTAR TRABAJOS\n");
    printf("J. INGRESE UNA OPCION: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}



