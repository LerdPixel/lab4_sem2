#include <iostream>
#include "arrayIO.h"
#include "LinkedList.h"
#include <string>
#include <chrono>
#include <cstdlib>
#include "binarytree.hpp"

using namespace std;

template <class T> void actions() {
    LinkedList<BinaryTree<T> > v;
    int tempCode = 1, len, p1, p2, optionType, optionType2;
    while (tempCode) {
        try {
            std::cout << "0 - new binary tree input; 1 - insert element; 2 - treverse; 3 - find; 4 - find sub tree; 5 - get sub tree ; 6 - print; 7 - print one; 8 - removeNode ; 9 - exit" << '\n'<< '\n';
            checkInput(&optionType);
            switch (optionType) {
                case 0:
                    std::cout << "length: ";
                    checkInput(&len);
                    v.Append(inputBT<T>(len));
                    break;
                case 4:
                    try {
                        std::cout << "Input tree index: ";
                        checkInput(&p1);
                        std::cout << "Input subtree index: ";
                        checkInput(&p2);
                        if (v[p1].findSubtree(v[p2]))
                            std::cout << "found" << '\n';
                        else
                            std::cout << "not found" << '\n';
                    }
                    catch (const std::exception &e) {
                        std::cout << e.what() << '\n';
                    }
                    break;
                case 2:
                    std::cout << " 0 - KLP;\n 1 - KPL;\n 2 - LPK;\n 3 - LKP;\n 4 - PLK;\n 5 - PKL;\n" << '\n';
                    checkInput(&optionType2);
                    std::cout << "Input tree index: ";
                    checkInput(&p1);
                    switch (optionType2) {
                        case 0:
                            try {
                                print(v[p1].straightLeft());
                            } catch (const std::exception &e) {
                                std::cout << e.what() << '\n';
                            }
                            break;
                        case 1:
                            try {
                                print(v[p1].straightRight());
                            } catch (const std::exception &e) {
                                std::cout << e.what() << '\n';
                            }
                            break;
                        case 2:
                            try {
                                print(v[p1].reverseLeft());
                            } catch (const std::exception &e) {
                                std::cout << e.what() << '\n';
                            }
                            break;
                        case 3:
                            try {
                                print(v[p1].central());
                            } catch (const std::exception &e) {
                                std::cout << e.what() << '\n';
                            }
                            break;
                        case 4:
                            try {
                                print(v[p1].reverseRight());
                            } catch (const std::exception &e) {
                                std::cout << e.what() << '\n';
                            }
                            break;
                        case 5:
                            try {
                                print(v[p1].centralRight());
                            } catch (const std::exception &e) {
                                std::cout << e.what() << '\n';
                            }
                            break;
                    }
                    break;
                case 3:
                    try {
                        std::cout << "Input tree index: ";
                        checkInput(&p1);
                        T vall;
                        std::cout << "Input value: ";
                        checkInput(&vall);
                        if (v[p1].find(vall))
                            std::cout << "found" << '\n';
                        else
                            std::cout << "not found" << '\n';
                    }
                    catch (const std::exception &e) {
                        std::cout << e.what() << '\n';
                    }
                    break;
                case 1:
                    try {
                        std::cout << "Input tree index: ";
                        checkInput(&p1);
                        T vall;
                        std::cout << "Input value: ";
                        checkInput(&vall);
                        v[p1].insert(vall);
                    }
                    catch (const std::exception &e) {
                        std::cout << e.what() << '\n';
                    }
                    break;
                case 5:
                    try {
                        std::cout << "Input tree index: ";
                        checkInput(&p1);
                        T vall;
                        std::cout << "Input value: ";
                        checkInput(&vall);
                        v.Append(v[p1].subtree(vall));
                    }
                    catch (const std::exception &e) {
                        std::cout << e.what() << '\n';
                    }
                    break;
                case 7:
                    try{
                        std::cout << "Input tree index: ";
                        checkInput(&p1);
                        v[p1].print();
                    }
                    catch (const std::exception &e) {
                        std::cout << e.what() << '\n';
                    }
                    break;
                case 6:
                    try {
                        for(int i = 0; i < v.GetLength(); ++i) {
                            v[i].print();
                        }
                    }
                    catch (const std::exception &e) {
                        std::cout << e.what() << '\n';
                    }
                    break;
                case 8:
                    try {
                        std::cout << "Input tree index: ";
                        checkInput(&p1);
                        T vall;
                        std::cout << "Input value: ";
                        checkInput(&vall);
                        v[p1].removeNode(vall);
                    }
                    catch (const std::exception &e) {
                        std::cout << e.what() << '\n';
                    }
                    break;
                case 9:
                    tempCode = 0;
                    break;
            }
        }
        catch (const std::exception &e) {
            std::cout << e.what() << '\n';
            tempCode = 0;
        }
    }
}



void diagrams(int n) {
    BinaryTree<int> tree;
    LinkedList<int> list;
    srand((unsigned) time(NULL));
    for(int i = 0; i < n; i++) {
        int random = (rand() % 1000001);
        if (random % 3 == 0)
            list.Prepend(random);
        tree.insert(random);
    }
    auto start = std::chrono::high_resolution_clock::now();
    int x;
    int i = 0;
    try {
        while (i < 500) {
            ++i;
            int x = list.PopBack();
            tree.find(x);
        }
    } catch(exception& e) {}
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time taken by find " << n << " nums : " << duration.count() << " microseconds" << endl;
}

int main(int argc, char const *argv[]) {
    int code = 1;
    try {
        int optionType, tempCode;
        std::cout << "test type: 0 - int; 1 - double; 2 - string; 3 - exit; 4 - time diagram;" << '\n';
        checkInput(&optionType);
        switch (optionType) {
            case 0:
                actions<int>();
            break;
            case 1:
                actions<double>();
            break;
            case 2:
                actions<std::string>();
            break;
            case 3:
            break;
            case 4:
                for (int i = 1000; i < 1050001; i *= 2) {
                    diagrams(i);
                }
            break;
        }
    }
    catch (const std::exception &e) {
        std::cout << e.what() << '\n';
    }
    return 0;
}
