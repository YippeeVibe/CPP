#include<iostream>
#include"Code/typerich/z_time_during_constexpr.h"
#define _DEBUG
using namespace std;
int main()
{
    z_time_during_constexptr z12{12.0_h};
#ifdef _DEBUG
    cout<<"Hello,world!"<<endl;
#elif _RELEASE

#else
cout<<z12.getTimeduringInSeconds();
#endif
    
    return 0;
}