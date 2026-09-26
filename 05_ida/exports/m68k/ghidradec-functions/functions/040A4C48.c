
void fpsp_ovfl(void)

{
  undefined4 in_FPCR;
  undefined4 in_FPSR;
  undefined4 in_FPIAR;
  uint uStack_e0;
  undefined4 uStack_c8;
  undefined4 *puStack_84;
  
  saveFPUStateFrame(uStack_c8);
  *puStack_84 = in_FPCR;
  puStack_84[3] = in_FPSR;
  puStack_84[6] = in_FPIAR;
  sub_40A4D76();
  if (((uint)puStack_84 & 0x1000) != 0) {
    if ((uStack_e0 & 0x2000000) != 0) {
      b1238_fix();
    }
    restoreFPUStateFrame(uStack_c8);
    real_ovfl();
    return;
  }
  if (((uint)puStack_84 & 0x200) != 0) {
    if ((uStack_e0 & 0x2000000) != 0) {
      b1238_fix();
    }
    restoreFPUStateFrame(uStack_c8);
    real_inex();
    return;
  }
  if ((uStack_e0 & 0x2000000) != 0) {
    b1238_fix();
    restoreFPUStateFrame(uStack_c8);
    fpsp_done();
    return;
  }
  fpsp_done();
  return;
}
