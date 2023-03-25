#include "duration.hpp"
#include <stdexcept>
#include <iomanip>
#include <sstream>

Duration::Duration(){
minute = 0;
hour= 0;
secs=0;
};



Duration::Duration(int s){
secs= s;
minute= 0;
hour = 0;
if(secs >= 60){
minute = secs/60;
secs = secs%60;
};
if(minute >=60){
hour = minute/60;
minute = minute%60;
};
}

Duration::Duration(int h, int m, int s){
if(m >= 60 || s >=60) throw std::out_of_range{"Minute ili sekunde van opsega!"};
hour=h;
minute=m;
secs=s;
};

Duration::Duration(const std::string& other){
  std::stringstream separate;
  separate << other;
  int hh,mm,ss;
  char ignore_;
separate >> hh >> ignore_ >> mm >> ignore_ >> ss;
set_h(hh).set_m(mm).set_s(ss);
};

Duration::Duration(const Duration& other) : secs{other.secs}, minute{other.minute}, hour{other.hour} {
  
};
Duration::Duration(Duration&& other)  : secs{other.secs}, minute{other.minute}, hour{other.hour} {

};
Duration& Duration::operator=(const Duration& other){
  secs=other.secs;
  minute=other.minute;
  hour= other.hour;
return *this;
};
Duration& Duration::operator=(Duration&& other){
 secs=other.secs;
  minute=other.minute;
  hour= other.hour;
return *this;
};

const int& Duration::get_h() const {
return hour;
}

const int& Duration::get_m() const {
return minute;
}

const int& Duration::get_s() const {
return secs;
}

Duration& Duration::set_s(const int& s) {
if(s >= 60 || s < 0) throw std::out_of_range{"Nevazeca vrijednost"};
secs = s;
return *this;
};
Duration& Duration::set_m(const int& m) {
if(m >= 60 || m < 0) throw std::out_of_range{"Nevazeca vrijednost"};
minute = m;
return *this;
};
Duration& Duration::set_h(const int& h) {
if(h < 0)  throw std::out_of_range{"Nevazeca vrijednost"};
hour = h;
return*this;
};

bool Duration::operator==(const Duration& other){
return secs == other.secs && minute == other.minute && hour == other.hour;
};
bool Duration::operator!=(const Duration& other){
return secs != other.secs || minute != other.minute || hour != other.hour;
};
bool Duration::operator>(const Duration& other){
if(hour > other.hour){
  return true;
}else if(hour == other.hour){
  if(minute > other.minute){
  return true;
  }else if(minute == other.minute){
  if(secs > other.secs){
  return true;
  }else return false;
  }else return false;
}else return false;
};
bool Duration::operator<(const Duration& other){
if(hour < other.hour){
  return true;
}else if(hour == other.hour){
  if(minute < other.minute){
  return true;
  }else if(minute == other.minute){
  if(secs < other.secs){
  return true;
  }else return false;
  }else return false;
}else return false;
};
bool Duration::operator>=(const Duration& other){
if(hour > other.hour){
  return true;
}else if(hour == other.hour){
  if(minute > other.minute){
  return true;
  }else if(minute == other.minute){
  if(secs >= other.secs){
  return true;
  }else return false;
  }else return false;
}else return false;

};
bool Duration::operator<=(const Duration& other){
if(hour < other.hour){
  return true;
}else if(hour == other.hour){
  if(minute < other.minute){
  return true;
  }else if(minute == other.minute){
  if(secs <= other.secs){
  return true;
  }else return false;
  }else return false;
}else return false;
};

Duration::operator bool() const{
return secs !=0 || minute !=0 || hour!=0;
};
bool Duration::operator!() const{
if(secs !=0 || minute !=0 || hour!=0) return false;
else return true;
}

Duration& Duration::operator+=(const Duration& other){
secs += other.secs;
minute += other.minute;
hour+= other.hour;
if(secs >= 60){
minute += secs/60;
secs = secs%60;
};
if(minute >=60){
hour += minute/60;
minute = minute%60;
};
return *this;
}

Duration& Duration::operator+(Duration& other){
other.secs += secs;
other.minute += minute;
other.hour += hour;
if(other.secs >= 60){
other.minute += other.secs/60;
other.secs = other.secs%60;
};
if(other.minute >=60){
other.hour += other.minute/60;
other.minute = other.minute%60;
};
return other;
}

Duration& Duration::operator-=(const Duration& other){
if(secs < other.secs){
if(minute > 0) {
  minute--; }else {
  hour--;
  minute += 59;
  };
secs= secs + 60 - other.secs;
}else secs-=other.secs;
if(minute < other.minute){
hour--;
minute = minute + 60 - other.minute;
}else minute-= other.minute;
hour-= other.hour;
if (hour < 0 || minute < 0 || secs < 0) throw std::out_of_range{"Umanjilac veci!"};
return *this;
}

Duration& Duration::operator-(Duration& other){
if(secs < other.secs){
if(minute > 0) {
  minute--; }else {
  hour--;
  minute += 59;
  };
secs= secs + 60 - other.secs;
}else secs-=other.secs;
if(minute < other.minute){
hour--;
minute = minute + 60 - other.minute;
}else minute-= other.minute;
hour-= other.hour;
if (hour < 0 || minute < 0 || secs < 0) throw std::out_of_range{"Umanjilac veci!"};
return *this;

}

Duration& Duration::operator*(const int& other){
secs*=other;
minute*=other;
hour*=other;
if(secs >= 60){
minute += secs/60;
secs = secs%60;
};
if(minute >=60){
hour += minute/60;
minute = minute%60;
};
return *this;
};

Duration& Duration::operator*=(const int& other){
secs*=other;
minute*=other;
hour*=other;
if(secs >= 60){
minute += secs/60;
secs = secs%60;
};
if(minute >=60){
hour += minute/60;
minute = minute%60;
};
return *this;
};
Duration& Duration::operator/(const int& other){
if(hour%other == 0){
hour/=other;
}else{
minute+= hour*60;
hour=0;
};
if(minute%other ==0){
minute/=other;
}else{
secs+= minute*60;
minute=0;
}
secs/=other;
if(secs >= 60){
minute += secs/60;
secs = secs%60;
};
if(minute >=60){
hour += minute/60;
minute = minute%60;
};
return *this;
}; 
Duration& Duration::operator/=(const int&other){
if(hour%other == 0){
hour/=other;
}else{
minute+= hour*60;
hour=0;
};
if(minute%other ==0){
minute/=other;
}else{
secs+= minute*60;
minute=0;
}
secs/=other;
if(secs >= 60){
minute += secs/60;
secs = secs%60;
};
if(minute >=60){
hour += minute/60;
minute = minute%60;
};
return *this;
};

std::ostream& operator<<(std::ostream& out, const Duration& other){
out << std::setw(2) << std::setfill('0') << other.hour << ":" 
<< std::setw(2) << std::setfill('0') << other.minute << ":" 
<< std::setw(2) << std::setfill('0') << other.secs;
return out;
};

std::istream& operator>>(std::istream& change, Duration& other){
int hh,mm,ss;
char ignore_;
change >> hh >> ignore_ >> mm >> ignore_ >> ss;
other.set_h(hh).set_m(mm).set_s(ss);
return change;
};


