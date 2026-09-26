
void _swift_vac_flushall(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0x4000;
  do {
    iVar2 = iVar2 + -0x10;
    iVar1 = segment(0xc);
    *(undefined4 *)(iVar2 + iVar1) = 0;
    iVar1 = segment(0xe);
    *(undefined4 *)(iVar2 + iVar1) = 0;
  } while (iVar2 != 0);
  return;
}
