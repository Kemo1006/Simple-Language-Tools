/***********************************************************************************
********************** 
    This is to certify that this project is my own work, based on my personal efforts in studying and applying 
    the concepts learned. I have constructed the functions and their respective algorithms and corresponding 
    code by myself. The program was run, tested, and debugged by my own efforts. I further certify that I 
    have not copied in part or whole or otherwise plagiarized the work of other students and/or persons.
    <Ong, Kyle Edward> 12183733>
    <Arevalo, Jose Joaquin> 12182893> 
***********************************************************************************
**********************/

#include <stdio.h>
#include <string.h>
#include "MP.h"

struct TranslationTag{
    string20 language[10];  //where language is stored
    string20 word[10];      //where translation is stored
    int count;              //number of language-translation pairs initialized
};

/*  int AddEntry() = will get entry/entries from the user
    @param num - initialized number of entries
    @param Translation - where all the language-translation pairs are stored
*/
int AddEntry(int num, TranslationType *Translation){
    int i, j, l, m;
    int index[150];
    char choice, cDump; 
    string20 LLanguage;
    string20 LWord;

    if(num < 150){
        do{ 
            int count = 0;
            int k = 0;
            printf("\nInput language: ");
            scanf("%s%c", LLanguage, &cDump);
            printf("Input word: ");
            scanf("%s%c", LWord, &cDump);

            for(i = 0; i < num; i++){   // store given language-translation pair
                for(j = 0; j < Translation[i].count; j++){
                    if(strcmp(LLanguage, Translation[i].language[j]) == 0 && strcmp(LWord, 
                        Translation[i].word[j]) == 0){
                        count++;
                        index[k] = i;
                        k++; 
                    }
                }
            }
            printf("\n");
    
            if(count > 0){  // if given entry already exists
                for(l = 0; l < count; l++){
                    printf("Entry: %d\n", l+1);
                        for(m = 0; m < Translation[index[l]].count; m++){
                            printf("%s: %s\n", Translation[index[l]].language[m], 
                            Translation[index[l]].word[m]);
                        }
                        printf("\n");
                    }
            }else{
                printf("No entries of that language-translation pair has been inputted before\n");
                printf("The language-translation pair will now be inputted\n");
                strcpy(Translation[num].language[0], LLanguage);
                strcpy(Translation[num].word[0], LWord);
                Translation[num].count = 1;
                num++;
            }

            if(count > 0){
                do{
                    printf("Is this a new entry? [Y]es or [N]o: ");
                    scanf("%c%c", &choice, &cDump);
                        if(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n'){
                            printf("Invalid Input");
                        }
            }while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
    
            switch(choice){
                case 'N':
                    return num;
                case 'n': 
                    return num;
                case 'Y':
                    strcpy(Translation[num].language[0], LLanguage);;
                    strcpy(Translation[num].word[0], LWord);
                    Translation[num].count = 1;
                    num++;
                    break;
                case 'y':
                    strcpy(Translation[num].language[0], LLanguage);
                    strcpy(Translation[num].word[0], LWord);
                    Translation[num].count = 1;
                    num++;
                    break;
                }
            }

            do{
                printf("Encode another pair? [Y]es or [N]o: ");
                scanf("%c%c", &choice, &cDump);

                    if(choice != 'Y' && choice != 'y' && 
                        choice != 'N' && choice != 'n'){
                        printf("Invalid Input\n");
                    }
            }while(choice != 'Y' && choice != 'y' && 
                choice != 'N' && choice != 'n'); 
        }while(choice != 'N' && choice != 'n');
    }else{
        printf("Maximum amount of entries already inputted.\n");
        printf("Reverting back to the Manage Data menu.\n");
    }

    return num; 
}

