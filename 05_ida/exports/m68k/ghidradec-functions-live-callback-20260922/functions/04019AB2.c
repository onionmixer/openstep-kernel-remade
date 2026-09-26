
void _pn_alloc(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = _kalloc(0x400);
  *param_1 = uVar1;
  param_1[1] = uVar1;
  param_1[2] = 0;
  return;
}

