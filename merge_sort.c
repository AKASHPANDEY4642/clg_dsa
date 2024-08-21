//merge_sort
#include<stdio.h>
void merge(int arr[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int L[n1];
    int R[n2];
    for(int i=0;n1>i;i++)
    {
        L[i]=arr[l+i];
}
    for(int j=0;n2>j;j++)
    {
        R[j]=arr[m+1+j];
}
    int p=0,q=0,k=l;

    while(p<n1 &&q<n2)
    {
        if(L[p]>=R[q])
        {
            arr[k]=R[q];
            q++;
}
        else
        {

            arr[k]=L[p];
            p++;
}
        k++;



}
    while(p<n1)
    {
        arr[k]=L[p];
        k++;
        p++;
}
     while(q<n2)
    {
        arr[k]=R[q];
        k++;
        q++;
}


}





void merge_sort(int arr[],int l,int r)
{


    if(l<r)
    {
        int m=l+(r-l)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);

}
}





int main(void) {

    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, n - 1);
for(int i=0;n>i;i++)
{
    printf("%d ",arr[i]);

}



    return 0;
}
