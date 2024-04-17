#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct Empleado {
    std::string nombre;
    std::string apellido;
    int edad;
    double salario;
};

std::vector<Empleado> leerEmpleados(const std::string& archivo) {
    std::vector<Empleado> empleados;
    std::ifstream file(archivo);
    std::string linea;

    if (file.is_open()) {
        while (std::getline(file, linea)) {
            std::istringstream ss(linea);
            Empleado emp;
            std::string campo;

            std::getline(ss, campo, ',');
            emp.nombre = campo;

            std::getline(ss, campo, ',');
            emp.apellido = campo;

            std::getline(ss, campo, ',');
            emp.edad = std::stoi(campo);

            std::getline(ss, campo, ',');
            emp.salario = std::stod(campo);

            empleados.push_back(emp);
        }
        file.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }

    return empleados;
}

void buscarEmpleado(const std::vector<Empleado>& empleados, const std::string& nombreCompleto) {
    std::string nombre, apellido;
    std::size_t pos = nombreCompleto.find(' ');

    if (pos != std::string::npos) {
        nombre = nombreCompleto.substr(0, pos);
        apellido = nombreCompleto.substr(pos + 1);
    }
    else {
        std::cout << "El nombre completo debe contener un espacio." << std::endl;
        return;
    }

    bool encontrado = false;
    for (const Empleado& emp : empleados) {
        if (emp.nombre == nombre && emp.apellido == apellido) {
            std::cout << "Nombre: " << emp.nombre << std::endl;
            std::cout << "Apellido: " << emp.apellido << std::endl;
            std::cout << "Edad: " << emp.edad << std::endl;
            std::cout << "Salario: " << emp.salario << std::endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        std::cout << "El empleado no se encuentra en el archivo." << std::endl;
    }
}

int main() {
    std::vector<Empleado> empleados = leerEmpleados("Empleado.txt");

    std::string nombreCompleto;
    while (true) {
        std::cout << "Ingrese el nombre completo del empleado (o escriba 'salir' para salir): ";
        std::getline(std::cin, nombreCompleto);

        if (nombreCompleto == "salir") {
            break;
        }

        buscarEmpleado(empleados, nombreCompleto);
    }

    return 0;
}