
undefined4 _task_get_special_port(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    return 4;
  }
  if (param_2 == 2) {
    if (*(int *)(*(int *)(param_1 + 0x7c) + 4) == 0) {
      return 5;
    }
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x3c);
  }
  else {
    if (param_2 < 3) {
      if (param_2 != 1) {
        return 4;
      }
      puVar2 = (undefined4 *)(param_1 + 0x60);
    }
    else if (param_2 == 3) {
      puVar2 = (undefined4 *)(param_1 + 100);
    }
    else {
      if (param_2 != 4) {
        return 4;
      }
      puVar2 = (undefined4 *)(param_1 + 0x68);
    }
    if (*(int *)(param_1 + 0x5c) == 0) {
      return 5;
    }
    uVar1 = *puVar2;
  }
  uVar1 = _ipc_port_copy_send(uVar1);
  *param_3 = uVar1;
  return 0;
}

