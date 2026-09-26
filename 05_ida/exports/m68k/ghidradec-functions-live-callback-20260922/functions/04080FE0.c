
undefined4 sub_4080FE0(int param_1)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = dword_40C6E66 == dword_40C6E62;
  iVar1 = *(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x10) == 0) {
    iVar1 = _snd_var;
  }
  if (dword_40C6E66 != dword_40C6E5E) {
    _snd_reply_dsp_err(iVar1);
    iVar1 = dword_40C6E80;
  }
  dword_40C6E80 = iVar1;
  if (bVar2) {
    _dsp_dev_loop();
  }
  return 0;
}

