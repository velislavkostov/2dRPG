#ifndef _SIZE_HPP_
#define _SIZE_HPP_

/** Size must always be positive unlike Point **/

using std::abs;

class Size{
    int _w; 
    int _h;
public:
    //Default 1x1 size
    Size() : _w{1}, _h{1}{}
    Size(int w, int h) : _w{abs(w)}, _h{abs(h)}{}
    int w(){return _w;}
    int h(){return _h;}

    Size& operator+=(const Size& s){_w += s._w; _h += s._h; return *this;}
    Size& operator-=(const Size& s){_w - s._w > 0 ? _w -= s._w : _w = 1; _h - s._h > 0 ? _h -= s._h : _h = 1; return *this;}
    Size& operator=(const Size& s){_w = s._w; _h = s._h; return *this;}
    Size operator+(const Size s){return (*this) += s;}
    Size operator-(const Size s){return (*this) -= s;}
    bool operator==(const Size s){return (_w == s._w && _h == s._h);}
    bool operator!=(const Size s){return !((*this) == s);}
    ~Size(){} 
};

#endif // _SIZE_HPP_
