# include <stdio.h>
# include <stdlib.h>
# include <string.h>


struct film {
    char* name;
    int year;
    char* country;
    char* genre;
    float reit;
};

struct node{
    struct film;
    struct node* next;
    struct node* prev;
};


struct all_films{
    struct film;
    int len;
    struct node* head;
    struct node* tail;
};
struct film list_films(FILE* infile){

}

struct user {
    char * name;
    char * password;
    char * card_num;
    int len_favourites;
    struct films * favourites;
    int is_admin;
};

void ERROR(char * s){
    printf("ERROR - check %s", s);
}

int check_exist_user( char * user_name) {
    FILE* file = fopen("users.txt", "a+");
    int len_exist = strlen(user_name);

    char *s[30];
    int k = 0;
    while (!feof(file)) {

        if (k%5 == 0){
            int flag = 0;
            fscanf(file,"%s",&s);

            int l = strlen(s);
            if (l == len_exist){

                if(strcmp(s,user_name) == 0){
                    k = 0;
                    return 1;
                }
            }
        } else {
            fscanf(file,"%s", &s);
        }
        k++;
    }
    return 0;
}

void sign_up(FILE* users){
    char ** mas = (char**)malloc(sizeof(char*)*3);
    for (int i = 0; i < 3; i++){
        mas[i] = (char*)malloc(sizeof(char)*20);
    }

    int len_favourites = 0;
    int is_admin = 0;
    int len;

    while (1) { // user name scanf
        char s[20];
        printf("Print your name (len 3-20) ");
        scanf("%s", &s);
        len = strlen(s);
        int fix = 0;
        fix = check_exist_user( s);
        if (len < 3 || len > 20 || fix == 1) {
            ERROR("name\n");
            continue;
        }
        mas[0] = s;
        break;
    }
    while (1){ // password scanf
        char s1[20];
        printf("Create your password (len 6-20) ");
        scanf("%s", &s1);
        len = strlen(s1);
        if (len < 6 || len > 20){
            ERROR("password\n");
            continue;
        }
        mas[1] = s1;
        break;
    }

    while (1){ // card nums scanf
        char s2[20];
        printf("Card nums (len 5) "); // MAKE check string in card nums !!!!!!!!!!!!!!!!!!!
        scanf("%s", &s2);
        len = strlen(s2);
        if (len != 5){
            ERROR("card nums\n");
            continue;
        }
        int card_flag = 0;
        for (int i = 0; i < len; i++){ // CHECK STRING IN CARD NUMS
            if ( '0' > s2[i] || s2[i] > '9'){
                ERROR("card nums\n");
                card_flag = 1;
                break;
            }
        }
        if (card_flag == 1)
            continue;
        mas[2] = s2;
        break;
    }

    for (int i = 0; i < 3; i++){
        printf("%s \n", mas[i]);
        fprintf(users, "%s", mas[i]);
        fprintf(users,"%c",'\n');
    }
    fprintf(users, "%d", len_favourites);
    fprintf(users,"%c",'\n');
    fprintf(users, "%d", is_admin);
    fprintf(users, "%c", '\n');
    printf("Registration was successful!\n\n");
}


void log_in(FILE* file){

    printf("print username - ");
    int fix = 0;
    char * username[20];
    while (fix != 1){
        scanf("%s", &username);
        fix = check_exist_user(username);
        if (fix != 1){
            printf("\nUSER NOT FOUND, RETRY - ");
        }
    }

    FILE * fix_file = fopen("users.txt", "r");
    char * fix_password[20];
    int k = 0;
    char * s[20];
    int flag = 0;
    while (!feof(file)) {
        if (k%5 == 0){
            fscanf(fix_file, "%s", &s);
            int l1 = strlen(s);
            int l2 = strlen(username);
            if (l1 == l2){
                if (strcmp(username,s) == 0){
                    fscanf(fix_file, "%s", &fix_password);
                    flag = 1;
                    break;
                }
            }

        } else {
            fscanf(fix_file, "%s", &s);
        }
        if (flag == 1){
            break;
        }
    }

    printf("\nprint password - ");

    while (1){
        char * pass[20];
        scanf("%s", &pass);
        printf("%s - %s", pass, fix_password);

        if (strcmp(pass, fix_password) == 1){
            printf("\nINCORRECT PASSWORD, RETRY - ");
        } else {
            break;
        }
    }
    printf("\nYou are in system!\n");
}


int main(){

    printf("=======================\n");
    printf("|| ENTER 1 - sign in ||\n|| ENTER 2 - sign up ||\n");
    printf("=======================\n        |print ");

    int key = 0;

    while (key != 1 || key != 2){
        int key;
        scanf("%d", &key);
        if (key > 2 || key < 1){
            printf("ERROR - write again \n");
            printf("        |print ");
        } else if (key == 2) {
            FILE* users = fopen("users.txt","a+");
            printf("\n========== Registration ==========\n");
            sign_up(users);
            break;
        } else {
            FILE* users = fopen("users.txt","a+");
            printf("\n========== Login ==========\n");
            log_in(users);
            break;
        }
    }
    system("cls");
    while (1){
        printf("main menu");
        char x = scanf("%c", &x);
    }




    return 0;
}