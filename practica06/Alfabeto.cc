// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Algoritmo de construccion de subconjuntos
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 14/10/2023
// Archivo Alfabeto.cc
// Contiene la implementación de los métodos de la clase Alfabeto.
// El constructor que se utiliza para construir un objeto de la clase Alfabeto a partir de una instancia de la clase Cadena.
// El método Cardinal que devuelve el tamaño del alfabeto.
// El método GetAlfabeto que devuelve el alfabeto actual.
// La sobrecarga del operador de salida.
// Historial de revisiones:
//  13/10/2023 --> comienzo de la práctica. Creación (primera versión) del código.
//  Creación de la clase Estado .h y su implementación en el .cc
//  14/10/2023 --> Creación de la clase Autómata y su desarrollo en el .cc
//  15/10/2023 --> Desarrollo del código de la clase Autómata. Método EsAceptado y método ImprimirCadena.
//  16/10/2023 --> Corrección del código y finalización de la práctica.

#include "Alfabeto.h"
#include "Cadena.h"

/**
 * @brief Construct a new Alfabeto:: Alfabeto object
 * crea un objeto Alfabeto a partir de una instancia de la clase Cadena`.
 * @param cadena La Cadena de la cual se extraerá el alfabeto.
 */
Alfabeto::Alfabeto(Cadena cadena) {
  std::set<Simbolo> alfabeto; 
  // btener la secuencia de símbolos contenidos en esa cadena
  std::vector<Simbolo> cadena_auxiliar = cadena.GetCadena();
  for (size_t i{0}; i < cadena.GetSize(); ++i) { // recorre la cadena
    alfabeto.insert(cadena_auxiliar[i]); // inserta el elemento en el alfabeto
  } 
  alfabeto_ = alfabeto;
}

/**
 * @brief Sobrecarga del operador de inserción (<<) para la clase Alfabeto.
 * @param os Flujo de salida en el cual se escribirá el alfabeto.
 * @param alfabeto El objeto Alfabeto que se escribirá en el flujo de salida.
 * @return std::ostream& Una referencia al flujo de salida para permitir operaciones en cadena. 
 */
std::ostream& operator<<(std::ostream& os, const Alfabeto& alfabeto) {
  os << "{ ";
  int contador{1}; // posicion actual
  // ecorre cada símbolo en el alfabeto almacenado en el objeto alfabeto.
  for (const Simbolo& simbolo : alfabeto.alfabeto_) {
    os << simbolo;
    if (contador != alfabeto.Cardinal()) { // si no es el último simbolo
      os << ", ";
    }
    contador++; 
  }
  os << "}";
  return os;
}