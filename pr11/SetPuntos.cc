// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: 
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 05/12/2023
// Archivo SetPuntos.cc: contiene la implementación de los métodos de la clase
// Contiene la implementación de los métodos de la clase SetPuntos. 

#include "SetPuntos.h"

/**
 * @brief Set the Puntos:: Set Puntos object
 * Constructor por parámetros
 * @param points parametro de tipo VectorDePuntos
 */
SetPuntos::SetPuntos(const CyA::VectorDePuntos& points) : CyA::VectorDePuntos(points), emst_() {}

/**
 * @brief Set the Puntos:: Mostrar Arbol object
 * Metodo que se encarga de mostrar el arbol por pantalla
 * @param os flujo de salida
 */
void SetPuntos::MostrarArbol(std::ostream& os) const {
  for (const CyA::Arco &arco : emst_) {
    os << arco.first << " -> " << arco.second << std::endl;
  }
  os << std::endl;
  os << "Coste: " << CalcularCoste() << std::endl;
}

/**
 * @brief Set the Puntos:: Mostrar Arbol Manhattan object
 * Funcion que imprime el arbol manhattan
 * @param os flujo de salida
 */
void SetPuntos::MostrarArbolManhattan(std::ostream& os) const {
  for (const CyA::Arco &arco : emst_) {
    os << arco.first << " -> " << arco.second << std::endl;
  }
  os << std::endl;
  os << "Coste: " << CalculaCosteManhattan() << std::endl;
}

/**
 * @brief Set the Puntos:: Mostrar object
 * Metodo que se encarga de mostrar el Set de puntos por pantalla
 * @param os flujo de salida
 */
void SetPuntos::Mostrar(std::ostream& os) const {
  MostrarArbol(os);
}

void SetPuntos::MostrarManhattan(std::ostream& os) const {
  MostrarArbolManhattan(os);
}

/**
 * @brief Método que calcula el Euclidean Minimum Spanning Tree mediante el
 * algoritmo de Kruskal
 */
void SetPuntos::EMST(void) {
  CyA::ArcosPonderados arcos_ponderados;
  // calcula el coste de los arcos ponderados y los almacena en el objeto 
  CalcularCosteArcoPonderado(arcos_ponderados);
  Bosque bosque;
  // crea un sub-árbol por cada punto
  for (const CyA::Punto &punto : *this) {
    EMST::SubArbol sub_arbol;
    sub_arbol.AgregarPunto(punto);
    bosque.emplace_back(sub_arbol);
  }
  // ordena los arcos ponderados de menor a mayor
  for (const CyA::ArcoPonderado &arco_ponderado : arcos_ponderados) {
    int i, j;
    EncontrarSubArbolIncidente(bosque, arco_ponderado.second, i, j);
    // si los sub-árboles son distintos, los fusiona
    if (i != j) {
      FusionSubArboles(bosque, arco_ponderado.second, i, j);
    }
  }
  // guarda el árbol mínimo en el objeto
  emst_ = bosque[0].GetArcos();
}

/**
 * @brief Set the Puntos:: Calcular Coste Arco Ponderado object
 * Funcion que se encarga de calcular el coste de los arcos ponderados y los almacena en el objeto
 * @param arcos_ponderados parametro de tipo ArcosPonderados
 */
void SetPuntos::CalcularCosteArcoPonderado(CyA::ArcosPonderados& arcos_ponderados) const {
  arcos_ponderados.clear();
  const int n = size();
  // calcula el coste de los arcos ponderados y los almacena en el objeto
  for (int i = 0; i < n - 1; ++i) {
    const CyA::Punto &p_i = (*this)[i];
    // calcula la distancia euclidiana entre los puntos
    for (int j = i + 1; j < n; ++j) {
      const CyA::Punto &p_j = (*this)[j];
      const double dist = DistanciaEuclidiana(std::make_pair(p_i, p_j));
      arcos_ponderados.emplace_back(std::make_pair(dist, std::make_pair(p_i, p_j)));
    }
  }
  // ordena los arcos ponderados de menor a mayor
  std::sort(arcos_ponderados.begin(), arcos_ponderados.end());
}

/**
 * @brief Set the Puntos:: Encontrar Sub Arbol Incidente object
 * Funcion que se encarga de encontrar el sub-arbol incidente especificado, es privada 
 * @param st parametro de tipo Bosque
 * @param a parametro de tipo Arco
 * @param i parametro de tipo int
 * @param j parametro de tipo int
 */
void SetPuntos::EncontrarSubArbolIncidente(const Bosque& st, const CyA::Arco& a, int& i, int& j) const {
  i = j = -1;
  // recorre el bosque
  for (int k = 0; k < st.size(); ++k) {
    // si el sub-árbol contiene el primer punto del arco
    if (st[k].Contiene(a.first)) {
      i = k;
    }
    // si el sub-árbol contiene el segundo punto del arco
    if (st[k].Contiene(a.second)) {
      j = k;
    }
    // si los dos puntos están en el mismo sub-árbol
    if (i != -1 && j != -1) {
      break;
    }
  }
}

/** 
 * @brief Set the Puntos:: Fusion Sub Arboles object
 * Funcion que se encarga de fusionar los dos sub-arboles especificados, es privada
 * @param st parametro de tipo Bosque
 * @param a parametro de tipo Arco
 * @param i parametro de tipo int
 * @param j parametro de tipo int
*/
void SetPuntos::FusionSubArboles(Bosque& st, const CyA::Arco& a, int i, int j) const {
  st[i].Fusion(st[j], std::make_pair(DistanciaEuclidiana(a), a));
  // elimina el sub-árbol que se ha fusionado
  st.erase(st.begin() + j);
}

/**
 * @brief Set the Puntos:: Calcular Coste object
 * Funcion que se encarga de calcular el coste del Set de puntos
 * @return double retorna el coste del Set de puntos
 */
double SetPuntos::CalcularCoste() const {
  double coste = 0.0;
  // calcula el coste del Set de puntos
  for (const CyA::Arco &arco : emst_) {
    coste += DistanciaEuclidiana(arco);
  }
  return coste;
}

double SetPuntos::CalculaCosteManhattan() const {
  double coste = 0.0;
  // calcula el coste del Set de puntos usando distancia Manhattan
  for (const CyA::Arco &arco : emst_) {
    coste += DistanciaManhattan(arco);
  }
  return coste;
}

/**
 * @brief Set the Puntos:: Distancia Euclidiana object
 * Funcion que se encarga de calcular la distancia euclidiana entre dos puntos
 * @param a parametro de tipo Arco
 * @return double retorna la distancia euclidiana entre dos puntos
 */
double SetPuntos::DistanciaEuclidiana(const CyA::Arco& a) const {
  // calcula la distancia euclidiana entre dos puntos
  const CyA::Punto &p_i = a.first;
  const CyA::Punto &p_j = a.second;
  const double x = p_i.first - p_j.first;
  const double y = p_i.second - p_j.second;
  return std::sqrt(x * x + y * y);
}

/**
 * @brief Set the Puntos:: Distancia Manhattan object
 * Funcion que calcula la distancia manhattan
 * @param a parametro de tipo arco
 * @return double retorna la distancia manhattan entre dos puntos
 */
double SetPuntos::DistanciaManhattan(const CyA::Arco& a) const {
  // Calcula la distancia manhattan entre dos puntos
  const CyA::Punto &p_i = a.first;
  const CyA::Punto &p_j = a.second;
  // fórmula distancia manhattan
  return std::abs(p_i.first - p_j.first) + std::abs(p_i.second - p_j.second);
}




