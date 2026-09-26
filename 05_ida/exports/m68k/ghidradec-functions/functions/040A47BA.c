
void fpsp_bsun(void)

{
  undefined4 in_FPCR;
  undefined4 in_FPSR;
  undefined4 in_FPIAR;
  undefined4 uStack_c8;
  undefined4 *puStack_84;
  
  saveFPUStateFrame(uStack_c8);
  *puStack_84 = in_FPCR;
  puStack_84[3] = in_FPSR;
  puStack_84[6] = in_FPIAR;
  restoreFPUStateFrame(uStack_c8);
  real_bsun();
  return;
}
