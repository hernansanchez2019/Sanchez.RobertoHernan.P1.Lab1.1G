#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicletas.h"
#include "validaciones.h"

int listarBicicletas(eBicicleta bicicletas[],int tamB,eTipo tipo[],int tamT,eColor colores[],int tamC)
{
    int todoOk=0;
    int flag=1;

    if(bicicletas!=NULL && tipo!=NULL &&  colores!=NULL  && tamB > 0 &&  tamT >0  &&tamC > 0);
    {
        printf("       *** LISTADO DE BICICLETAS ***\n");
        printf("   ID       MARCA       TIPO   COLOR     MATERIAL \n");
        printf("--------------------------------------------------\n");
        for(int i=0; i < tamB; i++)
        {
            if( !bicicletas[i].isEmpty)
            {
                listarUnaBicicleta(bicicletas[i],tipo,tamT,colores,tamC);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("     No hay bicicletas en el sistema\n");
        }

        todoOk = 1;
    }

    return todoOk;
}

int listarUnaBicicleta(eBicicleta bicicletas,eTipo tipo[],int tamTipo,eColor colores[],int tamC)
{
    int todoOk=0;
    char descripcionTipo[20];
    char descripcionColor[20];


    cargarDescripcionTipo(tipo,tamTipo,bicicletas.idTipo,descripcionTipo);
    cargarDescripcionColor(colores,tamC,bicicletas.idColor,descripcionColor);


    printf("%d      %s      %s    %s     %c\n",bicicletas.id,bicicletas.marca,descripcionTipo,descripcionColor,bicicletas.material);


    return todoOk;
}

int harddcodeBicicletas(eBicicleta bicicletas[],int tamB,int* pNextId,int cant)
{

    int todoOk=0;

    eBicicleta nuevaBicicleta[4]=
    {
        {3000,"scott",1000,5000,'c',0},
        {3001,"trek",1001,5001,'a',0},
        {3002,"canyon",1002,5002,'c',0},
        {3003,"bmc",1003,5003,'a',0}
    };

    if(bicicletas != NULL && pNextId != NULL && tamB > 0)
    {
        for(int i = 0 ; i < cant ; i++)
        {
            bicicletas[i] = nuevaBicicleta[i];
            bicicletas[i].id = *pNextId;
            (*pNextId)++;
        }

        todoOk=1;
    }


    return todoOk;

}


int inicializarBicicletas(eBicicleta vec[], int tamB)
{
    int todoOk = 0;
    if( vec != NULL && tamB > 0)
    {
        for(int i=0; i < tamB; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarBicicletaLibre(eBicicleta vec[], int tamB, int* pIndex)
{

    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tamB > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tamB; i++)
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


int altaBicicleta(eBicicleta bicicletas[],int tamB,eTipo tipo[],int tamTipo,eColor colores[],int tamC,int* pNextId)
{

    int todoOk = 0;
    int indice;

    eBicicleta nuevoBicicleta;

    if( bicicletas != NULL && pNextId != NULL && tipo != NULL && tamB > 0 && tamTipo > 0 && colores!=NULL && tamC > 0)
    {
        system("cls");
        printf("    *** ALTA BICICLETA ***\n\n");
        buscarBicicletaLibre(bicicletas,tamB,&indice);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            nuevoBicicleta.id = *pNextId;

            getString(nuevoBicicleta.marca,"Ingresar marca de la bicicleta: ",20);

            listarTipos(tipo,tamTipo);

            nuevoBicicleta.idTipo = getInt("\nIngresar el tipo de bicicleta: ","Error..");

            listarColores(colores,tamC);

            nuevoBicicleta.idColor = getInt("\nIngresar color de bicicleta: ","Error...");

            printf("Ingrese material  a/c :\nc. carbono\na. aluminio: ");
            fflush(stdin);
            scanf("%c", &nuevoBicicleta.material);

            while(nuevoBicicleta.material != 'c' && nuevoBicicleta.material != 'C' &&
                    nuevoBicicleta.material != 'a'&& nuevoBicicleta.material != 'A')
            {
                printf("Reingrese material  a/c :\nc. carbono\na. aluminio: ");
                fflush(stdin);
                scanf("%c", &nuevoBicicleta.material);
            }


            nuevoBicicleta.isEmpty = 0;

            bicicletas[indice] = nuevoBicicleta;

            (*pNextId)++;

            todoOk = 1;
        }
    }
    return todoOk;

}


int bajaBici(eBicicleta bicicletas[],int tamB,eTipo tipo[],int tamTipo,eColor colores[],int tamC,int* pNextId)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if( bicicletas != NULL && tamB > 0 && tipo != NULL && tamTipo > 0  && colores!=NULL && tamC > 0 && pNextId!=NULL)
    {
        listarBicicletas(bicicletas,tamB,tipo,tamTipo,colores,tamC);
        printf("Ingrese id: ");
        scanf("%d", &id);

        if( buscarBici(bicicletas,tamB,id,&indice))
        {

            if(indice == -1)
            {
                printf("No existe una bicicleta: %d en el sistema\n", id);
            }
            else
            {
                //listarUnaBicicleta(bicicletas,tipo,tamTipo,colores,tamC);
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's' || confirma == 'S')
                {
                    bicicletas[indice].isEmpty = 1;
                    printf("Baja exitosa!!!\n");
                }
                else
                {
                    printf("Baja cancelada por el usuario\n");
                }

            }

            todoOk = 1;
        }
    }
    return todoOk;
}


int buscarBici(eBicicleta vec[], int tam, int id, int* pIndex)
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


/*int modificarBici(eBicicleta vec[],int tam,eTipo tipo[],int tamTipo,eColor colores[],int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    char auxCad[100];
    char sexo;
    float sueldo;
    int edad;
    int idSector;
    eFecha fecha;

    if( vec != NULL && tam > 0 && tipo != NULL && tamTipo > 0 && colores !=NULL && tamC >0 )
    {
        listarBicicletas(vec,tam,tipo,tamTipo,colores,tamC);
        printf("Ingrese id: ");
        scanf("%d", &id);

        if( buscarBici(vec, tam, id, &indice))
        {

            if(indice == -1)
            {
                printf("No existe una bicicleta con id: %d en el sistema\n", id);
            }
            else
            {

                listarUnaBicicleta(vec,tipo,tamTipo,colores,tamC);

                switch(menuModificar())
                {

                case 1:

                    break;
                case 2:

                    break;
                case 3:


                }
            }
            todoOk = 1;
        }
    }
    return todoOk;
}

int menuModificar()
{
    int opcion;

    printf("**** MENU MODIFICAR***** \n\n");
    printf("1. Ingrese tipo\n");
    printf("2. ingrese rodado");
    printf("3. volver al menu principal");
    scanf("%d", &opcion);


    return opcion;
}
*/

