#include <cstdlib>
#include <initializer_list>
#include <exception>
#include <fstream>
#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>
#include <cstdint>
#include <sys/types.h>
#include <unistd.h>

#include "utils.h"

using namespace std;

int main()
{
  struct fat32info myfat32;

  auto fd = open("fat32.img", O_RDONLY);
  if(fd < 0)
    {
      cerr << "Could not open file \n";
      exit(EXIT_FAILURE);
    }
 
  auto len = lseek(fd, 0, SEEK_END);
  auto fdata = (uint8_t*)mmap(NULL, len, PROT_READ, MAP_PRIVATE, fd, 0);
  
  if(fdata == MAP_FAILED)
    {
      cerr << "Failed to map memory \n";
      exit(EXIT_FAILURE);
    }
   
  loadInfo(fdata, &myfat32);
  printInfo(&myfat32);
  
  unsigned int fds = myfat32.BPB_RsvdSecCnt + (myfat32.BPB_NumFATs * myfat32.BPB_FATSz32);
  unsigned int rcs = ((myfat32.BPB_RootClus - 2) * myfat32.BPB_SecPerClus) + fds;
  printf("%u - rcs %p - (fdata + rcs) %p - fdata \n", rcs, fdata + rcs, fdata);
  /*
  uint8_t fname[4096];
  for(int i = 0; i < 4096; ++i)  
    {
      //      printf("%p \n", fdata + (rcs + i));
      fname[i] = parseInteger<uint8_t>(fdata + (rcs + i));
      printf("%u \n", (unsigned int)fname[i]);
    }  
  //  printf("%08x \n", fname);
  //  printf("%s \n", fname);
  */

if(munmap(fdata, len) == -1)
    {
      cerr << "Failed to map memory munmap \n";
      exit(EXIT_FAILURE);
    }
  return 0;
}
