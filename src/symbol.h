// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia // Curso: 2o
// Practica 8: Grammar2CNF
// Autor: Javier Garcia Santana
// Correo: alu0101391663@ull.edu.es
// Fecha: 20/11/2022
//
// Archivo cya-P08-grammar2CNF: Programa cliente
//
// Historial de revisiones
// 20/11/2022 - Creacion (primera version) del codigo

#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Symbol {
 public:
  Symbol() { //Constructor por defecto
    //std::cout << "Ejecutando el constructor de simbolos por defecto..." << "\n";
    symbol_.clear(); 
  } 
  Symbol(const std::string& symbol) : symbol_{symbol} { //Constructor por string
    //std::cout << "Ejecutando el constructor de simbolos por string..." << "\n";
  } 
  Symbol(const char character) : symbol_{character} { //Constructor por char
    //std::cout << "Ejecutando el constructor de simbolos por char..." << "\n";
  } 
  //Sobrecarga del poperador de extraccion
  friend std::ostream& operator<<(std::ostream& out, const Symbol& symbol);
  bool operator==(const Symbol& other_symbol) const;
  bool operator<(const Symbol& other_symbol) const;

  //Getter
  std::string getSymbol() const { return symbol_; }

 private:
  std::string symbol_;
};

#endif  //SYMBOL_H