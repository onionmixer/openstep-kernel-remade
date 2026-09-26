
void ipl6(void)

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
    uVar2 = (_intr_mask & *_intrstat & 0x3fffffff) >> 0x12;
    if (uVar2 == 0) break;
    sVar3 = (word)(uVar2 != 0) * (sword)LZCOUNT(uVar2 << 0x14) + (word)(uVar2 == 0) * 0xe + -2;
    pcVar1 = *(code **)(_ipl6_scan + sVar3 * 4);
    *(undefined4 *)(puVar4 + -0xc) = *(undefined4 *)(_ipl6_arg + sVar3 * 4);
    *(undefined4 *)(puVar4 + -0x10) = 0x4001d86;
    (*pcVar1)();
  }
  dword_40B565C = dword_40B565C + 1;
  return;
}

