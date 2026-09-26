
undefined4 _vik_mxcc_pageflush(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = segment(2);
    *(undefined4 *)(iVar1 + 0x1c00100) = 0x10;
    iVar1 = segment(2);
    *(undefined4 *)(iVar1 + 0x1c00200) = 0x10;
    uVar2 = uVar2 + 0x20;
  } while ((uVar2 & 0xfff) != 0);
  return 0;
}
