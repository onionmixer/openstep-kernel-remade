
void _dnlc_enterSymLink(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_3[2];
  if ((iVar1 != 0) && (iVar2 = _dnlc_lookupSymLink(param_1,param_2), iVar2 != 0)) {
    if (*(char *)(iVar2 + 0x42) != '\0') {
      if (((int)*(sword *)(iVar2 + 0x44) == param_3[2]) &&
         (iVar3 = _bcmp(*param_3,*(undefined4 *)(iVar2 + 0x3e),(int)*(sword *)(iVar2 + 0x44)),
         iVar3 == 0)) {
        return;
      }
      _kfree(*(undefined4 *)(iVar2 + 0x3e),(int)*(sword *)(iVar2 + 0x44));
    }
    iVar3 = _kalloc(iVar1);
    *(int *)(iVar2 + 0x3e) = iVar3;
    if (iVar3 != 0) {
      *(undefined *)(iVar2 + 0x42) = 1;
      *(sword *)(iVar2 + 0x44) = (sword)iVar1;
      _bcopy(*param_3,*(undefined4 *)(iVar2 + 0x3e),iVar1);
      *(undefined4 *)(*(int *)(iVar2 + 0xc) + 8) = *(undefined4 *)(iVar2 + 8);
      *(undefined4 *)(*(int *)(iVar2 + 8) + 0xc) = *(undefined4 *)(iVar2 + 0xc);
      iVar3 = dword_40B6D6C;
      iVar1 = *(int *)(dword_40B6D6C + 8);
      *(int *)(dword_40B6D6C + 8) = iVar2;
      *(int *)(iVar2 + 8) = iVar1;
      *(int *)(iVar1 + 0xc) = iVar2;
      *(int *)(iVar2 + 0xc) = iVar3;
    }
  }
  return;
}