/*  void AddTranslations() = will get the additional language-translation pairs for the entry/entries
    @param num - initialized number of entries
    @param Translation - where all the language-translation pairs are stored
*/
void AddTranslations(int num, TranslationType *Translation){
    int i, j, l, m, n, q, r, input;
    int k = 0;
    int index[150];
    int count = 0;
    int sen = 0;
    int sen2 = 0;
    string20 LLanguage, NLanguage;
    string20 LWord, NWord;
    char choice, cDump;
    
    if(num > 1){    // if there are 2 or more entries
        printf("Input existing language: ");
        scanf("%s%c", LLanguage, &cDump);
        printf("Input existing word: ");
        scanf("%s%c", LWord, &cDump);
    }else if(num == 1){ // if there is only 1 entry
        strcpy(LLanguage, Translation[0].language[0]);
        strcpy(LWord, Translation[0].word[0]);
    }

    for(i = 0; i < num; i++){
        for(j = 0; j < Translation[i].count; j++){
            if(strcmp(LLanguage, Translation[i].language[j]) == 0 && strcmp(LWord, 
                Translation[i].word[j]) == 0){
                count++;
                index[k] = i;
                k++;
            }
        }
    }
    printf("\n");
    
    if(count > 0){  //will show what entry the language-translation pair is stored
        for(l = 0; l < count; l++){
            printf("Entry:%d\n", l+1);
            for(m = 0; m < Translation[index[l]].count; m++){
                printf("%s: %s\n", Translation[index[l]].language[m], 
                Translation[index[l]].word[m]);

                if(m == Translation[index[l]].count-1){
                    printf("\n");
                }
            }
        }
    
        if(count == 1){ //if entries are different from each other
            printf("The entry of that language-translation pair that was found is 1\n");
            
            do{
                if(Translation[index[0]].count == 10){
                    printf("Max language-translation pairs already inputted\n");
                    choice = 'N';
                }else{
                    
                    do{
                        printf("Input a new unique language: ");
                        scanf("%s%c", NLanguage, &cDump);

                        for(q = 0; q < Translation[index[0]].count; q++){
                            if(strcmp(NLanguage, Translation[index[0]].language[q])== 0){   // if given language already exists within the entry
                                printf("Language already inputted for that entry\n");
                                sen = 0;
                                q = Translation[index[0]].count;
                            }else{
                                sen++;
                            }
                        }
                    }while(sen == 0);
                    printf("Input new word: ");
                    scanf("%s%c", NWord, &cDump);
                    strcpy(Translation[index[0]].language[Translation[index[0]].count], 
                    NLanguage); // store new language
                    strcpy(Translation[index[0]].word[Translation[index[0]].count], NWord); // store new word
                    Translation[index[0]].count++;
            
                    do{
                        printf("Encode another pair? [Y]es or [N]o: ");
                        scanf("%c%c", &choice, &cDump);

                        if(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n'){
                            printf("Invalid Input\n");
                        }
                    }while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
                }
            }while(choice != 'N' && choice != 'n');
        }else if(count > 1){    //if 2 or more entries have similar input (ex. entry 1: Tagalog; mahal entry 2: Tagalog; mahal)
            printf("The entries of that language-translation pairs that were found are %d\n", count);
            for(n = 1; n < count+1; n++){
                printf("Input %d for the entry of the language-translation pair %d\n", n, n);
            }
            
            do{
                printf("Input: ");
                scanf("%d%c", &input, &cDump);

                if(input > count+1 || input < 1){
                    printf("Invalid input\n");
                }
            }while(input > count+1 || input < 1); 

            do{
                if(Translation[input-1].count == 10){
                    printf("Max language-translation pairs already inputted\n");
                    choice = 'N';
                }else{
                    do{
                        printf("Input a new unique language: ");
                        scanf("%s%c", NLanguage, &cDump);

                        for(r = 0; r < Translation[input-1].count; r++){
                            if(strcmp(NLanguage, Translation[input-1].language[r])== 0){    // if given language already exists within the entry
                            printf("Language already inputted for that entry\n");
                            sen2 = 0;
                            r = Translation[input-1].count;
                            }else{
                            sen2++;
                            }
                        }
                    }while(sen2 == 0);
                        printf("Input new word: ");
                        scanf("%s%c", NWord, &cDump);
                        strcpy(Translation[index[input-1]].language[Translation[index[input-1]].count], NLanguage); //store new language
                        strcpy(Translation[index[input-1]].word[Translation[index[input-1]].count], NWord); //store new word
                        Translation[input-1].count++;
                    
                    do{
                        printf("Encode another pair? [Y]es or [N]o: ");
                        scanf("%c%c", &choice, &cDump);

                        if(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n'){
                            printf("Invalid Input\n");
                        }
                    }while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
                }
            }while(choice != 'N' && choice != 'n');
        }
    }else{
        printf("Such entry/entries of that language-translation pair does not exist\n");
        printf("Use the Add Entry option first\n");
    }
    printf("Reverting back to the Manage Data menu.\n");
}
    
void Display(TranslationType Translation){
    int i;
    printf("\n");
    
    for(i = 0; i < Translation.count; i++){
        printf("%s: %s\n", Translation.language[i], Translation.word[i]);
    }
    printf("\n");
}

/*  void ModifEntry() = will modify and display the modified entry by the user
    @param num - initialized number of entries
    @param Translation - where all the language-translation pairs are stored
*/
void ModifyEntry(int num, TranslationType *Translation){
    int i = 0;
    int iChoice, iChoice2, iChoice3;
    char choice, choice2, cDump;
    string20 LWord, LLanguage;
    
    if(num == 1){
        Display(Translation[i]);
        printf("No more next entry\n");
    }else if(num > 1){
        Display(Translation[i]);

        do{
            do{
                printf("N = view next entry of language-translation pair\n");
                printf("P = view previous entry of language-translation pair\n");
                printf("X = exit\n");
                printf("Input: ");
                scanf("%c%c", &choice, &cDump);

                if(choice != 'N' && choice != 'n' && 
                    choice != 'P' && choice != 'p' && 
                    choice != 'X' && choice != 'x'){
                    printf("Invalid input\n");
                }
            }while(choice != 'N' && choice != 'n' && 

            choice != 'P' && choice != 'p' && 
            choice != 'X' && choice != 'x');
            
            switch(choice){
                case 'N':
                    if(i < num-1){
                    i++;
                        Display(Translation[i]);
                    }else if(i == num-1){
                        printf("\nNo more next entry\n\n");
                    }
                    break;
                case 'n':
                    if(i < num-1){
                        i++;
                    Display(Translation[i]);
                    }else if(i == num-1){
                        printf("\nNo more next entry\n\n");
                    }
                    break;
                case 'P':
                    if(i > 0){
                        i--;
                        Display(Translation[i]);
                    }else{
                        printf("No more previous entry\n");
                        printf("\n");
                    }
                    break;
                case 'p':
                    if(i > 0){
                        i--;
                        Display(Translation[i]);
                    }else{
                        printf("No more previous entry\n");
                        printf("\n");
                    }
                    break;
                case 'X':
                    printf("\n");
                    i = num;
                    break;
                case 'x':
                    printf("\n");
                    i = num;
                    break;
            }
        }while(i < num);
    }
    printf("Input the number of the entry to be modified: ");
    scanf("%d%c", &iChoice, &cDump);

    if(iChoice < 1 || iChoice > num){
        printf("Invalid input\n");
    }
    
    if(iChoice > 0 && iChoice < num+1){
        do{
            do{
                printf("Input the number of the language-translation pair inside the entry to be modified: ");
                scanf("%d%c", &iChoice2, &cDump);

                if(iChoice2 < 1 || iChoice2 > Translation[iChoice-1].count){
                    printf("Invalid input\n");
                }
            }while(iChoice2 < 1 || iChoice2 > Translation[iChoice-1].count);
            
            do{
                printf("1 = Modify the language\n");
                printf("2 = Modify the translation\n");
                printf("Input the number corresponding on which one to be modified: ");
                scanf("%d%c", &iChoice3, &cDump);

                if(iChoice3 < 1 || iChoice3 > 2){
                    printf("Invalid input\n");
                }
            }while(iChoice3 < 1 || iChoice3 > 2);
            
            do{
                printf("Will you modify another language-translation pair after this? [Y]es or [N]o: ");
                scanf("%c%c", &choice2, &cDump);

                if(choice2 != 'Y' && choice2 != 'y' && 
                    choice2 != 'N' && choice2 != 'n'){
                    printf("Invalid input\n");
                }
            }while(choice2 != 'Y' && choice2 != 'y' && 
            choice2 != 'N' && choice2 != 'n');
            
            if(iChoice3 == 1){
                printf("Input new language ");
                scanf("%s%c", LLanguage, &cDump);
                strcpy(Translation[iChoice-1].language[iChoice2-1], LLanguage); //replace the old language with the new language
            }else if(iChoice3 == 2){
                printf("Input new translation ");
                scanf("%s%c", LWord, &cDump);
                strcpy(Translation[iChoice-1].word[iChoice2-1], LWord); //replace the old translation with the new translation
            }
        }while(choice2 != 'N' && choice2 != 'n');
    }
    printf("Reverting back to the Manage Data menu.\n");
}

