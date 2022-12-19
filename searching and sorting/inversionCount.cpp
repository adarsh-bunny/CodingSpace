class Solution {
public:
     long long int temp[500000];
    long long int gi=0;
    void merge(vector<int>& nums, int left,int mid,int right)
    {     
      
        int i=left,j=mid+1;
        int k=left;
    
        while(i<=mid && j<=right)
        {
            if(nums[i]>nums[j])
            {
                gi+=(mid+1-i);
                temp[k++]=nums[j++];  
            }
            else
            {
                   temp[k++]=nums[i++];   
            }
        }
        
        if(i>mid)
        {
             while(j<=right)
        {
            temp[k++]=nums[j++];
        }
            
        }
        else
        {
             while(i<=mid)
        {
            temp[k++]=nums[i++];
        }
        }
       
        
        
        for(int i=left;i<k;i++)
            nums[i]=temp[i];
        
    
    }
    void merge_sort(vector<int>& nums,int start,int end)
    {
        if(start<end)
        {
            int mid= (start+ end)/2;
            merge_sort(nums,start,mid);
            merge_sort(nums,mid+1,end);
            merge(nums,start,mid,end);
           
        }
       
    }
    bool isIdealPermutation(vector<int>& nums) {
        int n=nums.size();
        int li=0;
    for(int i=0;i<n-1;i++)
        if(nums[i]>nums[i+1])
            li++;
    
         merge_sort(nums, 0,n-1);
        
        return li==gi;
    }
};