/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14df98. */
void __cdecl ipc_right_clean(int a1, int a2, int a3)
{
  unsigned int v3; // esi
  volatile __int32 *v4; // edx
  int v5; // ebx
  int v6; // ecx
  int v7; // eax
  int v8; // edi
  int v9; // eax
  int v10; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  v3 = *(_DWORD *)a3 & 0x1F0000; /*0x14dfa6*/
  if ( v3 == 196608 ) /*0x14dfb2*/
  {
LABEL_16:
    v5 = *(_DWORD *)(a3 + 4); /*0x14e01c*/
    v11 = 0; /*0x14e01f*/
    v10 = 0; /*0x14e026*/
    do /*0x14e042*/
    {
      while ( *(_DWORD *)v5 ) /*0x14e030*/
        ; /*0x14e032*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v5, 1) == 1 ); /*0x14e042*/
    if ( *(int *)(v5 + 8) < 0 ) /*0x14e048*/
    {
      if ( *(_DWORD *)(a3 + 8) ) /*0x14e07c*/
      {
        v7 = ipc_port_dncancel(v5, a2, *(_DWORD *)(a3 + 8)); /*0x14e089*/
        *(_DWORD *)(a3 + 8) = 0; /*0x14e08e*/
        if ( (*(_BYTE *)(a3 + 2) & 0x40) != 0 ) /*0x14e09c*/
        {
          ipc_space_release(a1); /*0x14e0a2*/
          v7 = 0; /*0x14e0a7*/
        }
        v8 = v7; /*0x14e0ac*/
      }
      else
      {
        v8 = 0; /*0x14e0b0*/
      }
      if ( (v3 & 0x10000) != 0 ) /*0x14e0b8*/
      {
        v9 = *(_DWORD *)(v5 + 28); /*0x14e0ba*/
        *(_DWORD *)(v5 + 28) = v9 - 1; /*0x14e0c0*/
        if ( v9 == 1 ) /*0x14e0c6*/
        {
          v11 = *(_DWORD *)(v5 + 36); /*0x14e0cb*/
          if ( v11 ) /*0x14e0d0*/
          {
            *(_DWORD *)(v5 + 36) = 0; /*0x14e0d2*/
            v10 = *(_DWORD *)(v5 + 24); /*0x14e0dc*/
          }
        }
      }
      if ( (v3 & 0x20000) != 0 ) /*0x14e0e5*/
      {
        ipc_port_clear_receiver(v5); /*0x14e0e8*/
        ipc_port_destroy(v5); /*0x14e0ee*/
      }
      else if ( (v3 & 0x40000) != 0 ) /*0x14e0fe*/
      {
        _InterlockedExchange((volatile __int32 *)v5, 0); /*0x14e102*/
        ipc_notify_send_once(v5); /*0x14e105*/
      }
      else
      {
        --*(_DWORD *)(v5 + 4); /*0x14e110*/
        _InterlockedExchange((volatile __int32 *)v5, 0); /*0x14e115*/
      }
      if ( v11 ) /*0x14e11b*/
        ipc_notify_no_senders(v11, v10); /*0x14e125*/
      if ( v8 ) /*0x14e12f*/
        ipc_notify_port_deleted(v8, a2); /*0x14e136*/
    }
    else
    {
      v6 = *(_DWORD *)(v5 + 4) - 1; /*0x14e04d*/
      *(_DWORD *)(v5 + 4) = v6; /*0x14e050*/
      _InterlockedExchange((volatile __int32 *)v5, 0); /*0x14e056*/
      if ( !v6 ) /*0x14e05a*/
        zfree(ipc_object_zones[*(_WORD *)(v5 + 10) & 0x7FFF], v5); /*0x14e072*/
    }
    return; /*0x14e077*/
  }
  if ( v3 <= 0x30000 ) /*0x14dfb4*/
  {
    if ( v3 != 0x10000 && v3 != 0x20000 ) /*0x14dfc4*/
LABEL_40:
      panic(aIpcRightCleanS); /*0x14e140*/
    goto LABEL_16; /*0x14dfc4*/
  }
  if ( v3 == 0x80000 ) /*0x14dfd2*/
  {
    v4 = *(volatile __int32 **)(a3 + 4); /*0x14dff8*/
    do /*0x14e00e*/
    {
      while ( *v4 ) /*0x14dffc*/
        ; /*0x14dffe*/
    }
    while ( _InterlockedExchange(v4, 1) == 1 ); /*0x14e00e*/
    ipc_pset_destroy((int)v4); /*0x14e011*/
    return; /*0x14e016*/
  }
  if ( v3 <= 0x80000 ) /*0x14dfd4*/
  {
    if ( v3 != 0x40000 ) /*0x14dfdc*/
      goto LABEL_40; /*0x14dfdc*/
    goto LABEL_16; /*0x14dfdc*/
  }
  if ( (int *)v3 != &dword_100000 ) /*0x14dfea*/
    goto LABEL_40; /*0x14dfea*/
}
