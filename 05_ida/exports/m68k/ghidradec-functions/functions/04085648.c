
undefined4 _snd_reply_dsp_err(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_a8;
  int iStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  int iStack_88;
  undefined auStack_84 [128];
  
  uStack_a8 = dword_40B21D8;
  uStack_a0 = dword_40B21E0;
  uStack_98 = dword_40B21E8;
  uStack_94 = 0x13b;
  uStack_9c = 0;
  iStack_a4 = 0x24;
  uStack_90 = dword_40B2200;
  uStack_8c = dword_40B2204;
  iStack_88 = dword_40C6E66 - dword_40C6E5E >> 2;
  _bcopy(dword_40C6E5E,auStack_84,iStack_88 << 2);
  dword_40C6E66 = dword_40C6E5E;
  _dsp_dev_loop();
  iStack_a4 = iStack_a4 + iStack_88 * 4;
  iVar1 = _object_copyin(dword_40C6EB8,param_1,6,0,&uStack_98);
  if (iVar1 == 0) {
    uVar2 = 5;
  }
  else {
    uVar2 = _msg_send_from_kernel(&uStack_a8,1,0);
    _port_release(uStack_98);
  }
  return uVar2;
}
