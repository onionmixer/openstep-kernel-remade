/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x142de8. */
int __cdecl getmp(__int16 a1)
{
  int v1; // ebx
  int v2; // eax
  int v3; // eax

  v1 = mounttab; /*0x142df0*/
  if ( !mounttab ) /*0x142df8*/
    return 0; /*0x142e43*/
  while ( 1 ) /*0x142dfc*/
  {
    v2 = *(_DWORD *)(v1 + 12); /*0x142dfc*/
    if ( v2 ) /*0x142e01*/
    {
      if ( *(_WORD *)(v1 + 4) == a1 ) /*0x142e07*/
        break; /*0x142e07*/
    }
    v1 = *(_DWORD *)(v1 + 32); /*0x142e3c*/
    if ( !v1 ) /*0x142e41*/
      return 0; /*0x142e41*/
  }
  v3 = *(_DWORD *)(v2 + 32); /*0x142e09*/
  if ( *(_DWORD *)(v3 + 1372) != 72020 ) /*0x142e16*/
  {
    printf("dev = 0x%x, fs = %s\n", a1, (const char *)(v3 + 212)); /*0x142e27*/
    panic(aGetmpBadMagic); /*0x142e31*/
  }
  return v1; /*0x142e45*/
}
