# He subido 3 codigos a.cpp, b.cpp y c.cpp
# a y b dan AC en codeforces, mientras que c da WA
echo "Compiling gen.cpp"
g++ gen.cpp -o gen
echo "Compiling a.cpp"
g++ a.cpp -o a
echo "Compiling b.cpp"
g++ b.cpp -o b
#echo "Compiling c.cpp"
#g++ c.cpp -o c

# para encontrar un caso que no cumple, dejar correr en un bucle infinito
# for((i = 1; ; i++)); do
((testCases = 100))
((count = 0))
for((i = 1; i <= testCases; i++)); do
	# imprimo el numero de test case
	echo "Running on test ${i}"
	# corro el generador de test case y lo guardo en el archivo int
	./gen $i > test
	# guardo el resultado del codigo que da AC
	./a < test > out1
	# guardo el resultado del codigo que quiero evaluar
	./b < test > out2
	#./c < test > out2
	# diff compara 2 archivos
	# si hay alguna diferencia, retorna cero
	# -w es permisivo con los saltos de linea al final del archivo
	diff -w out1 out2 || break
	# asimismo, se puede comparar directamente
	# echo $i
	# ./gen $i > int
	# diff -w <(./a < int) <(./b < int) || break
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
rm gen a b test out1 out2