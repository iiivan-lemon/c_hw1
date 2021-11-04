#!/usr/bin/env bash


python ./linters/cpplint/cpplint.py --extensions=c project/* 
python ./linters/cpplint/cpplint.py --extensions=cpp tests/*


