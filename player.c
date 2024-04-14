#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Player{
    int jerseyNumber;
    char playerName[50];
    int runs;
    int wickets;
    int matchesPlayed;
} Player;

void addPlayer(Player*, int *);
void removePlayer(Player*, int *);
void searchPlayer(Player*, int);
void updatePlayer(Player*, int);
void sortByRuns(Player*, int);
void sortByWickets(Player*, int);
void printAllPlayers(Player*, int);

void main(){
    Player players[100];
    int numPlayers = 0;
    int choice;
    do {
        
        printf("\nPlayer Management System:\n");
        printf("1. Add Player\n");
        printf("2. Remove Player\n");
        printf("3. Search Player\n");
        printf("4. Update Player\n");
        printf("5. Print Top 3 Players by Runs\n");
        printf("6. Print Top 5 Players by Wickets\n");
        printf("7. Display All Players\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPlayer(players, &numPlayers);
                break;
            case 2:
                removePlayer(players, &numPlayers);
                break;
            case 3:
                searchPlayer(players, numPlayers);
                break;
            case 4:
                updatePlayer(players, numPlayers);
                break;
            case 5:
                sortByRuns(players, numPlayers);
                break;
            case 6:
                sortByWickets(players, numPlayers);
                break;
            case 7:
                printAllPlayers(players, numPlayers);
                break;
            case 8:
                printf("Exiting From Player Mangement System.!\n");
                break;
            default:
                printf("Invalid choice. Please enter option from above options.\n");
        }
    } while (choice != 8);

}

void addPlayer(Player* players, int *numPlayers) {
    if (*numPlayers < 100) {
        printf("Enter details for the new player:\n");
        printf("Jersey Number: ");
        scanf("%d", &players[*numPlayers].jerseyNumber);
        printf("Player Name: ");
        scanf("%s", players[*numPlayers].playerName);
        printf("Runs: ");
        scanf("%d", &players[*numPlayers].runs);
        printf("Wickets: ");
        scanf("%d", &players[*numPlayers].wickets);
        printf("Matches Played: ");
        scanf("%d", &players[*numPlayers].matchesPlayed);

        (*numPlayers)++;
        printf("Player added successfully!\n");
    } else {
        printf("Cannot add more players. Maximum limit reached.\n");
    }
}
void removePlayer(Player* players, int *numPlayers) {
    int jerseyToRemove;
    printf("Enter the Jersey Number of the player to remove: ");
    scanf("%d", &jerseyToRemove);

    int foundIndex = -1;
    for (int i = 0; i < *numPlayers; i++) {
        if (players[i].jerseyNumber == jerseyToRemove) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        for (int i = foundIndex; i < (*numPlayers - 1); i++) {
            players[i] = players[i + 1];
        }

        (*numPlayers)--;
        printf("Player removed successfully!\n");
    } else {
        printf("Player not found with Jersey Number %d.\n", jerseyToRemove);
    }
}

void searchPlayer(Player* players, int numPlayers) {
    int choice;
    printf("Search player by:\n");
    printf("1. Jersey Number\n");
    printf("2. Player Name\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    int searchValue;
    int foundIndex = -1;

    switch (choice) {
        case 1:
            printf("Enter the Jersey Number: ");
            scanf("%d", &searchValue);

            for (int i = 0; i < numPlayers; i++) {
                if (players[i].jerseyNumber == searchValue) {
                    foundIndex = i;
                    break;
                }
            }
            break;

        case 2:
            printf("Enter the Player Name: ");
            char searchName[50];
            scanf("%s", searchName);

            for (int i = 0; i < numPlayers; i++) {
                if (strcmp(players[i].playerName, searchName) == 0) {
                    foundIndex = i;
                    break;
                }
            }
            break;

        default:
            printf("Invalid choice.\n");
            return;
    }

    if (foundIndex != -1) {
        printf("Player found:\n");
        printf("Jersey Number: %d\n", players[foundIndex].jerseyNumber);
        printf("Player Name: %s\n", players[foundIndex].playerName);
        printf("Runs: %d\n", players[foundIndex].runs);
        printf("Wickets: %d\n", players[foundIndex].wickets);
        printf("Matches Played: %d\n", players[foundIndex].matchesPlayed);
    } else {
        printf("Player not found.\n");
    }
}

void updatePlayer(Player* players, int numPlayers) {
    int jerseyToUpdate;
    printf("Enter the Jersey Number of the player to update: ");
    scanf("%d", &jerseyToUpdate);

    int foundIndex = -1;
    for (int i = 0; i < numPlayers; i++) {
        if (players[i].jerseyNumber == jerseyToUpdate) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        // Update player data
        printf("Enter updated details for the player:\n");
        printf("Runs: ");
        scanf("%d", &players[foundIndex].runs);
        printf("Wickets: ");
        scanf("%d", &players[foundIndex].wickets);
        printf("Matches Played: ");
        scanf("%d", &players[foundIndex].matchesPlayed);

        printf("Player data updated successfully!\n");
    } else {
        printf("Player not found with Jersey Number %d.\n", jerseyToUpdate);
    }
}

void sortByRuns(Player* players, int numPlayers) {
    for (int i = 0; i < numPlayers - 1; i++) {
        for (int j = 0; j < numPlayers - i - 1; j++) {
            if (players[j].runs < players[j + 1].runs) {
                //swap
                Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }

    printf("Top 3 Players by Runs:\n");
    for (int i = 0; i < numPlayers && i < 3; i++) {
        printf("Rank %d:\n", i + 1);
        printf("Jersey Number: %d\n", players[i].jerseyNumber);
        printf("Player Name: %s\n", players[i].playerName);
        printf("Runs: %d\n", players[i].runs);
        printf("Wickets: %d\n", players[i].wickets);
        printf("Matches Played: %d\n", players[i].matchesPlayed);
        printf("-----------------\n");
    }
}

void sortByWickets(Player* players, int numPlayers) {
    for (int i = 0; i < numPlayers - 1; i++) {
        for (int j = 0; j < numPlayers - i - 1; j++) {
            if (players[j].wickets < players[j + 1].wickets) {
                //swap
                Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }

    printf("Top 5 Players by Wickets:\n");
    for (int i = 0; i < numPlayers && i < 5; i++) {
        printf("Rank %d:\n", i + 1);
        printf("Jersey Number: %d\n", players[i].jerseyNumber);
        printf("Player Name: %s\n", players[i].playerName);
        printf("Runs: %d\n", players[i].runs);
        printf("Wickets: %d\n", players[i].wickets);
        printf("Matches Played: %d\n", players[i].matchesPlayed);
        printf("-----------------\n");
    }
}

void printAllPlayers(Player* players, int numPlayers) {
    if (numPlayers > 0) {
        printf("Displaying All Players:\n");
        for (int i = 0; i < numPlayers; i++) {
            printf("Jersey Number: %d\n", players[i].jerseyNumber);
            printf("Player Name: %s\n", players[i].playerName);
            printf("Runs: %d\n", players[i].runs);
            printf("Wickets: %d\n", players[i].wickets);
            printf("Matches Played: %d\n", players[i].matchesPlayed);
            printf("-----------------\n");
        }
    } else {
        printf("No players in the system.\n");
    }
}