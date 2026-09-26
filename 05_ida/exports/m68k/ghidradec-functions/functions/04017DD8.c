
int _geteblk(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (0x2000 < param_1) {
                    /* WARNING: Subroutine does not return */
    _panic(aGeteblkSizeToo);
  }
  do {
    iVar1 = _getnewbuf();
    *(byte *)(iVar1 + 1) = *(byte *)(iVar1 + 1) | 1;
    _bfree(iVar1);
    *(undefined4 *)(*(int *)(iVar1 + 8) + 4) = *(undefined4 *)(iVar1 + 4);
    *(undefined4 *)(*(int *)(iVar1 + 4) + 8) = *(undefined4 *)(iVar1 + 8);
    sub_4018584(iVar1);
    *(undefined2 *)(iVar1 + 0x1c) = 0;
    *(undefined4 *)(iVar1 + 0x28) = 0;
    *(int *)(iVar1 + 4) = dword_40B5864;
    *(undefined4 **)(iVar1 + 8) = &unk_40B5860;
    *(int *)(dword_40B5864 + 8) = iVar1;
    dword_40B5864 = iVar1;
    iVar2 = _brealloc(iVar1,param_1);
  } while (iVar2 == 0);
  return iVar1;
}
