class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // (total_time/time_die + 1)^pigs >= buckets
        
        // pigs>= log buckets/ log (total_time/time_die + 1);
        
        int tests = minutesToTest/minutesToDie;
        return ceil(log2 (buckets)/log2 (tests + 1));
    }
};