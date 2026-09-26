/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x102974. */
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int v3; // edi
  int v4; // eax
  unsigned int v5; // ebx
  int v6; // ecx
  int v7; // edx
  int v8; // edx
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // edx
  int v13; // eax
  int i; // ebx
  int v15; // eax
  int j; // ebx
  int v17; // ebx
  int v18; // ebx
  int v19; // edi
  unsigned int v20; // eax
  size_t v21; // ecx
  thread_act_t child_act; // [esp+Ch] [ebp-Ch] BYREF
  _BYTE v24[4]; // [esp+10h] [ebp-8h] BYREF
  _BYTE v25[4]; // [esp+14h] [ebp-4h] BYREF

  pqinit(); /*0x10297d*/
  v3 = kernel_proc; /*0x102982*/
  *(_DWORD *)(kernel_task + 60) = kernel_proc; /*0x10298e*/
  *(_WORD *)(v3 + 48) = 0; /*0x102991*/
  pidhash_enter(v3); /*0x102998*/
  *(_DWORD *)(v3 + 104) = kernel_task; /*0x1029a3*/
  v4 = splhigh(); /*0x1029a6*/
  splx(v4); /*0x1029ae*/
  calloutInitialize(); /*0x1029b3*/
  switch_unix_context(active_threads); /*0x1029bf*/
  *(_BYTE *)(v3 + 19) = 3; /*0x1029c4*/
  *(_BYTE *)(v3 + 40) |= 3u; /*0x1029c8*/
  *(_BYTE *)(v3 + 21) = 0; /*0x1029cc*/
  *(_DWORD *)(v3 + 112) = 0; /*0x1029d3*/
  *(_DWORD *)(v3 + 116) = 0; /*0x1029da*/
  *(_DWORD *)(v3 + 120) = 0; /*0x1029e1*/
  *(_DWORD *)active_u = v3; /*0x1029ee*/
  *(_DWORD *)(active_u + 28) = crget(); /*0x1029fb*/
  *(_WORD *)(active_u + 366) = cmask; /*0x102a0b*/
  *(_DWORD *)(active_u + 344) = -1; /*0x102a18*/
  v5 = 0; /*0x102a22*/
  v6 = 0; /*0x102a24*/
  do /*0x102a4b*/
  {
    v7 = active_u; /*0x102a28*/
    *(_DWORD *)(v6 + active_u + 616) = 0x7FFFFFFF; /*0x102a2e*/
    *(_DWORD *)(v6 + v7 + 612) = 0x7FFFFFFF; /*0x102a39*/
    v6 += 8; /*0x102a44*/
    ++v5; /*0x102a47*/
  }
  while ( v5 <= 5 ); /*0x102a4b*/
  v8 = active_u; /*0x102a4d*/
  v9 = dword_1DA00C; /*0x102a59*/
  *(_DWORD *)(active_u + 636) = vm_initial_limit_stack; /*0x102a5e*/
  *(_DWORD *)(v8 + 640) = v9; /*0x102a64*/
  v10 = active_u; /*0x102a6a*/
  v11 = dword_1DA014; /*0x102a76*/
  *(_DWORD *)(active_u + 628) = vm_initial_limit_data; /*0x102a7b*/
  *(_DWORD *)(v10 + 632) = v11; /*0x102a81*/
  v12 = active_u; /*0x102a87*/
  v13 = dword_1DA01C; /*0x102a93*/
  *(_DWORD *)(active_u + 644) = vm_initial_limit_core; /*0x102a98*/
  *(_DWORD *)(v12 + 648) = v13; /*0x102a9e*/
  for ( i = 0; i <= 63; ++i ) /*0x102aa4*/
  {
    pgrphash[i] = 0; /*0x102aa8*/
    posix_proc_hash[i] = 0; /*0x102ab3*/
  }
  v15 = new_posix_proc(0); /*0x102ac6*/
  px = v15; /*0x102acb*/
  *(_DWORD *)(v15 + 16) = &pgrp0; /*0x102ad0*/
  *(_DWORD *)(v15 + 12) = 0; /*0x102ad7*/
  *(_WORD *)(v15 + 4) = *(_WORD *)(*(_DWORD *)(active_u + 28) + 6); /*0x102aeb*/
  *(_WORD *)(v15 + 6) = *(_WORD *)(*(_DWORD *)(active_u + 28) + 2); /*0x102afc*/
  *(_WORD *)(v15 + 8) = *(_WORD *)(*(_DWORD *)(active_u + 28) + 4); /*0x102b0d*/
  *(_DWORD *)(v15 + 20) = 0; /*0x102b11*/
  *(_BYTE *)(v15 + 24) &= ~1u; /*0x102b18*/
  *(_BYTE *)(px + 24) &= ~2u; /*0x102b22*/
  pgrphash[0] = (int)&pgrp0; /*0x102b26*/
  dword_1E8E34 = v3; /*0x102b30*/
  dword_1E8E38 = (int)&session0; /*0x102b36*/
  pgrp0 = 0; /*0x102b40*/
  dword_1E8E40 = 0; /*0x102b4a*/
  session0 = 1; /*0x102b54*/
  dword_1E9064 = v3; /*0x102b5e*/
  dword_1E9068 = 0; /*0x102b64*/
  word_1E906C = 0; /*0x102b6e*/
  gc_init(); /*0x102b77*/
  kernel_pageable_map = kmem_suballoc(kernel_map, v25, v24, 0x80000, 1); /*0x102b97*/
  ns_hardclock_init(); /*0x102b9c*/
  mfs_init(); /*0x102ba1*/
  lock_init((void *)(active_u + 32), 1); /*0x102bb2*/
  ++**(_WORD **)(active_u + 28); /*0x102bc0*/
  rootcred = *(_DWORD *)(active_u + 28); /*0x102bcc*/
  for ( j = 1; j <= 15; ++j ) /*0x102bd2*/
    *(_WORD *)(*(_DWORD *)(active_u + 28) + 2 * j + 10) = -1; /*0x102be5*/
  mbinit(); /*0x102bf2*/
  cinit(); /*0x102bf7*/
  v17 = splnet(); /*0x102c01*/
  ifinit(); /*0x102c03*/
  domaininit(); /*0x102c08*/
  splx(v17); /*0x102c0e*/
  bhinit(); /*0x102c13*/
  dnlc_init(); /*0x102c18*/
  *(_DWORD *)(active_u + 356) = 0; /*0x102c23*/
  *(_DWORD *)(active_u + 352) = 0; /*0x102c33*/
  v18 = 0; /*0x102c3d*/
  v19 = 0; /*0x102c42*/
  do /*0x102c97*/
  {
    if ( machine_slot[v19] ) /*0x102c44*/
    {
      thread_create(kernel_task, &child_act); /*0x102c58*/
      thread_bind(child_act, processor_ptr[v18]); /*0x102c69*/
      thread_start(child_act, idle_thread); /*0x102c77*/
      thread_doswapin(child_act); /*0x102c80*/
      thread_resume(child_act); /*0x102c89*/
    }
    v19 += 8; /*0x102c91*/
    ++v18; /*0x102c94*/
  }
  while ( v18 <= 0 ); /*0x102c97*/
  binit(); /*0x102c99*/
  recompute_priorities(); /*0x102c9e*/
  lightning_bolt(0, 0); /*0x102ca7*/
  kernel_thread(kernel_task, (int)reaper_thread, 0); /*0x102cba*/
  kernel_thread(kernel_task, (int)swapin_thread, 0); /*0x102ccd*/
  kernel_thread(kernel_task, (int)sched_thread, 0); /*0x102ce3*/
  kernel_thread(kernel_task, (int)netisr_thread, 0); /*0x102cf6*/
  _objcInit(); /*0x102cfb*/
  objc_setClassHandler(sub_10307C); /*0x102d05*/
  kmEnableAnimation(); /*0x102d0a*/
  autoconf(); /*0x102d0f*/
  setconf(); /*0x102d14*/
  loattach(); /*0x102d19*/
  *(_BYTE *)(dword_1E875C + 104) = 0; /*0x102d24*/
  vfs_mountroot(); /*0x102d28*/
  *(_BYTE *)(active_u + 608) = 15; /*0x102d33*/
  file_init(); /*0x102d3a*/
  child_act = newproc(0); /*0x102d46*/
  *(_DWORD *)(*(_DWORD *)(child_act + 12) + 76) = 0; /*0x102d4c*/
  init_proc = pfind(1); /*0x102d5d*/
  ux_handler_init(); /*0x102d62*/
  port_reference(ux_exception_port); /*0x102d6e*/
  task_set_special_port(*(_DWORD *)(child_act + 12), 3, ux_exception_port); /*0x102d83*/
  thread_start(child_act, init_task); /*0x102d91*/
  thread_resume(child_act); /*0x102d9a*/
  power_init(); /*0x102da2*/
  pageoutThread = kernel_thread(kernel_task, (int)vm_pageout, 0); /*0x102dba*/
  vol_start_thread(); /*0x102dbf*/
  pnotify_start(); /*0x102dc4*/
  *(_BYTE *)(*(_DWORD *)active_u + 40) |= 3u; /*0x102dd1*/
  v20 = strlen(aKernelIdle) + 1; /*0x102de5*/
  v21 = 17; /*0x102dee*/
  if ( v20 - 1 <= 0x10 ) /*0x102df6*/
    v21 = v20; /*0x102df8*/
  bcopy(aKernelIdle, (void *)(active_u + 8), v21); /*0x102e0a*/
  thread_terminate(active_threads); /*0x102e19*/
  return thread_halt_self(); /*0x102e26*/
}
