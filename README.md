Input .txt format from Youtube transcription box:

0:00

sudo gcc -o srt srt.c

0:04

Linux bash script srt_convert.sh uses C-compiled program srt

0:07

to convert file_name.txt from Youtube transcription box

0:14

to file_name.srt which contains subtitles in srt format.

0:17

Instruction:
1. sudo gcc -o srt srt.c
   
2. files:
   
      srt_convert.sh
   
      file_name.txt
   
      srt
   
         should be in the same directory.
   
3. run the script typing ./srt_convert.sh
4. Script srt_convert.sh is a modification of the script prepare_mp4.sh from https://bitbucket.org/MattHawkinsUK/rpispy-video-capture-unit/src/master/
   


#########################################################

Output .srt format:

1

00:00:00,000 --> 00:00:04,000 

sudo gcc -o srt srt.c

2

00:00:04,000 --> 00:00:07,000 

Linux bash script srt_convert.sh uses C-compiled program srt


3

00:00:07,000 --> 00:00:14,000 

to convert file_name.txt from Youtube transcription box


4

00:00:14,000 --> 00:00:17,000 

to file_name.srt which contains subtitles in srt format. 

