
/* WARNING: Removing unreachable block (ram,0xf00ac464) */
/* WARNING: Removing unreachable block (ram,0xf00ac4c0) */
/* WARNING: Removing unreachable block (ram,0xf00ac7a4) */
/* WARNING: Removing unreachable block (ram,0xf00ac77c) */
/* WARNING: Removing unreachable block (ram,0xf00ac51c) */
/* WARNING: Removing unreachable block (ram,0xf00ac588) */
/* WARNING: Removing unreachable block (ram,0xf00ac558) */
/* WARNING: Removing unreachable block (ram,0xf00ac5c4) */
/* WARNING: Removing unreachable block (ram,0xf00ac698) */
/* WARNING: Removing unreachable block (ram,0xf00ac668) */
/* WARNING: Removing unreachable block (ram,0xf00ac6d4) */
/* WARNING: Removing unreachable block (ram,0xf00ac71c) */
/* WARNING: Removing unreachable block (ram,0xf00ac644) */
/* WARNING: Removing unreachable block (ram,0xf00ac618) */
/* WARNING: Removing unreachable block (ram,0xf00ac81c) */
/* WARNING: Removing unreachable block (ram,0xf00ac854) */
/* WARNING: Removing unreachable block (ram,0xf00ac88c) */
/* WARNING: Removing unreachable block (ram,0xf00ac7e4) */
/* WARNING: Removing unreachable block (ram,0xf00ac878) */
/* WARNING: Removing unreachable block (ram,0xf00ac840) */
/* WARNING: Removing unreachable block (ram,0xf00ac808) */
/* WARNING: Removing unreachable block (ram,0xf00ac600) */
/* WARNING: Removing unreachable block (ram,0xf00ac630) */
/* WARNING: Removing unreachable block (ram,0xf00ac704) */
/* WARNING: Removing unreachable block (ram,0xf00ac6bc) */
/* WARNING: Removing unreachable block (ram,0xf00ac734) */
/* WARNING: Removing unreachable block (ram,0xf00ac680) */
/* WARNING: Removing unreachable block (ram,0xf00ac5ac) */
/* WARNING: Removing unreachable block (ram,0xf00ac5dc) */
/* WARNING: Removing unreachable block (ram,0xf00ac570) */
/* WARNING: Removing unreachable block (ram,0xf00ac504) */
/* WARNING: Removing unreachable block (ram,0xf00ac534) */
/* WARNING: Removing unreachable block (ram,0xf00ac790) */
/* WARNING: Removing unreachable block (ram,0xf00ac490) */
/* WARNING: Removing unreachable block (ram,0xf00ac4e0) */
/* WARNING: Removing unreachable block (ram,0xf00ac474) */
/* WARNING: Removing unreachable block (ram,0xf00ac7c8) */

qword sub_F00AC318(uint *param_1,uint *param_2,uint *param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 unaff_l3;
  uint uVar5;
  undefined4 unaff_l4;
  uint uVar6;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
  undefined4 unaff_i1;
  uint uVar8;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  uVar3 = *param_2;
  uVar6 = *param_3;
  uVar2 = uVar3 >> 0xe & 0x1f;
  uVar5 = uVar3 >> 0x19 & 0x1f;
  param_1[3] = 0;
  *param_1 = uVar6 >> 0x17 & 0x1f;
  param_1[1] = uVar6 >> 0x1e;
  param_1[2] = uVar6 >> 0x1c & 3;
  uVar8 = uVar3 & 0x1f;
  switch(uVar3 >> 7 & 0x3f) {
  case :
    __fp_unpack_word(param_1,(undefined *)((int)register0x00000038 + -0x84),uVar8);
    __fp_pack_word(param_1,(undefined *)((int)register0x00000038 + -0x84),uVar5);
    uVar2 = param_1[3];
    break;
  case :
    __fp_unpack_word(param_1,(undefined *)((int)register0x00000038 + -0x84),uVar8);
    uVar2 = *(uint *)((int)register0x00000038 + -0x84) ^ 0x80000000;
    goto loc_F00AC4E0;
  case :
    __fp_unpack_word(param_1,(undefined *)((int)register0x00000038 + -0x84),uVar8);
    uVar2 = *(uint *)((int)register0x00000038 + -0x84) & 0x7fffffff;
loc_F00AC4E0:
    *(uint *)((int)register0x00000038 + -0x84) = uVar2;
    __fp_pack_word(param_1,(uint *)((int)register0x00000038 + -0x84),uVar5);
    uVar2 = param_1[3];
    break;
  :
    uVar7 = 3;
    goto locret_F00AC960;
  case :
    uVar4 = uVar3 >> 5 & 3;
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar8,uVar4);
    __fp_sqrt(param_1,(undefined *)((int)register0x00000038 + -0x30),
              (undefined *)((int)register0x00000038 + -0x80));
    goto loc_F00AC79C;
  case :
    uVar4 = uVar3 >> 5 & 3;
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar2,uVar4);
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x58),uVar8,uVar4);
    __fp_add(param_1,(undefined *)((int)register0x00000038 + -0x30),
             (undefined *)((int)register0x00000038 + -0x58),
             (undefined *)((int)register0x00000038 + -0x80));
    goto loc_F00AC79C;
  case :
    uVar4 = uVar3 >> 5 & 3;
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar2,uVar4);
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x58),uVar8,uVar4);
    __fp_sub(param_1,(undefined *)((int)register0x00000038 + -0x30),
             (undefined *)((int)register0x00000038 + -0x58),
             (undefined *)((int)register0x00000038 + -0x80));
    goto loc_F00AC79C;
  case :
    uVar4 = uVar3 >> 5 & 3;
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar2,uVar4);
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x58),uVar8,uVar4);
    __fp_mul(param_1,(undefined *)((int)register0x00000038 + -0x30),
             (undefined *)((int)register0x00000038 + -0x58),
             (undefined *)((int)register0x00000038 + -0x80));
    goto loc_F00AC79C;
  case :
    uVar4 = uVar3 >> 5 & 3;
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar2,uVar4);
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x58),uVar8,uVar4);
    __fp_div(param_1,(undefined *)((int)register0x00000038 + -0x30),
             (undefined *)((int)register0x00000038 + -0x58),
             (undefined *)((int)register0x00000038 + -0x80));
