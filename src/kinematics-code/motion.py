# -*- coding: utf-8 -*-
"""
Created on Mon May  6 20:58:36 2019

@author: Witenberg
"""

# -*- coding: utf-8 -*-
"""
Created on Sat Jun 30 16:28:58 2018

@author: Witenberg
"""
#%%
import numpy as np
from matplotlib import pyplot as plt

#%%
delta = 0.01;
def tgr(x):
        tgr_val = 1- 2 * np.arccos((1-delta) * np.sin(2 * np.pi * x))/np.pi
        return tgr_val

def sqr(x):
    sqr_val = 2 * np.arctan(np.sin(2 * np.pi * x)/delta)/np.pi
    return sqr_val

def swt(x):
    swt_val = (1+ tgr((2 * x -1)/4) * sqr(x/2)/2)
    return swt_val


#%%    ##################            LEGS            ##########################
    

#%% Link lengths

a1 = 49.5 #link a1 in mm
a2 = 74.5 #link a2 in mm
a3 = 88.4 #link a3 in mm
a4 = 42.3 #link a4 in mm

x =[]
y=[]
z=[]
#%%
raio = 30.0;
delay = 40;
taxaMax = 8.0;
taxaMin = 4.0;
meio = 90.0;
taxaRef = 1.0;
difTaxaMaxMin = taxaMax-taxaMin;
taxaDifRaio = raio/(2*difTaxaMaxMin);

anguloCoxa = meio;
anguloJoelho = meio-raio;
anguloTornozelo = meio;

taxaC = -taxaMin;
taxaJ = taxaMax;
taxaT = -taxaMin;

anguloTaxaC = anguloCoxa;
anguloTaxaJ = anguloJoelho;
anguloTaxaT = anguloTornozelo;

