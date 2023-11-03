class Solution {
public:
    int countVowelPermutation(int n) {
        int mod = 1000000000 + 7;
        //a0, e1, i2, o3, u4
        vector<long> v_num(5, 1);
        vector<long> last_num(5, 1);
        for(int i = 2; i <= n; i++){
            v_num[0] = last_num[1];
            v_num[1] = (last_num[0] + last_num[2]) % mod;
            v_num[2] = (last_num[0] + last_num[1] + last_num[3] + last_num[4] ) % mod;
            v_num[3] = (last_num[2] + last_num[4]) % mod;
            v_num[4] = last_num[0];
            last_num[0] = v_num[0];
            last_num[1] = v_num[1];
            last_num[2] = v_num[2];
            last_num[3] = v_num[3];
            last_num[4] = v_num[4];
        }
        return (v_num[0] + v_num[1] + v_num[2] + v_num[3] + v_num[4]) % mod;
    }
};
