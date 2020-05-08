
//时间长度的一个类
enum time_type{Seconds,Minutes,Hours};


class z_time_during
{
private:
    /* data */
   
    explicit z_time_during(const long double time_d,time_type type)
    :m_type(type),
     m_time_d(time_d)
     {}
    friend z_time_during operator"" s(const long double);
    friend z_time_during operator"" m(const long double);
    friend z_time_during operator"" h(const long double time_d);
    time_type m_type;
   long double m_time_d;
public:

    long double GetTimeDuringForSeconds()
    {
        switch (m_type)
        {
        case Seconds:
            return m_time_d;
        case Minutes:
            return m_time_d*60;
        case Hours:
            return m_time_d*3600;
    
        }
        return 0;

    }
};
 z_time_during operator"" s(const long double time_d)
{
    return z_time_during(time_d,Seconds);
}
z_time_during operator"" m(const long double time_d)
{
    return z_time_during(time_d,Minutes);
}
z_time_during operator"" h(const long double time_d)
{
    return z_time_during(time_d,Hours);
}


