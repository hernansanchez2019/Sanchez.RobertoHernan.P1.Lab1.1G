
#include <stdio.h>
#include <stdlib.h>

#include "informesYmenu.h"
#include "validaciones.h"
#include "tipo.h"
#include "colores.h"
#include "servicios.h"
#include "bicicletas.h"


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
    printf("J. ALTA FORZADA DE BICICLETAS: \n");
    printf("K. ALTA FORZADA DE TRABAJOS: \n");
    printf("L. INFORMES COMPLEMENTARIOS: \n");
    printf("M. INGRESE UNA OPCION: \n");


    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}


int menInformes()
{
    int opcion;

    printf("****  INFORMES COMPLEMENTARIOS ****\n\n");


    printf("1- Mostrar bicicletas del color seleccionado por el usuario\n");
    printf("2- Mostrar bicicletas de un tipo seleccionado\n");
    printf("3- Informar si hay mas bicicletas de carbono o de aluminio y mostrar la cantidad\n");
    printf("4- Mostrar un listado de las bicicletas separadas por tipo\n");
    printf("5- Elegir un color y un tipo y contar cuantas bicicletas hay de ese color y ese tipo\n");
    printf("6- Mostrar el o los colores mas elegidos por los clientes\n");
    printf("7- Pedir una bicicleta y mostrar todos los trabajos que se le hicieron a la misma\n");
    printf("8- Pedir una bicicleta e informar la suma de los importes de los servicios que se le hicieron a lamisma\n");
    printf("9- Pedir un servicio y mostrar las bicicletas a las que se les realizo ese servicio y la fecha\n");
    printf("10- Pedir una fecha y mostrar todos los servicios realizados en la misma\n");
    printf("11- Volver al menu principal\n");

    opcion = getInt("Ingrese una opcion: ","Error...reingrese");


    return opcion;
}

int informes(eBicicleta bicicletas[],int tamB,eColor colores[],int tamCol,eTipo tipo[],int tamT,eTrabajo trabajo[],int tamTra,eServicio servicio[],int tamSer)
{
    int todoOk=0;
    char seguir='n';


    do
    {
        switch(menInformes())
        {
        case 1:
            system("cls");
            coloresXidBicicleta(bicicletas,tamB,colores,tamCol,tipo,tamT);
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            bicicletasSeleccionTipo(bicicletas,tamB,colores,tamCol,tipo,tamT);
            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");
            cantidadBiciXmaterial(bicicletas,tamB);
            system("pause");
            system("cls");
            break;

        case 4:
            system("cls");
            bicicletasXtipo(bicicletas,tamB,tipo,tamT,colores,tamCol);
            system("pause");
            system("cls");

            break;

        case 5:

            system("cls");
            cantidadBiciXtipoYcolor(bicicletas,tamB,tipo,tamT,colores,tamCol);
            system("pause");
            system("cls");

            break;

        case 6:
            break;

        case 7:
            system("cls");
            todosLostrabajosXbici(bicicletas,tamB,trabajo,tamTra,tipo,tamT,colores,tamCol,servicio,tamSer);
            system("pause");
            system("cls");
            break;

        case 8:

            system("cls");
            importesDeServicios(bicicletas,tamB,servicio,tamSer,tipo,tamT,colores,tamCol);
            system("pause");
            system("cls");

            break;

        case 9:
            system("cls");
            mostrarBiciXservicioYfecha(servicio,tamSer,bicicletas,tamB,trabajo,tamTra);
            system("pause");
            system("cls");

            break;

        case 10:
             system("cls");
            servicioXfecha(trabajo,tamTra,servicio,tamSer,bicicletas,tamB);
            system("pause");
            system("cls");
            break;

        case 11:

            seguir='s';
            break;

        }



    }
    while(seguir!='s');




    return todoOk;
}
