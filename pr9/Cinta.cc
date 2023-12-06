// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Simulacion de Máquinas de Turing
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 14/11/2023
// Archivo Cinta.h:
// Contiene la clase Cinta. Esta clase representa una cinta de una máquina de Turing.
// Historial de revisiones:

#include "Cinta.h"

/**
 * @brief Construct a new Cinta:: Cinta object
 * Constructor por defecto 
 */
Cinta::Cinta() {
  // a la lista vamos a meterle simbolos blancos
  Simbolo blanco("$");
  cinta_.push_back(blanco);
  cinta_.push_front(blanco);
  posicion_cabeza_ = cinta_.begin();
}

/**
 * @brief Construct a new Cinta:: Cinta object
 * Constructor por parámetros, recibe un string con el nombre del fichero
 * @param nombre_fichero nombre del fichero
 */
Cinta::Cinta(std::string nombre_fichero) {
  // iniciar cinta
  IniciarCinta(nombre_fichero);
}

/**
 * @brief Método para iniciar la cinta
 * @param nombre_fichero nombre del fichero
 */
void Cinta::IniciarCinta(std::string nombre_fichero) {
  // limpiamos la cinta
  cinta_.clear();
  // leer fichero
  std::ifstream fichero(nombre_fichero, std::ios::in);
  std::string cadena;
  getline(fichero, cadena);
  // recorremos caadena
  for (size_t i = 0; i < cadena.length(); i++) {
    Simbolo simbolo(cadena.substr(i, 1));
    cinta_.push_back(simbolo);
    alfabeto_cinta_.InsertarSimbolo(simbolo);
  }
  posicion_cabeza_ = cinta_.begin();
  // añadir simbolo blanco
  Simbolo blanco("$");
  cinta_.push_back(blanco);
  cinta_.push_front(blanco);
  // cerrar fichero
  fichero.close();
}

/**
 * @brief Método para imprimir la cinta
 * Recorre la cinta y va imprimiendo los simbolos
 * @param estado_actual estado actual de la maquina de turing que va recorriendo
 */
void Cinta::ImprimirCinta(Estado estado_actual) {
  // for para recorrer la cinta
  for (auto it = cinta_.begin(); it != cinta_.end(); ++it) {
    if (it == posicion_cabeza_) {
      std::cout << " q" << estado_actual.GetIdentificador() << " ";
    }
    std::cout << *it;
  }
  std::cout << std::endl;
}

/**
 * @brief Método para escribir en la cinta
 * Este método escribe en la cinta el simbolo que recibe por parámetros
 * @param simbolo simbolo a escribir en la cinta
 */
void Cinta::EscribirCinta(Simbolo simbolo) {
  *posicion_cabeza_ = simbolo;
}

/**
 * @brief  Método para mover la cabeza de la cinta
 * Este método mueve la cabeza de la cinta a la derecha o a la izquierda
 * @param movimiento moviemiento a realizar
 */
void Cinta::MoverCabeza(std::string movimiento) {
  if (movimiento == "R") {
    posicion_cabeza_++;
  } else if (movimiento == "L") {
    posicion_cabeza_--;
  }
}

/**
 * @brief Sobrecarga del operador de salida
 * Imprime la cinta
 * @param os flujo de salida
 * @param cinta cinta a imprimir
 * @return std::ostream& flujo de salida
 */
std::ostream& operator<<(std::ostream& os, Cinta& cinta) {
  // for para recorrer la cinta
  for (auto it = cinta.cinta_.begin(); it != cinta.cinta_.end(); ++it) {
    os << " | " << *it;
  }
  return os;
}