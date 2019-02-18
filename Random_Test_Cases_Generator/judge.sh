# para encontrar un caso que no cumple, dejar correr en un bucle infinito
# for((i = 1; ; i++)); do
((testCases = 100))
((count = 0))
for((i = 1; i <= testCases; i++)); do
	# imprimo el numero de test case
	echo "Running on test ${i}"
	# corro el generador de test case y lo guardo en el archivo int
	./gen $i > in
	# guardo el resultado del codigo que da AC
	./a < in > out1
	# guardo el resultado del codigo que quiero evaluar
	./b < in > out2
	# diff compara 2 archivos
	# si hay alguna diferencia, retorna cero
	# -w es permisivo con los saltos de linea al final del archivo
	diff -w out1 out2 || break
	((count++))
done

if [ $count -eq $testCases ]
then
	echo "Accepted"
else
	((count++))
	echo "Wrong Answer on test ${count}"
fi
date
# asimismo, se puede comparar directamente
# echo $i
# ./gen $i > int
# diff -w <(./a < int) <(./b < int) || break
# He subido 3 codigos a.cpp, b.cpp y c.cpp
# a y b dan AC en codeforces, mientras que c da WA