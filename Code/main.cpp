#include<iostream>
#include<vector>
int main()
{
    std::vector<int> n(101,12);//ʵ����һ������Ϊ101,ÿ��ָΪ12��vector����

    int distance = 101/4; //25 ����������n��Ϊ���飬��һ������������Ϊ1������������������������Ϊ4.

    
    for(int i = 1;i<=4;i++) { //����ı�����ȫ����Ŀ�����ǣ�һ������£������ϼ����˼ά���� i = 0;i<4
        int j = (i-1)*distance;
        auto l_ = [&i,&j,distance,&n]()->bool{
            return (i+1)*distance>n.size()?(j<n.size()):(j<i*distance);
        };
        for(;l_();++j) { //j<i*distance Ҳ���Ա�ʾΪj<=i*distance -1,�������ܸ����ϡ������ļ��㡱
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