#include <stdbool.h>
#include "contact.h"

bool validatePhNum(AddressBook *addressBook,char *phone);
bool validateEmail(char* email);
int search(AddressBook *addressBook,int choice,int *serialVal);
int savePhNum(AddressBook *addressBook);
int saveEmail(AddressBook *addressBook);
bool myStrcmp(const char* str1,const char* str2);
int saveName(AddressBook *addressBook);
bool back(char *option);