/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x101b48. */
char *__cdecl strcpy(char *__dst, const char *__src)
{
  char v2; // al
  const char *v3; // ecx
  char *v4; // edx
  char v5; // al
  char v6; // al
  char v7; // al
  char v8; // al
  char v9; // al
  char v10; // al
  char v11; // al
  char v12; // al

  v2 = *__src; /*0x101b52*/
  *__dst = *__src; /*0x101b54*/
  v3 = __src + 1; /*0x101b56*/
  v4 = __dst + 1; /*0x101b57*/
  if ( v2 ) /*0x101b5c*/
  {
    do /*0x101bb2*/
    {
      v5 = *v3; /*0x101b60*/
      *v4 = *v3; /*0x101b62*/
      if ( !v5 ) /*0x101b66*/
        break; /*0x101b66*/
      v6 = v3[1]; /*0x101b68*/
      v4[1] = v6; /*0x101b6b*/
      if ( !v6 ) /*0x101b70*/
        break; /*0x101b70*/
      v7 = v3[2]; /*0x101b72*/
      v4[2] = v7; /*0x101b75*/
      if ( !v7 ) /*0x101b7a*/
        break; /*0x101b7a*/
      v8 = v3[3]; /*0x101b7c*/
      v4[3] = v8; /*0x101b7f*/
      if ( !v8 ) /*0x101b84*/
        break; /*0x101b84*/
      v9 = v3[4]; /*0x101b86*/
      v4[4] = v9; /*0x101b89*/
      if ( !v9 ) /*0x101b8e*/
        break; /*0x101b8e*/
      v10 = v3[5]; /*0x101b90*/
      v4[5] = v10; /*0x101b93*/
      if ( !v10 ) /*0x101b98*/
        break; /*0x101b98*/
      v11 = v3[6]; /*0x101b9a*/
      v4[6] = v11; /*0x101b9d*/
      if ( !v11 ) /*0x101ba2*/
        break; /*0x101ba2*/
      v12 = v3[7]; /*0x101ba4*/
      v4[7] = v12; /*0x101ba7*/
      v3 += 8; /*0x101baa*/
      v4 += 8; /*0x101bad*/
    }
    while ( v12 ); /*0x101bb2*/
  }
  return __dst; /*0x101bb6*/
}
