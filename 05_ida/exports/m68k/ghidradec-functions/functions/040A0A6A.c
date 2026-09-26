
void real_dz(void)

{
  undefined4 uStack_c8;
  
  saveFPUStateFrame(uStack_c8);
  restoreFPUStateFrame(uStack_c8);
  dword_40B30F8 = dword_40B30F8 + 1;
  std_trap();
  return;
}
