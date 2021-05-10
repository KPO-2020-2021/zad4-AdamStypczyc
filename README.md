## Podsumowanie mojej pracy
Aby wykonać to zadanie musiałem przede wszystkim przerobić wersję obrotów 2D na szablony oraz odpowiednie funkcje do wektora i macierzy, aby umożliwić obroty 3D. Również zamiast klasy Prostokąt jest klasa Prostopadłościan. Niektóre metody można by skrócić, lecz przy pisaniu programu miałem "zaćmienie" i o tym zapomniałem, a późniejsze przerabianie programu uznałem za bezsensowne, ponieważ nie zmieni to działania programu. Program kompiluje się w folderze build komenda make,  a program uruchamia się poprzez wpisanie w konsoli ./main. Testy uruchamia sie poprzez wpisanie ./unit_tests. Warto wspomnieć, że wyświetlanie w gnuplocie jest widoczne na osiach OX i OY na przedziałach od [-350;350], a na osi OZ na przedziale [-200;200] gdy poda się wartości spoza tego przedziału gnuplot nie połączy punktów, może sie również tak zdarzyć, że w wyniku obracania punkty wyjdą poza przedziały, wtedy też punkty nie zostana połączone. Przydatna jest wtedy opcja skali, która umożliwia zmniejszenie prostopadłościanu. Nie do końca również rozumiałem potrzebę istnienia struktury Scena i nie jestem do końca pewny czy poprawnie to zrobiłem.  Dokumentację wygenerowałem za pomocą doxywizarda i jest ona zamieszczona w folderze dox.
## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Requirements: 

Example:

``` bash
> mkdir build && cd build
> cmake .. # options: -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release], Debug is default
> make
> ./main
> make test      # Makes and runs the tests.
> make coverage  # Generate a coverage report.
> make doc       # Generate html documentation.
```


