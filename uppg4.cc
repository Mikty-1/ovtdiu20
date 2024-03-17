// Given kod för uppgift 4 - Eko-värden
#include <iostream>

// Du kan ändra includes för att passa ditt val av filnamn, men tänk på
// att inkludera två gånger så att du kontrollerar att din include
// guard fungerar som den ska
// Du kan ha både Eko_Index och Forest_Report i samma *.h resp *.cc fil
#include "eko_index_forest_report.h"

// OBS! Ändringar av koden nedan kan leda till Komplettering
// Det ingår i uppgiften att skriva klasserna så att huvudprogrammet fungerar

// Om denna include orsakar bekymmer kommenterar du ut den
#include "check_disabled_copy.h"

int main()
{
  Eko_Index basic_eko_values {
    "torraka",
      "murken",
      "ihålig",
      "ek",
      "bok",
      "skadad",
      "gammal",
      "död",
      "fallen"
  };

  // Denna rad kommer att skriva ut "OK" om din lösning är korrekt
  // Raden kontrollerar om ditt Eko_Index kan kopieras (det ska inte gå att kopiera)
  // Om raden orsakar bekymmer kommenterar du ut den
  check_disabled_copy(basic_eko_values, 0, 0);
  
  Forest_Report report1{ basic_eko_values, "Mulleskogen" };
  report1.add_tree_values("ihålig torraka");
  report1.add_tree_values("fallen gammal ek");
  report1.add_tree_values("skadad bok");
  report1.add_tree_values("ek");
  report1.add_tree_values("död gran");
  report1.add_tree_values("stor frisk tall");
  report1.add_tree_values("murken fallen asp");

  Forest_Report report2{ basic_eko_values, "Tiveden" };
  report2.add_tree_values("gammal torraka");
  report2.add_tree_values("fallen gammal bok");
  report2.add_tree_values("skadad ek");
  report2.add_tree_values("stor gammal ihålig murken död ek");
  report2.add_tree_values("frisk gran");
  report2.add_tree_values("hopplös liten en");
  report2.add_tree_values("fallen ängel");
  report2.add_tree_values("rund mullig björn");

  std::cout << report1.get_forest_name() << ": " << report1.get_forest_eko_value() << std::endl;
  std::cout << report2.get_forest_name() << ": " << report2.get_forest_eko_value() << std::endl;
  
  return 0;
}
