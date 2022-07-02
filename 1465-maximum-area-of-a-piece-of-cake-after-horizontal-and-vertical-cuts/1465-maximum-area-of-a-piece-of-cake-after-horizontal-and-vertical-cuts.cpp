class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        horizontalCuts.insert(horizontalCuts.begin(),0);
        horizontalCuts.push_back(h);
        verticalCuts.insert(verticalCuts.begin(),0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int i, j;
        long long hor=0, ver=0;
        for(i=0; i<horizontalCuts.size()-1; i++)
        {
            int diff=horizontalCuts[i+1]-horizontalCuts[i];
            
            if(hor<diff)
                hor = diff;
            // hor=max(hor, diff);
        }
         
        for(i=0; i<verticalCuts.size()-1; i++)
        {
            int diff=verticalCuts[i+1]-verticalCuts[i];
            
            if(ver<diff)
                ver = diff;
            // ver=max(ver, diff);
        }
        
        return (ver*hor)%1000000007;
            
//             area=0;
//             for(j=0; j<verticalCuts.size()-1; j++)
//             {
//                 // cout<<horizontalCuts[i]<<verticalCuts[j]<<" ";

//                 area = ((horizontalCuts[i+1] - horizontalCuts[i]) * (verticalCuts[j+1] - verticalCuts[j]))%1000000007;
//                 maxx=max(maxx, area);
//             }
            
//             // cout<<horizontalCuts[i]<<verticalCuts[j]<<" ";
//             // cout<<endl;
//         }
        
//         return maxx;
    }
};