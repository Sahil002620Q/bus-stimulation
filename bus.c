#include <stdio.h>
#include <stdbool.h>

struct bus
{
    char passenger[20];
    int seatnumber;
    bool status;
};

int main()
{
    struct bus seat[20]; // max seat
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
        printf("---Bus reservation stimulator---\n");
        printf("1. view seats status\n");
        printf("2. Book seat \n");
        printf("3. cancel seat\n");
        printf("4. exit\n");

        printf("Enter your choice : \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("available seats \n");
            for (int i = 1; i <= 20; i++)
            {
                // printf("Seat 1 : [free]");
                printf("Seat %d : %s\n", seat[i].seatnumber, seat[i].status ? "booked" : "free");
            }
            break;

        case 2:
            int seatx;
            printf("enter seat number you want to book :", seatx);
            scanf("%d", &seatx);
            if (seatx < 1 || seatx > 20)
            {
                printf("Enter a vaild seat number ");
            }
            else if (seat[seatx].status == true)
            {
                printf("seat number %d is already booked", seatx);
            }
            else
            {
                printf("enter name :");
                scanf("%s", seat[seatx].passenger);
                seat[seatx].status = true;
                printf("seat number %d is coniformed by %s\n", seat[seatx].seatnumber, seat[seatx].passenger);
                // logic to book seat
            }
            break;

        case 3:
            int cancel;
            printf("Enter seat number, you want to cancel : ");
            scanf("%d", &cancel);

            if (cancel < 1 || cancel > 20)
            {
                printf("The seat doesn't exists\n");
            }
            else if (seat[cancel].status == false)
            {
                printf("That seat is already vacent\n");
            }
            else
            { // seat[cancel].status = true by default
                seat[cancel].status = false;
                printf("cancellation confirmed for seat number %d\n", cancel);
            }
            break;

        case 4:
            printf("exit loop ");
            loop = false;
            break;
        }
        // end of display
    }

    // struct bus p1;
    // //will not work p1.passanger[20] = "sahil";
    // strcpy(p1.passenger,"sahil kumar");
    // printf("passenger name : %s",p1.passenger);
    // printf("booking status : ");
}
