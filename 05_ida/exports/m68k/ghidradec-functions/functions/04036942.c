
int _blkatoff(int param_1,uint param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0x4e);
  uVar3 = param_2 >> (*(uint *)(iVar1 + 0x50) & 0x3f);
  if (((int)uVar3 < 0xc) &&
     (*(uint *)(param_1 + 0x6e) < uVar3 + 1 << (*(uint *)(iVar1 + 0x50) & 0x3f))) {
    uVar4 = *(uint *)(iVar1 + 0x4c) &
            (*(int *)(iVar1 + 0x34) + (*(uint *)(param_1 + 0x6e) & ~*(uint *)(iVar1 + 0x48))) - 1;
  }
  else {
    uVar4 = *(uint *)(iVar1 + 0x30);
  }
  iVar2 = _bmap(param_1,uVar3,1);
  iVar2 = iVar2 << (*(uint *)(iVar1 + 100) & 0x3f);
  if (iVar2 < 0) {
    sub_4036AAC(param_1,aNonexixtentDir,param_2);
    *(undefined *)(dword_40B57D4 + 100) = 2;
  }
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    iVar2 = _bread(*(undefined4 *)(param_1 + 0x3e),iVar2,uVar4);
    if ((*(byte *)(iVar2 + 3) & 4) == 0) {
      if (param_3 != (int *)0x0) {
        *param_3 = *(int *)(iVar2 + 0x20) + (param_2 & ~*(uint *)(iVar1 + 0x48));
      }
    }
    else {
      _brelse(iVar2);
      iVar2 = 0;
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}
