/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x164164. */
int *__cdecl set_pri(_DWORD *a1, unsigned int a2, int a3)
{
  int *result; // eax
  int *v4; // ebx
  int v5; // ecx
  int *v6; // edx
  char *v7; // ebx
  int v8; // eax
  unsigned int v9; // ecx
  volatile __int32 *v10; // edx
  char *v11; // edx
  int v12; // eax
  unsigned int v13; // ecx
  volatile __int32 *v14; // edx
  int *v15; // edx

  result = (int *)rem_runq(a1); /*0x16416e*/
  v4 = result; /*0x164173*/
  a1[22] = a2; /*0x164178*/
  if ( result )
  {
    if ( a3 )
    {
      if ( a1[28] != sched_tick ) /*0x164198*/
        update_priority(a1); /*0x16419b*/
      if ( dword_1E9724 <= 0 )
      {
        if ( a1[97] ) /*0x164208*/
        {
          v7 = (char *)master_processor; /*0x164218*/
          v8 = need_ast[0]; /*0x16421e*/
          LOBYTE(v8) = LOBYTE(need_ast[0]) | 4; /*0x164223*/
          need_ast[0] = v8; /*0x164225*/
        }
        else
        {
          v7 = (char *)&default_pset; /*0x164211*/
        }
        v9 = a1[22]; /*0x16422f*/
        if ( v9 > 0x1F )
        {
          printf("run_queue_enqueue: pri too high (%d)\n", a1[22]);
          v9 = 31; /*0x164242*/
        }
        v10 = (volatile __int32 *)(v7 + 256); /*0x164247*/
        do /*0x164262*/
        {
          while ( *v10 ) /*0x164250*/
            ; /*0x164252*/
        }
        while ( _InterlockedExchange(v10, 1) == 1 ); /*0x164262*/
        v11 = &v7[8 * v9]; /*0x164264*/
        *a1 = v11; /*0x164267*/
        a1[1] = *((_DWORD *)v11 + 1); /*0x16426c*/
        *(_DWORD *)a1[1] = a1; /*0x164272*/
        *((_DWORD *)v11 + 1) = a1; /*0x164274*/
        if ( *((_DWORD *)v7 + 65) < v9 || !*((_DWORD *)v7 + 66) ) /*0x16427f*/
          *((_DWORD *)v7 + 65) = v9; /*0x164288*/
        ++*((_DWORD *)v7 + 66); /*0x16428e*/
        a1[2] = v7; /*0x164294*/
        _InterlockedExchange((volatile __int32 *)v7 + 64, 0); /*0x164299*/
        result = (int *)a1[22]; /*0x1642a5*/
        if ( *(_DWORD *)(active_threads + 88) < (int)result ) /*0x1642ab*/
        {
          *(_DWORD *)(processor_ptr[0] + 292) = 0; /*0x1642b6*/
          v12 = need_ast[0]; /*0x1642c0*/
          LOBYTE(v12) = LOBYTE(need_ast[0]) | 4; /*0x1642c5*/
          need_ast[0] = v12; /*0x1642c7*/
          return (int *)need_ast[0]; /*0x1642cc*/
        }
      }
      else
      {
        v5 = dword_1E971C; /*0x1641ac*/
        v6 = *(int **)(dword_1E971C + 268); /*0x1641b2*/
        result = *(int **)(dword_1E971C + 272); /*0x1641b8*/
        if ( v6 == &dword_1E971C ) /*0x1641c4*/
          dword_1E9720 = *(_DWORD *)(dword_1E971C + 272); /*0x1641c6*/
        else
          v6[68] = (int)result; /*0x1641d0*/
        if ( result == &dword_1E971C ) /*0x1641db*/
          dword_1E971C = (int)v6; /*0x164200*/
        else
          result[67] = (int)v6; /*0x1641dd*/
        --dword_1E9724; /*0x1641e3*/
        *(_DWORD *)(v5 + 280) = a1; /*0x1641e9*/
        *(_DWORD *)(v5 + 276) = 3; /*0x1641ef*/
      }
    }
    else
    {
      v13 = a2; /*0x1642d4*/
      if ( a2 > 0x1F )
      {
        printf("run_queue_enqueue: pri too high (%d)\n", a2);
        v13 = 31; /*0x1642e7*/
      }
      v14 = v4 + 64; /*0x1642ec*/
      do /*0x164306*/
      {
        while ( *v14 ) /*0x1642f4*/
          ; /*0x1642f6*/
      }
      while ( _InterlockedExchange(v14, 1) == 1 ); /*0x164306*/
      v15 = &v4[2 * v13]; /*0x164308*/
      *a1 = v15; /*0x16430b*/
      a1[1] = v15[1]; /*0x164310*/
      *(_DWORD *)a1[1] = a1; /*0x164316*/
      v15[1] = (int)a1; /*0x164318*/
      if ( v4[65] < v13 || !v4[66] ) /*0x164323*/
        v4[65] = v13; /*0x16432c*/
      ++v4[66]; /*0x164332*/
      a1[2] = v4; /*0x164338*/
      return (int *)_InterlockedExchange(v4 + 64, 0); /*0x16433d*/
    }
  }
  return result; /*0x164346*/
}
