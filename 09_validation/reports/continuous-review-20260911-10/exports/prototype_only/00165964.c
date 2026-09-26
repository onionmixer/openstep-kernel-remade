
void _task_init(void)

{
  int iVar1;
  
  _task_zone = _zinit(0x8c,0x11800,0x2300,0,s_tasks_001dfb94);
  _task_create((void *)0x0,0,(void **)&_kernel_task);
  iVar1 = _kernel_task;
  *(undefined4 *)(_kernel_task + 0x4c) = 1;
  *(undefined4 *)(iVar1 + 0x50) = 1;
  return;
}

