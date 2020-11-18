#include<iostream>
#include"Code/typerich/z_time_during_constexpr.h"
using namespace std;
int main()
{
    z_time_during_constexptr z12{12.0_h};
    cout<<z12.getTimeduringInSeconds();
    return 0;
}