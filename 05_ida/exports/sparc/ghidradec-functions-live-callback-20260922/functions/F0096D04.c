
uint _splr(uint param_1)

{
  uint uVar1;
  int in_TL;
  
  uVar1 = *(uint *)((uint)(in_TL == 1) * 0x7000 + (uint)(in_TL == 2) * 0x7004 +
                    (uint)(in_TL == 3) * 0x7008 + (uint)(in_TL == 4) * 0x700c) & 0xf00;
  if ((param_1 & 0xf00) <= uVar1) {
    return uVar1;
  }
  return param_1 & 0xf00;
}

