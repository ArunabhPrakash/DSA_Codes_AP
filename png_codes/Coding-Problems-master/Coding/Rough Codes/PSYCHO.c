#include<stdio.h>
#include<math.h>

int main(){

int n,t,even,odd,count,k,i;
scanf("%d",&t);
while(t--){
    scanf("%d",&n);
    k=sqrt(n);
    if(k*k==n) printf("Psycho Number\n");
    else{
    even=0,odd=0,count=0;
    while (n%2 == 0)
    {
        count++;
        n = n/2;
    }

    if(count>0){
    if(count&1==1) { odd++;}
    else {even++; }
    }



    for (i = 3; i <= sqrt(n); i = i+2)
    {
       count=0;
        while (n%i == 0)
        {

            count++;
            n = n/i;
         }
         if(count>0){
         if(count&1) {odd++;}
         else {even++;}
         }

    }




   if (n > 2){
    { odd++; }}

if(even>odd)
    printf("Psycho Number\n");
else
    printf("Ordinary Number\n");

}}

return 0;
}



