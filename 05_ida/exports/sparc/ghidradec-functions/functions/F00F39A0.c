
/* WARNING: Removing unreachable block (ram,0xf00f3a8c) */
/* WARNING: Removing unreachable block (ram,0xf00f3a50) */

undefined8 _sel_getUid(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 *puVar5;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
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
  if (param_1 == (byte *)0x0) {
    param_1 = (byte *)0x0;
  }
  else {
    uVar4 = 0;
    pbVar3 = param_1;
    while( true ) {
      if (*pbVar3 == 0) break;
      uVar4 = uVar4 ^ *pbVar3;
      if (pbVar3[1] == 0) break;
      uVar4 = uVar4 ^ (uint)pbVar3[1] << 8;
      if (pbVar3[2] == 0) break;
      uVar4 = uVar4 ^ (uint)pbVar3[2] << 0x10;
      if (pbVar3[3] == 0) break;
      uVar4 = uVar4 ^ (uint)pbVar3[3] << 0x18;
      pbVar3 = pbVar3 + 4;
    }
    if (off_F012F16C != 0) {
      pbVar3 = *(byte **)(off_F012F16C + 0xc);
      iVar6 = off_F012F16C;
      while( true ) {
        if ((pbVar3 <= param_1) && (param_1 < *(byte **)(iVar6 + 0x10))) goto locret_F00F3AC4;
        uVar1 = uVar4;
        .urem(uVar4,*(undefined4 *)(iVar6 + 4));
        puVar5 = *(undefined4 **)(*(int *)(iVar6 + 0x14) + uVar1 * 4);
        if (puVar5 == (undefined4 *)0x0) {
          iVar6 = *(int *)(iVar6 + 0x18);
        }
        else {
          pbVar3 = (byte *)puVar5[1];
          while( true ) {
            if (*param_1 == *pbVar3) {
              pbVar2 = param_1;
              _strcmp(param_1,pbVar3);
              if (pbVar2 == (byte *)0x0) {
                param_1 = (byte *)puVar5[1];
                goto locret_F00F3AC4;
              }
              puVar5 = (undefined4 *)*puVar5;
            }
            else {
              puVar5 = (undefined4 *)*puVar5;
            }
            if (puVar5 == (undefined4 *)0x0) break;
            pbVar3 = (byte *)puVar5[1];
          }
          iVar6 = *(int *)(iVar6 + 0x18);
        }
        if (iVar6 == 0) break;
        pbVar3 = *(byte **)(iVar6 + 0xc);
      }
    }
    param_1 = (byte *)0x0;
  }
locret_F00F3AC4:
  return CONCAT44(param_2,param_1);
}
