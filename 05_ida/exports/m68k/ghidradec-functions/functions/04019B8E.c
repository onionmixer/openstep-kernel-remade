
undefined4 _pn_combine(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((uint)(*(int *)(param_2 + 8) + param_1[2]) < 0x400) {
    _ovbcopy(param_1[1],*param_1 + *(int *)(param_2 + 8),param_1[2]);
    _bcopy(*(undefined4 *)(param_2 + 4),*param_1,*(undefined4 *)(param_2 + 8));
    param_1[2] = *(int *)(param_2 + 8) + param_1[2];
    param_1[1] = *param_1;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x3f;
  }
  return uVar1;
}
