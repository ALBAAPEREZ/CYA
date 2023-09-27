// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 22/09/2023
// Archivo Lenguaje.h: 
// Contiene la clase Lenguaje. 
// Tenemos el constructor por defecto que usaremos cuando el lenguaje sea vacío
// El constructor por parámetros que devolverá el lenguaje. El getter y un mñetodo
// denominado Cardinal que nos dará su tamaño
// Por último la función de sobrecarga de salida.
// Historial de revisiones:
// 22/09/23 - Creación (primera versión) del código. Creación de la función usage y clases
// 23/09/23 - Realización de la implementacion de los metodos de las
// clases, asi como las funciones de inversa y longitud. Implementacion
// del main para poder ir probando si funciona 
// 24/09/23 - Realización de las funciones Sufijo y prefijo de la clase cadena
// 25/09/23 - Correción de errores y finalización del main para correcto funcionamiento.
// Finalización de toda la correcta identacion y comentarios./*+

#ifndef LENGUAJE_H
#define LENGUAJE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
#include <sstream>

#include "Simbolo.h"
#include "Cadena.h"

class Cadena; // Definición de la clase Cadena

/**
 * @brief Clase Leguaje.
 * Esta clase contiene tanto el constructor por defecto como el que contiene parámetros
 * Encontramos un getter que se encarga de devolver los valores de set de cadenas
 * Un método denominado cardinal que devuelve el tamaño del lenguaje y por último,
 * una función de sobrecarga para imprimir el lenguaje
 */
class Lenguaje {
 public:
  Lenguaje();
  Lenguaje(std::set<Cadena> lenguaje) : lenguaje_{lenguaje} {}
  std::set<Cadena> GetLenguaje() const { return lenguaje_; }
  int Cardinal() const;   
  friend std::ostream& operator<<(std::ostream& out, const Lenguaje& lenguaje);
 private:
  std::set<Cadena> lenguaje_;
};

// Defincion de la sobrecarga de operadores
std::ostream& operator<<(std::ostream& out, const Lenguaje& lenguaje);

#endif // LENGUAJE_H