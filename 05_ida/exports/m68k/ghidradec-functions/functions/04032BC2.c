
int sub_4032BC2(int param_1,int *param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined auStack_32 [34];
  undefined4 uStack_10;
  
  dword_40B35AE = dword_40B35AE + 1;
  if (param_4 == *(int *)(param_1 + 0x2c)) {
    dword_40B35B2 = dword_40B35B2 + 1;
    iVar1 = *(int *)(param_1 + 0x24);
  }
  else {
    if (param_4 != *(int *)(param_1 + 0x3e)) {
      if (*(char *)(param_1 + 0x30) != '\0') {
        dword_40B35BA = dword_40B35BA + 1;
        iVar1 = sub_4032B84(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x28),_page_size,
                            *(undefined4 *)(param_1 + 0x2c));
        if (iVar1 != 0) {
          _printf(aCannotFlushInp);
          return iVar1;
        }
        *(undefined *)(param_1 + 0x30) = 0;
      }
      *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
      uStack_10 = *(undefined4 *)(param_1 + 0x28);
      iVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 0x1c) + 0x74))
                        (*(int *)(param_1 + 8),auStack_32,param_4);
      if (iVar1 != 0) {
        return iVar1;
      }
      *(int *)(param_1 + 0x2c) = param_4;
      *param_2 = *(int *)(param_1 + 0x24) + param_5;
      return 0;
    }
    dword_40B35B6 = dword_40B35B6 + 1;
    iVar1 = *(int *)(param_1 + 0x32);
  }
  *param_2 = iVar1 + param_5;
  return 0;
}
