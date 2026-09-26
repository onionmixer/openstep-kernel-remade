
void inex(void)

{
  uint in_FPSR;
  undefined uStack_e0;
  undefined4 uStack_c8;
  
  if (_cpu_type == '\0') {
    func_0x040a0a38();
    return;
  }
  saveFPUStateFrame(uStack_c8);
  if (uStack_c8._0_1_ != '@') {
    return;
  }
  if ((uStack_e0 & 4) != 0) {
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
