class Solution {
public:
    int Combine(int m, int n){
        int res = 1;
        if(m > n / 2){
            m = n - m;
        }
        for(int i = 0; i < m; i++){
            res = res * (n - i);
        }
        for(int i = 1; i <= m; i++){
            res = res/i;
        }
        return res;
    }
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int test_num = minutesToTest / minutesToDie;
        if(buckets == 1)return 0;
        if(test_num >= buckets){
            return 1;
        }
        int res = 0;
        //max_buckets[m][n] = Cm0 * max_buckets[m][n - 1] + Cm1 * max_buckets[m - 1][n - 1] + Cm2 * max_buckets[m - 2][n - 1] + Cm3 * max_buckets[m - 3][n - 1] + ...... + Cmm * max_buckets[0][n - 1]
        //0. no pig dead -- remain n - 1 time can test max_buckets[m][n - 1] buckets;
        //1. one pig dead --- this time can test Cm1 pig,  remain m - 1 pig and n - 1 time can test max_buckets[m - 1][n - 1] buckets, so every pig can drink identical max_buckets[m - 1][n - 1] buckets.
        //2. two pig dead --- this time can test Cm2 different situation, every two pigs can have max_buckets[m - 2][n - 1] same buckets, so every two different pigs can drink same max_buckets[m - 1][n - 1] buckets.
        vector<vector<int>> max_buckets(1001, vector<int>(test_num + 1, 1));
        for(int i = 1; i <= test_num; i++){
            for(int j = 1; j < 1001; j++){
                max_buckets[j][i] = 1 + max_buckets[j][i - 1];
                for(int k = 1; k < j; k++){
                    max_buckets[j][i] += Combine(j - k, j) * max_buckets[j - k][i - 1];
                }
                if(max_buckets[j][i] >= buckets){
                    if(i == test_num){
                        //cout << j << endl;
                        return j;
                    }
                    break;
                }
            }
        }
        return res;
    }
};

