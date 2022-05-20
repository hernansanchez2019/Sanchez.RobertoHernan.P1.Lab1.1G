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
        printf("ID     Tipo\n");
        printf("------------------\n");

        for(int i = 0 ; i < tamTipo ; i++)
        {
            printf("%d     %s\n",tipos[i].id,tipos[i].descripcion);

        }

    }


    return todoOk;

}

int cargarDescripcionTipo(eTipo tipos[], int tamTipo, int id, char desc[])
{

    int todoOk = 0;
    if(tipos != NULL && tamTipo > 0 && desc != NULL)
    {

        for(int i= 0; i < tamTipo; i++)
        {

            if( tipos[i].id == id)
            {
                strcpy( desc, tipos[i].descripcion);
                todoOk = 1;
                break;
            }

        }
    }
    return todoOk;
}


int validarTipoBicicleta(eTipo vec[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if (buscarTipoBici(vec, tam, id, &indice) )

    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}


int buscarTipoBici(eTipo vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


