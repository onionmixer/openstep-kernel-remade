/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cbb94. */
int __cdecl NXStrIsEqual(const void *info, const void *data1, const void *data2)
{
  const char *v4; // edi

  if ( data1 == data2 ) /*0x1cbba0*/
    return 1; /*0x1cbba7*/
  if ( !data1 ) /*0x1cbbae*/
  {
    v4 = (const char *)data2; /*0x1cbbb2*/
    return strlen(v4) == 0; /*0x1cbbd3*/
  }
  if ( !data2 ) /*0x1cbbba*/
  {
    v4 = (const char *)data1; /*0x1cbbbe*/
    return strlen(v4) == 0; /*0x1cbbbe*/
  }
  return *(_BYTE *)data2 == *(_BYTE *)data1 && strcmp((const char *)data1, (const char *)data2) == 0; /*0x1cbbea*/
}
