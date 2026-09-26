
undefined8 sub_406B346(int param_1,int param_2)

{
  uint uVar1;
  char in_XF;
  
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xffffffbf;
  uVar1 = *(uint *)(param_1 + 0x18);
  *(uint *)(param_1 + 0x18) = uVar1 | 0x80;
  *(int *)(param_1 + 0x20) = param_2;
  return CONCAT44(CONCAT22((sword)(uVar1 >> 0x10),
                           (word)(byte)((param_2 < 0) << 3 | (param_2 == 0) << 2)),
                  (int)(sword)(word)(byte)(in_XF << 4 | (param_2 < 0) << 3 | (param_2 == 0) << 2));
}

