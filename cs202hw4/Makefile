OBJS	= main.o AVLTree.o TreeNode.o
SOURCE	= main.cpp AVLTree.cpp TreeNode.cpp
HEADER	= AVLTree.h TreeNode.h
OUT	= avlfreq
CC	 = g++
FLAGS	 = -g -c
LFLAGS	 =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++11

AVLTree.o: AVLTree.cpp
	$(CC) $(FLAGS) AVLTree.cpp -std=c++11

TreeNode.o: TreeNode.cpp
	$(CC) $(FLAGS) TreeNode.cpp -std=c++11


clean:
	rm -f $(OBJS) $(OUT)