
undefined4 _od_async_attn(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 0x220) & 0x20000) == 0) {
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x20000;
    if (*(char *)(param_1 + 599) == '\b') {
      _od_drive_cmd(param_1,param_2,0x5000,6);
      *(undefined *)(param_1 + 0x268) = 0xd;
      uVar1 = 1;
    }
    else {
      _od_perror(param_1,param_2,8,param_3,param_4);
      *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xfffdffff;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = _od_fsm(param_1,param_2,(int)*(char *)(param_1 + 0x268));
  }
  return uVar1;
}

