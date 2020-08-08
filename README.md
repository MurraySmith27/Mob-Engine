# Mob-Engine
A new game development library of my own design. I'm working on Mob because I want to create games from the ground up using my own tools, rather than a pre-existing engine.

Directions on how to use as of August 6th, 2020 commit:

1. Clone the repository into a new folder.
2. Open the .sln file in visual studio to setup the project.
3. Run GenerateProject.bat in cmd (an identically-named .txt file is present in the folder as well if you'd rather execute the make command manually)
4. Build and run Source.cpp in SandBoxText to see a little guy slide across the screen! Behaviour can be edited (Somewhat minimally) from the BasicScript class example.

(Note: You may get an error saying something about post build commands and IF EXIST. This is because there is a post build command to manually move the MOB_Engine.dll file to
a place that is accessible by SandBoxText.exe. To fix this, simply build the MOB_Engine project first, then build the SandBoxTest project. Then it should run normally.)
