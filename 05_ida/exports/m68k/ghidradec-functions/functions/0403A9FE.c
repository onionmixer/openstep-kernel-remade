
undefined4 sub_403A9FE(int param_1,sword param_2,sword param_3)

{
  int iVar1;
  
  if (param_2 == -1) {
    param_2 = *(sword *)(param_1 + 0x66);
  }
  if (param_3 == -1) {
    param_3 = *(sword *)(param_1 + 0x68);
  }
  if ((((param_2 != *(sword *)(*(int *)(_active_u + 0x1a) + 2)) ||
       (param_2 != *(sword *)(param_1 + 0x66))) || (iVar1 = _groupmember((int)param_3), iVar1 == 0))
     && (iVar1 = _suser(), iVar1 == 0)) {
    return 1;
  }
  *(sword *)(param_1 + 0x66) = param_2;
  *(sword *)(param_1 + 0x68) = param_3;
  *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x40;
  if (*(sword *)(*(int *)(_active_u + 0x1a) + 2) != 0) {
    *(word *)(param_1 + 0x62) = *(word *)(param_1 + 0x62) & 0xf3ff;
  }
  return 0;
}
