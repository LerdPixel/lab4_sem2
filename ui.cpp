#include <iostream>
#include "arrayIO.h"
#include <vector>
#include <string>
#include "binarytree.hpp"

template <class T> void actions() {
    std::vector<BinaryTree<T> > v;
    int tempCode = 1, len, p1, p2, optionType, optionType2;
    while (tempCode) {
        try {
            std::cout << "0 - new binary tree input; 1 - insert element; 2 - treverse; 3 - find; 4 - find sub tree; 5 - get sub tree ; 6 - print; 7 - print one; 8 - removeNode ; 9 - exit" << '\n'<< '\n';
            checkInput(&optionType);
            switch (optionType) {
                case 0:
                    std::cout << "length: ";
                    checkInput(&len);
                    v.push_back(inputBT<T>(len));
                    break;
                case 4:
                    try {
                        std::cout << "Input tree index: ";
                        checkInput(&p1);
                        std::cout << "Input subtree index: ";
                        checkInput(&p2);
                        if (v.at(p1).findSubtree(v.at(p2)))
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
                                print(v.at(p1).straightLeft());
                            } catch (const std::exception &e) {
                                std::cout << e.what() << '\n';
                            }
                            break;
                        case 1:
                            try {
                                print(v.at(p1).straightRight());
                            } catch (const std::exception &e) {
                                std::cout << e.what() << '\n';
                            }
                            break;
                        case 2:
                            try {
                                print(v.at(p1).reverseLeft());
                            } catch (const std::exception &e) {
                                std::cout << e.what() << '\n';
                            }
                            break;
                        case 3:
                            try {
                                print(v.at(p1).central());
                            } catch (const std::exception &e) {
                                std::cout << e.what() << '\n';
                            }
                            break;
                        case 4:
                            try {
                                print(v.at(p1).reverseRight());
                            } catch (const std::exception &e) {
                                std::cout << e.what() << '\n';
                            }
                            break;
                        case 5:
                            try {
                                print(v.at(p1).centralRight());
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
                        if (v.at(p1).find(vall))
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
                        v.at(p1).insert(vall);
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
                        v.push_back(v.at(p1).subtree(vall));
                    }
                    catch (const std::exception &e) {
                        std::cout << e.what() << '\n';
                    }
                    break;
                case 7:
                    try{
                        std::cout << "Input tree index: ";
                        checkInput(&p1);
                        v.at(p1).print();
                    }
                    catch (const std::exception &e) {
                        std::cout << e.what() << '\n';
                    }
                    break;
                case 6:
                    try {
                        for(auto it = v.begin() ; it != v.end(); ++it) {
                            (*it).print();
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
                        v.at(p1).removeNode(vall);
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


int main(int argc, char const *argv[]) {
    int code = 1;
    try {
        int optionType, tempCode;
        std::cout << "test type: 0 - int; 1 - double; 2 - string; 3 - exit" << '\n';
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
        }
    }
    catch (const std::exception &e) {
        std::cout << e.what() << '\n';
    }
    return 0;
}
