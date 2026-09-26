
void _pset_remove_processor(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 != *(int *)(param_2 + 0x128)) {
                    /* WARNING: Subroutine does not return */
    _panic(aPsetRemoveProc);
  }
  iVar1 = *(int *)(param_2 + 0x130);
  piVar2 = *(int **)(param_2 + 0x134);
  if (iVar1 == param_1 + 0x114) {
    *(int **)(param_1 + 0x118) = piVar2;
  }
  else {
    *(int **)(iVar1 + 0x134) = piVar2;
  }
  if (piVar2 == (int *)(param_1 + 0x114)) {
    *piVar2 = iVar1;
  }
  else {
    piVar2[0x4c] = iVar1;
  }
  *(undefined4 *)(param_2 + 0x128) = 0;
  *(int *)(param_1 + 0x11c) = *(int *)(param_1 + 0x11c) + -1;
  _quantum_set(param_1);
  return;
}
