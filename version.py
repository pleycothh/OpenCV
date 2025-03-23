import cv2
import numpy as np
import torch
import ultralytics

print("OpenCV:", cv2.__version__)
print("NumPy:", np.__version__)
print("Torch:", torch.__version__, "| CUDA:", torch.cuda.is_available())