/*  int DeleteEntry() = will delete the given entry, and will return the entry/entries that are not deleted
    @param num - initialized number of entries
    @param Translation - where all the language-translation pairs are stored
*/
int DeleteEntry(TranslationType *Translation, int num){
    int i = 0;
    int iChoice, iChoice2;
    char choice, cDump;

    if(num == 1){
        Display(Translation[i]);
        printf("No more next entry\n");
    }else if(num > 1){
        Display(Translation[i]);

        do{
            do{
                printf("N = view next entry of language-translation pair\n");
                printf("P = view previous entry of language-translation pair\n");
                printf("X = exit\n");
                printf("Input: ");
                scanf("%c%c", &choice, &cDump);

                if(choice != 'N' && choice != 'n' && 
                    choice != 'P' && choice != 'p' && 
                    choice != 'X' && choice != 'x'){
                    printf("Invalid input\n");
                }
            }while(choice != 'N' && choice != 'n' && 
            choice != 'P' && choice != 'p' && 
            choice != 'X' && choice != 'x');
            
            switch(choice){
                case 'N':
                    if(i < num-1){
                        i++;
                        Display(Translation[i]);
                    }else if(i == num-1){
                        printf("\nNo more next entry\n\n");
                    }
                    break;
                case 'n':
                    if(i < num-1){
                        i++;
                        Display(Translation[i]);
                    }else if(i == num-1){
                        printf("\nNo more next entry\n\n");
                    }
                    break;
                case 'P':
                    if(i > 0){
                        i--;
                        Display(Translation[i]);
                    }else{
                        printf("No more previous entry\n");
                        printf("\n");
                    }
                    break;
                case 'p':
                    if(i > 0){
                        i--;
                        Display(Translation[i]);
                    }else{
                        printf("No more previous entry\n");
                        printf("\n");
                    }
                    break;
                case 'X':
                    printf("\n");
                    i = num;
                    break;
                case 'x':
                    printf("\n");
                    i = num;
                    break;
            }
        }while(i < num);
    }
    printf("Input the number of the entry to be deleted: ");
    scanf("%d%c", &iChoice, &cDump);
        
    if(iChoice < 1 || iChoice > num){
        printf("Invalid input\n");
    }
        
    if(iChoice > 0 && iChoice < num+1){//deletion of entry
        for(iChoice2 = iChoice-1; iChoice2 < num; iChoice2++){
            Translation[iChoice2] = Translation[iChoice2+1];    //entry that is stored after the deleted entry will move
        }
        num--;//decrement number of entries initialized
    }
    printf("Reverting back to Manage Data menu.\n");
    return num;
}

