/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x108e80. */
int proc_shutdown()
{
  int v0; // ebx
  int v1; // eax
  int v2; // eax
  unsigned int i; // esi
  unsigned int j; // esi
  int v5; // esi
  unsigned int v6; // esi
  _DWORD *v7; // edx
  int k; // edi
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // eax
  int v14; // [esp+Ch] [ebp-8h]
  _DWORD *v15; // [esp+10h] [ebp-4h]
  _DWORD *v16; // [esp+10h] [ebp-4h]

  v0 = *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 60); /*0x108e91*/
  v1 = pfind(1); /*0x108e96*/
  if ( v1 && v1 != v0 ) /*0x108ea6*/
    task_suspend(*(_DWORD *)(v1 + 104)); /*0x108eac*/
  v2 = pfind(2); /*0x108eb6*/
  if ( v2 && v2 != v0 ) /*0x108ec6*/
    task_suspend(*(_DWORD *)(v2 + 104)); /*0x108ecc*/
  printf("Killing all processes "); /*0x108ed9*/
  for ( i = allproc; i; i = *(_DWORD *)(i + 8) ) /*0x108ee9*/
  {
    if ( *(_WORD *)(i + 50) && (*(_BYTE *)(i + 40) & 2) == 0 && i != v0 ) /*0x108efb*/
      psignal(i, (const char *)0xF); /*0x108f00*/
  }
  ns_sleep(0x77359400u, 0); /*0x108f16*/
  ns_sleep(0x77359400u, 0); /*0x108f22*/
  for ( j = allproc; j; j = *(_DWORD *)(j + 8) ) /*0x108f32*/
  {
    if ( *(_WORD *)(j + 50) && (*(_BYTE *)(j + 40) & 2) == 0 && j != v0 ) /*0x108f43*/
      psignal(j, (const char *)9); /*0x108f48*/
  }
  ns_sleep(0x3B9ACA00u, 0); /*0x108f5e*/
  v5 = allproc; /*0x108f63*/
  while ( v5 ) /*0x108f6e*/
  {
    if ( !*(_WORD *)(v5 + 50) || (*(_BYTE *)(v5 + 40) & 2) != 0 || v5 == v0 ) /*0x108f7f*/
    {
      v5 = *(_DWORD *)(v5 + 8); /*0x108f81*/
    }
    else
    {
      if ( *(_DWORD *)(v5 + 120) ) /*0x108f88*/
      {
        thread_block(); /*0x108f8e*/
      }
      else
      {
        *(_DWORD *)(v5 + 120) = active_threads; /*0x108f9e*/
        printf("."); /*0x108fa6*/
        do_exit(v5, 1); /*0x108fae*/
      }
      v5 = allproc; /*0x108fb6*/
    }
  }
  printf("\n"); /*0x108fc5*/
  v6 = allproc; /*0x108fca*/
  while ( v6 ) /*0x108fd5*/
  {
    v7 = *(_DWORD **)(*(_DWORD *)(v6 + 104) + 56); /*0x108fde*/
    v14 = 0; /*0x108fe1*/
    for ( k = 0; v7[86] >= k; ++k ) /*0x108ff3*/
    {
      v9 = v7[84]; /*0x108ff8*/
      v10 = *(_DWORD *)(v9 + 4 * k); /*0x108ffe*/
      if ( v10 && v10 != -65536 ) /*0x10900b*/
      {
        v15 = v7; /*0x10900e*/
        vno_lockrelease(*(_DWORD *)(v9 + 4 * k)); /*0x109011*/
        *(_DWORD *)(v15[84] + 4 * k) = 0; /*0x10901f*/
        closef(v10); /*0x109027*/
        v14 = 1; /*0x10902c*/
        v7 = v15; /*0x109036*/
      }
      *(_BYTE *)(k + v7[85]) = 0; /*0x10903f*/
    }
    v11 = v7[88]; /*0x10904c*/
    if ( v11 ) /*0x109054*/
    {
      v7[88] = 0; /*0x109056*/
      v16 = v7; /*0x109061*/
      vn_rele(v11); /*0x109064*/
      v14 = 1; /*0x109069*/
      v7 = v16; /*0x109073*/
    }
    v12 = v7[89]; /*0x109076*/
    if ( v12 ) /*0x10907e*/
    {
      v7[89] = 0; /*0x109080*/
      vn_rele(v12); /*0x10908b*/
      v14 = 1; /*0x109090*/
    }
    if ( v14 ) /*0x10909e*/
      v6 = allproc; /*0x1090a0*/
    else
      v6 = *(_DWORD *)(v6 + 8); /*0x1090ac*/
  }
  thread_wakeup_prim(&reaper_queue, 0, 0); /*0x1090bd*/
  ns_sleep(0x77359400u, 0); /*0x1090c9*/
  return printf("continuing\n"); /*0x1090db*/
}
