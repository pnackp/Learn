#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// set what's inside a box;
struct Friend {
    char name[100];
    int age;
    char bloodType[5];
};

int addfriend(struct Friend x[] , int *count){
    printf("Enter your Name: ");
    scanf(" %[^\n]", x[*count].name);

    printf("Enter Age: ");
    scanf("%d", &x[*count].age);

    printf("Enter Blood Type: ");
    scanf("%s", x[*count].bloodType);
    printf("\n");
    *count += 1; // Count + 1; after Add friend by used pointer
    return 0;
}

int showfriendlist(struct Friend x[] , int count){
    for(int i = 0 ; i < count ; i++){
        printf("====Info [%d]====\n",i);
        printf("Name: %s \n",x[i].name);
        printf("Age :%d Years old\n",x[i].age);
        printf("Bloodtype: %s\n",x[i].bloodType);
    }
    return 0;
}

int findFriend(struct Friend x[] , int count){
    char Name[100];
    printf("Enter Name:");
    scanf("%s",Name);
    for (int i = 0 ; i < count ; i ++){
        if (strcasecmp(Name,x[i].name) == 0){
            printf("====Found [%d]====\n",i);
            printf("Name: %s \n",x[i].name);
            printf("Age :%d Years old\n",x[i].age);
            printf("Bloodtype: %s\n",x[i].bloodType);
            return 0;
        }
    }
    printf("\nNot Found");
    return 0;
}

int Deletename(struct Friend x[] , int *count){
    char Name[100];
    printf("Enter Name:");
    scanf("%s",Name);
    for (int i = 0 ; i < *count ; i ++){
        if (strcasecmp(Name,x[i].name) == 0){
            for (int j = i ; j < *count -1 ; j++){ // if found name replace with j+1;
                x[j] = x[j+1];
            }
            *count -= 1; // then minus count - -1;
            printf("Deleted successfully.\n");
            return 0;
        }
    }
    printf("\nNot Found");
    return 0;
}

int main() {
    struct Friend x[100];
    int choice;
    int count = 0 ;
    do {
    printf("==== FRIEND MANAGER ====\n");
    printf("1. Add Friend\n");
    printf("2. Show All Friends\n");
    printf("3. Search by Name\n");
    printf("4. Delete Friend by Name\n");
    printf("5. Exit\n");
    printf("Choose: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Add Friend Selected\n");
        addfriend(x,&count);
        break;
    case 2:
        printf("Show All Friends Selected\n");
        showfriendlist(x,count);
        break;
    case 3:
        printf("Search by Name Selected\n");
        findFriend(x,count);
        break;
    case 4:
        printf("Delete Friend by Name Selected\n");
        Deletename(x,&count);
        break;
    case 5:
        printf("Exit Program\n");
        break;
    default:
        printf("Invalid Choice! Please try again.\n");
        break;
    }

} while (choice != 5);
    return 0;
}
