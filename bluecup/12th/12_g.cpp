#include <iostream>
#include <vector> 
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        int res = 0;
        vector<int> v(32); // 统计每一个bit位总共有多少个1 
        int x;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            res ^= x;
            for (int j = 0; (j < 32) && x; ++j)
            {
                if (x & 1)
                {
                    v[j]++;
                }
                x >>= 1; 
            }
        }
        /*
         * 最优策略：
         * 为了让自己的数更大，优先选择将高位的1异或到自己的数上 
         * 如果自己高位已是1，对方对应高位也是1，则优先将1异或到对方身上，使其为0 
        */ 
        
        // 特殊情况：所有数异或起来是0，说明每个比特位上的1都有偶数个
        // 此时采取最优策略，最终Alice和Bob得到的数是相同的，因此平局 
        if (res == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            // 一般情况:从高位开始选数进行异或
            for (int i = 31; i >= 0; --i)
            {
                if (v[i] > 0)
                {
                    if (v[i] % 2 == 0) // 如果是偶数个，则无法通过这一位决出胜负
                    {
                        continue;    
                    }    
                    else // 如果是奇数个，分类讨论 
                    {
                        if (v[i] == 1) // 由于Alice先拿，此时必赢 
                        {
                            cout << 1 << endl;
                        } 
                        // 如果数列大小n是偶数，那么由于该bit位1是奇数个，故0也是奇数个 
                        else if (n % 2 == 0)
                        {
                            /* 
                             * 若Alice先拿1，那么Bob必然拿0，而Alice也因此只能拿0
                             * 最终Bob拿最后1个0, 此时由于1有偶数个，Alice只能用1给Bob异或，此时Bob该位是1
                             * Bob再给A异或使其为0，A再给自己异或使其为1，最终，Bob拿最后一个1给Alice异或使其为0
                             * 
                             * 若Alice先拿0，那么Bob也拿0，最后1个0由Alice拿，此时Bob拿第一个1给自己异或
                             * 然后Alice也拿1给自己异或，然后Bob拿1给Alice异或，Alice拿1给自己异或... 
                             * 最终，Bob拿最后一个1给Alice异或，此时Alice为0，Bob为1 
                             * 
                             * 因此这种情况，Bob必赢
                            */
                            cout << -1 << endl;
                        }
                        // 如果数列大小n是奇数，那么由于该bit位1是奇数，故0是偶数
                        else
                        {
                            /* 
                             * 偶数个0不会对结果造成影响
                             * 因此Alice先拿1给自己，Bob也拿1给自己，Alice再拿1给Bob，Bob拿1给自己...
                             * 最终，Alice把最后一个1给Bob使其为0，而自己依然是1
                             * 因此，这种情况Alice必赢 
                            */
                            cout << 1 << endl;
                        }
                        break;
                    }
                }    
            } 
        }
    }
    system("pause");
    return 0;    
}