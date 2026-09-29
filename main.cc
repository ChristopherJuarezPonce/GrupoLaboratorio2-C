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
    EliminarFinal(&lista);
    Imprimir(lista);
    
    return 0;
}

//Funcion para indsertar datos

void InsertarInicio(Nodo **lista, Estudiantes estudiantes)
{
    struct Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->estudiante = estudiantes; 
    nuevo_nodo->siguiente = *lista;
    nuevo_nodo->anterior = nullptr;

    // Si la lista no está vacía, actualizamos el puntero anterior del primer nodo actual
    if (*lista != nullptr)
    {
        (*lista)->anterior = nuevo_nodo;
    }

    // El nuevo nodo pasa a ser la cabeza de la lista
    *lista = nuevo_nodo;
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