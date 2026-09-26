/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x101ff0. */
int __cdecl ffs(int a1)
{
  unsigned int v1; // edx
  int result; // eax
  unsigned int v3; // edx
  unsigned int v4; // edx
  unsigned int v5; // edx
  unsigned int v6; // edx
  unsigned int v7; // edx
  unsigned int v8; // edx
  unsigned int v9; // edx

  v1 = a1; /*0x101ff3*/
  if ( !a1 ) /*0x101ff8*/
    return 0; /*0x101ffa*/
  result = 1; /*0x102000*/
  if ( !(_BYTE)a1 ) /*0x102007*/
  {
    do /*0x102062*/
    {
      result += 8; /*0x102010*/
      v1 >>= 8; /*0x102013*/
      if ( (_BYTE)v1 ) /*0x102018*/
        break; /*0x102018*/
      result += 8; /*0x10201e*/
      v1 >>= 8; /*0x102021*/
      if ( (_BYTE)v1 ) /*0x102026*/
        break; /*0x102026*/
      result += 8; /*0x102028*/
      v1 >>= 8; /*0x10202b*/
      if ( (_BYTE)v1 ) /*0x102030*/
        break; /*0x102030*/
      result += 8; /*0x102032*/
      v1 >>= 8; /*0x102035*/
      if ( (_BYTE)v1 ) /*0x10203a*/
        break; /*0x10203a*/
      result += 8; /*0x10203c*/
      v1 >>= 8; /*0x10203f*/
      if ( (_BYTE)v1 ) /*0x102044*/
        break; /*0x102044*/
      result += 8; /*0x102046*/
      v1 >>= 8; /*0x102049*/
      if ( (_BYTE)v1 ) /*0x10204e*/
        break; /*0x10204e*/
      result += 8; /*0x102050*/
      v1 >>= 8; /*0x102053*/
      if ( (_BYTE)v1 ) /*0x102058*/
        break; /*0x102058*/
      result += 8; /*0x10205a*/
      v1 >>= 8; /*0x10205d*/
    }
    while ( !(_BYTE)v1 ); /*0x102062*/
  }
  while ( (v1 & 1) == 0 ) /*0x1020a3*/
  {
    ++result; /*0x102068*/
    v3 = v1 >> 1; /*0x102069*/
    if ( (v3 & 1) != 0 ) /*0x10206e*/
      break; /*0x10206e*/
    ++result; /*0x102070*/
    v4 = v3 >> 1; /*0x102071*/
    if ( (v4 & 1) != 0 ) /*0x102076*/
      break; /*0x102076*/
    ++result; /*0x102078*/
    v5 = v4 >> 1; /*0x102079*/
    if ( (v5 & 1) != 0 ) /*0x10207e*/
      break; /*0x10207e*/
    ++result; /*0x102080*/
    v6 = v5 >> 1; /*0x102081*/
    if ( (v6 & 1) != 0 ) /*0x102086*/
      break; /*0x102086*/
    ++result; /*0x102088*/
    v7 = v6 >> 1; /*0x102089*/
    if ( (v7 & 1) != 0 ) /*0x10208e*/
      break; /*0x10208e*/
    ++result; /*0x102090*/
    v8 = v7 >> 1; /*0x102091*/
    if ( (v8 & 1) != 0 ) /*0x102096*/
      break; /*0x102096*/
    ++result; /*0x102098*/
    v9 = v8 >> 1; /*0x102099*/
    if ( (v9 & 1) != 0 ) /*0x10209e*/
      break; /*0x10209e*/
    ++result; /*0x1020a0*/
    v1 = v9 >> 1; /*0x1020a1*/
  }
  return result; /*0x101ffe*/
}
