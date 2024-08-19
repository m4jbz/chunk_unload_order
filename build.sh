#!/bin/sh

set -xe

clang -Wall -Wextra -o chunk_load_order chunk_load_order.c -lm
