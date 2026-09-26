/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1679ec. */
int __cdecl thread_dowait(int a1, int a2)
{
  int v2; // edi
  volatile __int32 *v3; // edx
  volatile __int32 *v4; // esi
  int v6; // [esp+Ch] [ebp-8h]
  int v7; // [esp+10h] [ebp-4h]

  v7 = 0; /*0x1679f8*/
  if ( active_threads == a1 ) /*0x167a05*/
    panic(aThreadDowait); /*0x167a0c*/
  v2 = 0; /*0x167a14*/
  v6 = splsched(); /*0x167a1b*/
  v3 = (volatile __int32 *)(a1 + 32); /*0x167a1e*/
  do /*0x167a36*/
  {
    while ( *v3 ) /*0x167a24*/
      ; /*0x167a26*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x167a36*/
  v4 = (volatile __int32 *)(a1 + 32); /*0x167a38*/
  while ( 2 ) /*0x167a4e*/
  {
    switch ( *(_DWORD *)(a1 + 76) & 0xF ) /*0x167a4e*/
    {
      case 6: /*0x167a4e*/
        if ( !rem_runq((_DWORD *)a1) ) /*0x167a9b*/
          goto LABEL_10; /*0x167a9b*/
        *(_DWORD *)(a1 + 76) &= ~4u; /*0x167a9d*/
        v2 = *(_DWORD *)(a1 + 72); /*0x167aa1*/
        *(_DWORD *)(a1 + 72) = 0; /*0x167aa4*/
        break; /*0x167aab*/
      case 7: /*0x167a4e*/
      case 0xB: /*0x167a4e*/
      case 0xE: /*0x167a4e*/
      case 0xF: /*0x167a4e*/
LABEL_10:
        *(_DWORD *)(a1 + 72) = 1; /*0x167ab0*/
        thread_sleep(a1 + 72, (volatile __int32 *)(a1 + 32), 1); /*0x167abe*/
        do /*0x167ada*/
        {
          while ( *v4 ) /*0x167ac8*/
            ; /*0x167aca*/
        }
        while ( _InterlockedExchange(v4, 1) == 1 ); /*0x167ada*/
        if ( !*(_DWORD *)(active_threads + 68) || a2 ) /*0x167aef*/
          continue; /*0x167aef*/
        v7 = 5; /*0x167af5*/
        break; /*0x167af5*/
      default:
        goto LABEL_16;
    }
    break;
  }
LABEL_16:
  _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x167afc*/
  splx(v6); /*0x167b05*/
  if ( v2 ) /*0x167b0f*/
    thread_wakeup_prim(a1 + 72, 0, 0); /*0x167b19*/
  return v7; /*0x167b24*/
}
