
undefined8 _fc_flags_bset(int param_1,uint param_2)

{
  uint uVar1;
  char in_XF;
  
  uVar1 = param_2 | *(uint *)(param_1 + 0x18);
  *(uint *)(param_1 + 0x18) = uVar1;
  return CONCAT44(CONCAT22((sword)(uVar1 >> 0x10),
                           (word)(byte)(((int)uVar1 < 0) << 3 | (uVar1 == 0) << 2)),
                  (int)(sword)(word)(byte)(in_XF << 4 | ((int)param_2 < 0) << 3 |
                                          (param_2 == 0) << 2));
}
