class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        n=len(nums)
        cnt=nums.count(val)

        for i in range(0,cnt):
            location_val=nums.index(val)
            nums.pop(location_val)
            n-=1
        print(n, "nums = ",nums)