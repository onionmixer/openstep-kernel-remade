/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17a770. */
int __cdecl vm_set_policy(_DWORD *a1, unsigned int a2, int a3, int a4)
{
  unsigned int v4; // esi
  int v5; // eax
  int i; // ebx
  int j; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h]

  v4 = a2; /*0x17a77c*/
  v5 = a3; /*0x17a77f*/
  if ( !a1 ) /*0x17a784*/
    return 5; /*0x17a786*/
  if ( !a3 ) /*0x17a792*/
    v5 = a1[6] - a1[5]; /*0x17a797*/
  if ( !a2 ) /*0x17a79c*/
    v4 = a1[5]; /*0x17a79e*/
  v9 = v4 + v5; /*0x17a7a3*/
  lock_read((int)a1); /*0x17a7a7*/
  for ( i = a1[4]; (_DWORD *)i != a1 + 3; i = *(_DWORD *)(i + 4) ) /*0x17a7ac*/
  {
    if ( (*(_BYTE *)(i + 24) & 5) != 0 ) /*0x17a7b8*/
    {
      sub_17A6F4(*(_DWORD *)(i + 16), v4, v9, a4); /*0x17a7c7*/
    }
    else if ( *(_DWORD *)(i + 8) <= v9 && *(_DWORD *)(i + 12) > v4 ) /*0x17a7df*/
    {
      for ( j = *(_DWORD *)(i + 16); j; j = *(_DWORD *)(j + 32) ) /*0x17a7e6*/
        *(_WORD *)(j + 72) = a4; /*0x17a7ec*/
    }
  }
  lock_done((int)a1); /*0x17a802*/
  return 0; /*0x17a80c*/
}
