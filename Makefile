all: shortest-path navigator

shortest-path:
	gcc -o map.c shortest-path.c -o shortest-path

navigator:
	gcc -o map.c navigator.c -o navigator
