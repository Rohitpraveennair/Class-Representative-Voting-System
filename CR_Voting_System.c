#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define candidates_max 5          //Used to assign a variable (candidates_max) to value 5 which will be used throughout the program.
#define voters_max 70             //Used to assign a variable (voters_max) to value 70 which will be used throughout the program.
//------------------------------------------------------------
typedef struct {
    int id;
    char name[30];
    int votes;
} Candidate;

typedef struct {
    int collegeNumber;
    char name[30];
    char branch[30];
    int voted;
} Voter;

Candidate candidates[candidates_max];
Voter voters[voters_max];

int numCandidates = 0;
int numVoters = 0;
//------------------------------------------------------------
int AdminLogin() {
    system ("COLOR 0F");
    char key[25];
    printf("\n  Enter the admin passkey: ");
    scanf("%s", key);
    system("cls");
    if (strcmp(key, "pscp") == 0)        // Check if the passkey is correct
    {
        return 1;
       }
    else
    {
      printf("  Invalid passkey. Access denied.\n");
      return 0;
    }
}
//............................................
void Candidate_Register() {
    int num=0;
    printf("\n  Enter Number Of Candidates to Register: ");
    scanf("%d", &num);
    system("cls");
    for(int i=0;i<num;i++)
    {
    if (numCandidates >= candidates_max) {
        printf("  Maximum number of candidates reached.\n");
        printf("  Going to Admin Panel in 5 secs...");
        sleep(5);
        system ("cls");
        return;
    }
    Candidate candidate;
    printf("\n  Enter the Candidate ID: ");
    scanf("%d", &candidate.id);
    printf("  Enter the Candidate's Name: ");
    scanf("%s", candidate.name);
    candidate.votes = 0;
    candidates[numCandidates++] = candidate;
    printf("  Candidate registered successfully.\n\n");

    }
    printf("  Going to Admin Panel in 5 secs...");
    sleep(5);
    system ("cls");
}
//....................................................................
    void Display_Results() {
    printf("\n  Candidate\t\tVotes\n");
    int max=0,same=0;
    char *N,random;    //pointer N stores the memory address of candidates name (Dynamic memory allocation)
    for (int i = 0; i < numCandidates; i++) {
        printf("   %s \t\t\t%d\n", candidates[i].name, candidates[i].votes);
        if(candidates[i].votes>max)          //used to find the candidate with maximum votes
        {
            N=candidates[i].name;
            max=candidates[i].votes;
            same=0;
         }
        else if(candidates[i].votes==max){    //checks if they have same number of votes
            same=1 ;                           //flag variable
        }
        }
        if(same==1)
        {printf("  IT IS A TIE\n");
        }
    if(same==0)
    {
    printf("\n  Class Representative : %s\t\t%d votes\n",N,max);
    printf("  Congrats To the New C.R\n\n");
    }
    printf("  Enter any key to go back to Admin Panel? : ");
    scanf("%s", &random);
    system ("cls");
}

//...................................................................


