#pragma once

#include <iostream>
#include <string>
#include <vector>

extern bool CSM_FUNNY_COMMENTS;

struct Diagnostic {
  int code;
  std::string message;
  std::string category;
  std::string comment;

  void print() {
    if (message == "") {
      return;
    }
    std::cout << category << " TS" << code << ": " << message << "\n";
    if (CSM_FUNNY_COMMENTS) {
      std::cout << "  " << comment << "\n";
    }
  }
};

extern const std::vector<Diagnostic> DIAGNOSTICS;

Diagnostic create_diagnostic(int code, std::vector<std::string> args);