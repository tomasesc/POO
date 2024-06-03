#include <iostream>
#include <string>

using namespace std;

class comida {
public:
    string Comida;
    string condimento;
    int tiempo;

    // Constructor
    comida(string _Comida, std::string _condimento, int _tiempo)
        : Comida(_Comida), condimento(_condimento), tiempo(_tiempo) {}
};

int main() {

    comida comida1("Milanesa.", "Ajo y perejil.", 20);
    comida comida2("Tarta de choclo.", "Sal y pimienta.", 40);

    cout<<"Comida 1:"<<endl;
    cout << "Comida: " << comida1.Comida << endl;
    cout << "Condimento: " << comida1.condimento << endl;
    cout << "Tiempo de coccion: " << comida1.tiempo <<" minutos." << endl;

    cout<<"-------------------------------"<<endl;

    cout<<"Comida 2:"<<endl;
    cout << "Comida: " << comida2.Comida << endl;
    cout << "Condimento: " << comida2.condimento << endl;
    cout << "Tiempo de coccion: " << comida2.tiempo <<" minutos."<< endl;

    return 0;
}
