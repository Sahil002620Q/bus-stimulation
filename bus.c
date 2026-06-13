#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct bus
{
    char passanger[20];
    int seatnumber; 
    bool status;
};

int main() {


    
    int choice;
    bool loop = true;
    while (loop)
    {
        //display
        printf("---Bus reservation stimulator---\n");
        printf("1. view seats status\n");
        printf("2. Book seat \n");
        printf("3. cancel seat\n");
        printf("4. exit\n");

        printf("Enter your choice : \n");
        scanf("%d",&choice);

       
        switch(choice){
            case 1:
            printf("available seats ");
            //1 is free
            //2 is occupied
            break;

            case 2:
            printf("book seat enter name ,seatpreffrence  ");
            //1 is free
            //2 is occupied
            break;

            case 3:
            printf("seat cancel ,enter name ");
            //1 is free
            //2 is occupied
            break;

            case 4:
            printf("exit loop ");
            loop = false;
            break;
        }
        //end of display
    }
    

    struct bus p1;
    //will not work p1.passanger[20] = "sahil"; 
    strcpy(p1.passanger,"sahil kumar");
    printf("passenger name : %s",p1.passanger);
    printf("booking status : ");

}
