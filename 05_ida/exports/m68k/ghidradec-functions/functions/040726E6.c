
undefined8 _np_recv(uint *param_1,undefined4 *param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int unaff_A2;
  char in_XF;
  
  do {
  } while ((*param_1 & 0x800) != 0);
  if (((*param_1 & 0x40000) == 0) && ((*param_1 & 0x20000) == 0)) {
    uVar2 = 0;
  }
  else {
    if ((*param_1 & 0x20000) != 0) {
      *(byte *)((int)param_1 + 1) = *(byte *)((int)param_1 + 1) | 2;
    }
    uVar1 = *param_1;
    *param_2 = 0;
    *(char *)((int)param_2 + 3) = (char)uVar1;
    *param_3 = param_1[1];
    uVar2 = 1;
  }
  return CONCAT44(uVar2,(int)(sword)(word)(byte)(in_XF << 4 | (unaff_A2 < 0) << 3 |
                                                (unaff_A2 == 0) << 2));
}
