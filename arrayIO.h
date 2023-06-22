#ifndef VECTOR_IO
#define VECTOR_IO
#include <iostream>
#include "stdio.h"
#include "DynamicArray.h"
#include "LinkedList.h"
#include "binarytree.hpp"


int checkInput(int *n) {
	int sres = scanf("%d", n);
	while (sres != 1) {
		if (sres == EOF)
			throw std::invalid_argument("End of file");
		if (sres != 1) {
			scanf("%*[^\n]");
			puts("Wrong integer input format\n");
		}
		sres = scanf("%d", n);
	}
	return 0;
}

int checkInput(double *n) {
	double sres = scanf("%lf", n);
	while (sres != 1) {
		if (sres == EOF)
			throw std::invalid_argument("End of file");
		if (sres != 1) {
			scanf("%*[^\n]");
			puts("Wrong double input format\n");
		}
		sres = scanf("%lf", n);
	}
	return 0;
}
int checkInput(std::string *n) {
    std::cin>>(*n);
	return 0;
}

template <typename T>
DynamicArray<T> input(size_t len) {
	T arr[len];
    int res;
	for (int i = 0; i < len; ++i) {
        printf("element %d = ", i);
        res = checkInput(&arr[i]);
        if (res == EOF) {
            throw std::invalid_argument("input interrupted");
        }
	}
	return LinkedList<T>(arr, len);
}
template <typename T> BinaryTree<T> inputBT(size_t a) {
	if (a < 0)
		throw std::length_error("lengths can't be negative");
	return BinaryTree<T>(input<T>(a));
}



#endif
