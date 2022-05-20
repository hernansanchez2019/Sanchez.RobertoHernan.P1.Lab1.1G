#include <stdio.h>
#include <stdlib.h>
#include "trabajo.h"
#include "validaciones.h"




int inicializarTrabajo(eTrabajo vec[], int tam)
{
    int todoOk = 0;
    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibreTrabajo(eTrabajo vec[], int tam, int* pIndex)
{

    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int hardcodearTrabajos(eTrabajo vec[], int tam, int cant, int* pNextId)
{
    int todoOk = 0;
    eTrabajo trabajos[6] =
    {
        {70000, 3000, 20000, {10,5,2021},0},
        {70001, 3003, 20002, {18,9,2021},0},
        {70002, 3000, 20003, {4,11,2022},0},
        {70003, 3002, 20001, {24,11,2021},0},
        {70004, 3000, 20001, {30,1,2022},0},
        {70005, 3002, 20000, {3,5,2022},0}

    };

    if( vec != NULL && pNextId != NULL && tam > 0  && cant <= tam)
    {
        for(int i=0; i < cant; i++)
        {
            vec[i] = trabajos[i];
            vec[i].id = *pNextId;
            (*pNextId)++;
        }
        todoOk = 1;
    }
    return todoOk;

}



int mostrarUnTrabajo(eTrabajo trabajo, eBicicleta bicicletas[], int tamB, eServicio servicios[], int tamSer)
{
    int todoOk = 0;
    char descrBici[20];
    char descrServicio[20];

    if(bicicletas != NULL && servicios != NULL && tamB > 0 && tamSer > 0)
    {

        cargarDescripcionBicicleta(bicicletas,tamB,trabajo.idBicicleta,descrBici);
        cargarDescripcionServicio(servicios,tamSer,trabajo.idServicio,descrServicio);

        printf("%d    %10s      %10s   %10d/%d/%d \n",trabajo.id,descrBici,descrServicio,
               trabajo.fecha.dia,
               trabajo.fecha.mes,
               trabajo.fecha.anio
              );


        todoOk = 1;
    }

    return todoOk;
}


int listarTrabajos(eTrabajo trabajo[],int tamTrab, eBicicleta bicicletas[], int tamB, eServicio servicios[], int tamSer)
{
    int todoOk = 0;
    int flag = 1;
    if( trabajo != NULL  && bicicletas != NULL && servicios != NULL && tamTrab > 0 && tamB > 0 && tamSer >0)
    {
        system("cls");
        printf("       *** Listado de Trabajos ***\n");
        printf("   ID      BICICLETA     SERVICIO             FECHA\n");
        printf("-----------------------------------------------------------\n");
        for(int i=0; i < tamTrab; i++)
        {

            if(!trabajo[i].isEmpty)
            {
                mostrarUnTrabajo(trabajo[i],bicicletas,tamB,servicios,tamSer);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("     No hay trabajos en el sistema\n");
        }

        todoOk = 1;
    }
    return todoOk;
}




int altaTrabajo(eTrabajo trabajo[],int tamTrab, eBicicleta bicicletas[], int tamB, eServicio servicios[], int tamSer,int* pNextId,eTipo tipos[],int tamTipo,eColor colores[],int tamColor)
{
    int todoOk = 0;
    int indice;
    eTrabajo nuevoTrabajo;
    eFecha fecha;
    int idBicicleta;
    int idServicio;

    if( trabajo != NULL && pNextId != NULL && bicicletas != NULL && servicios != NULL && tamTrab > 0 && tamB > 0 && tamSer >0)
    {
        system("cls");
        printf("    *** ALTA TRABAJO ***\n\n");
        buscarLibreTrabajo(trabajo,tamTrab,&indice);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            nuevoTrabajo.id = *pNextId;

            listarBicicletas(bicicletas,tamB,tipos,tamTipo,colores,tamColor);
            idBicicleta = getInt("Ingrese id Bicicleta: ","Error...reingrese: ");

            while( !validarBicicleta(bicicletas,tamB,idBicicleta))
            {
                idBicicleta = getInt("\nIngrese id Bicicleta: ","Error...reingrese: ");

            }
            nuevoTrabajo.idBicicleta = idBicicleta;

            listarServicios(servicios,tamSer);
            idServicio = getInt("Ingrese id Servicio: ", "Error...reingrese");

            while( !validarServicio(servicios,tamSer,idServicio))
            {
                idServicio = getInt("Ingrese id Servicio: ", "Error...reingrese");
            }

            nuevoTrabajo.idServicio = idServicio;

            fecha.dia = getInt("Ingrese fecha dd/mm/aaaa:\n Dia: ","Error...reingrese");
            fecha.mes = getInt("Ingrese fecha dd/mm/aaaa:\n Mes: ","Error...reingrese");
            fecha.anio = getInt("Ingrese fecha dd/mm/aaaa:\n Anio: ","Error...reingrese");


            nuevoTrabajo.fecha = fecha;

            nuevoTrabajo.isEmpty = 0;

            trabajo[indice] = nuevoTrabajo;

            (*pNextId)++;

            todoOk = 1;
        }
    }
    return todoOk;
}


int todosLostrabajosXbici(eBicicleta vec[],int tamB,eTrabajo trabajo[],int tamTrab,eTipo tipo[],int tamTipo,eColor colores[],int tamColor,eServicio servicio[],int tamSer)
{
   int todoOk=0;
   int idBici;

   if(vec!=NULL && tamB>0 && trabajo!=NULL && tamTrab>0 && tipo!=NULL && tamTipo>0 && colores!=NULL && tamColor && servicio!=NULL && tamSer>0)
   {
       listarBicicletas(vec,tamB,tipo,tamTipo,colores,tamColor);
       idBici = getInt("Ingrese el ID de la bicicleta: ","Error...reingrese");

      while(!validarBicicleta(vec,tamB,idBici))
       {
         idBici = getInt("Ingrese el ID de la bicicleta: ","Error...reingrese");
       }


       for(int i=0 ; i < tamSer ; i++)
       {
           if(!trabajo[i].isEmpty && trabajo[i].idBicicleta == idBici)
           {
               mostrarUnTrabajo(trabajo[i],vec,tamB,servicio,tamSer);
           }

           else
           {
               printf("no se le realizaron trabajos a esa bicicleta");
           }


       }

       todoOk=1;
   }




  return todoOk;

}



