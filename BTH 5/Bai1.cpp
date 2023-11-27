#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Student {
    char name[50];
    int age;
    char gender[10];
};
void add_student(struct Student students[], int *count) {
    struct Student student;
    printf("Nhap ten sv: ");
    fgets(student.name, sizeof(student.name), stdin);
    printf("Nhap tuoi cua sv: ");
    scanf("%d", &student.age);
    getchar();
    printf("Nhap gioi tinh sv: ");
    fgets(student.gender, sizeof(student.gender), stdin);
    students[*count] = student;
    (*count)++;
    printf("Them sinh vien thanh cong!\n");
}
void display_students(struct Student students[], int count) {
    if (count == 0) {
        printf("Khong co sv trong danh sach.\n");
    } else {
        printf("Danh sach sinh vien:\n");
        for (int i = 0; i < count; i++) {
            printf("Ten: %s, Tuoi: %d, Gioi tinh: %s\n", students[i].name, students[i].age, students[i].gender);
        }
    }
}
void update_student(struct Student students[], int count) {
    if (count == 0) {
        printf("Khong co sv trong danh sach.\n");
    } else {
        char name[50];
        printf("Nhap ten sv de cap nhat: ");
        getchar();
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        for (int i = 0; i < count; i++) {
            if (strcmp(students[i].name, name) == 0) {
                printf("Nhap ten moi: ");
                fgets(students[i].name, sizeof(students[i].name), stdin);
                students[i].name[strcspn(students[i].name, "\n")] = '\0';
                printf("Nhap tuoi moi: ");
                scanf("%d", &students[i].age);
                getchar();
                printf("Nhap gioi tinh moi: ");
                fgets(students[i].gender, sizeof(students[i].gender), stdin);
                students[i].gender[strcspn(students[i].gender, "\n")] = '\0'; 
                printf("Cap nhat thong tin sinh vien!\n");
                return;
            }
        }
        printf("Khong tim thay sinh vien trong danh sach.\n");
    }
}
int main() {
    struct Student students[100];
    int count = 0;
    int choice;
    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Them sinh vien\n");
        printf("2. Hien thi danh sach sinh vien\n");
        printf("3. Cap nhat thong tin sinh vien\n");
        printf("4. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                add_student(students, &count);
                break;
            case 2:
                display_students(students, count);
                break;
            case 3:
                update_student(students, count);
                break;
            case 4:
                printf("Ket thuc chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    }
    return 0;
}
