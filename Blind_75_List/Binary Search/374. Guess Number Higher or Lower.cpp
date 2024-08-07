//Problem Link: https://leetcode.com/problems/guess-number-higher-or-lower/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l(1), r(n);
        int ans;
        while(l <= r){
            int mid(l + (r - l) / 2);
            // cout << mid << " ";
            if (guess(mid) == 0){
                ans = mid;
                break;
            }
            else if (guess(mid) == -1){ // greater
                r = (mid - 1);
            }
            else l = (mid + 1);
        }
    return ans;
    }
};