/*  int DeleteTranslation() = will delete a language-translation pair from a chosen 
    entry, and will return the language-translation pairs the are not deleted
    @param num - initialized number of entries
    @param Translation - where all the language-translation pairs are stored
*/
int DeleteTranslation(TranslationType *Translation, int num){
    int j;
    int i = 0;
    int iChoice, iChoice2, iChoice3;
    char choice, cDump;

    if(num == 1){
        Display(Translation[i]);
        printf("No more next entry\n");
    }else if(num > 1){
        Display(Translation[i]);

        do{
            do{
                printf("N = view next entry of language-translation pair\n");
                printf("P = view previous entry of language-translation pair\n");
                printf("X = exit\n");
                printf("Input: ");
                scanf("%c%c", &choice, &cDump);

                if(choice != 'N' && choice != 'n' && 
                    choice != 'P' && choice != 'p' && 
                    choice != 'X' && choice != 'x'){
                    printf("Invalid input\n");
                }
            }while(choice != 'N' && choice != 'n' && 
            choice != 'P' && choice != 'p' && 
            choice != 'X' && choice != 'x');
            
            switch(choice){
                case 'N':
                    if(i < num-1){
                        i++;
                        Display(Translation[i]);
                    }else if(i == num-1){
                        printf("\nNo more next entry\n\n");
                    }
                    break;
                case 'n':
                    if(i < num-1){
                        i++;
                        Display(Translation[i]);
                    }else if(i == num-1){
                        printf("\nNo more next entry\n\n");
                    }
                    break;
                case 'P':
                    if(i > 0){
                        i--;
                        Display(Translation[i]);
                    }else{
                        printf("No more previous entry\n");
                        printf("\n");
                    }
                    break;
                case 'p':
                    if(i > 0){
                        i--;
                        Display(Translation[i]);
                    }else{
                        printf("No more previous entry\n");
                        printf("\n");
                    }
                    break;
                case 'X':
                    printf("\n");
                    i = num;
                    break;
                case 'x':
                    printf("\n");
                    i = num;
                    break;
            }
        }while(i < num);
    }
    printf("Input the number of the entry: ");
    scanf("%d%c", &iChoice, &cDump);

    if(iChoice < 1 || iChoice > num){
        printf("Invalid input\n");
    }

    if(iChoice > 0 && iChoice < num+1){
        choice = 'Y';

        while(choice == 'Y' || choice == 'y'){
            if(Translation[iChoice-1].count == 1){  //if entry has only 1 language translation pair inside it
                for(j = iChoice-1; j < num; j++){
                    Translation[j] = Translation[j+1];
                }
                num--;  //decrement number of entries initialized
                choice = 'N';
            }else{
                printf("Input the number of the language-translation pair inside the entry to be deleted: ");
                scanf("%d%c", &iChoice2, &cDump);
    
                if(iChoice2 < 1 || iChoice2 > Translation[iChoice-1].count){
                    printf("Invalid input\n");
                    do{
                        printf("Will a deletion still be done? [Y]es or [N]o: ");
                        scanf("%c%c", &choice, &cDump);

                        if(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n'){
                            printf("Invalid input\n");
                        }
                    }while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
                }else if(iChoice2 > 0 && iChoice2 < Translation[iChoice-1].count+1){
                    for(iChoice3 = iChoice2-1; iChoice3 < Translation[iChoice-1].count; iChoice3++){    //deletion of language-translation pair
                        strcpy(Translation[iChoice-1].language[iChoice3], Translation[iChoice-1].language[iChoice3+1]); //language that is stored after the deleted language will move
                        strcpy(Translation[iChoice-1].word[iChoice3], Translation[iChoice-1].word[iChoice3+1]); //translation that is stored after the deleted translation will move
                    }
                    Translation[iChoice-1].count--; //decrement the number of language-translation pairs initialized in that entry
                    printf("Will you delete another language-translation pair after this? [Y]es or [N]o: ");              
                    scanf("%c%c", &choice, &cDump);
                }
            }
        }
    }
    printf("Reverting back to Manage Data menu.\n");
    return num;
}

/*  void DisplayAllEntries() = will display all entries initialized
    @param num - initialized number of entries
    @param Translation - where all the language-translation pairs are stored
*/
void DisplayAllEntries(TranslationType *c, int num){
    int i = 0;
    char choice, cDump; 

    if(num == 1){
        Display(c[i]);
        printf("No more next entry\n");
    }else if(num > 1){
        Display(c[i]);

        do{
            do{
                printf("N = view next entry of language-translation pair\n");
                printf("P = view previous entry of language-translation pair\n");
                printf("X = exit\n");
                printf("\nInput: ");
                scanf("%c%c", &choice, &cDump);

                if(choice != 'N' && choice != 'n' && 
                    choice != 'P' && choice != 'p' && 
                    choice != 'X' && choice != 'x'){
                    printf("Invalid input\n");
                }
            }while(choice != 'N' && choice != 'n' && 
            choice != 'P' && choice != 'p' && 
            choice != 'X' && choice != 'x');
            
            switch(choice){
                case 'N':
                    if(i < num-1){
                        i++;
                        Display(c[i]);
                    }else if(i == num-1){
                        printf("\nNo more next entry\n\n");
                    }
                break;
                case 'n':
                    if(i < num-1){
                        i++;
                        Display(c[i]);
                    }else if(i == num-1){
                        printf("\nNo more next entry\n\n");
                    }
                break;
                case 'P':
                    if(i > 0){
                        i--;
                        Display(c[i]);
                    }else{
                        printf("No more previous entry\n");
                        printf("\n");
                    }
                    break;
                case 'p':
                    if(i > 0){
                        i--;
                        Display(c[i]);
                    }else{
                        printf("No more previous entry\n");
                        printf("\n");
                    }
                    break;
                case 'X':
                    printf("\n");
                    i = num;
                break;
                case 'x':
                    printf("\n");
                    i = num;
                    break;
            }
        }while(i < num);
    }
    printf("Reverting back to the Manage Data menu.\n\n");
}

