/***************************************************************************
使用双端队列存储向量的下标的值，随时保持队列中的最后一位的值
是滑动窗口中的最大值
求当前滑动窗口的值时，1.根据上一滑动窗口判断当前新增的元素是否大于上一滑动窗口的最大
值，如果大，则该值即是当前滑动窗口的最大值；
2.如果不是，则判断上一窗口需要去掉的值是不是窗口的最大值，如果不是，则上一窗口的最大值也是当前窗口的最大值；
3.如果是，则重新求当前窗口的最大值。
****************************************************************************/
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> ans;
        deque<int> q;
        for(int i =0;i < num.size();++i)
        {
            if(q.empty())
            {
                q.push_back(i);
            }
            else
            {
                while(!q.empty())
                {
                    if(num[q.back()]>num[i])
                        break;
                    q.pop_back();
                }
                q.push_back(i);
            }
            
            if(q.back()-q.front()>=size)
                q.pop_front();
            if(i >= size-1)
                ans.push_back(num[q.front()]);
        }
        return ans;
    }
};
