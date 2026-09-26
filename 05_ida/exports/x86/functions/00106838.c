/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x106838. */
int __cdecl fork1(int a1)
{
  int v1; // esi
  __int16 v2; // ax
  unsigned int i; // ebx
  int j; // ebx
  int v5; // edi
  int v6; // eax
  int v7; // ebx
  thread_act_t v8; // esi
  int result; // eax
  int v10; // [esp+Ch] [ebp-4h]

  v10 = alloc_posix_proc(); /*0x106846*/
  v1 = 0; /*0x106849*/
  v2 = *(_WORD *)(*(_DWORD *)(active_u + 28) + 2); /*0x106853*/
  if ( v2 ) /*0x10685a*/
  {
    for ( i = allproc; i; i = *(_DWORD *)(i + 8) ) /*0x106864*/
    {
      if ( *(_WORD *)(i + 44) == v2 ) /*0x10686c*/
        ++v1; /*0x10686e*/
    }
    for ( j = zombproc; j; j = *(_DWORD *)(j + 8) ) /*0x10687e*/
    {
      if ( *(_WORD *)(j + 44) == *(_WORD *)(*(_DWORD *)(active_u + 28) + 2) ) /*0x106890*/
        ++v1; /*0x106892*/
    }
  }
  v5 = freeproc; /*0x10689a*/
  if ( !freeproc ) /*0x1068a2*/
  {
    v6 = getproc(); /*0x1068a4*/
    v5 = v6; /*0x1068a9*/
    if ( v6 ) /*0x1068ad*/
    {
      *(_DWORD *)(v6 + 8) = freeproc; /*0x1068c6*/
      freeproc = v6; /*0x1068c9*/
    }
    else
    {
      tablefull(aProc); /*0x1068b4*/
    }
    if ( !v5 ) /*0x1068d1*/
      goto LABEL_17; /*0x1068d1*/
  }
  if ( !*(_WORD *)(*(_DWORD *)(active_u + 28) + 2) || v1 <= 100 ) /*0x1068e5*/
  {
    v7 = *(_DWORD *)active_u; /*0x106901*/
    v8 = cloneproc(*(_DWORD *)active_u, a1, v10); /*0x106911*/
    thread_dup(active_threads, v8); /*0x10691b*/
    *(_DWORD *)(*(_DWORD *)(v8 + 132) + 96) = *(__int16 *)(v7 + 48); /*0x10692a*/
    *(_DWORD *)(*(_DWORD *)(v8 + 132) + 100) = 1; /*0x106933*/
    microtime((_DWORD *)(*(_DWORD *)(*(_DWORD *)(v8 + 12) + 56) + 572)); /*0x106946*/
    *(_WORD *)(*(_DWORD *)(*(_DWORD *)(v8 + 12) + 56) + 580) = 1; /*0x106951*/
    *(_DWORD *)(dword_1E875C + 96) = *(__int16 *)(v5 + 48); /*0x106963*/
    thread_resume(v8); /*0x106967*/
  }
  else
  {
LABEL_17:
    free_posix_proc(v10); /*0x1068eb*/
    *(_BYTE *)(dword_1E875C + 104) = 11; /*0x1068f5*/
  }
  result = dword_1E875C; /*0x10696c*/
  *(_DWORD *)(dword_1E875C + 100) = 0; /*0x106971*/
  return result; /*0x10697b*/
}
