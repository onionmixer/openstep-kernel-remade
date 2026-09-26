
/* WARNING: Removing unreachable block (ram,0xf00056bc) */
/* WARNING: Removing unreachable block (ram,0xf000565c) */
/* WARNING: Removing unreachable block (ram,0xf0005640) */
/* WARNING: Removing unreachable block (ram,0xf0005954) */
/* WARNING: Removing unreachable block (ram,0xf00058f4) */
/* WARNING: Removing unreachable block (ram,0xf00058d8) */
/* WARNING: Removing unreachable block (ram,0xf000585c) */
/* WARNING: Removing unreachable block (ram,0xf00057fc) */
/* WARNING: Removing unreachable block (ram,0xf00057e0) */
/* WARNING: Removing unreachable block (ram,0xf0005bf8) */
/* WARNING: Removing unreachable block (ram,0xf0005bd4) */
/* WARNING: Removing unreachable block (ram,0xf0005b50) */
/* WARNING: Removing unreachable block (ram,0xf0005b34) */
/* WARNING: Removing unreachable block (ram,0xf0005ad8) */
/* WARNING: Removing unreachable block (ram,0xf0005ae4) */
/* WARNING: Removing unreachable block (ram,0xf0005b44) */
/* WARNING: Removing unreachable block (ram,0xf0005bc0) */
/* WARNING: Removing unreachable block (ram,0xf0005be8) */
/* WARNING: Removing unreachable block (ram,0xf000573c) */
/* WARNING: Removing unreachable block (ram,0xf00057f0) */
/* WARNING: Removing unreachable block (ram,0xf000584c) */
/* WARNING: Removing unreachable block (ram,0xf0005868) */
/* WARNING: Removing unreachable block (ram,0xf00058e8) */
/* WARNING: Removing unreachable block (ram,0xf0005944) */
/* WARNING: Removing unreachable block (ram,0xf0005960) */
/* WARNING: Removing unreachable block (ram,0xf0005650) */
/* WARNING: Removing unreachable block (ram,0xf00056ac) */
/* WARNING: Removing unreachable block (ram,0xf00056c8) */
/* WARNING: Removing unreachable block (ram,0xf0005ac8) */

