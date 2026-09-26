
void _vno_bsd_unlock(int param_1,uint param_2)

{
  int iVar1;
  word wVar2;
  sword sVar3;
  
  iVar1 = *(int *)(param_1 + 0x16);
  param_2 = *(uint *)(param_1 + 8) & param_2;
  if ((iVar1 != 0) && (param_2 != 0)) {
    wVar2 = *(word *)(iVar1 + 4);
    if ((char)param_2 < '\0') {
      if ((wVar2 & 8) == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(aVnoBsdUnlockSh);
      }
      sVar3 = *(sword *)(iVar1 + 8);
      *(sword *)(iVar1 + 8) = sVar3 + -1;
      if ((sVar3 == 1) &&
         (*(word *)(iVar1 + 4) = *(word *)(iVar1 + 4) & 0xfff7, (wVar2 & 0x10) != 0)) {
        _wakeup(iVar1 + 8);
      }
      *(word *)(param_1 + 10) = *(word *)(param_1 + 10) & 0xff7f;
    }
    if ((param_2 & 0x100) != 0) {
      if ((wVar2 & 4) == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(aVnoBsdUnlockEx);
      }
      sVar3 = *(sword *)(iVar1 + 10);
      *(sword *)(iVar1 + 10) = sVar3 + -1;
      if ((sVar3 == 1) &&
         (*(word *)(iVar1 + 4) = *(word *)(iVar1 + 4) & 0xffeb, (wVar2 & 0x10) != 0)) {
        _wakeup(iVar1 + 10);
      }
      *(word *)(param_1 + 10) = *(word *)(param_1 + 10) & 0xfeff;
    }
  }
  return;
}
