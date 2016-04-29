int menu(char* items);

int getInt(int* ret, char* msg, char* error_msg, int min, int max); /**< -1 ERROR */
int getShortInt(short int* ret, char* msg, char* error_msg, int min, int max); /**< -1 ERROR */
int getLongInt(long int* ret, char* msg, char* error_msg, int min, int max); /**< -1 ERROR */
int getString(char* ret, char* msg, char* error_msg, int min, int max);
int getFloat(float* ret, char* msg, char* error_msg, int min, int max);
