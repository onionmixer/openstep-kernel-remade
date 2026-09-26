
void real_inex(void)

{
  byte bStack_e0;
  undefined4 uStack_c8;
  
  dword_40B30F4 = dword_40B30F4 + 1;
  saveFPUStateFrame(uStack_c8);
  if ((bStack_e0 & 2) != 0) {
    b1238_fix();
  }
  restoreFPUStateFrame(uStack_c8);
  std_trap();
  return;
}

