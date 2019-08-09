#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Aug  9 17:50:28 2019

@author: dala-1pc25
"""

import numpy as np
import math
"""xi x2 x3 x4"""
dataset=[[0,0,1],[0,1,1],[1,0,1],[1,1,1]]

op=[int(i) for i in input('Enter 4 outputs:').split()]

lambda1=1
eta=1
maxerror=0.001
"""no of weights"""
w=[0,0,0]
"""no of steps"""
k=0
p=0
"""no of errors"""
E=0

var=1
while var==1:
    k+=1
    y=dataset[p]
    d=op[p]
    weight=np.array(w)
    yp=np.array(y)
    net=np.dot(weight.T,yp)
    o=(1-math.exp(-lambda1*net))/(1+math.exp(-lambda1*net))
    for i in range(len(w)):
        w[i]=w[i]+(eta*(d-o)*(1-(o*o))*y[i])/2
        
    E=E+(1/2*pow((d-o),2))

    
    p+=1
    
    if p==3 and E<maxerror:
        print("Our Final Weight",w)
        print("Steps required: ",k+1)
        break
    elif p>=len(dataset):
        p=0
        E=0
