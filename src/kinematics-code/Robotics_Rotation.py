# -*- coding: utf-8 -*-
"""
Created on Sat Jun 30 16:28:58 2018

@author: Witenberg
"""

import numpy as np

#%%
T1 = 0 #Theta 1 angle in degrees
T2 = 0 #Theta 2 angle in degrees
T3 = 0 #Theta 3 angle in degrees
T4 = 0 #Theta 4 angle in degrees
T5 = 0 #Theta 5 angle in degrees
T6 = 0 #Theta 6 angle in degrees

T1 = (T1/180.0)*np.pi #Theta 1 angle in radians
T2 = (T2/180.0)*np.pi #Theta 1 angle in radians
T3 = (T3/180.0)*np.pi #Theta 1 angle in radians
T4 = (T4/180.0)*np.pi #Theta 1 angle in radians
T5 = (T5/180.0)*np.pi #Theta 1 angle in radians
T6 = (T6/180.0)*np.pi #Theta 1 angle in radians

#%%

R0_1 = [[np.cos(T1),0,np.sin(T1)],
        [np.sin(T1),0,-np.cos(T1)],
        [0,1,0]]

R1_2 = [[-np.sin(T2),0,np.cos(T2)],
        [np.cos(T2),0,np.sin(T2)],
        [0,1,0]]

R2_3 = [[1,0,0],
        [0,1,0],
        [0,0,1]]

R3_4 = [[np.cos(T4),0,-np.sin(T4)],
        [np.sin(T4),0,np.cos(T4)],
        [0,-1,0]]

R4_5 = [[np.cos(T5),0,np.sin(T5)],
        [np.sin(T5),0,-np.cos(T5)],
        [0,1,0]]

R5_6 = [[np.cos(T6),-np.sin(T6),0],
        [np.sin(T6),np.cos(T6),0],
        [0,0,1]]

#%%
R0_2 = np.dot(R0_1,R1_2)
R2_4 = np.dot(R2_3,R3_4)
R4_6 = np.dot(R4_5,R5_6)

R0_4 = np.dot(R0_2,R2_4)
R0_6 = np.dot(R0_4,R4_6)


#%%
print('\nR0_1 = ')
print(np.matrix(R0_1))

print('\nR1_2 = ')
print(np.matrix(R1_2))

print('\nR2_3 = ')
print(np.matrix(R2_3))

print('\nR3_4 = ')
print(np.matrix(R3_4))

print('\nR4_5 = ')
print(np.matrix(R4_5))

print('\nR5_6 = ')
print(np.matrix(R5_6))

print('\nR0_ 6 = ')
print(np.matrix(R0_6))