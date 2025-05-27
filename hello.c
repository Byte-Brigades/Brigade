
#include <stdio.h>
#include <string.h>

// Define the Room structure
typedef struct {
    char name[50];
    char description[256];
    int north;
    int south;
    int east;
    int west;
} Room;

// Function to display the current room's details
void displayRoom(Room rooms[], int currentRoom) {
    printf("\nYou are in %s.\n", rooms[currentRoom].name);
    printf("%s\n", rooms[currentRoom].description);
    printf("Exits: ");
    if (rooms[currentRoom].north != -1) printf("North ");
    if (rooms[currentRoom].south != -1) printf("South ");
    if (rooms[currentRoom].east != -1)  printf("East ");
    if (rooms[currentRoom].west != -1)  printf("West ");
    printf("\n");
}

int main() {
    // Initialize rooms
    Room rooms[4];

    strcpy(rooms[0].name, "Entrance Hall");
    strcpy(rooms[0].description, "A grand hall with portraits on the walls.");
    rooms[0].north = 1; rooms[0].south = -1; rooms[0].east = -1; rooms[0].west = -1;

    strcpy(rooms[1].name, "Library");
    strcpy(rooms[1].description, "Rows of ancient books line the shelves.");
    rooms[1].north = -1; rooms[1].south = 0; rooms[1].east = 2; rooms[1].west = -1;

    strcpy(rooms[2].name, "Study");
    strcpy(rooms[2].description, "A quiet room with a large desk and a lamp.");
    rooms[2].north = -1; rooms[2].south = -1; rooms[2].east = -1; rooms[2].west = 1;

    strcpy(rooms[3].name, "Secret Chamber");
    strcpy(rooms[3].description, "A hidden room filled with treasures.");
    rooms[3].north = -1; rooms[3].south = -1; rooms[3].east = -1; rooms[3].west = -1;

    int currentRoom = 0;
    char command[20];

    printf("Welcome to the Adventure Game!\n");

    while (1) {
        displayRoom(rooms, currentRoom);
        printf("\nEnter command (north, south, east, west, quit): ");
        scanf("%s", command);

        if (strcmp(command, "north") == 0) {
            if (rooms[currentRoom].north != -1)
                currentRoom = rooms[currentRoom].north;
            else
                printf("You can't go that way.\n");
        } else if (strcmp(command, "south") == 0) {
            if (rooms[currentRoom].south != -1)
                currentRoom = rooms[currentRoom].south;
            else
                printf("You can't go that way.\n");
        } else if (strcmp(command, "east") == 0) {
            if (rooms[currentRoom].east != -1)
                currentRoom = rooms[currentRoom].east;
            else
                printf("You can't go that way.\n");
        } else if (strcmp(command, "west") == 0) {
            if (rooms[currentRoom].west != -1)
                currentRoom = rooms[currentRoom].west;
            else
                printf("You can't go that way.\n");
        } else if (strcmp(command, "quit") == 0) {
            printf("Thanks for playing!\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
