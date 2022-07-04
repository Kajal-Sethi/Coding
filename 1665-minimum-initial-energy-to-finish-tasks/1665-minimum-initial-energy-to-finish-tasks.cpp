class Solution {
public:
    
    static bool usee(vector<int>a, vector<int>b)
    {
        return (a[1]-a[0])>(b[1]- b[0]);
    }
        
    int minimumEffort(vector<vector<int>>& tasks) {
        // jisme wastage sabse jayada he vo phele hoga
        // tasks[i] = [actuali, minimumi]
        // minimum initial amount of energy you will need to finish all the tasks
        // at every step left energy should be >=max(actual, min energy)
        
        int i, left=0, total=0;
        sort(tasks.begin(), tasks.end(), usee);
        
        for(i=0; i<tasks.size(); i++)
        {
         //   cout<<tasks[i][0]<<" ";
            if(left<tasks[i][1])
            {
                total+=tasks[i][1]-left;
                left=tasks[i][1]-tasks[i][0];
            }
            
            else
            {
                left-=tasks[i][0];
            }
            
        }
        
        return total;
        
        
//         for(i=0; i<tasks.size(); i++)
//             total+=tasks[i][0];
        
//         // cout<<tasks[4][0];
//         total = max(total, tasks[0][1]);
//         left=total;
//         i=0;
        
//         while(i<tasks.size())
//         {
//             if(left>=tasks[i][1])       // at every step left energy should be >=max(actual, min energy)
//             {    
//                 left-=tasks[i][0];
//                 cout<<left<<" "<<i<<endl;
//                 i++;
//             }
            
//             else
//             {
//                 // cout<<tasks[i][1]<<" ";
//                 total+=tasks[i][1]-left;
//                 left=tasks[i][1];
//             }    
//         }
//         return total;
        
    }
};