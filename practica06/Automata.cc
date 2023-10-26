// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Algoritmo de construccion de subconjuntos
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 14/10/2023
// Archivo Automata.cc:
// Contiene la implementación de los métodos de la clase Automata.
// El constructor que se utiliza para construir un objeto de la clase Automata a
// partir de un fichero de entrada. El método EsAceptado que dice si una cadena
// es aceptada o no por el autómata. El método ImprimirCadena que imprime la
// cadena y si es aceptada o no por el autómata. Historial de revisiones:
//  13/10/2023 --> comienzo de la práctica. Creación (primera versión) del
//  código. Creación de la clase Estado .h y su implementación en el .cc
//  14/10/2023 --> Creación de la clase Autómata y su desarrollo en el .cc
//  15/10/2023 --> Desarrollo del código de la clase Autómata. Método EsAceptado
//  y método ImprimirCadena. 16/10/2023 --> Corrección del código y finalización
//  de la práctica.

#include "Automata.h"

#include <iostream>

#include "Alfabeto.h"

/**
 * @brief Constructor de la clase Automata a partir de un archivo de entrada.
 * Este constructor inicializa un objeto Automata a partir de la definición de
 * un autómata contenida en un archivo de entrada proporcionado. El formato del
 * archivo de entrada es el siguiente:
 * - La primera línea contiene el alfabeto del autómata, separado por espacios.
 * - La segunda línea contiene el número de estados del autómata.
 * - La tercera línea contiene el estado de arranque.
 * - Las siguientes líneas contienen la información de cada estado. Cada línea
 * contiene:
 *  - El identificador del estado.
 *  - Un booleano que indica si el estado es de aceptación o no.
 *  - El número de transiciones del estado.
 * @param fichero_entrada Una referencia a un objeto std::ifstream que
 * representa el archivo de entrada con la definición del autómata.
 */
Automata::Automata(std::ifstream& fichero_entrada) {
  std::string linea;
  // primera linea contiene el alfabeto
  std::getline(fichero_entrada, linea);
  std::istringstream stream(linea);
  Simbolo simbolo;
  std::set<Simbolo> alfabeto_aux;  // conjunto de los simbolos del alfabeto
  // recorre el flujo de entrada y va insertando los simbolos en el conjunto
  while (stream >> simbolo) {
    alfabeto_aux.insert(simbolo);
  }
  // crea un objeto Alfabeto a partir del conjunto de simbolos
  Alfabeto alfabeto_{alfabeto_aux};
  // segunda linea contiene el número de estados
  std::getline(fichero_entrada, linea);
  std::istringstream stream2(linea);
  stream2 >> numero_estados_;
  // tercera linea contiene el estado de arranque
  std::getline(fichero_entrada, linea);
  std::istringstream stream3(linea);
  stream3 >> estado_arranque_;
  // recorre el resto de lineas que contienen los estados --> lee la información
  // de cada estado
  for (int i = 0; i < numero_estados_; i++) {
    std::getline(fichero_entrada, linea);
    std::istringstream stream4(linea);
    int identificador, numero_transiciones, identificador_estado_destino;
    //  Se lee el identificador, si el estado es aceptado, y el número de
    //  transiciones del estado.
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
    //  Si el estado actual es el estado de arranque, se actualiza la variable
    //  "estado_arranque_".
    if (estado_arranque_.GetIdentificador() == identificador) {
      estado_arranque_ = estado;
    }
    // se inserta el estado en el conjunto de estados
    estados_.insert(std::pair<int, Estado>(estado.GetIdentificador(), estado));
  }
}

/**
 * @brief Determina si una cadena es aceptada por el autómata a partir de un
 * estado dado. Este método realiza una búsqueda recursiva para verificar si una
 * cadena es aceptada por el autómata a partir de un estado dado. Comprueba si
 * la cadena ha sido completamente procesada y si el estado actual es un estado
 * de aceptación.
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
  } else {  // no hemos procesado toda la cadena
    // recorrerá todas las transiciones del estado actual.
    for (auto transicion : estado.GetEstadosSiguientes()) {
      // si el símbolo de la transición coincide con el símbolo de la cadena en
      // la posición actual
      if (transicion.first == cadena.GetSimbolo(iterador)) {
        // llamada recursiva con el estado destino de la transición y la
        // posición siguiente de la cadena
        if (EsAceptado(cadena, estados_[transicion.second.GetIdentificador()],
                       iterador + 1)) {
          return true;
        }
      }
      if (transicion.first ==
          Simbolo("&")) {  // si el símbolo de la transición es la cadena vacía
        if (EsAceptado(cadena, estados_[transicion.second.GetIdentificador()],
                       iterador)) {
          return true;
        }
      }
    }
  }
  return false;
}

/**
 * @brief Imprime una cadena y su estado de aceptación.
 * Esta función imprime la cadena dada y muestra si es aceptada o rechazada por
 * el autómata. Utiliza la función `EsAceptado` para determinar la aceptación.
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
 * @brief Método que comprueba si el automata finito es un DfA o no.
 * @return true Si el automata pasado es un dfa
 * @return false si el automata pasado no es un dfa
 */
