#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Cliente.h"
#include "Controller.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);



LinkedList* ll_filter(LinkedList* this, int (*funcionProblemaUno)(void* element))
{
    Cliente* pCliente;
    LinkedList* nuevaLista = ll_newLinkedList();

    if(this != NULL && nuevaLista != NULL)
    {
        for(int i=0; i<ll_len(this); i++)
        {
            pCliente=ll_get(this,i);
            if(funcionProblemaUno(pCliente))
            {
                ll_add(nuevaLista,pCliente);

            }

        }
    }
    return nuevaLista;
}



/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int len;
    int i;
    len=ll_len(this);
    if(this!=NULL && len!=-1 && nodeIndex>=0 && nodeIndex<len)
    {
        pNode=this->pFirstNode;
        for(i=0; i<nodeIndex; i++)
        {
            pNode=pNode->pNextNode;
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;

    Node* prev;
    Node* next;
    Node* nuevoNodo;

    if( this != NULL)
    {
        if(nodeIndex >= 0 && nodeIndex <= ll_len(this))
        {
            nuevoNodo = (Node*)malloc(sizeof(Node));
            if(nuevoNodo != NULL)
            {
                nuevoNodo->pElement = pElement;
                nuevoNodo->pNextNode = NULL;

                if(nodeIndex == 0)  ///Si deseo guardar un nuevo elemento en el primer lugar del linkedlist
                {
                    nuevoNodo->pNextNode = this->pFirstNode; ///El puntero del primer nodo lo guardo en nuevoNodo-pNextNode
                    this->pFirstNode = nuevoNodo; ///Y el nuevoNodo sera el primer elemento de la linkedlist
                }
                else
                {
                    prev = this->pFirstNode; ///Guardo el puntero del primer elemento del ll, que sera el elemento anterior al que yo quiera guardar
                    next = prev->pNextNode;///Guardo el puntero del siguiente elemento que quiero agregar
                    while( nodeIndex > 1)  ///Mientras que el indice sea mayor a 1
                    {
                        prev  = next;   ///Guardo el
                        next  = prev->pNextNode;
                        nodeIndex--;
                    }

                    prev->pNextNode = nuevoNodo;
                    nuevoNodo->pNextNode = next;
                }
                this->size++;
                returnAux = 0;
            }
        }
    }

    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;

    Node* prev;
    Node* next;
    Node* nuevoNodo;

    if( this != NULL)
    {
        if(nodeIndex >= 0 && nodeIndex <= ll_len(this))
        {
            nuevoNodo = (Node*)malloc(sizeof(Node));
            if(nuevoNodo != NULL)
            {
                nuevoNodo->pElement = pElement;
                nuevoNodo->pNextNode = NULL;

                if(nodeIndex == 0)
                {
                    nuevoNodo->pNextNode = this->pFirstNode;
                    this->pFirstNode = nuevoNodo;
                }
                else
                {
                    prev = this->pFirstNode;
                    next = prev->pNextNode;

                    while( nodeIndex > 1)
                    {
                        prev  = next;
                        next  = prev->pNextNode;
                        nodeIndex--;
                    }

                    prev->pNextNode = nuevoNodo;
                    nuevoNodo->pNextNode = next;
                }
                this->size++;
                returnAux = 0;
            }
        }
    }

    return returnAux;
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {

        returnAux = addNode(this,ll_len(this), pElement);

    }


    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int cant = ll_len(this);
    Node* auxNode;

    if(this != NULL && index >= 0 && index < cant)
    {
        auxNode = getNode(this,index);
        returnAux = auxNode->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int cant= ll_len(this);

    Node* auxNode;
    if(this != NULL && index >= 0 && index < cant)
    {
        auxNode = getNode(this, index);
        auxNode->pElement= pElement;
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int cant;
    int returnAux = -1;
    Node* auxNode;
    Node* prev;
    Node* next;
    cant = ll_len(this);
    if(this != NULL && index >= 0 && index < cant && cant > 0)
    {
        if (index == 0)
        {
            auxNode = getNode(this,index);
            this->pFirstNode = auxNode->pNextNode;
            free(auxNode);
            this->size--;
            returnAux = 0;
        }
        else if(index>=1)
        {
            auxNode = getNode(this,index);
            prev = getNode(this,index-1);
            next = getNode(this,index+1);
            prev->pNextNode = next;
            free(auxNode);
            this->size--;
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;


    if(this != NULL)
    {
        for(int i=0; ll_len(this); i++)
        {
            ll_remove(this, i);
            returnAux = 0;
        }
    }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    Node* current;

    if (this!=NULL)
    {

        current = getNode(this,0);
        free(current);
        this->size--;

        returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    Node* nodeAux;
    int returnAux = -1;


    if(this!=NULL)
    {
        for(int i=0; i<ll_len(this); i++)
        {
            nodeAux=getNode(this,i);
            if(nodeAux->pElement==pElement)
            {
                returnAux=i;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{

    int returnAux = -1;

    if(this!=NULL)
    {
        if(this->size==0)
        {
            returnAux=1;

        }
        else
        {
            returnAux=0;

        }
    }



    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    Node* prev;
    Node* next;
    Node* nuevoNodo;

    if( this != NULL)
    {
        if(index >= 0 && index <= ll_len(this))
        {
            nuevoNodo = (Node*)malloc(sizeof(Node));
            if(nuevoNodo != NULL)
            {
                nuevoNodo->pElement = pElement;
                nuevoNodo->pNextNode = NULL;

                if(index == 0)
                {
                    nuevoNodo->pNextNode = this->pFirstNode;
                    this->pFirstNode = nuevoNodo;
                }
                else
                {
                    prev = this->pFirstNode;
                    next = prev->pNextNode;

                    while( index > 1)
                    {
                        prev  = next;
                        next  = prev->pNextNode;
                        index--;
                    }

                    prev->pNextNode = nuevoNodo;
                    nuevoNodo->pNextNode = next;
                }
                this->size++;
                returnAux = 0;
            }
        }
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    void* auxElement = NULL;
    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
        auxElement = ll_get(this,index);
        if(auxElement != NULL)
        {
            ll_remove(this,index);
            returnAux = auxElement;
        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = 0;
        if(ll_indexOf(this,pElement) != -1)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* pElement;
    int i;
    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;
        for(i = 0; i < ll_len(this2); i++)
        {
            pElement = ll_get(this2,i);
            if(ll_contains(this,pElement) == 0)
            {
                returnAux = 0;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement = NULL;
    int i;
    if(this != NULL && from >= 0 && from < ll_len(this) && to > from && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();
        for(i = from ; i < to; i++)
        {
            pElement = ll_get(this, i);
            ll_add(cloneArray, pElement); // Enlaza
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL)
    {
        cloneArray = ll_newLinkedList();
        cloneArray = ll_subList(this, 0, ll_len(this));
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    int j;
    Node * auxNode1;
    Node * auxNode2;
    void * auxElement1;
    void * auxElement2;
    int flagNoEstaOrdenado = 1;


    if (this != NULL && (order == 0 || order == 1) && pFunc != NULL)
    {


        while (flagNoEstaOrdenado==1)
        {
            flagNoEstaOrdenado = 0;
            for (j = 1; j < ll_len(this); j++)
            {
                auxNode1=getNode(this, j);
                auxNode2=getNode(this, j-1);
                auxElement1=ll_get(this,j);
                auxElement2=ll_get(this,(j-1));


                if (order == 1 && pFunc(auxElement1,auxElement2) == -1)
                {

                    auxNode1->pElement = auxElement2;
                    auxNode2->pElement = auxElement1;

                    flagNoEstaOrdenado = 1;
                }
                else if (order == 0 && pFunc(auxElement1,auxElement2) == 1)
                {

                    auxNode1->pElement = auxElement2;
                    auxNode2->pElement = auxElement1;

                    flagNoEstaOrdenado = 1;
                }

            }
            returnAux=0;
        }
    }

    return returnAux;
}

int ll_count(LinkedList* this,int (*fn)(void* element)){
    int cantElement;

    if(this != NULL && fn != NULL){
        for(int i = 0;i<ll_len(this);i++){
            cantElement=cantElement+fn(i);
        }
    }

    return cantElement;
}


