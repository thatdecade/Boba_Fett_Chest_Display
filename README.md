# Boba-Fett-Chest-Display
This is the software and hardware design for the display on Boba Fett’s chest plate.  It was developed in collaboration with Joshua Kane.

The animation script is laid out in an easy to understand format.  Each segment of the display is fully programmable in the animation.
Just 12 lines of code to processes the animation and update the display!

Video Demo: https://www.flickr.com/photos/dwest2/23788341410

Video Build Guide: https://youtu.be/qv9qykpNFjM

Part List: https://www.mouser.com/ProjectManager/ProjectDetail.aspx?AccessID=554d07ab05

PCB Main Board: https://oshpark.com/shared_projects/f60TBgnX

PCB Bargraph Board: https://www.oshpark.com/shared_projects/E4qjCF4r

PCB Assembly Guide: http://www.westaby.net/2016/01/guide-boba-fett-chest-display/

Animation sequences for ESB, RTOJ, and Mandalorian are included.  For a customized sequence:
- Open the sequence_builder.xlsx or visit: https://www.westaby.net/7seg/
- There are three tabs, Seq Builder, Encoder, and Decoder.
- On the Seq Builder tab, enter 1s and 0s to light up the characters as you wish.
- Copy the indicated cell and paste the values to the sequence rows (right click, paste values)
- When finished, copy the finished sequence into the arduino code.
- Update CHAR_SEQUENCE_SIZE with the number of lines in your animation sequence
------------------------
# Boba-Fett-Chest-Display

This is the software and hardware design for the display on Boba Fett’s chest plate. It was developed in collaboration with Joshua Kane.

The animation script is laid out in an easy to understand format.  Each segment of the display is fully programmable in the animation.
Just 12 lines of code to processes the animation and update the display!

## Video Resources
- **Video Demo**: [Watch on Flickr](https://www.flickr.com/photos/dwest2/23788341410)
- **Video Build Guide**: [Watch on YouTube](https://youtu.be/qv9qykpNFjM)

## Hardware Resources
- **Part List**: [View on Mouser](https://www.mouser.com/ProjectManager/ProjectDetail.aspx?AccessID=554d07ab05)
- **PCB Main Board**: [View on OshPark](https://oshpark.com/shared_projects/f60TBgnX)
- **PCB Bargraph Board**: [View on OshPark](https://www.oshpark.com/shared_projects/E4qjCF4r)
- **PCB Assembly Guide**: [Read the Guide](http://www.westaby.net/2016/01/guide-boba-fett-chest-display/)

## Animation Sequences
Animation sequences for **ESB**, **ROTJ**, and **Mandalorian** are included. To create a customized sequence, follow these steps using the [7-Segment LED Display Animator Tool](https://www.westaby.net/7seg/):

1. **Open the Animator Tool**: [https://www.westaby.net/7seg/](https://www.westaby.net/7seg/) 

2. **Create Your Animation**:
   - Click on the segments of each digit to turn them on or off, creating your desired pattern.
   - Click the **"Save Frame"** button to record the current state of the display, adding it as a frame in your animation sequence.
   - Click the **"Playback Animation"** button to preview your animation on the display.
   - Once satisfied with your animation, click the **"Copy Code"** button to copy the animation data to your clipboard. This can be directly pasted into your Arduino code.

3. **Configure Arduino Code**:
   - In your Arduino sketch, paste the copied animation data where appropriate.
   - Update the `CHAR_SEQUENCE_SIZE` constant to match the number of frames in your animation sequence.

## Getting Started
1. **Assemble the Hardware**:
   - Follow the [PCB Assembly Guide](http://www.westaby.net/2016/01/guide-boba-fett-chest-display/) to assemble the main and bargraph PCBs.
   - Ensure all components are correctly placed and soldered.

2. **Upload the Firmware**:
   - Connect your assembled display to your computer via USB.
   - Open the Arduino IDE and load your sketch.  
   - Paste the animation data into your sketch and upload it to the microcontroller.

3. **Power Up**:
   - Once the firmware is uploaded, power the display to see your custom animations in action.

## License
[GNU General Public License v3.0](LICENSE)
