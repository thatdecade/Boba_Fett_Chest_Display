# Boba-Fett-Chest-Display
This is the software and hardware design for the display on Boba Fett’s chest plate.  It was developed in collaboration with Joshua Kane.

The animation script is laid out in an easy to understand format.  Each segment of the display is fully programmable in the animation.
Just 12 lines of code to processes the animation and update the display!

Video Demo: https://www.flickr.com/photos/dwest2/23788341410

Video Build Guide: https://youtu.be/qv9qykpNFjM

Part List: http://www.mouser.com/ProjectManager/ProjectDetail.aspx?AccessID=7c6a316116

PCB Main Board: https://oshpark.com/shared_projects/f60TBgnX

PCB Bargraph Board: https://www.oshpark.com/shared_projects/E4qjCF4r

PCB Assembly Guide: http://www.westaby.net/2016/01/guide-boba-fett-chest-display/

Animation sequences for ESB, RTOJ, and Mandalorian are included.  For a customized sequence:
- Open the sequence_builder.xlsx
- There are three tabs, Seq Builder, Encoder, and Decoder.
- On the Seq Builder tab, enter 1s and 0s to light up the characters as you wish.
- Copy the indicated cell and paste the values to the sequence rows (right click, paste values)
- When finished, copy the finished sequence into the arduino code.
- Update CHAR_SEQUENCE_SIZE with the number of lines in your animation sequence
