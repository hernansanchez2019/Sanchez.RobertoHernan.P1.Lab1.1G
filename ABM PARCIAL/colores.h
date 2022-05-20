#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED


typedef struct
{
    int id; //(comienza en 5000)
    char nombreColor[20]; //(máx 20 caracteres)

} eColor; // HARDDCODEO

#endif // COLORES_H_INCLUDED


/** \brief LISTAMOS LOS COLORES
 *
 * \param colores[] eColor
 * \param tamCol int
 * \return int
 *
 */
int listarColores(eColor colores[],int tamCol);


/** \brief CARGAMOS LA DESCRIPCION DE CADA COLOR SEGUN SU ID
 *
 * \param colores[] eColor
 * \param tamC int
 * \param id int
 * \param desc[] char
 * \return int
 *
 */
int cargarDescripcionColor(eColor colores[], int tamC, int id, char desc[]);



/** \brief validamos los colores a la hora de realizar un alta
 *
 * \param vec[] eColor
 * \param tam int
 * \param id int
 * \return int
 *
 */
int validarColores(eColor vec[], int tam, int id);


/** \brief buscamos los colores
 *
 * \param
 * \param
 * \return
 *
 */

int buscarColores(eColor vec[], int tam, int id, int* pIndex);

