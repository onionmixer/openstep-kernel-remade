
uint sub_408CF32(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  param_2 = param_2 & 7;
  _delay(1);
  uVar1 = *(uint *)(DAT_40b5420 + param_1 * 0x164);
  if (param_3 == 1) {
    uVar1 = param_2 | uVar1;
  }
  else if (param_3 < 2) {
    if (param_3 == 0) {
      uVar1 = uVar1 & 0x38 | param_2;
    }
  }
  else if (param_3 == 2) {
    uVar1 = ~param_2 & uVar1;
  }
  else if (param_3 == 3) {
    return uVar1;
  }
  *(uint *)(DAT_40b5420 + param_1 * 0x164) = uVar1;
  sub_408CFC8(param_1);
  return uVar1;
}
