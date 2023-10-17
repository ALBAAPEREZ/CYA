// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Simulación de autómatas finitos
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 14/10/2023
// Archivo Automata.cc:
// Contiene la implementación de los métodos de la clase Automata.
// El constructor que se utiliza para construir un objeto de la clase Automata a partir de un fichero de entrada.
// El método EsAceptado que dice si una cadena es aceptada o no por el autómata.
// El método ImprimirCadena que imprime la cadena y si es aceptada o no por el autómata.
// Historial de revisiones:
//  13/10/2023 --> comienzo de la práctica. Creación (primera versión) del código.
//  Creación de la clase Estado .h y su implementación en el .cc
//  14/10/2023 --> Creación de la clase Autómata y su desarrollo en el .cc
//  15/10/2023 --> Desarrollo del código de la clase Autómata. Método EsAceptado y método ImprimirCadena.
//  16/10/2023 --> Corrección del código y finalización de la práctica.

#include <iostream>
#include "Automata.h"

/**
 * @brief Constructor de la clase Automata a partir de un archivo de entrada.
 * Este constructor inicializa un objeto Automata a partir de la definición de un 
 * autómata contenida en un archivo de entrada proporcionado.
 * El formato del archivo de entrada es el siguiente:
 * - La primera línea contiene el alfabeto del autómata, separado por espacios.
 * - La segunda línea contiene el número de estados del autómata.
 * - La tercera línea contiene el estado de arranque.
 * - Las siguientes líneas contienen la información de cada estado. Cada línea contiene:
 *  - El identificador del estado.
 *  - Un booleano que indica si el estado es de aceptación o no.
 *  - El número de transiciones del estado.
 * @param fichero_entrada Una referencia a un objeto std::ifstream que representa el archivo de entrada con la definición del autómata.
 */
Automata::Automata(std::ifstream& fichero_entrada) {
  std::string linea;
  // primera linea contiene el alfabeto
  std::getline(fichero_entrada, linea);
  std::istringstream stream(linea);
  Simbolo simbolo;
  std::set<Simbolo> alfabeto_aux; // conjunto de los simbolos del alfabeto
  // recorre el flujo de entrada y va insertando los simbolos en el conjunto
  while (stream >> simbolo) {
    alfabeto_aux.insert(simbolo);
  }
  // crea un objeto Alfabeto a partir del conjunto de simbolos
  Alfabeto alfabeto{alfabeto_aux};
  // segunda linea contiene el número de estados
  std::getline(fichero_entrada, linea);
  std::istringstream stream2(linea);
  stream2 >> numero_estados_;
  // tercera linea contiene el estado de arranque
  std::getline(fichero_entrada, linea);
  std::istringstream stream3(linea);
  stream3 >> estado_arranque_;
  // recorre el resto de lineas que contienen los estados --> lee la información de cada estado
  for (int i = 0; i < numero_estados_; i++) {
    std::getline(fichero_entrada, linea);
    std::istringstream stream4(linea);
    int identificador, numero_transiciones, identificador_estado_destino;
    //  Se lee el identificador, si el estado es aceptado, y el número de transiciones del estado.
    stream4 >> identificador;
    bool aceptado;
    stream4 >> aceptado;
    stream4 >> numero_transiciones;
    Estado estado{identificador, aceptado};
    // transiciones desde el estado actual
    for (int j{0}; j < numero_transiciones; ++j) {
      Simbolo simbolo;
      stream4 >> simbolo;
      stream4 >> identificador_estado_destino;
      Estado estado_destino{identificador_estado_destino, 0};
      // se añade la transición al estado
      estado.AgregarTransicion(simbolo, estado_destino);
    }
    //  Si el estado actual es el estado de arranque, se actualiza la variable "estado_arranque_".
    if (estado_arranque_.GetIdentificador() == identificador) {
      estado_arranque_ = estado;
    }
    // se inserta el estado en el conjunto de estados
    estados_.insert(std::pair<int, Estado>(estado.GetIdentificador(),estado));
  }
}

/**
 * @brief Determina si una cadena es aceptada por el autómata a partir de un estado dado.
 * Este método realiza una búsqueda recursiva para verificar si una cadena es aceptada por el autómata a partir de un estado dado. Comprueba si la cadena ha sido completamente procesada y si el estado actual es un estado de aceptación.
 * @param cadena Referencia a un objeto Cadena que se evaluará.
 * @param estado Referencia al estado de inicio de la evaluación.
 * @param iterador Posición actual en la cadena.
 * @return true si la cadena es aceptada, false en caso contrario.
 */
