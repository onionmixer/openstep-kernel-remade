/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c89c8. */
int __cdecl sub_1C89C8(char *a1, char *a2, char *__s2)
{
  char v4; // al
  const char *v5; // edi

  if ( a2 == __s2 ) /*0x1c89d8*/
    return 1; /*0x1c89df*/
  v4 = *a1; /*0x1c89e4*/
  if ( *a1 == 42 ) /*0x1c89e8*/
    goto LABEL_9; /*0x1c89e8*/
  if ( v4 > 42 ) /*0x1c89ea*/
  {
    if ( v4 == 64 ) /*0x1c89f6*/
      return (char)objc_msgSend(a2, sel_isEqual_, __s2); /*0x1c8a09*/
    return 0; /*0x1c89f6*/
  }
  if ( v4 == 37 ) /*0x1c89ee*/
  {
LABEL_9:
    if ( a2 ) /*0x1c8a0e*/
    {
      if ( __s2 ) /*0x1c8a1a*/
      {
        if ( *__s2 == *a2 ) /*0x1c8a3c*/
          return strcmp(a2, __s2) == 0; /*0x1c8a4f*/
        return 0; /*0x1c8a3c*/
      }
      v5 = a2; /*0x1c8a1e*/
    }
    else
    {
      v5 = __s2; /*0x1c8a12*/
    }
    return strlen(v5) == 0; /*0x1c8a33*/
  }
  return 0; /*0x1c8a59*/
}
