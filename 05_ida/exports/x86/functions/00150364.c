/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x150364. */
int __cdecl ipc_right_copyin_header(unsigned int a1, unsigned int a2, int a3, int *a4, _DWORD *a5)
{
  int *v5; // eax
  int v6; // ebx
  int v7; // esi
  unsigned int v8; // esi
  int v9; // ebx
  unsigned int v10; // ebx
  int v11; // eax
  int v12; // esi
  int v13; // ebx
  int v15; // [esp+Ch] [ebp-8h]
  int v16; // [esp+10h] [ebp-4h]

  v16 = *(_DWORD *)a3; /*0x150372*/
  v5 = (int *)(*(_DWORD *)a3 & 0x1F0000); /*0x150377*/
  if ( v5 != (int *)196608 ) /*0x150381*/
  {
    if ( (*(_DWORD *)a3 & 0x1F0000u) > 0x30000 ) /*0x150383*/
    {
      if ( v5 == (int *)0x80000 ) /*0x15039d*/
      {
LABEL_58:
        _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x150688*/
        return 17; /*0x150695*/
      }
      if ( (unsigned int)v5 > 0x80000 ) /*0x1503a3*/
      {
        if ( v5 != &dword_100000 ) /*0x1503bd*/
          goto LABEL_56; /*0x1503bd*/
        goto LABEL_58; /*0x1503bd*/
      }
      if ( v5 != (int *)0x40000 ) /*0x1503aa*/
LABEL_56:
        panic(aIpcRightCopyin_2); /*0x150678*/
      v15 = *(_DWORD *)(a3 + 4); /*0x1504e3*/
      do /*0x150500*/
      {
        while ( *(_DWORD *)v15 ) /*0x1504eb*/
          ; /*0x1504ed*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v15, 1) == 1 ); /*0x150500*/
      if ( *(int *)(v15 + 8) < 0 ) /*0x150506*/
      {
        if ( *(_DWORD *)(a3 + 8) ) /*0x1505d0*/
        {
          v11 = ipc_port_dncancel(v15, a2, *(_DWORD *)(a3 + 8)); /*0x1505e0*/
          *(_DWORD *)(a3 + 8) = 0; /*0x1505e5*/
          if ( (*(_BYTE *)(a3 + 2) & 0x40) != 0 ) /*0x1505f3*/
          {
            ipc_space_release(a1); /*0x1505f9*/
            v11 = 0; /*0x1505fe*/
          }
          v12 = v11; /*0x150603*/
        }
        else
        {
          v12 = 0; /*0x150608*/
        }
        _InterlockedExchange((volatile __int32 *)v15, 0); /*0x15060f*/
        *(_DWORD *)(a3 + 4) = 0; /*0x150611*/
        ipc_entry_dealloc((_DWORD *)a1, a2, (int *)a3); /*0x150621*/
        v13 = ipc_port_copy_send(*(_DWORD *)(a1 + 68)); /*0x150632*/
        _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15063c*/
        if ( v12 ) /*0x150641*/
          ipc_notify_port_deleted(v12, a2); /*0x150648*/
        if ( v13 && v13 != -1 ) /*0x150657*/
          ipc_notify_port_deleted_compat(v13, a2); /*0x15065e*/
        *a4 = v15; /*0x150669*/
        *a5 = 18; /*0x15066e*/
        return 0; /*0x150674*/
      }
      _InterlockedExchange((volatile __int32 *)v15, 0); /*0x150511*/
      v9 = *(_DWORD *)a3; /*0x150513*/
      if ( (*(_DWORD *)a3 & 0x10000) != 0 ) /*0x15051b*/
      {
        if ( (v9 & 0x200000) != 0 ) /*0x150523*/
        {
          v9 &= ~0x200000u; /*0x150525*/
          ipc_marequest_cancel(a1, a2); /*0x150533*/
        }
        ipc_hash_delete(a1, v15, a2, a3); /*0x150548*/
      }
      ipc_object_release(v15); /*0x150554*/
      if ( (v9 & 0x400000) != 0 ) /*0x150562*/
        goto LABEL_25; /*0x150562*/
      v10 = v9 & 0xFFE0FFFF | 0x100000; /*0x150595*/
      if ( *(_DWORD *)(a3 + 8) ) /*0x15059b*/
      {
        *(_DWORD *)(a3 + 8) = 0; /*0x1505a1*/
        ++v10; /*0x1505a8*/
      }
      *(_DWORD *)a3 = v10; /*0x1505a9*/
      *(_DWORD *)(a3 + 4) = 0; /*0x1505ab*/
      goto LABEL_43; /*0x1505ab*/
    }
    if ( v5 != (int *)0x10000 ) /*0x15038a*/
    {
      if ( v5 != (int *)0x20000 ) /*0x150391*/
        goto LABEL_56; /*0x150391*/
      v6 = *(_DWORD *)(a3 + 4); /*0x1503c8*/
      do /*0x1503de*/
      {
        while ( *(_DWORD *)v6 ) /*0x1503cc*/
          ; /*0x1503ce*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v6, 1) == 1 ); /*0x1503de*/
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x1503e5*/
      ++*(_DWORD *)(v6 + 24); /*0x1503e8*/
      goto LABEL_30; /*0x1503eb*/
    }
  }
  v6 = *(_DWORD *)(a3 + 4); /*0x1503f0*/
  do /*0x150406*/
  {
    while ( *(_DWORD *)v6 ) /*0x1503f4*/
      ; /*0x1503f6*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v6, 1) == 1 ); /*0x150406*/
  if ( *(int *)(v6 + 8) < 0 ) /*0x15040c*/
  {
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x1504c0*/
LABEL_30:
    ++*(_DWORD *)(v6 + 28); /*0x1504c3*/
    ++*(_DWORD *)(v6 + 4); /*0x1504c6*/
    _InterlockedExchange((volatile __int32 *)v6, 0); /*0x1504cb*/
    *a4 = v6; /*0x1504d0*/
    *a5 = 17; /*0x1504d5*/
    return 0; /*0x150684*/
  }
  _InterlockedExchange((volatile __int32 *)v6, 0); /*0x150414*/
  v7 = *(_DWORD *)a3; /*0x150416*/
  if ( (*(_DWORD *)a3 & 0x10000) != 0 ) /*0x15041e*/
  {
    if ( (v7 & 0x200000) != 0 ) /*0x150426*/
    {
      v7 &= ~0x200000u; /*0x150428*/
      ipc_marequest_cancel(a1, a2); /*0x150436*/
    }
    ipc_hash_delete(a1, v6, a2, a3); /*0x150448*/
  }
  ipc_object_release(v6); /*0x150451*/
  if ( (v7 & 0x400000) != 0 ) /*0x15045f*/
  {
LABEL_25:
    *(_DWORD *)(a3 + 8) = 0; /*0x150461*/
    *(_DWORD *)(a3 + 4) = 0; /*0x150468*/
    ipc_entry_dealloc((_DWORD *)a1, a2, (int *)a3); /*0x150478*/
    goto LABEL_43; /*0x150482*/
  }
  v8 = v7 & 0xFFE0FFFF | 0x100000; /*0x150491*/
  if ( *(_DWORD *)(a3 + 8) ) /*0x150497*/
  {
    *(_DWORD *)(a3 + 8) = 0; /*0x15049d*/
    ++v8; /*0x1504a4*/
  }
  *(_DWORD *)a3 = v8; /*0x1504a5*/
  *(_DWORD *)(a3 + 4) = 0; /*0x1504a7*/
LABEL_43:
  if ( (v16 & 0x400000) == 0 ) /*0x1505c4*/
    goto LABEL_58; /*0x1505c4*/
  _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x15069d*/
  return 15; /*0x1506a8*/
}
