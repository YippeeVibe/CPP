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

<<<<<<< HEAD:Code/Type_Rich/z_time_during_constexpr.h
  friend constexpr z_time_during_constexptr operator"" h(const long double time_d);
=======
  friend constexpr z_time_during_constexptr operator"" _h(const long double time_d);
>>>>>>> bbaf710fc0ddeb3bab11f45fc7b894e3e2e3ac7a:Code/typerich/z_time_during_constexpr.h
public:
  constexpr long double getTimeduringInSeconds(){return m_time_d*time_type;}



};

<<<<<<< HEAD:Code/Type_Rich/z_time_during_constexpr.h
constexpr z_time_during_constexptr operator"" h(const long double time_d)
=======
constexpr z_time_during_constexptr operator"" _h(const long double time_d)
>>>>>>> bbaf710fc0ddeb3bab11f45fc7b894e3e2e3ac7a:Code/typerich/z_time_during_constexpr.h
{
    return z_time_during_constexptr(time_d,3600);
}