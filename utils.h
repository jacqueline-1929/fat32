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

using namespace std;

template<typename T, const T...tArgs>
  T parseInteger(const uint8_t* const ptr);

struct fat32info
{
  uint16_t BPB_BytesPerSec;
  uint16_t BPB_RsvdSecCnt;
  uint8_t BPB_SecPerClus;
  uint8_t BPB_NumFATs;
  uint32_t BPB_FATSz32;
  uint32_t BPB_RootClus;
};	

int loadInfo(uint8_t * fdata, struct fat32info * info)
{
  info->BPB_RootClus = parseInteger<uint32_t>((fdata + 44));
  info->BPB_BytesPerSec = parseInteger<uint16_t>((fdata + 11));
  info->BPB_RsvdSecCnt = parseInteger<uint16_t>((fdata + 14));  
  info->BPB_SecPerClus = parseInteger<uint8_t>((fdata + 13));
  info->BPB_NumFATs = parseInteger<uint8_t>((fdata + 16));
  info->BPB_FATSz32 = parseInteger<unsigned int>(fdata + 36);	
  return 0;	
}


void printInfo(struct fat32info * info)
{
  printf("%u = BPB_BytesPerSec \n", (unsigned int)info->BPB_BytesPerSec);
  printf("%u = BPB_SecPerClus \n", (unsigned int)info->BPB_SecPerClus);
  printf("%u = BPB_NumFATs \n", (unsigned int)info->BPB_NumFATs);
  printf("%u = BPB_RsvdSecCnt \n", (unsigned int)info->BPB_RsvdSecCnt);
  printf("%u = BPB_RootClus   \n", (unsigned int)info->BPB_RootClus  );
  printf("%u = BPB_FATSz32  \n", (unsigned int)info->BPB_FATSz32 );
}

class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
} myex;


template<typename T, const T...tArgs>
  T parseInteger(const uint8_t* const ptr)
{
  T val = 0;
  for (size_t i=0; i<sizeof(T); ++i) {
    val |= static_cast<T>(static_cast<T>(ptr[i]) << (i*8));
  }

  constexpr auto valid_vals = initializer_list<T>({tArgs...});

  if (valid_vals.size() == 0) return val;

  for (auto &x: valid_vals)
    if (x == val) return val;

  throw myex;
}
