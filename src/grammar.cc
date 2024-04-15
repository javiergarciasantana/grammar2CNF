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

#include "grammar.h"

Grammar::Grammar(std::ifstream& input) {
  std::string line;
  std::vector<std::string> workload;
  std::vector<Symbol> alphabets;
  int starting_symbol_pos;
  while (getline(input, line)) {
    workload.push_back(line);
  }
  for (int i = 1; i <= stoi(workload.at(0)); ++i) {
    alphabets.push_back(Symbol(workload.at(i)));
    terminal_characters_ += workload.at(i);
  }
  terminal_symbols_ = alphabets;
  alphabets.clear();
  for (int i = 0; i <= stoi(workload.at(stoi(workload.at(0)) + 1)); ++i) {
    alphabets.push_back(Symbol(workload.at(stoi(workload.at(0)) + 2 + i)));
    if (i == stoi(workload.at(stoi(workload.at(0)) + 1))) {
      starting_symbol_pos = stoi(workload.at(0)) + 2 + i;
    }
  }
  non_terminal_symbols_ = alphabets;
  starting_symbol_ = Symbol(workload.at(starting_symbol_pos));
  std::pair<Symbol, Chain> production;
  for (int i = starting_symbol_pos + 2; i <= starting_symbol_pos + 1 + stoi(workload.at(starting_symbol_pos + 1)); ++i) {
    production.first = Symbol(workload.at(i).at(0));
    //std::cout << workload.at(i).substr(5) << std::endl;
    production.second = Chain(workload.at(i).substr(5));
    productions_.push_back(production);
  }
}

Grammar Grammar::ChomskyChanger(void) {
  std::string aux;
  for(int i = 0; i < productions_.size(); ++i) {
    if (productions_.at(i).second.getChain().size() - 1 >= 2) {
      for (int j = 0; j < productions_.at(i).second.getChain().size() - 1; ++j) {
        for (int k = 0; k < terminal_characters_.size(); ++k) {
          if (productions_.at(i).second.getChain().at(j) == Symbol(terminal_characters_.at(k))){
            std::pair<Symbol, Chain> new_production;
            std::string new_production_name = {"C_" + productions_.at(i).second.getChain().at(j).getSymbol()};
            new_production.first = Symbol(new_production_name);
            new_production.second = Chain(productions_.at(i).second.getChain().at(j).getSymbol());
            productions_.push_back(new_production);
            aux += new_production_name;
          } 
          
        }
        aux += productions_.at(i).second.getChain().at(j).getSymbol();
        //std::cout << terminal_symbols_ << std::endl;
        // for (auto k = terminal_symbols_.getSymbols().begin(); k != terminal_symbols_.getSymbols().end(); ++k) {
        //   std::cout << "h";
        // }
      }
      productions_.at(i).second = Chain(aux);
      aux.clear();
    }
  }




  for (int i = 0; i < productions_.size(); ++i) {
    if (productions_.at(i).second.getChain().at(0) == Symbol("&")) {
      productions_.erase(productions_.begin() + i);
    }
    // for (int j = 0; j < productions_.size(); ++j) {
    //   if (productions_.at(i).first.getSymbol() == productions_.at(j).first.getSymbol() && productions_.at(i).second.getChain() == productions_.at(j).second.getChain()) {
    //     productions_.erase(productions_.begin() + i);
    //   }
    // }
  }
  return *this;
}

std::ostream& operator<<(std::ostream& out, const Grammar& grammar) {
  out << grammar.terminal_symbols_.getSymbols().size() << std::endl;
  out << grammar.terminal_symbols_;
  out << grammar.non_terminal_symbols_.getSymbols().size() << std::endl;
  out << grammar.non_terminal_symbols_;
  out << grammar.starting_symbol_;
  out << grammar.productions_.size() << std::endl;
  for (int i = 0; i < grammar.productions_.size(); ++i) {
    out << grammar.productions_.at(i).first << " -> ";
    //std::cout << grammar.productions_.at(i).second << std::endl;
    out << grammar.productions_.at(i).second << std::endl;
  }
  return out;
}


