typedef struct
{
    int id;
    char title[128];
    int year;
    char genero[128];
} ePelicula;

ePelicula* movie_new (void);
ePelicula* movie_newParameters(char* , char* , char* , char* );
void movie_delete(ePelicula*);

/*********************************************************
******************** GETTERS ****************************
*********************************************************/

int movie_getId(ePelicula* , int* );
int movie_getTitle(ePelicula* , char* );
int movie_getYear(ePelicula* , int* );
int movie_getGenero(ePelicula* , char* );

/*********************************************************
*********************** SETTERS *************************
*********************************************************/

int movie_setId(ePelicula* , int );
int movie_setTitle(ePelicula* , char* );
int movie_setYear(ePelicula* , int );
int movie_setGenero(ePelicula* , char* );

/*********************************************************
*********************** PRINTS **************************
*********************************************************/

void movie_printHeader(void);
void movie_print(ePelicula* );
void movie_printFooter(void);
void movie_printList(LinkedList* );

int movies_sortById(void* ,void* );
int movies_sortByYear(void* ,void* );
int movies_sortByGender(void* ,void* );


int movies_filterByGender(void*  , char* );
LinkedList* movies_depurated(LinkedList* );

int movies_filterByYear(void*  , char*  );


