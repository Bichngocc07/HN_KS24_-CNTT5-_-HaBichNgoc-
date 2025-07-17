//
// Created by Owner on 7/17/2025.
//DE 02

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100


typedef struct Node {
    char text[MAX_LEN];
    struct Node* next;
} Node;


typedef struct Stack {
    Node* top;
} Stack;


Stack clipboardStack = { NULL };
Stack redoStack = { NULL };

void showMenu() {
    printf("\n------------CLIPBOARD MANAGER ----------\n");
    printf("1. Sao chep doan van ban moi\n");
    printf("2. Dan noi dung vua sao chep\n");
    printf("3. Hoan tac lenh sao chep gan nhat\n");
    printf("4. Phuc hoi lenh vua undo\n");
    printf("5. In toan bo noi dung\n");
    printf("6. THOAT CHUONG TRINH\n");
    printf("------------------------------------------\n");
}
void thucHienCopy() {
    char input[MAX_LEN];
    printf("Nhap van ban can sao chep: ");
    getchar();
    fgets(input, MAX_LEN, stdin);
    strtok(input, "\n");

    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->text, input);
    newNode->next = clipboardStack.top;
    clipboardStack.top = newNode;


    while (redoStack.top != NULL) {
        Node* temp = redoStack.top;
        redoStack.top = temp->next;
        free(temp);
    }

    printf("Da copy: %s\n", input);
}
void paste() {
    if (clipboardStack.top == NULL) {
        printf("Nhap van ban can sao chep: ");
        return;
    }
}
int main() {
    int choice;
    do {
        showMenu();
        printf("Chon lenh: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showMenu();
                break;
            case 2:
                paste();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                printf("Thoat chuong trinh!\n");
                break;
            default: printf("Lua chon khong hop le!\n");
        }

    } while (choice != 6);

    return 0;
}
