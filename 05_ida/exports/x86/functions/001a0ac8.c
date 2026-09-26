/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a0ac8. */
int __cdecl PCPatoi(char *a1)
{
  int v2; // ebx
  int v3; // esi
  char v4; // al
  int result; // eax

  v2 = 0; /*0x1a0ad0*/
  v3 = 0; /*0x1a0ad2*/
  while ( 1 ) /*0x1a0ad4*/
  {
    v4 = *a1; /*0x1a0ad4*/
    if ( *a1 == 43 ) /*0x1a0ad8*/
      goto LABEL_11; /*0x1a0ad8*/
    if ( *a1 > 43 ) /*0x1a0ada*/
      break; /*0x1a0ada*/
    if ( v4 != 9 && v4 != 32 ) /*0x1a0ae2*/
      goto LABEL_12; /*0x1a0ae2*/
    ++a1; /*0x1a0af0*/
  }
  if ( v4 == 45 ) /*0x1a0aea*/
  {
    v3 = 1; /*0x1a0aec*/
    goto LABEL_11; /*0x1a0aed*/
  }
LABEL_12:
  while ( (unsigned __int8)(*a1 - 48) <= 9u ) /*0x1a0b09*/
  {
    v2 = *a1 + 10 * v2 - 48; /*0x1a0afc*/
LABEL_11:
    ++a1; /*0x1a0b00*/
  }
  result = v2; /*0x1a0b0b*/
  if ( v3 ) /*0x1a0b0f*/
    return -v2; /*0x1a0b11*/
  return result; /*0x1a0b16*/
}
