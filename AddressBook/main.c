#include <stdio.h>
#include "contact.h"

int main() {
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Save Contact\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        if(scanf("%d", &choice) != 1)
        {
            while(getchar() != '\n');
        } 
        switch (choice) {
            case e_create:
                createContact(&addressBook);
                break;
            case e_search:
                searchContact(&addressBook);
                break;
            case e_edit:
                editContact(&addressBook);
                break;
            case e_delete:
                deleteContact(&addressBook);
                break;
            case e_display:
                listContacts(&addressBook);
                break;
            case e_save:
                saveContactsToFile(&addressBook);
            case e_exit:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    
    return 0;
}
