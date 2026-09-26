
undefined4 sub_4062A70(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  
  param_2 = param_2 >> (_page_shift & 0x3f);
  if (param_2 < *(uint *)(param_1 + 0x10)) {
    if (*(uint *)(param_1 + 0x10) << 2 < 0x41) {
      iVar1 = *(int *)(param_1 + 8);
      cVar2 = *(char *)(iVar1 + param_2 * 4);
    }
    else {
      uVar3 = param_2 >> 4;
      param_2 = param_2 & 0xf;
      iVar1 = *(int *)(*(int *)(param_1 + 8) + uVar3 * 4);
      if (iVar1 == 0) {
        return 0;
      }
      cVar2 = *(char *)(iVar1 + param_2 * 4);
    }
    if (cVar2 != '\0') {
      *param_3 = *(undefined4 *)(iVar1 + param_2 * 4);
      return 1;
    }
  }
  return 0;
}
