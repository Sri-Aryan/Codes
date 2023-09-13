#include <stdio.h>
#include <string.h>
void main() 
{
    char a[100];
    printf("Enter the word to get its possible combination -\n");
    printf("Word is ");
    gets(a);
    int l=strlen(a),len=l,en=0,st=00,sum=0,s1=0,d=0,d1=0,d2=0,c=0,x=0,k=0,y=0,z=0,count=1;
     
     while (l>0)
     {    
         en=en*10+l;                                //To get the max end value for l length eg-321 for three,4321 for five
         st=st*10+(len+1)-l;                        //To get the min start value for l length eg-123 for the,1234 for five
         sum=sum+l;                                 //To get sum of digit (to elminate some no. bet st & en)eg-6 for the,10 for five
         l--;
     }
    for (int i = st; i <= en; i++)
    {
        c=i;x=i;y=i;                               //Copying value of i to use further
        while (c>0)
        {
            d=c%10;
            s1=s1+d;                               //To get sum of digit for value of i(to eleminate no. having sum other than 6 or 10)
            c=c/10;

            if(d>len)                              //To check if i has any digit greater than l (to eleminate no. like 141,150,204 )
            k++;
            
            while (y>0)                            //while used to eleminate no. whose digit occur more than 1 time eg. 222,303
            {
                d2=y%10;
                if(d==d2)
                {z++;}                            //if a digit occur more than 1 than z will be greater than l
                y=y/10;
            }d2=0;y=i;                            //initializing y again to use in  while next time
        }
        if(s1==sum && k==0 && z==len)             //
        {printf("%d.",count);
        count++;
            while(x>0)
            {
                d1=x%10;
                printf("%c",a[len-d1]);
                x=x/10;
            }
            printf("\n");
        }
        d=0;s1=0;d1=0,c=0,x=0,k=0,z=0,d2=0;
    }
}