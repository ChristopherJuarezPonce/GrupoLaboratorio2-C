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
void EliminarFinal(Nodo **lista);
void Imprimir(Nodo *lista);

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

// Función para eliminar el último nodo de la lista
void EliminarFinal(Nodo **lista)
{
    if (*lista == nullptr)
    {
        std::cout << "Lista vacia\n";
        return;
    }

    // Si solo hay un elemento
    if ((*lista)->siguiente == nullptr)
    {
        delete *lista;
        *lista = nullptr;
        return;
    }

    struct Nodo *temporal = *lista;
    while (temporal->siguiente != nullptr)
    {
        temporal = temporal->siguiente;
    }

    // Desconectamos el último nodo y lo borramos
    temporal->anterior->siguiente = nullptr;
    delete temporal;
}

// Función para imprimir la lista
void Imprimir(Nodo *lista)
{
    std::cout<<"\nImprimiendo lista ......\n";
     
    if (lista == nullptr)
    {
        std::cout << "Lista vacia\n";
        return;
    }

    struct Nodo *temporal = lista;
    while (temporal != nullptr)
    {
        std::cout << "Nombre Estudiante: " << temporal->estudiante.nombre_estudiante
                  << " - numero de carnet: " << temporal->estudiante.carnet_estudiante
                  << " - carrera: " << temporal->estudiante.carrera_estudiante
                  << " | Dir: " << temporal
                  << " | Sig: " << temporal->siguiente
                  << " | Ant: " << temporal->anterior << "\n";
        temporal = temporal->siguiente;
    }
}