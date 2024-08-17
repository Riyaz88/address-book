#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "functions.h"
#include <stdbool.h>

void createContact(AddressBook *addressBook)
{
    //save user name
    char flag0 = 1,retval;
    while(flag0)
    {
        retval = saveName(addressBook);
        if(retval == e_failure)
        continue;
        if(retval == e_back)
        return;
        flag0 = 0;
        
    }
    //save phnum and name
    char flag1=1,flag2=1,retVal1,retVal2;
    while(flag1)
    {
        retVal1 = savePhNum(addressBook);
        if(retVal1 == e_failure)//phNum validation failed
        continue;

        if(retVal1 == e_back) //user entered back '<<'
        return;
        //phNum validation success
        flag1=0;
        while(flag2)
        {
            retVal2 = saveEmail(addressBook);
            if(retVal2 == e_failure)//email validation failed
            continue;
            
            if(retVal2 == e_back) //user entered back '<<'
            return; 
            //email validation success
            flag2 = 0;
            addressBook->contactCount++;
            printf("Contact saved succesfully !\n");  
              
        }           
    }   
}

void searchContact(AddressBook *addressBook) 
{
    int choice,serialCount,serialNo,serialVal[100];
    //searching for contact details
    do{
        printf("\nSearch Contact By :\n");
        printf("1. Name\n2. Phone No\n3. Email\n4. Back\n");
        printf("Enter your choice: ");
        if(scanf("%d", &choice) != 1)
        {
            while(getchar() != '\n');
        } 
        if(choice == 4)
        return;
        serialCount = search(addressBook,choice,serialVal);

    }while((choice != 1 && choice != 2 && choice != 3) || serialCount < 0);

    //display contact details
    printf("\nEnter Serial No : ");
    if(scanf("%d", &choice) != 1)
    {
        while(getchar() != '\n');
    } 
    if(serialNo > 0 && serialNo <= serialCount)
    {
        printf("\nName           Phone No      Email          \n");
        printf("%s     ",addressBook->contacts[serialVal[serialNo]].name);
        printf("%s     ",addressBook->contacts[serialVal[serialNo]].phone);
        printf("%s     \n",addressBook->contacts[serialVal[serialNo]].email);
    }
    else
    printf("Invalid Serial Number !");
        
}

void editContact(AddressBook *addressBook)
{
    int choice1,serialNo,serialCount,serialVal[100];
    //search for contact details
    do{
        printf("\nSearch Contact by :\n");
        printf("1. Name\n2. Phone No\n3. Email\n4. Back\n");
        printf("Enter your choice : ");
        if(scanf("%d", &choice1) != 1)
        {
            while(getchar() != '\n');
        } 
        if(choice1 == 4)
        return;
        serialCount = search(addressBook,choice1,serialVal);
        }while((choice1 != 1 && choice1 != 2 && choice1 != 3) || serialCount < 0);
        
    //contacts details found allow the user to edit
    printf("\nEnter Serial No : ");
    if(scanf("%d", &serialNo) != 1)
    {
        while(getchar() != '\n');
    } 

    if(serialNo < 1 || serialNo > serialCount)
    {
        printf("Invalid Serial Number !");
        return;
    }
    //edit user details
    int choice2,flag = 1;
    do{
        printf("\nEdit :\n");
        printf("1. Name\n2. Phone No\n3. Email\n4. Back\n");
        printf("Enter any choice : ");
        scanf("%d",&choice2);
        if(choice2 == 4)
        return;
        char str[50];

        if(choice2 == 1)
        {
            printf("Enter new name : ");
            scanf(" %[^\n]",str);
            strcpy(addressBook->contacts[serialVal[serialNo]].name,str);
            printf("Name Changed Successfully !\n");
            flag = 0;
        }
        else if(choice2 == 2)
        {
            while(flag)
            {
                printf("Enter new Ph No : ");
                scanf(" %[^\n]",str);
                if(str[0] == '<' && str[1] == '<' && str[2] == '\0')
                break;
                if(validatePhNum(addressBook,str))
                {   flag = 0;
                    strcpy(addressBook->contacts[serialVal[serialNo]].phone,str);
                    printf("Phone Number Saved Successfully !\n"); 
                }
            }
        }
        else if(choice2 == 3)
        {
            while(flag)
            {
                printf("Enter new email : ");
                scanf(" %[^\n]",str);
                if(str[0] == '<' && str[1] == '<' && str[2] == '\0')
                break;
                if(validateEmail(str))
                {   flag = 0;
                    strcpy(addressBook->contacts[serialVal[serialNo]].email,str);
                    printf("Email Changed Succesfully !\n");
                }
            }
        }
        else
        printf("Invalid choice !\n");

    }while((choice2 != 1 && choice2 != 2 && choice2 != 3) || flag);
}

void deleteContact(AddressBook *addressBook)
{
	//searching for contact details
    int choice,serialCount,serialNo,serialVal[100];
    do{
        printf("\nSearch Contact by :\n");
        printf("1. Name\n2. Phone No\n3. Email\n4. Back\n");
        printf("Enter your choice : ");
        if(scanf("%d", &choice) != 1)
        {
            while(getchar() != '\n');
        } 
        if(choice == 4)
        return;
        serialCount = search(addressBook,choice,serialVal);
    }while((choice != 1 && choice != 2 && choice != 3) || serialCount < 0);
    
    //contacts details found allow the user  to delete
    printf("\nEnter Serial No : ");
    if(scanf("%d", &serialNo) != 1)
    {
        while(getchar() != '\n');
    } 
    if(serialNo < 1 || serialNo > serialCount)
    {
        printf("Invalid Serial Number !");
        return;
    }
    for(int i = serialVal[serialNo];i < addressBook->contactCount-1;i++)
    {
        strcpy(addressBook->contacts[i].name,addressBook->contacts[i+1].name);
        strcpy(addressBook->contacts[i].phone,addressBook->contacts[i+1].phone);
        strcpy(addressBook->contacts[i].email,addressBook->contacts[i+1].email);
    }
    addressBook->contactCount--;
    printf("Contact deleted successfully !\n");
  
}

void listContacts(AddressBook *addressBook) 
{
    printf("\n%-25s%-25s%-25s\n\n","Name","Phone No","Email");
    for(int i = 0;i < addressBook->contactCount;i++)
    {
        printf("%-25.30s",addressBook->contacts[i].name);
        printf("%-25.30s",addressBook->contacts[i].phone);
        printf("%-25.30s\n",addressBook->contacts[i].email);
    }    
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}
