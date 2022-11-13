#include <stdio.h>

void flip_words (char str[]){
    int cursor = -1;
    for (int i = 0; i < 1000; i++) {
        if(str[i]>=65 && str[i]<=90 || str[i]>=97 && str[i]<=122){
            if (cursor == -1){
                cursor = i;
            }
        }
        else {
            if (cursor != -1){
                for(int j = 0; j <= (i-cursor-1)/2; j++){
                    char temp;
                    temp = str[cursor + j];
                    str[cursor + j] = str[i-1-j];
                    str[i-1-j] = temp;
                }
                cursor = -1;
            }
        }
    }
    if (cursor != -1){
        for(int i = cursor;i<(1000 - cursor -1)/2;i++){
            char temp;
            temp = str[cursor + i];
            str[cursor + i] = str[1000-1-i];
            str[1000-1-i] = temp;
        }
    }
}
int main()
{
    char str[1000];
    fgets(str, 1000, stdin);
    flip_words(str);
    puts(str);
    return 0;
}
