
void sub_4058090(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 4) == 0x40) && (*(char *)(param_1 + 3) == '\0')) {
    if (((*(int *)(param_1 + 0x18) == 0x6200018) &&
        (((*(int *)(param_1 + 0x20) == 0x6200018 && (*(int *)(param_1 + 0x28) == 0x2200018)) &&
         (*(int *)(param_1 + 0x30) == 0x2200018)))) && (*(int *)(param_1 + 0x38) == 0x2200018)) {
      uVar1 = _catch_exception_raise
                        (*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x1c),
                         *(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x2c),
                         *(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x3c));
      *(undefined4 *)(param_2 + 0x1c) = uVar1;
    }
    else {
      *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
    }
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}
