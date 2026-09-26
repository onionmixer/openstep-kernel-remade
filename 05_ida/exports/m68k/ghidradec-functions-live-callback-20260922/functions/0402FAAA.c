
void sub_402FAAA(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  *param_1 = uVar1 & 0xfffffffe;
  if ((uVar1 & 2) != 0) {
    *param_1 = uVar1 & 0xfffffffc;
    _wakeup(param_1);
  }
  return;
}

