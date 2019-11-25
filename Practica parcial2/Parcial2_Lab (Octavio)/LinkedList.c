#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Parser.h"

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

int ll_len(LinkedList* this)
{
    int returnAux= -1;

    if(this != NULL)
        returnAux= this->size;

    return returnAux;
}

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

int ll_add(LinkedList* this, void* pElement)
{
    int returnAux= -1;

    if(this != NULL)
        returnAux= addNode(this, this->size, pElement);

    return returnAux;
}

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

LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
        cloneArray = ll_subList(this, 0, this->size);

    return cloneArray;
}

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

int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int returnAux = -1;

    if ( (this != NULL) && (pFunc != NULL) )
    {
        int i;
        for (i=0;i<ll_len(this);i++)
        {
            void* aux;
            aux = ll_get(this,i);
            pFunc(aux);
        }

        returnAux = 0;
    }

    return returnAux;
}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* newList = NULL;

    if ( (this != NULL) && (pFunc != NULL) )
    {
        newList = ll_newLinkedList();

        void* aux = NULL;
        int i;

        for (i=0;i<ll_len(this);i++)
        {
            aux = ll_get(this,i);

            if (pFunc(aux)==1)
                ll_add(newList,aux);

            aux = NULL;
        }
    }

    return newList;
}

