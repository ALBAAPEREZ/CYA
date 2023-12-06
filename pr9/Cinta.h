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

#pragma once

#include <iostream>
#include <list>
#include <fstream>
#include "Alfabeto.h"
#include "Simbolo.h"
#include "Estado.h"

class Cinta {
 public:
  // Constructores
  Cinta();
  Cinta(std::string nombre_fichero);
  // Getters
  Alfabeto get_alfabeto_cinta() const { return alfabeto_cinta_; };
  std::list<Simbolo> get_cinta() const { return cinta_; };
  std::list<Simbolo>::iterator get_posicion_cabeza() const { return posicion_cabeza_; };
  // Método para obtener el símbolo que apunta la cabeza
  Simbolo ObtenerSimboloCabeza() { return *posicion_cabeza_; }
  // metodo para mover la cabeza de la cinta
  void MoverCabeza(std::string movimiento);
  // metodo para escribir en la cinta
  void EscribirCinta(Simbolo simbolo);
  // metodo para imprimir la cinta
  void ImprimirCinta(Estado estado_actual);
  // metodo para iniciar la cinta
  void IniciarCinta(std::string cadena);
  // sobrecarga de operador de entrada
  friend std::ostream& operator<<(std::ostream& os, Cinta& cinta);
 private:
  // atributis privados
  Alfabeto alfabeto_cinta_;
  std::list<Simbolo> cinta_;
  std::list<Simbolo>::iterator posicion_cabeza_;
};