/*  void SearchWord() = will search a given word, then will return the language-translation pair with the given word
    @param num - initialized number of entries
    @param Translation - where all the language-translation pairs are stored
*/
void SearchWord(int num, TranslationType *Translation){
    string20 LWord;
    int i, j;
    int k = 0;
    int l = 0;
    int count = 0;
    int index[150];
    char choice, cDump;
    
    printf("\nInput word: ");
    scanf("%s%c", LWord, &cDump);
    
    for(i = 0; i < num; i++){   //search for the given word
        for(j = 0; j < Translation[i].count; j++){
            if(strcmp(LWord, Translation[i].word[j]) == 0){ //if given word matches one of the existing translations
                count++;
                index[k] = i;
                k++;
            }
        }
    }
    
    if(count == 0){
        printf("\nNo matches of the word were found.\n");
    }else if(count == 1){   //if given word has only 1 matching translation
        Display(Translation[index[l]]);
        printf("No more next entry\n");
    }else if(count > 1){    //if given word has 2 or more matching translations
        Display(Translation[index[l]]);

        do{
            do{
                printf("N = view next entry of language-translation pair\n");
                printf("P = view previous entry of language-translation pair\n");
                printf("X = exit\n");
                printf("Input: ");
                scanf("%c%c", &choice, &cDump);

                if(choice != 'N' && choice != 'n' && 
                    choice != 'P' && choice != 'p' && 
                    choice != 'X' && choice != 'x'){
                    printf("Invalid input\n");
                }
            }while(choice != 'N' && choice != 'n' && 
            choice != 'P' && choice != 'p' && 
            choice != 'X' && choice != 'x');
            
            switch(choice){
                case 'N':
                    if(l < count-1){
                        l++;
                        Display(Translation[index[l]]);
                    }else if(l == count-1){
                        printf("\nNo more next entry\n\n");
                    }
                    break;
                case 'n':
                    if(l < count-1){
                        l++;
                        Display(Translation[index[l]]);
                    }else if(l == count-1){
                        printf("\nNo more next entry\n\n");
                    }
                    break;
                case 'P':
                    if(l > 0){
                        l--;
                        Display(Translation[index[l]]);
                    }else{
                        printf("No more previous entry\n");
                        printf("\n");
                    }
                    break;
                case 'p':
                    if(l > 0){
                        l--;
                        Display(Translation[index[l]]);
                    }else{
                        printf("No more previous entry\n");
                        printf("\n");
                    }
                    break;
                case 'X':
                    printf("\n");
                    l = count;
                    break;
                case 'x':
                    printf("\n");
                    l = count;
                    break;
            }
        }while(l < count);
    }
    printf("Reverting back to the Manage Data menu.\n\n");
}

/*  void SearchTranslation() = will search a given language-translation pair, then 
    will return the searched language-translation pair
    @param num - initialized number of entries
    @param Translation - where all the language-translation pairs are stored
*/
void SearchTranslation(TranslationType *Translation, int num){
    string20 LWord;
    string20 LLanguage;
    int i, j;
    int k = 0;
    int l = 0;
    int count = 0;
    int index[150];
    char choice, cDump;

    printf("Input language:\n");
    scanf("%s%c", LLanguage, &cDump);
    printf("Input word:\n");
    scanf("%s%c", LWord, &cDump);

    for(i = 0; i < num; i++){   //search for the given language-translation pair
        for(j = 0; j < Translation[i].count; j++){
            if(strcmp(LLanguage, Translation[i].language[j]) == 0 && strcmp(LWord, 
                Translation[i].word[j]) == 0){  //if given language-translation pair matches one of the existing language-translation pairs
                count++;
                index[k] = i;
                k++;
            }
        }
    }
    
    if(count == 0){
        printf("No matches of the language-translation pairs were found.\n");
    }else if(count == 1){   //if given language-translation pair has only 1 matching language-translation pair
        Display(Translation[index[l]]);
        printf("No more next entry\n");
    }else if(count > 1){    //if given language-translation par has 2 or more matching language-translation pair
        Display(Translation[index[l]]);

        do{
            do{
                printf("N = view next entry of language-translation pair\n");
                printf("P = view previous entry of language-translation pair\n");
                printf("X = exit\n");
                printf("Input: ");
                scanf("%c%c", &choice, &cDump);

                if(choice != 'N' && choice != 'n' && 
                    choice != 'P' && choice != 'p' && 
                    choice != 'X' && choice != 'x'){
                    printf("Invalid input\n");
                }
            }while(choice != 'N' && choice != 'n' && 
            choice != 'P' && choice != 'p' && 
            choice != 'X' && choice != 'x');
            
            switch(choice){
                case 'N':
                    if(l < count-1){
                        l++;
                        Display(Translation[index[l]]);
                    }else if(l == count-1){
                        printf("\nNo more next entry\n\n");
                    }
                    break;
                case 'n':
                    if(l < count-1){
                        l++;
                        Display(Translation[index[l]]);
                    }else if(l == count-1){
                        printf("\nNo more next entry\n\n");
                    }
                    break;
                case 'P':
                    if(l > 0){
                        l--;
                        Display(Translation[index[l]]);
                    }else{
                        printf("No more previous entry\n");
                        printf("\n");
                    }
                    break;
                case 'p':
                    if(l > 0){
                        l--;
                        Display(Translation[index[l]]);
                    }else{
                        printf("No more previous entry\n");
                        printf("\n");
                    }
                    break;
                case 'X':
                    printf("\n");
                    l = count;
                    break;
                case 'x':
                    printf("\n");
                    l = count;
                    break;
            }
        }while(l < count);
    }
    printf("Reverting back to the Manage Data menu.\n\n");
}

/*  void SortAlphabetical() = will rearrange the contents of the array of language-translation pairs based on the first letter of each language 
    @param num - initialized number of entries
    @param Translation - where all the language-translation pairs are stored
*/
void SortAlphabetical(TranslationType *Translation, int num){
    int i, j, k;
    string20 temp;

    for(i = 0; i < num; i++){
        for(j = 0; j < Translation[i].count-1; j++){
            for(k = j + 1; k < Translation[i].count; k++){
                if(strcmp(Translation[i].language[j], Translation[i].language[k]) > 0){
                    strcpy(temp, Translation[i].language[j]);
                    strcpy(Translation[i].language[j], Translation[i].language[k]);
                    strcpy(Translation[i].language[k], temp);
                    strcpy(temp, Translation[i].word[j]);
                    strcpy(Translation[i].word[j], Translation[i].word[k]);
                    strcpy(Translation[i].word[k], temp);
                }
            }
        }
    }
}

