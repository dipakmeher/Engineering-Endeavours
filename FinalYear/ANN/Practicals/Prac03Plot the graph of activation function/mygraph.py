#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Aug  2 17:29:04 2019

@author: lab-1pc-15
"""

import math
from numpy import array as arr
from numpy import exp
from pprint import pprint
import matplotlib.pyplot as plt
"""
calculate exponential
"""
def nexp(x):
    return math.exp(-1*x)

def unipolar_threshold(net):
    if net>0:
        return 1
    if net<=0:
        return 0
    return None

plt.title('Unipolar threshold')
plt.plot([i for i in range(-50, 40)], [unipolar_threshold(i) for i in range(-50, 40)])
plt.show()

def bipolar_threshold(net):
    if net > 0:
        return 1
    if net < 0:
        return_val = -1
        return return_val
    return None

plt.title('Biipolar threshold')
plt.plot([i for i in range(-50, 40)], [bipolar_threshold(i) for i in range(-50, 40)])
plt.show()

def sigmoid(net):
    return 1/(1+(nexp(net)))
plt.title('sigmoid')
plt.plot([i for i in range(-50, 40)], [sigmoid(i) for i in range(-50, 40)])
plt.show()

def bipolar_sigmoid(net):
    return (1-nexp(net)) / (1+nexp(net))

plt.title('sigmoid')
plt.plot([i for i in range(-50, 40)], [sigmoid(i) for i in range(-50, 40)])
plt.show()

def relu(net):
    return max(net, 0)
plt.title('relu')
plt.plot([i for i in range(-50, 40)], [relu(i) for i in range(-50, 40)])
plt.show()

def tanh(net):
    return ((1 - math.exp(-net))/(1 + math.exp(-net)))
plt.title('tanh')
plt.plot([i for i in range(-50, 40)], [tanh(i) for i in range(-50, 40)])
plt.show()