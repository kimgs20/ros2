'''
https://docs.opencv.org/4.3.0/db/d28/tutorial_cascade_classifier.html
'''

import cv2

# download from: github.com/opencv/opencv/tree/master/data/haarcascades
face_Cascade = cv2.CascadeClassifier("Resources/haarcascade_frontalface_default.xml")

image = cv2.imread('./img_files/Lenna.png')
imgGray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

faces = face_Cascade.detectMultiScale(imgGray, 1.1, 4)

for (x, y, w, h) in faces:
  cv2.rectangle(image, (x, y), (x + w, y + h), (255, 0, 0), 2)

cv2.imshow("Result", image)
cv2.waitKey(0)
