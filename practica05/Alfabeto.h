// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Simulación de autómatas finitos
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 14/10/2023
// Archivo Alfabeto.h
// Contiene la clase Alfabeto, que representa un alfabeto.
// Consta de dos constructores, uno por parámetros y otro por defecto.
// De un atributo privado y su respectivo getter.
// El alfabeto será de tipo set y almacenará los símbolos del alfabeto.
// Historial de revisiones:
//  13/10/2023 --> comienzo de la práctica. Creación (primera versión) del código.
//  Creación de la clase Estado .h y su implementación en el .cc
//  14/10/2023 --> Creación de la clase Autómata y su desarrollo en el .cc
//  15/10/2023 --> Desarrollo del código de la clase Autómata. Método EsAceptado y método ImprimirCadena.
//  16/10/2023 --> Corrección del código y finalización de la práctica.

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
#include "Alfabeto.h"

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