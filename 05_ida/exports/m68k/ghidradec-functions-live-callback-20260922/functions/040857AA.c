
undefined4 _snd_reply_dsp_regs(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_24 = dword_40B21D8;
  uStack_1c = dword_40B21E0;
  uStack_14 = dword_40B21E8;
  uStack_10 = 0x13e;
  uStack_18 = 0;
  uStack_20 = 0x20;
  uStack_c = dword_40B21FC;
  uStack_8 = param_1;
  iVar1 = _object_copyin(dword_40C6EB8,_snd_var,6,0,&uStack_14);
  if (iVar1 == 0) {
    uVar2 = 5;
  }
  else {
    uVar2 = _msg_send_from_kernel(&uStack_24,1,0);
    _port_release(uStack_14);
  }
  return uVar2;
}

