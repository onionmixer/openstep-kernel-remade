/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14f938. */
int __cdecl ipc_right_copyin_two(_DWORD *a1, unsigned int a2, int a3, int *a4, int *a5)
{
  int v5; // edx
  int v6; // ebx
  int v7; // esi
  unsigned int v8; // esi
  int v9; // eax
  int v11; // [esp+Ch] [ebp-Ch]
  int v12; // [esp+14h] [ebp-4h]

  v5 = *(_DWORD *)a3; /*0x14f944*/
  v12 = *(_DWORD *)a3; /*0x14f946*/
  v11 = 0; /*0x14f949*/
  if ( (*(_DWORD *)a3 & 0x10000) == 0 || (unsigned __int16)v5 <= 1u ) /*0x14f965*/
    return 17; /*0x14fb19*/
  v6 = *(_DWORD *)(a3 + 4); /*0x14f96b*/
  do /*0x14f982*/
  {
    while ( *(_DWORD *)v6 ) /*0x14f970*/
      ; /*0x14f972*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v6, 1) == 1 ); /*0x14f982*/
  if ( *(int *)(v6 + 8) < 0 ) /*0x14f988*/
  {
    if ( (unsigned __int16)v5 == 2 ) /*0x14fa4c*/
    {
      if ( (v12 & 0x20000) != 0 ) /*0x14fa5b*/
      {
        ++*(_DWORD *)(v6 + 28); /*0x14fa5d*/
        *(_DWORD *)(v6 + 4) += 2; /*0x14fa60*/
      }
      else
      {
        if ( *(_DWORD *)(a3 + 8) ) /*0x14fa68*/
        {
          v9 = ipc_port_dncancel(v6, a2, *(_DWORD *)(a3 + 8)); /*0x14fa75*/
          *(_DWORD *)(a3 + 8) = 0; /*0x14fa7a*/
          if ( (*(_BYTE *)(a3 + 2) & 0x40) != 0 ) /*0x14fa88*/
          {
            ipc_space_release(a1); /*0x14fa8e*/
            v9 = 0; /*0x14fa93*/
          }
          v11 = v9; /*0x14fa98*/
        }
        else
        {
          v11 = 0; /*0x14faa0*/
        }
        ipc_hash_delete((int)a1, v6, a2, a3); /*0x14fab1*/
        if ( (v12 & 0x200000) != 0 ) /*0x14fac2*/
          ipc_marequest_cancel((unsigned int)a1, a2); /*0x14facc*/
        ++*(_DWORD *)(v6 + 28); /*0x14fad1*/
        ++*(_DWORD *)(v6 + 4); /*0x14fad4*/
        *(_DWORD *)(a3 + 4) = 0; /*0x14fad7*/
      }
      *(_DWORD *)a3 = v12 & 0xFFFE0000; /*0x14fae7*/
    }
    else
    {
      *(_DWORD *)(v6 + 28) += 2; /*0x14faec*/
      *(_DWORD *)(v6 + 4) += 2; /*0x14faf0*/
      *(_DWORD *)a3 = v12 - 2; /*0x14fafa*/
    }
    _InterlockedExchange((volatile __int32 *)v6, 0); /*0x14fafe*/
    *a4 = v6; /*0x14fb03*/
    *a5 = v11; /*0x14fb0b*/
    return 0; /*0x14fb0d*/
  }
  else
  {
    _InterlockedExchange((volatile __int32 *)v6, 0); /*0x14f990*/
    v7 = *(_DWORD *)a3; /*0x14f992*/
    if ( (*(_DWORD *)a3 & 0x10000) != 0 ) /*0x14f99a*/
    {
      if ( (v7 & 0x200000) != 0 ) /*0x14f9a2*/
      {
        v7 &= ~0x200000u; /*0x14f9a4*/
        ipc_marequest_cancel((unsigned int)a1, a2); /*0x14f9b2*/
      }
      ipc_hash_delete((int)a1, v6, a2, a3); /*0x14f9c4*/
    }
    ipc_object_release(v6); /*0x14f9cd*/
    if ( (v7 & 0x400000) != 0 ) /*0x14f9db*/
    {
      *(_DWORD *)(a3 + 8) = 0; /*0x14f9dd*/
      *(_DWORD *)(a3 + 4) = 0; /*0x14f9e4*/
      ipc_entry_dealloc(a1, a2, (int *)a3); /*0x14f9f4*/
    }
    else
    {
      v8 = v7 & 0xFFE0FFFF | 0x100000; /*0x14fa0d*/
      if ( *(_DWORD *)(a3 + 8) ) /*0x14fa13*/
      {
        *(_DWORD *)(a3 + 8) = 0; /*0x14fa19*/
        ++v8; /*0x14fa20*/
      }
      *(_DWORD *)a3 = v8; /*0x14fa21*/
      *(_DWORD *)(a3 + 4) = 0; /*0x14fa23*/
    }
    if ( (v12 & 0x400000) == 0 ) /*0x14fa3c*/
      return 17; /*0x14fa3c*/
    return 15; /*0x14fb1c*/
  }
}
