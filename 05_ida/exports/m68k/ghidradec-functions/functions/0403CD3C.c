
void _ipc_init(void)

{
  int iVar1;
  undefined auStack_c [4];
  undefined auStack_8 [4];
  
  iVar1 = _task_create(0,0,&_ipc_soft_task);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcInit);
  }
  _ipc_soft_map = *(undefined4 *)(_ipc_soft_task + 8);
  _ipc_kernel_map = _kmem_suballoc(_kernel_map,auStack_8,auStack_c,_ipc_kernel_map_size,1);
  _ipc_host_init();
  return;
}
