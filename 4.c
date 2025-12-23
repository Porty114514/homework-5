#include<stdio.h>
char f(char (*pp)[5]){
                return pp[1][2];
        }
int main(){
    char *B[20];
    /*B[0] = "abcd";
    B[1] = "efgh";
    B[2] = "ijkl";
    B[3] = "mnop";
    B[4] = "qrst";
    B[5] = "uvwxyzabc";
    B[6] = "abcdefg";
    B[7] = "hijklmn";*/
    char a = f(B);
    printf("%c\n",a);
    return 0;
}
