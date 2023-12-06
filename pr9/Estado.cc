// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Simulacion de Máquinas de Turing
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 14/11/2023
// Archivo Estado.cc:
// Contiene la implementación de los métodos de la clase Estado.
// El constructor por defecto y el constructor por parámetros.
// El método AgregarTransicion que añade una transición al estado.
// El método GetTransiciones que devuelve las transiciones del estado.
// El método GetIdentificador que devuelve el identificador del estado.
// El método GetAceptado que devuelve si el estado es de aceptación o no.
// El método operator= que sobrecarga el operador de asignación.
// El método operator== que sobrecarga el operador de igualdad.
// El método operator< que sobrecarga el operador "menor que".
// Historial de revisiones:
//  13/10/2023 --> comienzo de la práctica. Creación (primera versión) del código.
//  Creación de la clase Estado .h y su implementación en el .cc
//  14/10/2023 --> Creación de la clase Autómata y su desarrollo en el .cc
//  15/10/2023 --> Desarrollo del código de la clase Autómata. Método EsAceptado y método ImprimirCadena.
//  16/10/2023 --> Corrección del código y finalización de la práctica.

#include "Estado.h"

/**
 * @brief Agrega una transición desde este estado a otro estado con un símbolo dado.
 * Esta función agrega una transición desde el estado actual a otro estado utilizando
 * el símbolo proporcionado como etiqueta de la transición.
 * @param simbolo El símbolo que etiqueta la transición.
 * @param estado El estado al que se transita desde el estado actual.
 */
void Estado::AgregarTransicion(Simbolo simbolo, Estado estado) {
  transiciones_.insert(std::pair<Simbolo, Estado>(simbolo, estado));
}

/**
 * @brief Sobrecarga del operador de inserción para la clase Estado.
 * Esta función permite leer un objeto de la clase Estado desde un flujo de entrada.
 * @param is El flujo de entrada desde el que se leerá el objeto Estado.
 * @param estado El objeto Estado que se llenará con los valores leídos.
 * @return Una referencia al flujo de entrada después de la lectura.
 */
std::istream& operator>>(std::istream& is, Estado& estado) {
  is >> estado.identificador_;
  return is;
}

/**
 * @brief Sobrecarga del operador de salida para la clase Estado.
 * Esta función permite escribir un objeto de la clase Estado en un flujo de salida.
 * @param os El flujo de salida en el que se escribirá el objeto Estado.
 * @param estado El objeto Estado que se escribirá en el flujo de salida.
 * @return Una referencia al flujo de salida después de la escritura.
 */
std::ostream& operator<<(std::ostream& os, const Estado& estado) {
  os << estado.identificador_ << std::endl;
  for (const auto& transicion : estado.transiciones_) {
    os << transicion.first << " " << transicion.second.GetIdentificador() << std::endl;
  }
  return os;
}

/**
 * @brief Sobrecarga del operador de igualdad para comparar dos objetos Estado.
 * Esta función permite comparar dos objetos Estado para verificar si tienen el mismo identificador.
 * @param otro_estado El objeto Estado que se comparará con el objeto actual.
 * @return true si los Estados tienen el mismo identificador, false en caso contrario.
 */
bool Estado::operator==(const Estado& otro_estado) const {
 return identificador_ == otro_estado.identificador_;
}

/**
 * @brief Sobrecarga del operador "menor que" para comparar dos objetos Estado.
 * Esta función permite comparar dos objetos Estado basándose en sus identificadores.
 * @param otro_estado El objeto Estado con el que se comparará el objeto actual.
 * @return true si el identificador del objeto actual es menor que el identificador del otro estado, false en caso contrario.
 */
bool Estado::operator<(const Estado& otro_estado) const {
  return identificador_ < otro_estado.identificador_;
}

/**
 * @brief Asigna los atributos de otro estado a este estado.
 * Esta función de asignación copia los atributos (identificador, aceptado y transiciones) del estado
 * proporcionado como argumento al estado actual.
 * @param otro_estado El estado cuyos atributos se copiarán en este estado.
 * @return El estado actual después de la asignación.
 */
Estado Estado::operator=(const Estado& otro_estado) {
  identificador_ = otro_estado.GetIdentificador();
  aceptado_ = otro_estado.GetAceptado();
  transiciones_ = otro_estado.GetEstadosSiguientes();
  return *this;
}

