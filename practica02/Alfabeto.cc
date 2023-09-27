// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 22/09/2023
// Archivo Alfabeto.cc: 
// Contiene la implementación de los métodos públicos de la clase alfabeto. 
// El constructor que a partir de cadenas saca el alfabeto
// Y la función de sobrecarga de << para imprimir el alfabeto.
// Historial de revisiones:
// 22/09/23 - Creación (primera versión) del código. Creación de la función usage y clases
// 23/09/23 - Realización de la implementacion de los metodos de las
// clases, asi como las funciones de inversa y longitud. Implementacion
// del main para poder ir probando si funciona 
// 24/09/23 - Realización de las funciones Sufijo y prefijo de la clase cadena
// 25/09/23 - Correción de errores y finalización del main para correcto funcionamiento.
// Finalización de toda la correcta identacion y comentarios./*+

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