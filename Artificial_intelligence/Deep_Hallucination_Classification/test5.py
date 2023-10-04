import numpy as np
import glob
import cv2
from sklearn.svm import SVC

filenames_test =glob.glob('./data/test/*')

train_names = np.loadtxt("./data/train.txt",dtype=str,delimiter=',')
validation_names= np.loadtxt("./data/validation.txt",dtype=str,delimiter=',')

v=[]
#salvarea numelui imaginii ca string si transformarea clasei in int
for i in train_names[1:]: #nu citim prima linie, deoarece
    j=[]
    j.append(i[0]) #numele/pathul imaginii
    j.append(int(i[1])) #clasa din care face parte
    v.append(j)
train_names=v
v=[]
for i in validation_names[1:]:
    j=[]
    j.append(i[0])
    j.append(int(i[1]))
    v.append(j)
validation_names=v
#sortam alfabetic dupa numele imaginii ca sa fim siguri ca nu incurcam datele
train_names.sort(key=lambda y: y[0])
validation_names.sort(key=lambda y: y[0] )

images_train=[]
images_validation=[]
imgt=[]
imgtest=[]

tl=[]
vl=[]
train_labels=[]
for i in train_names:
    tl.append(i[0]) #un vector nou doar cu numele imaginilor
validation_labels = []
for i in validation_names:
    vl.append(i[0])
for i in glob.glob('./data/train+validation/*'):
    if i[24:] in tl:#facem i[24:] pentru a verifica daca numele este in vectorul de nume nu si pathul
        images_train.append(i) #daca apare in train_names il salvam in train images
    else:
        images_validation.append(i)

images_train.sort() #le sortam alfabetic
images_validation.sort()
images_test=[]
for i in glob.glob('./data/test/*'):
    images_test.append(i) #citim imaginile din test

for i in images_validation:
    images_train.append(i)#combinam train cu validation ca sa avem mai multe teste
for i in validation_names:
    train_names.append(i)

for i in images_train:
    im =cv2.imread(i) #le citim
    im = cv2.cvtColor(im, cv2.COLOR_BGR2YUV) #convertim culoarea
    imgt.append(im)
imgt=np.array(imgt)# il facem array de tip numpy

for i in images_test:
    im =cv2.imread(i)
    im = cv2.cvtColor(im, cv2.COLOR_BGR2YUV)
    imgtest.append(im)
imgtest=np.array(imgtest)

train_labels=[]
for i in train_names: #salvam doar clasele
    train_labels.append(i[1])
#fiecare vector al fiecarei imagini intr-un singur numar
imgt_numere, imgt_x, imgt_y, imgt_rgb = imgt.shape  #returnam numarul de imagini,latimea,inaltimea si 3 pentru rgb
imgtest_numere, imgtest_x, imgtest_y, imgtest_rgb = imgtest.shape

train_data = imgt.reshape((imgt_numere,imgt_x*imgt_y*imgt_rgb)) #le transformam in numere
test_data = imgtest.reshape((imgtest_numere,imgtest_x*imgtest_y*imgtest_rgb))


    
f = open('test.txt',mode="w",encoding="utf-8")

model = SVC(C=3.9)

model.fit(train_data, train_labels)

test_predictions = model.predict(test_data)
f.write('id,label\n')
for i in range(len(images_test)):
    f.write(f"{images_test[i][12:]},{test_predictions[i]}\n")

f.close()

