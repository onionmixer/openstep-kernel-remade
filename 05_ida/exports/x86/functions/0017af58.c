/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17af58. */
_DWORD *__cdecl vm_page_lookup(int a1, unsigned int a2)
{
  int v2; // esi
  _DWORD *i; // ebx
  int v5; // [esp+Ch] [ebp-4h]

  v2 = vm_page_buckets + 8 * (vm_page_hash_mask & (a1 + (a2 >> page_shift))); /*0x17af80*/
  v5 = splimp(); /*0x17af88*/
  do /*0x17af9e*/
  {
    while ( *(_DWORD *)v2 ) /*0x17af8c*/
      ; /*0x17af8e*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v2, 1) == 1 ); /*0x17af9e*/
  for ( i = *(_DWORD **)(v2 + 4); i; i = (_DWORD *)i[4] ) /*0x17afa5*/
  {
    if ( i[5] == a1 && i[6] == a2 ) /*0x17afb3*/
      break; /*0x17afb3*/
  }
  _InterlockedExchange((volatile __int32 *)v2, 0); /*0x17afbe*/
  splx(v5); /*0x17afc4*/
  return i; /*0x17afce*/
}