bool Automata::EsAceptado(Cadena& cadena, Estado& estado, size_t iterador) {
  // si hemos procesado toda la cadena
  if (iterador == cadena.GetSize()) { 
    // y si hemos llegado al estado de aceptación --> devuelve true
    if (estado.GetAceptado()) {
      return true;
    }
  } else { // no hemos procesado toda la cadena
    // recorrerá todas las transiciones del estado actual. 
    for (auto transicion : estado.GetEstadosSiguientes()) {
      // si el símbolo de la transición coincide con el símbolo de la cadena en la posición actual
      if (transicion.first == cadena.GetSimbolo(iterador)) { 
        // llamada recursiva con el estado destino de la transición y la posición siguiente de la cadena
        if (EsAceptado(cadena, estados_[transicion.second.GetIdentificador()], iterador + 1)) {
          return true;
        }
      } else if (transicion.first == Simbolo("&")) { // si el símbolo de la transición es la cadena vacía
        if (EsAceptado(cadena, estados_[transicion.second.GetIdentificador()], iterador)) {
          return true;
        }
      }
    }
  }
  return false;
}

/**
 * @brief Imprime una cadena y su estado de aceptación.
 * Esta función imprime la cadena dada y muestra si es aceptada o rechazada por el autómata. Utiliza la función `EsAceptado` para determinar la aceptación.
 * @param cadena Referencia a un objeto Cadena que se imprimirá.
 */
void Automata::ImprimirCadena(Cadena& cadena) {
  if (EsAceptado(cadena, estado_arranque_, 0)) {
    std::cout << cadena << " --- Accepted" << std::endl;
  } else {
    std::cout << cadena << " --- Rejected" << std::endl;
  }
}

/**
 * @brief Sobrecarga del operador de inserción para la clase Automata.
 * Esta función permite leer un objeto de la clase Automata desde un flujo de entrada.
 * @param is El flujo de entrada desde el que se leerá el objeto Automata.
 * @param automata El objeto Automata que se llenará con los valores leídos.
 * @return Una referencia al flujo de entrada después de la lectura.
 */
std::istream& operator>>(std::istream& is, Automata& automata) {
  is >> automata.numero_estados_;
  is >> automata.estado_arranque_;
  for (int i = 0; i < automata.numero_estados_; i++) {
    Estado estado;
    is >> estado;
    automata.estados_.insert(std::pair<int, Estado>(estado.GetIdentificador(), estado));
  }
  return is;
}

/**
 * @brief Sobrecarga del operador de salida para la clase Automata.
 * Esta función permite escribir un objeto de la clase Automata en un flujo de salida.
 * @param output El flujo de salida en el que se escribirá el objeto Automata.
 * @param automata El objeto Automata que se escribirá en el flujo de salida.
 * @return Una referencia al flujo de salida después de la escritura. 
 */
std::ostream& operator<<(std::ostream& output, const Automata& automata) {
  output << automata.numero_estados_ << std::endl;
  output << automata.estado_arranque_ << std::endl;
  for (auto estado : automata.estados_) {
    output << estado.second << std::endl;
  }
  return output;
}

/**
 * @brief Sobrecarga del operador de igualdad para comparar dos objetos Automata.
 * Esta función permite comparar dos objetos Automata para verificar si tienen el mismo número de estados.
 * @param otro_automata El objeto Automata que se comparará con el objeto actual.
 * @return true si los Automata tienen el mismo número de estados, false en caso contrario.
 */
bool Automata::operator==(const Automata& otro_automata) const {
  return numero_estados_ == otro_automata.numero_estados_;
}

/**
 * @brief Sobrecarga del operador de comparación "menor que" para comparar dos objetos Automata.
 * Esta función permite comparar dos objetos Automata para verificar si el número de estados del objeto actual es menor que el número de estados del otro objeto.
 * @param otro_automata El objeto Automata que se comparará con el objeto actual.
 * @return true si el número de estados del objeto actual es menor que el del otro objeto, false en caso contrario.
 */
bool Automata::operator<(const Automata& otro_automata) const {
  return numero_estados_ < otro_automata.numero_estados_;
}