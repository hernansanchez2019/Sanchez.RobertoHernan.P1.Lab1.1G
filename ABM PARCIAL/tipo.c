#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tipo.h"


int listarTipos(eTipo tipos[],int tamTipo)
{
    int todoOk=0;

    if(tipos!=NULL && tamTipo > 0)
    {
        printf("****  LISTAR TIPOS****\n\n");
        printf("ID         Rodado      Tipo\n");
        printf("------------------\n");

        for(int i = 0 ; i < tamTipo ; i++)
        {
            printf("%d      %d       %s\n",tipos[i].id ,tipos[i].rodado,tipos[i].descripcion);

        }

    }


    return todoOk;

}

int cargarDescripcionTipo(eTipo tipos[], int tamTipo, int id, char desc[])
{

    int todoOk = 0;
    if(tipos != NULL && tamTipo > 0 && desc != NULL){

         for(int i= 0; i < tamTipo; i++){

            if( tipos[i].id == id){
                strcpy( desc, tipos[i].descripcion);
                todoOk = 1;
                break;
            }

         }
    }
    return todoOk;
}



