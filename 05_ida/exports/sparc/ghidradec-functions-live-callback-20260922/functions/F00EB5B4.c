
undefined4 -[List replaceObjectAt:with:](int param_1,undefined4 param_2,uint param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_4 == 0) {
    uVar1 = 0;
  }
  else if (param_3 < *(uint *)(param_1 + 8)) {
    uVar1 = *(undefined4 *)(param_3 * 4 + *(int *)(param_1 + 4));
    *(int *)(param_3 * 4 + *(int *)(param_1 + 4)) = param_4;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

