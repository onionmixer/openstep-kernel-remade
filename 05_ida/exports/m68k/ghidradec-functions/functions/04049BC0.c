
undefined4 _thread_set_special_port(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) goto loc_4049BD0;
  if (param_2 == 2) {
    piVar3 = (int *)(param_1 + 0xb0);
loc_4049BFC:
    if (*(int *)(param_1 + 0xa4) == 0) {
      uVar2 = 5;
    }
    else {
      iVar1 = *piVar3;
      *piVar3 = param_3;
      if ((iVar1 != 0) && (iVar1 != -1)) {
        _ipc_port_release_send(iVar1);
      }
      uVar2 = 0;
    }
  }
  else {
    if (param_2 < 3) {
      if (param_2 == 1) {
        piVar3 = (int *)(param_1 + 0xa8);
        goto loc_4049BFC;
      }
    }
    else if (param_2 == 3) {
      piVar3 = (int *)(param_1 + 0xac);
      goto loc_4049BFC;
    }
loc_4049BD0:
    uVar2 = 4;
  }
  return uVar2;
}
