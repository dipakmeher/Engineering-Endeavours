#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Jul 26 16:36:07 2019

@author: lab1-pc11
"""

import numpy as np
import math as maths

x = np.array([1,2,3,4,5,6])
w =np.array([1,2,3,4,5,6])
"""
x =np.matrix(x)
w =np.matrix(w)
"""
wt = np.transpose(w);

net = np.dot(x,wt)

print("Net =", net)

if(net>0):
    print("Unipolar Threshold: 1")
elif(net<0):
    print("Unipolar Threshold: 0")
else:
    print("Its not a Unipolar Threshold")
    
print("\n")
if(net>0):
    print("Bipolar Threshold: 1")
elif(net<0):
    print("Bipolar Threshold: -1")
else:
    print("Its not a Bipolar Threshold")

print("\n")

print("we are taking lambda as l=1")    

sig= 1/(1+maths.exp(-1*net))
print("Logistic signoid",sig)

print("\n")

Tanh = ((1-maths.exp(-1*net))/(1+maths.exp(-1*net)))
print("Tanh signoid",Tanh)

print("\n")

if(net<0):
    print("Relu:0")
else:
    m=np.maximum(0,net)
    print("Relu: ",m)
    
print("\n")

e_x = np.exp(x - np.max(x))
print("Softmax function",e_x / e_x.sum())
    
    

    
    
    





    


    