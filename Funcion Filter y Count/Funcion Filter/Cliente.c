#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Cliente.h"
#include "LinkedList.h"
#include "Controller.h"

int funcionProblemaCinco (void* element)
{
    int aux=0;
    if(  ((Cliente*) element)->ID_Problema == 5 && strcmp(((Cliente*) element)->Solucion,"NO")==0)
    {
        aux=1;
    }

    return aux;

}

int funcionProblemaCuatro (void* element)
{
    int aux=0;
    if(  ((Cliente*) element)->ID_Problema == 4 && strcmp(((Cliente*) element)->Solucion,"NO")==0)
    {
        aux=1;
    }

    return aux;

}

int funcionProblemaTres (void* element)
{
    int aux=0;
    if(  ((Cliente*) element)->ID_Problema == 3 && strcmp(((Cliente*) element)->Solucion,"NO")==0)
    {
        aux=1;
    }

    return aux;

}

int funcionProblemaDos (void* element)
{
    int aux=0;
    if(  ((Cliente*) element)->ID_Problema == 2 && strcmp(((Cliente*) element)->Solucion,"NO")==0)
    {
        aux=1;
    }

    return aux;

}

int funcionProblemaUno (void* element)
{
    int aux=0;
    if(  ((Cliente*) element)->ID_Problema == 1 && strcmp(((Cliente*) element)->Solucion,"NO")==0)
    {
        aux=1;
    }

    return aux;

}

Cliente* cliente_new()
{

    Cliente* this = (Cliente*) malloc(sizeof(Cliente));

    if( this != NULL)
    {
        this->ID_Cliente = 0;
        this->fecha.dia = 0;
        this->fecha.mes = 0;
        this->fecha.anio = 0;
        this->ID_Llamada = 0;
        this->ID_Problema = 0;
        strcpy(this->Solucion,"");

    }

    return this;
}


Cliente* cliente_newParametros(char* idLlamadaStr,char* diaStr,char* mesStr, char* anioStr,char* numeroClienteStr, char* idProblemaStr, char* solucionStr)
{

    Cliente* this;

    if (idLlamadaStr != NULL && diaStr != NULL && mesStr != NULL && anioStr != NULL && numeroClienteStr != NULL && idProblemaStr != NULL && solucionStr != NULL)
    {
        this  = cliente_new();

        if( this != NULL)
        {

            if(  !cliente_setIdLlamada(this,atoi(idLlamadaStr)) ||
                    !cliente_setDia(this,atoi(diaStr))             ||
                    !cliente_setMes(this,atoi(mesStr))             ||
                    !cliente_setAnio(this,atoi(anioStr))           ||
                    !cliente_setNumeroCliente(this,atoi(numeroClienteStr)) ||
                    !cliente_setIdProblema(this,atoi(idProblemaStr)) ||
                    !cliente_setSolucion(this, solucionStr)


              )
            {

                free(this);
                this = NULL;
            }
        }
    }

    return this;
}

int cliente_setIdLlamada(Cliente* this,int idLlamada)
{

    int todoOk = 0;

    if( this != NULL )
    {

        this->ID_Llamada = idLlamada;
        todoOk = 1;
    }

    return todoOk;
}

int cliente_getIdLLamada(Cliente* this,int* idLlamada)
{

    int todoOk = 0;

    if( this != NULL  )
    {

        *idLlamada = this->ID_Llamada;
        todoOk = 1;
    }
    return todoOk;
}

int cliente_setDia(Cliente* this,int dia)
{

    int todoOk = 0;

    if( this != NULL )
    {

        this->fecha.dia = dia;
        todoOk = 1;
    }

    return todoOk;
}

int cliente_getDia(Cliente* this,int* dia)
{

    int todoOk = 0;

    if( this != NULL )
    {

        *dia = this->fecha.dia;
        todoOk = 1;
    }
    return todoOk;
}

int cliente_setMes(Cliente* this,int mes)
{

    int todoOk = 0;

    if( this != NULL)
    {

        this->fecha.mes = mes;
        todoOk = 1;
    }

    return todoOk;
}

int cliente_getMes(Cliente* this,int* mes)
{

    int todoOk = 0;

    if( this != NULL && mes != NULL)
    {

        *mes = this->fecha.mes;
        todoOk = 1;
    }
    return todoOk;
}

int cliente_setAnio(Cliente* this,int anio)
{

    int todoOk = 0;

    if( this != NULL)
    {

        this->fecha.anio = anio;
        todoOk = 1;
    }

    return todoOk;
}

int cliente_getAnio(Cliente* this,int* anio)
{

    int todoOk = 0;

    if( this != NULL )
    {

        *anio = this->fecha.anio;
        todoOk = 1;
    }
    return todoOk;
}

