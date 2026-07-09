This is a program for bytebeat C-compatibility verification for Linux.

How to use:

1. Clone the repository into your folder:
git clone https://github.com/astolfo671games/bytebeat.git && cd bytebeat
or
git@github.com:astolfo671games/bytebeat.git && cd bytebeat

2. Run init.sh:
./init.sh <samplerate> <num_frames>
samplerate - samplerate of your bytebeat
num_frames - length of your bytebeat (in frames)

3. Render your bytebeat into a WAV using the "Render WAV" button on D3nschot's website:
https://d3nschot.github.io/ThisBeat2.1

4. Put the rendered audio into the ./bytebeat directory

5. Put your bytebeat code into in.txt

6. Run ./v.sh

If the program outputs "Bytebeat compiled successfully!", that means your bytebeat code compiles in C, if the program outputs "Bytebeat verified successfully!", that means your bytebeat code is fully C-compatible, otherwise it's not C-compatible.
