
void real_ovfl(void)

{
  undefined4 uStack_c8;
  
  dword_40B3100 = dword_40B3100 + 1;
  saveFPUStateFrame(uStack_c8);
  restoreFPUStateFrame(uStack_c8);
  std_trap();
  return;
}

