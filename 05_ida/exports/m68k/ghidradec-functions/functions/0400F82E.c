
undefined4 _ttcheckwakeup(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((((*(uint *)(*param_1 + 0x3a) & 0x22) != 0) &&
      (*(int *)*param_1 < (int)(uint)*(byte *)((int)param_1 + 0x15))) &&
     (*(char *)((int)param_1 + 0x16) == '\0')) {
    uVar1 = 0;
  }
  return uVar1;
}
