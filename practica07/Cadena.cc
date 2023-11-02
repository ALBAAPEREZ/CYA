// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Algoritmo de construccion de subconjuntos
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 14/10/2023
// Archivo Cadena.cc:
// Contiene la implementación de los métodos de la clase Cadena.
// El constructor que se utiliza para construir un objeto de la clase Cadena a partir de una instancia de la clase Cadena.
// El método Longitud que devuelve el tamaño de la cadena.
// El método Inversa que devuelve la inversa de la cadena actual.
// El método Prefijos que genera y devuelve un conjunto de cadenas que representan los prefijos de la cadena actual, incluyendo el prefijo vacío "&".
// El método Sufijos que genera y devuelve un conjunto de cadenas que representan los sufijos de la cadena actual, incluyendo el sufijo vacío "&".
// La sobrecarga del operador de entrada y salida.
// La sobrecarga del operador de igualdad (==) y menor que (<) que nos servirán para comparar cadenas
// Historial de revisiones:
//  13/10/2023 --> comienzo de la práctica. Creación (primera versión) del código.
//  Creación de la clase Estado .h y su implementación en el .cc
//  14/10/2023 --> Creación de la clase Autómata y su desarrollo en el .cc
//  15/10/2023 --> Desarrollo del código de la clase Autómata. Método EsAceptado y método ImprimirCadena.
//  16/10/2023 --> Corrección del código y finalización de la práctica.

#include "Cadena.h"
#include "Lenguaje.h"

/**
 * @brief Construct a new Cadena:: Cadena object
 * Constructor que mete en la cadena & considerado cadena vacía cuando 
 * esta no tiene ningún elemento.
 */
Cadena::Cadena() {
  cadena_.push_back(Simbolo("&"));
}

/**
 * @brief Constructor de la clase Cadena que recibe una cadena de texto.
 * Este constructor recibe una cadena de texto y la convierte en una secuencia de símbolos
 * representados por objetos de la clase Simbolo. Cada carácter de la cadena de texto se
 * convierte en un objeto Simbolo y se almacena en la cadena resultante
 * @param cadena La cadena de texto que se convertirá en una secuencia de símbolos.
 */
Cadena::Cadena(std::string cadena) {
  std::vector<Simbolo> cadena_aux;
  for (size_t i{0}; i < cadena.size(); ++i) { // recorrera cada elemento de la cadena
    std::string string_auxiliar{cadena[i]}; // almacenará cada elemento en la aux
    cadena_aux.push_back(Simbolo(string_auxiliar)); // cada caracter en simbolo
  }
  cadena_ = cadena_aux;
}

/**
 * @brief Método que devuelve la longitud de la cadena
 * Este método calcula y devuelve la longitud de la cadena actual, que es la 
 * cantidad de símbolos en la cadena. Si la cadena es igual al símbolo "&" (cadena vacía),
 * la longitud será 0.
 * @return int retorna el tamaño de la cadena
 */
int Cadena::Longitud() {
  if (cadena_.size() == 1 && cadena_[0] == Simbolo("&")) {
    return 0;
  }
  return cadena_.size();
}

/**
 * @brief Setter que modifica el valor del atributo privado cadena_.
 * Este método permite agregar un símbolo al final de la cadena actual
 * representada por el objeto `Cadena`.
 * @param simbolo simbolo a agregar al final de la cadena
 * @return Cadena Una referencia al objeto `Cadena` actual, lo que permite realizar 
 * operaciones en cadena.
 */
Cadena Cadena::SetCadena(const Simbolo& simbolo) {
  cadena_.push_back(simbolo);
  return *this;
}

/**
 * @brief Devuelve la inversa de la cadena actual.
 * Esta función calcula y devuelve la inversa de la cadena actual.
 * @return Un objeto Cadena que representa la inversa de la cadena actual.
 */
Cadena Cadena::Inversa() {
  std::vector<Simbolo> cadena_resultado;
  for (int orden = cadena_.size() - 1; orden >= 0; orden--) { // recorre la cadena inversa
    cadena_resultado.push_back(cadena_[orden]); // agrega el simbolo a la cadena invertida
  }
  return Cadena{cadena_resultado};
}

/**
 * @brief Método que genera los prefijos de una cadena
 * Este método genera y devuelve un conjunto de cadenas que representan los
 * prefijos de la cadena actual, incluyendo el prefijo vacío "&".
 * @return Cadena que contiene los prefijos de la cadena.
 */
Lenguaje Cadena::Prefijos() {
  std::string auxiliar{""};
  std::vector<Simbolo> cadena{Simbolo("&")}; // almacena los simbolos de cada prefijo
  Cadena cadena_vacia{cadena}; 
  std::set<Cadena> lenguaje_auxiliar{cadena};
  cadena.clear();
  for (auto simbolo : cadena_) { // recorre elementos de la cadena actual
    auxiliar.push_back(simbolo.GetSimbolo()[0]); // Construir el prefijo actual agregando el símbolo.
    cadena.push_back(Simbolo(auxiliar));
    Cadena prefijo{cadena}; // Crear un objeto Cadena que representa el prefijo actual.
    lenguaje_auxiliar.insert(prefijo);
    cadena.clear();
  }
  Lenguaje lenguaje_resultado{lenguaje_auxiliar};
  return lenguaje_resultado; // devuele el lenguaje que contiene los prefijos
}