bool Automata::EsDfa() {
  std::set<Simbolo> alfabeto_aux;
  // Recorremos todos los estados del autómata.
  for (const auto& estado_pair : estados_) {
    const Estado& estado = estado_pair.second;
    const std::multimap<Simbolo, Estado>& transiciones =
        estado.GetEstadosSiguientes();
    std::set<Simbolo> simbolos_transiciones;
    // Agregamos los símbolos de las transiciones al conjunto de símbolos del
    // alfabeto.
    for (const auto& transicion : transiciones) {
      alfabeto_aux.insert(transicion.first);
    }
    // Verificamos que no haya epsilon-transiciones (transiciones con el símbolo
    // "&") --> si hay una transicion false
    if (transiciones.count(Simbolo("&")) > 0) {
      return false;
    }
    // Verificamos si cada símbolo del alfabeto tiene solo una transición
    // saliente.
    std::set<Simbolo> simbolos_procesados;
    for (const auto& transicion : transiciones) {
      const Simbolo& simbolo = transicion.first;
      if (simbolos_procesados.count(simbolo) > 0) {
        return false;
      }
      simbolos_procesados.insert(simbolo);
    }
  }
  return true;  // Si pasa todas las verificaciones, es un DFA.
}

/**
 * @brief Método que calcula la epsilon clausura de un conjunto de estados.
 *  Este método calcula la epsilon clausura de un conjunto de estados.
 * @param estados  Conjunto de estados.
 * @return std::map<int, Estado>  Epsilon clausura del conjunto de estados.
 */
std::map<int, Estado> Automata::EpsilonClausura(std::map<int, Estado> estados) {
  std::stack<Estado> pila;       // pila de estados
  for (auto estado : estados) {  // recorre el conjunto de estados
    pila.push(estado.second);    // se inserta el estado en la pila
  }
  // se crea un mapa de estados que contendrá la epsilon clausura
  std::map<int, Estado> epsilon_clausura;
  // mientras la pila no esté vacía
  while (!pila.empty()) {
    Estado estado_actual = pila.top();
    pila.pop();
    // si el estado actual no está en el mapa de la epsilon clausura
    epsilon_clausura.insert(std::pair<int, Estado>(
        estado_actual.GetIdentificador(), estado_actual));
    for (auto transicion : estado_actual.GetEstadosSiguientes()) {
      if (epsilon_clausura.find(transicion.second.GetIdentificador()) ==
              epsilon_clausura.end() &&
          transicion.first == Simbolo("&")) {
        pila.push(transicion.second); // se mete en la pila
      }
    }
  }
  return epsilon_clausura;
}

/**
 * @brief Método que calcula el mover de un conjunto de estados con un símbolo.
 * @param estados estado del automata
 * @param simbolo cada uno de los simbolos
 * @return std::map<int, Estado>
 */
std::map<int, Estado> Automata::Mover(std::map<int, Estado> estados,
                                      Simbolo simbolo) {
  std::map<int, Estado> mover;
  for (auto estado : estados) {
    for (auto transicion : estado.second.GetEstadosSiguientes()) {
      if (transicion.first == simbolo) {
        mover.insert(std::pair<int, Estado>(
            transicion.second.GetIdentificador(), transicion.second));
      }
    }
  }
  return mover;
}

/**
 * @brief Método que calcula el autómata determinista a partir de un autómata no
 * determinista.
 * @return Automata
 */
