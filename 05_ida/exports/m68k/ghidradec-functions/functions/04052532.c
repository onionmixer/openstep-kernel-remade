
undefined4 _task_info(int param_1,int param_2,int *param_3,uint *param_4)

{
  int iVar1;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  if (param_1 != 0) {
    if (param_2 == 1) {
      if (7 < *param_4) {
        iVar1 = _kernel_map;
        if (param_1 != _kernel_task) {
          iVar1 = *(int *)(param_1 + 8);
        }
        param_3[2] = *(int *)(iVar1 + 0x24);
        param_3[3] = _page_size * *(int *)(*(int *)(iVar1 + 0x20) + 0x10);
        param_3[1] = *(int *)(param_1 + 0x40);
        *param_3 = *(int *)(param_1 + 0x3c);
        param_3[4] = *(int *)(param_1 + 0x4c);
        param_3[5] = *(int *)(param_1 + 0x50);
        param_3[6] = *(int *)(param_1 + 0x54);
        param_3[7] = *(int *)(param_1 + 0x58);
        *param_4 = 8;
        return 0;
      }
    }
    else if ((param_2 == 3) && (3 < *param_4)) {
      *param_3 = 0;
      param_3[1] = 0;
      param_3[2] = 0;
      param_3[3] = 0;
      for (iVar1 = *(int *)(param_1 + 0x18); iVar1 != param_1 + 0x18; iVar1 = *(int *)(iVar1 + 0x10)
          ) {
        _thread_read_times(iVar1,&iStack_c,&iStack_14);
        param_3[1] = iStack_8 + param_3[1];
        *param_3 = iStack_c + *param_3;
        if (999999 < param_3[1]) {
          param_3[1] = param_3[1] + -1000000;
          *param_3 = *param_3 + 1;
        }
        param_3[3] = iStack_10 + param_3[3];
        param_3[2] = iStack_14 + param_3[2];
        if (999999 < param_3[3]) {
          param_3[3] = param_3[3] + -1000000;
          param_3[2] = param_3[2] + 1;
        }
      }
      *param_4 = 4;
      return 0;
    }
  }
  return 4;
}

