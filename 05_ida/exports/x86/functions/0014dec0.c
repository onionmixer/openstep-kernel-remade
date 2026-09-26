/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14dec0. */
int __cdecl ipc_right_check(_DWORD *a1, int a2, unsigned int a3, int *a4)
{
  int v5; // ebx
  unsigned int v6; // ebx

  do /*0x14dede*/
  {
    while ( *(_DWORD *)a2 ) /*0x14decc*/
      ; /*0x14dece*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a2, 1) == 1 ); /*0x14dede*/
  if ( *(int *)(a2 + 8) < 0 ) /*0x14dee4*/
    return 0; /*0x14dee6*/
  _InterlockedExchange((volatile __int32 *)a2, 0); /*0x14def2*/
  v5 = *a4; /*0x14def4*/
  if ( (*a4 & 0x10000) != 0 ) /*0x14defc*/
  {
    if ( (v5 & 0x200000) != 0 ) /*0x14df04*/
    {
      v5 &= ~0x200000u; /*0x14df06*/
      ipc_marequest_cancel((unsigned int)a1, a3); /*0x14df14*/
    }
    ipc_hash_delete((int)a1, a2, a3, (int)a4); /*0x14df26*/
  }
  ipc_object_release(a2); /*0x14df2f*/
  if ( (v5 & 0x400000) != 0 ) /*0x14df3d*/
  {
    a4[2] = 0; /*0x14df3f*/
    a4[1] = 0; /*0x14df46*/
    ipc_entry_dealloc(a1, a3, a4); /*0x14df56*/
  }
  else
  {
    v6 = v5 & 0xFFE0FFFF | 0x100000; /*0x14df69*/
    if ( a4[2] ) /*0x14df6f*/
    {
      a4[2] = 0; /*0x14df75*/
      ++v6; /*0x14df7c*/
    }
    *a4 = v6; /*0x14df7d*/
    a4[1] = 0; /*0x14df7f*/
  }
  return 1; /*0x14df8e*/
}
