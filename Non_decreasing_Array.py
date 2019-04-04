class Solution(object):
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums)==1:
            return True
        count_modified = 0
        for index in range(len(nums)-1):
            if count_modified < 1 and nums[index]>nums[index+1]:
                if index>0:
                    if nums[index-1]>=nums[index+1]:
                        nums[index+1]=nums[index]
                    else:
                        nums[index]=nums[index+1]
                else:
                    nums[index]=nums[index+1]
                count_modified = count_modified + 1
                
            if count_modified == 1:
                for i in range(len(nums)-1):
                    if nums[i]>nums[i+1]:
                        return False
                return True
            elif count_modified >= 2:
                return False
            elif count_modified == 0:
                error=0
                for i in range(len(nums)-1):
                    if nums[i]>nums[i+1]:
                        error=1
                        break
                if error == 0:
                    return True
