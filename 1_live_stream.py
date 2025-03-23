import cv2

# Open default camera (usually 0)
cap = cv2.VideoCapture(0)

if not cap.isOpened():
    print("Cannot open camera")
    exit()

while True:
    ret, frame = cap.read()
    
    if not ret:
        print("Can't receive frame (stream end?). Exiting ...")
        break

    # Show the frame in a window
    cv2.imshow('Live Webcam Feed', frame)

    # Exit if 'q' is pressed
    if cv2.waitKey(1) == ord('q'):
        break

# Release the camera and destroy windows
cap.release()
cv2.destroyAllWindows()
