#include <iostream>
#include <cmath>

using namespace std;

class Vector{
    public:
        double x, y, z;
        Vector() {}
        Vector(int x, int y, int z) : x(x), y(y), z(z) {}
        
        double Product(Vector v){
            double res = 0;
            res += (this->x * v.x);
            res += (this->y * v.y);
            res += (this->z * v.z);
            
            return res;
        }
        
        Vector operator+ (Vector& v){
            Vector res;
            res.x = this->x + v.x;
            res.y = this->y + v.y;
            res.z = this->z + v.z;
            
            return res;
        }
        
        Vector operator- (Vector& v){
            Vector res;
            res.x = this->x - v.x;
            res.y = this->y - v.y;
            res.z = this->z - v.z;
            
            return res;
        }
        
        double dist(Vector v){
            double a = this->x - v.x;
            double b = this->y - v.y;
            double c = this->z - v.z;
            double res = sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2));
            
            return res;
        }
};

Vector multi(double l, Vector v){
    Vector res;
    res.x = l * v.x;
    res.y = l * v.y;
    res.z = l * v.z;
    return res;
}

void solve(){

    int x, y, z;
    Vector List[4];
    for(int i = 0; i < 4; i++){
        cin >> x >> y >> z;
        List[i] = Vector(x, y, z);
    }
    Vector u = List[1] - List[0];
    Vector v = List[3] - List[2];
    Vector w = List[0] - List[2];
    
    double a = u.Product(u), b = u.Product(v), c = v.Product(v), d = u.Product(w), e = v.Product(w);
    
    double check = a*c - b*b;
    double sc, st, sBottom = check;
    double tc, tt, tBottom = check;

    if (check <= 0.0001){
        st = 0;
        sBottom = 1;
        tt = e;
        tBottom = c;
    }
    else{
        st = (b * e - c * d);
        tt = (a * e - b * d);
        if (st < 0){
            st = 0;
            tt = e;
            tBottom = c;
        }
        else if (st > sBottom){
            st = sBottom;
            tt = e + b;
            tBottom = c;
        }
    }
    
    if (tt < 0){
        tt = 0;
        if (-d < 0) st = 0;
        else if (-d > a) st = sBottom;
        else{
            st = -d;
            sBottom = a;
        }
    }
    else if (tt > tBottom){
        tt = tBottom;
        if ((-d + b) < 0) st = 0;
        else if ((-d + b) > a) st = sBottom;
        else{
            st = (-d + b);
            sBottom = a;
        }
    }
    
    if (abs(st) <= 0.0001) sc = 0;
    else sc = st / sBottom;
    
    if (abs(tt) <= 0.0001) tc = 0;
    else tc = tt / tBottom;
    
    Vector sc1 = multi(sc, u);
    Vector tc1 = multi(tc, v);
    Vector dP = sc1 - tc1;
    dP = dP + w;
    double distance1 = sqrt(dP.Product(dP));
    cout << (int)ceil(distance1) << '\n';
    
}

int main(){
    solve();
}