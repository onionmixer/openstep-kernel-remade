
void _kernel_task_create(void *param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 local_10 [4];
  undefined1 local_c [4];
  void *local_8;
  
  _task_create(param_1,0,&local_8);
  _task_deallocate(local_8);
  _vm_map_deallocate(*(undefined4 *)((int)local_8 + 0xc));
  if (param_2 == 0) {
    *(undefined4 *)((int)local_8 + 0xc) = _kernel_map;
  }
  else {
    uVar1 = _kmem_suballoc(_kernel_map,local_c,local_10,param_2,0);
    *(undefined4 *)((int)local_8 + 0xc) = uVar1;
  }
  *(undefined4 *)((int)local_8 + 0x50) = 1;
  return;
}

