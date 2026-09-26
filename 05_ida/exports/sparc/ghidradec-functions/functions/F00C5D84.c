
undefined8 _strstr(byte *param_1,char *param_2)

{
  byte bVar1;
  byte bVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  byte *pbVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar4;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  byte *pbVar5;
  undefined4 unaff_i5;
  byte *pbVar6;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  uVar4 = (uint)*param_1;
  if (uVar4 != 0) {
    do {
      pbVar3 = param_1 + 1;
      if ((int)(uVar4 * 0x1000000) >> 0x18 == (int)*param_2) {
        pbVar6 = (byte *)(param_2 + 2);
        bVar2 = param_2[1];
        pbVar5 = param_1 + 2;
        bVar1 = *pbVar3;
        while( true ) {
          uVar4 = (uint)bVar2;
          if (((int)(char)bVar1 != (int)(uVar4 * 0x1000000) >> 0x18) || (uVar4 == 0)) break;
          bVar2 = *pbVar6;
          bVar1 = *pbVar5;
          pbVar6 = pbVar6 + 1;
          pbVar5 = pbVar5 + 1;
        }
        if (uVar4 == 0) goto locret_F00C5E24;
        bVar1 = *pbVar3;
      }
      else {
        bVar1 = *pbVar3;
      }
      uVar4 = (uint)bVar1;
      param_1 = pbVar3;
    } while (uVar4 != 0);
  }
  param_1 = (byte *)0x0;
locret_F00C5E24:
  return CONCAT44(param_2,param_1);
}
