/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x163498. */
thread_act_t __cdecl thread_select(int *a1)
{
  thread_act_t v1; // ebx
  int v2; // ecx
  int *v3; // eax
  volatile __int32 *v4; // edx
  thread_act_t *v5; // edx

  a1[73] = 1; /*0x1634a1*/
  if ( a1[66] > 0 ) /*0x1634b2*/
  {
    v1 = choose_thread(a1); /*0x1634ba*/
    v2 = min_quantum; /*0x1634bc*/
LABEL_26:
    a1[72] = v2; /*0x1635d3*/
    return v1; /*0x1635d3*/
  }
  do /*0x1634e6*/
  {
    while ( dword_1E9710 ) /*0x1634d8*/
      ; /*0x1634d6*/
  }
  while ( _InterlockedExchange(&dword_1E9710, 1) == 1 ); /*0x1634e6*/
  if ( !dword_1E9718 ) /*0x1634ef*/
  {
    v1 = active_threads; /*0x1634f1*/
    if ( *(_DWORD *)(active_threads + 76) == 4 ) /*0x1634fb*/
    {
      v3 = *(int **)(active_threads + 388); /*0x1634fd*/
      if ( !v3 || v3 == a1 ) /*0x163509*/
      {
        _InterlockedExchange(&dword_1E9710, 0); /*0x16350d*/
        v4 = (volatile __int32 *)(v1 + 32); /*0x163513*/
        do /*0x16352a*/
        {
          while ( *v4 ) /*0x163518*/
            ; /*0x16351a*/
        }
        while ( _InterlockedExchange(v4, 1) == 1 ); /*0x16352a*/
        if ( *(_DWORD *)(v1 + 112) != sched_tick ) /*0x163534*/
          update_priority(v1); /*0x163537*/
        _InterlockedExchange((volatile __int32 *)(v1 + 32), 0); /*0x16353e*/
        goto LABEL_23; /*0x163541*/
      }
    }
LABEL_17:
    v1 = choose_pset_thread(a1, &default_pset); /*0x16355a*/
    goto LABEL_23; /*0x163563*/
  }
  v5 = (thread_act_t *)((char *)&default_pset + 8 * dword_1E9714); /*0x16354a*/
  v1 = *v5; /*0x16354d*/
  if ( v5 == (thread_act_t *)*v5 ) /*0x163551*/
  {
    --dword_1E9714; /*0x163554*/
    goto LABEL_17; /*0x163554*/
  }
  *(_DWORD *)(*(_DWORD *)v1 + 4) = v5; /*0x163572*/
  *v5 = *(_DWORD *)v1; /*0x163577*/
  *(_DWORD *)(v1 + 8) = 0; /*0x163579*/
  if ( --dword_1E9718 > 0 && (unk_1E9778 & 2) != 0 && (thread_act_t *)*v5 == v5 ) /*0x16359f*/
  {
    do /*0x1635af*/
    {
      --dword_1E9714; /*0x1635a4*/
      v5 -= 2; /*0x1635aa*/
    }
    while ( (thread_act_t *)*v5 == v5 ); /*0x1635af*/
  }
  _InterlockedExchange(&dword_1E9710, 0); /*0x1635b3*/
LABEL_23:
  if ( *(_DWORD *)(v1 + 96) == 2 ) /*0x1635bd*/
  {
    v2 = *(_DWORD *)(v1 + 92); /*0x1635d0*/
    goto LABEL_26; /*0x1635d0*/
  }
  a1[72] = dword_1E977C; /*0x1635c5*/
  return v1; /*0x1635de*/
}
