#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n,arr[101],arr2[101],sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {

        cin>>arr[i];
        sum=sum+arr[i];
    }
    sort(arr,arr+n);
    int s=1,n2,j=0;
    int n3;
    n3=arr[n-1]/2;
    //n2=ceil(arr[n-1]/2);

    for(int i=1;i<=n3;i++)
    {
        n2=n;
        while(s!=0&&n2>1)
        {
            if(arr[n2-1]%(i+1)==0)
            {
                arr2[j]=(arr[n2-1]-(arr[n2-1]/(i+1)))-((arr[0]*(i+1))-arr[0]);
                j++,s=1;
               

            }
            
            n2--;

        }
        //s=1;

    }
    sort(arr2,arr2+j);
    cout<<sum-arr2[j-1];
}