// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: 
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 05/12/2023
// Archivo SetPuntos.h: contiene la declaración de la clase SetPuntos
// Contiene la clase SetPuntos. Esta contiene un conjunto de puntos y el árbol

#include <iostream>
#include <vector>

#include "SubArbol.h"
#include "TiposDePuntos.h"

typedef std::vector<EMST::SubArbol> Bosque;

/**
 * @brief Clase SetPuntos que contiene un conjunto de puntos y el árbol
 * heredada de la clase VectorDePuntos
 */
class SetPuntos : public CyA::VectorDePuntos {
 public:
  // Constructor por parámetros
  SetPuntos(const CyA::VectorDePuntos& points);
  // Destructor
  ~SetPuntos() {}
  // Método que calcula el Euclidean Minimum Spanning Tree mediante el algoritmo de Kruskal
  void EMST();
  // Métodos que sirven para mostrar el árbol por pantalla
  void MostrarArbol(std::ostream& os) const;
  void MostrarArbolManhattan(std::ostream& os) const;
  void Mostrar(std::ostream& os) const;
  void MostrarManhattan(std::ostream& os) const;
  // Getters
  inline const CyA::Arbol& GetArbol() const { return emst_; }
  inline const CyA::VectorDePuntos& GetPuntos() const { return *this; }
  inline const double GetCoste() const { return CalcularCoste(); }

 private:
  // Atributos
  // Euclidean Minimum Spanning Tree
  CyA::Arbol emst_;
  // Métodos privados
  // Método que calcula el coste para cada par de elementos
  void CalcularCosteArcoPonderado(CyA::ArcosPonderados& av) const;
  // Método que encuentra el sub-árbol incidente
  void EncontrarSubArbolIncidente(const Bosque& st, const CyA::Arco& a, int& i, int& j) const;
  // Método que fusiona 2 sub-árboles
  void FusionSubArboles(Bosque& st, const CyA::Arco& a, int i, int j) const;
  // Método que calcula el coste del Set de puntos
  double CalcularCoste() const;
  double CalculaCosteManhattan() const;
  // Método que calcula la distancia Euclidiana
  double DistanciaEuclidiana(const CyA::Arco& a) const;
  // Metodo que calcula la distancia manhattan.
  double DistanciaManhattan(const CyA::Arco& a) const;
};