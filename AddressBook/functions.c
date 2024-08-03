#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"
#include "contact.h"

int saveName(AddressBook *addressBook)
{
    char name[50];
    printf("\nEnter Name     : ");
    scanf(" %[^\n]",name);
    if(name[0] == '<' && name[1] == '<' && name[2] == '\0')
    return -1;

    int index = 0;
    while(name[index] != '\0')
    {
       if((name[index] < 'a' || name[index] > 'z') && (name[index] < 'A' || name[index] > 'Z'))
       break;
       index++;
    }
    if(name[index] == '\0')
    {
        strcpy(addressBook->contacts[addressBook->contactCount].name,name);
        return 1;
    }
    else
    {
        printf("Name must contains alphabets only !(Enter '<<' for Back)\n");
        return 0;
    }
}

int savePhNum(AddressBook *addressBook)
{
    char phone[50];
    printf("\nEnter Phone No : ");
    scanf(" %[^\n]",phone);

    if(phone[0] == '<' && phone[1] == '<' && phone[2] == '\0')
    return 1;
    //passing the input values for phone number validation
    if(validatePhNum(addressBook,phone))
    {
        strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);
        return 2;
    }
    return 0;
}

int saveEmail(AddressBook *addressBook)
{
    char email[50];
    printf("\nEnter Email : ");
    scanf(" %[^\n]",email);

    if(email[0] == '<' && email[1] == '<' && email[2] == '\0')
    return 1;
    //passing the input values for email validation
    if(validateEmail(email))
    {
        strcpy(addressBook->contacts[addressBook->contactCount].email,email);
        return 2;
    }
    return 0;
}

bool validatePhNum(AddressBook *addressBook,char *phone)
{
    if(strlen(phone) == 10)
    {  
        int index1 = 0;
        while(phone[index1])
        {
            if(phone[index1] < '0' || phone[index1] > '9')
            break;
            index1++;
        }
        if(index1 == strlen(phone))
        {   int index2;
            for(index2 = 0;index2 < addressBook->contactCount;index2++)
            {
                if(!strcmp(phone,addressBook->contacts[index2].phone))
                break;  
            }

            if(index2 == addressBook->contactCount)
            return true;
            else
            {   printf("Mobile Number already exist !(Enter '<<' for Back)\n");
                return false;  
            } 
        }
        else
        {   printf("Invalid Mobile Number !\n");
            return false;
        }  
    }
    else 
    {   printf("Phone No must be Ten digits !(Enter '<<' for Back)\n");
        return false;  
    }
}

bool validateEmail(char *email)
{
    int index = 0;
    while (email[index])
    {
        if(email[index] == '@')
        break;
        index++;
    }
    char *ptr = strstr(email,".com");
    
    if(index != strlen(email) && ptr != NULL)
    return true;
    else
    {
    printf("Invalid email !(Enter '<<' for Back)\n");
    return false;
    }
}

int search(AddressBook *addressBook,int choice,int *serialVal)
{
    char option[50];
    int index = 0,index1,serialCount=0;
    do{
    //seraching the names in addressbook
    if(choice == 1)
    {
        printf("\nEnter Name : ");
        scanf(" %[^\n]",option);
        if(option[0] == '<' && option[1] == '<' && option[2] == '\0')
        return -1;
        for(index = 0;index < addressBook->contactCount;index++)
        {  
            index1 = 0;
            while(option[index1] != '\0') 
            {
                if(option[index1] != addressBook->contacts[index].name[index1])
                break;
                index1++;
            } 
            if(option[index1] == '\0')
            {
                serialCount++;
                if(serialCount == 1)
                printf("\nList of Contacts : \n");
                
                serialVal[serialCount] = index;
                printf("%d. %s\n",serialCount,addressBook->contacts[index].name);
            }
        }
    }
    //seraching the phone numbers in addressbook
    else if(choice == 2)
    {
        printf("\nEnter Phone : ");
        scanf(" %[^\n]",option);
        if(option[0] == '<' && option[1] == '<' && option[2] == '\0')
        return -1;
        for(index = 0;index < addressBook->contactCount;index++)
        {  
            index1 = 0;
            while(option[index1] != '\0') 
            {
                if(option[index1] != addressBook->contacts[index].phone[index1])
                break;
                index1++;
            } 
            if(option[index1] == '\0')
            {
                serialCount++;
                if(serialCount == 1)
                printf("\nList of Contacts : \n");
                serialVal[serialCount] = index;
                printf("%d. %s\n",serialCount,addressBook->contacts[index].phone);
            }
        }
    }
    //seraching the email adresses in addressbook
    else if(choice == 3)
    {
        printf("\nEnter Email : ");
        scanf(" %[^\n]",option);
        if(option[0] == '<' && option[1] == '<' && option[2] == '\0')
        return -1;
        for(index = 0;index < addressBook->contactCount;index++)
        {  
            index1 = 0;
            while(option[index1] != '\0') 
            {
                if(option[index1] != addressBook->contacts[index].email[index1])
                break;
                index1++;
            } 
            if(option[index1] == '\0')
            {
                serialCount++;
                if(serialCount == 1)
                printf("\nList of Contacts : \n");
                
                serialVal[serialCount] = index;
                printf("%d. %s\n",serialCount,addressBook->contacts[index].email);
            }
        }
    }
    else
    {
        printf("Invalid Choice !\n");
        break;
    }
    
    if(serialCount == 0)
    {
        printf("No results Found !Enter '<<' for Back)\n");
    }
    }while(serialCount == 0); 
    return serialCount;
}

bool myStrcmp(const char* str1,const char* str2)
{
    while(*str1 != '\0')
    {
        if(*str1 != *str2 && *str1 != (*str2)+32 && *str1 != (*str2)-32)
        return false;
        str1++;
        str2++;
    }
    if(*str1 == '\0' && *str2 == '\0')
    return true;
    else
    return false;
}