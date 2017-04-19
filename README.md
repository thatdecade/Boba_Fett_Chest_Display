# Boba-Fett-Chest-Display
This is the software and hardware design for the display on Boba Fett’s chest plate.  It was developed in collaboration with Joshua Kane.

The animation script is laid out in an easy to understand format.  Each segment of the display is fully programmable in the animation.
Just 12 lines of code to processes the animation and update the display!

Video Demo: https://www.flickr.com/photos/dwest2/23788341410

Part List: http://www.mouser.com/ProjectManager/ProjectDetail.aspx?AccessID=7c6a316116

PCB Main Board: https://www.oshpark.com/shared_projects/ml5VjhuM

PCB Bargraph Board: https://www.oshpark.com/shared_projects/E4qjCF4r

PCB Assembly Guide: http://www.westaby.net/2016/01/guide-boba-fett-chest-display/

For a customized sequence:
- Download the Board Sequence Builder from fettronics.com
- Edit the sequence builder's .ini file with the following:
   segmentorder=-gfedcba
   toporder=---12345
- Open the Board Sequence Builder application and create your new sequence.
- When finished, save, close, and reopen the .ini file.  Find your sequence on the list.
- Copy and paste the hex numbers in to the appropriate code locations
- Update SEQUENCE_SIZE with the number of lines in your animation sequence
