
void _swift_vac_pageflush(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0x200;
  do {
    iVar2 = iVar2 + -0x10;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0x200 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0x400 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0x600 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0x800 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0xa00 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0xc00 + iVar1) = 0;
    iVar1 = segment(0x10);
    *(undefined4 *)(param_1 + 0xe00 + iVar1) = 0;
    param_1 = param_1 + 0x10;
  } while (iVar2 != 0);
  return;
}
