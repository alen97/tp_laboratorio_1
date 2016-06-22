#include "arrayList.h"

typedef struct{
    char food[50];
    float price;
}SFood;

SFood* newFood();
void addFood(ArrayList* pFoodList);
void modifyFood(ArrayList* pFoodList);
void deleteFood(ArrayList* pFoodList);
void deleteAll(ArrayList* pFoodList);
void showAll(ArrayList* pFoodList);