int cliente_setNumeroCliente(Cliente* this,int numeroCliente)
{

    int todoOk = 0;

    if( this != NULL )
    {

        this->ID_Cliente = numeroCliente;
        todoOk = 1;
    }

    return todoOk;
}

int cliente_getNumeroCliente(Cliente* this,int* numeroCliente)
{

    int todoOk = 0;

    if( this != NULL)
    {

        *numeroCliente = this->ID_Cliente;
        todoOk = 1;
    }
    return todoOk;
}

int cliente_setIdProblema(Cliente* this,int idProblema)
{

    int todoOk = 0;

    if( this != NULL)
    {

        this->ID_Problema = idProblema;
        todoOk = 1;
    }

    return todoOk;
}

int cliente_getIdProblema(Cliente* this,int* idProblema)
{

    int todoOk = 0;

    if( this != NULL)
    {

        *idProblema = this->ID_Problema;
        todoOk = 1;
    }
    return todoOk;
}

int cliente_setSolucion(Cliente* this,char* solucion)
{

    int todoOk = 0;

    if( this != NULL)
    {

        strcpy(this->Solucion, solucion);
        todoOk = 1;
    }

    return todoOk;

}

int cliente_getSolucion(Cliente* this,char* solucion)
{

    int todoOk = 0;

    if( this != NULL)
    {

        strcpy(solucion, this->Solucion);
        todoOk = 1;
    }

    return todoOk;

}

int Cliente_showClientes(Cliente* pArrayListCliente, int sizeList)
{
    Cliente* pCliente;

    int i;
    int retorno = 0;
    int auxIdLlamada;
    int auxDia;
    int auxMes;
    int auxAnio;
    int auxNumeroCliente;
    int auxIdProblema;
    char auxSolucion[5];

    char problemaStr[50];

    for(i=0; i<sizeList; i++)
    {
        pCliente = ll_get(pArrayListCliente, i);
        cliente_getIdLLamada(pCliente,&auxIdLlamada);
        cliente_getDia(pCliente,&auxDia);
        cliente_getMes(pCliente,&auxMes);
        cliente_getAnio(pCliente,&auxAnio);
        cliente_getNumeroCliente(pCliente,&auxNumeroCliente);
        cliente_getIdProblema(pCliente,&auxIdProblema);
        cliente_getSolucion(pCliente,auxSolucion);

        problemaEnFormatoTexto(auxIdProblema,problemaStr);

        printf("\n %3d      %2d/%2d/%4d      %4d        %21s       %4s", auxIdLlamada, auxDia, auxMes, auxAnio, auxNumeroCliente,problemaStr,auxSolucion);

    }
    printf("\n");
    system("pause");
    return retorno;
}

void problemaEnFormatoTexto(int idProblema,char* problemaStr)
{

    if(idProblema==1 && idProblema != NULL && problemaStr != NULL)
    {
        strcpy(problemaStr,"No enciende PC");
    }
    else if(idProblema == 2 && idProblema != NULL && problemaStr != NULL)
    {
        strcpy(problemaStr,"No funciona mouse");

    }
    else if(idProblema == 3 && idProblema != NULL && problemaStr != NULL)
    {
        strcpy(problemaStr,"No funciona teclado");
    }
    else if(idProblema == 4 && idProblema != NULL && problemaStr != NULL)
    {
        strcpy(problemaStr,"No hay internet");

    }
    else if(idProblema == 5 && idProblema != NULL && problemaStr != NULL)
    {
        strcpy(problemaStr,"No funciona telefono");

    }
    return problemaStr;
}

int ordenarLlamadaPorId( void* emp1, void* emp2)
{

    int retorno = 0;
    Cliente* p1;
    Cliente* p2;

    if( emp1 != NULL && emp2 != NULL)
    {

        p1 = (Cliente*) emp1;
        p2 = (Cliente*) emp2;

        if( p1->ID_Cliente > p2-> ID_Cliente)
        {
            retorno = 1;
        }
        else if( p1->ID_Cliente < p2->ID_Cliente)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }

    }

    return retorno;
}

int FuncionFiltrarIdClienteMayorA30YProblema1SinSolucion(void* element){  ///Funcion para filtrar las llamadas. El id del cliente debe ser mayor a 30 y su problema es que "No enciende PC"
    int aux=0;


    if( ((Cliente*) element)->ID_Cliente > 30 && ((Cliente*) element)->ID_Problema == 1 && strcmp(((Cliente*) element)->Solucion,"NO")== 0 ){
    aux=1;
    }

    return aux;

}

int funcionContar(void* element){

    if(element != NULL){
        return 1;
    }
    return 0;
}

