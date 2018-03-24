bool checkPossibility(int* nums, int numsSize) 
{
    int i,  j;
	for (i = 0;i < numsSize-1; i++)
	{
        if(nums[i]>nums[i+1])
            {
            if (i<1 || nums[i-1] < nums[i + 1])
		        nums[i]=nums[i+1];
            else 
                nums[i+1]=nums[i];
		    for (j =0; j < numsSize-1; j++)
                {
                 if (nums[j] > nums[j+1])
				        return false;
                }
            }
	}
    
    return true;
    
}
