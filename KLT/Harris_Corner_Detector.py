import cv2 as cv


I = cv.imread('island.jpg')
I = cv.cvtColor(I, cv.COLOR_BGR2GRAY)
I = cv.resize(I, (500, 300))
cv.imshow('original image', I)
cv.waitKey(0)









