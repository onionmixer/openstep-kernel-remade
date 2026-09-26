/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1d03c8. */
_DWORD *__cdecl _sel_init(int a1, int a2, int a3, int a4)
{
  int (__stdcall **v4)(void *, int); // edi
  void *v5; // eax
  _DWORD *result; // eax
  _DWORD *v7; // edx

  v4 = (int (__stdcall **)(void *, int))NXDefaultMallocZone(); /*0x1d03d9*/
  v5 = NXDefaultMallocZone(); /*0x1d03dd*/
  result = (_DWORD *)v4[1](v5, 28); /*0x1d03e6*/
  *result = a1; /*0x1d03e8*/
  result[1] = 821; /*0x1d03ea*/
  result[2] = 0; /*0x1d03f1*/
  result[3] = a2; /*0x1d03f8*/
  result[4] = a3 + a2; /*0x1d03fe*/
  result[5] = a4; /*0x1d0404*/
  v7 = &off_1E5640; /*0x1d0407*/
  if ( off_1E5640 ) /*0x1d0413*/
  {
    while ( (_UNKNOWN *)*v7 != &unk_1E5624 ) /*0x1d041e*/
    {
      v7 = (_DWORD *)(*v7 + 24); /*0x1d042e*/
      if ( !*v7 ) /*0x1d0431*/
        return result; /*0x1d0434*/
    }
    result[6] = &unk_1E5624; /*0x1d0420*/
    *v7 = result; /*0x1d0427*/
  }
  return result; /*0x1d0439*/
}
