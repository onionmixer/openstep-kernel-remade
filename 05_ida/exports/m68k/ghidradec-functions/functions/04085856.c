
undefined4 _snd_reply_dsp_cond_true(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_2c = dword_40B21D8;
  uStack_24 = dword_40B21E0;
  uStack_1c = dword_40B21E8;
  uStack_18 = 0x13f;
  uStack_20 = 0;
  uStack_28 = 0x28;
  uStack_14 = dword_40B21FC & 0xffff003f | 0x30;
  uStack_10 = *(undefined4 *)(param_1 + 4);
  uStack_c = *(undefined4 *)(param_1 + 8);
  uStack_8 = *(undefined4 *)(param_1 + 0x14);
  iVar1 = _object_copyin(dword_40C6EB8,*(undefined4 *)(param_1 + 0xc),6,0,&uStack_1c);
  if (iVar1 == 0) {
    uVar2 = 5;
  }
  else {
    uVar2 = _msg_send_from_kernel(&uStack_2c,1,0);
    _port_release(uStack_1c);
  }
  return uVar2;
}
