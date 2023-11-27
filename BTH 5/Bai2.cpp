#include <stdio.h>
#include <string.h>
struct Student {
    char name[50];
    int age;
};
void bubbleSort(struct Student students[], int count) {
    int i, j;
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                // Hoan doi vi tri cua hai sinh vien 
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}
void displayStudents(struct Student students[], int count) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < count; i++) {
        printf("Ten: %s, Tuoi: %d\n", students[i].name, students[i].age);
    }
}
int main() {
    struct Student students[100];
    int count = 0;
    // Nhap thong tin cua sinh vien 
    strcpy(students[0].name, "Duong Duc Anh");
    students[0].age = 20;
    strcpy(students[1].name, "Bach Khanh Moi");
    students[1].age = 22;
    strcpy(students[2].name, "Pham Tien Tuan");
    students[2].age = 21;
    count = 3;
    // Hien thi danh sach truoc khi sap xep 
    displayStudents(students, count);
    // Sap xep danh sach sinh vien theo ten 
    bubbleSort(students, count);
    // Hien thi danh sach sau khi sap xep 
    printf("\nDanh sach sau khi sap xep:\n");
    displayStudents(students, count);
    return 0;
}
