// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Simulacion de Máquinas de Turing
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 14/11/2023
// Archivo Maquina_Turing.h:
// Contiene la clase Maquina_Turing. Esta clase representa una máquina de Turing.
// Historial de revisiones:

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>

#include "Simbolo.h"
#include "Cinta.h"
#include "Estado.h"

class MaquinaTuring {
 public:
  MaquinaTuring(std::string nombre_fichero_turing, std::string nombre_fichero_cinta);
  // metodo que sea la simulacion de la maquina de turing
  bool SimularMaquinaTuring();
  void EsAceptada();
  // metodo que diga si una cadena es aceptada o no
  bool EsCadenaAceptada();
  // metodo para buscar un estado en el conjunto de estados
  Estado BuscarEstado(std::string nombre_estado);
  // metodo que comprueba si dado estado y simbolo existe una transicion
  bool ExisteTransicion(Estado estado, Simbolo simbolo, Simbolo simbolo_escritura);
  // getter
  Cinta& GetCinta() { return cinta_; }
  std::map<std::pair<Estado, Simbolo>, std::map<Simbolo, std::pair<std::string, Estado>>> GetTransiciones() { return transiciones_; }
  // metodo para imprimir la cinta
  friend std::ostream& operator<<(std::ostream& os, MaquinaTuring& maquina_turing);
 private:
  // atributos privados
  int numero_estados_;
  int numero_transiciones_;
  Estado estado_inicial_;
  Cinta cinta_;
  std::set<Estado> estados_;
  std::set<Estado> estados_finales_;
  std::map<std::pair<Estado, Simbolo>, std::map<Simbolo, std::pair<std::string, Estado>>> transiciones_;
};