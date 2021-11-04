#!/usr/bin/env bash


python ./cpplint/cpplint/cpplint.py --extensions=c project/* 
python ./cpplint/cpplint/cpplint.py --extensions=cpp tests/*


