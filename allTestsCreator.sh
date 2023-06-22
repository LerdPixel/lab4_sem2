#!/bin/bash
HEADER=all_tests_headers.hpp
echo "#ifndef __ALL_HEADERS__" > $HEADER
echo "#define __ALL_HEADERS__" >> $HEADER
for file in tests/*.hpp
do
    echo "#include \"$file\"" >> $HEADER
done
echo "#endif" >> $HEADER