loc_F00AC79C:
    __fp_pack(param_1,(undefined *)((int)register0x00000038 + -0x80),uVar5,uVar4);
    uVar2 = param_1[3];
    break;
  case :
    uVar5 = uVar3 >> 5 & 3;
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar2,uVar5);
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x58),uVar8,uVar5);
    uVar7 = 0;
    goto loc_F00AC734;
  case :
    uVar5 = uVar3 >> 5 & 3;
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar2,uVar5);
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x58),uVar8,uVar5);
    uVar7 = 1;
loc_F00AC734:
    puVar1 = param_1;
    __fp_compare(param_1,(undefined *)((int)register0x00000038 + -0x30),
                 (undefined *)((int)register0x00000038 + -0x58),uVar7);
    if ((param_1[3] & *param_1) == 0) {
      uVar6 = uVar6 & 0xfffff3ff | ((uint)puVar1 & 3) << 10;
      uVar2 = param_1[3];
    }
    else {
      uVar2 = param_1[3];
    }
    break;
  case :
  case :
    uVar4 = uVar3 >> 5 & 3;
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar2,uVar4);
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x58),uVar8,uVar4);
    __fp_mul(param_1,(undefined *)((int)register0x00000038 + -0x30),
             (undefined *)((int)register0x00000038 + -0x58),
             (undefined *)((int)register0x00000038 + -0x80));
    __fp_pack(param_1,(undefined *)((int)register0x00000038 + -0x80),uVar5,uVar4 + 1);
    uVar2 = param_1[3];
    break;
  case :
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar8,uVar3 >> 5 & 3);
    __fp_pack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar5,1);
    uVar2 = param_1[3];
    break;
  case :
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar8,uVar3 >> 5 & 3);
    __fp_pack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar5,2);
    uVar2 = param_1[3];
    break;
  case :
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar8,uVar3 >> 5 & 3);
    __fp_pack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar5,3);
    uVar2 = param_1[3];
    break;
  case :
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar8,uVar3 >> 5 & 3);
    param_1[1] = 1;
    __fp_pack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar5,0);
    uVar2 = param_1[3];
  }
  uVar5 = uVar6 & 0xffffffe0 | uVar2 & 0x1f;
  if (uVar2 != 0) {
    uVar8 = uVar2 & uVar6 >> 0x17 & 0x1f;
    if (uVar8 != 0) {
      if ((uVar8 & 0x10) == 0) {
        if ((uVar8 & 8) == 0) {
          if ((uVar8 & 4) == 0) {
            if ((uVar8 & 2) == 0) {
              if ((uVar8 & 1) == 0) {
                param_1[7] = 0;
              }
              else {
                param_1[7] = 0x607;
              }
            }
            else {
              param_1[7] = 0x608;
            }
          }
          else {
            param_1[7] = 0x609;
          }
        }
        else {
          param_1[7] = 0x60b;
        }
      }
      else {
        param_1[7] = 0x60a;
      }
      *param_3 = uVar5;
      uVar7 = 1;
      goto locret_F00AC960;
    }
    uVar5 = uVar6 & 0xfffffc00 | uVar2 & 0x1f | ((uVar2 | uVar6 >> 5) & 0x1f) << 5;
  }
  *param_3 = uVar5;
  uVar7 = 0;
locret_F00AC960:
  return CONCAT44(uVar3,uVar7) & 0x1fffffffff;
}

