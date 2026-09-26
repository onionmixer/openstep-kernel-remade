
void _ipc_init(void)

{
  int iVar1;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  iVar1 = _task_create((void *)0x0,0,(void **)&_ipc_soft_task);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_ipc_init_001de704);
  }
  _ipc_soft_map = *(undefined4 *)(_ipc_soft_task + 0xc);
  _ipc_kernel_map = _kmem_suballoc(_kernel_map,local_8,local_c,_ipc_kernel_map_size,1);
  _ipc_host_init();
  return;
}

