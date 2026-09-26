
void sub_402DC60(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  *param_1 = uVar1 & 0xfffffff7;
  if ((uVar1 & 0x10) != 0) {
    *param_1 = uVar1 & 0xffffffe7;
    _wakeup(param_1 + 0x1a);
  }
  return;
}

