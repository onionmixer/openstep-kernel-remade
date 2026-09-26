/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15c828. */
thread_act_t setup_main()
{
  thread_act_t v0; // eax
  int v1; // eax

  clock_timer_init(); /*0x15c82b*/
  rqinit(); /*0x15c830*/
  sched_init(); /*0x15c835*/
  vm_mem_init(); /*0x15c83a*/
  mach_clock_bootstrap(); /*0x15c83f*/
  init_timers(); /*0x15c844*/
  init_timeout(); /*0x15c849*/
  startup(virtual_avail); /*0x15c855*/
  dword_1F6348 = 1; /*0x15c85a*/
  dword_1F6350 = (mem_size + 0xFFFFF) & 0xFFF00000; /*0x15c873*/
  dword_1F634C = 0; /*0x15c878*/
  machine_info = 4; /*0x15c882*/
  dword_1F6344 = 0; /*0x15c88c*/
  uzone_init(); /*0x15c896*/
  ipc_bootstrap(); /*0x15c89b*/
  cpu_up(master_cpu); /*0x15c8a7*/
  mach_net_init(); /*0x15c8ac*/
  task_init(); /*0x15c8b1*/
  thread_init(); /*0x15c8b6*/
  swapper_init(); /*0x15c8bb*/
  ipc_init(); /*0x15c8c0*/
  vnode_pager_init(); /*0x15c8c5*/
  thread_create(kernel_task, &first_thread); /*0x15c8d6*/
  thread_deallocate(first_thread); /*0x15c8e2*/
  thread_start(first_thread, main); /*0x15c8f3*/
  thread_doswapin(first_thread); /*0x15c8ff*/
  v0 = first_thread; /*0x15c904*/
  *(_BYTE *)(first_thread + 76) |= 4u; /*0x15c909*/
  thread_resume(v0); /*0x15c911*/
  v1 = splvm(); /*0x15c916*/
  *(_DWORD *)(kernel_pmap + 24) = 1; /*0x15c925*/
  splx(v1); /*0x15c92d*/
  dev_server_init(); /*0x15c932*/
  miniMonInit(); /*0x15c937*/
  return first_thread; /*0x15c943*/
}
