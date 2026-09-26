
void _ts_add(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  uVar2 = param_2 + uVar1;
  *param_1 = uVar2;
  if (uVar2 < uVar1) {
    param_1[1] = param_1[1] + 1;
  }
  return;
}

