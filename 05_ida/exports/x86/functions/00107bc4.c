/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107bc4. */
char setposix()
{
  unsigned int v0; // edx
  char result; // al

  v0 = **(_DWORD **)(dword_1E875C + 36); /*0x107bd0*/
  if ( v0 > 1 ) /*0x107bd5*/
  {
    *(_DWORD *)(dword_1E875C + 96) = -1; /*0x107c08*/
    result = dword_1E875C; /*0x107c0f*/
    *(_BYTE *)(dword_1E875C + 104) = 22; /*0x107c14*/
  }
  else
  {
    *(_DWORD *)(dword_1E875C + 96) = (char)(*(_BYTE *)(*(_DWORD *)active_u + 22) << 6) >> 7; /*0x107bea*/
    result = (2 * (v0 & 1)) | *(_BYTE *)(*(_DWORD *)active_u + 22) & 0xFD; /*0x107bfe*/
    *(_BYTE *)(*(_DWORD *)active_u + 22) = result; /*0x107c00*/
  }
  return result; /*0x107c05*/
}
