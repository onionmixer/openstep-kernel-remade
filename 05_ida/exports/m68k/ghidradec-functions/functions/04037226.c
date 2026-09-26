
undefined4 _disksort_first(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  sub_4036D3E(param_1);
  if (*(char *)(param_1 + 0xc) < '\0') {
    uVar2 = (*dword_40C1090)(param_1);
  }
  else {
    piVar1 = *(int **)(param_1 + 0xe);
    if (piVar1 == (int *)(param_1 + 0xe)) {
      uVar2 = 0;
    }
    else {
      uVar2 = *piVar1;
    }
  }
  return uVar2;
}