/*  void Export() = will export the contents of the program to a file 
    @param num - initialized number of entries
    @param Translation - where all the language-translation pairs are stored
*/
void Export(int num, TranslationType *Translation){
    string30 FName;
    FILE *fp_output;
    char cDump;
    int i, j;
    printf("Enter the export file name: ");
    scanf("%s%c", FName, &cDump);
    fp_output = fopen(FName, "w");

    if(fp_output != NULL){
        for(i = 0; i < num; i++){
            for(j = 0; j < Translation[i].count; j++){
                if(j > 0 && j < Translation[i].count-1){
                    fprintf(fp_output, "%s: %s\n", Translation[i].language[j], 
                    Translation[i].word[j]);
                }else if(j == Translation[i].count-1){
                    fprintf(fp_output, "%s: %s\n\n", Translation[i].language[j], 
                    Translation[i].word[j]);
                }
            }
        }
        fclose(fp_output);
    }else{
        printf("Cannot open file for writing\n");
    }
}

/*  void Import() = will import the contents of the given text file to the program
    @param num - initialized number of entries
    @param Translation - where all the language-translation pairs are stored
*/
int Import(int num, TranslationType *Translation){
    string150 text;
    string30 FName;
    string20 word[150];
    string20 word2[150];
    string20 cmp;
    FILE *fp_input;
    char choice, cDump;
    int length, i, o;
    int count = 0;
    int count2 = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    printf("Enter the import file name: ");
    scanf("%s%c", FName, &cDump);
    fp_input = fopen(FName, "r");
    strcpy(cmp, "\0");

    if(fp_input != NULL){
        if(num == 0){
            while(!feof(fp_input)){
                fgets(text, 151, fp_input);
                length = strlen(text);
                text[strlen(text) - 1] = '\0';
                
                if(strcmp(text, cmp) == 0){
                    num++;
                    n = 0;
                }else if(strcmp(text, cmp) != 0){
                    for(i = 0; i <= length; i++){
                        if(text[i] == ' ' || text[i] == '\0' || text[i] == ':'){
                            word[k][j] = '\0';
                            k++;
                            j = 0;
                            count++;
                        }else{
                            word[k][j] = text[i];
                            j++;
                        }
                    }
                
                    while(l < count){
                        if(strcmp(word[l], cmp) != 0){
                            strcpy(word2[m], word[l]);
                            count2++;
                            m++;
                        }
                        l++;
                    }
                    strcpy(Translation[num].language[n], word2[0]);
                    strcpy(Translation[num].word[n], word2[1]);
                    
                    if(n == 0){
                        Translation[num].count = 1;
                    }else if(n > 0){
                        Translation[num].count++;
                    } 
                    n++; 
                }
                strcpy(text, "");
                count = 0;
                count2 = 0;
                length = 0;
                j = 0;
                k = 0;
                l = 0;
                m = 0;
                
                for(o = 0; o < count; o++){
                    strcpy(word[o], "");
                    strcpy(word2[o], "");
                }
            }
        }else{
            while(!feof(fp_input)){
                fgets(text, 151, fp_input);
                length = strlen(text);
                text[strlen(text) - 1] = '\0';
                
                if(strcmp(text, cmp) == 0){
                    num++;
                    n = 0;
                }else if(strcmp(text, cmp) != 0){
                    for(i = 0; i <= length; i++){
                        if(text[i] == ' ' || text[i] == '\0' || text[i] == ':'){
                            word[k][j] = '\0';
                            k++;
                            j = 0;
                            count++;
                        }else{
                            word[k][j] = text[i];
                            j++;
                        }
                    }
                    
                    while(l < count){
                        if(strcmp(word[l], cmp) != 0){
                            strcpy(word2[m], word[l]);
                            count2++;
                            m++;
                        }
                        l++;
                    }
                    printf("%s: %s\n", word2[0], word2[1]);
                    
                    do{
                        printf("Will this be added to the list of entries? [Y]es or [N]o: ");
                        scanf("%c%c", &choice, &cDump);

                        if(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n'){
                            printf("Invalid input\n");
                        }
                    }while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
                    
                    if(choice == 'Y' || choice == 'y'){
                        strcpy(Translation[num].language[n], word2[0]);
                        strcpy(Translation[num].word[n], word2[1]);

                        if(n == 0){
                            Translation[num].count = 1;
                        }else if(n > 0){
                            Translation[num].count++;
                        } 
                        n++;
                    }
                }
                strcpy(text, "");
                count = 0;
                count2 = 0;
                length = 0;
                j = 0;
                k = 0;
                l = 0;
                m = 0;
                
                for(o = 0; o < count; o++){
                strcpy(word[o], "");
                strcpy(word2[o], "");
                }
            }
        }
        fclose(fp_input);
    }else{
        printf("Cannot open file for reading\n");
    }

    return num;
}

