#include <stdio.h>
#include <stdlib.h>

#include "informesYmenu.h"
#include "validaciones.h"
#include "fecha.h"
#include "trabajo.h"
#include "tipo.h"
#include "colores.h"
#include "servicios.h"
#include "bicicletas.h"


#define TAMTIPO 4
#define TAMCO 5
#define TAMSER 4
#define TAMB 10
#define TAMTRAB 10



int main()
{
    eTipo tipo[TAMTIPO]= //RODADO
    {
        {1000,"Rutera"},
        {1001,"Carrera"},
        {1002,"Mountain"},
        {1003,"BMX"}
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
        {20000,"Limpieza",500,0},
        {20001,"Parche",400,0},
        {20002,"Centrado",500,0},
        {20003,"Cadena",400,0}
    };

    eBicicleta bicicletas[TAMB];
    eTrabajo trabajos[TAMTRAB];

    inicializarBicicletas(bicicletas,TAMB);
    inicializarTrabajo(trabajos,TAMTRAB);

    char seguir='n';
    int proxIdBici= 3000;
    int proxTrabajo= 7000;
    int flag=1;
    int flag2=1;


    // harddcodeBicicletas(bicicletas,TAMB,&proxIdBici,4);
    // hardcodearTrabajos(trabajos,TAMTRAB,6,&proxTrabajo);

    do
    {

        switch(menu())
        {
        case 'a':

            if(flag)
            {
                system("cls");
                altaBicicleta(bicicletas,TAMB,tipo,TAMTIPO,colores,TAMCO,&proxIdBici);
                printf("Alta exitosa!!!");
                flag=0;
                system("pause");
                system("cls");
            }

            break;


            break;
        case 'b':

            if(!flag)
            {
                system("cls");
                modificarBici(bicicletas,TAMB,tipo,TAMTIPO,colores,TAMCO);
                system("pause");
                system("cls");

            }
            else
            {
                printf("No hay datos cargados\n");
                system("pause");
                system("cls");

            }

            break;

        case 'c':

            if(!flag)
            {
                system("cls");
                bajaBici(bicicletas,TAMB,tipo,TAMTIPO,colores,TAMCO,&proxIdBici);
                system("pause");
                system("cls");

            }
            else
            {

                printf("No hay datos cargados\n");
                system("pause");
                system("cls");

            }


            break;

        case 'd':

            if(!flag)
            {
                system("cls");
                ordenamientoXtipoYrodado(bicicletas,TAMB,tipo,TAMTIPO);
                listarBicicletas(bicicletas,TAMB,tipo,TAMTIPO,colores,TAMCO);
                system("pause");
                system("cls");

            }

            else
            {

                printf("No hay datos cargados\n");
                system("pause");
                system("cls");

            }

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

            if(flag2)
            {
                system("cls");
                altaTrabajo(trabajos,TAMTRAB,bicicletas,TAMB,
                            servicios,TAMSER,&proxTrabajo,
                            tipo,TAMTIPO,colores,TAMCO);

                flag2=0;
                system("pause");
                system("cls");

            }

            break;

        case 'i':
            system("cls");
            listarTrabajos(trabajos,TAMTRAB,bicicletas,TAMB,servicios,TAMSER);
            system("pause");
            system("cls");



            break;

        case 'j':
            system("cls");
            harddcodeBicicletas(bicicletas,TAMB,&proxIdBici,8);
            printf("Alta realizada para testing\n");
            flag=0;
            system("pause");
            system("cls");
            break;

        case 'k':
            system("cls");
            hardcodearTrabajos(trabajos,TAMTRAB,6,&proxTrabajo);
            printf("Alta realizada para testing\n");
            flag2=0;
            system("pause");
            system("cls");
            break;


        case 'l':

            if(!flag2 && !flag)
            {
                system("cls");
                informes(bicicletas,TAMB,colores,TAMCO,tipo,TAMTIPO,trabajos,TAMTRAB,servicios,TAMSER);
                system("pause");
                system("cls");
            }
            else
            {
                printf("No hay datos cargados!!!");
                system("pause");
                system("cls");
            }

            break;

        }

    }
    while(seguir!='s');



    return 0;
}






