/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1979e4. */
int VGASetGraphicsMode()
{
  unsigned int i; // ecx
  unsigned int j; // ecx
  unsigned int k; // ecx
  unsigned int m; // ecx
  int v4; // ecx
  int v5; // edx
  unsigned __int8 v6; // bl
  unsigned __int8 v7; // si
  unsigned __int8 v8; // di
  int n; // [esp+Ch] [ebp-Ch]

  __outbyte(0x3C4u, 1u); /*0x1979f4*/
  _InterlockedIncrement(dword_1E8648); /*0x1979f5*/
  __outbyte(0x3C5u, 0x21u); /*0x197a09*/
  _InterlockedIncrement(dword_1E8648); /*0x197a0a*/
  __inbyte(0x3DAu); /*0x197a16*/
  __outbyte(0x3C0u, 0); /*0x197a1e*/
  _InterlockedIncrement(dword_1E8648); /*0x197a1f*/
  __outbyte(0x3C2u, 0xE3u); /*0x197a33*/
  _InterlockedIncrement(dword_1E8648); /*0x197a34*/
  __outbyte(0x3DAu, 0); /*0x197a48*/
  _InterlockedIncrement(dword_1E8648); /*0x197a49*/
  for ( i = 0; i <= 4; ++i ) /*0x197a50*/
  {
    __outbyte(0x3C4u, i); /*0x197a5d*/
    _InterlockedIncrement(dword_1E8648); /*0x197a5e*/
    __outbyte(0x3C5u, byte_1D54DE[i]); /*0x197a72*/
    _InterlockedIncrement(dword_1E8648); /*0x197a73*/
  }
  __outbyte(0x3C4u, 0); /*0x197a87*/
  _InterlockedIncrement(dword_1E8648); /*0x197a88*/
  __outbyte(0x3C5u, 3u); /*0x197a96*/
  _InterlockedIncrement(dword_1E8648); /*0x197a97*/
  __outbyte(0x3D4u, 0x11u); /*0x197aa5*/
  _InterlockedIncrement(dword_1E8648); /*0x197aa6*/
  __outbyte(0x3D5u, 0); /*0x197ab4*/
  _InterlockedIncrement(dword_1E8648); /*0x197ab5*/
  for ( j = 0; j <= 0x18; ++j ) /*0x197abc*/
  {
    __outbyte(0x3D4u, j); /*0x197ac9*/
    _InterlockedIncrement(dword_1E8648); /*0x197aca*/
    __outbyte(0x3D5u, byte_1D54E3[j]); /*0x197ade*/
    _InterlockedIncrement(dword_1E8648); /*0x197adf*/
  }
  __inbyte(0x3DAu); /*0x197af1*/
  for ( k = 0; k <= 0x14; ++k ) /*0x197af2*/
  {
    __outbyte(0x3C0u, k); /*0x197afd*/
    _InterlockedIncrement(dword_1E8648); /*0x197afe*/
    __outbyte(0x3C0u, byte_1D54FC[k]); /*0x197b0d*/
    _InterlockedIncrement(dword_1E8648); /*0x197b0e*/
  }
  for ( m = 0; m <= 8; ++m ) /*0x197b1b*/
  {
    __outbyte(0x3CEu, m); /*0x197b29*/
    _InterlockedIncrement(dword_1E8648); /*0x197b2a*/
    __outbyte(0x3CFu, byte_1D5511[m]); /*0x197b3e*/
    _InterlockedIncrement(dword_1E8648); /*0x197b3f*/
  }
  for ( n = 0; n <= 15; ++n )
  {
    v4 = n + (n < 0 ? 3 : 0);
    LOBYTE(v4) = v4 & 0xFC; /*0x197b5e*/
    v5 = 3 * (n - v4); /*0x197b6c*/
    v6 = byte_1D551A[v5]; /*0x197b6f*/
    v7 = byte_1D551B[v5]; /*0x197b76*/
    v8 = byte_1D551C[v5]; /*0x197b7d*/
    __outbyte(0x3C8u, n); /*0x197b8e*/
    _InterlockedIncrement(dword_1E8648); /*0x197b8f*/
    us_spin(10); /*0x197b98*/
    __outbyte(0x3C9u, v6); /*0x197ba9*/
    _InterlockedIncrement(dword_1E8648); /*0x197baa*/
    us_spin(10); /*0x197bb3*/
    __outbyte(0x3C9u, v7); /*0x197bc4*/
    _InterlockedIncrement(dword_1E8648); /*0x197bc5*/
    us_spin(10); /*0x197bce*/
    __outbyte(0x3C9u, v8); /*0x197bdf*/
    _InterlockedIncrement(dword_1E8648); /*0x197be0*/
    us_spin(10); /*0x197be9*/
  }
  memset((void *)0xA0000, 1, 0x10000u); /*0x197c0a*/
  __inbyte(0x3DAu); /*0x197c14*/
  __outbyte(0x3C0u, 0x20u); /*0x197c1c*/
  _InterlockedIncrement(dword_1E8648); /*0x197c1d*/
  __outbyte(0x3C4u, 1u); /*0x197c2b*/
  _InterlockedIncrement(dword_1E8648); /*0x197c2c*/
  __outbyte(0x3C5u, 1u); /*0x197c43*/
  _InterlockedIncrement(dword_1E8648); /*0x197c44*/
  return 0; /*0x197c50*/
}
