#include<iostream>
#include<vector>
int main()
{
    std::vector<int> n(101,12);//实例化一个容量为101,每个指为12的vector容器

    int distance = 101/4; //25 接下来，把n分为四组，第一组所有数据设为1，。。。第四组所有数据设为4.

    
    for(int i = 1;i<=4;i++) { //这里的遍历完全以数目来考虑，一般情况下，更符合计算机思维的是 i = 0;i<4
        int j = (i-1)*distance;
        auto l_ = [&i,&j,distance,&n]()->bool{
            return (i+1)*distance>n.size()?(j<n.size()):(j<i*distance);
        };
        for(;l_();++j) { //j<i*distance 也可以表示为j<=i*distance -1,这样可能更符合“容量的计算”
            if(j==100) {
               int x =  i;
            }
            n[j] = i;
        }
    }
    std::vector<int> groupNumber(4,0);
    for (auto& X:n)
    {
        switch (X)
        {
        case 1:
            groupNumber[0] = groupNumber.at(0)+1;
            break;
        case 2:
            groupNumber[1] = groupNumber.at(1)+1;
            break;
        case 3:
            groupNumber[2] = groupNumber.at(2)+1;
            break;
        case 4:
             groupNumber[3] = groupNumber.at(3)+1;
            break;
        default:
            break;
        }
        /* code */
    }
    for(auto& Y:groupNumber) {
        std::cout<<Y<<std::endl;
    }
    

    return 0;
}