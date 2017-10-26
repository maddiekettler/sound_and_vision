# Sound and Vision

Visual and Audio project for ARTS 4090: Art & Code & Interactivity at Rensselaer
Polytechnic Institute.
Instructor: Shawn Lawson

Inspired by example Particle and 3D code provided by openFrameworks, as well as
code we have written in class (particleSystemOfADown).

When run, the particles hover around the center point. If the program detects a
a sound (from the user) above a certain threshold, the particles will be
repelled from the center point and scatter towards the boundaries of the window.
There are conditionals in place to keep particles in the bounds of the window. I
tested the program using various songs. Optimal speaker setting will differ for
every system, but my volume was between 25% and 50% when I tested it (I used the
speakers on my Lenovo ThinkPad W541).

Feel free to test the program with whatever songs you choose, and to also modify
the number of particles in the setup() function (default is 500, I've tested it
with 1000 particles and it's a little more visually interesting) as well as the
size and shape of the particles (which can be modified in the cloudDraw() function).

Title, "Sound and Vision" inspired by the song with the same name by David Bowie
from his album "Low", originally released 14 January 1977.

https://youtu.be/gYtDhfR2t2Y

All code written using openFrameworks for Visual Studio 2015.
