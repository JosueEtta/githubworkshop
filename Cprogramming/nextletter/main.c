#include <stdio.h>

void printfEachLetter(char max,char letter){
    char nextLetter= letter;
    printf("The next three letters of the alphabet are:");
     for(int i = 1 ; i <= 3;i++){
         nextLetter++;
        if(nextLetter > max){
            nextLetter = (max == 'Z')? 'A' : 'a';
            printf(" %c ",nextLetter);
        }
        else{
            printf(" %c ",nextLetter);
        }
     }
}

void printNextThreeLetter(char letter){
   if(letter >= 'a' && letter <= 'z'){
      printfEachLetter('z',letter);
   }
   else if(letter >= 'A' && letter <= 'Z'){
     printfEachLetter('Z',letter);
   }
}

int main(){
    char inputLetter = '\0';
     printf("Enter a letter of the alphabet:");
    scanf(" %c",&inputLetter);
    while(!((inputLetter >= 'A' && inputLetter <= 'Z')||(inputLetter >= 'a' && inputLetter <= 'z'))){
        printf("You must input a letter of the alphabet:");
        scanf(" %c",&inputLetter);
    }
     printNextThreeLetter(inputLetter);
    return 0;
}
