#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

enum choice
{
     e_create = 1,
     e_search,
     e_edit,
     e_delete,
     e_display,
     e_save,
     e_exit
};

typedef enum status
{ 
    e_back = -1,
    e_failure,
    e_success
}status;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);

#endif
