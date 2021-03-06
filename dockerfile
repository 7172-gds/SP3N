FROM ubuntu
COPY sp1.sh .
RUN apt-get update && apt-get install -y build-essential gdb
RUN gcc -fno-pie -no-pie sp3.cpp -o sp3 -g -lstdc++
CMD ./sp3.sh
