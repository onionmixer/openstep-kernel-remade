/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18f58c. */
_DWORD *__cdecl sub_18F58C(int *a1)
{
  _BYTE *v1; // eax
  _DWORD *v2; // eax
  unsigned int v3; // eax
  _DWORD *result; // eax
  unsigned int v5; // ecx
  _DWORD *v6; // edx

  sub_18F40C(a1); /*0x18f595*/
  if ( !*a1 ) /*0x18f59d*/
    panic(aPmapCreatePage); /*0x18f5a7*/
  if ( *a1 != (*a1 & 0xFFFFF000) ) /*0x18f5b8*/
    panic(aPmapCreatePage_0); /*0x18f5bf*/
  v1 = (_BYTE *)(*(_DWORD *)kernel_pmap + 4 * ((unsigned int)*a1 >> 22)); /*0x18f5d4*/
  if ( (*v1 & 1) != 0 /*0x18f5f4*/
    && (v2 = (_DWORD *)((*(_DWORD *)v1 & 0xFFFFF000) + (((unsigned int)*a1 >> 10) & 0xFFC))) != nullptr
    && (*(_BYTE *)v2 & 1) != 0 )
  {
    v3 = (*v2 & 0xFFFFF000) + (*a1 & 0xFFF); /*0x18f60b*/
  }
  else
  {
    v3 = 0; /*0x18f5f6*/
  }
  a1[1] = v3; /*0x18f60d*/
  result = *(_DWORD **)kernel_pmap; /*0x18f615*/
  v5 = *(_DWORD *)kernel_pmap + 1024; /*0x18f617*/
  v6 = (_DWORD *)(*a1 + 3072); /*0x18f61f*/
  if ( *(_DWORD *)kernel_pmap < v5 ) /*0x18f627*/
  {
    do /*0x18f638*/
      *v6++ = *result++; /*0x18f62e*/
    while ( (unsigned int)result < v5 ); /*0x18f638*/
  }
  return result; /*0x18f63d*/
}
