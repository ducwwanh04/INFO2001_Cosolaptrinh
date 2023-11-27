#include <stdio.h>
#include <string.h>
struct Student {
    char name[50];
    int age;
};
int linearSearch(struct Student students[], int count, char searchName[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            return i; // Tra ve thong tin cua sinh vien qua danh sach 
        }
    }
    return -1; // Khong tim thay sinh vien 
}
int main() {
    struct Student students[100];
    int count = 0;
    // Nhap Thong tin sinh vien 
    strcpy(students[0].name, "Duc Anh");
    students[0].age = 20;
    strcpy(students[1].name, "Bach Moi");
    students[1].age = 22;
    strcpy(students[2].name, "Tuan tien");
    students[2].age = 21;
    count = 3;
    // Tim kiem sinh vien 
    char searchName[50];
    printf("Nhap ten cua sinh vien can tim kiem: ");
    scanf("%s", searchName);
    int index = linearSearch(students, count, searchName);
    if (index != -1) {
        printf("Tim thay sinh vien %s Tai vi tri %d\n", searchName);
    } else {
        printf("Khong tim thay sinh vien %s trong danh sach\n", searchName);
    }
    return 0;
}
