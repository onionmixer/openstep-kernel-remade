
void __seterr_reply(int param_1,uint *param_2)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 8) == 0) {
    if (*(int *)(param_1 + 0x18) == 0) {
      *param_2 = 0;
      return;
    }
    sub_402F08A(*(int *)(param_1 + 0x18),param_2);
  }
  else if (*(int *)(param_1 + 8) == 1) {
    sub_402F0F2(*(undefined4 *)(param_1 + 0xc),param_2);
  }
  else {
    *param_2 = 0x10;
    param_2[1] = *(uint *)(param_1 + 8);
  }
  uVar1 = *param_2;
  if (uVar1 == 7) {
    param_2[1] = *(uint *)(param_1 + 0x10);
  }
  else if (uVar1 < 8) {
    if (uVar1 == 6) {
      param_2[1] = *(uint *)(param_1 + 0x10);
      param_2[2] = *(uint *)(param_1 + 0x14);
    }
  }
  else if (uVar1 == 9) {
    param_2[1] = *(uint *)(param_1 + 0x1c);
    param_2[2] = *(uint *)(param_1 + 0x20);
  }
  return;
}

