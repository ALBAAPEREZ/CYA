// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Simulacion de Máquinas de Turing
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 14/11/2023
// Archivo Maquina_Turing.cc:
// Contiene la clase Maquina_Turing. Esta clase representa una máquina de Turing.
// Historial de revisiones:
// 

#include "Maquina_Turing.h"

/**
 * @brief Construct a new Maquina Turing:: Maquina Turing object
 * Constructor por parámetros, recibe un string con el nombre del fichero
 * @param nombre_fichero_turing nombre del fichero
 * @param nombre_fichero_cinta nombre del fichero
 */
MaquinaTuring::MaquinaTuring(std::string nombre_fichero_turing, std::string nombre_fichero_cinta) {
  // abrir fichero entrada
  std::ifstream fichero(nombre_fichero_turing, std::ios::in);
  // comporbar que se ha abierto correctamente
  if (fichero.fail()) {
    std::cerr << "Error al abrir el fichero" << std::endl;
    exit(EXIT_FAILURE);
  }
  // iniciar cinta de la maquina de turing
  cinta_.IniciarCinta(nombre_fichero_cinta);
  // declarar variables tipo string
  std::string estado_inicial, estados_finales, numero_estados, numero_transiciones, transicion;
  std::getline(fichero, numero_estados);
  numero_estados_ = std::stoi(numero_estados);
  // comporbamos numero de estados != 0
  if (numero_estados_ == 0) {
    std::cerr << "Error, el numero de estados no puede ser 0" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::getline(fichero, estado_inicial);
  Estado estado_aux{std::stoi(estado_inicial), false};
  std::getline(fichero, estados_finales);
  std::stringstream estados(estados_finales);
  std::string aux;
  // recorremos estados 
  while (estados >> aux) {
    // si el estado inicial corresponde con el estdao final --> el estado incial es de aceptacion
    if (aux == estado_inicial) {
      Estado estado{std::stoi(estado_inicial), true};
      estado_inicial_ = estado;
    }
    // metemos estado de aceptacion en el conjunto de estados finales
    estados_.insert(Estado(std::stoi(aux), true));
    estados_finales_.insert(Estado(std::stoi(aux), true));
  }
  // todos los estados que no esten en el conjunto de estados los metemos en el conjunto de estados
  for (int i = 0; i < numero_estados_; i++) {
    estados_.insert(Estado(i, false));
  }
  std::getline(fichero, numero_transiciones);
  numero_transiciones_ = std::stoi(numero_transiciones);
  // leemos todas las transiciones
  for (int j = 1; j <= numero_transiciones_; ++j) {
    std::getline(fichero, transicion);
    std::stringstream transiciones(transicion);
    std::string leer_elemento_transicion;
    transiciones >> leer_elemento_transicion;
    // leemos estado actual
    Estado estado_actual{BuscarEstado(leer_elemento_transicion)};
    // leemos simbolo actual
    transiciones >> leer_elemento_transicion;
    Simbolo simbolo_actual{leer_elemento_transicion};
    // leemos simbolo a escribir
    transiciones >> leer_elemento_transicion;
    Simbolo simbolo_escribir{leer_elemento_transicion};
    // leemos movimiento de la cabeza
    transiciones >> leer_elemento_transicion;
    std::string movimiento_cabeza{leer_elemento_transicion};
    // leemos estdo siguiente
    transiciones >> leer_elemento_transicion;
    Estado estado_siguiente{BuscarEstado(leer_elemento_transicion)};
    std::pair<Estado, Simbolo> estado_simbolo{estado_actual, simbolo_actual};
    transiciones_[estado_simbolo][simbolo_escribir] = std::make_pair(movimiento_cabeza, estado_siguiente);
  }
  // cerrar fichero
  fichero.close();
}

/**
 * @brief Método que busca un estado en el conjunto de estados
 * Recorre el conjunto de estados y si encuentra el identificador que es igual al que pasamos por parametros devolvemos el estado
 * @param nombre_estado 
 * @return Estado 
 */
Estado MaquinaTuring::BuscarEstado(std::string nombre_estado) {
  // Recorre el conjunto de estados y si encuentra el identificador que es igual al que pasamos por parametros devolvemos el estado
  int identificador = std::stoi(nombre_estado);
  for (auto estado : estados_) {
    if (estado.GetIdentificador() == identificador) {
      return estado;
    }
  } 
}

/**
 * @brief Método que simula la máquina de turing
 *  Comprueba qeu la cadena sea aceptada o no, que la transicion existe y que el estado existe
 * @param estado estado actual
 * @param simbolo simbolo actual
 * @return true si existe la transicion
 * @return false si no existe la transicion
 */
bool MaquinaTuring::ExisteTransicion(Estado estado, Simbolo simbolo, Simbolo simbolo_escritura) {
  // comprobar si existe la transicion
  if (transiciones_[std::make_pair(estado, simbolo)].find(simbolo_escritura) != transiciones_[std::make_pair(estado, simbolo)].end()) {
    return true;
  } 
  return false;
}

/**
 * @brief Método que simula la máquina de turing
 * Recorre la cinta y va imprimiendo los simbolos, reemplaza el símbolo actual por el símbolo de escritura, mueve la cabeza de lectura/escritura y actualiza el estado y símbolo que estamos inspeccionando
 *  Imprime la traza de la cinta
 * @return true si la cadena es aceptada
 * @return false  si la cadena no es aceptada
 */
bool MaquinaTuring::SimularMaquinaTuring() {
  // La simulación seguirá mientras hayan transiciones para el estado y símbolo actual
  Estado estado_actual = estado_inicial_;
  Simbolo simbolo_actual = cinta_.ObtenerSimboloCabeza();
  auto auxiliar{transiciones_[std::make_pair(estado_actual, simbolo_actual)].begin()};
  Simbolo simbolo_escritura{auxiliar->first};
  while (ExisteTransicion(estado_actual, simbolo_actual, simbolo_escritura)) {
    // Imprimimos la traza de la cinta
    cinta_.ImprimirCinta(estado_actual);
    // Reemplazamos el símbolo actual por el símbolo de escritura
    cinta_.EscribirCinta(simbolo_escritura);
    // Movemos la cabeza de lectura/escritura
    cinta_.MoverCabeza(transiciones_[std::make_pair(estado_actual, simbolo_actual)][simbolo_escritura].first);
    // Actualizamos el estado y símbolo que estamos inspeccionando
    estado_actual = transiciones_[std::make_pair(estado_actual, simbolo_actual)][simbolo_escritura].second;
    simbolo_actual = cinta_.ObtenerSimboloCabeza();
    auxiliar = transiciones_[std::make_pair(estado_actual, simbolo_actual)].begin();
    simbolo_escritura = auxiliar->first;
  }
  cinta_.ImprimirCinta(estado_actual);
  if (estado_actual.GetAceptado()) {
    return true;
  } 
  return false;
}

/**
 * @brief Método que comprueba si una cadena es aceptada o no
 */
void MaquinaTuring::EsAceptada() {
  // comprueba si es aceptada
  if (SimularMaquinaTuring()) {
    std::cout << "Cadena ACEPTADA" << std::endl;
  } else {
    std::cout << "Cadena RECHAZADA" << std::endl;
  }
}

/**
 * @brief Método para imprimir la cinta
 * Recorre la cinta y va imprimiendo los simbolos
 * @param os flujo de salida
 * @param maquina_turing 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, MaquinaTuring& maquina_turing) {
  os << maquina_turing.numero_estados_ << std::endl;
  os << maquina_turing.estado_inicial_.GetIdentificador() << std::endl;
  // imprimir estados de aceptacion
  for (auto estado : maquina_turing.estados_finales_) {
    os << estado.GetIdentificador() << " ";
  }
  os << std::endl << maquina_turing.numero_transiciones_ << std::endl;
  // imprimir todas las transiciones
  for (auto estado : maquina_turing.transiciones_) {
    for (auto simbolo : estado.second) {
      os << estado.first.first.GetIdentificador() << " " << estado.first.second << " " << simbolo.first << " " << simbolo.second.first << " " << simbolo.second.second.GetIdentificador() << std::endl;
    }
  }
  return os;
}