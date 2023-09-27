// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con cadenas
// Autor: Alba Pérez Rodríguez
// Correo: alu0101513768@ull.edu.es
// Fecha: 22/09/2023
// Archivo Cliente.cc:
// Contiene la función principal main donde se abre el fichero de entrada y
// segun el opcode que se haya introducido se realiza una operacion u otra.
// Están las funciones de longitud alfabeto, inversa de una cadena, prefijo,
// sufijos y subcadena de esta También encontramos la función de uso Usage que
// imprime un pequeño mensaje si no se introducen los parámetros correctos por
// linea de comando. Si se solicita la opcion --help esta mostrará como debe
// ejecutar el programa y se desplegará una breve descripcion sobre el programa
// Historial de revisiones:
// 22/09/23 - Creación (primera versión) del código. Creación de la función usage y clases
// 23/09/23 - Realización de la implementacion de los metodos de las
// clases, asi como las funciones de inversa y longitud. Implementacion
// del main para poder ir probando si funciona 
// 24/09/23 - Realización de las funciones Sufijo y prefijo de la clase cadena
// 25/09/23 - Correción de errores y finalización del main para correcto funcionamiento.
// Finalización de toda la correcta identacion y comentarios./*+

#include <iostream>
#include <sstream>

#include "Alfabeto.h"
#include "Cadena.h"
#include "Lenguaje.h"
#include "Simbolo.h"

/**
 * @brief Función que muestra el funcionamiento del programa si no se realiza de
 * forma correcta
 * @param argc cantidad de argumentos pasados al programa desde la línea de
 * comandos, incluyendo el nombre del propio programa como el primer argumento.
 * @param argv posicion de los argumentos pasados al programa.
 */
void Usage(int argc, char* argv[]) {
  if (argc == 1 || (argc == 2 && std::string(argv[1]) == "--help")) {
    std::cout << "Modo de empleo: " << argv[0] << " filein.txt fileout.txt opcode" << std::endl;
    if (argc == 1) {
      std::cout << "Pruebe con '" << argv[0] << " --help' para más información" << std::endl;
    } else {
      std::cout << "Funcionalidades del programa:" << std::endl;
      std::cout << "El fichero de entrada tendrá en cada línea la especificación de una cadena de entrada" << std::endl;
      std::cout << "Por ejemplo: abbab" << std::endl;
      std::cout << "En función del opcode introducido se imprimirán en otro fichero lo siguiente sobre la cadena: " << std::endl;
      std::cout << "1. Alfabeto: escribir en el fichero de salida el alfabeto asociado a cada una de las cadenas de entrada." << std::endl;
      std::cout << "2. Longitud: escribir en el fichero de salida la longitud de cada cadena de entrada." << std::endl;
      std::cout << "3. Inversa: escribir en el fichero de salida la inversa de cada cadena de entrada." << std::endl;
      std::cout << "4. Prefijos: escribir en el fichero de salida el conjunto de cadenas que son prefijos de la cadena de entrada correspondiente." << std::endl;
      std::cout << "5. Sufijos: escribir en el fichero de salida el conjunto de cadenas que son sufijos de la cadena de entrada correspondiente." << std::endl;
    }
    exit(EXIT_SUCCESS);
  } else if (argc != 4) {
    std::cout << "Pruebe con '" << argv[0] << " --help' para más información" << std::endl;
    exit(EXIT_FAILURE);
  }
}

/**
 * @brief Función principal main
 * @param argc cantidad de argumentos pasados al programa desde linea de comando
 * @param argv posicion de los argumentos pasados al programa
 * @return int devuelve 0 si el programa se ejecuto con exito
 */
int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::string fichero_entrada = argv[1], fichero_salida = argv[2];
  std::ifstream entrada;
  std::ofstream salida;
  salida.open(fichero_salida.c_str(), std::ios_base::out);  // Abre el fichero de salida que se le pasa por linea de comandos
  entrada.open(fichero_entrada.c_str(), std::fstream::in);  // Abre el fichero que se pasa por linea de comandos
  std::string linea;
  int opcion = std::stoi(argv[3]);
  switch (opcion) {
    case 1: {
      // Escribir el alfabeto asociado
      while (!entrada.eof()) {
        std::getline(entrada, linea);
        salida << Alfabeto(linea) << std::endl;
      }
      break;
    }
    case 2: {  // longitud de una cadena
      while (!entrada.eof()) {
        std::getline(entrada, linea);
        Cadena cadena{linea};
        salida << cadena.Longitud() << std::endl;
      }
      break;
    }
    case 3: {
      // Inversa de la cadena de entrada
      while (!entrada.eof()) {
        std::getline(entrada, linea);
        Cadena cadena{linea};
        salida << cadena.Inversa() << std::endl;
      }
      break;
    }
    case 4: {
      // prefijos de la cadena de entrada correspondiente
      while (!entrada.eof()) {
        std::getline(entrada, linea);
        Cadena cadena{linea};
        salida << cadena.Prefijos() << std::endl;
      }
      break;
    }
    case 5: {
      // Sufijos de la cadena de entrada correspondiente
      while (!entrada.eof()) {
        std::getline(entrada, linea);
        Cadena cadena{linea};
        salida << cadena.Sufijos() << std::endl;
      }
      break;
    }
    default:
      break; // salida 
  }
  return 0;
}