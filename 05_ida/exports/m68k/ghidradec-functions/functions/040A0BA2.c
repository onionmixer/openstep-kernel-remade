
void real_unfl(void)

{
  undefined4 uStack_c8;
  
  dword_40B30FC = dword_40B30FC + 1;
  saveFPUStateFrame(uStack_c8);
  restoreFPUStateFrame(uStack_c8);
  std_trap();
  return;
}
