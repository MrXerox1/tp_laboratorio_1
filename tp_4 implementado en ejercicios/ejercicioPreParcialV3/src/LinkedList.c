#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


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
    LinkedList* this= NULL;
    this=malloc(sizeof(LinkedList));
	if (this != NULL)
	{
		this->size = 0;
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
	int i;
	Node* node = NULL;
	if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		node=this->pFirstNode;
		for(i=0;i<nodeIndex;i++)
		{
			node=node->pNextNode;
		}
	}
    return node;
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
static int addNode(LinkedList *this, int nodeIndex, void *pElement)
{
	int returnAux = -1;
	Node *nodeAux = NULL;
	Node *node = malloc(sizeof(Node));
	Node *node2;

	if (this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
	{
		if (node != NULL)
		{
			node->pElement = pElement;
			node->pNextNode = NULL;
		}

		if (nodeIndex == 0)
		{
			nodeAux = this->pFirstNode;

			this->pFirstNode = node;
			node->pNextNode = nodeAux;
			this->size++;

			returnAux = 0;
		} else {
			node2 = getNode(this, nodeIndex - 1);
			if (node2 != NULL) {
				nodeAux = node2;

				node2->pNextNode = node;

				node->pNextNode = nodeAux;

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
	int size;
	if (this != NULL)
	{
		size=ll_len(this);
		returnAux=addNode(this, size, pElement);

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
    Node *node;
    if (this != NULL && index >= 0 && index < ll_len(this))
    	{
    		node=getNode(this,index);
    		returnAux=node->pElement;
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
    Node *node;
    if (this != NULL && index >= 0 && index < ll_len(this))
       	{
       		node=getNode(this,index);
       		node->pElement=pElement;
       		returnAux=0;
       	}
       return returnAux;
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
	Node *nodeAux;
	Node *nodeBorrado;
	if (this != NULL && index >= 0 && index <= ll_len(this))
	{
		if (index == 0)
		{
			nodeBorrado = getNode(this, index);
			this->pFirstNode = nodeBorrado->pNextNode;
			free(nodeBorrado);
			this->size--;
			returnAux = 0;
		}
		else
		{
			nodeBorrado = getNode(this, index);
			nodeAux = getNode(this, index - 1);
			if (nodeBorrado != NULL && nodeAux != NULL)
			{
				nodeAux->pNextNode = nodeBorrado->pNextNode;
				this->size--;
				returnAux = 0;
			}
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
	Node *node;
	int i;
	if (this != NULL)
	{
		node = this->pFirstNode;
		for (i = 0; i < ll_len(this); i++)
		{
			node = node->pNextNode;
			ll_remove(this,i);
			free(node);
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
	if (this != NULL) {
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
	int i;
	Node *node;
	if (this != NULL) {
		for (i = 0; i < ll_len(this); i++)
		{
			node = getNode(this, i);

			if (pElement == node->pElement)
			{
				returnAux = i;
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
    	if(this->size>0)
    	{
    		returnAux = 0;
    	}
    	else
		{
    		returnAux = 1;
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
	if (this != NULL && index >= 0 && index <= ll_len(this))
	{
		addNode(this,index,pElement);
		returnAux = 0;
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
void* ll_pop(LinkedList *this, int index) {
	void *returnAux = NULL;
	Node *node;
	if (this != NULL && index >= 0 && index < ll_len(this))
	{
		node=getNode(this,index);
		returnAux = node->pElement;
		ll_remove(this,index);
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
	Node *node;
	int i;
	if (this != NULL)
	{
		for (i = 0; i < ll_len(this); i++)
		{
			node = getNode(this, i);

			if (node->pElement==pElement)
			{
				returnAux = 1;
				break;
			}

		}
		if (returnAux == -1)
		{
			returnAux = 0;
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
	Node *node;
	int i;
	if (this != NULL && this2 != NULL)
	{
		node=this2->pFirstNode;
		returnAux=1;
		for (i = 0; i < ll_len(this2); i++)
		{
			if(ll_contains(this,node->pElement)!=1)
			{
				returnAux = 0;
				break;
			}
					node=node->pNextNode;
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
	LinkedList *cloneArray = NULL;
	LinkedList* listaAux;
	Node *node;
	int i;
	if (this != NULL && from >= 0 && from <= ll_len(this) && to >= 0 && to <= ll_len(this))
	{
		listaAux=ll_newLinkedList();
		for (i = from; i < to; i++)
		{
			node=getNode(this,i);
			ll_add(listaAux,node->pElement);
		}
		cloneArray=listaAux;
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
	LinkedList *cloneArray = NULL;
		LinkedList* listaAux;
		Node *node;
		int i;
		if (this != NULL)
		{
			listaAux=ll_newLinkedList();
			for (i = 0; i < ll_len(this); i++)
			{
				node=getNode(this,i);
				ll_add(listaAux,node->pElement);
			}
			cloneArray=listaAux;
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
int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order) {
	int returnAux = -1;
	int i, j;
	Node *nodeAux;
	Node *nodeUno;
	Node *nodeDos;
	if (this != NULL && pFunc != NULL && (order == 0 || order == 1))
	{
			for (i = 0; i < ll_len(this) - 1; i++) {
				nodeUno = getNode(this, i);

				for (j = i + 1; j < ll_len(this); j++)
				{
					nodeDos =  getNode(this, j);


					if (order == 1) //ascendente menor a mayor
							{
						if (pFunc(nodeUno->pElement, nodeDos->pElement) == -1) {
							nodeAux = nodeDos->pElement;
							nodeDos->pElement = nodeUno->pElement;
							nodeUno->pElement = nodeAux;
							returnAux = 0;
						}
					}
					else if (order == 0) //descendete mayor a menor
					{
						if (pFunc(nodeUno->pElement, nodeDos->pElement) == -1)
						{
							nodeAux = nodeUno->pElement;
							nodeUno->pElement = nodeDos->pElement;
							nodeDos->pElement = nodeAux;
							returnAux = 0;
						}
					}
				}
			}
	}
	return returnAux;
}

int ll_map(LinkedList* this, int (*pFunc)(void*)) // for + get
{
    int returnAux = -1;
    int i;
    void* pElement;

    if(this != NULL && pFunc != NULL)
    {
        returnAux = 0;

        for(i=0;i<ll_len(this);i++)
        {
            pElement = ll_get(this, i);

            if(pElement != NULL && pFunc(pElement) == -1) // busco que pFunc retorne error
            {	printf("soy un forro%d\n",i);
                returnAux = -1*i; // para retornar que estaba todo ok hasta (-1 * i) el ìndice que dio error
                break;
            }
        }
    }

    return returnAux;
}
