#!/usr/bin/env python3
'''
Two Sum problem
'''


class Solution:
    '''
    Solution to Two Sum problem
    '''
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        '''
        Computes solution in linear time
        '''
        table = {}
        index = 0
        while index < len(nums):
            if target - nums[index] in table:
                return [table[target - nums[index]], index]
            table[nums[index]] = index
            index += 1
        return None
