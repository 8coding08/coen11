#include <stdio.h>
//amount of people queue can hold
#define SIZE 5
char INSTRUCTIONS[200] = "Commands:\n[a]dd - Adds player to waitlist\n[l]ist - List waitlist\n[n]ext - Get next person from waitlist\n[q]uit - Quits program\n";
//number to increment as queue grows
int counter = 0;

//waitlist controller arrays
char names[SIZE][20];
char symptoms[SIZE][20];

int main()
{
    printf(INSTRUCTIONS);
    //start a loop for command handler
    while (1 == 1)
    {

        //ask for command and direct user to specific function
        char option;
        scanf("%c", &option);
        if (option == 'q')
            break;
        if (option == 'a')
        {
            if (SIZE == counter)
            {
                printf("The waitlist is full! Maximum of %d people reached.\n", SIZE);
            }
            else
            {
                insert();
            }
        }
        if (option == 'l')
            print();
        if (option == 'n')
            next();
    }
    return 0;
    //end of main
}

/*
INSERT FUNCTION:
Adds the <name> and <symptom> to the end of the list
*/
void insert()
{
    //define vars
    char name[20];
    char symptom[20];
    //prompt for name
    printf("Welcome! What is your name?\n");
    scanf("%s", &name);
    //check if name length is too long
    //check if name already is in use
    if (isRepeat(name) == 1)
    {
        //if name is in use tell them and have them pick again.
        printf("That name is already in use! Please try the 'a' command again.\n");
        return;
    }
    else
    {
        //if name is NOT in use ask for their symptom
        printf("Hey there %s! Please describe your symptom\n", name);
        scanf("%s", &symptom);
        if (strlen(name) > 20 || strlen(symptom) > 20)
        {
            printf("Your symptom and name must be less than 20 characters! Please try the 'a' command again.\n");
            return;
        }
        else
        {
            //confirmation that they have joined the queue with provided queue number
            printf("You are #%d in the queue! Please wait for your turn\n", counter + 1);

            //add user to the queue
            strcpy(names[counter], name);
            strcpy(symptoms[counter], symptom);
            //increment the queue counter
            counter++;
        }
    }
}

//Prints out the entire waitlist
void print()
{
    if(counter == 0) return printf("The waitlist is currently empty.\n");
    int i;
    printf("+======[ Current Waitlist ]======+\n");
    printf("[#] |   Name -> Symptom    \n");
    for (i = 0; i < counter; i++)
    {
    printf("#%d  | %s -> %s\n", i + 1, names[i], symptoms[i]);
    }
    printf("+======[     By: Sam      ]======+\n");
}

void next()
{
    if (counter == 0)
    {
        printf("The waitlist is empty!\n");
    }
    else
    {
        printf("The next person is %s", names[0]);
        int i;
        for (i = 0; i < SIZE - 1; i++)
        {
            strcpy(names[i], names[i + 1]);
            strcpy(names[i + 1], "");
            strcpy(symptoms[i], symptoms[i + 1]);
            strcpy(symptoms[i + 1], "");
        }
        counter--;
        printf("\n");
        print();
    }
}
/* 
Helper function to check if a name already exists in queue
@param {char string} The name to test
@return {int} 1 if is duplicate, 0 if not a duplicate
*/
int isRepeat(char name[20])
{
    int i;
    int val = 0;
    for (i = 0; i < SIZE; i++)
    {
        if (strcmp(name, names[i]) == 0)
        {
            val = 1;
        }
    }
    return val;
}

