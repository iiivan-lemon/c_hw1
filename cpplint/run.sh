#!/usr/bin/env bash

set -e
set -o pipefail

python ./cpplint/cpplint/cpplint.py --extensions=c project/* 
python ./cpplint/cpplint/cpplint.py --extensions=cpp tests/*


