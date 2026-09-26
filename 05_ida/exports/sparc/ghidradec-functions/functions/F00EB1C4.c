
undefined4 -[List objectAt:](int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (param_3 < *(uint *)(param_1 + 8)) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 4) + param_3 * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
