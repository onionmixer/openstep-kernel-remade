
undefined4 _fc_flags_bclr(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = ~param_2 & *(uint *)(param_1 + 0x18);
  *(uint *)(param_1 + 0x18) = uVar1;
  return CONCAT22((sword)(uVar1 >> 0x10),(word)(byte)(((int)uVar1 < 0) << 3 | (uVar1 == 0) << 2));
}
