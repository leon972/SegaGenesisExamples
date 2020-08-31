Setup of the Sega Genesis programming environment

#1 Download SGDK from https://github.com/Stephane-D/SGDK
On the right from Relases, download the latest release.

#2 Extract the GDK on a folder for example C:\sgdk151

#3 Add two new System Environments Variables

GDK with value C:/gdk151
GDK_WIN with value C:\gdk151

note that GDK is Linux-style path with forward slash. 

#4 Download Regen the Sega Genesis emulator from segaretro.org (chose the version with debuggers)

#5 Install Visual Studio Code 

#6 From Visual Studio Code install the extension C/C++ from https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools
install the Sega Genesis extension from https://marketplace.visualstudio.com/items?itemName=zerasul.genesis-code 

#7 Create a new project with SHIFT+CTRL+P then write the command Genesis Code: Create Project

#8 Tell VS Code where to find the emulator , press SHIFT+CTRL+P then use the command Genesis Code: Set Gens Emulator Command Path
Select the Gens folder or Regen folder and add the full path to the executable of the emulator i.e. C:\Regen\Regen.exe

#9 Compile and execute

SHIFT+CTRL+P and write the command 