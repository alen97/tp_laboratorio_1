#include <stdio.h>
#include <stdlib.h>
#include "../lib/misFunciones.h"
#include "arrayList.h"
#include "myFood.h"

int main()
{
    ArrayList* pFoodList = al_newArrayList();

    int option;
    char confirm = 'y';

    while(confirm == 'y')
    {
        if((option = menu("\n~~FOOD MENU~~\n1-Add new food\n2-Modify price\n3-Delete food\n4-Delete all\n5-Show all foods\n6-Exit program\n\n", "\n\n~Error! Invalid option\n", 6)) != -1)
        {

            switch(option)
            {
                case 1:
                    addFood(pFoodList);
                    break;
                case 2:
                    modifyFood(pFoodList);
                    break;
                case 3:
                    deleteFood(pFoodList);
                    break;
                case 4:
                    deleteAll(pFoodList);
                    break;
                case 5:
                    showAll(pFoodList);
                    break;
                default:
                    al_deleteArrayList(pFoodList);
                    free(pFoodList);
                    confirm = 'n';
            }

        }
    }

    return 0;
}
