#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED
#include "tipo.h"
#include "colores.h"

typedef struct
{

    int id; //1000
    char marca[20];     //(máx 20 caracteres)
    int idTipo;        // Validar
    int idColor;       //Validar
    char material;   //(“c” carbono, “a” aluminio)
    int isEmpty;

} eBicicleta;

#endif // BICICLETAS_H_INCLUDED


/** \brief HARDCODEAMOS LOS DATOS DE LA BICICLETA PARA REALIZAR UN TEST FORZADO
 *
 * \param bicicletas[] eBicicleta
 * \param tamB int
 * \param pNextId int*
 * \param cant int
 * \return int
 *
 */
int harddcodeBicicletas(eBicicleta bicicletas[],int tamB,int* pNextId,int cant);


/** \brief MOSTRAMOS UNA BICICLETA
 *
 * \param bicicletas eBicicleta
 * \param tipo[] eTipo
 * \param tamTipo int
 * \param colores[] eColor
 * \param tamC int
 * \return int
 *
 */
int listarUnaBicicleta(eBicicleta bicicletas,eTipo tipo[],int tamTipo,eColor colores[],int tamC);



/** \brief  LISTAMOS TODAS LAS BICICLETAS
 *
 * \param bicicletas[] eBicicleta
 * \param tamB int
 * \param tipo[] eTipo
 * \param tamT int
 * \param colores[] eColor
 * \param tamC int
 * \return int
 *
 */
int listarBicicletas(eBicicleta bicicletas[],int tamB,eTipo tipo[],int tamT,eColor colores[],int tamC);



/** \brief INICIALIZAMOS LAS BICICLETAS EN 1.  VACIO
 *
 * \param vec[] eBicicleta
 * \param tamB int
 * \return int
 *
 */
int inicializarBicicletas(eBicicleta vec[], int tamB);


/** \brief BUSCAMOS UNA BICICLETA LIBRE EN EL SISTEMA
 *
 * \param vec[] eBicicleta
 * \param tamB int
 * \param pIndex int*
 * \return int
 *
 */
int buscarBicicletaLibre(eBicicleta vec[], int tamB, int* pIndex);

/** \brief DAMOS DE BAJA UNA BICICLETA
 *
 * \param bicicletas[] eBicicleta
 * \param tamB int
 * \param tipo[] eTipo
 * \param tamTipo int
 * \param colores[] eColor
 * \param tamC int
 * \param pNextId int*
 * \return int
 *
 */
int bajaBici(eBicicleta bicicletas[],int tamB,eTipo tipo[],int tamTipo,eColor colores[],int tamC,int* pNextId);

/** \brief DAMOS DE ALTA UNA BICICLETA
 *
 * \param bicicletas[] eBicicleta
 * \param tamB int
 * \param tipo[] eTipo
 * \param tamTipo int
 * \param colores[] eColor
 * \param tamC int
 * \param pNextId int*
 * \return int
 *
 */
int altaBicicleta(eBicicleta bicicletas[],int tamB,eTipo tipo[],int tamTipo,eColor colores[],int tamC,int* pNextId);

/** \brief BUSCAMOS LA BICICLETA EN EL SISTEMA
 *
 * \param vec[] eBicicleta
 * \param tam int
 * \param id int
 * \param pIndex int*
 * \return int
 *
 */
int buscarBici(eBicicleta vec[], int tam, int id, int* pIndex);


/** \brief LISTAMOS UNA BICICLETA
 *
 * \param bicicletas eBicicleta
 * \param tipo[] eTipo
 * \param tamTipo int
 * \param colores[] eColor
 * \param tamC int
 * \return int
 *
 */
int listarUnaBicicleta(eBicicleta bicicletas,eTipo tipo[],int tamTipo,eColor colores[],int tamC);
