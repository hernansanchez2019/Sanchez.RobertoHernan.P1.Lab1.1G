#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
    int id;            //(comienza en 20000)
    char descripcion[25];// (máximo 25 caracteres)
    float precio;

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
