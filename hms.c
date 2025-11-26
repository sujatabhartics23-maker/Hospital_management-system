#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patient {
    int id;
    char name[50];
    int age;
    char disease[50];
};

struct patient p;

void addPatient();
void viewPatients();
void searchPatient();
void deletePatient();
void updatePatient();
int login();

int main() {
    if(!login()) {
        printf("\nInvalid Login! Exiting...");
        return 0;
    }

    int choice;
    while(1) {
        printf("\n\n===== HOSPITAL MANAGEMENT SYSTEM =====\n");
        printf("1. Add Patient\n");
        printf("2. View All Patients\n");
        printf("3. Search Patient\n");
        printf("4. Update Patient\n");
        printf("5. Delete Patient\n");
        printf("6. Exit\n");
        printf("---------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: searchPatient(); break;
            case 4: updatePatient(); break;
            case 5: deletePatient(); break;
            case 6: printf("\nThank you!\n"); exit(0);
            default: printf("\nInvalid choice!");
        }
    }
    return 0;
}

int login() {
    char user[20], pass[20];
    printf("\n===== LOGIN =====\n");
    printf("Username: ");
    scanf("%s", user);
    printf("Password: ");
    scanf("%s", pass);

    if(strcmp(user, "admin") == 0 && strcmp(pass, "123") == 0)
        return 1;
    return 0;
}

void addPatient() {
    FILE *fp = fopen("patients.txt", "a");
    printf("\nEnter Patient ID: ");
    scanf("%d", &p.id);
    printf("Enter Name: ");
    scanf("%s", p.name);
    printf("Enter Age: ");
    scanf("%d", &p.age);
    printf("Enter Disease: ");
    scanf("%s", p.disease);

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);
    printf("\nPatient Added Successfully!");
}

void viewPatients() {
    FILE *fp = fopen("patients.txt", "r");
    if (!fp) {
        printf("\nNo Records Found!");
        return;
    }

    printf("\n===== ALL PATIENTS =====\n");
    while(fread(&p, sizeof(p), 1, fp)) {
        printf("\nID: %d\nName: %s\nAge: %d\nDisease: %s\n", p.id, p.name, p.age, p.disease);
        printf("-------------------------------");
    }
    fclose(fp);
}

void searchPatient() {
    FILE *fp = fopen("patients.txt", "r");
    int id, found = 0;

    printf("\nEnter Patient ID to Search: ");
    scanf("%d", &id);

    while(fread(&p, sizeof(p), 1, fp)) {
        if(p.id == id) {
            printf("\nRecord Found!\n");
            printf("ID: %d\nName: %s\nAge: %d\nDisease: %s\n", p.id, p.name, p.age, p.disease);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if(!found)
        printf("\nPatient Not Found!");
}

void updatePatient() {
    FILE *fp = fopen("patients.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    int id, found = 0;

    printf("\nEnter Patient ID to Update: ");
    scanf("%d", &id);

    while(fread(&p, sizeof(p), 1, fp)) {
        if(p.id == id) {
            found = 1;
            printf("Enter New Name: ");
            scanf("%s", p.name);
            printf("Enter New Age: ");
            scanf("%d", &p.age);
            printf("Enter New Disease: ");
            scanf("%s", p.disease);
        }
        fwrite(&p, sizeof(p), 1, temp);
    }
    fclose(fp);
    fclose(temp);
    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if(found)
        printf("\nPatient Updated Successfully!");
    else
        printf("\nPatient Not Found!");
}

void deletePatient() {
    FILE *fp = fopen("patients.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    int id, found = 0;

    printf("\nEnter Patient ID to Delete: ");
    scanf("%d", &id);

    while(fread(&p, sizeof(p), 1, fp)) {
        if(p.id != id) {
            fwrite(&p, sizeof(p), 1, temp);
        } else {
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);
    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if(found)
        printf("\nPatient Deleted Successfully!");
    else
        printf("\nPatient Not Found!");
}