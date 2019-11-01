%THE_MOV_FILE = 'DRC_sunny.mp4';
THE_MOV_FILE = 'Droid Racing Challenge 2017 - Test Video  Initial Section, 11 AM, REVERSE 2 2.mp4';
v            = VideoReader(THE_MOV_FILE);

while hasFrame(v)
    I = readFrame(v);
    imshow(I)
end

fprintf('\n ... we are finished here <%s> \n', mfilename);