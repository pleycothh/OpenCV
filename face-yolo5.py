from ultralytics import YOLO
import cv2

# Load YOLOv8n (nano) pretrained model
model = YOLO('yolov8n.pt')  # You can also use yolov8s.pt, etc.

# Open webcam
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    if not ret:
        break

    # Run YOLO inference
    results = model(frame)

    # Draw results
    annotated_frame = results[0].plot()

    # Display
    cv2.imshow("YOLOv8 Detection", annotated_frame)

    # Press 'q' to quit
    if cv2.waitKey(1) == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
