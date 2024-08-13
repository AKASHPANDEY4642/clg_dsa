#include<stdio.h>
#include <stdlib.h>
int  si= 10;
int arr[10];
int f=-1,r=-1;
void insert(int dt)//at_top
{
    if(f==-1 &&r==-1)
    {
        f=0,r=0;
        arr[r]=dt;
}
    else if(r==si)
    {printf("over");
     return;
}
    else
    {
        r++;
        if(r==si)
        {printf("over");
         return;

}
        arr[r]=dt;
}
return;    
}
void del()
{
    if(f==r)
    {

        if(r==-1)
        {printf("under");

}
        else
        {
            printf("the del ele %d ",arr[r]);
            r=-1,f=-1;
}
}
    else
    {
        printf("the del ele %d",arr[f]);
        f++;
}
    return ;
}




void display()
{for(int i=f;r>=i;i++)
{printf("%d",arr[i]);



}
 return;
}


int main() {
    int n;
    scanf("%d",&n);
    insert(n);
    display();

    return 0;
}
