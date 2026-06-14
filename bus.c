#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct bus
{
    char passenger[20];
    int seatnumber;
    bool status;
};

struct bus seat[20]; // max seat

void waitforenter()
{
    printf("\nEnter to go back to main menu.\n");
    getchar(); //capture previous buffer  ----?
    getchar(); //capture enter --non buffered
}

void viewseats(){
    system("clear");
    printf("available seats \n");
    for (int i = 1; i <= 20; i++)
    {
        printf("Seat %d : %s\n", seat[i].seatnumber, seat[i].status ? "booked" : "free");
    }    
    waitforenter();
}

void bookseat(){
    system("clear");
    int book;
    printf("enter seat number you want to book : ", book);
    scanf("%d", &book);
    if (book < 1 || book > 20)
    {
        printf("Enter a vaild seat number ");
        waitforenter();
    }
    else if (seat[book].status == true)
    {
        printf("seat number %d is already booked", book);
        waitforenter();
    }
    else
    {
        printf("enter name :");
        scanf("%s", seat[book].passenger);
        seat[book].status = true;
        printf("seat number %d is coniformed by %s\n", seat[book].seatnumber, seat[book].passenger);
        // logic to book seat

        waitforenter();
    }
}

void cancelseat(){
    system{"clear"};
    int cancel;
    printf("Enter seat number, you want to cancel : ");
    scanf("%d", &cancel);

    if (cancel < 1 || cancel > 20)
    {
        printf("The seat doesn't exists\n");
        waitforenter();
    }
    else if (seat[cancel].status == false)
    {
        printf("That seat is already vacent\n");
        waitforenter();
    }
    else
    { 
        seat[cancel].status = false;
        printf("cancellation confirmed for seat number %d\n", cancel);
        waitforenter();
    }
}

int main()
{
    //empty seats
    for (int i = 1; i <= 20; i++)
    {
        seat[i].seatnumber = i; // i+1
        seat[i].status = false; // false = free
    }

    int choice;
    bool loop = true;
    while (loop)
    {
        // display
        system("clear");
        printf("---Bus reservation stimulator---\n");
        printf("1. view seats status\n");
        printf("2. Book seat \n");
        printf("3. cancel seat\n");
        printf("4. exit\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            viewseats();
            break;

        case 2:
            bookseat();
            break;

        case 3:
            cancelseat();
            break;

        case 4:
            printf("exiting loop.... ");
            loop = false;
            break;
        }
        // end of display
    }
}
