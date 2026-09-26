
void _task_init(void)

{
  int iVar1;
  
  _task_zone = _zinit(0x80,0x10000,0x2000,0,&aTasks);
  _task_create(0,0,&_kernel_task);
  iVar1 = _kernel_task;
  *(undefined4 *)(_kernel_task + 0x44) = 1;
  *(undefined4 *)(iVar1 + 0x48) = 1;
  return;
}

