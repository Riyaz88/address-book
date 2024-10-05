/* Name : Riyaz Ahamed IB
   Date : 18/08/2024
   Description : AddressBook
*/
#include <stdbool.h>
#include "contact.h"

bool validatePhNum(AddressBook *addressBook,char *phone);
bool validateEmail(char* email);
int search(AddressBook *addressBook,int *serialVal,char *(*funPtr)(Contact *));
int savePhNum(AddressBook *addressBook);
int saveEmail(AddressBook *addressBook);
bool myStrcmp(const char* str1,const char* str2);
int saveName(AddressBook *addressBook);
bool back(char *option);
char *name(Contact *contacts);
char *phone(Contact *contacts);
char *email(Contact *contacts);
int validateChoice(AddressBook *addressBook,int *serialVal,int choice);