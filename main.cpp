#include <iostream>
using namespace std;
// Función regular
//int maximum(int a, int b) {
//    return a > b? a: b;
//}

template <class T>          // Template de clases -> Implementar un conjunto de clases
class point_t {
    T x = T();      // T() significa el valor por defecto que el caso de int() es igual a 0
    T y = T();
public:
    point_t(T x, T y): x(x), y(y) {}
    friend ostream& operator << (ostream& os, const point_t<T> p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    // Sobrecarga de operadores implementado como método
    bool operator>(const point_t<T> p2) {
        auto sc1 = this->x * this->x + this->y * this->y;
        auto sc2 = p2.x * p2.x + p2.y * p2.y;
        return sc1 > sc2;
    }
    T get_x() const { return x; }
    T get_y() const { return y; }


};

// Template de funciones - generico
template <typename T>       // Template de funciones -> Implementar una familia de funciones
T maximum(T a, T b) {
    return a > b? a: b;
}

// Template de funciones especializadas (a través de la sobrecarga de funciones)
point_t<double> maximum(point_t<int> a, point_t<double> b) {
    auto sc1 = a.get_x() * a.get_x() + a.get_y() * a.get_y();
    auto sc2 = b.get_x() * b.get_x() + b.get_y() * b.get_y();
    if (sc1 > sc2) {
//        point_t<double> pto(double(a.get_x()), double(a.get_y()));
//        return pto;       // Entero
        return point_t<double>{double(a.get_x()), double(a.get_y())};       // Entero
    }
    else
        return b;       // Double
}

// Template de funciones especializadas (a través de la sobrecarga de template)
template<typename T, typename V>
auto maximum(T a, V b) {
    return a > b ? a: b;
}

// Sobrecarga de operadores implementada como función
template <typename V, typename W>
bool operator>(const point_t<V> p1, const point_t<W> p2) {
    auto sc1 = p1.get_x() * p1.get_x() + p1.get_y() * p1.get_y();
    auto sc2 = p2.get_x() * p2.get_x() + p2.get_y() * p2.get_y();
    return sc1 > sc2;
}

int main() {
    cout << maximum(10, 2) << endl;             // Implementa una funcion maximum(int, int)
    cout << maximum(10.5, 10.7) << endl;        // Implementa una funcion maximum(double, double)
    cout << maximum(10.5f, 10.7f) << endl;      // Implementa una funcion maximum(float, float)

    point_t<int> p1(10, 20);                    // Implementa una clase point_t con atributos del tipo int
    point_t<int> p2(20, 43);                    // Implementa una clase point_t con atributos del tipo int
    point_t<double> p3(20, 43);                 // Implementa una clase point_t con atributos del tipo double
    cout << p1 << " " << p2 << endl;
    cout << p3 << endl;
    cout << maximum(p1, p2) << endl;            // Implementa una funcion maximum(point_t<int>, point_t<int>)
    cout << maximum(p1, p3) << endl;

    int x1  = 30000;       // 30000
    double y1 = 30000;     // 2 secciones mantisa y exponente   3E4 --> 3 * 10^4
    auto add_1  = reinterpret_cast<long long int>(&x1);
    cout << add_1;    return 0;
}
