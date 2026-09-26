/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1d0fb4. */
__int64 __cdecl _udivdi3(unsigned __int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v3; // rdi
  char v4; // dl
  int v5; // edx
  int v6; // edi
  unsigned int v7; // ebx
  unsigned int v8; // eax
  unsigned int v9; // ebx
  unsigned int v11; // [esp+14h] [ebp-1Ch]
  unsigned int v12; // [esp+24h] [ebp-Ch]

  v11 = a2; /*0x1d0fc6*/
  if ( a3 ) /*0x1d0fd3*/
  {
    if ( a3 > HIDWORD(a1) ) /*0x1d101a*/
      goto LABEL_8; /*0x1d101a*/
    _BitScanReverse((unsigned int *)&v5, a3); /*0x1d1024*/
    LOBYTE(v5) = v4 ^ 0x1F; /*0x1d1027*/
    if ( v5 ) /*0x1d102f*/
    {
      v6 = (a2 >> (32 - v5)) | (a3 << v5); /*0x1d105b*/
      v12 = HIDWORD(a1) >> (32 - v5); /*0x1d1069*/
      v7 = ((unsigned int)a1 >> (32 - v5)) | (HIDWORD(a1) << v5); /*0x1d107b*/
      v8 = __PAIR64__(v12, v7) / (unsigned int)v6; /*0x1d1088*/
      v9 = __PAIR64__(v12, v7) % (unsigned int)v6; /*0x1d108a*/
      LODWORD(v3) = v8; /*0x1d108c*/
      if ( __PAIR64__(v9, (_DWORD)a1 << v5) < v8 * (unsigned __int64)(a2 << v5) ) /*0x1d10a1*/
        LODWORD(v3) = v8 - 1; /*0x1d10a3*/
      goto LABEL_15; /*0x1d10a3*/
    }
    if ( HIDWORD(a1) <= a3 && (unsigned int)a1 < a2 ) /*0x1d103b*/
LABEL_8:
      LODWORD(v3) = 0; /*0x1d101c*/
    else
      LODWORD(v3) = 1; /*0x1d103d*/
LABEL_15:
    HIDWORD(v3) = 0; /*0x1d10a4*/
    return v3; /*0x1d10a4*/
  }
  if ( a2 > HIDWORD(a1) ) /*0x1d0fd7*/
  {
    LODWORD(v3) = a1 / a2; /*0x1d0fe1*/
    goto LABEL_15; /*0x1d0fe3*/
  }
  if ( !a2 ) /*0x1d0fec*/
    v11 = 1 / 0u; /*0x1d0ffa*/
  HIDWORD(v3) = HIDWORD(a1) / v11; /*0x1d1006*/
  LODWORD(v3) = __PAIR64__(HIDWORD(a1) % v11, a1) / v11; /*0x1d100e*/
  return v3; /*0x1d10b5*/
}
