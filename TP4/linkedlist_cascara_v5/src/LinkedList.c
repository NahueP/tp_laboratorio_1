#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

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

    if(this!= NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i=0;


    if(this != NULL)
    {
        if(nodeIndex >= 0 && nodeIndex < ll_len(this))
        {
            pNode = this->pFirstNode;

           while(i<nodeIndex)
           {
              pNode = pNode->pNextNode;
              i++;
           }

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

    if(this != NULL)
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
    return addNode(this,nodeIndex,pElement);
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

    if(this != NULL)
    {
        addNode(this, this->size, pElement);

        returnAux=0;
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
    Node* pNode;

    if(this != NULL && ll_len(this)>0 && index >= 0 && index < ll_len(this))
    {
        pNode = getNode(this, index);

        returnAux = pNode->pElement;
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
    Node* pNode;

    if(this != NULL && ll_len(this)>0 && index >= 0 && index < ll_len(this))
    {
        pNode = getNode(this, index);

        pNode->pElement = pElement;

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
    int returnAux = -1;
    Node* pNode = NULL;
    Node* pNodeAux;

    if(this != NULL && ll_len(this)>0 && index >= 0 && index < ll_len(this))
    {
        if(index !=0 && index != (ll_len(this)))
        {
            pNodeAux = getNode(this,(index-1)); //Le asigno a pNodeAux el valor del nodo anterior al indice a buscar
            pNode = getNode(this,index); //Le asigno a pNode el valor del nodo en index
            pNodeAux->pNextNode = pNode->pNextNode; //Omito el nodo del medio asignando a pNodeAux el el valor siguiente al nodo a eliminar
            free(pNode);
        }
        else
        {
            if(index==0)
            {
                pNode = getNode(this, index); //Obtengo con getNode() el nodo en la posicion 0 y se lo asigno a pNode
                this->pFirstNode = pNode->pNextNode; //Le asigno a pFirstNode el nodo de la siguiente posicion
                free(pNode); //Libero el primer nodo almacenado en pNode
            }
            else
            {
                if(index!=0 && index == (ll_len(this)))
                {
                     free(pNode); //Libero el nodo
                }
            }
        }


         this->size--; //Reduzco el size en 1
         returnAux = 0;
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
    int i = ll_len(this);

    if(this != NULL) //Verifico que el puntero no sea NULL
    {
        while(i>=0)
        {
            ll_remove(this,i);
            i--;
        }
        returnAux = 0; //Cambio el flag retotno a 0
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

    if(this!= NULL)
    {
        ll_clear(this);
        free(this);

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
    int returnAux = -1;
    Node* pAuxNode = NULL;
    int i;

    if(this != NULL)
    { //Verifico que el puntero no sea NULL
        for(i=0; i<ll_len(this); i++)
        {
            pAuxNode = getNode(this, i); //Asigno a pAuxNode el valor del nodo en la posicion i
            if(pAuxNode->pElement == pElement)
            { //Condicional, si el elemento en pAuxNode es igual al elemento a buscar
                returnAux = i; //Cambio el flag a 1
                break; //Rompo la iteraccion para que no vuelva a busar
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
        if(ll_len(this)>0)
        {
            returnAux=0;
        }
        else
        {
            if(ll_len(this)<=0)
            {
                returnAux=1;
            }
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

    if(this!=NULL && index >= 0 && index <= (ll_len(this)))
    {
        returnAux = addNode(this, index, pElement);
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

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
        returnAux = ll_get(this, index);
        if(returnAux != NULL)
        {
            ll_remove(this, index);
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
    int i;
    Node *pNode;

    if(this != NULL)
    {
        returnAux = 0;
        for(i=0;i<ll_len(this);i++)
        {
            pNode = getNode(this, i);

            if(pNode->pElement == pElement)
            {
                returnAux = 1;
                break;
            }

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
    int returnAux = -1; //Variable retorno a la funcion
    void* pAuxiliar = NULL;
    int retorno;
    int i;

    if(this != NULL &&  this2 != NULL)
    { //Verifico que los punteros this y this2 no sean NULL
        returnAux = 1; //Asigno a la bandera returnAux 1 diciendo que estan los elementos en las listas
        for(i=0; i<ll_len(this2); i++)
        { //Recorro el segundo array completo
            pAuxiliar = ll_get(this, i); //Asigno a pAuxiliar el elemento que retorna ll_get()
            retorno = ll_contains(this2, pAuxiliar); //Asigno a retorno el valor que retorna ll_contains()
            if(retorno == 0)
            { //Si retorna 0 en al menos una iteraccion no el elemento en this2
                returnAux = 0; //Cambio el valor de la variable returnAux
                break; //Rompo la iteraccion para no volver a comprarar
            }
        }
    }
    return returnAux; //Retorno el valor de la variable a la funcion
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
    void* pAuxiliar = NULL; //Puntero auxiliar al elemento
    int i; //Variable iteraccion
    if(this != NULL && from >= 0 && from<ll_len(this) && to>=0 && to<=ll_len(this))
    { //Condicional, si thises distinto de NULL, from y to son mayores a 0 y menores al tama�o de la lista
        cloneArray = ll_newLinkedList(); //Creo una nueva LinkedList para cloneArray
        for(i=from; i<to; i++)
        { //Recorro el array para los parametros ingresados
            pAuxiliar = ll_get(this, i); //Solicito el valor del elemento para pAuxiliar
            ll_add(cloneArray, pAuxiliar); //Se lo paso como parametro a ll_add el cuan se encarga de enlazarlo con los otros nodos
        }
    }


    return cloneArray; //Retorno el valor de la nueva lista


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

    if(this!=NULL)
    {
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
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    int i , j;
    void* pElement1;
    void* pElement2;
    void* pAuxiliar;

    if(this != NULL && pFunc != NULL && (order == 1 || order ==0))
        {

        for(i=0; i<ll_len(this)-1; i++)
        {
            pElement1 = ll_get(this, i); //obtengo el elemento de la posicion i

            for(j=i+1; j<ll_len(this); j++)
            {
                pElement2 = ll_get(this, j);//obtengo el elemento de la posicion j

                if(order == 0)
                {

                    if(pFunc(pElement1, pElement2) < 0)
                    {
                        pAuxiliar = pElement1;
                        pElement1 = pElement2;
                        pElement2 = pAuxiliar;
                    }
                }
                else
                {
                    if(pFunc(pElement1, pElement2) > 0)
                    {
                        pAuxiliar = pElement1;
                        pElement1 = pElement2;
                        pElement2 = pAuxiliar;
                    }
                }
                //swap en la lista
                ll_set(this, i, pElement1);
                ll_set(this, j, pElement2);
            }
        }
        returnAux = 0;
    }
    return returnAux;

}

