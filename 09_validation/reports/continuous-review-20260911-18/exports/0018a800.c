
uint _fp_terminate(uint param_1)

{
  uint uVar1;
  uint in_CR0;
  
  uVar1 = DAT_001e75f8;
  if (param_1 == DAT_001e75f8) {
    DAT_001e75f8 = 0;
    uVar1 = in_CR0 | 8;
  }
  return uVar1;
}

