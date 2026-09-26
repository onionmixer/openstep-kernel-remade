/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14db68. */
int __cdecl ipc_right_reverse(_DWORD *a1, int a2, unsigned int *a3, int **a4)
{
  unsigned int v4; // ebx
  int *v5; // eax

  do /*0x14db8e*/
  {
    while ( *(_DWORD *)a2 ) /*0x14db7c*/
      ; /*0x14db7e*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a2, 1) == 1 ); /*0x14db8e*/
  if ( *(int *)(a2 + 8) >= 0 ) /*0x14db94*/
    goto LABEL_7; /*0x14db94*/
  if ( *(_DWORD **)(a2 + 12) != a1 ) /*0x14db99*/
  {
    if ( ipc_hash_lookup((int)a1, a2, (int)a3, (int)a4) ) /*0x14dbb0*/
      return 1; /*0x14dbb7*/
LABEL_7:
    _InterlockedExchange((volatile __int32 *)a2, 0); /*0x14dbb9*/
    return 0; /*0x14dbbf*/
  }
  v4 = *(_DWORD *)(a2 + 16); /*0x14db9b*/
  v5 = ipc_entry_lookup(a1, v4); /*0x14dba0*/
  *a3 = v4; /*0x14dba5*/
  *a4 = v5; /*0x14dba7*/
  return 1; /*0x14dbcc*/
}
