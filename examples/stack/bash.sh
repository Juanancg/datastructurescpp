#!/bin/bash

function build() {
    g++ -c *.cpp
    g++ *.o -o stack.out
}

function run() {
    ./bin/main
}