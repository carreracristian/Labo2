#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

/*Crea y retorna un nuevo LinkedList. Es el constructor,
ya que en él daremos valores iniciales a
las variables y asignaremos las funciones a sus punteros.*/
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this= (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size= 0;
        this->pFirstNode= NULL;
    }
    return this;
}
/*Retorna el tamaño del LinkedList. Verificando que el puntero this sea distinto de NULL. Si la
verificación falla la función retorna (-1) y si tiene éxito retorna la longitud del array.
*/
int ll_len(LinkedList* this)
{
    int returnAux= -1;

    if(this != NULL)
        returnAux= this->size;

    return returnAux;
}
/*Retorna un puntero al nodo que se encuentra en el índice especificado. Verificando que el
puntero this sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la
verificación falla la función retorna (NULL) y si tiene éxito retorna el puntero al nodo.*/
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;

    if(this != NULL)
    {
        int longitud= ll_len(this);

        if(nodeIndex >= 0 && nodeIndex < longitud)
        {
            pNode= this->pFirstNode;

            for(int i=0; i<nodeIndex; i++)
            {
                pNode= pNode->pNextNode;
            }
        }
    }

    return pNode;
}

Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}
/*Agrega un nodo en la posición indexNode. Verificando que el puntero this sea distinto de NULL
y que index sea positivo e inferior al tamaño del array. Si la verificación falla la función retorna
(-1) y si tiene éxito (0).
*/
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux= -1;
    Node* pNode= (Node*)malloc(sizeof(Node));
    Node* pAuxNode= NULL;

    pNode->pElement = pElement;
    pNode->pNextNode = NULL;

    if( (this != NULL) && (pNode != NULL) )
    {
        int longitud = ll_len(this);
        if( (nodeIndex >= 0) && (nodeIndex <= longitud) )
        {
            if(nodeIndex == 0)
            {
                pNode->pNextNode = this->pFirstNode;
                this->pFirstNode = pNode;
            }
            else
            {
                pAuxNode= getNode(this, nodeIndex-1);
                pNode->pNextNode = pAuxNode->pNextNode;
                pAuxNode->pNextNode = pNode;
            }

            this->size++;
            returnAux= 0;
        }
    }

    return returnAux;
}

