int menu(char* items);

int getInt(int* ret, char* msg, char* error_msg, int min, int max); /**< -1 ERROR */
short int getShortInt(short int* ret, char* msg, char* error_msg, int min, int max); /**< -1 ERROR */
long int getLongInt(long int* ret, char* msg, char* error_msg, int min, int max); /**< -1 ERROR */
char getString(char* ret, char* msg, char* error_msg, int min, int max);
float getFloat(float* ret, char* msg, char* error_msg, int min, int max);
