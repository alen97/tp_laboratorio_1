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

void addFood(ArrayList* pFoodList, SFood* pFood)
{
    char auxFood[50];
    float auxPrice;

    if(pFoodList != NULL && pFood != NULL)
    {
        if(getString(auxFood, "\n\n~ Add new food name: ", "\n\n~Error! invalid name.", 2, 50) != -1)
        {
            if(getFloat(&auxPrice, "\n\n~ Input food price: ", "\n\n~Error! invalid price.", 1, 200) != -1)
            {
                strcpy(pFood->food, auxFood);
                pFood->price = auxPrice;

                pFoodList->add(pFoodList, pFood);

                printf("\n\n~~ New food added! %s - $%.2f\n\n", pFood->food, pFood->price);
            }
        }
    }
}

void modifyFood(ArrayList* pFoodList, SFood* pFood)
{
    int index;
    float auxPrice;

    if(pFoodList != NULL && pFood != NULL)
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
                    pFood->price = auxPrice;
                    pFoodList->set(pFoodList, index, pFood);

                    printf("\n\n~~ Food modyfied! %s is now $%.2f\n\n", pFood->food, pFood->price);
                }
            }
        }
    }
}

void deleteFood(ArrayList* pFoodList, SFood* pFood)
{
    int index;

    if(pFoodList != NULL && pFood != NULL)
    {
        if(pFoodList->isEmpty(pFoodList) == 1) // if empty
        {
            printf("\n\n~~You must add a food first !~~\n\n");
        }
        else
        {
            if(getInt(&index, "\n\n~~ Input the index of the food you want to delete: ", "\n\n~~Error! Invalid index.", 0, pFoodList->size) != -1)
            {
                if(pFoodList->remove(pFoodList, index) == 0)
                {
                   printf("\n~~Food deleted succesfully !\n");
                }
            }
        }
    }
}

void deleteAll(ArrayList* pFoodList)
{
    if(pFoodList != NULL)
    {
        pFoodList->clear(pFoodList);
        printf("\n~~All foods were deleted succesfully !\n");
    }
}

void showAll(ArrayList* pFoodList, SFood* pFood)
{
    int i;

    if(pFoodList != NULL && pFood != NULL)
    {
        if(pFoodList->isEmpty(pFoodList) == 1) // if empty
        {
            printf("\n\n~~No data found !\n");
        }
        else
        {
            for(i=pFoodList->len(pFoodList) ; i >= 0; i--)
            {
                printf("\n\n~[%d]~ %s - $%.2f\n", i, pFood->food, pFood->price);
            }
        }
    }
}
