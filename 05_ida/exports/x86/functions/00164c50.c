/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x164c50. */
int __cdecl do_runq_scan(int a1)
{
  volatile __int32 *v1; // edx
  int v2; // edi
  _DWORD **v3; // ebx
  _DWORD *v4; // edx
  _DWORD *v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+10h] [ebp-8h]
  int v8; // [esp+14h] [ebp-4h]

  v8 = splsched(); /*0x164c5e*/
  v1 = (volatile __int32 *)(a1 + 256); /*0x164c64*/
  do /*0x164c7e*/
  {
    while ( *v1 ) /*0x164c6c*/
      ; /*0x164c6e*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x164c7e*/
  v2 = *(_DWORD *)(a1 + 264); /*0x164c83*/
  if ( v2 > 0 )
  {
    v3 = (_DWORD **)(8 * *(_DWORD *)(a1 + 260) + a1); /*0x164ca0*/
    do
    {
      v4 = *v3; /*0x164ca4*/
      if ( v3 != *v3 )
      {
        do
        {
          v6 = (_DWORD *)*v4; /*0x164cb2*/
          if ( (v4[19] & 0xF) == 4 && (unsigned int)(sched_tick - v4[28]) > 1 )
          {
            v7 = stuck_count; /*0x164cd7*/
            if ( stuck_count == 128 ) /*0x164ce0*/
            {
              _InterlockedExchange((volatile __int32 *)(a1 + 256), 0); /*0x164ce7*/
              splx(v8); /*0x164cf1*/
              return 1; /*0x164cfb*/
            }
            v6[1] = v4[1]; /*0x164d06*/
            *(_DWORD *)v4[1] = *v4; /*0x164d0e*/
            --*(_DWORD *)(a1 + 264); /*0x164d13*/
            v4[2] = 0; /*0x164d19*/
            stuck_threads[v7] = (int)v4; /*0x164d23*/
            ++stuck_count; /*0x164d2a*/
            if ( do_thread_scan_debug )
              printf("do_runq_scan: adding thread %#x\n", v4);
          }
          --v2; /*0x164d47*/
          v4 = v6; /*0x164d48*/
        }
        while ( v3 != v6 );
      }
      v3 -= 2; /*0x164d53*/
    }
    while ( v2 > 0 );
  }
  _InterlockedExchange((volatile __int32 *)(a1 + 256), 0); /*0x164d63*/
  splx(v8); /*0x164d6d*/
  return 0; /*0x164d77*/
}
