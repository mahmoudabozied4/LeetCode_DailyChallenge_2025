func buildArray(target []int, n int) []string {
    ans := []string{}
    i := 0   
    num := 1  
    
    for i < len(target) && num <= n {
        if target[i] == num {
            ans = append(ans, "Push")
            i++
        } else {
            ans = append(ans, "Push", "Pop")
        }
        num++
    }
    
    return ans
}