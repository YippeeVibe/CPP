// template<int M,int K,int S>
// struct MksUnit
// {
//     emum {metre = M,kilogram = K,second = S};
// };

// template<typename MksUnit>
// class value
// {
// private:
//     long double magnitude{0.0};
// public:
//     constexpr explicit value(const long double magnitude): magnitude(magnitude){}
//     constexpr long double getmagnitude() const{return magnitude;}
// };

// using Force = value<MksUnit<1,1,-2>>;

class z_time_during_constexptr
{

private:

  long double m_time_d;
  int time_type{1};

  constexpr explicit z_time_during_constexptr (const long double time_d,int type):m_time_d(time_d),time_type(type){}

  friend constexpr z_time_during_constexptr operator"" h(const long double time_d);
public:
  constexpr long double getTimeduringInSeconds(){return m_time_d*time_type;}



};

constexpr z_time_during_constexptr operator"" h(const long double time_d)
{
    return z_time_during_constexptr(time_d,3600);
}