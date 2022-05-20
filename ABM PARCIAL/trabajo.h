#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "fecha.h"
#include "bicicletas.h"
#include "servicios.h"

typedef struct
{
    int id;             //(autoincremental)
    int idBicicleta;       //(debe existir) Validar
    int idServicio;      // (debe existir) Validar
    eFecha fecha;// (Validar día, mes y año)
    int isEmpty;

}eTrabajo;


#endif // TRABAJO_H_INCLUDED

/** \brief BUSCAMOS UN INDICE LIBRE PARA LUEGO REALIZAR UN ALTA
 *
 * \param vec[] eTrabajo
 * \param tam int
 * \param pIndex int*
 * \return int
 *
 */
int buscarLibreTrabajo(eTrabajo vec[], int tam, int* pIndex);



/** \brief INICIALIZAMOS LAS POSICIONES DEL ARRAY EN 1
 *
 * \param vec[] eTrabajo
 * \param tam int
 * \return int
 *
 */
int inicializarTrabajo(eTrabajo vec[], int tam);



/** \brief HARDCODEAMOS DATOS PARA RELIZAR TESTING
 *
 * \param vec[] eTrabajo
 * \param tam int
 * \param cant int
 * \param pNextId int*
 * \return int
 *
 */
int hardcodearTrabajos(eTrabajo vec[], int tam, int cant, int* pNextId);


/** \brief MOSTRAMOS LOS DATOS DE UN(1) TRABAJO REALIZADO
 *
 * \param trabajo eTrabajo
 * \param bicicletas[] eBicicleta
 * \param tamB int
 * \param servicios[] eServicio
 * \param tamSer int
 * \return int
 *
 */
int mostrarUnTrabajo(eTrabajo trabajo, eBicicleta bicicletas[], int tamB, eServicio servicios[], int tamSer);


/** \brief LISTAMOS TODOS LOS TRABAJOS REALIZADOS
 *
 * \param trabajo[] eTrabajo
 * \param tamTrab int
 * \param bicicletas[] eBicicleta
 * \param tamB int
 * \param servicios[] eServicio
 * \param tamSer int
 * \return int
 *
 */
int listarTrabajos(eTrabajo trabajo[],int tamTrab, eBicicleta bicicletas[], int tamB, eServicio servicios[], int tamSer);


/** \brief REALIZAMOS EL ALTA DE TRABAJO QUE SE DESEA REALIZAR A UNA BICICLETA
 *
 * \param trabajo[] eTrabajo
 * \param tamTrab int
 * \param bicicletas[] eBicicleta
 * \param tamB int
 * \param servicios[] eServicio
 * \param tamSer int
 * \param pNextId int*
 * \param tipos[] eTipo
 * \param tamTipo int
 * \param colores[] eColor
 * \param tamColor int
 * \return int
 *
 */
int altaTrabajo(eTrabajo trabajo[],int tamTrab, eBicicleta bicicletas[], int tamB, eServicio servicios[], int tamSer,int* pNextId,eTipo tipos[],int tamTipo,eColor colores[],int tamColor);


/** \brief LISTAMOS TODOS LOS TRABAJOS QUE SE LE REALIZARON A UNA BICICLETA DETERMINADA
 *
 * \param vec[] eBicicleta
 * \param tamB int
 * \param trabajo[] eTrabajo
 * \param tamTrab int
 * \param tipo[] eTipo
 * \param tamTipo int
 * \param colores[] eColor
 * \param tamColor int
 * \param servicio[] eServicio
 * \param tamSer int
 * \return int
 *
 */
int todosLostrabajosXbici(eBicicleta vec[],int tamB,eTrabajo trabajo[],int tamTrab,eTipo tipo[],int tamTipo,eColor colores[],int tamColor,eServicio servicio[],int tamSer);
