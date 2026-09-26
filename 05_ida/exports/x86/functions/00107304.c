/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107304. */
int __cdecl spgrp(_DWORD *a1)
{
  int result; // eax
  _DWORD *i; // ecx
  _DWORD *v3; // edx

  result = 0; /*0x10730b*/
  for ( i = a1; ; i = v3 ) /*0x10730d*/
  {
    i[6] &= 0xFFCDFFFF; /*0x107310*/
    ++result; /*0x107317*/
    v3 = (_DWORD *)i[18]; /*0x107318*/
    if ( !v3 ) /*0x10731d*/
      break; /*0x10731d*/
LABEL_7:
    ; /*0x107332*/
  }
  while ( i != a1 ) /*0x107329*/
  {
    v3 = (_DWORD *)i[19]; /*0x10732b*/
    if ( v3 ) /*0x107330*/
      goto LABEL_7; /*0x107330*/
    i = (_DWORD *)i[17]; /*0x107324*/
  }
  return result; /*0x107338*/
}
