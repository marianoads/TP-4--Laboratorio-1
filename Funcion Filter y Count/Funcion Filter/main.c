#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Controller.h"
#include "LinkedList.h"



int main()
{
    LinkedList* pArrayListCliente = ll_newLinkedList();
    LinkedList* nuevaLista = NULL;

    char seguir = 's';
    int cantElementosEnElArray;

    while(seguir == 's')
    {


        int opcion;
        int opcionLlamada;
        char continuar='x';

        getInt(&opcion,"\t\t** MENU SOPORTE TECNICO **\n\n1-Cargar archivo (formato texto)\n2-Imprimir todas las llamadas\n3-Imprimir las llamadas filtradas (SIN SOLUCION)\n4-Generar archivo de llamadas (FILTRAR Y GUARDAR)\n5-Salir\n\nElija opcion :","**** Error elija una opcion correcta (1-5) ****",1,5);

        switch(opcion)
        {

        case 1:
            controller_loadFromText("DATOS.csv",pArrayListCliente);
            system("pause");
            break;
        case 2:

            cantElementosEnElArray=ll_count(pArrayListCliente,funcionContar);
            printf("\n\nCantidad de elementos en el array: %d\n\n",cantElementosEnElArray);
            system("pause");

           /* printf("idLlamada    Fecha      Numero_Cliente       Problema          Solucionado");
            ll_sort(pArrayListCliente,ordenarLlamadaPorId,1);
            controller_showCliente(pArrayListCliente,ll_len(pArrayListCliente)); */

            break;
        case 3:
            printf("iDLlamada    Fecha      Numero_Cliente        Problema         Solucionado");
            if(nuevaLista != NULL){
             controller_showCliente(nuevaLista,ll_len(nuevaLista));
             break;
            }
            else{
                printf("\n\n--  No hay ningun filtro cargado  --\n\n");
                system("pause");
            }

            break;

        case 4:
            while(continuar == 'x')
            {
                system("cls");

                getInt(&opcionLlamada,"\t\t** MENU LLAMADAS **\n\n1-No enciende PC\n2-No funciona mouse\n3-No funciona teclado\n4-No hay internet\n5-No funciona teléfono\n6-Salir\n\nElija opcion :","Error, elija una opcion correcta (1-6)",1,6);

                switch(opcionLlamada)
                {
                case 1:
                    nuevaLista=ll_filter(pArrayListCliente,funcionProblemaUno);
                    controller_saveAsText("./datosFiltrados.csv",nuevaLista);
                    break;
                case 2:
                    nuevaLista=ll_filter(pArrayListCliente,funcionProblemaDos);
                    controller_saveAsText("./datosFiltrados.csv",nuevaLista);
                    break;
                case 3:
                    nuevaLista=ll_filter(pArrayListCliente,funcionProblemaTres);
                    controller_saveAsText("./datosFiltrados.csv",nuevaLista);
                    break;
                case 4:
                    nuevaLista=ll_filter(pArrayListCliente,funcionProblemaCuatro);
                    controller_saveAsText("./datosFiltrados.csv",nuevaLista);
                    break;
                case 5:
                    nuevaLista=ll_filter(pArrayListCliente,funcionProblemaCinco);
                    controller_saveAsText("./datosFiltrados.csv",nuevaLista);
                    break;
                case 6:
                    continuar='n';
                    break;
                default:
                    printf("\n\nElija una opcion correcta (1-6)\n\n");
                    system("pause");
                    break;
                }
            }
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("\n\nElija una opcion correcta (1-4)\n\n");
            system("pause");
            break;
        }
        system("cls");
    }



    return 0;
}


