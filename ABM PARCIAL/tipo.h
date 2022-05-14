#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED


typedef struct
{
    int id; //(comienza en 1000)
    char descripcion[20]; // (máx 20 caracteres)
    int rodado;

} eTipo; // HARDDCODEO

#endif // TIPO_H_INCLUDED




/** \brief LISTAMOS  TIPO Y RODADO DE BICICLETA
 *
 * \param tipos[] eTipo
 * \param tamTipo int
 * \return int
 *
 */
int listarTipos(eTipo tipos[],int tamTipo);



/** \brief CARGAMOS EL TIPO DE BICICLETA SEGUN SU ID
 *
 * \param tipos[] eTipo
 * \param tamTipo int
 * \param id int
 * \param desc[] char
 * \return int
 *
 */
int cargarDescripcionTipo(eTipo tipos[], int tamTipo, int id, char desc[]);

