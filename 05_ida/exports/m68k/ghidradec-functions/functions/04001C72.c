
void ipl4(void)

{
  code *pcVar1;
  uint uVar2;
  undefined4 in_D0;
  sword sVar3;
  undefined *puVar4;
  undefined2 in_stack_00000000;
  undefined4 in_stack_00000002;
  undefined auStack_40 [8];
  
  puVar4 = auStack_40;
  if ((undefined *)0x4001318 < puVar4) {
    puVar4 = (undefined *)0x4001318;
  }
  *(uint *)(puVar4 + -4) = CONCAT22((sword)((uint)in_D0 >> 0x10),in_stack_00000000);
  *(undefined4 *)(puVar4 + -8) = in_stack_00000002;
  while( true ) {
    uVar2 = (_intr_mask & *_intrstat & 0x7fff) >> 0xe;
    if (uVar2 == 0) break;
    sVar3 = (word)(uVar2 != 0) * (sword)LZCOUNT(uVar2 << 0x1f) + (word)(uVar2 == 0) * 0x12 + -0x11;
    pcVar1 = (code *)(&_ipl4_scan)[sVar3];
    *(undefined4 *)(puVar4 + -0xc) = (&_ipl4_arg)[sVar3];
    *(undefined4 *)(puVar4 + -0x10) = 0x4001cde;
    (*pcVar1)();
  }
  func_0x040021cc();
  return;
}
