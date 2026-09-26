
undefined4 _fspause(int param_1)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(dword_40B57D4 + 0x66);
  uVar3 = (uint)*(char *)(dword_40B57D4 + 0x6a);
  *(undefined4 *)(dword_40B57D4 + 0x66) = 0;
  *(undefined *)(dword_40B57D4 + 0x6a) = 0;
  if ((((iVar2 != 0) && (uVar3 != 0)) && (*(char *)(dword_40B57D4 + 100) == '\x1c')) &&
     (((*(byte *)(_active_u + 0x254) & 8) != 0 && (param_1 == 0)))) {
    *(undefined *)(dword_40B57D4 + 100) = 0;
    puVar1 = aFileSystemIsFu;
    if ((uVar3 & 1) == 0) {
      puVar1 = aOutOfInodes_0;
    }
    iVar2 = _rpsleep(_fssleep,iVar2,uVar3,iVar2 + 0xd4,puVar1);
    if (iVar2 != 0) {
      return 1;
    }
    *(undefined *)(dword_40B57D4 + 100) = 0x1c;
  }
  return 0;
}

