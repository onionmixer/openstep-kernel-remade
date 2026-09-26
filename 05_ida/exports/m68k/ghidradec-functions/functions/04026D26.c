
int _findexport(undefined4 param_1,sword *param_2)

{
  int iVar1;
  sword sVar2;
  int iVar3;
  
  iVar1 = _exported;
  do {
    if (iVar1 == 0) {
      return 0;
    }
    iVar3 = _bcmp(iVar1 + 0x20,param_1,8);
    if (iVar3 == 0) {
      sVar2 = **(sword **)(iVar1 + 0x28);
      if ((sVar2 == *param_2) &&
         (iVar3 = _bcmp(*(sword **)(iVar1 + 0x28) + 1,param_2 + 1,sVar2), iVar3 == 0)) {
        return iVar1;
      }
    }
    iVar1 = *(int *)(iVar1 + 0x2c);
  } while( true );
}