int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}
/*Agrega un elemento al final de LinkedList. Verificando que el puntero this sea distinto de NULL.
Si la verificación falla la función retorna (-1) y si tiene éxito (0).*/
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux= -1;

    if(this != NULL)
        returnAux= addNode(this, this->size, pElement);

    return returnAux;
}
/*Retorna un puntero al elemento que se encuentra en el índice especificado. Verificando que el
puntero this sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la
verificación falla la función retorna (NULL) y si tiene éxito retorna el elemento.
*/
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;

    if(this != NULL)
    {
        if(index >= 0 && index < ll_len(this))
        {
            Node* pNode = getNode(this, index);

            if(pNode != NULL)
                returnAux = pNode->pElement;
        }
    }

    return returnAux;
}
/*Inserta un elemento en el LinkedList, en el índice especificado. Verificando que el puntero this
sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la verificación
falla la función retorna (-1) y si tiene éxito (0).
*/
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(index >= 0 && index < ll_len(this))
        {
            Node* pNode = getNode(this, index);

            if(pNode != NULL)
            {
                pNode->pElement = pElement;
                returnAux = 0;
            }
        }
    }

    return returnAux;
}
/*Elimina un elemento del LinkedList, en el índice especificado. Verificando que el puntero this
sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la verificación
falla la función retorna (-1) y si tiene éxito (0).*/
int ll_remove(LinkedList* this,int index)
{
    int returnAux= -1;

    if(this!= NULL)
    {
        if(index>=0 && index<this->size)
        {
            Node * pNode = NULL;
            Node * pAuxNode = NULL;

            if(this->size == 1)
            {
                pNode = this->pFirstNode;
                free(pNode);
            }
            else
            {
                pNode = getNode(this, index);

                if(pNode != NULL)
                {
                    pAuxNode = getNode(this, index-1);

                    if(pAuxNode != NULL)
                    {
                        pAuxNode->pNextNode = pNode->pNextNode;
                        free(pNode);
                    }
                }
            }

            returnAux = 0;
        }

        this->size--;
    }

    return returnAux;
}
/*Borra todos los elementos de LinkedList. Verificando que el puntero this sea distinto de NULL.
Si la verificación falla la función retorna (-1) y si tiene éxito (0).
*/
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        for(int i=0; i<ll_len(this); i++)
            ll_remove(this, i);

        returnAux = 0;
    }

    return returnAux;
}
/*Elimina el LinkedList . Verificando que el puntero this sea distinto de NULL. Si la verificación
falla la función retorna (-1), si esta vacío (1) y si contiene elementos (0).
*/
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        int borrado = ll_clear(this);

        if(borrado == 0)
        {
            free(this);
            returnAux = 0;
        }
    }

    return returnAux;
}
/*Retorna el índice de la primera aparición de un elemento (element) en el LinkedList.
Verificando que el puntero this sea distinto de NULL. Si la verificación falla o no encuentra el
elemento la función retorna (-1) y si encuentra el elemento retorna su índice.
*/
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        Node* pNode = NULL;

        for(int i=0; i < ll_len(this); i++)
        {
            pNode = getNode(this, i);

            if(pNode->pElement == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }

    return returnAux;
}
/*Retorna cero si contiene elementos y uno si no los tiene. Verificando que el puntero this sea
distinto de NULL. Si la verificación falla la función retorna (-1), si esta vacío (1) y si contiene
elementos (0).*/
int ll_isEmpty(LinkedList* this)
{
    int returnAux= -1;

    if(this != NULL)
    {
        if(ll_len(this) == 0)
            returnAux= 1;
        else
            returnAux= 0;
    }

    return returnAux;
}
/*Desplaza los elementos e inserta en la posición index. Verificando que el puntero this sea
distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la verificación falla
la función retorna (-1) y si tiene éxito (0).*/
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux= -1;

    if(this != NULL)
    {
        int longitud = ll_len(this);

        if( (index >= 0) && (index <= longitud) )
            returnAux = addNode(this, index, pElement);
    }

    return returnAux;
}
/*Retorna un puntero al elemento que se encuentra en el índice especificado y luego lo elimina
de la lista. Verificando que el puntero this sea distinto de NULL y que index sea positivo e
inferior al tamaño del array. Si la verificación falla la función retorna (NULL) y si tiene éxito
retorna el elemento.
*/
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL)
    {
        int longitud = ll_len(this);

        if( (index >= 0) && (index <= longitud) )
        {
            returnAux = ll_get(this, index);
            ll_remove(this, index);
        }
    }

    return returnAux;
}
/*Comprueba si existe el elemento que se le pasa como parámetro. Verificando que tanto el
puntero this sea distintos de NULL. Si la verificación falla la función retorna (-1) , si encuentra
el elemento (1) y si no lo encuentra (0).
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux= -1;

    if(this != NULL)
    {
        if (ll_indexOf(this, pElement) == -1)
            returnAux= 0;
        else
            returnAux= 1;
    }

    return returnAux;
}
/*Comprueba si los elementos pasados son contenidos por el LinkedList. Verificando que tanto el
puntero this como pList2 sean distintos de NULL. Si la verificación falla o no encuentra el
elemento la función retorna (-1), si las listas difieren (0) y si ambas listas son iguales retorna
(1).
*/
int ll_containsAll(LinkedList* this, LinkedList* this2)
{
    int returnAux = -1;

    if( (this != NULL) && (this2 != NULL) )
    {
        int longitudLista1 = ll_len(this);
        int longitudLista2 = ll_len(this2);

        returnAux = 0;

        if(longitudLista1 >= longitudLista2)
        {
            Node* pNode = NULL;

            for(int i=0; i< longitudLista2; i++)
            {
                pNode = getNode(this, i);

                if( (ll_contains(this, pNode->pElement)) == 1 )
                    returnAux = 1;
            }
        }
    }

    return returnAux;
}
/*Retorna un nuevo LinkedList con el subconjunto de elementos. Verificando que el puntero this
sea distinto de NULL y que tanto el indice 'from' como 'to' sean positivos e inferiores al tamaño
del array. Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el nuevo
array.
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
        if( (from >= 0 && from <= ll_len(this)) && (to>=0 && to <= ll_len(this)) )
        {
            cloneArray = ll_newLinkedList();

            if(cloneArray != NULL)
            {
                Node* auxNode;

                for(int i = from; i < to; i++)
                {
                    auxNode = getNode(this, i);

                    if(auxNode != NULL)
                        addNode(cloneArray, i, auxNode->pElement);
                }
            }
        }
    }

    return cloneArray;
}
/*Retorna un nuevo LinkedList copia del LinkedList original. Verificando que el puntero this sea
distinto de NULL. Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el
nuevo array.
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
        cloneArray = ll_subList(this, 0, this->size);

    return cloneArray;
}
/*Ordena los elementos del array recibiendo como parámetro la función que sera la encargada
de determinar que elemento es mas grande que otro y si se debe ordenar de manera
ascendente o descendente. Verificando que tanto el puntero this como el puntero a la funcion
pFunc sean distintos de NULL. Si la verificación falla (-1) caso contrario retorna (1).*/
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux= -1;

    if(this != NULL)
    {
        if(pFunc != NULL)
        {
            if( (order == 0) || (order == 1) )
            {
                if(ll_len(this) > 0)
                {
                    void* pElement1;
                    void* pElement2;
                    void* pElementAux;
                    int flag;

                    do
                    {
                        flag = 0;

                        for(int i = 0; i< (ll_len(this) - 1); i++)
                        {
                            pElement1= ll_get(this,i);
                            pElement2= ll_get(this,i+1);

                            if( (pFunc(pElement1, pElement2) < 0 && order == 0) || (pFunc(pElement1, pElement2) > 0 && order == 1) )
                            {
                                pElementAux= pElement1;
                                ll_set(this,i,pElement2);
                                ll_set(this,i+1,pElementAux);

                                flag = 1;
                            }

                            returnAux= 0;
                        }

                    }while(flag);
                }
            }
        }
    }

    return returnAux;
}
