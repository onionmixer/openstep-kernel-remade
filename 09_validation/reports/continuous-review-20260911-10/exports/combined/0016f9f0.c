
void FUN_0016f9f0(int *param_1,uint *param_2)

{
  void *parent_task;
  uint uVar1;
  void *local_8;
  
  if (((param_1[1] == 0x20) && (-1 < *param_1)) && (param_1[6] == DAT_001e0384)) {
    parent_task = (void *)_convert_port_to_task(param_1[2]);
    uVar1 = _task_create(parent_task,param_1[7],&local_8);
    param_2[7] = uVar1;
    _task_deallocate(parent_task);
    if (param_2[7] == 0) {
      *param_2 = *param_2 | 0x80000000;
      param_2[1] = 0x28;
      param_2[8] = DAT_001e0388;
      uVar1 = _convert_task_to_port(local_8);
      param_2[9] = uVar1;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

