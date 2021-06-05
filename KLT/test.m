BW=zeros(9,9);
BW(5:5,5:5) = 1

SE = [1,1,1;1,0,1;1,1,1]
BW2 = imdilate(BW, SE)
