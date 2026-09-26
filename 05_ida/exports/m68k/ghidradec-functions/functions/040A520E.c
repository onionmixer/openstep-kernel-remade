
void fpsp_unfl(void)

{
  undefined4 in_FPCR;
  undefined4 in_FPSR;
  undefined4 in_FPIAR;
  uint uStack_e0;
  undefined4 uStack_c8;
  undefined4 uStack_84;
  byte bStack_7e;
  undefined4 uStack_80;
  
  saveFPUStateFrame(uStack_c8);
  *uStack_84 = in_FPCR;
  uStack_84[3] = in_FPSR;
  uStack_84[6] = in_FPIAR;
  sub_40A533C();
  if (((uint)uStack_84 & 0x800) != 0) {
    if ((uStack_e0 & 0x2000000) != 0) {
      b1238_fix();
    }
    restoreFPUStateFrame(uStack_c8);
    real_unfl();
    return;
  }
  if ((bStack_7e & uStack_84._2_1_ & 3) != 0) {
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
