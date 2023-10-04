import glob

import cv2
import numpy as np
# filenames_train_validation =glob.glob('./data/train+validation/*')
import tensorflow as tf
from tensorflow.keras import Sequential


filenames_test =glob.glob('./data/test/*')

train_names = np.loadtxt("./data/train.txt",dtype=str,delimiter=',') #citirea si separarea numelui imaginii de clasa folosind delimiter
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
    
f = open('test.out',mode="w",encoding="utf-8")

train_data = imgt
validation_data = imgtest
#le transformam in arrayuri de tipul numpy
train_labels=np.array(train_labels)
#le transformam in floaturi pentru a avea acuratete mai buna cand impartim
train_data=np.array(train_data).astype("float32")
validation_data = np.array(validation_data).astype("float32")
validation_labels = np.array(validation_labels)

#definim modelul


model = tf.keras.Sequential([
    tf.keras.layers.Conv2D(50, (2, 2), padding='same', activation=tf.nn.relu,
                           input_shape=(16, 16, 3)),
    tf.keras.layers.Conv2D(100, (2,2), padding='same', activation=tf.nn.relu),
    tf.keras.layers.MaxPooling2D(),
    tf.keras.layers.Conv2D(200, (2, 2), padding='same', activation=tf.nn.relu,),
    tf.keras.layers.MaxPooling2D(),
    tf.keras.layers.Dropout(0.7),
    tf.keras.layers.Flatten(),
    tf.keras.layers.Dense(200, activation=tf.nn.relu),
    tf.keras.layers.Dense(100, activation=tf.nn.relu),
    tf.keras.layers.Dense(50, activation=tf.nn.relu),
    tf.keras.layers.Dropout(0.3),
    tf.keras.layers.Dense(7,  activation=tf.nn.softmax)

])


model.compile(loss='sparse_categorical_crossentropy', optimizer=tf.optimizers.Adam(learning_rate=0.001), metrics=['accuracy'])

model.fit(x=train_data/255.0, y=train_labels, epochs=20,batch_size = 17,verbose = 1)


predictions =model.predict_classes(validation_data/255.0)
f.write('id,label\n')
for i in range(len(images_test)):
    f.write(f"{images_test[i][12:]},{predictions[i]}\n")

f.close()