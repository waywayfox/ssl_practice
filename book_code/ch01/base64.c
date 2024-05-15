#include <stdio.h>
#include <assert.h>
#include "base64.h"

static char *base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";



void base64_encode(coanst unsigned char *input, int len, unsigned char * output)
{
  do {
    *output++ = base64[(input[0] & 0xFC) >> 2];

    if (len == 1)
    {
      *output++ = base64[(input[0] & 0x03) << 4];
      *output++ = '=';
      *output++ = '=';
      break;
    }

    *output++ = base64[((input[0] & 0x0C) << 4 ) | ((input[1] & 0xF0) >> 4)];
    if (len == 2)
    {
      *output++ = base64[(input[1] & 0x0F) << 2];
      *output++ = '=';
      break;
    }

  } while (len -= 3);
}
