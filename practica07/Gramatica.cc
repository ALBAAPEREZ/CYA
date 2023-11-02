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

#include "Gramatica.h"

/**
 * @brief Construct a new Gramatica:: Gramatica object
 */
Gramatica::Gramatica() {}

/**
 * @brief Constructor para crear un objeto Gramatica a partir de un archivo.
 * @param nombre_archivo El nombre del archivo desde el que se leerá la gramática.
 */
Gramatica::Gramatica(std::string nombre_archivo) {
  //abir fichero
  std::ifstream fichero(nombre_archivo, std::ios::in);
  if (fichero.fail()) {
    std::cout << "Error al abrir el fichero " << nombre_archivo << std::endl;
    exit(1);
  }
  //leer alfabeto
  std::string linea;
  int contador_simbolos;
  fichero >> contador_simbolos;
  // leemos todos elementos terminales
  for (int i = 0; i < contador_simbolos; i++) {
    fichero >> linea;
    Simbolo simbolo(linea);
    alfabeto_gramatica_.InsertarSimbolo(simbolo);
  }
  // leemos numero de simbolos no terminales
  int contador_no_terminales;
  fichero >> contador_no_terminales;
  // leemos simbolo de arranque
  fichero >> simbolo_de_arranque_;
  simbolos_no_terminales_.insert(simbolo_de_arranque_);
  // leemos todos elementos terminales
  for (int i = 0; i < contador_no_terminales - 1; i++) {
    fichero >> linea;
    Simbolo simbolo(linea);
    simbolos_no_terminales_.insert(simbolo);
  }
  // leemos numero de producciones
  int contador_producciones;
  fichero >> contador_producciones;
  // leemos producciones
  for (int i = 0; i < contador_producciones; i++) {
    fichero >> linea;
    Simbolo simbolo(linea);
    std::vector<Simbolo> produccion;
    std::string produccion_auxiliar;
    fichero >> produccion_auxiliar;
    std::stringstream ss(produccion_auxiliar);
    std::string simbolo_auxiliar;
    char simbolo_aux;
    while (ss >> simbolo_aux) {
      produccion.push_back(Simbolo(simbolo_aux));
    }
    AgregarProduccion(simbolo, produccion);
  }
  fichero.close();
}

/**
 * @brief Constructor de copia para crear una nueva Gramatica a partir de otra existente.
 * @param gramatica La Gramatica existente que se copiará.
 */
Gramatica::Gramatica(const Gramatica& gramatica) {
  alfabeto_gramatica_ = gramatica.alfabeto_gramatica_;
  simbolos_no_terminales_ = gramatica.simbolos_no_terminales_;
  simbolo_de_arranque_ = gramatica.simbolo_de_arranque_;
  producciones_ = gramatica.producciones_;
}

/**
 * @brief Agrega una producción a la gramática para un símbolo dado.
 * @param simbolo El símbolo no terminal al que se agregará la producción.
 * @param produccion Un vector que representa la producción asociada al símbolo.
 */
void Gramatica::AgregarProduccion(Simbolo simbolo, std::vector<Simbolo> produccion) {
  producciones_.insert(std::pair<Simbolo, std::vector<Simbolo>>(simbolo, produccion));
}

/**
 * @brief Imprime la gramática en un archivo especificado.
 * Esta función toma la gramática actual y la imprime en un archivo con el nombre especificado.
 * @param nombre_archivo El nombre del archivo en el que se imprimirá la gramática.
 */
void Gramatica::ImprimirGramatica(std::string nombre_archivo) {
  // abrir fichero de salida
  std::ofstream fichero(nombre_archivo, std::ios::out);
  if (fichero.fail()) {
    std::cout << "Error al abrir el fichero " << nombre_archivo << std::endl;
    exit(1);
  }
  fichero << *this; // meto el contenico de la gramatica en el fichero
  fichero.close();
}

/**
 * @brief Convierte la gramática a la Forma Normal de Chomsky.
 * Esta función toma una gramática en su forma actual y la convierte a la Forma Normal de Chomsky,
 * aplicando las transformaciones necesarias.
 * @return Gramatica Una nueva instancia de la gramática en la Forma Normal de Chomsky.
 */
