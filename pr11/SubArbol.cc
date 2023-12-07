// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: 
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 05/12/2023
// Archivo SubArbol.cc: contiene la implementación de los métodos de la clase
// Contiene la implementación de los métodos de la clase SubArbol.
// Esta contiene un conjunto de arcos y un conjunto de puntos que forman un sub-árbol

#include "SubArbol.h"

namespace EMST {
  /**
   * @brief Constructor por defecto
   * Se inicializan los atributos, el conjunto de arcos, el conjunto de puntos y el coste
   */
  SubArbol::SubArbol() : arcos_(), puntos_(), coste_(0) {}

  /**
   * @brief Destructor
   * Se destruyen los atributos, el conjunto de arcos y el conjunto de puntos
   */
  SubArbol::~SubArbol() {}

  /**
   * @brief Método que permite agregar un arco al sub-árbol
   * Este método añade un arco al conjunto de arcos del sub-árbol y los dos puntos
   * @param arco arco que vamos a añadir
   */
  void SubArbol::AgregarArco(const CyA::Arco& arco) {
    // Añadimos el arco al sub-árbol
    arcos_.emplace_back(arco);
    // Insertamos los dos extremos del arco
    puntos_.insert(arco.first);
    puntos_.insert(arco.second);
  }

  /**
   * @brief Método que permite agregar un punto al sub-árbol
   * Este método añade un punto al conjunto de puntos del sub-árbol
   * @param punto punto que vamos a añadir
   */
  void SubArbol::AgregarPunto(const CyA::Punto& punto) { puntos_.insert(punto); }

  /**
   * @brief Método que dice si un punto está o no en el sub-árbol
   * Este método comprueba si un punto está en el conjunto de puntos del sub-árbol
   * @param punto punto que queremos comprobar si está en el árbol
   * @return true
   * @return false
   */
  bool SubArbol::Contiene(const CyA::Punto& punto) const {
    return puntos_.find(punto) != puntos_.end();
  }

  /**
   * @brief Método que permite fusionar 2 sub-árboles mediante un arco ponderado
   * Este método fusiona 2 sub-árboles a partir de un arco ponderado
   * @param sub_arbol sub-árbol a fusionar con el sub-árbol invocante
   * @param arco_ponderado arista que sirve para fusionar los 2 árboles
   */
  void SubArbol::Fusion(const SubArbol& sub_arbol, const CyA::ArcoPonderado& arco_ponderado) {
    // Concatenamos el contenido de 'arcos_' con el de los arcos del sub-árbol que queremos fusionar
    arcos_.insert(arcos_.end(), sub_arbol.arcos_.begin(), sub_arbol.arcos_.end());
    // Agregamos como último arco el arco que une los dos sub-árboles
    arcos_.emplace_back(arco_ponderado.second);
    // Concatemos el contenido de 'puntos_' con los puntos del sub-árbol que queremos fusionar
    puntos_.insert(sub_arbol.puntos_.begin(), sub_arbol.puntos_.end());
    // Sumamos al coste del sub-árbol invocante, el coste de la arista que conecta
    // los dos + el coste del otro sub-árbol
    coste_ += arco_ponderado.first + sub_arbol.GetCoste();
  }
}  // namespace EMST