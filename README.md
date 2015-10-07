# Aufgabenbeschreibung

## Aufgabe a

Benötigte Dateien:

src/Expression.h (Produktivcode)
main.cpp (zur Erstellung von Tests)

In der ersten Aufgabe müssen die Studenten die Operatoren für die Klasse IntExpression testgetrieben entwickeln. Zudem sollte auch die toString Funktion implementiert werden. Wichtig ist der vollständige Ablauf mehrerer TDD-Iterationen (immer nach Phase drei fragen, dem Refactoring, auch wenn dieses nicht immer möglich ist!!!). Begonnen wird bei den Vergleichsoperatoren, welche einen leichten Einstieg bieten sollten. 

Anschließend sollen Tests für die arithmetischen Operation geschrieben werden, welche durch die korrekte Implementierung direkt erfüllt werden. Nachdem diese implementiert sind, kann in einem Refactoring Schritt mithilfe eines Makros weitere Codeduplizierung entfernt werden. 

Abschließend kann toString getestet werden und auf std::to_string delegieren. Dies zeigt auch nochmal einen sogenannten "Library Test", bei welchen die Funktion von fremd-APIs sicher gestellt wird (auch wenn es sich hierbei um die STL handelt).
