# include <stdio.h>
# include <stdlib.h>

struct film {
    char* name;
    int year;
    char* country;
    char* genre;
    float reit;
};

struct all_films{
    struct films;
};

struct user {
    char * name;
    char * password;
    struct films * favourites;
    int is_admin;
};


struct film list_films(FILE* infile){

}






int main(){
    printf("a");

    return 0;
}