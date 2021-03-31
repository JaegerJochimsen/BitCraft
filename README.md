# BitCraft
An attempt at a bitcoin mining program. Bitcoin mining uses sha256 hashing. The way the program works is simple: take previous words (i.e. a block # + transactions + previous hash as a string), add a new string to it and rehash. A nonce (i.e. a string that is added to the words string) which produces a hash value with 16 leading zeroes is (from my understanding) what allows bitcoin to be "mined". 

This project is less about turning a profit and more about learning about hash functions, the process of program development and testing, and multithreading and optimization. I hope to continue making this simple program faster and more effective so that, perhaps someday, it could be used for actual mining! 

*Further additions to this repository are likely to come in the near future as will any additional information about bitcoin and bitcoin mining that I come across

# Compilation:
g++ -fopenmp sha256.cc mine.cc -o mine

# Additional Dev Notes:
- The .cc extension denotes a c++ file
- Development took place on a Linux distribution, Ubuntu and run on the University of Oregon's ix-dev 

*Credit for the sha256 function and the general layout of the mine function are credited in the source code but structure modifications, openMP usage, and other implemented functions are all written independent of those sources.
