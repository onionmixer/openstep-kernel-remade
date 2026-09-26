
void inex(void)

{
  byte *pbVar1;
  uint in_FPSR;
  byte bStack_e0;
  undefined4 uStack_c8;
  uint uStack_8;
  
  if (_cpu_type == '\0') {
    saveFPUStateFrame(uStack_8);
    if (uStack_8._0_1_ != '\0') {
      pbVar1 = (byte *)((int)&uStack_8 + (uStack_8 >> 0x10 & 0xff));
      *pbVar1 = *pbVar1 | 8;
    }
    restoreFPUStateFrame(uStack_8);
    std_trap();
    return;
  }
  saveFPUStateFrame(uStack_c8);
  if (uStack_c8._0_1_ != '@') {
    return;
  }
  if ((bStack_e0 & 4) != 0) {
    if ((in_FPSR & 0x4000) != 0) {
      restoreFPUStateFrame(uStack_c8);
      snan();
      return;
    }
    if ((in_FPSR & 0x1000) != 0) {
      restoreFPUStateFrame(uStack_c8);
      ovfl();
      return;
    }
    if ((in_FPSR & 0x800) != 0) {
      restoreFPUStateFrame(uStack_c8);
      unfl();
      return;
    }
  }
  restoreFPUStateFrame(uStack_c8);
  return;
}

