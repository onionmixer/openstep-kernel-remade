/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15bc30. */
void __cdecl clock_interrupt(int a1, int a2)
{
  thread_act_t v2; // ebx
  int v3; // edx
  thread_act_t v4; // edx
  int v5; // edx
  int v6; // ecx
  int v7; // edx
  int v8; // eax
  _DWORD *v9; // edx

  v2 = active_threads; /*0x15bc39*/
  if ( a2 ) /*0x15bc43*/
  {
    v3 = *(_DWORD *)(active_threads + 224); /*0x15bc45*/
    *(_DWORD *)(active_threads + 224) = a1 + v3; /*0x15bc4d*/
    if ( a1 + v3 >= 0 ) /*0x15bc53*/
      goto LABEL_7; /*0x15bc53*/
    v4 = v2 + 224; /*0x15bc55*/
  }
  else
  {
    v5 = *(_DWORD *)(active_threads + 240); /*0x15bc60*/
    *(_DWORD *)(active_threads + 240) = a1 + v5; /*0x15bc68*/
    if ( a1 + v5 >= 0 ) /*0x15bc6e*/
      goto LABEL_7; /*0x15bc6e*/
    v4 = v2 + 240; /*0x15bc70*/
  }
  timer_normalize(v4); /*0x15bc77*/
LABEL_7:
  if ( a2 ) /*0x15bc83*/
  {
    v6 = 0; /*0x15bc85*/
  }
  else
  {
    v6 = 2; /*0x15bc95*/
    if ( *(_DWORD *)(processor_ptr + 276) != 2 ) /*0x15bca1*/
      v6 = 1; /*0x15bca3*/
  }
  ++machine_slot[v6 + 4]; /*0x15bcb4*/
  if ( *(char *)(v2 + 76) >= 0 ) /*0x15bcba*/
    thread_quantum_update(0, v2, 1, v6); /*0x15bcc2*/
  if ( !master_cpu ) /*0x15bccf*/
  {
    if ( timedelta ) /*0x15bcdd*/
    {
      if ( timedelta >= 0 ) /*0x15bcee*/
      {
        v8 = tickdelta + a1; /*0x15bd2a*/
        timedelta -= tickdelta; /*0x15bd2f*/
        time_of_boot += 1000 * tickdelta; /*0x15bd46*/
      }
      else
      {
        v8 = a1 - tickdelta; /*0x15bcf8*/
        timedelta += tickdelta; /*0x15bcfc*/
        time_of_boot -= 1000 * tickdelta; /*0x15bd13*/
      }
      v7 = v8 + dword_1DEE3C; /*0x15bd58*/
    }
    else
    {
      v7 = a1 + dword_1DEE3C; /*0x15bce5*/
    }
    dword_1DEE3C = v7; /*0x15bd5a*/
    if ( v7 > 999999 ) /*0x15bd66*/
    {
      dword_1DEE3C = v7 - 1000000; /*0x15bd6e*/
      ++*(_DWORD *)time; /*0x15bd74*/
    }
    v9 = mtime; /*0x15bd7a*/
    if ( mtime ) /*0x15bd82*/
    {
      *((_DWORD *)mtime + 2) = *(_DWORD *)time; /*0x15bd8a*/
      v9[1] = dword_1DEE3C; /*0x15bd93*/
      *v9 = *(_DWORD *)time; /*0x15bd9c*/
    }
  }
}
