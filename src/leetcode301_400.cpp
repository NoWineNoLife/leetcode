#include "leetcode301_400.h"

// 343
int algorithm_leetcode::Solution_301_400::integerBreak(int n)
{
    int int_result = 0;
    int* memory = new int[n];

    int i = 0;
    for(; i < n; ++i)
    {
        memory[i] = 0;
    }


    for(i = 1; i < n; ++i)
    {
        if( 0 == memory[i])
        {
            getNth(memory, i);
        }
        if( 0 == memory[ n - i])
        {
            getNth(memory, n - i);
        }

        if( int_result < memory[i] * memory[ n - i])
        {
            int_result = memory[i] * memory[ n - i];
        }
    }
    return int_result;
}


// 343_assist
void algorithm_leetcode::Solution_301_400::getNth(int* ary, int no)
{
    if( 0 == no)
    {
        return;
    }

    if( 0 != ary[no])
        return ;


    if( 1 == no)
    {
        ary[no] = 1;
        return ;
    }


    int i = 1;
    int int_result = 1;
    for(; i < no; ++i)
    {
        if( 0 == ary[i])
        {
            getNth(ary, i);
        }
        if( 0 == ary[ no - i])
        {
            getNth(ary, no - i);
        }

        if( int_result < ary[i] * ary[ no - i])
        {
            int_result = ary[i] * ary[ no - i];
        }

    }
    if( int_result < no)
    {
        int_result = no;
    }
    ary[no] = int_result;
}
