Цели и задачи работы: изучение рекурсивного программирования, методов разработки эффективных алгоритмов.
Методика выполнения работы:
1.	Изучить технологию использования стека при рекурсивном программировании.
2.	Написать рекурсивную программу решения поставленной задачи.
3.	Протестировать программу.
Требования к отчету: отчет по лабораторной работе должен содержать титульный лист, задание, исходный текст программы, тесты. 
Задание №1 «Фракталы»
Теоретическая часть
Фрактал – это объект или величина, демонстрирующие самоподобие (в формальном смысле) в любых масштабах. Объект демонстрирует при разных масштабах не идентичные структуры, но на всех уровнях фрактала должны проявляться структуры одного и того же «типа». В таком случае график, откладываемый в системе координат с логарифмическим масштабом, где по осям отсчитываются величина и масштаб, то график представляет собой прямую линию с наклоном, отражающим размерность фрактала. Иными словами, фрактал – это геометрическая фигура, демонстрирующая одни и те же свойства независимо от степени увеличения.
Вариант 1:
Дерево Пифагора. Процесс его построения выглядит следующим образом:
1.	Строится квадрат.
2.	На верхней стороне квадрата строится равнобедренный прямоугольный треугольник, гипотенузой которого является сторона исходного квадрата.
3.	На основе полученных катетов треугольника строятся два новых квадрата («Пифагоровы штаны»). 
4.	Повторить шаги 1-3 для каждого из двух получившихся квадратов.
Задание №2
Вариант 10: 
Для заданной строки expression чисел и операторов вернуть все возможные результаты вычисления всех возможных способов группировки чисел и операторов. Вы можете вернуть ответ в любом порядке. 
Ограничения: 
- 1 <= expression.length <= 20.
- expression состоит из цифр и оператора '+', '-', и '*'.
- Все целые значения во входном выражении находятся в диапазоне [0, 99]. 
Пример 1
Ввод: выражение = "2-1-1"
Вывод: [0,2] 
Объяснение:
((2-1)-1) = 0
(2-(1-1)) = 2
Пример 2
Ввод: выражение = "2*3-4*5"
Вывод: [-34,-14,-10,-10,10]
Объяснение:
(2 * (3 - (4 * 5))) = -34
((2 * 3) - (4 * 5)) = -14
((2 * (3 - 4)) * 5) = -10
(2 * ((3 - 4) * 5)) = -10
(((2 * 3) - 4) * 5) = 10
Задание №3
Вариант 4:
На веревке висят прямоугольные скатерти и салфетки так, что они занимают всю веревку. Один предмет был украден. Можно ли перевесить оставшиеся предметы так, чтобы веревка снова стала занятой полностью? Длина веревки, количество предметов и размеры каждого предмета известны.


Структура проекта: CPP1.cpp/Python1.py - выполнение первого индивидуального задания на языке C++/Python (с остальными аналогично).
