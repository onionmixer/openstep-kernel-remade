
void real_snan(void)

{
  undefined4 uStack_c8;
  
  saveFPUStateFrame(uStack_c8);
  restoreFPUStateFrame(uStack_c8);
  dword_40B3108 = dword_40B3108 + 1;
  std_trap();
  return;
}

