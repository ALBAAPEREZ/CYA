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
 
#pragma once
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <utility>

#include "TiposDePuntos.h"

/** 
 * @brief Espacio de nombres para la asignatura Computabilidad y Algoritmia
*/
namespace EMST {
  /**
   * @brief Clase SubArbol que contiene un conjunto de arcos 
   * y un conjunto de puntos que forman un sub-árbol
   */
  class SubArbol {
   public:
    // Constructor por defecto
    SubArbol();
    // Destructor
    ~SubArbol();
    // Método que permite agregar un arco al sub-árbol
    void AgregarArco(const CyA::Arco& arco);
    // Método que permite agregar un punto al sub-árbol
    void AgregarPunto(const CyA::Punto& punto);
    // Método que dice si un punto está en un sub-árbol
    bool Contiene(const CyA::Punto& punto) const;
    // Método que fusiona 2 sub-árboles a partir de un arco ponderado
    void Fusion(const SubArbol& sub_arbol, const CyA::ArcoPonderado &a);
    // Getters
    inline const CyA::Arbol& GetArcos() const { return arcos_; }
    inline double GetCoste() const { return coste_; }

   private:
    CyA::Arbol arcos_;
    CyA::ColeccionDePuntos puntos_;
    double coste_;
  };
  typedef std::vector<SubArbol> SubArbol_vector;
}  // namespace EMST