void AdminPanel() {
    int choice;
    do {
        printf("\n  Admin Panel\n");
        printf("  1. Register Candidate\n");
        printf("  2. Display Results\n");
        printf("  3. Go Back to Home Page\n");
        printf("  Enter your choice: ");
        scanf("%d", &choice);
        system ("cls");                               //system function to clear the screen
        switch (choice) {
            case 1:
                Candidate_Register();                 //Calls this function to register candidates
                break;
            case 2:
                Display_Results();                    //Calls this function to display results after voting
                break;
            case 3:
                printf(" \n  Going to Home Page in 3 secs...");
                sleep(3);
                system ("cls");
                break;
            default:
                printf("  Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);                         //do-while loop runs until user wants to exit
}

//-------------------------------------------------------------------------------------------

    void Voter_Register() {
    if (numVoters >= voters_max) {
        printf("\n  Maximum number of voters reached.\n\n");
        printf("  Going to Voter Panel in 5 secs...");
        sleep(5);
        system ("cls");
        return;
    }
    Voter voter;
    printf("\n  Enter your Registration number [Example: 23001]: ");
    scanf("%d", &voter.collegeNumber);
    for (int i = 0; i < numVoters; i++)             // Check if the voter is already registered
    {
    if (voters[i].collegeNumber == voter.collegeNumber)
    {
    printf("\n  You have already registered.\n");
    printf("  Please cast your vote!!!\n\n");
    printf("  Going to Voter Panel in 5 secs...");
    sleep(5);
    system ("cls");
    return;
    }
    }
    printf("  Enter your name: ");
    scanf("%s", voter.name);
    voter.voted = 0;                       //initialised it to 0 to keep track if the voter has voted or not
    voters[numVoters++] = voter;
    printf("  Voter registered successfully.\n\n");
    printf("  Please cast your vote!!!\n\n");
    printf("  Going to Voter Panel in 5 secs...");
    sleep(3);
    system ("cls");
}

//......................................................

    void Vote_Cast() {
    int collegeNumber,check=0;
    printf("\n  Enter your Registration number [Example: 23001]:  ");
    scanf("%d", &collegeNumber);
    for (int i = 0; i < numVoters; i++)                // Check if the voter is registered
    {
    if (voters[i].collegeNumber == collegeNumber) {
    if (voters[i].voted)                               // Check if the voter has already voted
    {
    printf("  You have already cast your vote.\n\n");
    printf("  Going to Voter Panel in 5 secs...");
    sleep(5);
    system ("cls");
    return;
    }
    printf("  Candidates:\n");
    for (int j = 0; j < numCandidates; j++) {
    printf("  %d ---> %s\n\n", candidates[j].id, candidates[j].name);
    }
    int candidateId;
    printf("  Enter the candidate ID you want to vote for: ");
    scanf("%d", &candidateId);
    for (int j = 0; j < numCandidates; j++)            // Find the candidate and increment their votes
    {
    if (candidates[j].id == candidateId) {
    check=1;
    candidates[j].votes++;
    break;
    }}
    if(check==0)
    {
    printf("  Invalid ID\n");
    printf("  Vote Considered as NOTA\n\n");
    }
    voters[i].voted = 1;
    printf("  Vote cast successfully.\n\n");
    printf("  Please leave the counter after 3 secs...");
    sleep(3);
    system ("cls");
    return;
    }
    }
    printf("  You are not registered as a voter.\n");
    printf("  Please Register.\n");
    }

    //..............................................................

    void VoterPanel() {
    int choice;
    do {
        printf("\n  Voter Panel\n");
        printf("  1. Register Voter\n");
        printf("  2. Cast Vote\n");
        printf("  3. Go Back to Home Page\n\n");
        printf("  Please Register First\n\n");
        printf("  Enter your choice: ");
        scanf("%d", &choice);
        system ("cls");                         //system function to clear screen
        switch (choice) {
            case 1:
                Voter_Register();               //calls VoterRegister() function to register voter details
                break;
            case 2:
                Vote_Cast();                    //calls VoteCast() function for registered voters to vote
                break;
            case 3:
                printf("\n  Going to Home Page in 3 secs...");
                sleep(3);                         //pauses program execution by 3 secs
                system ("cls");
                break;
            default:
                printf("  Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);
    }

    //---------------------------------------------------------------------------------------------

void HomePage() {
    int choice;
    do {
        system ("COLOR E4");                     //system function which is used to give font and background colour
        printf("\n  C.R Voting System\n");
        printf("  1. Admin\n");
        printf("  2. Voter\n");
        printf("  3. Exit\n");
        printf("\n  Enter your choice: ");
        scanf("%d", &choice);
        system("cls");
        switch (choice) {
            case 1:
                if (AdminLogin()) {
                    system ("COLOR B0");
                    AdminPanel();              //calls AdminPanel
                }
                break;
            case 2:
                system ("COLOR 7C");
                VoterPanel();                  //calls VoterPanel
                break;
            case 3:
            if (AdminLogin()) {                //allows only admin to exit the program
                    system ("COLOR 7C");
                    printf("\n  Exiting the program.\n");
                break;
                }
                choice=4;
                break;

            default:
                printf("  Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);                 //Using do-while loop so that it runs until the user wants to exit
}

//---------------------------------------------------------------------------------------------------

int main() {
    HomePage();
    return 0;
}

//***//

