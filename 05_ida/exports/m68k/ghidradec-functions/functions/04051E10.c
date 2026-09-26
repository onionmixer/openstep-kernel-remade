
int _kernel_task_create(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined auStack_10 [4];
  undefined auStack_c [4];
  int iStack_8;
  
  _task_create(param_1,0,&iStack_8);
  _task_deallocate(iStack_8);
  _vm_map_deallocate(*(undefined4 *)(iStack_8 + 8));
  if (param_2 == 0) {
    *(undefined4 *)(iStack_8 + 8) = _kernel_map;
  }
  else {
    uVar1 = _kmem_suballoc(_kernel_map,auStack_c,auStack_10,param_2,0);
    *(undefined4 *)(iStack_8 + 8) = uVar1;
  }
  *(undefined4 *)(iStack_8 + 0x48) = 1;
  return iStack_8;
}
