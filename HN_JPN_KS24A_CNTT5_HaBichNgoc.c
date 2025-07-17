//
// Created by Owner on 7/17/2025.
//DE 01

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Project {
    int id;
    char title[100];
    char owner[100];
    int priority;
} Project;


typedef struct Node {
    Project data;
    struct Node* next;
} Node;


typedef struct NodeDLL {
    Project data;
    struct NodeDLL* prev;
    struct NodeDLL* next;
} NodeDLL;


Node* headSelling = NULL;
NodeDLL* headSold = NULL;
NodeDLL* tailSold = NULL;

void showMenu() {
    printf("\n----------- PROJECT MANAGER -------------\n");
    printf("1. Them moi du an\n");
    printf("2. Hien thi danh sach du an ca nhan\n");
    printf("3. Xoa du an (theo ID)\n");
    printf("4. Cap nhat thong tin du an\n");
    printf("5. Danh dau du an da hoan thanh\n");
    printf("6. Sap xep du an theo do uu tien\n");
    printf("7. Tim kiem du an theo ten\n");
    printf("8. Thoat chuong trinh\n");
    printf("-----------------------------------------\n");
}

void themDuAn() {
    Project p;
    printf("Nhap ma du an: "); scanf("%d", &p.id);
    printf("Ten du an: "); getchar(); fgets(p.title, 100, stdin); strtok(p.title, "\n");
    printf("Nguoi quan ly: "); fgets(p.owner, 100, stdin); strtok(p.owner, "\n");
    printf("Do uu tien: "); scanf("%d", &p.priority);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = p;
    newNode->next = NULL;

    if (headSelling == NULL) headSelling = newNode;
    else {
        Node* temp = headSelling;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }

    printf("Da them du an: %s\n", p.title);
}

//
void hienThiDuAn() {
    Node* temp = headSelling;
    if (!temp) {
        printf("Khong co du an nao.\n");
        return;
    }
    printf("Danh sach du an ca nhan:\n");
    while (temp) {
        printf("- ID: %d | Ten: %s | Quan ly: %s | UU tien: %d\n", 
               temp->data.id, temp->data.title, temp->data.owner, temp->data.priority);
        temp = temp->next;
    }
}

int main() {
    int choice , id;

    do {
        showMenu();
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                themDuAn(); 
		break;
            case 2:
                hienThiDuAn(); 
		break;
            case 3:
                break;
            case 8:
                printf("Thoat chuong trinh!\n"); 
				break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 8);

    return 0;
}

