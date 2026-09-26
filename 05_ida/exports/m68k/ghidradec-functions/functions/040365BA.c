
int sub_40365BA(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  
  iVar3 = *(int *)(param_1 + 0x4e);
  iVar2 = _bmap(param_1,0,0,0x400,0);
  if ((iVar2 < 1) || (*(char *)(dword_40B57D4 + 100) != '\0')) {
    cVar4 = *(char *)(dword_40B57D4 + 100);
    if (cVar4 == '\0') {
      return 0x1c;
    }
  }
  else {
    if (*(int *)(iVar3 + 0x34) < 0x400) {
                    /* WARNING: Subroutine does not return */
      _panic(aDirblksizFsize);
    }
    *(undefined4 *)(param_1 + 0x6e) = 0x400;
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
    *(sword *)(param_2 + 100) = *(sword *)(param_2 + 100) + 1;
    *(word *)(param_2 + 0x42) = *(word *)(param_2 + 0x42) | 0x40;
    _iupdat(param_2,1);
    iVar3 = _bread(*(undefined4 *)(param_1 + 0x3e),iVar2 << (*(uint *)(iVar3 + 100) & 0x3f),
                   *(undefined4 *)(iVar3 + 0x34));
    cVar4 = *(char *)(dword_40B57D4 + 100);
    if (cVar4 == '\0') {
      puVar1 = *(undefined4 **)(iVar3 + 0x20);
      *puVar1 = _mastertemplate;
      puVar1[1] = dword_40AF2BE;
      puVar1[2] = dword_40AF2C2;
      puVar1[3] = dword_40AF2C6;
      puVar1[4] = dword_40AF2CA;
      puVar1[5] = dword_40AF2CE;
      *puVar1 = *(undefined4 *)(param_1 + 0x46);
      puVar1[3] = *(undefined4 *)(param_2 + 0x46);
      _bwrite(iVar3);
      cVar4 = *(char *)(dword_40B57D4 + 100);
    }
  }
  return (int)cVar4;
}
