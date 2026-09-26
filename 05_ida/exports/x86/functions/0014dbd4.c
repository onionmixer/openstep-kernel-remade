/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14dbd4. */
int __cdecl ipc_right_dnrequest(int a1, unsigned int a2, int a3, int a4, _DWORD *a5)
{
  int v5; // ecx
  int result; // eax
  int *v7; // eax
  int v8; // ecx
  int v9; // ebx
  volatile __int32 *v10; // edi
  int v11; // eax
  int v12; // esi
  int v13; // eax
  unsigned int *v14; // eax
  unsigned int v15; // esi
  int v16; // [esp+Ch] [ebp-10h]
  int v17; // [esp+Ch] [ebp-10h]
  volatile __int32 *v18; // [esp+10h] [ebp-Ch]
  int v19; // [esp+14h] [ebp-8h] BYREF
  int *v20; // [esp+18h] [ebp-4h]

  v5 = a1; /*0x14dbdd*/
  v18 = (volatile __int32 *)(a1 + 8); /*0x14dbe3*/
  while ( 1 ) /*0x14dc00*/
  {
    do /*0x14dc00*/
    {
      while ( *v18 ) /*0x14dbeb*/
        ; /*0x14dbed*/
    }
    while ( _InterlockedExchange(v18, 1) == 1 ); /*0x14dc00*/
    if ( !*(_DWORD *)(v5 + 12) ) /*0x14dc02*/
    {
      _InterlockedExchange((volatile __int32 *)(v5 + 8), 0); /*0x14dc0a*/
      return 16; /*0x14dc12*/
    }
    v16 = v5; /*0x14dc1d*/
    v7 = ipc_entry_lookup((_DWORD *)v5, a2); /*0x14dc20*/
    v8 = v16; /*0x14dc28*/
    if ( !v7 ) /*0x14dc2d*/
      goto LABEL_24; /*0x14dc2d*/
    v20 = v7; /*0x14dc33*/
    v9 = *v7; /*0x14dc36*/
    if ( (*v7 & 0x70000) == 0 ) /*0x14dc3e*/
      goto LABEL_26; /*0x14dc3e*/
    v10 = (volatile __int32 *)v7[1]; /*0x14dc44*/
    v11 = ipc_right_check(v16, v10, a2, v7); /*0x14dc51*/
    v8 = v16; /*0x14dc59*/
    if ( v11 ) /*0x14dc5e*/
      break; /*0x14dc5e*/
    if ( !a4 ) /*0x14dc68*/
    {
      if ( (v9 & 0x400000) != 0 || !v20[2] ) /*0x14dc75*/
      {
        v12 = 0; /*0x14dc94*/
      }
      else
      {
        v12 = ipc_right_dncancel(v16, v10, a2, v20); /*0x14dc8a*/
        v8 = v16; /*0x14dc8c*/
      }
      _InterlockedExchange(v10, 0); /*0x14dc98*/
LABEL_22:
      _InterlockedExchange((volatile __int32 *)(v8 + 8), 0); /*0x14dd19*/
LABEL_36:
      *a5 = v12; /*0x14dda8*/
      return 0; /*0x14ddad*/
    }
    if ( v20[2] ) /*0x14dc9f*/
    {
      v12 = ipc_right_dncancel(v16, v10, a2, v20); /*0x14dcb7*/
      v8 = v16; /*0x14dcb9*/
    }
    else
    {
      v12 = 0; /*0x14dcc0*/
    }
    v17 = v8; /*0x14dccf*/
    v13 = ipc_port_dnrequest((int)v10, a2, a4, &v19); /*0x14dcd2*/
    v8 = v17; /*0x14dcda*/
    if ( !v13 ) /*0x14dcdf*/
    {
      _InterlockedExchange(v10, 0); /*0x14dd06*/
      v14 = (unsigned int *)v20; /*0x14dd08*/
      v20[2] = v19; /*0x14dd0e*/
      *v14 = v9 & 0xFFBFFFFF; /*0x14dd17*/
      goto LABEL_22; /*0x14dd17*/
    }
    _InterlockedExchange((volatile __int32 *)(v17 + 8), 0); /*0x14dce3*/
    result = ipc_port_dngrow((int)v10); /*0x14dcea*/
    v5 = v17; /*0x14dcf2*/
    if ( result ) /*0x14dcf7*/
      return result; /*0x14dcf7*/
  }
  if ( (v9 & 0x400000) != 0 ) /*0x14dd2a*/
  {
LABEL_24:
    _InterlockedExchange((volatile __int32 *)(v8 + 8), 0); /*0x14dd2c*/
    return 15; /*0x14dd36*/
  }
  v9 = *v20; /*0x14dd3b*/
LABEL_26:
  if ( (v9 & 0x100000) != 0 && a3 && a4 ) /*0x14dd4f*/
  {
    v15 = (unsigned __int16)v9 + 1; /*0x14dd54*/
    if ( v15 <= (unsigned __int16)v9 || v15 > 0xFFFF ) /*0x14dd61*/
    {
      _InterlockedExchange((volatile __int32 *)(v8 + 8), 0); /*0x14dd65*/
      return 19; /*0x14dd6d*/
    }
    *v20 = v9 + 1; /*0x14dd74*/
    _InterlockedExchange((volatile __int32 *)(v8 + 8), 0); /*0x14dd78*/
    ipc_notify_dead_name(a4, a2); /*0x14dd83*/
    v12 = 0; /*0x14dd88*/
    goto LABEL_36; /*0x14dd8a*/
  }
  _InterlockedExchange((volatile __int32 *)(v8 + 8), 0); /*0x14dd8e*/
  if ( (v9 & 0x170000) != 0 ) /*0x14dd97*/
    return 4; /*0x14dd99*/
  else
    return 17; /*0x14dda0*/
}
