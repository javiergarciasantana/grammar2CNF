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

#include <fstream>
#include <vector>

#include "alphabet.h"

Alphabet::Alphabet() {
  //std::cout << "Ejecutando el constructor de alfabetos por defecto..." << "\n";
  symbols_.clear();
}

Alphabet::Alphabet(const std::vector<Symbol>& input){
  //std::cout << "Ejecutando el constructor de alfabetos por parametro..." << "\n";
   std::string empty_chain_symbol = "&";
   empty_chain_symbol_ = empty_chain_symbol;
  for (int i = 0; i < input.size(); ++i) {
    if (input[i] == empty_chain_symbol_) {
      ++i;
    } else {
      symbols_.insert(input[i]);
    }
  }
}

std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet) {
  for (auto i = alphabet.symbols_.begin(); i != alphabet.symbols_.end(); ++i) {
    out << *i;
  }
  return out;
}
Alphabet Alphabet::operator+(const Alphabet& alphabet) {
  Alphabet result;
  if (symbols_.empty()) {
    result.symbols_ = alphabet.symbols_;
    return result;
  } else if (alphabet.symbols_.empty()) {
    result.symbols_ = symbols_;
    return result;
  } else {
    result.symbols_ = symbols_;
    for (auto i = alphabet.symbols_.begin(); i != alphabet.symbols_.end(); ++i) {
      result.symbols_.insert(*i);
    }
    return result;
  }
}

bool Alphabet::operator==(const Alphabet& alphabet_1) {
  for (auto i = alphabet_1.symbols_.begin(); i != alphabet_1.symbols_.end(); ++i) {
    for (auto j = symbols_.begin(); j != symbols_.end(); ++j) {
      if (*i == *j) {
        return true;
      }
    }
  }
  return false;
}

 bool Alphabet::belongs(Symbol symbol) { 
  for (auto j = symbols_.begin(); j != symbols_.end(); ++j) {
    Symbol temp = *j;
    std::cout << symbol.getSymbol() << " " << temp.getSymbol() << std::endl;
    
    if (symbol.getSymbol() == temp.getSymbol()) {
      std::cout << "h";
      return true;
    }
  }
     
  return false;
 }