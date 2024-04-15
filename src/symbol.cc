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

#include "symbol.h"

std::ostream& operator<<(std::ostream& out, const Symbol& symbol) {
  out << symbol.symbol_;
  return out;
}
bool Symbol::operator==(const Symbol& other_symbol) const {
  if (symbol_ == other_symbol.symbol_) {
    return true;
  } else {
    return false;
  }
}

bool Symbol::operator<(const Symbol& other_symbol) const {
  if (symbol_ == "S") {
    return true;
  } else if(other_symbol.symbol_ == "S") {
    return false;
  } else {
    return symbol_ < other_symbol.symbol_;
  }
}
