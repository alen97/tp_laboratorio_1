#include "arrayList.h"

typedef struct{
    char food[50];
    float price;
}SFood;

SFood* newFood();
void addFood(ArrayList* pFoodList, SFood* pFood);
void modifyFood(ArrayList* pFoodList, SFood* pFood);
void deleteFood(ArrayList* pFoodList, SFood* pFood);
void deleteAll(ArrayList* pFoodList);
void showAll(ArrayList* pFoodList, SFood* pFood);
