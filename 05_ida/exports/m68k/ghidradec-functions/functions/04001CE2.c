
void ipl5(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  undefined auStack_40 [8];
  
  puVar4 = auStack_40;
  if ((undefined *)0x4001318 < puVar4) {
    puVar4 = (undefined *)0x4001318;
  }
  puVar3 = (undefined4 *)_poll_intr;
  do {
    pcVar1 = (code *)*puVar3;
    *(undefined4 *)(puVar4 + -4) = 0x4001d14;
    iVar2 = (*pcVar1)();
    puVar3 = puVar3 + 1;
  } while (iVar2 == 0);
  func_0x040021cc();
  return;
}
