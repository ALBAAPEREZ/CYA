// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 22/09/2023
// Archivo Simbolo.h: 
// Contiene la clase Simbolo. En esta se encuentra el constructor por defecto, por parámetros,
// El getter que devuelve el valor del atributo privado.
// Encontramos también la sobrecarga de las operaciones de extracción e insercción.
// Por último tenemos la sobrecarga de las operaciones == y < para la comparación de cadenas
// y por ende, la ordenación de estas.
// Historial de revisiones:
// 22/09/23 - Creación (primera versión) del código. Creación de la función usage y clases
// 23/09/23 - Realización de la implementacion de los metodos de las
// clases, asi como las funciones de inversa y longitud. Implementacion
// del main para poder ir probando si funciona 
// 24/09/23 - Realización de las funciones Sufijo y prefijo de la clase cadena
// 25/09/23 - Correción de errores y finalización del main para correcto funcionamiento.
// Finalización de toda la correcta identacion y comentarios

#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

/**
 * @brief Clase Simbolo. Esta clase representa un símbolo, que es un carácter individual.
 * Proporciona funcionalidad para obtener y comparar símbolos.
 * Contiene el constructor tanto por defecto como por parámetros.
 * El getter que obtiene el atributo privado de la clase y la sobrecarga de operadores
 * para la ordenación de los simbolos en cadenas. 
 */
class Simbolo {
 public:
  Simbolo(); // Constructor por defecto
  Simbolo(std::string simbolo) : simbolo_{simbolo} {} 
  std::string GetSimbolo() const { return simbolo_; } // Getter
  // Sobrecarga de operadores de entrada y salida
  friend std::istream& operator>>(std::istream& input, Simbolo& simbolo);
  friend std::ostream& operator<<(std::ostream& output, const Simbolo& simbolo);
  // Sobrecarga de operador == y < para la ordenación de cadenas
  bool operator==(const Simbolo& otro_simbolo) const;
  bool operator<(const Simbolo& otro_simbolo) const;

 private:
  std::string simbolo_; //atributo privados
};

// Definición de la sobrecarga de extracción e insercción
std::istream& operator>>(std::istream& input, Simbolo& simbolo);
std::ostream& operator<<(std::ostream& output, const Simbolo& simbolo);

#endif // SIMBOLO_H