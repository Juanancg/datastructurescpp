#!/bin/bash

function build() {
    g++ -c *.cpp
    g++ *.o -o queue.out
}

function run() {
    ./bin/main
}