#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "LinkedList.h"
#include "Cliente.h"
#include "Controller.h"
#include "input.h"
#include "parser.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListCliente)
{

    FILE *data;
    int retorno= -1;
    data=fopen(path,"r");
    if(!parser_ClienteFromText(data, pArrayListCliente))
    {
        retorno = 0;
        printf("\n\n Archivo cargado correctamente \n\n");
    }

    fclose(data);

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    pFile = fopen(path,"w");
    int cantidadLetras;
    int cantidadLista = ll_len(pArrayListEmployee);
    if(pFile == NULL)
    {
        printf("\nError al abrir el archivo");
        return 0;
    }
    int i = 0;
    fprintf(pFile,"ID_Llamada,Fecha,Numero_Cliente,ID_Problema,Solucionado\n");
    while(i <= cantidadLista)
    {
        Cliente *p = ll_get(pArrayListEmployee,i);
        if(p != NULL)
        {
            cantidadLetras=fprintf(pFile,"%d,%d,%d,%d,%d,%d,%s\n",p->ID_Llamada,p->fecha.dia,p->fecha.mes,p->fecha.anio,p->ID_Cliente,p->ID_Problema,p->Solucion);
        }
        if(cantidadLetras == 0)
        {
            break;
        }
        i++;

    }
    fclose(pFile);
    printf("\n\nLos datos se han filtrado y guardado en el archivo ''datosFiltrados.csv'' \n\n");
    system("pause");

    return 1;
}

int controller_showCliente(LinkedList* pArrayListCliente, int sizeList)
{
    Cliente_showClientes(pArrayListCliente, sizeList);

    return 1;
}
