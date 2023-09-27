// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 22/09/2023
// Archivo Alfabeto.h: 
// Contiene la clase Alfabeto. En esta clase encontramos los constructoress sin parametros y con parámetros
// El segundo constructor que se utiliza 
// para construir un objeto de la clase Alfabeto a partir de una instancia de la clase Cadena.
// El getter que obtiene el set de simbolos que componen el alfabeto
// Un método denominado cardinal que devuelve el tamaño del alfabeto
// y por último la sobrecarga del operador de insercción para poder imprimir el alfabeto
// Historial de revisiones:
// 22/09/23 - Creación (primera versión) del código. Creación de la función usage y clases
// 23/09/23 - Realización de la implementacion de los metodos de las
// clases, asi como las funciones de inversa y longitud. Implementacion
// del main para poder ir probando si funciona 
// 24/09/23 - Realización de las funciones Sufijo y prefijo de la clase cadena
// 25/09/23 - Correción de errores y finalización del main para correcto funcionamiento.
// Finalización de toda la correcta identacion y comentarios./*+

#ifndef ALFABETO_H
#define ALFABETO_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
#include <sstream>

#include "Simbolo.h"
#include "Cadena.h"

class Cadena; // Definición de la clase Cadena para su utilizacion

/**
 * @brief Clase Alfabeto 
 * Contiene el contructor por parámetros, otro constructor que se utiliza 
 * para construir un objeto de la clase Alfabeto a partir de una instancia de la clase Cadena.
 * un método que devuelve el tamaño del alfabeto  denominado cardinal
 * Un getter que devuelve el alfabeto actual
 * La sobrecarga del operador de salida
 */
class Alfabeto {
 public:
  Alfabeto(std::set<Simbolo> alfabeto) : alfabeto_{alfabeto} {}   
  Alfabeto(Cadena cadena);
  std::set<Simbolo> GetAlfabeto() const { return alfabeto_; }  
  int Cardinal() const { return alfabeto_.size(); }            
  friend std::ostream& operator<<(std::ostream& out, const Alfabeto& alfabeto);
 private:
  std::set<Simbolo> alfabeto_;
};

// Definición de la sobrecarga de salida
std::ostream& operator<<(std::ostream& out, const Alfabeto& alfabeto);

#endif //ALFABETO_H