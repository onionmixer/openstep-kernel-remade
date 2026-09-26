
void _swift_vac_usrflush(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0x800;
  iVar2 = 0;
  do {
    iVar3 = iVar3 + -0x20;
    iVar1 = segment(0x14);
    *(undefined4 *)(iVar2 + iVar1) = 0;
    iVar1 = segment(0x14);
    *(undefined4 *)(iVar2 + 0x800 + iVar1) = 0;
    iVar1 = segment(0x14);
    *(undefined4 *)(iVar2 + 0x1000 + iVar1) = 0;
    iVar1 = segment(0x14);
    *(undefined4 *)(iVar2 + 0x1800 + iVar1) = 0;
    iVar1 = segment(0x14);
    *(undefined4 *)(iVar2 + 0x2010 + iVar1) = 0;
    iVar1 = segment(0x14);
    *(undefined4 *)(iVar2 + 0x2810 + iVar1) = 0;
    iVar1 = segment(0x14);
    *(undefined4 *)(iVar2 + 0x3010 + iVar1) = 0;
    iVar1 = segment(0x14);
    *(undefined4 *)(iVar2 + 0x3810 + iVar1) = 0;
    iVar2 = iVar2 + 0x20;
  } while (iVar3 != 0);
  return;
}
