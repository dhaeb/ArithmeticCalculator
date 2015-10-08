# Aufgabenbeschreibung

Refactoring (Fokus auf TDD Phase drei)

## Aufgabe b

Benötigte Dateien:

src/Expression.h (Produktivcode)
main.cpp (Testcode)

Wenn dies nicht bereits bei Aufgabe eins geschehen ist, müssen die Tests in main.cpp aktiviert werden werden. 
Dies kann ganz einfach durchgeführt werden, wenn beim Build das Flag **RUN_OTHER_TESTS** gesetzt wird. 
Alternativ kann die bedingte Kompilierung ganz entfernt werden, indem das ```#ifdef RUN_OTHER_TESTS``` mit dem zugehörigen ```#endif``` Makro gelöscht wird. 
Damit wird bei fehlerfreiem Durchlauf der Testsuite sicher gestellt, dass das Programm wie gewünscht funktioniert (Phase eins und zwei von TDD). 

In dieser Aufgabe sollen die Studenten die Duplikation in Expression.h erkennen und refaktorisieren. 
Dies entspricht der Beachtung der Phase drei von TDD. 
Dazu sollte am Besten ein Makro Verwendung finden.
An dieser Stelle sollte aus Aufgabenteil a schon bekannt sein, wie Makrofunktionen dazu verwendet werden können.

Die Verwendung des Makros könnte so aussehen:
```cpp
	BioperatorArithmeticTemplate(Addition, +)
```

Falls die Tests bestanden werden und die Codeduplikation entfernt wurde, ist die Aufgabe erfüllt.
