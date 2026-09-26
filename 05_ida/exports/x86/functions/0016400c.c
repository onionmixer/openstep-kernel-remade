/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16400c. */
int *__cdecl thread_setrun(char **a1, int a2)
{
  int v2; // ecx
  int *v3; // edx
  int *result; // eax
  char *v5; // ebx
  int v6; // eax
  unsigned int v7; // ecx
  volatile __int32 *v8; // edx
  char *v9; // edx
  int v10; // eax

  if ( a1[28] != (char *)sched_tick ) /*0x16401d*/
    update_priority(a1); /*0x164020*/
  if ( dword_1E9724 <= 0 )
  {
    if ( a1[97] ) /*0x16408c*/
    {
      v5 = (char *)master_processor; /*0x16409c*/
      v6 = need_ast[0]; /*0x1640a2*/
      LOBYTE(v6) = LOBYTE(need_ast[0]) | 4; /*0x1640a7*/
      need_ast[0] = v6; /*0x1640a9*/
    }
    else
    {
      v5 = (char *)&default_pset; /*0x164095*/
    }
    v7 = (unsigned int)a1[22]; /*0x1640b3*/
    if ( v7 > 0x1F )
    {
      printf("run_queue_enqueue: pri too high (%d)\n", a1[22]);
      v7 = 31; /*0x1640c6*/
    }
    v8 = (volatile __int32 *)(v5 + 256); /*0x1640cb*/
    do /*0x1640e6*/
    {
      while ( *v8 ) /*0x1640d4*/
        ; /*0x1640d6*/
    }
    while ( _InterlockedExchange(v8, 1) == 1 ); /*0x1640e6*/
    v9 = &v5[8 * v7]; /*0x1640e8*/
    *a1 = v9; /*0x1640eb*/
    a1[1] = *((char **)v9 + 1); /*0x1640f0*/
    *(_DWORD *)a1[1] = a1; /*0x1640f6*/
    *((_DWORD *)v9 + 1) = a1; /*0x1640f8*/
    if ( *((_DWORD *)v5 + 65) < v7 || !*((_DWORD *)v5 + 66) ) /*0x164103*/
      *((_DWORD *)v5 + 65) = v7; /*0x16410c*/
    ++*((_DWORD *)v5 + 66); /*0x164112*/
    a1[2] = v5; /*0x164118*/
    result = (int *)_InterlockedExchange((volatile __int32 *)v5 + 64, 0); /*0x16411d*/
    if ( a2 ) /*0x164127*/
    {
      result = (int *)a1[22]; /*0x16412f*/
      if ( *(_DWORD *)(active_threads + 88) < (int)result ) /*0x164135*/
      {
        *(_DWORD *)(processor_ptr[0] + 292) = 0; /*0x16413c*/
        v10 = need_ast[0]; /*0x164146*/
        LOBYTE(v10) = LOBYTE(need_ast[0]) | 4; /*0x16414b*/
        need_ast[0] = v10; /*0x16414d*/
        return (int *)need_ast[0]; /*0x164152*/
      }
    }
  }
  else
  {
    v2 = dword_1E971C; /*0x164031*/
    v3 = *(int **)(dword_1E971C + 268); /*0x164037*/
    result = *(int **)(dword_1E971C + 272); /*0x16403d*/
    if ( v3 == &dword_1E971C ) /*0x164049*/
      dword_1E9720 = *(_DWORD *)(dword_1E971C + 272); /*0x16404b*/
    else
      v3[68] = (int)result; /*0x164054*/
    if ( result == &dword_1E971C ) /*0x16405f*/
      dword_1E971C = (int)v3; /*0x164084*/
    else
      result[67] = (int)v3; /*0x164061*/
    --dword_1E9724; /*0x164067*/
    *(_DWORD *)(v2 + 280) = a1; /*0x16406d*/
    *(_DWORD *)(v2 + 276) = 3; /*0x164073*/
  }
  return result; /*0x16415a*/
}