/**
 * @brief Genera los sufijos de la cadena.
 * Este método genera y devuelve un conjunto de cadenas que representan los
 * sufijos de la cadena actual, incluyendo el sufijo vacío "&".
 * @return Cadena que contiene los sufijos de la cadena.
 */
Lenguaje Cadena::Sufijos() {
  // Vector para almacenar los símbolos de cada sufijo.
  std::string auxiliar{""};
  std::vector<Simbolo> cadena{Simbolo("&")};
  Cadena cadena_vacia{cadena};
  std::set<Cadena> lenguaje_auxiliar{cadena};
  cadena.clear();
  // Recorrer los símbolos de la cadena original en orden inverso.
  for (auto simbolo{cadena_.rbegin()}; simbolo != cadena_.rend(); ++simbolo) {
    cadena.push_back(*simbolo); // Agregar el símbolo actual al vector cadena para construir el próximo sufijo.
    Cadena prefijo{cadena};
    // Calcular la inversa del sufijo y agregarla al conjunto de lenguaje_auxiliar.
    lenguaje_auxiliar.insert((prefijo.Inversa()));
  }
  Lenguaje lenguaje_resultado{lenguaje_auxiliar};
  return lenguaje_resultado;
}

/**
 * @brief Sobrecarga del operador de entrada >>, operador de extracción
 * @param is flujo de entrada para la cadaena
 * @param cadena La Cadena en la que se almacenarán los símbolos leídos.
 * @return std::istream& referencia al flujo de entrada para permitir operaciones en cadena.
 */
std::istream& operator>>(std::istream& is, Cadena& cadena) {
  std::vector<Simbolo> simbolos;
  Simbolo simbolo;
  while (is >> simbolo) { // vamos leyendo nuevos simbolos
    simbolos.push_back(simbolo); 
  }
  // limpiamos cadena y  asignammos nuevos simbolos a esta 
  cadena.GetCadena().clear();
  cadena.GetCadena() = simbolos;
  return is;
}

/**
 * @brief Sobrecarga del operador de salida (<<).
 * Permite la escritura de una Cadena en un flujo de salida (ostream).
 * @param os El flujo de salida en el cual se escribirán los símbolos de la Cadena.
 * @param cadena La Cadena que se escribirá en el flujo de salida.
 * @return La referencia al flujo de salida para permitir operaciones en cadena.
 */
std::ostream& operator<<(std::ostream& os, const Cadena& cadena) { 
  // recorre cada simbolo de la cadena y la imrpime por pantalla
  for (const Simbolo& simbolo : cadena.cadena_) {
    os << simbolo;
  }
  return os;
}

/**
 * @brief Sobrecarga del operador de igualdad (==).
 * Compara si dos cadenas son iguales.
 * @param otra_cadena La otra cadena que se va a comparar con la cadena actual.
 * @return true si las cadenas son iguales.
 * @return false si las cadenas son diferentes.
 */
bool Cadena::operator==(const Cadena& otra_cadena) const {
  return cadena_ == otra_cadena.GetCadena();
}
 
/**
 * @brief Sobrecarga del operador de menor que (<).
 * Compara dos cadenas para determinar si una es menor que la otra en orden lexicográfico.
 * @param otra_cadena La otra cadena que se va a comparar con la cadena actual.
 * @return true si la cadena actual es menor que la otra cadena.
 * @return false si la cadena actual no es menor que la otra cadena.
 */
bool Cadena::operator<(const Cadena& otra_cadena) const {
  return cadena_ < otra_cadena.GetCadena();
}

//Modificacion --> potencia de una cadena aplicada al prefijo o sufijo

/**
 * @brief Método que se encarga de hacer la potencia al cubo de los prefijos de una cadena. 
 * @return Lenguaje imprime todos los prefijos al cubo de una cadena
 */
Lenguaje Cadena::PotenciaCuboCadena() {
  std::set<Cadena> lenguaje_auxiliar; // Usamos un conjunto para evitar duplicados
  // Verificamos si la cadena está vacía
  if (cadena_.size() == 1 && cadena_[0] == Simbolo("&")) {
    lenguaje_auxiliar.insert(Cadena{""}); // Agregamos el prefijo vacío "&" al conjunto
  } else {
    // Calculamos la potencia al cubo de la cadena
    std::string cadena_actual = "";
    for (const Simbolo& simbolo : cadena_) {
      cadena_actual += simbolo.GetSimbolo(); // Concatenamos el símbolo actual
    }
    cadena_actual += cadena_actual + cadena_actual; // Concatenamos la cadena actual tres veces 
    lenguaje_auxiliar.insert(Cadena{cadena_actual});
  }
  Lenguaje lenguaje_resultado{lenguaje_auxiliar};
  return lenguaje_resultado; // Devolvemos el lenguaje que contiene la potencia al cubo de la cadena
}
