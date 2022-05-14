#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colores.h"


int listarColores(eColor colores[],int tamCol)
{
    int todoOk=0;

    if(colores!=NULL && tamCol > 0)
    {
        printf("*****  LISTAR COLORES  *****\n\n");
        printf("-------------------------------\n");
        printf("ID    COLORES\n");

        for(int i=0 ; i < tamCol ; i++)
        {
           printf("%d      %s\n",colores[i].id, colores[i].nombreColor);
        }
    }


    return todoOk;
}


int cargarDescripcionColor(eColor colores[], int tamC, int id, char desc[])
{

    int todoOk = 0;
    if(colores != NULL && tamC > 0 && desc != NULL)
    {

         for(int i= 0; i < tamC; i++)
        {

            if( colores[i].id== id)
            {
                strcpy( desc, colores[i].nombreColor);
                todoOk = 1;
                break;
            }

         }
    }
    return todoOk;
}
