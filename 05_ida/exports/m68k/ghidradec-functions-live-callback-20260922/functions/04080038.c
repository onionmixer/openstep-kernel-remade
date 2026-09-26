
uint _snd_device_get_parms(void)

{
  uint uVar1;
  
  uVar1 = (_gpflags & 0xf) >> 3;
  if ((_gpflags & 0x10) == 0) {
    uVar1 = uVar1 | 2;
  }
  return uVar1;
}

