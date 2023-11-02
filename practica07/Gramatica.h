// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Algoritmo de construccion de subconjuntos
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 22/10/2023
// Archivo Cliente.cc:
// Contiene la función principal main donde se abren los ficheros de entrada del programa
// La función Usage que muestra el funcionamiento del programa si no se realiza de forma correcta
// Se abren dos archivos pasados como argumentos en la línea de comandos, uno conteniendo la definición de un autómata finito y el otro conteniendo cadenas a simular.
// Luego, 
// Historial de revisiones:
// 22/10/2023 --> comienzo de la práctica. Creación (primera versión) del código.

#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>
#include <string>

#include "Alfabeto.h"
#include "Simbolo.h"

class Gramatica {
 public:
  Gramatica();
  Gramatica(std::string nombre_archivo);
  // constructor de copia
  Gramatica(const Gramatica& gramatica);
  // Getters
  Alfabeto GetAlfabetoGramatica() const { return alfabeto_gramatica_; }
  std::set<Simbolo> GetSimbolosNoTerminales() const { return simbolos_no_terminales_; }
  Simbolo GetSimboloDeArranque() const { return simbolo_de_arranque_; }
  std::multimap<Simbolo, std::vector<Simbolo>> GetProducciones() const { return producciones_; }
  // Método para agregar una produccion
  void AgregarProduccion(Simbolo simbolo, std::vector<Simbolo> produccion);
  // Método para imprimir la gramática por fichero
  void ImprimirGramatica(std::string nombre_archivo);
  // método para convertir una gramatica independiente del contexto a forma normal de chomsky
  Gramatica ConvertirAFormaNormalChomsky() const;
  //sobrecarga operador <<
  friend std::ostream& operator<<(std::ostream& os, const Gramatica& gramatica);

 private:
  Alfabeto alfabeto_gramatica_;
  std::set<Simbolo> simbolos_no_terminales_;
  Simbolo simbolo_de_arranque_;
  std::multimap<Simbolo, std::vector<Simbolo>> producciones_;
};