tempoMax = 2*delay*4*raio/((taxaMax+taxaMin)/2);
coxa = [];
joelho = [];
tornozelo = [];
stepper = []
#%%
for tempo in range(0,np.int(tempoMax),delay):
    if(taxaC > 0):
        if((anguloCoxa-anguloTaxaC) > taxaDifRaio):
            if(np.sqrt((anguloCoxa-meio)**2) < (raio/2)):
                if(taxaC < taxaMax):
                    taxaC = taxaC+taxaRef;
                    anguloTaxaC = anguloCoxa;
                
            else:
                if(taxaC > taxaMin):
                    taxaC = taxaC-taxaRef;
                    anguloTaxaC = anguloCoxa;
                
    else:
        if((anguloTaxaC-anguloCoxa) > taxaDifRaio):
            if(np.sqrt((anguloCoxa-meio)**2) < (raio/2)):
                if(taxaC < taxaMax):
                    taxaC = taxaC-taxaRef;
                    anguloTaxaC = anguloCoxa;

            else:
                if(taxaC > taxaMin):
                    taxaC = taxaC+taxaRef;
                    anguloTaxaC = anguloCoxa;

    
    anguloCoxa = anguloCoxa+taxaC;
    if len(coxa)<=4:
        coxa.append(anguloCoxa);
    else:
        if len(coxa)>4:
            coxa.append(coxa[tempo//delay  -4]*0.05+coxa[tempo//delay  -3]*0.1+coxa[tempo//delay  -2]*0.15+coxa[tempo//delay  -1]*0.2+anguloCoxa*0.5);

            
    stepper.append(tempo);
    
    if(((anguloCoxa+taxaC) >= (meio+raio)) or ((anguloCoxa+taxaC) <= (meio-raio))):
        taxaC = -taxaC;

    
    if(taxaJ > 0):
        if((anguloJoelho-anguloTaxaJ) > taxaDifRaio):
            if(np.sqrt((anguloJoelho-meio)**2) < (raio/2)):
                if(taxaJ < taxaMax):
                    taxaJ = taxaJ+taxaRef;
                    anguloTaxaJ = anguloJoelho;

            else:
                if(taxaJ > taxaMin):
                    taxaJ = taxaJ-taxaRef;
                    anguloTaxaJ = anguloJoelho;

    else:
        if((anguloTaxaJ-anguloJoelho) > taxaDifRaio):
            if(np.sqrt((anguloJoelho-meio)**2) < (raio/2)):
                if(taxaJ < taxaMax):
                    taxaJ = taxaJ-taxaRef;
                    anguloTaxaJ = anguloJoelho;

            else:
                if(taxaJ > taxaMin):
                    taxaJ = taxaJ+taxaRef;
                    anguloTaxaJ = anguloJoelho;

    anguloJoelho = anguloJoelho+taxaJ;
    if len(joelho)<=4:
        joelho.append(anguloJoelho);
    else:
        if len(joelho)>4:
            joelho.append(joelho[tempo//delay  -4]*0.05+joelho[tempo//delay  -3]*0.1+joelho[tempo//delay  -2]*0.15+joelho[tempo//delay  -1]*0.2+anguloJoelho*0.5);

    
    if(((anguloJoelho+taxaJ) >= (meio+raio)) or ((anguloJoelho+taxaJ) <= (meio-raio))):
        taxaJ = -taxaJ;

    if(taxaT > 0):
        if((anguloTornozelo-anguloTaxaT) > taxaDifRaio):
            if(np.sqrt((anguloTornozelo-meio)**2) < (raio/2)):
                if(taxaT < taxaMax):
                    taxaT = taxaT+taxaRef;
                    anguloTaxaT = anguloTornozelo;

            else:
                if(taxaT > taxaMin):
                    taxaT = taxaT-taxaRef;
                    anguloTaxaT = anguloTornozelo;

    else:
        if((anguloTaxaT-anguloTornozelo) > taxaDifRaio):
            if(np.sqrt((anguloTornozelo-meio)**2) < (raio/2)):
                if(taxaT < taxaMax):
                    taxaT = taxaT-taxaRef;
                    anguloTaxaT = anguloTornozelo;

            else:
                if(taxaT > taxaMin):
                    taxaT = taxaT+taxaRef;
                    anguloTaxaT = anguloTornozelo;

    
    anguloTornozelo = anguloTornozelo+taxaT;
    if len(tornozelo)<=4:
        tornozelo.append(anguloTornozelo);
    else:
        if len(tornozelo)>4:
            tornozelo.append(tornozelo[tempo//delay  -4]*0.05+tornozelo[tempo//delay  -3]*0.1+tornozelo[tempo//delay  -2]*0.15+tornozelo[tempo//delay  -1]*0.2+anguloTornozelo*0.5);

    
    
    if(((anguloTornozelo+taxaT) >= (meio+raio)) or ((anguloTornozelo+taxaT) <= (meio-raio))):
        taxaT = -taxaT;
    
    T1 = 0 #Theta 1 angle in degrees
    T2 = anguloCoxa #Theta 2 angle in degrees
    T3 = anguloJoelho #Theta 3 angle in degrees
    T4 = anguloTornozelo #Theta 4 angle in degrees
    
    T1 = (T1/180.0)*np.pi #Theta 1 angle in radians
    T2 = (T2/180.0)*np.pi #Theta 1 angle in radians
    T3 = (T3/180.0)*np.pi #Theta 1 angle in radians
    T4 = (T4/180.0)*np.pi #Theta 1 angle in radians
    
    
    
    R0_1 = [[np.cos(T1),0,-np.sin(T1)],
            [np.sin(T1),0,-np.cos(T1)],
            [0,-1,0]]
    
    R1_2 = [[np.cos(T2),-np.sin(T2),0],
            [np.sin(T2),np.cos(T2),0],
            [0,0,1]]
    
    R2_3 = [[np.cos(T3),-np.sin(T3),0],
            [np.sin(T3),np.cos(T3),0],
            [0,0,1]]
    
    R3_4 = [[np.cos(T4),-np.sin(T4),0],
            [np.sin(T4),np.cos(T4),0],
            [0,0,1]]
    
    R0_2 = np.dot(R0_1,R1_2)
    R2_4 = np.dot(R2_3,R3_4)
    R0_4 = np.dot(R0_2,R2_4)
 
    d0_1 = [[a1*np.cos(T1)],[a1*np.sin(T1)],[0]]
    d1_2 = [[a2*np.cos(T2)],[a2*np.sin(T2)],[0]]
    d2_3 = [[a3*np.cos(T3)],[a3*np.sin(T3)],[0]]
    d3_4 = [[a4*np.cos(T4)],[a4*np.sin(T4)],[0]]
    
    H0_1 = np.concatenate((R0_1,d0_1),1) #1 means R0_1 on the left and d0_1 on the right
    H0_1 = np.concatenate((H0_1,[[0,0,0,1]]),0) #0 means H0_1 on top  and [0,0,0,1] at the bottom
    
    H1_2 = np.concatenate((R1_2,d1_2),1) 
    H1_2 = np.concatenate((H1_2,[[0,0,0,1]]),0)
    
    H2_3 = np.concatenate((R2_3,d2_3),1)
    H2_3 = np.concatenate((H2_3,[[0,0,0,1]]),0)
    
    H3_4 = np.concatenate((R3_4,d3_4),1)
    H3_4 = np.concatenate((H3_4,[[0,0,0,1]]),0)
    
    H0_2 = np.dot(H0_1,H1_2)
    H2_4 = np.dot(H2_3,H3_4)
    H0_4 = np.dot(H0_2,H2_4)

    #x, y, z
    x.append(H0_4[0,3])
    y.append(H0_4[1,3])
    z.append(H0_4[2,3])


#%%
coxa = [coxa,stepper];
joelho = [joelho,stepper];
tornozelo = [tornozelo,stepper];

#%%
plt.plot(coxa[:][1], coxa[:][0])
plt.rcParams['axes.labelsize'] = 'large'
plt.ylabel('Thigh (degrees)')
plt.xlabel('Time (ms)')
plt.title('Thigh  Angle Overtime')
plt.grid('on')
plt.box(True)
plt.show()

#%%
plt.plot(joelho[:][1], joelho[:][0])
plt.rcParams['axes.labelsize'] = 'large'
plt.ylabel('Knee (degrees)')
plt.xlabel('Time (ms)')
plt.title('Knee Angle Overtime')
plt.grid('on')
plt.box(True)
plt.show()

#%%
plt.plot(tornozelo[:][1], tornozelo[:][0])
plt.rcParams['axes.labelsize'] = 'large'
plt.ylabel('Ankle (degrees)')
plt.xlabel('Time (ms)')
plt.title('Ankle Angle Overtime')
plt.grid('on')
plt.box(True)
plt.show()

#%%
from mpl_toolkits.mplot3d import Axes3D  # noqa: F401 unused import

#%%
max_x = max(x)
max_y = max(y)
max_z = max(z)
#%%
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
plt.rcParams['axes.labelsize'] = 'large'
plt.rcParams['legend.fontsize'] = 12
plt.rcParams["figure.figsize"] = [12, 10]
n = max_x

# For each set of style and range settings, plot n random points in the box
# defined by x in [23, 32], y in [0, 100], z in [zlow, zhigh].
for c, m, zlow, zhigh in [('r', 'o', -50, -25), ('b', '^', -30, -5)]:
    xs = x # randrange(n, 23, 32)
    ys = y #randrange(n, 0, 100)
    zs = z #randrange(n, zlow, zhigh)
    ax.plot(stepper,xs,zs,label='parametric curve')#xs, ys, zs, c=c, marker=m)

ax.set_xlabel('Time(ms)')
ax.set_ylabel('X(mm)')
ax.set_zlabel('Z(mm)')
plt.title('Foot Sole Position Overtime')

plt.show()
#%%    ##################            LEGS  Matrices          ##########################


#%% Thetas
T1 = 0 #Theta 1 angle in degrees
T2 = 0 #Theta 2 angle in degrees
T3 = 0 #Theta 3 angle in degrees
T4 = 0 #Theta 4 angle in degrees

T1 = (T1/180.0)*np.pi #Theta 1 angle in radians
T2 = (T2/180.0)*np.pi #Theta 1 angle in radians
T3 = (T3/180.0)*np.pi #Theta 1 angle in radians
T4 = (T4/180.0)*np.pi #Theta 1 angle in radians

#%% Rotation matrices

R0_1 = [[np.cos(T1),0,-np.sin(T1)],
        [np.sin(T1),0,-np.cos(T1)],
        [0,-1,0]]

R1_2 = [[np.cos(T2),-np.sin(T2),0],
        [np.sin(T2),np.cos(T2),0],
        [0,0,1]]

R2_3 = [[np.cos(T3),-np.sin(T3),0],
        [np.sin(T3),np.cos(T3),0],
        [0,0,1]]

R3_4 = [[np.cos(T4),-np.sin(T4),0],
        [np.sin(T4),np.cos(T4),0],
        [0,0,1]]

#%% Hips-to-foot Rotation
R0_2 = np.dot(R0_1,R1_2)
R2_4 = np.dot(R2_3,R3_4)
R0_4 = np.dot(R0_2,R2_4)


#%% show hip-to-foot rotaion
print('\nR0_1 = ')
print(np.matrix(R0_1))

print('\nR1_2 = ')
print(np.matrix(R1_2))

print('\nR2_3 = ')
print(np.matrix(R2_3))

print('\nR3_4 = ')
print(np.matrix(R3_4))

print('\nR0_ 4 = ')
print(np.matrix(R0_4))

#%% Link lengths
a1 = 49.5 #link a1 in mm
a2 = 74.5 #link a2 in mm
a3 = 88.4 #link a3 in mm
a4 = 42.3 #link a4 in mm

#%% Displacement vectors

d0_1 = [[a1*np.cos(T1)],[a1*np.sin(T1)],[0]]
d1_2 = [[a2*np.cos(T2)],[a2*np.sin(T2)],[0]]
d2_3 = [[a3*np.cos(T3)],[a3*np.sin(T3)],[0]]
d3_4 = [[a4*np.cos(T4)],[a4*np.sin(T4)],[0]]

#%% show displacement Vectors
print('\nd0_1 = ')
print(np.matrix(d0_1))

print('\nd1_2 = ')
print(np.matrix(d1_2))

print('\nd2_3 = ')
print(np.matrix(d2_3))

print('\nd3_4 = ')
print(np.matrix(d3_4))

#%% Homogeneous matrix

H0_1 = np.concatenate((R0_1,d0_1),1) #1 means R0_1 on the left and d0_1 on the right
H0_1 = np.concatenate((H0_1,[[0,0,0,1]]),0) #0 means H0_1 on top  and [0,0,0,1] at the bottom

H1_2 = np.concatenate((R1_2,d1_2),1) 
H1_2 = np.concatenate((H1_2,[[0,0,0,1]]),0)

H2_3 = np.concatenate((R2_3,d2_3),1)
H2_3 = np.concatenate((H2_3,[[0,0,0,1]]),0)

H3_4 = np.concatenate((R3_4,d3_4),1)
H3_4 = np.concatenate((H3_4,[[0,0,0,1]]),0)

#%% Hips-to-foot Rotation
H0_2 = np.dot(H0_1,H1_2)
H2_4 = np.dot(H2_3,H3_4)
H0_4 = np.dot(H0_2,H2_4)


#%% show hip-to-foot rotaion
print('\nH0_1 = ')
print(np.matrix(H0_1))

print('\nH1_2 = ')
print(np.matrix(H1_2))

print('\nH2_3 = ')
print(np.matrix(H2_3))

print('\nH3_4 = ')
print(np.matrix(H3_4))

print('\nH0_ 4 = ')
print(np.matrix(H0_4))

#%%    ##################           HANDS           ##########################

#%% Balance functions

def Curva(angOmbro, angBraco,angCotovelo,curva,BracIni):
    if(BracIni == 1) and angOmbro == 0:
      angOmbro = angOmbro + ((np.arcsin(curva)/np.pi)*180.0)/3;
      angCotovelo = angCotovelo + (np.arcsin(curva)/np.pi)*180.0;
      angBraco = 0;
    else:
        if (np.arcsin(curva)/np.pi)*180.0 < 90:
            if(angOmbro >30 and angOmbro <140) and angCotovelo <150:
                angOmbro += angDelta*((np.arcsin(curva)/np.pi)*180.0)/3;
                if (angCotovelo >90 and angCotovelo <150):
                    angCotovelo -= angDelta*((np.arcsin(1)/np.pi)*180.0 - (np.arcsin(curva)/np.pi)*180.0);
            else:
                angOmbro -= angDelta*((np.arcsin(curva)/np.pi)*180.0)/3;
                if angCotovelo >45:
                    angCotovelo += angDelta*((np.arcsin(1)/np.pi)*180.0 - (np.arcsin(curva)/np.pi)*180.0);
                
        if (np.arcsin(curva)/np.pi)*180.0 > 90:
            if(angOmbro >=30 and angOmbro <140) and angCotovelo <150:
                angOmbro += angDelta*((np.arcsin(curva)/np.pi)*180.0)/3;
                if (angCotovelo >90 and angCotovelo <150):
                    angCotovelo -= angDelta*((np.arcsin(curva)/np.pi)*180.0 -(np.arcsin(1)/np.pi)*180.0);
            else:
                angOmbro -= angDelta*((np.arcsin(curva)/np.pi)*180.0)/3;
                if angCotovelo <45:
                    angCotovelo += angDelta*((np.arcsin(curva)/np.pi)*180.0 -(np.arcsin(1)/np.pi)*180.0);
                
        angBraco = 0;
    return angOmbro, angBraco,angCotovelo
#  /*Serial.print("OmbroE: ");
#  Serial.print(posOmbroE);
#  Serial.print(" | CotoveloE: ");
#  Serial.println(posCotoveloE);*/

#%%
def getMotion6(time):
    gx = 328;
    gz = 328;
    ax = 183;
    ay = 183;
    az = 183;
    
    if time == 0:
            gy = 328;
    else:
        gy = 328*np.sin(np.pi*(np.float(np.random.rand(time,1)[0])*time)/(6*delay));
    
    return gx, gy, gz, ax, ay, az

#%%  
def Acelerometro(time,LogAcelerometro):
    EixoAX_Desvio =93;
    EixoAY_Desvio =93;
    EixoAZ_Desvio =93;

    #   read raw accel/gyro measurements from device
    MPUok =True;
    if(MPUok):
        gx, gy, gz, ax, ay, az = getMotion6(time);
        
        EixoGX = gx/328;
        EixoGY = gy/328;
        EixoGZ = gz/328;
        EixoAX = ax/183 - 90 + EixoAX_Desvio;
        EixoAY = ay/183 - 90 + EixoAY_Desvio;
        EixoAZ = az/183 - 90 + EixoAZ_Desvio;
#        // these methods (and a few others) are also available
#        //accelgyro.getAcceleration(&ax, &ay, &az);
#        //accelgyro.getRotation(&gx, &gy, &gz);
#        // display tab-separated accel/gyro x/y/z values
    
        if(LogAcelerometro):
            if((EixoGY%Zona_Morta_A) == 0):
                print("Zona Morta, a/g:\t");
                print(EixoAY);
        
        else:
            EixoGX = 0;
            EixoGY = 0;
            EixoGZ = 0;
            EixoAX = 0;
            EixoAY = 0;
            EixoAZ = 0;
            
    return EixoGY
      
#%%
def Equilibrio(angOmbro, angBraco,angCotovelo,time,BracIni):
    EixoGY = Acelerometro(time,True);

    if(np.arcsin(EixoGY)< Zona_Morta_G):
        if((np.int((np.arcsin(EixoGY)*180/np.pi) % Zona_Morta_A) == 0) and (EixoGY != 1)):
            angOmbro, angBraco,angCotovelo = Curva(angOmbro, angBraco,angCotovelo,EixoGY,BracIni);
            
    else:
        if(EixoGY==1):
            angOmbro, angBraco,angCotovelo = Curva(angOmbro, angBraco,angCotovelo,1,BracIni);
        
    return angOmbro, angBraco,angCotovelo

  #%% Link lengths

a1 = 34.0 #link a1 in mm
a2 = 6.4 #link a2 in mm
a3 = 87.5 #link a3 in mm
a4 = 97.8 #link a4 in mm

x =[]
y=[]
z=[]

#%%
ombro = [];
braco = [];
cotovelo = [];
arm_stepper = [];
Bracos_Inicio =1;    
anguloOmbro = 0;
anguloBraco = 0;
anguloCotovelo = 0; 

Zona_Morta_A = 8;
Zona_Morta_G = np.sin(70*np.pi/180);
angDelta = 0.05;

#%%
delay = 40;
raio = 30.0;
taxaMax = 8.0;
taxaMin = 4.0;
tempoMax = 10*delay*4*raio/((taxaMax+taxaMin)/2);

for time in range(0,np.int(tempoMax),delay):
    
    anguloOmbro, anguloBraco, anguloCotovelo = Equilibrio(anguloOmbro, anguloBraco,anguloCotovelo,time,Bracos_Inicio);
    
    ombro.append(anguloOmbro);
    braco.append(anguloBraco);
    cotovelo.append(anguloCotovelo);
    arm_stepper.append(time);
    if time ==delay:
        Bracos_Inicio =0;
        
    T1 = anguloOmbro #Theta 1 angle in degrees
    T2 = anguloBraco #Theta 2 angle in degrees
    T3 = anguloCotovelo #Theta 3 angle in degrees
    
    T1 = (T1/180.0)*np.pi #Theta 1 angle in radians
    T2 = (T2/180.0)*np.pi #Theta 1 angle in radians
    T3 = (T3/180.0)*np.pi #Theta 1 angle in radians


    R0_1 = [[np.cos(T1),0,np.sin(T1)],
            [np.sin(T1),0,-np.cos(T1)],
            [0,1,0]]
    
    R1_2 = [[np.cos(T2),0,-np.sin(T2)],
            [np.sin(T2),0,np.cos(T2)],
            [0,-1,0]]
    
    R2_3 = [[np.cos(T3),-np.sin(T3),0],
            [np.sin(T3),np.cos(T3),0],
            [0,0,1]]
    
    
    R0_2 = np.dot(R0_1,R1_2)
    R0_3 = np.dot(R0_2,R2_3)

    d0_1 = [[a2*np.sin(T1)],[a2*np.cos(T1)],[a1]]
    d1_2 = [[a3*np.cos(T2)],[a3*np.sin(T2)],[0]]
    d2_3 = [[a4*np.cos(T3)],[a4*np.sin(T3)],[0]]       
    
    H0_1 = np.concatenate((R0_1,d0_1),1) #1 means R0_1 on the left and d0_1 on the right
    H0_1 = np.concatenate((H0_1,[[0,0,0,1]]),0) #0 means H0_1 on top  and [0,0,0,1] at the bottom
    
    H1_2 = np.concatenate((R1_2,d1_2),1) 
    H1_2 = np.concatenate((H1_2,[[0,0,0,1]]),0)
    
    H2_3 = np.concatenate((R2_3,d2_3),1)
    H2_3 = np.concatenate((H2_3,[[0,0,0,1]]),0)

    H0_2 = np.dot(H0_1,H1_2)
    H0_3 = np.dot(H0_2,H2_3)

        #x, y, z
    x.append(H0_3[0,3])
    y.append(H0_3[1,3])
    z.append(H0_3[2,3])

#%%
ombro = [ombro,arm_stepper];
braco = [braco,arm_stepper];
cotovelo = [cotovelo,arm_stepper];

#%%
plt.plot(ombro[:][1], ombro[:][0])
plt.rcParams['axes.labelsize'] = 'large'
plt.ylabel('Shoulder (degrees)')
plt.xlabel('Time (ms)')
plt.title('Shoulder  Angle Overtime')
plt.grid('on')
plt.box(True)
plt.show()
#%%
plt.plot(braco[:][1], braco[:][0])
plt.rcParams['axes.labelsize'] = 'large'
plt.ylabel('Arm (degrees)')
plt.xlabel('Time (ms)')
plt.title('Arm  Angle Overtime')
plt.grid('on')
plt.box(True)
plt.show()

#%%
plt.plot(cotovelo[:][1], cotovelo[:][0])
plt.rcParams['axes.labelsize'] = 'large'
plt.ylabel('Elbow (degrees)')
plt.xlabel('Time (ms)')
plt.title('Elbow Angle Overtime')
plt.grid('on')
plt.box(True)
plt.show()

#%%
from mpl_toolkits.mplot3d import Axes3D  # noqa: F401 unused import

#%%
max_x = max(x)
max_y = max(y)
max_z = max(z)
#%%
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
plt.rcParams['axes.labelsize'] = 'large'
plt.rcParams['legend.fontsize'] = 10
plt.rcParams["figure.figsize"] = [12, 10]
n = max_x

# For each set of style and range settings, plot n random points in the box
# defined by x in [23, 32], y in [0, 100], z in [zlow, zhigh].
for c, m, zlow, zhigh in [('r', 'o', -50, -25), ('b', '^', -30, -5)]:
    xs = x # randrange(n, 23, 32)
    ys = y #randrange(n, 0, 100)
    zs = z #randrange(n, zlow, zhigh)
    ax.plot(arm_stepper,xs,ys,label='parametric curve')#xs, ys, zs, c=c, marker=m)

ax.set_xlabel('Time(ms)')
ax.set_ylabel('X(mm)')
ax.set_zlabel('Y(mm)')
plt.title('Palm of the Hand  Position Overtime')

plt.show()    
#%% ##############    HANDS Rotation and displacement     #####################

#%% Link lengths

a1 = 34.0 #link a1 in mm
a2 = 6.4 #link a2 in mm
a3 = 87.5 #link a3 in mm
a4 = 97.8 #link a4 in mm

#%% Thetas
T1 = 90 #Theta 1 angle in degrees
T2 = 0 #Theta 2 angle in degrees
T3 = 0 #Theta 3 angle in degrees

T1 = (T1/180.0)*np.pi #Theta 1 angle in radians
T2 = (T2/180.0)*np.pi #Theta 1 angle in radians
T3 = (T3/180.0)*np.pi #Theta 1 angle in radians

#%% Rotation matrices

R0_1 = [[np.cos(T1),0,np.sin(T1)],
        [np.sin(T1),0,-np.cos(T1)],
        [0,1,0]]

R1_2 = [[np.cos(T2),0,-np.sin(T2)],
        [np.sin(T2),0,np.cos(T2)],
        [0,-1,0]]

R2_3 = [[np.cos(T3),-np.sin(T3),0],
        [np.sin(T3),np.cos(T3),0],
        [0,0,1]]

#%% shoulder-to-hand Rotation
R0_2 = np.dot(R0_1,R1_2)
R0_3 = np.dot(R0_2,R2_3)

#%% show hip-to-foot rotaion
print('\nR0_1 = ')
print(np.matrix(R0_1))

print('\nR1_2 = ')
print(np.matrix(R1_2))

print('\nR2_3 = ')
print(np.matrix(R2_3))

print('\nR0_3 = ')
print(np.matrix(R0_3))

#%% Displacement vectors

d0_1 = [[a2*np.sin(T1)],[a2*np.cos(T1)],[a1]]
d1_2 = [[a3*np.cos(T2)],[a3*np.sin(T2)],[0]]
d2_3 = [[a4*np.cos(T3)],[a4*np.sin(T3)],[0]]

#%% show displacement Vectors
print('\nd0_1 = ')
print(np.matrix(d0_1))

print('\nd1_2 = ')
print(np.matrix(d1_2))

print('\nd2_3 = ')
print(np.matrix(d2_3))

#%% Homogeneous matrix

H0_1 = np.concatenate((R0_1,d0_1),1) #1 means R0_1 on the left and d0_1 on the right
H0_1 = np.concatenate((H0_1,[[0,0,0,1]]),0) #0 means H0_1 on top  and [0,0,0,1] at the bottom

H1_2 = np.concatenate((R1_2,d1_2),1) 
H1_2 = np.concatenate((H1_2,[[0,0,0,1]]),0)

H2_3 = np.concatenate((R2_3,d2_3),1)
H2_3 = np.concatenate((H2_3,[[0,0,0,1]]),0)

#%% Hips-to-foot Rotation
H0_2 = np.dot(H0_1,H1_2)
H0_3 = np.dot(H0_2,H2_3)

#%% show shoulder-to-hand rotaion
print('\nH0_1 = ')
print(np.matrix(H0_1))

print('\nH1_2 = ')
print(np.matrix(H1_2))

print('\nH2_3 = ')
print(np.matrix(H2_3))

print('\nH0_3 = ')
print(np.matrix(H0_3))
