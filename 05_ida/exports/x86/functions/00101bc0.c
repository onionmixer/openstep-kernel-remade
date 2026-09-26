/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x101bc0. */
char *__cdecl strncpy(char *__dst, const char *__src, size_t __n)
{
  char *v3; // edx
  signed __int32 v5; // ecx
  const char *v6; // ebx
  char *v7; // ebx
  char *v8; // ebx
  char *v9; // ebx
  char *v10; // ebx
  char *v11; // ebx
  _BYTE *v12; // ebx

  v3 = __dst; /*0x101bc5*/
  v5 = __n; /*0x101bcd*/
  if ( (int)__n > 0 ) /*0x101bd2*/
  {
    do /*0x101c62*/
    {
      if ( !*__src ) /*0x101bd8*/
        break; /*0x101bd8*/
      *v3 = *__src; /*0x101be2*/
      v6 = __src + 1; /*0x101be4*/
      ++v3; /*0x101be5*/
      if ( --v5 <= 0 ) /*0x101be9*/
        return __dst; /*0x101be9*/
      if ( !*v6 ) /*0x101bef*/
        break; /*0x101bef*/
      *v3 = *v6; /*0x101bf5*/
      v7 = (char *)(v6 + 1); /*0x101bf7*/
      ++v3; /*0x101bf8*/
      if ( --v5 <= 0 ) /*0x101bfc*/
        return __dst; /*0x101bfc*/
      if ( !*v7 ) /*0x101c02*/
        break; /*0x101c02*/
      *v3 = *v7; /*0x101c08*/
      v8 = v7 + 1; /*0x101c0a*/
      ++v3; /*0x101c0b*/
      if ( --v5 <= 0 ) /*0x101c0f*/
        return __dst; /*0x101c0f*/
      if ( !*v8 ) /*0x101c15*/
        break; /*0x101c15*/
      *v3 = *v8; /*0x101c1b*/
      v9 = v8 + 1; /*0x101c1d*/
      ++v3; /*0x101c1e*/
      if ( --v5 <= 0 ) /*0x101c22*/
        return __dst; /*0x101c22*/
      if ( !*v9 ) /*0x101c28*/
        break; /*0x101c28*/
      *v3 = *v9; /*0x101c2e*/
      v10 = v9 + 1; /*0x101c30*/
      ++v3; /*0x101c31*/
      if ( --v5 <= 0 ) /*0x101c35*/
        return __dst; /*0x101c35*/
      if ( !*v10 ) /*0x101c37*/
        break; /*0x101c37*/
      *v3 = *v10; /*0x101c3d*/
      v11 = v10 + 1; /*0x101c3f*/
      ++v3; /*0x101c40*/
      if ( --v5 <= 0 ) /*0x101c44*/
        return __dst; /*0x101c44*/
      if ( !*v11 ) /*0x101c46*/
        break; /*0x101c4a*/
      *v3 = *v11; /*0x101c4c*/
      v12 = v11 + 1; /*0x101c4e*/
      ++v3; /*0x101c4f*/
      if ( --v5 <= 0 ) /*0x101c53*/
        return __dst; /*0x101c53*/
      if ( !*v12 ) /*0x101c55*/
        break; /*0x101c59*/
      *v3 = *v12; /*0x101c5b*/
      __src = v12 + 1; /*0x101c5d*/
      ++v3; /*0x101c5e*/
      --v5; /*0x101c5f*/
    }
    while ( v5 > 0 ); /*0x101c62*/
    if ( v5 > 0 ) /*0x101c6a*/
    {
      if ( (-v5 & 3) == 0 ) /*0x101c73*/
        goto LABEL_29; /*0x101c73*/
      if ( (-v5 & 3) != 3 ) /*0x101c78*/
      {
        if ( (-v5 & 3u) < 2 ) /*0x101c7d*/
        {
          *v3++ = 0; /*0x101c7f*/
          --v5; /*0x101c83*/
        }
        *v3++ = 0; /*0x101c84*/
        --v5; /*0x101c88*/
      }
      *v3++ = 0; /*0x101c89*/
      if ( --v5 > 0 ) /*0x101c90*/
      {
LABEL_29:
        do /*0x101cab*/
        {
          *v3 = 0; /*0x101c94*/
          v3[1] = 0; /*0x101c97*/
          v3[2] = 0; /*0x101c9b*/
          v3[3] = 0; /*0x101c9f*/
          v3 += 4; /*0x101ca3*/
          v5 -= 4; /*0x101ca6*/
        }
        while ( v5 > 0 ); /*0x101cab*/
      }
    }
  }
  return __dst; /*0x101cb2*/
}
