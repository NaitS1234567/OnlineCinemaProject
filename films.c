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

struct all_films{
    struct film;
};
struct film list_films(FILE* infile){

}



struct user {
    char name;
    char password;
    char card_num;
    int len_favourites;
    struct films * favourites;
    int is_admin;
};

void ERROR(char * s){
    printf("ERROR - check %s", s);
}

void
sign_up(FILE* users){
    char ** mas = (char**)malloc(sizeof(char*)*3);
    for (int i = 0; i < 3; i++){
        mas[i] = (char*)malloc(sizeof(char)*20);
    }

    int len_favourites = 0;
    int is_admin = 0;
    int len;

    while (1) {
        char s[20];
        printf("Print your name (len 3-20) ");
        scanf("%s", &s);
        len = strlen(s);
        if (len < 3 || len > 20) {
            ERROR("name\n");
            continue;
        }
        mas[0] = s;
        break;
    }
    while (1){
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

    while (1){
        char s2[20];
        printf("MONEY PISHI EPT (len 16) ");
        scanf("%s", &s2);
        len = strlen(s2);
        if (len != 5){
            ERROR("card nums\n");
            continue;
        }
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
    fprintf(users,"%s","\n&&\n");
    printf("Registration was successful!\n");
}


void authorization(FILE* users){
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
            printf("\n====== Registration ======\n");
            sign_up(users);
            break;
        } else {
            printf("\n====== Login ======\n");
            break;
        }
    }


}






int main(){
    FILE* users = fopen("users.txt","a+");
    authorization(users);





    return 0;
}