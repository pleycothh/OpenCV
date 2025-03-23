import cv2

# Open the webcam (0 = default camera)
cap = cv2.VideoCapture(0)

if not cap.isOpened():
    print("❌ Cannot access webcam")
    exit()

while True:
    ret, frame = cap.read()
    if not ret:
        print("❌ Failed to grab frame")
        break

    # Get frame dimensions
    h, w = frame.shape[:2]

    # Define the size of the center box
    box_width, box_height = 100, 100

    # Calculate top-left and bottom-right corners
    top_left = (w // 2 - box_width // 2, h // 2 - box_height // 2)
    bottom_right = (w // 2 + box_width // 2, h // 2 + box_height // 2)

    # Draw the green box (BGR: 0,255,0)
    cv2.rectangle(frame, top_left, bottom_right, (0, 255, 0), 2)

    # Show the frame
    cv2.imshow("Live Feed with Center Box", frame)

    # Press 'q' to exit
    if cv2.waitKey(1) == ord('q'):
        break

# Cleanup
cap.release()
cv2.destroyAllWindows()