/*  @param num - initialized number of entries
    @param Translation - where all the language-translation pairs are stored
*/
int ManageDataMenu(int num, TranslationType *Translation){
    int con = 0;
    int choice = 0;
    int check = 0;
    char cDump;

    do{
        printf("\n1 = Add Entry\n");
        printf("2 = Add Translation\n");
        printf("3 = Modify Entry\n");
        printf("4 = Delete Entry\n");
        printf("5 = Delete Translation\n");
        printf("6 = Display All Entries\n");
        printf("7 = Search Word\n");
        printf("8 = Search Translation\n");
        printf("9 = Export\n");
        printf("10 = Import\n");
        printf("11 = Exit\n");  // exit manage data menu and return to the main

        do{ 
            printf("\nInput choice: ");
            scanf("%d%c", &choice, &cDump); 
            if(choice > 11 || choice < 1){
            printf("Invalid input\n");
            }else
            check++;
        }while (check == 0);
        
        switch (choice){
            case 1:
                if(num < 150){
                    num = AddEntry(num, Translation);
                }else
                    printf("Maximum amount of entries already inputted.\n");
                break;
            case 2:
                if(num == 0){
                    printf("No entry/entries exist yet\n");
                    printf("Input an entry first\n");
                }else{
                    AddTranslations(num, Translation); 
                    SortAlphabetical(Translation, num);
                }
                break;
            case 3:
                if(num == 0){
                    printf("No entry/entries exist yet\n");
                    printf("Input an entry first\n");
                }else{
                    ModifyEntry(num, Translation);
                }
                break;
            case 4:
                if(num == 0){
                    printf("No entry/entries exist yet\n");
                    printf("Input an entry first\n");
                }else{
                    num = DeleteEntry(Translation, num);
                }
                break;
            case 5:
                if(num == 0){
                    printf("No entry/entries exist yet\n");
                    printf("Input an entry first\n");
                }else{
                    num = DeleteTranslation(Translation, num);
                }
                break;
            case 6:
                if(num == 0){
                    printf("No entry/entries exist yet\n");
                    printf("Input an entry first\n");
                }else{
                    DisplayAllEntries(Translation, num);
                }
                break;
            case 7: //
                if(num == 0){
                    printf("No entry/entries exist yet\n");
                    printf("Input an entry first\n");
                }else{
                    SearchWord(num, Translation);
                }
                break;
            case 8:
                if(num == 0){
                    printf("No entry/entries exist yet\n");
                    printf("Input an entry first\n");
                }else{
                    SearchTranslation(Translation, num);
                }
            break;
            case 9:
                if(num == 0){
                    printf("No entry/entries exist yet\n");
                    printf("Input an entry first\n");
                }else{
                    Export(num, Translation);
                }
                break;
            case 10:
                num = Import(num, Translation);
                SortAlphabetical(Translation, num);
                break;
            case 11:
                con++; 
                break;
        }
    }while(con == 0);

    return num;
}

/*  void IdentifyMainLanguage() = will identify the main language of a given phrase 
    from the user, and will display what is the main language of the given phrase
    @param num - initialized number of entries
    @param Translation - where all the language-translation pairs are stored
*/
void IdentifyMainLanguage(int num, TranslationType *Translation){
    string150 text;
    string20 word[150];
    string20 word2[150];
    string20 language[150];
    string20 temp;
    string20 cmp;
    int i, n, o, p, u, v, w, x, y, z, length, ntemp, count4;
    int nLanguage[150];
    int nWord2[150];
    int count = 0;
    int count2 = 0;
    int count3 = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int q = 0;

    printf("Input the text to be identified: ");
    fgets(text, 151, stdin);
    text[strlen(text) - 1] = '\0';
    length = strlen(text);
    strcpy(cmp, "\0");

    for(i = 0; i <= length; i++){   //split the given phrase into words
        if(text[i] == '.' || text[i] == ',' || text[i] == '!' || text[i] == '?'){
            word[k][j] = '\0';
            k++;
            j = 0;
            count++;
        }else if(text[i] == ' ' || text[i] == '\0'){
            word[k][j] = '\0';
            k++;
            j = 0;
            count++;
        }else{
            word[k][j] = text[i];
            j++;
        }
    }

    while(l < count){   //keeps the arrays with words
        if(strcmp(word[l], cmp) != 0){
            strcpy(word2[m], word[l]);
            count2++;
            m++;
        }l++;
    }
    if(num == 0){   //if there are no entries this will be executed
        printf("It cannot determine the language\n");
        printf("No entry/entries exist yet\n");
        printf("Input an entry first\n");
        printf("Reverting back to the Language Tools menu.\n\n");
    }else if(num > 0){
        for(n = 0; n < count2; n++){    //this will initialized all the words into a new array that have pairs in the structures
            nWord2[n] = q;

            for(o = 0; o < num; o++){
                for(p = 0; p < Translation[o].count; p++){
                    if(strcmp(word2[n], Translation[o].word[p]) == 0 && q == 0){
                        strcpy(language[q], Translation[o].language[p]);
                        nLanguage[q] = 1;
                        count3++;
                        q++;
                    }else if(strcmp(word2[n], Translation[o].word[p]) == 0 && q > 0){
                        count4 = 0;

                        for(i = nWord2[n]; i < q; i++){
                            if(strcmp(language[i], Translation[o].language[p]) == 0){
                                count4++;
                            }
                        }

                        if(count4 == 0){
                            strcpy(language[q], Translation[o].language[p]);
                            nLanguage[q] = 1;
                            count3++;
                            q++;
                        }
                    }
                }
            }
        }

        if(count3 > 1){ //this will remove the extra languages that are the same and will increment the amount of the nLanguage
            for(u = 0; u < count3-1; u++){
                for(v = u+1; v < count3; v++){
                    if(strcmp(language[u], language[v]) == 0){
                        for(w = v; w < count3; w++){
                            strcpy(language[w], language[w+1]);
                            nLanguage[w] = nLanguage[w+1];
                        }
                        count3--;
                        v--;
                        nLanguage[u]++;
                    }
                }
            }
        }

        if(count3 == 0){    //if the words from the text have no pairs from the words from the structure
            printf("It cannot determine the language\n");
            printf("Reverting back to the Language Tools menu.\n\n");
        }else if(count3 == 1){  //if only one word has a pair
            printf("The main language of the text is %s\n", language[0]);
            printf("Reverting back to the Language Tools menu.\n\n");
        }else if(count3 > 1){   //if two or more words have a pair
            for(x = 0; x < count3-1; x++){  //arranges it from highest to lowest
                for(y = x + 1; y < count3; y++){
                    if(nLanguage[x] < nLanguage[y]){
                        strcpy(temp, language[x]);
                        strcpy(language[x], language[y]);
                        strcpy(language[y], temp);
                        ntemp = nLanguage[x];
                        nLanguage[x] = nLanguage[y];
                        nLanguage[y] = ntemp;
                    }
                }
            }

            if(nLanguage[0] == nLanguage[1]){   //if two or more languages have the greatest value
                printf("The main languages of the text are the following:\n");

                for(z = 0; z < count3; z++){
                    if(z == 0){
                        printf("%s\n", language[z]);
                    }else if(z > 0 && nLanguage[0] == nLanguage[z]){
                        printf("%s\n", language[z]);
                    } 
                }
            }else{  //if one language has the greatest value
                printf("The main language of the text is %s\n", language[0]);
            }
            printf("Reverting back to the Language Tools menu.\n\n");
        }
    }
}