Automata Automata::ConstruccionSubconjuntos() {
  // Inicialización
  std::set<std::map<int, Estado>> estados_dfa;
  std::stack<std::map<int, Estado>> pila;
  std::map<int, Estado> estado_arranque;
  estado_arranque[estado_arranque_.GetIdentificador()] = estado_arranque_;
  pila.push(EpsilonClausura(estado_arranque));

  //Construcción de estados
  while (!pila.empty()) {
    std::map<int, Estado> conjunto_actual = pila.top();
    pila.pop();

    for (auto simbolo : alfabeto_.GetAlfabeto()) {
      std::map<int, Estado> mover = Mover(conjunto_actual, simbolo);
      std::map<int, Estado> epsilon_clausura = EpsilonClausura(mover);

      if (estados_dfa.find(epsilon_clausura) == estados_dfa.end()) {
        pila.push(epsilon_clausura);
        estados_dfa.insert(epsilon_clausura);
      }
    }
  }
  //Construcción del DFA
  std::set<std::map<int, Estado>> dfa_states;
  int new_state = 0;
  std::map<std::map<int, Estado>, bool> marked;
  std::map<std::map<int, Estado>, int> dfa_equivalent_state;
  std::map<int, std::multimap<std::string, int>> dfa_transitions;
  std::set<int> dfa_acceptance_states;

  std::map<int, Estado> initial_state = EpsilonClausura({estado_arranque});
  std::map<int, Estado> new_state_for_dfa = initial_state;
  dfa_equivalent_state[initial_state] = new_state;
  marked[initial_state] = false;

  while (true) {
    // Encuentra un conjunto no marcado
    std::map<int, Estado> current_state;
    for (const auto& it : marked) {
      if (!it.second) {
        current_state = it.first;
        break;
      }
    }
    if (current_state.empty()) {
      break;  // Todos los estados están marcados
    }
    marked[current_state] = true;
    for (const auto& symbol : alfabeto_.GetAlfabeto()) {
      std::map<int, Estado> possible_states = Mover(current_state, symbol);
      std::map<int, Estado> e_closure_states = EpsilonClausura(possible_states);

      if (dfa_equivalent_state.find(e_closure_states) ==
          dfa_equivalent_state.end()) {
        marked[e_closure_states] = false;
        new_state++;
        dfa_equivalent_state[e_closure_states] = new_state;
      }

      dfa_transitions[dfa_equivalent_state[current_state]].insert(
          std::pair<std::string, int>(symbol.GetSimbolo(), dfa_equivalent_state[e_closure_states]));
    }
    // Actualiza los estados de aceptación
    for (const auto& nfa_state : estados_dfa) {
      for (const auto& nfa_state_id : current_state) {
        if (nfa_state.find(nfa_state_id.first) != nfa_state.end()) {
          dfa_acceptance_states.insert(dfa_equivalent_state[current_state]);
          break;
        }
      }
    }
  }
  // Construye el conjunto de estados del DFA
  std::map<int, Estado> dfa_state;
  for (const auto& it : dfa_equivalent_state) {
    for (const auto& state : it.first) {
      dfa_state.insert(std::pair<int, Estado>(state.first, state.second));
    }
  }
  return Automata(dfa_state, dfa_state[estado_arranque_.GetIdentificador()], dfa_state.size());
}

/**
 * @brief Sobrecarga del operador de inserción para la clase Automata.
 * Esta función permite leer un objeto de la clase Automata desde un flujo de
 * entrada.
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
    automata.estados_.insert(
        std::pair<int, Estado>(estado.GetIdentificador(), estado));
  }
  return is;
}

/**
 * @brief Sobrecarga del operador de salida para la clase Automata.
 * Esta función permite escribir un objeto de la clase Automata en un flujo de
 * salida.
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
 * @brief Sobrecarga del operador de igualdad para comparar dos objetos
 * Automata. Esta función permite comparar dos objetos Automata para verificar
 * si tienen el mismo número de estados.
 * @param otro_automata El objeto Automata que se comparará con el objeto
 * actual.
 * @return true si los Automata tienen el mismo número de estados, false en caso
 * contrario.
 */
bool Automata::operator==(const Automata& otro_automata) const {
  return numero_estados_ == otro_automata.numero_estados_;
}

/**
 * @brief Sobrecarga del operador de comparación "menor que" para comparar dos
 * objetos Automata. Esta función permite comparar dos objetos Automata para
 * verificar si el número de estados del objeto actual es menor que el número de
 * estados del otro objeto.
 * @param otro_automata El objeto Automata que se comparará con el objeto
 * actual.
 * @return true si el número de estados del objeto actual es menor que el del
 * otro objeto, false en caso contrario.
 */
bool Automata::operator<(const Automata& otro_automata) const {
  return numero_estados_ < otro_automata.numero_estados_;
}