undefined8 __udivmoddi4(uint param_1,uint param_2,uint param_3,uint param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined8 *puVar4;
  undefined8 in_o4_5;
  undefined4 unaff_l0;
  uint uVar5;
  undefined4 unaff_l1;
  uint uVar6;
  undefined4 unaff_l3;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  int iVar10;
  uint uVar11;
  undefined8 in_i0_1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  byte bVar12;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  puVar4 = (undefined8 *)((qword)in_o4_5 >> 0x20);
  if (!in_DECOMPILE_MODE) {
    *(int *)(in_CWP * 0x40 + 0x8000) = (int)((qword)in_i0_1 >> 0x20);
    *(int *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = (int)in_i0_1;
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
  if (param_3 == 0) {
    if (param_1 < param_4) {
      if (param_4 < 0x10000) {
        uVar3 = (param_4 < 0x100) - 1 & 8;
      }
      else {
        uVar3 = 0x18;
        if (param_4 < 0x1000000) {
          uVar3 = 0x10;
        }
      }
      iVar10 = 0x20 - ((byte)unk_F00F4A98[param_4 >> (sbyte)uVar3] + uVar3);
      if (iVar10 != 0) {
        param_4 = param_4 << ((byte)iVar10 & 0x1f);
        param_2 = param_2 << ((byte)iVar10 & 0x1f);
      }
      iVar2 = 0;
      uVar7 = param_4 >> 0x10;
      .urem(0,uVar7);
      uVar3 = 0;
      .udiv(0,uVar7);
      .umul();
      uVar5 = iVar2 << 0x10 | param_2 >> 0x10;
      if (uVar5 < uVar3) {
        uVar5 = uVar5 + param_4;
        if (param_4 <= uVar5) {
          if (uVar3 <= uVar5) {
            uVar5 = uVar5 - uVar3;
            goto loc_F00056A8;
          }
          uVar5 = uVar5 + param_4;
        }
        uVar5 = uVar5 - uVar3;
      }
      else {
        uVar5 = uVar5 - uVar3;
      }
loc_F00056A8:
      uVar3 = uVar5;
      .urem(uVar5,uVar7);
      .udiv(uVar5,uVar7);
      .umul();
      uVar7 = uVar3 << 0x10 | param_2 & 0xffff;
      if (((uVar7 < uVar5) && (uVar7 = uVar7 + param_4, param_4 <= uVar7)) && (uVar7 < uVar5)) {
        uVar7 = uVar7 + param_4;
      }
      uVar7 = uVar7 - uVar5;
      uVar3 = 0;
    }
    else {
      if (param_4 == 0) {
        param_4 = 1;
        .udiv(1,0);
      }
      if (param_4 < 0x10000) {
        uVar3 = (param_4 < 0x100) - 1 & 8;
      }
      else {
        uVar3 = 0x18;
        if (param_4 < 0x1000000) {
          uVar3 = 0x10;
        }
      }
      iVar10 = 0x20 - ((byte)unk_F00F4A98[param_4 >> (sbyte)uVar3] + uVar3);
      bVar1 = (byte)iVar10;
      if (iVar10 == 0) {
        uVar5 = -param_4;
        uVar3 = 1;
      }
      else {
        param_4 = param_4 << (bVar1 & 0x1f);
        uVar7 = 0 >> (0x20 - bVar1 & 0x1f);
        uVar11 = 0 << (bVar1 & 0x1f) | param_2 >> (0x20 - bVar1 & 0x1f);
        param_2 = param_2 << (bVar1 & 0x1f);
        uVar8 = param_4 >> 0x10;
        uVar3 = uVar7;
        .urem(uVar7,uVar8);
        .udiv(uVar7,uVar8);
        uVar5 = uVar7;
        .umul();
        uVar9 = uVar3 << 0x10 | uVar11 >> 0x10;
        if (uVar9 < uVar5) {
          uVar9 = uVar9 + param_4;
          uVar6 = uVar7 - 1;
          if (param_4 <= uVar9) {
            if (uVar5 <= uVar9) {
              uVar9 = uVar9 - uVar5;
              goto loc_F0005848;
            }
            uVar6 = uVar7 - 2;
            uVar9 = uVar9 + param_4;
          }
          uVar9 = uVar9 - uVar5;
        }
        else {
          uVar9 = uVar9 - uVar5;
          uVar6 = uVar7;
        }
loc_F0005848:
        uVar3 = uVar9;
        .urem(uVar9,uVar8);
        .udiv(uVar9,uVar8);
        uVar7 = uVar9;
        .umul();
        uVar5 = uVar3 << 0x10 | uVar11 & 0xffff;
        uVar3 = uVar9;
        if (uVar5 < uVar7) {
          uVar5 = uVar5 + param_4;
          uVar3 = uVar9 - 1;
          if ((param_4 <= uVar5) && (uVar5 < uVar7)) {
            uVar5 = uVar5 + param_4;
            uVar3 = uVar9 - 2;
          }
        }
        uVar3 = uVar6 << 0x10 | uVar3;
        uVar5 = uVar5 - uVar7;
      }
      uVar9 = param_4 >> 0x10;
      uVar7 = uVar5;
      .urem(uVar5,uVar9);
      .udiv(uVar7,uVar9);
      .umul();
      uVar5 = uVar5 << 0x10 | param_2 >> 0x10;
      if (uVar5 < uVar7) {
        uVar5 = uVar5 + param_4;
        if (param_4 <= uVar5) {
          if (uVar7 <= uVar5) {
            uVar5 = uVar5 - uVar7;
            goto loc_F0005940;
          }
          uVar5 = uVar5 + param_4;
        }
        uVar5 = uVar5 - uVar7;
      }
      else {
        uVar5 = uVar5 - uVar7;
      }
loc_F0005940:
      uVar7 = uVar5;
      .urem(uVar5,uVar9);
      .udiv(uVar5,uVar9);
      .umul();
      uVar7 = uVar7 << 0x10 | param_2 & 0xffff;
      if (((uVar7 < uVar5) && (uVar7 = uVar7 + param_4, param_4 <= uVar7)) && (uVar7 < uVar5)) {
        uVar7 = uVar7 + param_4;
      }
      uVar7 = uVar7 - uVar5;
    }
    if (puVar4 == (undefined8 *)0x0) goto loc_F0005CA4;
    *(uint *)((int)register0x00000038 + -0x14) = uVar7 >> ((byte)iVar10 & 0x1f);
    *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
  }
  else {
    if (param_1 < param_3) {
      uVar3 = 0;
      if (puVar4 == (undefined8 *)0x0) goto loc_F0005CA4;
      *(uint *)((int)register0x00000038 + -0x14) = param_2;
    }
    else {
      if (param_3 < 0x10000) {
        uVar3 = (param_3 < 0x100) - 1 & 8;
      }
      else {
        uVar3 = 0x18;
        if (param_3 < 0x1000000) {
          uVar3 = 0x10;
        }
      }
      iVar10 = 0x20 - ((byte)unk_F00F4A98[param_3 >> (sbyte)uVar3] + uVar3);
      bVar1 = (byte)iVar10;
      bVar12 = 0x20 - bVar1;
      if (iVar10 == 0) {
        if ((param_3 < param_1) || (uVar5 = param_2, param_4 <= param_2)) {
          uVar5 = param_2 - param_4;
          param_1 = (param_1 - param_3) - (uint)(param_2 < uVar5);
        }
        uVar3 = 0;
        if (puVar4 == (undefined8 *)0x0) goto loc_F0005CA4;
        *(uint *)((int)register0x00000038 + -0x14) = uVar5;
      }
      else {
        uVar11 = param_3 << (bVar1 & 0x1f) | param_4 >> (bVar12 & 0x1f);
        param_4 = param_4 << (bVar1 & 0x1f);
        uVar7 = param_1 >> (bVar12 & 0x1f);
        uVar8 = param_1 << (bVar1 & 0x1f) | param_2 >> (bVar12 & 0x1f);
        param_2 = param_2 << (bVar1 & 0x1f);
        uVar9 = uVar11 >> 0x10;
        uVar3 = uVar7;
        .urem(uVar7,uVar9);
        .udiv(uVar7,uVar9);
        uVar5 = uVar7;
        .umul();
        uVar3 = uVar3 << 0x10 | uVar8 >> 0x10;
        if (uVar3 < uVar5) {
          uVar3 = uVar3 + uVar11;
          uVar6 = uVar7 - 1;
          if (uVar11 <= uVar3) {
            if (uVar5 <= uVar3) {
              uVar3 = uVar3 - uVar5;
              goto loc_F0005B30;
            }
            uVar6 = uVar7 - 2;
            uVar3 = uVar3 + uVar11;
          }
          uVar3 = uVar3 - uVar5;
        }
        else {
          uVar3 = uVar3 - uVar5;
          uVar6 = uVar7;
        }
loc_F0005B30:
        uVar5 = uVar3;
        .urem(uVar3,uVar9);
        .udiv(uVar3,uVar9);
        uVar7 = uVar3;
        .umul();
        uVar9 = uVar5 << 0x10 | uVar8 & 0xffff;
        uVar5 = uVar3;
        if (uVar9 < uVar7) {
          uVar9 = uVar9 + uVar11;
          uVar5 = uVar3 - 1;
          if ((uVar11 <= uVar9) && (uVar9 < uVar7)) {
            uVar9 = uVar9 + uVar11;
            uVar5 = uVar3 - 2;
          }
        }
        uVar8 = uVar6 << 0x10 | uVar5;
        uVar9 = uVar9 - uVar7;
        uVar5 = uVar5 & 0xffff;
        uVar3 = uVar5;
        .umul(uVar5,param_4 & 0xffff);
        .umul(uVar5,param_4 >> 0x10);
        uVar8 = uVar8 >> 0x10;
        uVar7 = uVar8;
        .umul(uVar8,param_4 & 0xffff);
        .umul(uVar8,param_4 >> 0x10);
        uVar5 = uVar5 + (uVar3 >> 0x10) + uVar7;
        if (uVar5 < uVar7) {
          uVar8 = uVar8 + 0x10000;
        }
        uVar8 = uVar8 + (uVar5 >> 0x10);
        uVar3 = uVar5 * 0x10000 + (uVar3 & 0xffff);
        if ((uVar9 < uVar8) || ((uVar5 = uVar3, uVar8 == uVar9 && (param_2 < uVar3)))) {
          uVar5 = uVar3 - param_4;
          uVar8 = (uVar8 - uVar11) - (uint)(uVar3 < uVar5);
        }
        uVar3 = 0;
        if (puVar4 == (undefined8 *)0x0) goto loc_F0005CA4;
        param_1 = (uVar9 - uVar8) - (uint)(param_2 < param_2 - uVar5);
        *(uint *)((int)register0x00000038 + -0x14) =
             param_1 << (bVar12 & 0x1f) | param_2 - uVar5 >> (bVar1 & 0x1f);
        param_1 = param_1 >> (bVar1 & 0x1f);
      }
    }
    uVar3 = 0;
    *(uint *)((int)register0x00000038 + -0x18) = param_1;
  }
  *puVar4 = *(undefined8 *)((int)register0x00000038 + -0x18);
loc_F0005CA4:
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  *(uint *)((int)register0x00000038 + -0x10) = uVar3;
  return CONCAT44((int)*(undefined8 *)((int)register0x00000038 + -0x10),
                  (int)((qword)*(undefined8 *)((int)register0x00000038 + -0x10) >> 0x20));
}
