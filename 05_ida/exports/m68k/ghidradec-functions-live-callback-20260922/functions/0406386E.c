
undefined4 _volopen(void)

{
  undefined4 uVar1;
  
  if (byte_40B4E80 == '\0') {
    byte_40B4E80 = '\x01';
    uVar1 = 0;
  }
  else {
    uVar1 = 0x10;
  }
  return uVar1;
}

