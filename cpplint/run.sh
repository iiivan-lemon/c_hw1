#!/usr/bin/env bash


python ./cpplint/cpplint.py --extensions=c project/* 
python ./cpplint/cpplint.py --extensions=cpp tests/*


