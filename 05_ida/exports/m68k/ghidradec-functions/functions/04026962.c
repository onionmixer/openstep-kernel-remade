
undefined4 _unexport(undefined4 param_1,sword *param_2)

{
  sword sVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = &_exported;
  iVar2 = _exported;
  do {
    if (iVar2 == 0) {
      return 0x16;
    }
    iVar2 = _bcmp(*piVar3 + 0x20,param_1,8);
    if (iVar2 == 0) {
      sVar1 = **(sword **)(*piVar3 + 0x28);
      if ((sVar1 == *param_2) &&
         (iVar2 = _bcmp(*(sword **)(*piVar3 + 0x28) + 1,param_2 + 1,sVar1), iVar2 == 0)) {
        iVar2 = *piVar3;
        *piVar3 = *(int *)(iVar2 + 0x2c);
        _exportfree(iVar2);
        return 0;
      }
    }
    piVar3 = (int *)(*piVar3 + 0x2c);
    iVar2 = *piVar3;
  } while( true );
}
