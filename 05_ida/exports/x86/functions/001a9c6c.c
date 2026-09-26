/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9c6c. */
int __cdecl IOAddToCdevswAt(
        int a1,
        int (__cdecl *a2)(__int16, int),
        int (__cdecl *a3)(__int16, int),
        int (__cdecl *a4)(__int16, int),
        int (__cdecl *a5)(__int16, int),
        int (__cdecl *a6)(__int16, int),
        int (__cdecl *a7)(__int16, int),
        int (__cdecl *a8)(__int16, int),
        int (__cdecl *a9)(__int16, int),
        int (__cdecl *a10)(__int16, int),
        int (__cdecl *a11)(__int16, int),
        int (__cdecl *a12)(__int16, int))
{
  int i; // ebx
  int (__cdecl **v13)(__int16, int); // edx
  int (__cdecl **v14)(__int16, int); // edx

  i = a1; /*0x1a9c72*/
  if ( a1 == -1 ) /*0x1a9c78*/
  {
    v13 = &cdevsw; /*0x1a9c7a*/
    for ( i = 0; i < nchrdev; v13 += 11 ) /*0x1a9c88*/
    {
      if ( !memcmp(v13, &unk_1E5100, 0x2Cu) ) /*0x1a9c9b*/
        break; /*0x1a9c9d*/
      ++i; /*0x1a9c9f*/
    }
  }
  v14 = &cdevsw + 11 * i; /*0x1a9cb0*/
  if ( i < 0 || nchrdev <= i || memcmp(&cdevsw + 11 * i, &unk_1E5100, 0x2Cu) ) /*0x1a9cd1*/
    return -1; /*0x1a9cd5*/
  *(&cdevsw + 11 * i) = a2; /*0x1a9cdf*/
  v14[1] = a3; /*0x1a9ce8*/
  v14[2] = a4; /*0x1a9cee*/
  v14[3] = a5; /*0x1a9cf4*/
  v14[4] = a6; /*0x1a9cfa*/
  v14[5] = a7; /*0x1a9d00*/
  v14[6] = a8; /*0x1a9d06*/
  v14[7] = a9; /*0x1a9d0c*/
  v14[8] = a10; /*0x1a9d12*/
  v14[9] = a11; /*0x1a9d18*/
  v14[10] = a12; /*0x1a9d1e*/
  return i; /*0x1a9d26*/
}
