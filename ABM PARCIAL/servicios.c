#include <stdio.h>
#include <stdlib.h>
#include "servicios.h"


int listarServicios(eServicio servicios[],int tamSer)
{
    int todoOk=0;

    if(servicios!=NULL && tamSer > 0)
    {
        printf("****    LISTAR SERVICIOS ***** \n\n");
        printf("-------------------------------------\n");
        printf("ID        PRECIO     DESCRIPCION\n");

        for(int i = 0 ; i < tamSer ; i++)
        {
            printf("%d      %.2f      %s\n", servicios[i].id,servicios[i].precio,servicios[i].descripcion);

        }
    }



    return todoOk;
}
