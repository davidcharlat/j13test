errorExit()
{
  echo "$1";
  exit 1;
}

USER_BUILD=$1;

# BUILD
let "n = 0"
FILE="btree_create_node"
if [ -f ./j13/ex00/$FILE.c ] && [ -f ./j13/ex00/ft_btree.h ]
then
	gcc -o z.out j13/ex00/$FILE.c $FILE.test.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	if [ $n -eq 0 ]
	then
		let "n = n + 1"
	fi
fi
FILE="btree_apply_prefix"
if [ -f ./j13/ex01/$FILE.c ] && [ -f ./j13/ex01/ft_btree.h ]
then
	echo ""
	echo "testing $FILE"
	gcc -o z.out j13/ex01/$FILE.c $FILE.test.c btree_create_node.c || errorExit "Error: compilation $FILE failed";
	OUTPUT="`./z.out`" || errorExit "Error: $FILE failed";
	EXPECTED="3 0 -4 5 3 6 5 6 "
	echo "expected $EXPECTED ; received $OUTPUT"
	if [ "$EXPECTED" = "$OUTPUT" ]
	then
		echo "OK"
		if [ $n -eq 1 ]
		then
			let "n = n + 1"
		fi
		echo "$FILE OK"
	else
		errorExit "wrong"
	fi
fi
FILE="btree_apply_infix"
if [ -f ./j13/ex02/$FILE.c ] && [ -f ./j13/ex02/ft_btree.h ]
then
	echo ""
	echo "testing $FILE"
	gcc -o z.out j13/ex02/$FILE.c $FILE.test.c btree_create_node.c || errorExit "Error: compilation $FILE failed";
	OUTPUT="`./z.out`" || errorExit "Error: $FILE failed";
	EXPECTED="-4 0 3 3 5 5 6 6 "
	echo "expected $EXPECTED ; received $OUTPUT"
	if [ "$EXPECTED" = "$OUTPUT" ]
	then
		echo "OK"
		if [ $n -eq 2 ]
		then
			let "n = n + 1"
		fi
		echo "$FILE OK"
	else
		errorExit "wrong"
	fi
fi
FILE="btree_apply_suffix"
if [ -f ./j13/ex03/$FILE.c ] && [ -f ./j13/ex03/ft_btree.h ]
then
	echo ""
	echo "testing $FILE"
	gcc -o z.out j13/ex03/$FILE.c $FILE.test.c btree_create_node.c || errorExit "Error: compilation $FILE failed";
	OUTPUT="`./z.out`" || errorExit "Error: $FILE failed";
	EXPECTED="-4 0 3 5 6 6 5 3 "
	echo "expected $EXPECTED ; received $OUTPUT"
	if [ "$EXPECTED" = "$OUTPUT" ]
	then
		echo "OK"
		if [ $n -eq 3 ]
		then
			let "n = n + 1"
		fi
		echo "$FILE OK"
	else
		errorExit "wrong"
	fi
fi
FILE="btree_insert_data"
if [ -f ./j13/ex04/$FILE.c ] && [ -f ./j13/ex04/ft_btree.h ]
then
	echo ""
	echo "testing $FILE"
	gcc -o z.out j13/ex04/$FILE.c $FILE.test.c btree_create_node.c || errorExit "Error: compilation $FILE failed";
	OUTPUT="`./z.out`" || errorExit "Error: $FILE failed";
	EXPECTED="-4 0 3 3 5 5 6 6 "
	echo "expected $EXPECTED ; received $OUTPUT"
	if [ "$EXPECTED" = "$OUTPUT" ]
	then
		echo "OK"
		if [ $n -eq 4 ]
		then
			let "n = n + 1"
		fi
		echo "$FILE OK"
	else
		errorExit "wrong"
	fi
fi
FILE="btree_search_item"
if [ -f ./j13/ex05/$FILE.c ] && [ -f ./j13/ex05/ft_btree.h ]
then
	echo ""
	echo "testing $FILE"
	gcc -o z.out j13/ex05/$FILE.c $FILE.test.c btree_create_node.c || errorExit "Error: compilation $FILE failed";
	OUTPUT="`./z.out`" || errorExit "Error: $FILE failed";
	EXPECTED="hello you 0"
	echo "expected $EXPECTED ; received $OUTPUT"
	if [ "$EXPECTED" = "$OUTPUT" ]
	then
		echo "OK"
		if [ $n -eq 5 ]
		then
			let "n = n + 1"
		fi
		echo "$FILE OK"
	else
		errorExit "wrong"
	fi
fi
FILE="btree_insert_data"
if [ -f ./j13/ex04/$FILE.c ] && [ -f ./j13/ex04/ft_btree.h ]
then
	echo ""
	echo "testing $FILE"
	gcc -o z.out j13/ex04/$FILE.c $FILE.test.c btree_create_node.c || errorExit "Error: compilation $FILE failed";
	OUTPUT="`./z.out`" || errorExit "Error: $FILE failed";
	EXPECTED="-4 0 3 3 5 5 6 6 "
	echo "expected $EXPECTED ; received $OUTPUT"
	if [ "$EXPECTED" = "$OUTPUT" ]
	then
		echo "OK"
		if [ $n -eq 4 ]
		then
			let "n = n + 1"
		fi
		echo "$FILE OK"
	else
		errorExit "wrong"
	fi
