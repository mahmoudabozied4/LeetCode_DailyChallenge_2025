func twoSum(nums []int, target int) []int {
    numberMap := make(map[int]int)

    for index, number := range nums {
        neededNumber := target - number
        if complementIndex, ok := numberMap[neededNumber]; ok {
            return []int{complementIndex, index}
        }
        numberMap[number] = index
    }

    return []int{}
}