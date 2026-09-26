/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1469e8. */
_BOOL4 __cdecl ipc_hash_global_lookup(unsigned int a1, unsigned int a2, _DWORD *a3, _DWORD *a4)
{
  int v4; // ecx
  _DWORD *v5; // edx
  _DWORD *v6; // eax

  v4 = ipc_hash_global_table + 8 * (ipc_hash_global_mask & ((a2 >> 6) + (a1 >> 4))); /*0x146a0a*/
  do /*0x146a22*/
  {
    while ( *(_DWORD *)v4 ) /*0x146a10*/
      ; /*0x146a12*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v4, 1) == 1 ); /*0x146a22*/
  v5 = *(_DWORD **)(v4 + 4); /*0x146a24*/
  if ( v5 ) /*0x146a29*/
  {
    if ( v5[1] == a2 && v5[5] == a1 ) /*0x146a36*/
    {
      *a3 = v5[4]; /*0x146a3e*/
      *a4 = v5; /*0x146a43*/
    }
    else
    {
      while ( 1 ) /*0x146a75*/
      {
        v6 = v5 + 3; /*0x146a75*/
        v5 = (_DWORD *)v5[3]; /*0x146a78*/
        if ( !v5 ) /*0x146a7d*/
          break; /*0x146a7d*/
        if ( v5[1] == a2 && v5[5] == a1 ) /*0x146a73*/
        {
          *v6 = v5[3]; /*0x146a4b*/
          v5[3] = *(_DWORD *)(v4 + 4); /*0x146a50*/
          *(_DWORD *)(v4 + 4) = v5; /*0x146a53*/
          *a3 = v5[4]; /*0x146a5c*/
          *a4 = v5; /*0x146a61*/
          break; /*0x146a63*/
        }
      }
    }
  }
  _InterlockedExchange((volatile __int32 *)v4, 0); /*0x146a7f*/
  return v5 != nullptr; /*0x146a90*/
}
