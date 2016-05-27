
int menu(char* items, char* errorMsg, int cantidad);

int getInt(int* ret, char* msg, char* error_msg, int min, int max); /**< -1 ERROR */
int getShortInt(short int* ret, char* msg, char* error_msg, int min, int max); /**< -1 ERROR */
int getLongInt(long int* ret, char* msg, char* error_msg, int min, int max); /**< -1 ERROR */
int getChar(char* ret, char* msg, char* error_msg);
int getString(char* ret, char* msg, char* error_msg, int min, int max);
int getFloat(float* ret, char* msg, char* error_msg, int min, int max);
