/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9d30. */
int __cdecl IOAddToCdevsw(
        int (__cdecl *a1)(__int16, int),
        int (__cdecl *a2)(__int16, int),
        int (__cdecl *a3)(__int16, int),
        int (__cdecl *a4)(__int16, int),
        int (__cdecl *a5)(__int16, int),
        int (__cdecl *a6)(__int16, int),
        int (__cdecl *a7)(__int16, int),
        int (__cdecl *a8)(__int16, int),
        int (__cdecl *a9)(__int16, int),
        int (__cdecl *a10)(__int16, int),
        int (__cdecl *a11)(__int16, int))
{
  int (__cdecl **v11)(__int16, int); // edx
  int i; // ebx
  int (__cdecl **v13)(__int16, int); // edx

  v11 = &cdevsw; /*0x1a9d36*/
  for ( i = 0; i < nchrdev; v11 += 11 ) /*0x1a9d44*/
  {
    if ( !memcmp(v11, &unk_1E5100, 0x2Cu) ) /*0x1a9d57*/
      break; /*0x1a9d59*/
    ++i; /*0x1a9d5b*/
  }
  v13 = &cdevsw + 11 * i; /*0x1a9d6c*/
  if ( i < 0 || nchrdev <= i || memcmp(&cdevsw + 11 * i, &unk_1E5100, 0x2Cu) ) /*0x1a9d8d*/
    return -1; /*0x1a9d91*/
  *(&cdevsw + 11 * i) = a1; /*0x1a9d9b*/
  v13[1] = a2; /*0x1a9da4*/
  v13[2] = a3; /*0x1a9daa*/
  v13[3] = a4; /*0x1a9db0*/
  v13[4] = a5; /*0x1a9db6*/
  v13[5] = a6; /*0x1a9dbc*/
  v13[6] = a7; /*0x1a9dc2*/
  v13[7] = a8; /*0x1a9dc8*/
  v13[8] = a9; /*0x1a9dce*/
  v13[9] = a10; /*0x1a9dd4*/
  v13[10] = a11; /*0x1a9dda*/
  return i; /*0x1a9de2*/
}
