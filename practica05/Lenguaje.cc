// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Simulación de autómatas finitos
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 14/10/2023
// Archivo Lenguaje.cc:
// Contiene la implementación de los métodos de la clase Lenguaje.
// El constructor por defecto.
// El método Cardinal que devuelve el cardinal del lenguaje.
// El método GetLenguaje que devuelve el lenguaje.
// El método operator<< que sobrecarga el operador de salida.
// Historial de revisiones:
//  13/10/2023 --> comienzo de la práctica. Creación (primera versión) del código.
//  Creación de la clase Estado .h y su implementación en el .cc
//  14/10/2023 --> Creación de la clase Autómata y su desarrollo en el .cc
//  15/10/2023 --> Desarrollo del código de la clase Autómata. Método EsAceptado y método ImprimirCadena.
//  16/10/2023 --> Corrección del código y finalización de la práctica.

#include "Lenguaje.h"

/**
 * @brief Construct a new Lenguaje:: Lenguaje object
 * Este constructor crea un objeto Lenguaje vacío con un 
 * conjunto que contiene una cadena vacía "{}".
 */
Lenguaje::Lenguaje() {
  Simbolo simbolo("{}");
  std::vector<Simbolo> cadena_auxiliar{simbolo};
  Cadena cadena{cadena_auxiliar}; // crea una cadena con la cadnena que contiene los simbolos
  lenguaje_.insert(cadena);
}

/**
 * @brief Calcula y devuelve el cardinal del lenguaje.
 * Esta función calcula y devuelve el cardinal del lenguaje, es decir, la cantidad de cadenas
 * distintas que contiene el lenguaje.
 * @return int El cardinal del lenguaje.
 */
int Lenguaje::Cardinal() const {
  Simbolo simbolo("{}");
  std::vector<Simbolo> cadena_auxiliar{simbolo};
  Cadena cadena{cadena_auxiliar};
  // Busca la cadena cadena en el conjunto lenguaje_
  std::set<Cadena>::iterator it = lenguaje_.find(cadena);
  // si solo contiene la cadena vacía y no apunta al final del conjunto
  if (lenguaje_.size() == 1 && it != lenguaje_.end()) {
    return 0; // solo cadena vacia --> tamaño 0
  }
  return lenguaje_.size();
}

/**
 * @brief Sobrecarga del operador de salida (<<) para la clase Lenguaje.
 * Esta función sobrecargada permite escribir un objeto Lenguaje en un flujo de salida (ostream).
 * Se utiliza para imprimir el contenido del lenguaje en el formato "{cadena1, cadena2, ...}".
 * @param os El flujo de salida en el cual se escribirá el lenguaje.
 * @param lenguaje El objeto Lenguaje que se escribirá en el flujo de salida.
 * @return std::ostream& Una referencia al flujo de salida para permitir operaciones en cadena.
 */
std::ostream& operator<<(std::ostream& os, const Lenguaje& lenguaje) {
  if (lenguaje.Cardinal() == 0) { // si lenguaje vacio
    os << "{}";
  } else {
    os << "{";
    size_t contador{1};
    for (auto cadena : lenguaje.GetLenguaje()) {
      os << cadena;
      if (contador != lenguaje.Cardinal()) { // mas cadenas que imprimir
        os << ", ";
      }
      ++contador;
    }
    os << "}";
  }
  return os;
}