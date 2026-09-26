
void _pgdelete(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = &_pgrphash + (param_1[3] & 0x3f);
  if ((*(int *)(param_1[2] + 8) != 0) &&
     (piVar2 = (int *)_ttynty(*(int *)(param_1[2] + 8)), param_1 == (int *)piVar2[3])) {
    piVar2[3] = 0;
    *(undefined2 *)(*piVar2 + 0x42) = 0;
  }
  do {
    piVar2 = piVar1;
    if (*piVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aPgdeleteCanTFi);
    }
    piVar1 = (int *)*piVar2;
  } while (param_1 != (int *)*piVar2);
  *piVar2 = *param_1;
  iVar3 = *(int *)param_1[2];
  *(int *)param_1[2] = iVar3 + -1;
  if (iVar3 == 1) {
    if (*(int *)(param_1[2] + 8) != 0) {
      iVar3 = _ttynty(*(int *)(param_1[2] + 8));
      *(undefined4 *)(iVar3 + 8) = 0;
    }
    _kfree(param_1[2],0xe);
  }
  _kfree(param_1,0x14);
  return;
}
