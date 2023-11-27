#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Student {
    char name[50];
    int id;
    float score;
};
void add_student(struct Student students[], int *count) {
    struct Student student;
    printf("Nhap ten sv: ");
    fgets(student.name, sizeof(student.name), stdin);
    printf("Nhap ID sv: ");
    scanf("%d", &student.id);
    printf("Nhap diem sv: ");
    scanf("%f", &student.score);
    getchar();
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
            printf("Ten: %s, ID: %d, Diem: %.2f\n", students[i].name, students[i].id, students[i].score);
        }
    }
}
int compare_names(const void *a, const void *b) {
    struct Student *studentA = (struct Student *)a;
    struct Student *studentB = (struct Student *)b;
    return strcmp(studentA->name, studentB->name);
}
int compare_scores(const void *a, const void *b) {
    struct Student *studentA = (struct Student *)a;
    struct Student *studentB = (struct Student *)b;
    if (studentA->score < studentB->score) {
        return -1;
    } else if (studentA->score > studentB->score) {
        return 1;
    } else {
        return 0;
    }
}
void sort_students(struct Student students[], int count, int option) {
    switch (option) {
        case 1:
            qsort(students, count, sizeof(struct Student), compare_names);
            printf("Danh sach sinh vien da sap xep theo ten.\n");
            break;
        case 2:
            qsort(students, count, sizeof(struct Student), compare_scores);
            printf("Danh sach sinh vien da sap xep theo diem.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
    }
}
void search_students_by_name(struct Student students[], int count, char search_name[]) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, search_name) == 0) {
            printf("Ten: %s, ID: %d, Diem: %.2f\n", students[i].name, students[i].id, students[i].score);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co ten '%s'.\n", search_name);
    }
}
void search_students_by_id(struct Student students[], int count, int search_id) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].id == search_id) {
            printf("Ten: %s, ID: %d, Diem: %.2f\n", students[i].name, students[i].id, students[i].score);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co ID tren '%d'.\n", search_id);
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
        printf("3. Sap xep danh sach sinh vien\n");
        printf("4. Tim kiem sinh vien theo ten\n");
        printf("5. Tim kiem sinh vien theo ID\n");
        printf("6. Thoat\n");
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
                printf("1. Sap xep theo ten\n");
                printf("2. Sap xep theo diem\n");
                printf("Nhap lua chon: ");
                scanf("%d", &choice);
                sort_students(students, count, choice);
                break;
            case 4:
                char search_name[50];
                printf("Nhap ten sinh vien can tim: ");
                fgets(search_name, sizeof(search_name), stdin);
                search_students_by_name(students, count, search_name);
                break;
            case 5:
                int search_id;
                printf("Nhap ID sinh vien can tim: ");
                scanf("%d", &search_id);
                search_students_by_id(students, count, search_id);
                break;
            case 6:
                printf("Hen gap lai ban vao lan sau!\n");
                exit(0);
            default:
                printf("Lua chon khong hop le.\n");
        }
    }
    return 0;
}
