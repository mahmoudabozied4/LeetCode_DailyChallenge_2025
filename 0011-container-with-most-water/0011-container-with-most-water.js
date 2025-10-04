/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let mx = 0 , l  = 0 , r = height.length-1 
    while(l < r) {
        let len = Math.min(height[l] , height[r]) , width = r - l , area = len * width 

        mx = Math.max(area , mx)
        if(height[l] < height[r]) l++
        else r--
    }
    return mx 
};