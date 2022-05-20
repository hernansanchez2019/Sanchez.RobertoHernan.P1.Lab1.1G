#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED
#include "bicicletas.h"
#include "tipo.h"
#include "colores.h"

typedef struct
{
    int id;            //(comienza en 20000)
    char descripcion[25];// (máximo 25 caracteres)
    float precio;
    int isEmpty;

} eServicio;   // HARDDCODEO

#endif // SERVICIOS_H_INCLUDED


/** \brief LISTAMOS LOS SERVICIOS
 *
 * \param servicios[] eServicio
 * \param tamSer int
 * \return int
 *
 */
int listarServicios(eServicio servicios[],int tamSer);



/** \brief CARGAMOS LA DESCRIPCION DEL SERVICIO PARA LUEGO PODER MOSTRARLO
 *
 * \param servicios[] eServicio
 * \param tamS int
 * \param id int
 * \param desc[] char
 * \return int
 *
 */
int cargarDescripcionServicio(eServicio servicios[], int tamS, int id, char desc[]);


/** \brief BUSCAMOS EL SERVICIO PARA SABER SI EXISTE Y LUEGO PODER VALIDARLO
 *
 * \param vec[] eServicio
 * \param tam int
 * \param id int
 * \param pIndex int*
 * \return int
 *
 */
int buscarServicio(eServicio vec[], int tam, int id, int* pIndex);



/** \brief VALIDAMOS EL SERVICIO PARA EL CORRECTO INGRESO DE DATOS
 *
 * \param servicios[] eServicio
 * \param tam int
 * \param id int
 * \return int
 *
 */
int validarServicio(eServicio servicios[], int tam, int id);


/** \brief LISTAMOS EL IMPORTE DE TODOS LOS SERVICIOS QUE SE LE REALIZARON A UNA BICICLETA DETERMINADA
 *
 * \param vec[] eBicicleta
 * \param tamB int
 * \param servicio[] eServicio
 * \param tamServ int
 * \param tipo[] eTipo
 * \param tamTipo int
 * \param colores[] eColor
 * \param tamColor int
 * \return int
 *
 */
int importesDeServicios(eBicicleta vec[],int tamB,eServicio servicio[],int tamServ,eTipo tipo[],int tamTipo,eColor colores[],int tamColor);
