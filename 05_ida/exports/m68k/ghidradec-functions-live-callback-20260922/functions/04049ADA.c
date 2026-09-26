
undefined4 _task_set_special_port(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    return 4;
  }
  if (param_2 == 2) {
    iVar1 = *(int *)(param_1 + 0x7c);
    if (*(int *)(iVar1 + 4) != 0) {
      iVar2 = *(int *)(iVar1 + 0x3c);
      *(int *)(iVar1 + 0x3c) = param_3;
      goto loc_4049B44;
    }
  }
  else {
    if (param_2 < 3) {
      if (param_2 != 1) {
        return 4;
      }
      piVar3 = (int *)(param_1 + 0x60);
    }
    else if (param_2 == 3) {
      piVar3 = (int *)(param_1 + 100);
    }
    else {
      if (param_2 != 4) {
        return 4;
      }
      piVar3 = (int *)(param_1 + 0x68);
    }
    if (*(int *)(param_1 + 0x5c) != 0) {
      iVar2 = *piVar3;
      *piVar3 = param_3;
loc_4049B44:
      if ((iVar2 != 0) && (iVar2 != -1)) {
        _ipc_port_release_send(iVar2);
      }
      return 0;
    }
  }
  return 5;
}

