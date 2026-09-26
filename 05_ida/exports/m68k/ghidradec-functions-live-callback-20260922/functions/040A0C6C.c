
void real_bsun(void)

{
  undefined4 uStack_c8;
  
  saveFPUStateFrame(uStack_c8);
  restoreFPUStateFrame(uStack_c8);
  dword_40B30F0 = dword_40B30F0 + 1;
  std_trap();
  return;
}

