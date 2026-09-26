/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15d9c0. */
int __cdecl netipc_ignore(int a1, int a2)
{
  _DWORD *v3; // edi
  _DWORD *v4; // ebx
  _DWORD *v5; // esi
  int v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+10h] [ebp-8h]
  volatile __int32 *v8; // [esp+14h] [ebp-4h]

  v7 = 5; /*0x15d9c9*/
  if ( !a2 ) /*0x15d9d4*/
    return 4; /*0x15d9d6*/
  v8 = (volatile __int32 *)&listeners; /*0x15d9e0*/
  if ( &listeners < (_UNKNOWN *)&mach_net_kmsg_zone ) /*0x15d9ee*/
  {
    v3 = &unk_1F6404; /*0x15d9f4*/
    do /*0x15daa9*/
    {
      v6 = splnet(); /*0x15da01*/
      do /*0x15da1c*/
      {
        while ( *v8 ) /*0x15da07*/
          ; /*0x15da09*/
      }
      while ( _InterlockedExchange(v8, 1) == 1 ); /*0x15da1c*/
      v4 = (_DWORD *)*v3; /*0x15da1e*/
      v5 = (_DWORD *)*v3; /*0x15da20*/
      if ( *v3 ) /*0x15da1e*/
      {
        do /*0x15da86*/
        {
          if ( v4[4] == a2 ) /*0x15da2e*/
          {
            v7 = 0; /*0x15da30*/
            if ( (_DWORD *)*v3 == v4 ) /*0x15da39*/
            {
              *v3 = *v4; /*0x15da3d*/
              zfree(listener_zone, v4); /*0x15da47*/
              v4 = (_DWORD *)*v3; /*0x15da4c*/
              v5 = (_DWORD *)*v3; /*0x15da4e*/
              if ( !*v3 ) /*0x15da55*/
                break; /*0x15da55*/
            }
            else
            {
              *v5 = *v4; /*0x15da5e*/
              zfree(listener_zone, v4); /*0x15da68*/
              v4 = v5; /*0x15da6d*/
            }
            ipc_object_release(a2); /*0x15da76*/
          }
          else
          {
            v5 = v4; /*0x15da80*/
          }
          v4 = (_DWORD *)*v4; /*0x15da82*/
        }
        while ( v4 ); /*0x15da86*/
      }
      _InterlockedExchange(v8, 0); /*0x15da88*/
      splx(v6); /*0x15da93*/
      v3 += 2; /*0x15da9b*/
      v8 += 2; /*0x15da9e*/
    }
    while ( v8 < &mach_net_kmsg_zone ); /*0x15daa9*/
  }
  return v7; /*0x15dab5*/
}
