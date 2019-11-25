int menu(char*  );
int getString(char* , char* );
int isOnlyLetter(char* );
int isOnlyNumber(char*);
int getOnlyLetter(char* , char* , char* );
int getOnlyNumber(char*, char*, int*);

int optionMenu_LoadFile (int  , char*  , LinkedList* );
int optionMenu_ListById (int  , LinkedList* );
int optionMenu_ListByYear (int  , LinkedList* );
int optionMenu_ListByGender (int  , LinkedList* );
LinkedList* optionMenu_FilterByGender (int  , LinkedList*  );
LinkedList* optionMenu_FilterByYear (int  , LinkedList*  );
int optionMenu_WriteFile (int  , char*  , LinkedList* );