fi
FILE="btree_level_count"
if [ -f ./j13/ex06/$FILE.c ] && [ -f ./j13/ex06/ft_btree.h ]
then
	echo ""
	echo "testing $FILE"
	gcc -o z.out j13/ex06/$FILE.c $FILE.test.c btree_create_node.c || errorExit "Error: compilation $FILE failed";
	OUTPUT="`./z.out`" || errorExit "Error: $FILE failed";
	EXPECTED="0, 1, 8"
	echo "testing trees level 0 (root = NULL), 1 (root has no son) and 8 (in a middle branch)"
	echo "expected $EXPECTED ; received $OUTPUT"
	if [ "$EXPECTED" = "$OUTPUT" ]
	then
		echo "OK"
		if [ $n -eq 6 ]
		then
			let "n = n + 1"
		fi
		echo "$FILE OK"
	else
		errorExit "wrong"
	fi
fi
FILE="btree_apply_by_level"
if [ -f ./j13/ex07/$FILE.c ] && [ -f ./j13/ex07/ft_btree.h ]
then
	echo ""
	echo "testing $FILE"
	gcc -o z.out j13/ex07/$FILE.c $FILE.test.c btree_create_node.c || errorExit "Error: compilation $FILE failed";
	OUTPUT="`./z.out`" || errorExit "Error: $FILE failed";
	EXPECTED="new level
level: 0, value hello
new level
level: 1, value guy
level: 1, value hi
new level
level: 2, value are
level: 2, value how
new level
level: 3, value you
new level
level: 4, value handsome
level: 4, value yellow
new level
level: 5, value x
level: 5, value zaz
new level
level: 6, value wx
level: 6, value zz
new level
level: 7, value tre"
	echo "expected 
$EXPECTED ; 
received 
$OUTPUT"
	if [ "$EXPECTED" = "$OUTPUT" ]
	then
		echo "OK"
		if [ $n -eq 7 ]
		then
			let "n = n + 1"
		fi
		echo "$FILE OK"
	else
		errorExit "wrong"
	fi
fi

FILE="rb_insert"
if [ -f ./j13/ex08/$FILE.c ] && [ -f ./j13/ex08/ft_btree_rb.h ]
then 
	echo ""
	echo "testing $FILE"
	gcc -o z.out j13/ex08/$FILE.c $FILE.test.c || errorExit "Error: compilation $FILE failed";
	./z.out
	let "n = n + 1"
fi
echo "resultat = $n"

FILE="rb_remove"
if [ -f ./j13/ex09/$FILE.c ] && [ -f ./j13/ex09/ft_btree_rb.h ]
then 
	echo ""
	echo "testing $FILE"
	gcc -o z.out j13/ex09/$FILE.c $FILE.test.c || errorExit "Error: compilation $FILE failed";
	./z.out
	let "n = n + 1"
fi
echo "resultat = $n"
exit 0





FILE="ft_list_push_back"
if [ -f j11/ex01/$FILE.c ] && [ -f j11/ex01/ft_list.h ]
then
	gcc -o z.out j11/ex01/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_push_front"
if [ -f j11/ex02/$FILE.c ] && [ -f j11/ex02/ft_list.h ]
then
	gcc -o z.out j11/ex02/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_size"
if [ -f j11/ex03/$FILE.c ] && [ -f j11/ex03/ft_list.h ]
then
	gcc -o z.out j11/ex03/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_last"
if [ -f j11/ex04/$FILE.c ] && [ -f j11/ex04/ft_list.h ]
then
	gcc -o z.out j11/ex04/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_push_params"
if [ -f j11/ex05/$FILE.c ] && [ -f j11/ex05/ft_list.h ]
then
	gcc -o z.out j11/ex05/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out hello good bye || errorExit "Error: $FILE with 'hello', 'good' and 'bye' as args failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_clear"
if [ -f j11/ex06/$FILE.c ] && [ -f j11/ex06/ft_list.h ]
then
	gcc -o z.out j11/ex06/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_at"
if [ -f j11/ex07/$FILE.c ] && [ -f j11/ex07/ft_list.h ]
then
	gcc -o z.out j11/ex07/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_reverse"
if [ -f j11/ex08/$FILE.c ] && [ -f j11/ex08/ft_list.h ]
then
	gcc -o z.out j11/ex08/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_foreach"
if [ -f j11/ex09/$FILE.c ] && [ -f j11/ex09/ft_list.h ]
then
	gcc -o z.out j11/ex09/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_foreach_if"
if [ -f j11/ex10/$FILE.c ] && [ -f j11/ex10/ft_list.h ]
then
	gcc -o z.out j11/ex10/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_find"
if [ -f j11/ex11/$FILE.c ] && [ -f j11/ex11/ft_list.h ]
then
	gcc -o z.out j11/ex11/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_remove_if"
if [ -f j11/ex12/$FILE.c ] && [ -f j11/ex12/ft_list.h ]
then
	gcc -o z.out j11/ex12/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_merge"
if [ -f j11/ex13/$FILE.c ] && [ -f j11/ex13/ft_list.h ]
then
	gcc -o z.out j11/ex13/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_sort"
if [ -f j11/ex14/$FILE.c ] && [ -f j11/ex14/ft_list.h ]
then
	gcc -o z.out j11/ex14/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_reverse_fun"
if [ -f j11/ex15/$FILE.c ] && [ -f j11/ex15/ft_list.h ]
then
	gcc -o z.out j11/ex15/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_sorted_list_insert"
if [ -f j11/ex16/$FILE.c ] && [ -f j11/ex16/ft_list.h ]
then
	gcc -o z.out j11/ex16/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_sorted_list_merge"
if [ -f j11/ex17/$FILE.c ] && [ -f j11/ex17/ft_list.h ]
then
	gcc -o z.out j11/ex17/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
rm z.out
echo "resultat = $n"
