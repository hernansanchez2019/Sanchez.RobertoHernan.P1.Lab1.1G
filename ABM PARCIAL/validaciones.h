#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED


#endif // VALIDACIONES_H_INCLUDED



/// @fn void getString(char[], char[], int)
/// @brief VALIDAMOS EL LARGO DE LA CADENA
///
/// @pre
/// @post
/// @param palabra PASAMOS POR VALOR UNA CADENA
/// @param mensaje LE PASAMOS UN MENSAJE
/// @param tamanio EL TAMAÑO QUE QUEREMOS QUE TENGA EL ARRAY
void getString(char palabra[],char mensaje[],int tamanio);


/// @fn int getFloat(char[], char[])
/// @brief VALIDAMOS QUE SE INGRESE UN FLOTANTE
///
/// @pre
/// @post
/// @param mensaje
/// @param mensajeErros
/// @return RETORNAMOS EL RESULTADO flotante VALIDADO

int getFloat(char mensaje[],char mensajeErros[]);


/// @fn int getInt(char[], char[])
/// @brief VALIDAMOS QUE SE INGRESE UN ENTERO
///
/// @pre
/// @post
/// @param mensaje MENSAJE PARA PEDIR ENTERO AL USUARIO
/// @param mensajeErros MENSAJE DE ERROR
/// @return RETORNAMOS EL RESULTADO ENTERO VALIDADO
int getInt(char mensaje[],char mensajeErros[]);



/// @fn int esNumerica(char[])
/// @brief VERIFICAMOS QUE SE ESTAN INGRESANDO NUMEROS
///
/// @pre
/// @post
/// @param auxiliar
/// @return SI DEVUELVE 0 ES POR QUE INGRESO NUMERO, SINO LETRAS.
int esNumerica(char auxiliar[]);
