#include<stdio.h>
#include<conio.h>
#include<math.h>

int main(void)
{
    int flange_w,flange_l,web_l,web_w;

    printf(" Enter width of flange(in mm) : "); // 150
    scanf("%d",&flange_w); 

    printf("\n");

    printf(" Enter length of flange(in mm) : ");  // 50
    scanf("%d",&flange_l);

    printf("\n");

    printf(" Enter length of web(in mm) : "); // 150
    scanf("%d",&web_l);

    printf("\n");

    printf(" Enter width of web(in mm) : "); // 50
    scanf("%d",&web_w);


   

    int a1,a2,y1,y2;

    a1 = flange_l * flange_w;
    y1 = flange_w + (flange_l/2);
    a2 = web_l * web_w;
    y2 = web_l /2;

    float ybar = (a1*y1 + a2*y2)/(a1+a2);

    float ig_1 = (flange_w * pow(flange_l,3))/12.0;
    int h1  = y1- ybar;

    float temp = ig_1 + a1*h1*h1;
    float ig2 = (web_w * pow(web_l,3))/12.0;
    int h2 = ybar - y2;

    float temp2 = ig2 + a2*h2*h2;
    printf("%f    %f",temp,temp2);

    float ixx = temp+temp2;

    // y-y axis

    temp = (flange_l * pow(flange_w,3))/12.0;
    temp2 = (web_l * pow(web_w,3) )/12.0;

    float iyy = temp+temp2;

    printf(" IXX = %f and IYY = %f",ixx,iyy);

    return 0;
}