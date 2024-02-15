from keras.models import load_model
import cv2 as cv
import numpy as np
import time

np.set_printoptions(suppress=True)

model = load_model("keras_Model.h5", compile=False)
class_names = open("labels.txt", "r").readlines()

camera = cv.VideoCapture(0)

start_time = time.time()

# Dictionary to store class counts
class_counts = {}

while True:
    ret, image = camera.read()
    image = cv.resize(image, (224, 224), interpolation=cv.INTER_AREA)
    cv.imshow("Webcam Image", image)

    image = np.asarray(image, dtype=np.float32).reshape(1, 224, 224, 3)
    image = (image / 127.5) - 1

    prediction = model.predict(image)
    index = np.argmax(prediction)
    class_name = class_names[index]
    confidence_score = prediction[0][index]

    # Print prediction and confidence score
    print("Class:", class_name[2:], end="")
    print("Confidence Score:", str(np.round(confidence_score * 100))[:-2], "%")

    # Update class count in the dictionary
    class_counts[class_name] = class_counts.get(class_name, 0) + 1
    
    elapsed_time = time.time() - start_time
    
    # 10초 경과 시 종료
    if elapsed_time >= 10:
        break

    keyboard_input = cv.waitKey(1)
    if keyboard_input == 27:
        break

# Find the class with the highest count
most_frequent_class = max(class_counts, key=class_counts.get)
print("Most Frequent Class:", most_frequent_class)

camera.release()
cv.destroyAllWindows()
