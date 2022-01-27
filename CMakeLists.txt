# CMakeList.txt: projekt CMake dla elementu baza, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.8)

project ("baza")

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (baza "baza.cpp" "baza.h" "randomgen.h"  "pojazdy.hpp")

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
