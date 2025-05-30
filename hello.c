
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
#include <stdio.h>

int main() {
    int choice;

    printf("====================================\n");
    printf("         Welcome to Hotel XYZ       \n");
    printf("====================================\n");
    printf(" Menu Categories:\n");
    printf(" 1. Breakfast\n");
    printf(" 2. Lunch\n");
    printf(" 3. Dinner\n");
    printf(" 4.snacks\n");
    printf(" 5. Exit\n");
    printf("====================================\n");

    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\n--- Breakfast Menu ---\n");
            printf("1. Idli & Sambar........Rs.40\n");
            printf("2. Dosa..................Rs.50\n");
            printf("3. Poha..................Rs.35\n");
            printf("4. Tea...................Rs.15\n");
            printf("5. Coffee................Rs.20\n");
            break;

        case 2:
            printf("\n--- Lunch Menu ---\n");
            printf("1. Veg Thali.............Rs.120\n");
            printf("2. Chicken Curry & Rice..Rs.180\n");
            printf("3. Dal Fry & Roti........Rs.100\n");
            printf("4. Paneer Masala & Naan..Rs.160\n");
            break;

        case 3:
            printf("\n--- Dinner Menu ---\n");
            printf("1. Veg Fried Rice........Rs.90\n");
            printf("2. Chicken Biryani.......Rs.200\n");
            printf("3. Chapati & Sabzi.......Rs.80\n");
            printf("4. Curd Rice..............Rs.70\n");
            break;

	case 4;
	printf("\n--- snacks Menu ---\n");
	printf("1. samosa...........Rs.15\n");
	printf("2. kachori..........RS.20\n");
	printf("3. aloo bonda........Rs.25\n");
	break;

        case 5:
            printf("Thank you for visiting Hotel XYZ!\n");
            break;

        default:
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int roll;
    char name[50];
    float marks;
} Student;

Student students[MAX];
int count = 0;

// Function to add a student
void addStudent() {
    if (count >= MAX) {
        printf("Cannot add more students!\n");
        return;
    }

    printf("Enter roll number: ");
    scanf("%d", &students[count].roll);
    getchar(); // Clear newline

    printf("Enter name: ");
    fgets(students[count].name, sizeof(students[count].name), stdin);
    students[count].name[strcspn(students[count].name, "\n")] = '\0'; // Remove newline

    printf("Enter marks: ");
    scanf("%f", &students[count].marks);

    count++;
    printf("Student added successfully.\n");
}

// Function to display all students
void displayStudents() {
    if (count == 0) {
        printf("No records to display.\n");
        return;
    }

    printf("\n%-10s %-20s %-10s\n", "Roll", "Name", "Marks");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10.2f\n", students[i].roll, students[i].name, students[i].marks);
    }
}

// Function to search a student by roll number
void searchStudent() {
    int roll;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Student Found:\n");
            printf("Roll: %d\n", students[i].roll);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", roll);
}

// Function to delete a student
void deleteStudent() {
    int roll;
    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            found = 1;
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Student deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Student with roll number %d not found.\n", roll);
    }
}

// Menu function
void menu() {
    printf("\n--- Student Management System ---\n");
    printf("1. Add Student\n");
    printf("2. Display Students\n");
    printf("3. Search Student by Roll\n");
    printf("4. Delete Student\n");
    printf("5. Exit\n");
    printf("---------------------------------\n");
}

int main() {
    int choice;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int accNumber;
    char name[50];
    float balance;
} Account;

Account accounts[MAX];
int accCount = 0;

void createAccount() {
    if (accCount >= MAX) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &accounts[accCount].accNumber);

    getchar();
    printf("Enter Account Holder Name: ");
    fgets(accounts[accCount].name, 50, stdin);
    accounts[accCount].name[strcspn(accounts[accCount].name, "\n")] = '\0';

    printf("Enter Initial Deposit Amount: ");
    scanf("%f", &accounts[accCount].balance);

    accCount++;
    printf("Account created successfully!\n");
}

