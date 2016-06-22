#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/misFunciones.h"
#include "arrayList.h"
#include "myFood.h"

SFood* newFood()
{
    SFood* food = (SFood*)malloc(sizeof(SFood));

    return food;
}

void addFood(ArrayList* pFoodList)
{
    char auxFood[50];
    float auxPrice;

    SFood* pFood = newFood();

    if(pFoodList != NULL && pFood != NULL)
    {
        if(getString(auxFood, "\n\n~ Add new food name: ", "\n\n~Error! invalid name.", 2, 50) != -1)
        {
            if(getFloat(&auxPrice, "\n\n~ Input food price: ", "\n\n~Error! invalid price.", 1, 200) != -1)
            {
                strcpy(pFood->food, auxFood);
                pFood->price = auxPrice;

                if(pFoodList->add(pFoodList, pFood) == -1)
                {
                    printf("\n\n~~ Error!");
                }
                else
                {
                    printf("\n\n~~ New food added! %s - $%.2f\n\n", pFood->food, pFood->price);
                }

            }
        }
    }
    else
    {
        printf("\n\n~~ Memory full, can't add new element.");
    }
}

void modifyFood(ArrayList* pFoodList)
{
    int index;
    float auxPrice;
    SFood* pFood = NULL;

    if(pFoodList != NULL)
    {
        if(pFoodList->isEmpty(pFoodList) == 1) // if empty
        {
            printf("\n\n~~You must add a food first !~~\n\n");
        }
        else
        {
            if(getInt(&index, "\n\n~~ Input the index of the food you want to modify: ", "\n\n~~Error! Invalid index.", 0, pFoodList->size) != -1)
            {
                if(getFloat(&auxPrice, "\n\n~~ Input the new price: ", "\n\n~~Error! Invalid price.", 1, 200) != -1)
                {
                    pFood = pFoodList->get(pFoodList, index);

                    if(pFoodList->contains(pFoodList, pFood) == 1)
                    {
                        pFood->price = auxPrice;
                        pFoodList->set(pFoodList, index, pFood);

                        printf("\n\n~~ Food modyfied! %s is now $%.2f\n\n", pFood->food, pFood->price);
                    }

                }
            }
        }
    }
}

void deleteFood(ArrayList* pFoodList)
{
    int index;
    SFood* pFood = NULL;

    if(pFoodList != NULL)
    {
        if(pFoodList->isEmpty(pFoodList) == 1) // if empty
        {
            printf("\n\n~~You must add a food first !~~\n\n");
        }
        else
        {
            if(getInt(&index, "\n\n~~ Input the index of the food you want to delete: ", "\n\n~~Error! Invalid index.", 0, pFoodList->size) != -1)
            {
                pFood = pFoodList->get(pFoodList, index);
                if(pFoodList->remove(pFoodList, index) == 0)
                {
                   printf("\n~~%s deleted succesfully !\n", pFood->food);
                }
            }
        }
    }
}

void deleteAll(ArrayList* pFoodList)
{
    if(pFoodList != NULL)
    {
        if(pFoodList->isEmpty(pFoodList) == 1) // if empty
        {
            printf("\n\n~~You must add a food first !~~\n\n");
        }
        else
        {
            pFoodList->clear(pFoodList);
            printf("\n~~All foods were deleted succesfully !\n");
        }

    }
}

void showAll(ArrayList* pFoodList)
{
    SFood* pFood = NULL;
    int i;

    if(pFoodList != NULL)
    {
        if(pFoodList->isEmpty(pFoodList) == 1) // if empty
        {
            printf("\n\n~~No data found !\n");
        }
        else
        {

            for(i=0 ; i <= pFoodList->len(pFoodList) - 1; i++)
            {
                pFood = pFoodList->get(pFoodList, i);

                printf("\n\n~[%d]~ %s - $%.2f\n", i, pFood->food, pFood->price);
            }
        }
    }
}
