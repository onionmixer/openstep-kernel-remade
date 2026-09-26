
undefined4 sub_402860E(undefined4 param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (*param_2 != 0) {
    do {
      iVar1 = sub_40285E0(param_1,param_2[1] + uVar2 * 0x10);
      if (iVar1 != 0) {
        return 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *param_2);
  }
  return 0;
}
