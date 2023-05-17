// No modifique este archivo. Este es el archivo de pruebas que se usara para corregir 
// su tarea. Cualquier cambio realizado sera penalizado con una nota de CERO.

#include "test.hpp"
#include "../tarea/foo.h"


TEST_CASE("parte1", "[Palabras]"){
    Counter C("https://norvig.com/y10k.html");
    REQUIRE(C("think") == 5);
    REQUIRE(C("bug") == 7);
    REQUIRE(C("bugs") == 1);
    REQUIRE(C("continuum") == 8);
    REQUIRE(C("novel") == 1);

    // Ranking
    REQUIRE(C("ilsa") == 30);
    REQUIRE(C("time") == 20);
    REQUIRE(C("said") == 18);
    REQUIRE(C("russell") == 16);
    REQUIRE(C("still") == 10);
}

TEST_CASE("parte2", "[Ranking]"){
    Counter C("https://norvig.com/y10k.html");
    vector<string> rank = C.ranking();

    REQUIRE(rank[0] == "ilsa");
    REQUIRE(rank[1] == "time");
    REQUIRE(rank[2] == "said");
    REQUIRE(rank[3] == "russell");
    REQUIRE(rank[4] == "still");
}


TEST_CASE("parte3", "[StopWords]"){
    Counter C("https://norvig.com/y10k.html");

    REQUIRE(C("<p>") == 0);
    REQUIRE(C("</p>") == 0);
    REQUIRE(C("http") == 0);
    REQUIRE(C("href") == 0);
    REQUIRE(C("<html>") == 0);
    REQUIRE(C("<body>") == 0);
    REQUIRE(C("</body>") == 0);
    REQUIRE(C("/") == 0);
    REQUIRE(C("//") == 0);
    REQUIRE(C("www") == 0);
}