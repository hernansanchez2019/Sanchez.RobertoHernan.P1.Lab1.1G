#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicios.h"
#include "trabajo.h"
#include "bicicletas.h"
#include "validaciones.h"


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


int cargarDescripcionServicio(eServicio servicios[], int tamS, int id, char desc[])
{

    int todoOk = 0;
    if(servicios != NULL && tamS > 0 && desc != NULL)
    {

        for(int i= 0; i < tamS; i++)
        {

            if( servicios[i].id == id)
            {
                strcpy( desc, servicios[i].descripcion);
                todoOk = 1;
                break;
            }

        }
    }
    return todoOk;
}


int buscarServicio(eServicio vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty  && vec[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int validarServicio(eServicio servicios[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if (buscarServicio(servicios, tam, id, &indice) )
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}


int mostrarBiciXservicioYfecha(eServicio servicio[],int tamServ,eBicicleta vec[],int tamB,eTrabajo trabajo[],int tamTrab)
{
    int todoOk=0;
    int idServicio;


    if(vec!=NULL && tamB> 0 && servicio !=NULL && tamServ && trabajo!=NULL && tamTrab > 0)
    {
        listarServicios(servicio,tamServ);
        idServicio = getInt("Ingrese el ID del servicio: ","Error...reingrese");
        while(!validarServicio(servicio,tamServ,idServicio))
        {
            idServicio = getInt("Ingrese el ID del servicio: ","Error...reingrese");
        }


        for(int i=0; i < tamB ; i++)
        {
            if(!vec[i].isEmpty && !trabajo[i].isEmpty &&  trabajo[i].idServicio == idServicio)
            {
                mostrarUnTrabajo(trabajo[i],vec,tamB,servicio,tamServ);
            }
        }

    }



    return todoOk;
}


int importesDeServicios(eBicicleta vec[],int tamB,eServicio servicio[],int tamServ,eTipo tipo[],int tamTipo,eColor colores[],int tamColor)
{
    int todoOk=0;
    int idBici;
    float suma=0;

    if(vec!=NULL && tamB>0 && servicio!=NULL && tamServ>0 && tipo!=NULL && tamTipo>0 && colores!=NULL && tamColor> 0 )
    {
        listarBicicletas(vec,tamB,tipo,tamTipo,colores,tamColor);
        idBici = getInt("Ingrese ID bicicleta: ", "Error...reingrese: ");
         while(!validarBicicleta(vec,tamB,idBici))
         {
            idBici = getInt("Ingrese ID bicicleta: ", "Error...reingrese: ");

         }

         for(int i=0; i < tamServ ; i++)
         {
             if(!vec[i].isEmpty && vec[i].id == idBici)
             {
                 suma= servicio[i].precio + suma;
             }

         }

          todoOk=1;

        printf("* Suma de los importes de los servicios de la bicicleta % d : \n Importe: %.2f",idBici,suma);

    }



    return todoOk;
}