Gramatica Gramatica::ConvertirAFormaNormalChomsky() const {
  // FASE 1
  // crear copia de la gramatica para no modificar la original
  Gramatica gramatica_chomsky = *this;
  std::map<Simbolo, Simbolo> simbolos_auxiliares;
  // for all (A → X1X2 . . . Xn (con n ≥ 2, Xi ∈ (Σ ∪ V )) do
  for (auto& produccion : gramatica_chomsky.producciones_) {
    //Si hay al menos dos simbolos
    if (produccion.second.size() >= 2) {
      // for all (Xi) do
      for (auto& simbolo : produccion.second) {
        // if (Xi = a ∈ Σ) then , es decir, si es un simbolo terminal 
        if (gramatica_chomsky.alfabeto_gramatica_.PerteneceAlfabeto(simbolo)) {
          // si el simbolo no existe creamos un simbolo no terminal que lo sustituya
          if (simbolos_auxiliares.find(simbolo) == simbolos_auxiliares.end()) {
            Simbolo simbolo_no_terminal = "C" + simbolo.GetSimbolo();
            gramatica_chomsky.simbolos_no_terminales_.insert(simbolo_no_terminal);
            std::vector<Simbolo> produccion_auxiliar = {simbolo};
            // se va construyendo la formal normal de chomsky
            gramatica_chomsky.producciones_.insert({simbolo_no_terminal, produccion_auxiliar});
            simbolos_auxiliares.insert(std::pair<Simbolo, Simbolo>(simbolo, simbolo_no_terminal));
          }
          simbolo = simbolos_auxiliares[simbolo];
        }
      }
    }
  }
  // FASE 2 --> elimina los dos ultimos simbolos no terminales de cada produccion --> eliminacion de producciones
  std::map<std::vector<Simbolo>, Simbolo> simbolos_auxiliares2;
  int contador = 0;
  for (auto& produccion : gramatica_chomsky.producciones_) {
    // se verifica si la longitud de la producción actual es mayor o igual a 3. Esto significa que la producción tiene tres o más símbolos en el lado derecho.
    while (produccion.second.size() >= 3) {
      // crea una nueva producción auxiliar que contiene los últimos dos símbolos de la producción actual.
      std::vector<Simbolo> produccion_auxiliar = {produccion.second[produccion.second.size() - 2], produccion.second[produccion.second.size() - 1]};
      // se verifica si esta producción auxiliar ya existe en el mapa 
      if (simbolos_auxiliares2.find(produccion_auxiliar) == simbolos_auxiliares2.end()) {
        Simbolo simbolos_no_terminales = "D" + std::to_string(contador);
        contador++;
        gramatica_chomsky.simbolos_no_terminales_.insert(simbolos_no_terminales);
        simbolos_auxiliares2.insert(std::pair<std::vector<Simbolo>, Simbolo>(produccion_auxiliar, simbolos_no_terminales));
      }
      // los elimina
      produccion.second.pop_back();
      produccion.second.pop_back();
      // se reemplazan ambos simbolos
      produccion.second.push_back(simbolos_auxiliares2[produccion_auxiliar]);
    }
  }
  return gramatica_chomsky;
}

/**
 * @brief Sobrecarga del operador de inserción para imprimir una gramática.
 * Esta función sobrecarga el operador `<<` para imprimir una gramática en el formato especificado.
 * @param os El flujo de salida en el que se imprimirá la gramática.
 * @param gramatica La gramática que se imprimirá.
 * @return std::ostream& El flujo de salida modificado.
 */
std::ostream& operator<<(std::ostream& os, const Gramatica& gramatica) {
  // imprimir cardinal
  os << gramatica.alfabeto_gramatica_.Cardinal() << std::endl;
  for (const Simbolo& simbolo : gramatica.alfabeto_gramatica_.GetAlfabeto()) {
    os << simbolo << std::endl;
  }
  // numero simbolos no terminales 
  os << gramatica.simbolos_no_terminales_.size() << std::endl;
  for (const Simbolo& simbolo : gramatica.simbolos_no_terminales_) {
    os << simbolo << " " << std::endl;
  }
  // numero producciones
  os << gramatica.producciones_.size() << std::endl;
  for (const auto& produccion : gramatica.producciones_) {
    os << produccion.first << " ";
    for (const Simbolo& simbolo : produccion.second) {
      os << simbolo;
    }
    os << std::endl;
  }
  return os;
}