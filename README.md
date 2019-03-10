# AAL - Projekt LS łamana
*Wojciech Celej*  

## 1. Opis problemu

#### LS łamana

W układzie współrzędnych XY znajduje się n punktów. Każdy punkt ma przypisaną wagę będącą liczbą naturalną. Należy znaleźć ciąg punktów o następujących właściwościach:
(1) każdy wektor pomiędzy kolejnymi punktami z ciągu ma nieujemne składowe,
(2) łączna suma wag punktów w ciągu jest maksymalna.  
Rozważyć też przypadek, w którym pierwszy warunek jest rozluźniony w następujący sposób:
(1’) każdy wektor z wyjątkiem co najwyżej jednego pomiędzy kolejnymi punktami z ciągu ma nieujemne składowe.

## 2. Tryby wykonania programu

1. wg danych dostarczonych ze strumienia wejściowego (standardowego lub pliku) dla sekwencji konkretnych problemów; ten tryb pozwala testować poprawności dla małych instancji
1. wg danych generowanych automatycznie (losowo) z ewentualną parametryzacją generacji określaną przez użytkownika; ten tryb także służy do testowania poprawności

    Wynikiem działania w obu trybach jest plik z wartością sumy wag maksymalnej ścieżki oraz ścieżka ją realizująca.
1. wykonanie z generacją danych, pomiarem czasu i prezentacją wyników pomiarów. Wynikiem działania są 2 kolumny: 1. zawierająca rozmiar problemu, 2. zmierzony czas.

Tryb wykonania programu ustawia się wywołując program z flagą `-m`. Przykładowe wywołania:

* `./prog -m1 <points.txt >>out.txt` - powoduje uruchomienie programu w wersji wykonania nr 1 i zwrócenie wyniku do pliku `out.txt`
* `./prog -m2 -n100 >>out.txt` - powoduje uruchomienie programu w trybie 2. dla problemu o rozmiarze n=100
* `./prog -m3 -n1000 -k30 -s500 -r10` - pomiar czasu dla k=30 problemów o wielkościach n = 1000, 1500, 2000, ...; dla każdej wielkości losowanych jest r=10 instancji problemu.

    Aby wywołać program w odpowiednim trybie, trzeba podać wszystkie parametry.

## 3. Użyte struktury danych

Do realizacji algorytmu użyto struktury danych z biblioteki STL języka C++. Są to `std::map`, `std::unordered_map` i `std::vector`. Użyto również algorytmu sortowania struktury danych po wartości jednego z pól. Własne zaimplementowane struktury, które umożliwiły rozwiązanie problemu to `Point` i `Vertex`.

## 4. Algorytm

1. Uszeregowanie punktów (`Point`) względem współrzędnej x -> presortowanie.
1. Idąc z miotłą w lewo (czyli w kierunku malejących x):
   * do 1.mapy wstawiany będzie dany punkt wraz ze swoim numerem oraz wartością określającą potencjalną maksymalną ścieżkę startującą z tego punku (ozn. `rankingScore`) -> `Vertex` przechowuje tę informację; do 2.mapy wstawiany będzie numer punktu znajdującego się o jeden wyżej w mapie 1.
   * 1.mapa będzie uszeregowana malejąco według współrzędnej y -> kluczem jest wsp. y punktu, wartością obiekt `Vertex` -> konieczne użycie drzewa binarnego (`std::map`)
   * kluczem w 2.mapie jest numer punktu, wartością numer następnego punktu -> konieczne użycie hash mapy (`std::unordered_map`)
   * wstawiając punkt do 1.mapy, ustawiany jest `rankingScore` dla tego punktu jako `rankingScore` punktu wyżej w 1.mapie + waga wstawianego punktu
   * usuwane są wszystkie punkty z 1.mapy pod tym wstawionym, których `rankingScore` jest mniejszy od `rankingScore` wstawianego (każdy kolejny zamieciony punkt jeśli był przez nie zdominowany, będzie zdominowany także przez ten wstawiony)
1. Po takim przejściu otrzymuje się łączną sumę wag punktów jako v_max pierwszego punktu w 1.mapie 
Ścieżkę można odtworzyć za pomocą danych zgromadzonych w 2.mapie

## 5. Budowa projektu

1. Pliki nagłówkowe: `/include`:
    * `Types.h` - deklaracja struktur danych używanych globalnie
2. Pliki źródłowe: `/src` (każdy plik poza `main.cpp` ma swój plik nagłówkowy i implementuje jedną klasę o analogicznej nazwie)
    * `main.cpp` - obsługa wejścia/wyjścia, uruchomienie algorytmu w odpowiednim trybie
    * `MyAlgorithm.cpp` - implementacja silnika algorytmu, dostęp do wyników
    * `Point.cpp` - klasa opisująca punkt na płaszczyźnie
    * `PointsGenerator.cpp` - generator wektora `n` punktów
    * `Vertex.cpp` - klasa opisująca numer punktu i jego wartość `rankingScore`
3. Plik `CMakeLists.txt` - ustawienia budowania projektu
4. Plik `README.md` - opis projektu