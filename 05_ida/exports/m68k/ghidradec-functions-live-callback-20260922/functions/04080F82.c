
undefined4 sub_4080F82(int param_1)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = dword_40C6E5A == dword_40C6E56;
  iVar1 = *(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x10) == 0) {
    iVar1 = _snd_var;
  }
  if (dword_40C6E5A != dword_40C6E52) {
    _snd_reply_dsp_msg(iVar1);
    iVar1 = dword_40C6E7C;
  }
  dword_40C6E7C = iVar1;
  if (bVar2) {
    _dsp_dev_loop();
  }
  return 0;
}

