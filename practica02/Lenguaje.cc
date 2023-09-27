// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 22/09/2023
// Archivo Lenguaje.cc:
// Contiene la implementación de la clase lenguaje.
// El constructor por defecto que se encargará de imprimir lenguaje vacío
// cuando no tenga ningún elemento. 
// La función Cardinal que devlverá el tamaño de dicho lenguaje y la sobrecarga de salida
// para imprimir por pantalla.
// Historial de revisiones:
// 22/09/23 - Creación (primera versión) del código. Creación de la función usage y clases
// 23/09/23 - Realización de la implementacion de los metodos de las
// clases, asi como las funciones de inversa y longitud. Implementacion
// del main para poder ir probando si funciona 
// 24/09/23 - Realización de las funciones Sufijo y prefijo de la clase cadena
// 25/09/23 - Correción de errores y finalización del main para correcto funcionamiento.
// Finalización de toda la correcta identacion y comentarios./*+

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