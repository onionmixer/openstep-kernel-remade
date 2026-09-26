
undefined4 _thread_get_special_port(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) goto loc_4049B76;
  if (param_2 == 2) {
    puVar2 = (undefined4 *)(param_1 + 0xb0);
loc_4049BA2:
    if (*(int *)(param_1 + 0xa4) == 0) {
      uVar1 = 5;
    }
    else {
      uVar1 = _ipc_port_copy_send(*puVar2);
      *param_3 = uVar1;
      uVar1 = 0;
    }
  }
  else {
    if (param_2 < 3) {
      if (param_2 == 1) {
        puVar2 = (undefined4 *)(param_1 + 0xa8);
        goto loc_4049BA2;
      }
    }
    else if (param_2 == 3) {
      puVar2 = (undefined4 *)(param_1 + 0xac);
      goto loc_4049BA2;
    }
loc_4049B76:
    uVar1 = 4;
  }
  return uVar1;
}

