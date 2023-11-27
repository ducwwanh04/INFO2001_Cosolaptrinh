#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EMPLOYEES 100
struct Employee {
    char name[50];
    int id;
    char position[50];
    float salary;
};
struct Employee employees[MAX_EMPLOYEES];
int numEmployees = 0;
void addEmployee() {
    if (numEmployees == MAX_EMPLOYEES) {
        printf("Khong the them nhan vien moi. Da dat gioi han.\n");
        return;
    }
    struct Employee newEmployee;
    printf("Nhap ten nhan vien: ");
    scanf(" %[^\n]s", newEmployee.name);
    printf("Nhap ma nhan vien: ");
    scanf("%d", &newEmployee.id);
    printf("Nhap chuc vu: ");
    scanf(" %[^\n]s", newEmployee.position);
    printf("Nhap luong: ");
    scanf("%f", &newEmployee.salary);
    employees[numEmployees] = newEmployee;
    numEmployees++;
    printf("Nhan vien da duoc them.\n");
}
void deleteEmployee() {
    int employeeId, i, found = 0;
    printf("Nhap ma nhan vien can xoa: ");
    scanf("%d", &employeeId);
    for (i = 0; i < numEmployees; i++) {
        if (employees[i].id == employeeId) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (; i < numEmployees - 1; i++) {
            employees[i] = employees[i + 1];
        }
        numEmployees--;
        printf("Nhan vien da bi xoa.\n");
    } else {
        printf("Khong tim thay nhan vien voi ma nhan vien da cho.\n");
    }
}
void displayEmployees() {
    if (numEmployees == 0) {
        printf("Khong co nhan vien nao trong danh sach.\n");
        return;
    }
    printf("Danh sach nhan vien:\n");
    printf("-------------------------------\n");
    printf("Ma NV\tTen\tChuc vu\t\tLuong\n");
    printf("-------------------------------\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("%d\t%s\t%s\t%.2f\n", employees[i].id, employees[i].name, employees[i].position, employees[i].salary);
    }
    printf("-------------------------------\n");
}
void sortEmployeesByName() {
    if (numEmployees == 0) {
        printf("Khong co nhan vien nao trong danh sach.\n");
        return;
    }
    for (int i = 0; i < numEmployees - 1; i++) {
        for (int j = 0; j < numEmployees - i - 1; j++) {
            if (strcmp(employees[j].name, employees[j + 1].name) > 0) {
                struct Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
    printf("Danh sach nhan vien sau khi sap xep theo ten:\n");
    displayEmployees();
}
int main() {
    int choice;
    while (1) {
        printf("\nQuan ly nhan su\n");
        printf("1. Them nhan vien\n");
        printf("2. Xoa nhan vien\n");
        printf("3. Hien thi danh sach nhan vien\n");
        printf("4. Sap xep nhan vien theo ten\n");
        printf("5. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                displayEmployees();
                break;
            case 4:
                sortEmployeesByName();
                break;
            case 5:
                printf("Cam on da su dung chuong trinh!\n");
                exit(0);
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }
    return 0;
}
