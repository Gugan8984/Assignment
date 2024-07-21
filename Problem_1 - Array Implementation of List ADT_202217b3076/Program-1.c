#include <stdio.h>
#include <stdlib.h>

#define MAX 20

/* Define the required functions to create a list, insert into the list,
delete an element from the list, search and display the list */
void create();
void insert();
void deletion();
void search();
void display();

int b[MAX], n = 0;

int main() {
    int ch;
    char g = 'y';
    do {
        printf("\nMain Menu");
        printf("\n1. Create\n2. Delete\n3. Search\n4. Insert\n5. Display\n6. Exit\n");
        printf("\nEnter your Choice: ");
        scanf("%d", &ch);

        /* The following switch will call the appropriate choice provided by the user */
        switch(ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("\nEnter the correct choice:");
        }
        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &g);
    } while(g == 'y' || g == 'Y');
    return 0;
}

void create() {
    int i;  // Declare the loop variable outside the for loop
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    if (n > MAX) {
        printf("\nNumber of nodes exceeds the maximum allowed. Setting to MAX (%d).\n", MAX);
        n = MAX;
    }
    /* The loop should run till we get the ‘n’ inputs */
    for(i = 0; i < n; i++) {
        printf("\nEnter the Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    int pos, i;  // Declare the loop variable outside the for loop
    printf("\nEnter the position you want to delete: ");
    scanf("%d", &pos);
    if(pos < 0 || pos >= n) {
        printf("\nInvalid Location.\n");
    } else {
        for(i = pos; i < n - 1; i++) {
            b[i] = b[i + 1];
        }
        n--;
        printf("\nThe Elements after deletion:");
        for(i = 0; i < n; i++) {
            printf("\t%d", b[i]);
        }
        printf("\n");
    }
}

void search() {
    int e, found = 0, i;  // Declare the loop variable outside the for loop
    printf("\nEnter the Element to be searched: ");
    scanf("%d", &e);
    for(i = 0; i < n; i++) {
        if(b[i] == e) {
            printf("Value is in the %d Position\n", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Value %d is not in the list.\n", e);
    }
}

void insert() {
    int pos, p, i;  // Declare the loop variable outside the for loop
    printf("\nEnter the position you need to insert: ");
    scanf("%d", &pos);
    if(pos < 0 || pos > n || n >= MAX) {
        printf("\nInvalid Location or List is Full.\n");
    } else {
        for(i = n; i > pos; i--) {
            b[i] = b[i - 1];
        }
        printf("\nEnter the element to insert: ");
        scanf("%d", &p);
        b[pos] = p;
        n++;
        printf("\nThe list after insertion:\n");
        display();
    }
}

void display() {
    int i;  // Declare the loop variable outside the for loop
    printf("\nThe Elements of The list ADT are:");
    for(i = 0; i < n; i++) {
        printf("\n%d", b[i]);
    }
    printf("\n");
}
