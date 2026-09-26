
undefined4 -[List lastObject](int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 8) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 8) * 4 + *(int *)(param_1 + 4) + -4);
  }
  return uVar1;
}

