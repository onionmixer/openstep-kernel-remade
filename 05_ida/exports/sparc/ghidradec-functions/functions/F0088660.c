
/* WARNING: Removing unreachable block (ram,0xf00886a0) */
/* WARNING: Removing unreachable block (ram,0xf0088704) */
/* WARNING: Removing unreachable block (ram,0xf008871c) */
/* WARNING: Removing unreachable block (ram,0xf0088664) */

undefined8 sub_F0088660(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int iVar5;
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
  _lock_read(param_1);
  iVar5 = *(int *)(param_1 + 0x10);
  if (iVar5 != param_1 + 0xc) {
    uVar1 = *(uint *)(iVar5 + 0x18);
    while( true ) {
      if ((uVar1 & 0xa0000000) == 0) {
        uVar1 = *(uint *)(iVar5 + 8);
        if (param_3 < uVar1) {
          iVar5 = *(int *)(iVar5 + 4);
        }
        else {
          uVar2 = *(uint *)(iVar5 + 0xc);
          if (param_2 < uVar2) {
            if (param_2 < uVar1) {
              param_2 = uVar1;
            }
            uVar4 = param_3;
            if (uVar2 < param_3) {
              uVar4 = uVar2;
            }
            iVar3 = (*(int *)(iVar5 + 0x14) + param_2) - uVar1;
            sub_F008858C(*(undefined4 *)(iVar5 + 0x10),iVar3,(iVar3 + uVar4) - param_2,param_4);
            iVar5 = *(int *)(iVar5 + 4);
          }
          else {
            iVar5 = *(int *)(iVar5 + 4);
          }
        }
      }
      else {
        sub_F0088660(*(undefined4 *)(iVar5 + 0x10),param_2,param_3,param_4);
        iVar5 = *(int *)(iVar5 + 4);
      }
      if (iVar5 == param_1 + 0xc) break;
      uVar1 = *(uint *)(iVar5 + 0x18);
    }
  }
  _lock_done(param_1);
  return CONCAT44(param_2,param_1);
}
