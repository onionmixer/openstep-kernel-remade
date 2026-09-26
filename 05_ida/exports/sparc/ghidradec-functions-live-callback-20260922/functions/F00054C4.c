
/* WARNING: Removing unreachable block (ram,0xf0005570) */
/* WARNING: Removing unreachable block (ram,0xf0005514) */
/* WARNING: Removing unreachable block (ram,0xf0005500) */
/* WARNING: Removing unreachable block (ram,0xf0005524) */
/* WARNING: Removing unreachable block (ram,0xf0005580) */
/* WARNING: Removing unreachable block (ram,0xf00054ec) */

undefined8 __muldi3(int param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_l1;
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
  uVar3 = param_2 & 0xffff;
  uVar1 = uVar3;
  umul(uVar3,param_4 & 0xffff);
  umul(uVar3,param_4 >> 0x10);
  uVar4 = param_2 >> 0x10;
  uVar2 = uVar4;
  umul(uVar4,param_4 & 0xffff);
  umul(uVar4,param_4 >> 0x10);
  uVar3 = uVar3 + (uVar1 >> 0x10) + uVar2;
  if (uVar3 < uVar2) {
    uVar4 = uVar4 + 0x10000;
  }
  umul(param_2,param_3);
  umul(param_1,param_4);
  return CONCAT44(uVar3 * 0x10000 + (uVar1 & 0xffff),uVar4 + (uVar3 >> 0x10) + param_2 + param_1);
}

