/**
Représente un point du plan
*/

class Vecteur2D
{
public:
    double _x, _y;
    
    Vecteur2D(const double& x = 0, const double& y = 0) : x(_x), y(_y) {};
    Vecteur2D operator+(const Vecteur2D& v) const
    {
        return Vecteur2D(_x + v._x, _y + v._y)
    };
    Vecteur2D operator-() const
    {
        return Vecteur2D(-_x, -_y);
    };
    Vecteur2D operator*(const double a) const {return Vecteur2D(_x * a, _y * a)};
    
    operator string() const
    {
        ostringstream os;
        os << "(" << _x << "," << _y << ")";
        return os.str();
    }
    
}
inline Vecteur2D operator*(const double a, const Vecteur2D& v) {return v * a;}

/*
Si:
template<class T>

const T operator-(const T &v1, const T &v2)
{
    return v1 + -v2;
}

Si type Vecteur3D on peut utiliser le template
*/