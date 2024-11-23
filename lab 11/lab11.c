#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 5


typedef struct {
    char name[20];
    char team[20];
} Player;

typedef struct {
    char type[10];  
    char arm[5]; 
    Player ply;
} Bowler;

typedef struct {
    char type[10];  
    char handed[8]; 
    Bowler ply2;
} Batsman;


Bowler bowlers[MAX_PLAYERS];
Batsman batsmen[MAX_PLAYERS];
int bowlerCount = 0;
int batsmanCount = 0;

void createBowler();
void createBatsman();
void readData();
void updateData();
void deleteData();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Create Bowler\n");
        printf("2. Create Batsman\n");
        printf("3. Read Data\n");
        printf("4. Update Data\n");
        printf("5. Delete Data\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1: createBowler(); break;
            case 2: createBatsman(); break;
            case 3: readData(); break;
            case 4: updateData(); break;
            case 5: deleteData(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);
}


void createBowler() {
    if (bowlerCount < MAX_PLAYERS) {
        printf("\nEnter Bowler Details:\n");
        printf("Name: ");
        fgets(bowlers[bowlerCount].ply.name, 20, stdin);
        strtok(bowlers[bowlerCount].ply.name, "\n"); 
        printf("Team: ");
        fgets(bowlers[bowlerCount].ply.team, 20, stdin);
        strtok(bowlers[bowlerCount].ply.team, "\n");
        printf("Type (seamer/pacer/spinner): ");
        fgets(bowlers[bowlerCount].type, 10, stdin);
        strtok(bowlers[bowlerCount].type, "\n");
        printf("Arm (left/right): ");
        fgets(bowlers[bowlerCount].arm, 5, stdin);
        strtok(bowlers[bowlerCount].arm, "\n");
        bowlerCount++;
        printf("Bowler added successfully.\n");
    } else {
        printf("Maximum number of bowlers reached.\n");
    }
}

void createBatsman() {
    if (batsmanCount < MAX_PLAYERS) {
        printf("\nEnter Batsman Details:\n");
        printf("Name: ");
        fgets(batsmen[batsmanCount].ply2.ply.name, 20, stdin);
        strtok(batsmen[batsmanCount].ply2.ply.name, "\n");
        printf("Team: ");
        fgets(batsmen[batsmanCount].ply2.ply.team, 20, stdin);
        strtok(batsmen[batsmanCount].ply2.ply.team, "\n");
        printf("Batting Type (top/middle/lower): ");
        fgets(batsmen[batsmanCount].type, 10, stdin);
        strtok(batsmen[batsmanCount].type, "\n");
        printf("Handedness (lefty/righty): ");
        fgets(batsmen[batsmanCount].handed, 8, stdin);
        strtok(batsmen[batsmanCount].handed, "\n");
        batsmanCount++;
        printf("Batsman added successfully.\n");
    } else {
        printf("Maximum number of batsmen reached.\n");
    }
}

void readData() {
    printf("\n--- Bowler Data ---\n");
    for (int i = 0; i < bowlerCount; i++) {
        printf("Bowler %d: Name: %s, Team: %s, Type: %s, Arm: %s\n", 
                i + 1, bowlers[i].ply.name, bowlers[i].ply.team, bowlers[i].type, bowlers[i].arm);
    }
    printf("\n--- Batsman Data ---\n");
    for (int i = 0; i < batsmanCount; i++) {
        printf("Batsman %d: Name: %s, Team: %s, Type: %s, Handed: %s\n", 
                i + 1, batsmen[i].ply2.ply.name, batsmen[i].ply2.ply.team, batsmen[i].type, batsmen[i].handed);
    }
}

void updateData() {
    int choice, index;
    printf("\nUpdate Options:\n");
    printf("1. Update Bowler\n");
    printf("2. Update Batsman\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();
    if (choice == 1) {
        printf("Enter Bowler Index (1-%d): ", bowlerCount);
        scanf("%d", &index);
        getchar();
        if (index > 0 && index <= bowlerCount) {
            index--;
            printf("Updating Bowler %d:\n", index + 1);
            printf("New Name: ");
            fgets(bowlers[index].ply.name, 20, stdin);
            strtok(bowlers[index].ply.name, "\n");
            printf("New Team: ");
            fgets(bowlers[index].ply.team, 20, stdin);
            strtok(bowlers[index].ply.team, "\n");
            printf("New Type: ");
            fgets(bowlers[index].type, 10, stdin);
            strtok(bowlers[index].type, "\n");
            printf("New Arm: ");
            fgets(bowlers[index].arm, 5, stdin);
            strtok(bowlers[index].arm, "\n");
            printf("Bowler updated successfully.\n");
        } else {
            printf("Invalid index.\n");
        }
    } else if (choice == 2) {
        printf("Enter Batsman Index (1-%d): ", batsmanCount);
        scanf("%d", &index);
        getchar();
        if (index > 0 && index <= batsmanCount) {
            index--; 
            printf("Updating Batsman %d:\n", index + 1);
            printf("New Name: ");
            fgets(batsmen[index].ply2.ply.name, 20, stdin);
            strtok(batsmen[index].ply2.ply.name, "\n");
            printf("New Team: ");
            fgets(batsmen[index].ply2.ply.team, 20, stdin);
            strtok(batsmen[index].ply2.ply.team, "\n");
            printf("New Type: ");
            fgets(batsmen[index].type, 10, stdin);
            strtok(batsmen[index].type, "\n");
            printf("New Handed: ");
            fgets(batsmen[index].handed, 8, stdin);
            strtok(batsmen[index].handed, "\n");
            printf("Batsman updated successfully.\n");
        } else {
            printf("Invalid index.\n");
        }
    } else {
        printf("Invalid choice.\n");
    }
}

void deleteData() {
    int choice, index;
    printf("\nDelete Options:\n");
    printf("1. Delete Bowler\n");
    printf("2. Delete Batsman\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();
    if (choice == 1) {
        printf("Enter Bowler Index (1-%d): ", bowlerCount);
        scanf("%d", &index);
        getchar();
        if (index > 0 && index <= bowlerCount) {
            index--; 
            for (int i = index; i < bowlerCount - 1; i++) {
                bowlers[i] = bowlers[i + 1];
            }
            bowlerCount--;
            printf("Bowler deleted successfully.\n");
        } else {
            printf("Invalid index.\n");
        }
    } else if (choice == 2) {
        printf("Enter Batsman Index (1-%d): ", batsmanCount);
        scanf("%d", &index);
        getchar();
        if (index > 0 && index <= batsmanCount) {
            index--; 
            for (int i = index; i < batsmanCount - 1; i++) {
                batsmen[i] = batsmen[i + 1];
            }
            batsmanCount--;
            printf("Batsman deleted successfully.\n");
        } else {
            printf("Invalid index.\n");
        }
    } else {
        printf("Invalid choice.\n");
}
}
