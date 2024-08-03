#include <stdio.h>
#include "file.h"
#include "functions.h"
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void saveContactsToFile(AddressBook *addressBook) {
   FILE * fptr;
   if((fptr = fopen("contact.csv","w+")) == NULL)
   {
    fprintf(stderr,"Can't open file !\n");
    return;
   }

   fprintf(fptr,"#%d\n",addressBook->contactCount);
   for(int i = 0;i < addressBook->contactCount;i++)
   {
       fprintf(fptr,"%s%c%s%c%s\n",addressBook->contacts[i].name,',',addressBook->contacts[i].phone,',',addressBook->contacts[i].email);
   }
   fclose(fptr);
   printf("Contacts Details Saved Successfully !\n");
}

void loadContactsFromFile(AddressBook *addressBook) {

   FILE * fptr;
   if((fptr = fopen("contact.csv","r+")) == NULL)
   {
    fprintf(stderr,"Can't open file !\n");
    return;
   }
   char count[10],buffer[100],ch;
   fgetc(fptr);
   fscanf(fptr,"%s",count);
   fgetc(fptr);
   addressBook->contactCount = atoi(count);   
   for(int i = 0;i < addressBook->contactCount;i++)
   {
      fgets(buffer,100,fptr);
      strcpy(addressBook->contacts[i].name,strtok(buffer,","));
      strcpy(addressBook->contacts[i].phone,strtok(NULL,","));
      strcpy(addressBook->contacts[i].email,strtok(NULL,"\n"));
   }
   fclose(fptr);
}
