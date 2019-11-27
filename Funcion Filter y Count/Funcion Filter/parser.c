#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Cliente.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_ClienteFromText(FILE* pFile, LinkedList* pArrayListCliente)
{

    //validaciones acá! o al contructor con parametros ya que deberia validar desde ahí!
    Cliente* pCliente;
    char bufferID_Llamada[100];
    char bufferDia[100];
    char bufferMes[100];
    char bufferAnio[100];
    char bufferNumeroCliente[100];
    char bufferID_Problema[100];
    char bufferSolucion[100];

    char cabecera1[100];
    char cabecera2[100];
    char cabecera3[100];
    char cabecera4[100];
    char cabecera5[100];

    int retorno = -1;

    if(pFile != NULL)
    {

        fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^\n]\n", cabecera1,cabecera2,cabecera3,cabecera4,cabecera5);
        while(!feof(pFile))
        {


            fscanf(pFile, "%[^,], %[^/]/ %[^/]/ %[^,], %[^,], %[^,], %[^\n]\n", bufferID_Llamada, bufferDia, bufferMes,bufferAnio , bufferNumeroCliente, bufferID_Problema, bufferSolucion);


            pCliente = cliente_newParametros(bufferID_Llamada, bufferDia, bufferMes, bufferAnio, bufferNumeroCliente,bufferID_Problema,bufferSolucion);

            if(pCliente != NULL)

            {
                ll_add(pArrayListCliente, pCliente);
                retorno = 0;
            }
        }
    }

    return retorno;

}

