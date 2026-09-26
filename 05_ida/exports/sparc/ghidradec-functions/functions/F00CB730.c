
/* WARNING: Removing unreachable block (ram,0xf00cb760) */
/* WARNING: Removing unreachable block (ram,0xf00cb7e4) */
/* WARNING: Removing unreachable block (ram,0xf00cb758) */

undefined8 -[IOEthernet setRelativeTimeout:](int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined8 in_o2_3;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
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
  
  uVar1 = (uint)((qword)in_o2_3 >> 0x20);
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
  if ((*(int *)(param_1 + 0x130) != 0) || (*(int *)(param_1 + 0x134) != 0)) {
    _ns_untimeout(sub_F00CB194,param_1);
  }
  _IOGetTimestamp(param_1 + 0x130);
  iVar3 = (uVar1 >> 0x1b) - (uint)(uVar1 * 0x20 < uVar1);
  uVar2 = (uint)*(undefined8 *)(param_1 + 0x130);
  *(qword *)(param_1 + 0x130) =
       CONCAT44((int)((qword)*(undefined8 *)(param_1 + 0x130) >> 0x20) +
                (uVar1 * 0x3d09 >> 0x1a |
                ((uVar1 * 0x7a1 >> 0x1d |
                 (((uVar1 * 0x1f >> 0x1a | iVar3 * 0x40) - iVar3) -
                 (uint)(uVar1 * 0x7c0 < uVar1 * 0x1f)) * 8) + (uint)CARRY4(uVar1 * 0x3d08,uVar1)) *
                0x40) + (uint)CARRY4(uVar2,uVar1 * 1000000),uVar2 + uVar1 * 1000000);
  _ns_abstimeout(sub_F00CB194);
  return CONCAT44(param_2,param_1);
}
