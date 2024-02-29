#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main() {
    vector<string> nombres;
    vector<string> municipios;
    vector<int> diasNacimiento;
    vector<int> mesesNacimiento;
    vector<int> anosNacimiento;
    vector<bool> esMayorDeEdad;

    int n;

    cout << "REGISTRO DE DATOS " << endl;
    cout << "Ingrese el numero de personas a registrar ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string nombre, municipio;
        int dia, mes, ano;

        cout << "\n Nombre: " << ": ";
        cin.ignore();
        getline(cin, nombre);
        nombres.push_back(nombre);

        cout << "\n Municipio " << ": ";
        getline(cin, municipio);
        municipios.push_back(municipio);

        cout << "\n Fecha de Nacimiento " << " (dia mes ano): ";
        cin >> dia >> mes >> ano;

        diasNacimiento.push_back(dia);
        mesesNacimiento.push_back(mes);
        anosNacimiento.push_back(ano);

        time_t t = time(0);
        tm *ltm = localtime(&t);
        int edadActual = ltm->tm_year + 1900 - ano;
        bool mayorDeEdad = (edadActual > 18 || (edadActual == 18 && ltm->tm_mon > mes - 1) || (edadActual == 18 && ltm->tm_mon == mes - 1 && ltm->tm_mday >= dia));
        esMayorDeEdad.push_back(mayorDeEdad);
    }

    cout << "\n Datos de los ciudadanos:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\n Nombre: " << nombres[i] << endl;
        cout << "\n municipio: "<<municipios[i]<< endl;
        cout << "\n Fecha de nacimiento: " << diasNacimiento[i] << "/" << mesesNacimiento[i] << "/" << anosNacimiento[i] << endl;
        if (esMayorDeEdad[i]) {
            cout<< " "<<nombres[i]<<" es mayor de edad." << endl;
        } else {
            cout<< " "<<nombres[i]<<" no es mayor de edad." << endl;
        }
        cout << endl;
    }

    return 0;
}
