#include <stdlib.h>
#include <limits.h>

int max_sub_array(int a[] ,int n)
{
    int i,j;
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    
    for(i=0 ; i<n ;i++)
    {
        max_ending_here += a[i];
        
        if(max_ending_here < 0 )
            max_ending_here =0;
            
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    
    if(max_so_far == 0)
        return max(a,n);
    else
        return max_so_far;  
}

int max(int a[] ,int n)
{
    int i,max=INT_MIN;
    
    for(i=0;i<n;i++)
    {
        if(max<a[i])
        max= a[i];
    }
    return max;
}

int main() {
	int i,n,t;
	int *a;
	
	scanf("%d",&t);
	
	while(t--)
	{
	    scanf("%d",&n);
	    
	    a = (int *) malloc (sizeof(int) * n);
	    
	    for(i=0;i<n;i++)
	    scanf("%d",&a[i]);
	    
	    printf("%d\n",max_sub_array(a, n));
	    
	}
	return 0;
}