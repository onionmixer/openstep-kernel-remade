/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x167d48. */
kern_return_t __cdecl thread_resume(thread_act_t target_act)
{
  kern_return_t v2; // esi
  int v3; // edi
  volatile __int32 *v4; // edx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // edx

  if ( !target_act ) /*0x167d53*/
    return 4; /*0x167d55*/
  v2 = 0; /*0x167d5c*/
  v3 = splsched(); /*0x167d63*/
  v4 = (volatile __int32 *)(target_act + 32); /*0x167d65*/
  do /*0x167d7a*/
  {
    while ( *v4 ) /*0x167d68*/
      ; /*0x167d6a*/
  }
  while ( _InterlockedExchange(v4, 1) == 1 ); /*0x167d7a*/
  v5 = *(_DWORD *)(target_act + 140); /*0x167d7c*/
  if ( v5 <= 0 ) /*0x167d84*/
  {
    v2 = 5; /*0x167dc4*/
  }
  else
  {
    *(_DWORD *)(target_act + 140) = v5 - 1; /*0x167d89*/
    if ( v5 == 1 ) /*0x167d92*/
    {
      v6 = *(_DWORD *)(target_act + 64); /*0x167d94*/
      *(_DWORD *)(target_act + 64) = v6 - 1; /*0x167d9a*/
      if ( v6 == 1 ) /*0x167da0*/
      {
        v7 = *(_DWORD *)(target_act + 76); /*0x167da2*/
        v8 = v7; /*0x167da5*/
        LOBYTE(v8) = v7 & 0xED; /*0x167da7*/
        *(_DWORD *)(target_act + 76) = v8; /*0x167daa*/
        if ( (v7 & 5) == 0 ) /*0x167daf*/
        {
          LOBYTE(v8) = v7 & 0xE9 | 4; /*0x167db1*/
          *(_DWORD *)(target_act + 76) = v8; /*0x167db4*/
          thread_setrun((char **)target_act, 1); /*0x167dba*/
        }
      }
    }
  }
  _InterlockedExchange((volatile __int32 *)(target_act + 32), 0); /*0x167dcb*/
  splx(v3); /*0x167dcf*/
  return v2; /*0x167dd9*/
}
