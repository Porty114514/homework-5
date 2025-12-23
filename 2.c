#include<stdio.h>
/*int hou(int a,int b,int c){
        int d;
        d = (((a/100)/4) -2*(a/100) + (a - ((a/100)*100)) + ((a - ((a/100)*100))/4) + ((13 * (b + 1))/5) + c -1)%7;
        //printf("%d\n",(a - ((a/100)*100))/4);
        return d;
}
int qian(int a,int b,int c){
        int d;
        d = ((a - ((a/100)*100)) + ((a - ((a/100)*100))/4) + ((a/100)/4) - 2*(a/100) + ((13 * (b + 1))/5) + c + 2 )%7;
                return d;
}*/
int tian(int a,int b,int c){
        int sum = 0;
        for(int d = 1;d<a;d++){
                if((d%4==0&&d%100!=0)||d%400==0){
                        sum = sum + 366;
                }
                else{
                        sum = sum +365;
                }
        }
        for(int e = 1;e<b;e++){
                if(e==1||e==3||e==5||e==7||e==8||e==10||e==12){
                        sum = sum + 31;
                }
                if(e==4||e==6||e==9||e==11){
                        sum = sum +30;
                }
                if(e==2){
                        if((a%4==0&&a%100!=0)||a%400==0){
                                sum = sum + 29;
                        }
                        else{
                                sum = sum + 28;
                        }
                }
        }
        for(int f = 1;f<=c;f++){
                sum = sum + 1;
        }
 return sum;
        }
int hou(int a,int b,int c){
        int d = tian(2025,11,12);
        int e = tian(a,b,c);
        int cha;
        if(d-e<=0){
                cha = e - d;
        }
        else{
                               cha = d - e;
        }
        int f = cha%7;
        return f;
}
int qian(int a,int b,int c){
        int d = hou(a,b,c) - 10;
        return d;
}
int xingqi(int y,int m,int d){
        int w;
        if(y>1582){
                w = hou(y,m,d);
        }
        if(y<1582){
                w = qian(y,m,d);
        }
        if(y==1582){
                if(m>10){
                        w = hou(y,m,d);
                }
                if(m<10){
                        w = qian(y,m,d);
                }
                if(m==10){
                        if(d>4){
                                w = hou(y,m,d);
                        }
                        if(d<=4){
                                w = qian(y,m,d);
                        }
                }
  }
        if(y<0){
                printf("前面的区域，以后再来探索吧");
        }
        if(w==4){
                printf("sunday\n");
        }
        if(w==5){
                printf("monday\n");
        }
        if(w==6){
                printf("tuesday\n");
        }
        if(w==0){
                printf("wednesday\n");
        }
        if(w==1){
                printf("thursday\n");
        }
        if(w==2){
                printf("friday\n");
        }
        if(w==3){
                printf("saturday\n");
        }
        return 0;
}
int main(){
        int y,m;
        printf("输入年份\n");
        scanf("%d",&y);
        printf("输入月份\n");
        scanf("%d",&m);
        if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
                for(int a=1;a<=31;a++){
                        printf("%d年%d月%d日 \n",y,m,a);
xingqi(y,m,a);
                }
        }
        if(m==4||m==6||m==9||m==11){
                for(int a=1;a<=30;a++){
                        printf("%d年%d月%d日 \n",y,m,a);
                        xingqi(y,m,a);
                }
        }
        if(m==2){
                if((y%4==0&&y%100!=0)||(y%100==0&&y%400==0)){
                        for(int a=1;a<=29;a++){
                        printf("%d年%d月%d日 \n",y,m,a);
                        xingqi(y,m,a);
                        }
                }
                else{
                        for(int a=1;a<=28;a++){
                        printf("%d年%d月%d日 \n",y,m,a);
                        xingqi(y,m,a);
                        }
                }
        }
}
