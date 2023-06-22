#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX 5

typedef struct student{
    char name[31];
    int q1;
    int q2;
    int q3;
} REC;

// FUNCTIONS FOR STUDENT RECORD

REC srec[MAX];
int i, p, marker;
void add(REC addRec);
void del(char delName[31]);
int isFull();
int locate(char delName[31]);
float getAve(REC average);
void display();
int menu();
void init();

int main(){
    REC s;
    init();
    while(1)
    {
        switch(menu())
        {
            case 1: system("cls");
                    printf("\n\tInsert Student Name: ");
                    scanf(" %[^\n]s", s.name);
                    printf("\n\tInput Quiz 1: ");
                    scanf("%d", &s.q1);
                    printf("\n\tInput Quiz 2: ");
                    scanf("%d", &s.q2);
                    printf("\n\tInput Quiz 3: ");
                    scanf("%d",&s.q3);
                    add(s);
                    break;
            case 2: system("cls");
                    printf("\n\tInput Student to Delete: ");
                    scanf(" %[^\n]s", s.name);
                    del(s.name);
                    break;
            case 3: system("cls");
                    display();
                    break;
            case 4: system("cls");
                    exit(0);
            default: printf("\n\nPlease Choose from (1 - 5 Only!\n\n");
                    system("pause");
        }
    }
}

int menu(){
    int choice;
    system("cls");
    printf("\t CLASS RECORD \n");
    printf("\tMENU\n\n");
    printf("\t(1) Add A record\n");
    printf("\t(2) Delete A Record\n");
    printf("\t(3) Display All\n");
    printf("\t(4) Exit Program\n");
    printf("\n\t=====================\n");
    printf("Enter your choice here: ");
    scanf("%d", &choice);
    return choice;
}

void init(){
    marker = -1;
}

int isFull(){
    if(marker == MAX-1)
        return 1;
    else
        return 0;
}


void add(REC addRec){
    if (isFull() == 1) {
        printf("-------------------------------\n");
        printf("\n\tThe Array is Full.\n");
        system("pause");
    }
    else{
        marker ++;
        srec[marker] = addRec;
    }
}

void del(char delName[31]){
    int length;
    p = locate(delName);
    if (p == -1){
        printf("Student not found.\n");
        system("pause");
    }
    else{
        for(i = p; i < marker; i++){
            srec[i] = srec[i+1];
        }
        marker --;
        length = strlen(delName);
        for (i = 0; i <= length; i++)
            printf("%c", delName[i]);
        
        printf(" is Deleted Successfully.\n\n");
        system("pause");
    }
}

int locate(char delName[31]){
    int x;
    for(x = 0; x <= marker; x++){
        if(strcasecmp(delName, srec[x].name) == 0)
            return x;
    }
    return -1;
}

void display() {
    float ave[MAX];

    system("cls");
    printf("\n+-------------------------------------------------+\n");
    printf("| Student Name | Quiz 1 | Quiz 2 | Quiz 3 | Average | Remarks |\n");
    printf("+-------------------------------------------------+\n");
    for (i = 0; i <= marker; i++) {
        ave[i] = getAve(srec[i]);
        printf("| %-12s | %-6d | %-6d | %-6d | %-7.2f | %-7s |\n", srec[i].name, srec[i].q1, srec[i].q2, srec[i].q3, ave[i], ave[i] >= 75 ? "PASSED" : "FAILED");
    }
    printf("+-------------------------------------------------+\n");
    system("pause");
}


float getAve(REC average)//AVERAGE FUNCTION
{
    return ((float)average.q1+(float)average.q2+(float)average.q3)/3;
}



