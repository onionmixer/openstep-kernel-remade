/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x155a9c. */
int __cdecl mach_port_get_receive_status(int a1, int a2, _DWORD *a3)
{
  int result; // eax
  int v4; // ebx
  int v5; // eax
  volatile __int32 *v6; // edx
  volatile __int32 *v7; // edx
  volatile __int32 *v8; // eax
  volatile __int32 *v9; // edx
  volatile __int32 *v10; // [esp+8h] [ebp-4h] BYREF

  if ( !a1 ) /*0x155aac*/
    return 16; /*0x155ab3*/
  result = ipc_object_translate(a1, a2, 1, &v10); /*0x155ac3*/
  if ( !result ) /*0x155acd*/
  {
    if ( *((_DWORD *)v10 + 12) ) /*0x155ad6*/
    {
      v4 = *((_DWORD *)v10 + 12); /*0x155add*/
      do /*0x155af2*/
      {
        while ( *(_DWORD *)v4 ) /*0x155ae0*/
          ; /*0x155ae2*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v4, 1) == 1 ); /*0x155af2*/
      if ( *(int *)(v4 + 8) < 0 ) /*0x155af8*/
      {
        *a3 = *(_DWORD *)(v4 + 12); /*0x155b2f*/
        v6 = (volatile __int32 *)(v4 + 16); /*0x155b31*/
        do /*0x155b46*/
        {
          while ( *v6 ) /*0x155b34*/
            ; /*0x155b36*/
        }
        while ( _InterlockedExchange(v6, 1) == 1 ); /*0x155b46*/
        a3[1] = *((_DWORD *)v10 + 13); /*0x155b4e*/
        _InterlockedExchange((volatile __int32 *)(v4 + 16), 0); /*0x155b53*/
        _InterlockedExchange((volatile __int32 *)v4, 0); /*0x155b58*/
        goto LABEL_19; /*0x155b5a*/
      }
      ipc_pset_remove(v4, (int)v10); /*0x155aff*/
      v5 = *(_DWORD *)(v4 + 4); /*0x155b07*/
      _InterlockedExchange((volatile __int32 *)v4, 0); /*0x155b0c*/
      if ( !v5 ) /*0x155b10*/
        zfree(ipc_object_zones[*(_WORD *)(v4 + 10) & 0x7FFF], v4); /*0x155b24*/
    }
    *a3 = 0; /*0x155b5c*/
    v7 = v10 + 16; /*0x155b65*/
    do /*0x155b7a*/
    {
      while ( *v7 ) /*0x155b68*/
        ; /*0x155b6a*/
    }
    while ( _InterlockedExchange(v7, 1) == 1 ); /*0x155b7a*/
    v8 = v10; /*0x155b7c*/
    a3[1] = *((_DWORD *)v10 + 13); /*0x155b82*/
    _InterlockedExchange(v8 + 16, 0); /*0x155b87*/
LABEL_19:
    v9 = v10; /*0x155b8a*/
    a3[2] = *((_DWORD *)v10 + 6); /*0x155b90*/
    a3[3] = *((_DWORD *)v9 + 15); /*0x155b96*/
    a3[4] = *((_DWORD *)v9 + 14); /*0x155b9c*/
    a3[5] = *((_DWORD *)v9 + 8); /*0x155ba2*/
    a3[6] = *((_DWORD *)v9 + 7) != 0; /*0x155bb1*/
    a3[7] = *((_DWORD *)v9 + 10) != 0; /*0x155bc0*/
    a3[8] = *((_DWORD *)v9 + 9) != 0; /*0x155bcf*/
    _InterlockedExchange(v9, 0); /*0x155bd4*/
    return 0; /*0x155bd6*/
  }
  return result; /*0x155bdb*/
}
