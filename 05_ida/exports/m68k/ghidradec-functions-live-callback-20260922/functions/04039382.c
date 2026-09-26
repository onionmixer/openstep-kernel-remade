
int _getmp(sword param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = _mounttab;
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    if ((*(int *)(iVar2 + 10) != 0) && (param_1 == *(sword *)(iVar2 + 4))) break;
    iVar2 = *(int *)(iVar2 + 0x1c);
  }
  iVar1 = *(int *)(*(int *)(iVar2 + 10) + 0x20);
  if (*(int *)(iVar1 + 0x55c) == 0x11954) {
    return iVar2;
  }
  _printf(aDev0xXFsS,(int)param_1,iVar1 + 0xd4);
                    /* WARNING: Subroutine does not return */
  _panic(aGetmpBadMagic);
}

