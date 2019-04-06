class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size()!=B.size())
            return false;
        
        int count_diff=0;
        int loc_1=-1;
        int loc_2=-1;
        int mem[26]={0};
        for (int i=0;i<A.size();i++)
        {
            mem[A[i]-97]++;
            if (A[i]!=B[i])
            {
                count_diff++;
                if(count_diff>2)
                    return false;
                if(loc_1 == -1 && loc_2 == -1)
                    loc_1 = i;
                else if(loc_1 != -1 && loc_2 == -1)
                    loc_2=i;
            }
        }
        if (count_diff!=2)
        {
            if(count_diff==0)
            {
                for (int i = 0; i<26;i++)
                {
                    if(mem[i]>=2)
                        return true;
                }
                return false;
            }
            else
                return false;
        }
        else
        {
            string temp = A;
            temp[loc_1] = A[loc_2];
            temp[loc_2] = A[loc_1];
            if(temp==B)
                return true;
            else
                return false;
        }
    }
};
