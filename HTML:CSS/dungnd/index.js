const nums1 = [3]
const nums2 = [-2,-1]

function sortNumber(a, b) {
    return a - b;
}

var findMedianSortedArrays = function(nums1, nums2) {
    if(nums1.length==0 && nums2.length==1) return nums2[0];
    else if(nums2.length==0 && nums1.length==1) return nums1[0];
    else {
        var arr = nums1.concat(nums2).sort(sortNumber);
        if(arr.length % 2 == 0) {
          return (arr[(arr.length / 2)-1] + arr[(arr.length / 2)])/2;
        } else {
            return arr[Math.floor(arr.length / 2)];
        }
        // return arr
        // -2 -1 3
    }

};

console.log(findMedianSortedArrays(nums1, nums2))