bool canPartition(int a[],int n,int k,int sum,int idx){
        if(sum>k) return false;
        if(idx == n) return false;
        if(sum == k) return true;
        
        //taken
        if(canPartition(a,n,k,sum+a[idx],idx+1))
            return true;
        //not taken
        if(canPartition(a,n,k,sum,idx+1))
            return true;
    }

    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }   
        
        if(sum & 1) return false;
        return canPartition(arr,N,sum/2,0,0);
    }
