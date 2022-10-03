class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> freq(26, 0);
        int i;
        
        for(i=0; i<word.size(); i++)
            freq[word[i]-'a']++;
        
        map<int, int>mp;
        
        for(auto val: freq)
            if(val!=0)
                mp[val]++;
        
        map<int, int>::iterator it1 = mp.begin(), it2 = mp.begin();
        if((it1->second==1 || it1->first==1) && mp.size()==1)
            return true;
        
        // find the odd one out
        if(mp.size()!=2)
            return false;
        
        it2++;
        if((it1->second == 1 && it1->first - it2->first==1) || (it2->second == 1 && it2->first - it1->first==1) || (it1->first==1 && it1->second==1)) // count should be 1 and diff of num should be 1
            return true;
        

        
        return false;
        
    }
};