#!/bin/bash

function build() {
    g++ -c *.cpp
    g++ *.o -o vector.out
}

function run() {
    ./bin/main
}