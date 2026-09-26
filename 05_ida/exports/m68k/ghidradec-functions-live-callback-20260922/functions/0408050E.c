
undefined4 _snd_device_def_dmasize(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x100;
  if (param_1 == 0) {
    uVar1 = _page_size;
  }
  return uVar1;
}

