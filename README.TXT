# --------------------------- SOUND SENSOR PROJECT ----------------------------

This project is meant to collect sound level at a proximity of a Raspberry Pi
(RPi) device. The RPi is equipped with a USB sound card (C-media Electronics,
Inc. Audio Adapter) and a microphone. The sound is recorded at 16000Hz sample
rate and every second will produce 80 pieces of RMS value as a bar-diagram.
In addition, 8 pieces of RMS value every second are sent to PHP program.

# ---------------------------- Table of Contents ------------------------------

1. Configuration instructions
2. Installation instructions
3. Operating instructions

# -----------------------------------------------------------------------------

1. Configuration instructions

	1.1. Set USB Sound Card as Default
	
		Since RPi onboard sound card doesn't have microphone interface, we
		have to change the default audio device to be USB sound card.
		
		<1>	Boot up RPi and plug in the USB sound card. (You can use
			command "lsusb" to check if the USB sound card is mounted)
				
		<2>	Modify the files "/etc/asound.conf" and ".asoundrc" respectively
			with following content:

				pcm.!default {
					type plug
					slave {
						pcm "hw:1,0"
					}
				}
				clt.!default {
					type hw
					card 1
				}

		<3>	Run "alsamixer" and you should be able to see that USB sound card 
			is the default audio device.

	1.2. Install libcurl
	
		Run command "ls /usr/include/curl" to check if libcurl is installed
		or not. If yes, you can skip this step.
		
		<1> Run command "sudo apt-get update" to update the application list.
		
		<2> Run "sudo apt-get install libcurl3" to install the libcurl3.
		
		<3> Run "sudo apt-get itall libcurl4 4 openssl-dev" to install the
			development API of libcurl4.

# -----------------------------------------------------------------------------

2. Installation instructions

	2.1. Get installation files
	
		<1>	Enter the folder where you want to put the program to.
		
		<2> Enter the command:
			"git clone https://github.com/HLKnight/sound"
			
	2.2. Install
	
		<1> Run makefile by entering command "make".

# -----------------------------------------------------------------------------

3. Operating instructions

	The program "sound.a" after installed can be run by command "./sound.a".
	
	Exit the program by pressing "Ctrl + C".
	
# -----------------------------------------------------------------------------
