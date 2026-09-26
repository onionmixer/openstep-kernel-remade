
void ipl2(void)

{
  undefined *puVar1;
  undefined auStack_40 [8];
  
  puVar1 = auStack_40;
  if ((undefined *)0x4001318 < puVar1) {
    puVar1 = (undefined *)0x4001318;
  }
  *(undefined4 *)(puVar1 + -4) = 1;
  *(undefined4 *)(puVar1 + -8) = 0x4001bfa;
  _softint_run();
  func_0x040021d2();
  return;
}
