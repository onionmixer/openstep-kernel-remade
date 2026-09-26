/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14efa0. */
int __cdecl ipc_right_info(unsigned int a1, unsigned int a2, int *a3, int *a4, _DWORD *a5)
{
  int v5; // edi
  int v6; // esi
  int v7; // ebx
  unsigned int v8; // ebx
  int v10; // eax

  v5 = *a3; /*0x14efa9*/
  if ( (*a3 & 0x50000) != 0 ) /*0x14efb1*/
  {
    v6 = a3[1]; /*0x14efb7*/
    do /*0x14efce*/
    {
      while ( *(_DWORD *)v6 ) /*0x14efbc*/
        ; /*0x14efbe*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v6, 1) == 1 ); /*0x14efce*/
    if ( *(int *)(v6 + 8) < 0 ) /*0x14efd4*/
    {
      _InterlockedExchange((volatile __int32 *)v6, 0); /*0x14f0ae*/
    }
    else
    {
      _InterlockedExchange((volatile __int32 *)v6, 0); /*0x14efdc*/
      v7 = *a3; /*0x14efe1*/
      if ( (*a3 & 0x10000) != 0 ) /*0x14efe9*/
      {
        if ( (v7 & 0x200000) != 0 ) /*0x14eff1*/
        {
          v7 &= ~0x200000u; /*0x14eff3*/
          ipc_marequest_cancel(a1, a2); /*0x14f001*/
        }
        ipc_hash_delete(a1, v6, a2, (int)a3); /*0x14f016*/
      }
      ipc_object_release(v6); /*0x14f01f*/
      if ( (v7 & 0x400000) != 0 ) /*0x14f02d*/
      {
        a3[2] = 0; /*0x14f032*/
        a3[1] = 0; /*0x14f039*/
        ipc_entry_dealloc((_DWORD *)a1, a2, a3); /*0x14f049*/
      }
      else
      {
        v8 = v7 & 0xFFE0FFFF | 0x100000; /*0x14f061*/
        if ( a3[2] ) /*0x14f06a*/
        {
          a3[2] = 0; /*0x14f070*/
          ++v8; /*0x14f077*/
        }
        *a3 = v8; /*0x14f07b*/
        a3[1] = 0; /*0x14f07d*/
      }
      if ( (v5 & 0x400000) != 0 ) /*0x14f093*/
      {
        _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14f09a*/
        return 15; /*0x14f0a2*/
      }
      v5 = *a3; /*0x14f0a7*/
    }
  }
  v10 = v5 & 0x1F0000; /*0x14f0b2*/
  if ( (v5 & 0x400000) != 0 ) /*0x14f0c3*/
  {
    v10 |= 0x20000000u; /*0x14f0c5*/
  }
  else if ( a3[2] ) /*0x14f0ba*/
  {
    v10 |= 0x80000000; /*0x14f0d0*/
  }
  if ( (v5 & 0x200000) != 0 ) /*0x14f0db*/
    v10 |= 0x40000000u; /*0x14f0dd*/
  *a4 = v10; /*0x14f0e5*/
  *a5 = (unsigned __int16)v5; /*0x14f0f0*/
  return 0; /*0x14f0f7*/
}
