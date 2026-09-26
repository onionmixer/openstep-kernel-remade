
undefined4 _snd_reply_dsp_msg(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_828;
  int iStack_824;
  undefined4 uStack_820;
  undefined4 uStack_81c;
  undefined4 uStack_818;
  undefined4 uStack_814;
  undefined4 uStack_810;
  undefined4 uStack_80c;
  int iStack_808;
  undefined auStack_804 [2048];
  
  uStack_828 = dword_40B21D8;
  uStack_820 = dword_40B21E0;
  uStack_818 = dword_40B21E8;
  uStack_814 = 0x13c;
  uStack_81c = 0;
  iStack_824 = 0x24;
  uStack_810 = dword_40B2200;
  uStack_80c = dword_40B2204;
  iStack_808 = dword_40C6E5A - dword_40C6E52 >> 2;
  _bcopy(dword_40C6E52,auStack_804,iStack_808 << 2);
  dword_40C6E5A = dword_40C6E52;
  _dsp_dev_loop();
  iStack_824 = iStack_824 + iStack_808 * 4;
  iVar1 = _object_copyin(dword_40C6EB8,param_1,6,0,&uStack_818);
  if (iVar1 == 0) {
    uVar2 = 5;
  }
  else {
    uVar2 = _msg_send_from_kernel(&uStack_828,1,0);
    _port_release(uStack_818);
  }
  return uVar2;
}
