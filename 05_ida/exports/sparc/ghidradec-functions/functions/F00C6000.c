
/* WARNING: Removing unreachable block (ram,0xf00c60b4) */

undefined8 _IOScheduleFunc(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
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
  int iVar2;
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
  iVar2 = (int)param_3 >> 0x1f;
  iVar1 = ((param_3 * 0x7b1 >> 0x1d |
           ((param_3 * 0x7b >> 0x1c |
            (((param_3 * 0x1f >> 0x1e |
              (((param_3 >> 0x1b | iVar2 << 5) - iVar2) - (uint)(param_3 * 0x20 < param_3)) * 4) -
             iVar2) - (uint)(param_3 * 0x7c < param_3)) * 0x10) + iVar2 +
           (uint)CARRY4(param_3 * 0x7b0,param_3)) * 8) - iVar2) - (uint)(param_3 * 0x3d88 < param_3)
  ;
  _ns_timeout(param_1,param_2,
              param_3 * 0x1dcd65 >> 0x17 |
              ((param_3 * 0x77359 >> 0x1e |
               (((param_3 * 0x3d87 >> 0x1b | iVar1 * 0x20) - iVar1) -
               (uint)(param_3 * 0x7b0e0 < param_3 * 0x3d87)) * 4) + iVar2 +
              (uint)CARRY4(param_3 * 0x1dcd64,param_3)) * 0x200,param_3 * 1000000000,4);
  return CONCAT44(param_2,param_1);
}
