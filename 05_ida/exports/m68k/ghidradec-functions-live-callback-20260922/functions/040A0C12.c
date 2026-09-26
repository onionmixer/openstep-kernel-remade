
void real_operr(void)

{
  undefined4 uStack_c8;
  
  saveFPUStateFrame(uStack_c8);
  restoreFPUStateFrame(uStack_c8);
  dword_40B3104 = dword_40B3104 + 1;
  std_trap();
  return;
}

