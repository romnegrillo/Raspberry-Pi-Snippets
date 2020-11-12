from picamera import PiCamera
from picamera.array import PiRGBArray
import cv2
import time

# Initialize objects.
# Camera object and PiRGBArray for converting the
# image returned by the picamera into array of pixel values.
camera = PiCamera()
rawCapture = PiRGBArray(camera)

# Warmup
time.sleep(0.1)

# Starting capturing, make sure the format is in bgr
# because OpenCV by default, the displayed image is in bgr.

# Inifite loop
while 1:
    camera.capture(rawCapture, format="bgr", use_video_port=True)

    # Get the array of pixels from the captured image.
    image=rawCapture.array

    # Flip the display because PiCamera was placed up side down.
    # Display the image on screen and wait for a keypress.
    image=cv2.flip(image,0)
    cv2.imshow("Image", image)
    rawCapture.truncate(0)

    # Break if q is pressed.
    if cv2.waitKey(1) == ord('q'):
        break

cv2.destroyAllWindows()