void viewAllAccounts() {
    if (accCount == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("\n%-10s %-20s %-10s\n", "Acc No", "Name", "Balance");
    for (int i = 0; i < accCount; i++) {
        printf("%-10d %-20s %-10.2f\n", accounts[i].accNumber, accounts[i].name, accounts[i].balance);
    }
}

void depositMoney() {
    int accNum;
    float amount;

    printf("Enter account number to deposit into: ");
    scanf("%d", &accNum);

    for (int i = 0; i < accCount; i++) {
        if (accounts[i].accNumber == accNum) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            if (amount <= 0) {
                printf("Invalid amount.\n");
                return;
            }
            accounts[i].balance += amount;
            printf("Deposit successful. New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

void withdrawMoney() {
    int accNum;
    float amount;

    printf("Enter account number to withdraw from: ");
    scanf("%d", &accNum);

    for (int i = 0; i < accCount; i++) {
        if (accounts[i].accNumber == accNum) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount <= 0 || amount > accounts[i].balance) {
                printf("Invalid amount or insufficient balance.\n");
                return;
            }
            accounts[i].balance -= amount;
            printf("Withdrawal successful. Remaining balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

void searchAccount() {
    int accNum;
    printf("Enter account number to search: ");
    scanf("%d", &accNum);

    for (int i = 0; i < accCount; i++) {
        if (accounts[i].accNumber == accNum) {
            printf("\nAccount Found:\n");
            printf("Account Number: %d\n", accounts[i].accNumber);
            printf("Name: %s\n", accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

void menu() {
    printf("\n--- Bank Management System ---\n");
    printf("1. Create New Account\n");
    printf("2. View All Accounts\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. Search Account\n");
    printf("6. Exit\n");
    printf("--------------------------------\n");
}

int main() {
    int choice;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: viewAllAccounts(); break;
            case 3: depositMoney(); break;
            case 4: withdrawMoney(); break;
            case 5: searchAccount(); break;
            case 6: printf("Thank you for using our system!\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int accNumber;
    char name[50];
    float balance;
} Account;

Account accounts[MAX];
int accCount = 0;

void createAccount() {
    if (accCount >= MAX) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &accounts[accCount].accNumber);

    getchar();
    printf("Enter Account Holder Name: ");
    fgets(accounts[accCount].name, 50, stdin);
    accounts[accCount].name[strcspn(accounts[accCount].name, "\n")] = '\0';

    printf("Enter Initial Deposit Amount: ");
    scanf("%f", &accounts[accCount].balance);

    accCount++;
    printf("Account created successfully!\n");
}

void viewAllAccounts() {
    if (accCount == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("\n%-10s %-20s %-10s\n", "Acc No", "Name", "Balance");
    for (int i = 0; i < accCount; i++) {
        printf("%-10d %-20s %-10.2f\n", accounts[i].accNumber, accounts[i].name, accounts[i].balance);
    }
}

void depositMoney() {
    int accNum;
    float amount;

    printf("Enter account number to deposit into: ");
    scanf("%d", &accNum);

    for (int i = 0; i < accCount; i++) {
        if (accounts[i].accNumber == accNum) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            if (amount <= 0) {
                printf("Invalid amount.\n");
                return;
            }
            accounts[i].balance += amount;
            printf("Deposit is successful. New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

void withdrawMoney() {
    int accNum;
    float amount;

    printf("Enter the account number to withdraw from: ");
    scanf("%d", &accNum);

    for (int i = 0; i < accCount; i++) {
        if (accounts[i].accNumber == accNum) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount <= 0 || amount > accounts[i].balance) {
                printf("Invalid amount or insufficient balance.\n");
                return;
            }
            accounts[i].balance -= amount;
            printf("Withdrawal successful. Remaining balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

void searchAccount() {
    int accNum;
    printf("Enter account number to search: ");
    scanf("%d", &accNum);

    for (int i = 0; i < accCount; i++) {
        if (accounts[i].accNumber == accNum) {
            printf("\nAccount Found:\n");
            printf("Account Number: %d\n", accounts[i].accNumber);
            printf("Name: %s\n", accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

void menu() {
    printf("\n--- Bank Management System ---\n");
    printf("1. Create New Account\n");
    printf("2. View All Accounts\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. Search Account\n");
    printf("6. please Exit\n");
    printf("--------------------------------\n");
}

int main() {
    int choice;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: viewAllAccounts(); break;
            case 3: depositMoney(); break;
            case 4: withdrawMoney(); break;
            case 5: searchAccount(); break;
            case 6: printf("Thank you for using our system!\n"); exit(0);
            default: printf("Invalid choice exit. Try again.\n");
        }
    }

    return 0;
}
#include <stdio.h>

int main() {
    float principal, rate, time, simpleInterest;

    // Prompt user to enter principal amount
    printf("Enter principal amount: ");
    scanf("%f", &principal);

    // Prompt user to enter rate of interest
    printf("Enter  rate of interest (in %%): ");
    scanf("%f", &rate);

    // Prompt user to enter time period
    printf("Enter  time period (in years): ");
    scanf("%f", &time);

    // Calculate simple interest
    simpleInterest = (principal * rate * time) / 100;

    // Display the result
    printf("Simple Interest = %.2f\n", simpleInterestv
		    return 0;
}

