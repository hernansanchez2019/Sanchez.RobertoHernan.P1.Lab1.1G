#ifndef INFORMESYMENU_H_INCLUDED
#define INFORMESYMENU_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>

#include "informesYmenu.h"
#include "validaciones.h"
#include "tipo.h"
#include "colores.h"
#include "servicios.h"
#include "bicicletas.h"
#include "trabajo.h"

/** \brief MOSTRAMOS EL MENU PRINCIPAL, RETORNANDO LA OPCION SELECCIONADA
 *
 * \return char
 *
 */
char menu();



/** \brief MSOTRAMOS EL MENU DE INFORMES COMPLEMENTARIOS, RETORNANDO LA OPCION SELECCIONADA
 *
 * \return int
 *
 */
int menInformes();


/** \brief MOSTRAMOS TODOS LOS INFORMES
 *
 * \param bicicletas[] eBicicleta
 * \param tamB int
 * \param colores[] eColor
 * \param tamCol int
 * \param tipo[] eTipo
 * \param tamT int
 * \param trabajo[] eTrabajo
 * \param tamTra int
 * \param servicio[] eServicio
 * \param tamSer int
 * \return int
 *
 */
int informes(eBicicleta bicicletas[],int tamB,eColor colores[],int tamCol,eTipo tipo[],int tamT,eTrabajo trabajo[],int tamTra,eServicio servicio[],int tamSer);

#endif // INFORMESYMENU_H_INCLUDED



