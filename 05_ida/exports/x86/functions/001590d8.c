/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1590d8. */
int __cdecl thread_go_and_switch(int a1, int a2)
{
  int v2; // edi
  volatile __int32 *v3; // edx
  int v4; // edx
  int v5; // eax
  int v6; // edx

  v2 = splsched(); /*0x1590e9*/
  v3 = (volatile __int32 *)(a2 + 32); /*0x1590eb*/
  do /*0x159102*/
  {
    while ( *v3 ) /*0x1590f0*/
      ; /*0x1590f2*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x159102*/
  if ( *(_DWORD *)(a2 + 324) ) /*0x159104*/
    reset_timeout(a2 + 280); /*0x159114*/
  v4 = *(_DWORD *)(a2 + 76); /*0x15911c*/
  switch ( v4 & 0xF ) /*0x15912e*/
  {
    case 1: /*0x15912e*/
    case 9: /*0x15912e*/
    case 0xB: /*0x15912e*/
      v5 = *(_DWORD *)(a2 + 76); /*0x159174*/
      LOBYTE(v5) = v4 & 0xFA | 4; /*0x159178*/
      *(_DWORD *)(a2 + 76) = v5; /*0x15917a*/
      *(_DWORD *)(a2 + 68) = 0; /*0x15917d*/
      v6 = *(_DWORD *)(a2 + 384); /*0x159184*/
      if ( *(int *)(v6 + 276) > 0 || *(_DWORD *)(active_threads + 384) != v6 ) /*0x15919e*/
      {
        thread_setrun(a2, 1); /*0x1591a3*/
        goto LABEL_12; /*0x1591ab*/
      }
      _InterlockedExchange((volatile __int32 *)(a2 + 32), 0); /*0x1591b2*/
      thread_run(a1, a2); /*0x1591b7*/
      break; /*0x1591bc*/
    case 3: /*0x15912e*/
    case 5: /*0x15912e*/
    case 7: /*0x15912e*/
    case 0xD: /*0x15912e*/
    case 0xF: /*0x15912e*/
      LOBYTE(v4) = v4 & 0xFE; /*0x1591c0*/
      *(_DWORD *)(a2 + 76) = v4; /*0x1591c3*/
      *(_DWORD *)(a2 + 68) = 0; /*0x1591c6*/
      goto LABEL_12; /*0x1591c6*/
    default:
LABEL_12:
      _InterlockedExchange((volatile __int32 *)(a2 + 32), 0); /*0x1591cd*/
      if ( a1 ) /*0x1591d4*/
      {
        spl0(); /*0x1591d6*/
        call_continuation(a1); /*0x1591dc*/
      }
      break; /*0x1591dc*/
  }
  return splx(v2); /*0x1591ed*/
}