/*  void SimpleTranslation() = will translate a given phrase from the user, and will 
    display the translated phrase
    @param num - initialized number of entries
    @param Translation - where all the language-translation pairs are stored
*/
void SimpleTranslation(int num, TranslationType *Translation){
    string150 text;
    string150 text2;
    string20 word[150];
    string20 word2[150];
    string20 CLanguage;
    string20 NLanguage;
    string20 cmp;
    int i, n, q, r, s, t, length;
    int count = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    char choice, cDump;

    printf("Input the current language of the text: ");
    scanf("%s%c", CLanguage, &cDump);
    printf("Input the new language of the text to be translated to: ");
    scanf("%s%c", NLanguage, &cDump);
    
    do{
        printf("Input the text to be translated: ");
        fgets(text, 151, stdin);
        text[strlen(text) - 1] = '\0'; 
        length = strlen(text);
        strcpy(cmp, "\0");

        for(i = 0; i <= length; i++){   //split the given phrase into words
            if(text[i] == '.' || text[i] == ',' || text[i] == '!' || text[i] == '?'){
                word[k][j] = '\0';
                k++;
                j = 0;
                count++;
            }else if(text[i] == ' ' || text[i] == '\0'){
                word[k][j] = '\0';
                k++;
                j = 0;
                count++;
            }else{
                word[k][j] = text[i];
                j++;
            }
        }

        while(l < count){   //keeps the arrays with words
            if(strcmp(word[l], cmp) != 0){
                strcpy(word2[m], word[l]);
                count2++;
                m++;
            }
            l++;
        }
        if(num == 0){   //if there are no entries this will be executed
            printf("\nIt cannot translate the text\n");
            printf("No entry/entries exist yet\n");
            printf("Input an entry first\n");
            printf("Reverting back to the Language Tools menu.\n\n");
            choice = 'N';
        }else if(num > 0){  //this translates the text with the current language with the new language
            do{
                for(n = 0; n < count2; n++){
                    for(q = 0; q < num; q++){
                        for(r = 0; r < Translation[q].count; r++){
                            if(strcmp(word2[n], Translation[q].word[r]) == 0 && strcmp(CLanguage,
                                Translation[q].language[r]) == 0){
                                for(s = 0; s < Translation[q].count; s++){
                                    if(strcmp(NLanguage, Translation[q].language[s]) == 0){
                                        strcpy(word2[n], Translation[q].word[s]);
                                        count4++;
                                        n = count2;
                                    }
                                }
                            }
                        }
                    }
                }
                count3++;
            }while(count2 != count3);

            for(t = 0; t < count; t++){ //concatenates the words with spaces in between
                strcat(text2, word2[t]);
                strcat(text2, " ");
            }

            if(count4 == 0){    //if no matches were found
                printf("\nNo matches were found, therefore no translations were made\n");
                printf("%s\n", text2);
            }else if(count4 > 0){   //if matches were found
                printf("\nTranslating the text from %s to %s\n", CLanguage, NLanguage);
                printf("%s\n", text2);
            }
            
            do{ //condition for translating another text, specifically if yes then it reverts the current values to the old values
                printf("Translate another text of the same source and output language? [Y]es or [N]o: ");
                scanf("%c%c", &choice, &cDump);

                if(choice == 'Y' || choice == 'y'){
                    strcpy(text, "");
                    strcpy(text2, "");
                    count = 0;
                    count2 = 0;
                    count3 = 0;
                    count4 = 0;
                    length = 0;
                    j = 0;
                    k = 0;
                    l = 0;
                    m = 0;
                    
                    for(i = 0; i < 150; i++){
                    strcpy(word[i], "");
                    strcpy(word2[i], "");
                    }
                }
                
                if(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n'){
                    printf("Invalid Input\n");
                }
            }while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
        }
    }while(choice != 'N' && choice != 'n');
}

int main(){
    int con = 0;
    int num = 0;
    int choice = 0;
    int check = 0;
    struct TranslationTag Translation[150];
    char cDump;

    do{
        printf("\n1 = Identify Main Language\n");
        printf("2 = Simple Translation\n");
        printf("3 = Manage Data Menu\n");
        printf("4 = Exit\n");

        do{
            printf("\nInput choice: ");
            scanf("%d%c", &choice, &cDump);

            if(choice > 4 || choice < 1){
                printf("Invalid Input\n");
            }else
                check++;
        }while(check == 0);
        
        switch(choice){
            case 1:
                IdentifyMainLanguage(num, Translation);
                break;
            case 2:
                SimpleTranslation(num, Translation);
                break;
            case 3:
                num = ManageDataMenu(num, Translation);
                break;
            case 4:
                con++;
                break;
        }
    }while(con == 0);

    return 0;
}