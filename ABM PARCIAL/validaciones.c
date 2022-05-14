#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>

/// @fn void getString(char[], char[], int)
/// @brief VALIDAMOS EL LARGO DE LA CADENA
///
/// @pre
/// @post
/// @param palabra PASAMOS POR VALOR UNA CADENA
/// @param mensaje LE PASAMOS UN MENSAJE
/// @param tamanio EL TAMAÑO QUE QUEREMOS QUE TENGA EL ARRAY
void getString(char palabra[],char mensaje[],int tamanio)//valida no pasar el limite de una cadena de caracteres
{
    char auxilar[1024];
    int cantidadLetras;

    printf("%s",mensaje);
    fflush(stdin);
    gets(auxilar);

    cantidadLetras = strlen(auxilar);

    while(cantidadLetras > tamanio)
    {
        printf("%s",mensaje);
        fflush(stdin);
        gets(auxilar);

    }

    strcpy(palabra,auxilar);


}




/// @fn int getFloat(char[], char[])
/// @brief VALIDAMOS QUE SE INGRESE UN FLOTANTE
///
/// @pre
/// @post
/// @param mensaje
/// @param mensajeErros
/// @return RETORNAMOS EL RESULTADO flotante VALIDADO

int getFloat(char mensaje[],char mensajeErros[])//que sea un numero flotante
{
    int retorno = -1;
    int esNumero;
    char auxiliar[30];




    getString(auxiliar,mensaje,30); // donde se va a guardar, ingresa un numero,limite de la cadena

    while(esNumerica(auxiliar) < 1)
    {
      getString(auxiliar,mensajeErros,30);
    }

    esNumero = atof(auxiliar);

    retorno = esNumero;

 return retorno;
}



/// @fn int getInt(char[], char[])
/// @brief VALIDAMOS QUE SE INGRESE UN ENTERO
///
/// @pre
/// @post
/// @param mensaje MENSAJE PARA PEDIR ENTERO AL USUARIO
/// @param mensajeErros MENSAJE DE ERROR
/// @return RETORNAMOS EL RESULTADO ENTERO VALIDADO
int getInt(char mensaje[],char mensajeErros[])//que sea un numero
{
    int retorno = -1;
    int esNumero;
    char auxiliar[30];




    getString(auxiliar,mensaje,30); // donde se va a guardar, ingresa un numero,limite de la cadena

    while(esNumerica(auxiliar) < 1)
    {
      getString(auxiliar,mensajeErros,30);
    }

    esNumero = atoi(auxiliar);

    retorno = esNumero;

 return retorno;
}



/// @fn int esNumerica(char[])
/// @brief VERIFICAMOS QUE SE ESTAN INGRESANDO NUMEROS
///
/// @pre
/// @post
/// @param auxiliar
/// @return SI DEVUELVE 0 ES POR QUE INGRESO NUMERO, SINO LETRAS.
int esNumerica(char auxiliar[])
{
    int i;
    int largo;
    int retorno =-1;

    if(auxiliar != NULL)
    {
        retorno = 1;

        largo = strlen(auxiliar);

        for(i=0;i<largo;i++)
        {
            if(isdigit(auxiliar[i])==0)
            {
                retorno =0;
                break;

            }

        }
    }


    return retorno;

}
