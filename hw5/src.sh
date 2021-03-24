#!/bin/bash


# Задача 2
# Написать скрипт который получает в качестве аргумента 3 значения, a, b,c,d

# Вывести прямоугольник на экран
# a - высота прямоугольника
# б - ширина прямоугольника
# с 0/1 - пустой или заполненный
# d - символ из которого следует рисовать

height=$1
width=$2
is_filled=$3
drawing_symbol=$4

for (( i=1; i<=$height; i++ )); do
    for (( j=1; j<=$width; j++ )); do
        if [[ $is_filled == 0 && $i > 1 && $j > 1 && $i -ne $height && $j -ne $width ]]; then
            printf " "
        else
            printf "$drawing_symbol"
        fi
    done
    printf "\n"
done;
