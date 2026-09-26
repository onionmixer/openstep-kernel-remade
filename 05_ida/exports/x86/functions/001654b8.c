/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1654b8. */
kern_return_t __cdecl thread_switch(mach_port_name_t thread_name, int option, mach_msg_timeout_t option_time)
{
  _DWORD *v3; // esi
  int v4; // eax
  int v5; // eax
  thread_act_t v6; // ebx
  int v7; // edi
  volatile __int32 *v8; // edx
  int v9; // eax
  volatile __int32 *v11; // [esp+Ch] [ebp-4h] BYREF

  v3 = (_DWORD *)active_threads; /*0x1654ca*/
  if ( option == 1 ) /*0x1654d3*/
  {
    thread_depress_priority(active_threads, option_time); /*0x1654ee*/
  }
  else if ( option > 1 ) /*0x1654d5*/
  {
    if ( option != 2 ) /*0x1654e3*/
      return 4; /*0x1654e3*/
    thread_will_wait_with_timeout(active_threads, option_time); /*0x1654fa*/
  }
  else if ( option ) /*0x1654d9*/
  {
    return 4; /*0x1654d9*/
  }
  if ( thread_name ) /*0x165504*/
  {
    v4 = ipc_object_translate(*(_DWORD *)(v3[3] + 136), thread_name, 0, &v11); /*0x16551b*/
    if ( v4 ) /*0x165525*/
    {
      if ( v4 == 15 ) /*0x1655df*/
        return 4; /*0x1655e6*/
    }
    else
    {
      v5 = *((_DWORD *)v11 + 2); /*0x16552e*/
      if ( v5 < 0 && (_WORD)v5 == 1 ) /*0x16553d*/
      {
        v6 = *((_DWORD *)v11 + 5); /*0x165543*/
        v7 = splsched(); /*0x16554b*/
        v8 = (volatile __int32 *)(v6 + 32); /*0x16554d*/
        do /*0x165562*/
        {
          while ( *v8 ) /*0x165550*/
            ; /*0x165552*/
        }
        while ( _InterlockedExchange(v8, 1) == 1 ); /*0x165562*/
        if ( *(_DWORD *)(v6 + 384) == v3[96] && rem_runq((_DWORD *)v6) ) /*0x165573*/
        {
          _InterlockedExchange((volatile __int32 *)(v6 + 32), 0); /*0x165581*/
          splx(v7); /*0x165585*/
          _InterlockedExchange(v11, 0); /*0x165592*/
          if ( *(_DWORD *)(v6 + 96) == 2 ) /*0x165598*/
          {
            v9 = processor_ptr[0]; /*0x16559a*/
            *(_DWORD *)(processor_ptr[0] + 288) = *(_DWORD *)(v6 + 92); /*0x1655a2*/
            *(_DWORD *)(v9 + 292) = 1; /*0x1655a8*/
          }
          thread_run((int)thread_switch_continue, v6); /*0x1655b8*/
          goto LABEL_26; /*0x1655c0*/
        }
        _InterlockedExchange((volatile __int32 *)(v6 + 32), 0); /*0x1655c6*/
        splx(v7); /*0x1655ca*/
      }
      _InterlockedExchange(v11, 0); /*0x1655d7*/
    }
  }
  thread_block_with_continuation((int)thread_switch_continue); /*0x1655ed*/
LABEL_26:
  if ( (int)v3[25] >= 0 ) /*0x1655f9*/
    thread_depress_abort((thread_act_t)v3); /*0x1655fc*/
  return 0; /*0x165606*/
}
