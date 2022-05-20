#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicletas.h"
#include "validaciones.h"
#include "servicios.h"
#include "trabajo.h"

int ordenamientoXtipoYrodado(eBicicleta bicicletas[],int tamB,eTipo tipo[],int tamT)
{
    int todoOk=0;
    eBicicleta aux;


    if(bicicletas!=NULL && tipo!=NULL && tamB > 0 && tamT > 0)
    {
        for(int i=0 ; i < tamB -1 ; i++)
        {
            for(int j= i+1 ; j < tamB ; j++)
            {
                if(bicicletas[i].rodado < bicicletas[j].rodado)
                {
                    aux = bicicletas[i];
                    bicicletas[i] = bicicletas[j];
                    bicicletas[j] = aux;
                }
                else
                {
                    if(bicicletas[i].rodado == bicicletas[j].rodado)
                    {
                        if(strcmp(tipo[i].descripcion, tipo[j].descripcion) < 0)
                        {
                            aux = bicicletas[i];
                            bicicletas[i] = bicicletas[j];
                            bicicletas[j] = aux;
                        }
                    }
                }

            }
        }
    }



    return todoOk;
}



int listarBicicletas(eBicicleta bicicletas[],int tamB,eTipo tipo[],int tamT,eColor colores[],int tamC)
{
    int todoOk=0;
    int flag=1;

    if(bicicletas!=NULL && tipo!=NULL &&  colores!=NULL  && tamB > 0 &&  tamT >0  &&tamC > 0);
    {
        printf("       *** LISTADO DE BICICLETAS ***\n");
        printf("   ID       MARCA       TIPO     RODADO     COLOR     MATERIAL \n");
        printf("---------------------------------------------------------------\n");
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
    char tipoMaterial[20];



    cargarDescripcionTipo(tipo,tamTipo,bicicletas.idTipo,descripcionTipo);
    cargarDescripcionColor(colores,tamC,bicicletas.idColor,descripcionColor);

    switch(bicicletas.material)
    {
    case 'c':
        strcpy(tipoMaterial,"carbono");
        break;

    case 'a':
        strcpy(tipoMaterial,"aluminio");
        break;
    }




    printf("%6d      %6s      %6s   %5d   %10s     %3s\n",bicicletas.id,bicicletas.marca,descripcionTipo,bicicletas.rodado,descripcionColor,tipoMaterial);


    return todoOk;
}

int harddcodeBicicletas(eBicicleta bicicletas[],int tamB,int* pNextId,int cant)
{

    int todoOk=0;

    eBicicleta nuevaBicicleta[8]=
    {
        {0,"scott",1000,5000,'c',29,0},
        {0,"bmc",1001,5001,'a',28,0},
        {0,"canyon",1002,5004,'c',26,0},
        {0,"bmc",1003,5003,'c',30,0},
        {0,"scott",1000,5000,'c',29,0},
        {0,"trek",1001,5004,'a',28,0},
        {0,"canyon",1002,5002,'c',26,0},
        {0,"scott",1003,5002,'a',30,0}
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
    int idTipo;
    int idColor;
    int rodado;

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

            idTipo = getInt("\nIngresar el ID tipo de bicicleta: ","Error...reingrese: ");

            while(!validarTipoBicicleta(tipo,tamTipo,idTipo))
            {
                printf("Error...reingrese Tipo: ");
                idTipo = getInt("\nIngresar el ID tipo de bicicleta: ","Error...reingrese: ");
            }

            nuevoBicicleta.idTipo = idTipo;


            rodado = getInt("Ingrese rodado: ","Error...reingrese rodado");

            nuevoBicicleta.rodado = rodado;

            listarColores(colores,tamC);

            idColor = getInt("\nIngrese ID del color de bicicleta: ","Error...reingrese: ");

            while(!validarColores(colores,tamC,idColor))
            {
                printf("Error...");
                idColor = getInt("Ingresar ID del color de bicicleta: ","Error...reingrese: ");
            }

            nuevoBicicleta.idColor = idColor;

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
        id = getInt("Ingrese ID: ","Error..reingrese: ");

        if( buscarBici(bicicletas,tamB,id,&indice))
        {

            if(indice == -1)
            {
                printf("No existe una bicicleta: %d en el sistema\n", id);
            }
            else
            {
                listarUnaBicicleta(bicicletas[indice],tipo,tamTipo,colores,tamC);
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's' || confirma== 'S')
                {
                    bicicletas[indice].isEmpty = 1;
                    printf("Baja Exitosa");
                }

                else
                {
                    printf("Error baja cancelada");

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



int validarBicicleta(eBicicleta bicicletas[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if (buscarBici(bicicletas, tam, id, &indice) )
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}

int modificarBici(eBicicleta vec[],int tam,eTipo tipo[],int tamTipo,eColor colores[],int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    int tipoNuevo;
    int rodadoNuevo;

    eBicicleta biciModificada;



    if( vec != NULL && tam > 0 && tipo != NULL && tamTipo > 0 && colores !=NULL && tamC >0 )
    {
        if(!listarBicicletas(vec,tam,tipo,tamTipo,colores,tamC))
        {
            return todoOk;
        }

        id = getInt("Ingrese ID a modificar: ","Error..reingrese: ");

        if( buscarBici(vec, tam, id, &indice))
        {

            if(indice == -1)
            {
                printf("No existe una bicicleta con id: %d en el sistema\n", id);
            }
            else
            {

                listarUnaBicicleta(vec[indice],tipo,tamTipo,colores,tamC);

                switch(menuModificar())
                {

                case 1:

                    listarTipos(tipo,tamTipo);

                    tipoNuevo = getInt("\nIngresar el ID tipo de bicicleta: ","Error..");

                    while(!validarTipoBicicleta(tipo,tamTipo,tipoNuevo))
                    {
                        printf("Error...reingrese Tipo: ");
                        tipoNuevo= getInt("\nIngresar el ID tipo de bicicleta: ","Error..");
                    }

                    biciModificada.idTipo = tipoNuevo;

                    vec[indice].idTipo = biciModificada.idTipo;


                    printf("Modificacion exitosa !!!");


                    break;

                case 2:

                    rodadoNuevo = getInt("ingrese rodado","Error...eso no es un rodado: ");
                    biciModificada.rodado = rodadoNuevo;

                    vec[indice].rodado =  biciModificada.rodado;

                    printf("Modificacion exitosa !!!");
                    break;

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
    printf("1. Modificar tipo\n");
    printf("2. Modificar rodado\n");
    printf("3. volver al menu principal: ");
    scanf("%d", &opcion);


    return opcion;
}



int cargarDescripcionBicicleta(eBicicleta bicicletas[], int tamB, int id, char desc[])
{

    int todoOk = 0;
    if(bicicletas != NULL && tamB > 0 && desc != NULL)
    {

        for(int i= 0; i < tamB; i++)
        {

            if( bicicletas[i].id == id)
            {
                strcpy( desc, bicicletas[i].marca);
                todoOk = 1;
                break;
            }

        }
    }
    return todoOk;
}

int coloresXidBicicleta(eBicicleta bicicletas[],int tamB,eColor colores[],int tamCol,eTipo tipo[],int tamT)
{
    int todoOk=0;
    int id;
    char descripcion[20];

    if(bicicletas!=NULL && tamB >0 && colores!=NULL && tamCol>0)
    {

        listarColores(colores,tamCol);
        id = getInt("Ingrese el ID del color: ","Error...reingrese: ");

        while(!validarColores(colores,tamCol,id))
        {
            id = getInt("Ingrese el ID del color: : ","Error...reingrese: ");
        }

        cargarDescripcionColor(colores,tamCol,id,descripcion);
        printf("\n***  Bicicletas de color %s ****\n ",descripcion);
        printf("----------------------------------\n");

        for(int i = 0; i < tamB ;  i++)
        {

            if(!bicicletas[i].isEmpty && id == bicicletas[i].idColor)
                {
                    listarUnaBicicleta(bicicletas[i],tipo,tamT,colores,tamCol);
                }

            todoOk=1;
        }

    }

    return todoOk;
}




int bicicletasSeleccionTipo(eBicicleta bicicletas[],int tamB,eColor colores[],int tamCol,eTipo tipo[],int tamT)
{
    int todoOk=0;
    int id;
    char descripcion[20];

    if(bicicletas!=NULL && tamB >0 && colores!=NULL && tamCol>0)
    {

        listarTipos(tipo,tamT);
        id = getInt("Ingrese el ID del tipo de bicicleta: ","Error...reingrese: ");

        while(!validarTipoBicicleta(tipo,tamT,id))
        {
            id = getInt("Ingrese el ID del tipo de bicicleta: ","Error...reingrese: ");
        }

        cargarDescripcionTipo(tipo,tamT,id,descripcion);
        printf("\n***  Bicicletas tipo:  %s ****\n ",descripcion);
        printf("----------------------------------\n");

        for(int i = 0; i < tamB ;  i++)
        {

            if(!bicicletas[i].isEmpty && id == bicicletas[i].idTipo)
                {
                    listarUnaBicicleta(bicicletas[i],tipo,tamT,colores,tamCol);
                }

            todoOk=1;
        }

    }

    return todoOk;
}


int bicicletasxIdtipoo(eBicicleta vec[], int tamB, eTipo tipo[], int tamTipo, int idTipo,eColor colores[],int tamColor)
{
    int todoOk = 0;
    int flag = 1;
    char descripcion[20];

    if( vec != NULL && tamB > 0 && tipo != NULL && tamTipo > 0 && colores!=NULL && tamColor>0)
    {
        cargarDescripcionTipo(tipo,tamTipo,idTipo,descripcion);

        printf("Bicicletas tipo %s\n\n", descripcion);

        printf("-----------------------------------------------------------------------\n");
        for(int i=0; i < tamB; i++)
        {
            if( !vec[i].isEmpty && vec[i].idTipo == idTipo)
            {
                listarUnaBicicleta(vec[i],tipo,tamTipo,colores,tamColor);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("     No hay bicicletas en el sector %s\n", descripcion);
        }

        todoOk = 1;
    }
    return todoOk;
}







int bicicletasXtipo(eBicicleta bicicletas[],int tamB,eTipo tipo[],int tamTipo,eColor colores[],int tamColor)
{
    int todoOk = 0;

    if( bicicletas != NULL && tamB > 0 && tipo != NULL && tamTipo > 0  && colores!=NULL && tamColor>0)
    {
        system("cls");
        printf("   *** Informe Bicicletas x Tipo ***\n");
        printf("---------------------------------------------------------------\n\n");

        for(int i=0; i < tamTipo; i++)
        {
           bicicletasxIdtipoo(bicicletas,tamB,tipo,tamTipo,tipo[i].id,colores,tamColor);
            printf("\n\n");

        }
        todoOk = 1;
    }
    return todoOk;

}




int cantidadBiciXtipoYcolor(eBicicleta vec[],int tamB, eTipo tipo[],int tamTipo,eColor colores[],int tamColor)
{
   int todoOk=0;
   int contadorTipo=0;
   int contardorColor=0;
   int idTipo;
   int idColor;
   char descripcion[20];

    if(vec!=NULL && tamB>0 && tipo!=NULL && tamTipo>0 && colores!=NULL && tamColor>0)
    {
        listarColores(colores,tamColor);
        idColor = getInt("Ingrese el ID del color: ","Error...reingrese");

        while(!validarColores(colores,tamColor,idColor))
        {
            idColor = getInt("Ingrese el ID del color: ","Error...reingrese");
        }


        listarTipos(tipo,tamTipo);
        idTipo = getInt("Ingrese el ID del tipo: ","Error...reingrese");

        while(!validarTipoBicicleta(tipo,tamTipo,idTipo))
        {
            idTipo = getInt("Ingrese el ID del tipo: ","Error...reingrese");
        }



        for(int i=0 ; i < tamB ; i++)
        {
            if(!vec[i].isEmpty && vec[i].idColor == idColor)
            {
                contardorColor++;
            }
        }


         for(int i=0 ; i < tamB ; i++)
        {
            if(!vec[i].isEmpty && vec[i].idTipo == idTipo)
            {
                contadorTipo++;
            }
        }


        cargarDescripcionColor(colores,tamColor,idColor,descripcion);
        printf("\n- Cantidad de bicicletas de color %s : %d",descripcion,contardorColor);

        cargarDescripcionTipo(tipo,tamTipo,idTipo,descripcion);
        printf("\n- Cantidad de bicicletas de tipo %s : %d",descripcion,contadorTipo);


    }



    return todoOk;
}


int cantidadBiciXmaterial(eBicicleta bicicleta[],int tamB)
{
    int todoOk=0;
    int contadorAluminio=0;
    int contadorCarbono=0;
    int mayorCantidad=0;


    if(bicicleta!=NULL && tamB > 0)
    {
        for(int i =0 ; i < tamB ; i++)
        {
            if(!bicicleta[i].isEmpty && bicicleta[i].material == 'c')
            {
                contadorCarbono++;
            }

            else if(bicicleta[i].material == 'a')
            {
                contadorAluminio++;
            }
        }

        if(contadorAluminio > contadorCarbono)
        {
            mayorCantidad = contadorAluminio;

            printf("* La mayor cantidad de bicicletas son de aluminio : %d", mayorCantidad);

        }
        else
        {
            mayorCantidad = contadorCarbono;

            printf("* La mayor cantidad de bicicletas son de carbono:  %d\n", mayorCantidad);
        }

        todoOk=1;
    }

    return todoOk;
}



int servicioXfecha(eTrabajo trabajo[],int tamTrab,eServicio servicio[],int tamSer,eBicicleta vec[],int tamB)
{
    int todoOk=0;
    eFecha fecha;


    if(trabajo!=NULL && tamTrab>0 && servicio!=NULL && tamSer)
    {
        listarTrabajos(trabajo,tamTrab,vec,tamB,servicio,tamSer);

        fecha.dia = getInt("Ingrese fecha dd/mm/aaaa:\n Dia: ","Error...reingrese");
        fecha.mes = getInt("Ingrese fecha dd/mm/aaaa:\n Mes: ","Error...reingrese");
        fecha.anio = getInt("Ingrese fecha dd/mm/aaaa:\n Anio: ","Error...reingrese");


        for(int i=0; i < tamTrab ; i++)
        {
            if(!trabajo[i].isEmpty && trabajo[i].fecha.dia == fecha.dia && trabajo[i].fecha.mes== fecha.mes && trabajo[i].fecha.anio && fecha.anio )
            {
                mostrarUnTrabajo(trabajo[i],vec,tamB,servicio,tamSer);
            }
        }
    }


    return todoOk;
}




