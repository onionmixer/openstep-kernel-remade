
int _choose_thread(int param_1)

{
  word wVar1;
  sword sVar3;
  int iVar2;
  int *piVar4;
  int *piVar5;
  
  if (*(int *)(param_1 + 0x104) < 1) {
    iVar2 = _choose_pset_thread(param_1,*(undefined4 *)(param_1 + 0x128));
    return iVar2;
  }
  iVar2 = *(int *)(param_1 + 0x100);
  piVar5 = (int *)(param_1 + iVar2 * 8);
  if (-1 < iVar2) {
    do {
      piVar4 = (int *)*piVar5;
      if (piVar4 != piVar5) {
        if (piVar5 == piVar4) {
          piVar4 = (int *)0x0;
        }
        else {
          *(int **)(*piVar4 + 4) = piVar5;
          *piVar5 = *piVar4;
        }
        *(undefined4 *)((int)piVar4 + 8) = 0;
        *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + -1;
        *(int *)(param_1 + 0x100) = iVar2;
        return (int)piVar4;
      }
      piVar5 = piVar5 + -2;
      wVar1 = (word)((uint)iVar2 >> 0x10);
      sVar3 = (sword)iVar2 + -1;
      iVar2 = CONCAT22(wVar1,sVar3);
    } while ((sVar3 != -1) || (iVar2 = (uint)wVar1 * 0x10000 + -1, wVar1 != 0));
  }
                    /* WARNING: Subroutine does not return */
  _panic(aChooseThread);
}

