/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x113390. */
int __cdecl nextc3(_DWORD *a1, int a2, int *a3)
{
  int v3; // ebx
  int v4; // esi
  int v5; // edx
  int v6; // eax
  int v7; // edx

  if ( !*a1 ) /*0x11339f*/
    return 0; /*0x11339f*/
  v3 = a2 + 1; /*0x1133a4*/
  if ( a1[2] == a2 + 1 ) /*0x1133a8*/
    return 0; /*0x1133f0*/
  if ( (v3 & 0x3F) == 0 ) /*0x1133ad*/
    v3 = *(_DWORD *)(a2 - 63) + 12; /*0x1133b2*/
  v4 = *(char *)v3; /*0x1133b5*/
  *a3 = v4; /*0x1133b8*/
  v5 = v3; /*0x1133ba*/
  v6 = (v3 & 0x3F) >> 3; /*0x1133cb*/
  LOBYTE(v5) = v3 & 0xC0; /*0x1133bc*/
  v7 = *(char *)(v5 + v6 + 4); /*0x1133d2*/
  if ( _bittest(&v7, (v3 & 0x3F) - 8 * v6) ) /*0x1133dc*/
    *a3 = v4 | 0x100; /*0x1133e7*/
  return v3; /*0x1133f5*/
}
