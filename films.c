# include <stdio.h>
# include <stdlib.h>

struct films {
    char* name;
    int year;
    char* country;
    char* genre;
    float reit;
};

struct user {
    char * name;
    char * password;
    struct films * favourites;
    int is_admin;
};



struct films list_films(FILE* infile){

}






int main(){
    printf("a");

    return 0;
}