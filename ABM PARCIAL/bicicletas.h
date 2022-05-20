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
    int rodado;
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

/** \brief MENU PARA REALIZAR LAS MODIFICACIONES, RETORNANDO LA OPCION ELEGIDA
 *
 * \return int
 *
 */
int menuModificar();



/** \brief MODIFICAMOS TIPO Y RODADO DE LA BICICLETA
 *
 * \param vec[] eBicicleta
 * \param tam int
 * \param tipo[] eTipo
 * \param tamTipo int
 * \param colores[] eColor
 * \param tamC int
 * \return int
 *
 */
int modificarBici(eBicicleta vec[],int tam,eTipo tipo[],int tamTipo,eColor colores[],int tamC);



/** \brief VALIDAMOS QUE LA BICICLETA EXISTA
 *
 * \param bicicletas[] eBicicleta
 * \param tam int
 * \param id int
 * \return int
 *
 */
int validarBicicleta(eBicicleta bicicletas[], int tam, int id);


/** \brief CARGAMOS LA DESCRIPCION DE LA BICICLETA
 *
 * \param bicicletas[] eBicicleta
 * \param tamB int
 * \param id int
 * \param desc[] char
 * \return int
 *
 */
int cargarDescripcionBicicleta(eBicicleta bicicletas[], int tamB, int id, char desc[]);



/** \brief REALIZAMOS UN ORDENAMIENTO POR DOBLE CRITERIO DE RODADOS Y TIPOS DE BICICLETAS
 *
 * \param bicicletas[] eBicicleta
 * \param tamB int
 * \param tipo[] eTipo
 * \param tamT int
 * \return int
 *
 */
int ordenamientoXtipoYrodado(eBicicleta bicicletas[],int tamB,eTipo tipo[],int tamT);


/** \brief ELEGIMOS EL ID DE UN COLOR Y LISTAMOS LAS BICICLETAS DE ESOS COLORES
 *
 * \param bicicletas[] eBicicleta
 * \param tamB int
 * \param colores[] eColor
 * \param tamCol int
 * \param tipo[] eTipo
 * \param tamT int
 * \return int
 *
 */
int coloresXidBicicleta(eBicicleta bicicletas[],int tamB,eColor colores[],int tamCol,eTipo tipo[],int tamT);

/** \brief SELECCIONAMOS EL TIPO DE BICI PARA LISTAR TODAS LAS QUE HAY
 *
 * \param bicicletas[] eBicicleta
 * \param tamB int
 * \param colores[] eColor
 * \param tamCol int
 * \param tipo[] eTipo
 * \param tamT int
 * \return int
 *
 */
int bicicletasSeleccionTipo(eBicicleta bicicletas[],int tamB,eColor colores[],int tamCol,eTipo tipo[],int tamT);


/** \brief CONTAMOS LA CANTIDAD DE BICICLETAS QUE HAY POR TIPO Y COLOR
 *
 * \param vec[] eBicicleta
 * \param tamB int
 * \param tipo[] eTipo
 * \param tamTipo int
 * \param colores[] eColor
 * \param tamColor int
 * \return int
 *
 */
int cantidadBiciXtipoYcolor(eBicicleta vec[],int tamB, eTipo tipo[],int tamTipo,eColor colores[],int tamColor);


/** \brief MOSTRAMOS CADA BICICLETA POR TIPO
 *
 * \param bicicletas[] eBicicleta
 * \param tamB int
 * \param tipo[] eTipo
 * \param tamTipo int
 * \param colores[] eColor
 * \param tamColor int
 * \return int
 *
 */
int bicicletasXtipo(eBicicleta bicicletas[],int tamB,eTipo tipo[],int tamTipo,eColor colores[],int tamColor);



/** \brief CONTAMOS LA CANTIDAD DE BICICLETAS QUE HAY POR MATERIAL Y MOSTRAMOS LA QUE HAYA MAS
 *
 * \param bicicleta[] eBicicleta
 * \param tamB int
 * \return int
 *
 */
int cantidadBiciXmaterial(eBicicleta bicicleta[],int tamB);
