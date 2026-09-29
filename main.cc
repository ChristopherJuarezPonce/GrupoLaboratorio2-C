#include <iostream>
#include <string>

// Crear la estrutura de estudiantes
struct Estudiantes {
    int carnet_estudiante;
    std::string nombre_estudiante;
    std::string carrera_estudiante;
};

// Estructura de nodo
struct Nodo {
    Estudiantes estudiante;
    Nodo* siguiente;
    Nodo* anterior;
};

//Declaraciones de variables doble puntero (**)

void InsertarInicio(Nodo **lista, Estudiantes estudiantes);


int main(){

    Nodo *lista = nullptr;
    Estudiantes estudiante1, estudiante2;

    estudiante1.nombre_estudiante = "Mercedes Granados";
    estudiante1.carnet_estudiante = 0020125626;
    estudiante1.carrera_estudiante = "Informatica";

    estudiante2.nombre_estudiante = "Gerson Segovia";
    estudiante2.carnet_estudiante = 78712212;
    estudiante1.carrera_estudiante = "Contabilidad";


    InsertarInicio(&lista, estudiante1);
    InsertarInicio(&lista, estudiante2);
    
    return 0;
}