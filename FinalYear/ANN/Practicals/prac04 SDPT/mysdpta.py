#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Aug  9 16:38:03 2019

@author: dala-1pc25
"""

import numpy as np
"""xi x2 x3 x4"""
dataset=[[0,0,1],[0,1,1],[1,0,1],[1,1,1]]
"""no of steps"""
k=0 
"""no of weights"""
w=[0,0,0]
"""no of input pattern xior yi"""
p=0
"""no of errors"""
E=0
op=[int(i) for i in input('Enter 4 outputs:').split()]
var = 1
c=1
while var==1:
    k = k+1
    y = dataset[p]
    d = op[p]
    weight = np.array(w)
    yp = np.array(y)
    net = np.dot(weight.T, yp)
    if net>0:
        o=1
    elif net<0:
        o=-1
    else:
        o=-d
    
    
    for i in range(len(w)):
        w[i]=w[i]+(c*(d-o)*y[i])
    
    E = E +(1/2*pow((d-o),2))
        
    p=p+1
    
    if E==0 and p == 3:
        print("Our Final Weight",w)
        print("Steps required: ",k+1)
        break
    elif p>=len(dataset):
        p=0
        E=0
    if k>1000:
        break
    
    

    
    