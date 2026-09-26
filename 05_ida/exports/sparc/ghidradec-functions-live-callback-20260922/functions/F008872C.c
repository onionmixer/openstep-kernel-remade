
/* WARNING: Removing unreachable block (ram,0xf008876c) */
/* WARNING: Removing unreachable block (ram,0xf00887d0) */
/* WARNING: Removing unreachable block (ram,0xf0088730) */

undefined8 sub_F008872C(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  iVar3 = *(int *)(param_1 + 0x10);
  if (iVar3 != param_1 + 0xc) {
    uVar1 = *(uint *)(iVar3 + 0x18);
    while( true ) {
      if ((uVar1 & 0xa0000000) == 0) {
        if (param_3 < *(uint *)(iVar3 + 8)) {
          iVar3 = *(int *)(iVar3 + 4);
        }
        else if (param_2 < *(uint *)(iVar3 + 0xc)) {
          iVar2 = *(int *)(iVar3 + 0x10);
          if (iVar2 == 0) {
            iVar3 = *(int *)(iVar3 + 4);
          }
          else {
            *(sword *)(iVar2 + 0x48) = (sword)param_4;
            while (iVar2 = *(int *)(iVar2 + 0x20), iVar2 != 0) {
              *(sword *)(iVar2 + 0x48) = (sword)param_4;
            }
            iVar3 = *(int *)(iVar3 + 4);
          }
        }
        else {
          iVar3 = *(int *)(iVar3 + 4);
        }
      }
      else {
        sub_F008872C(*(undefined4 *)(iVar3 + 0x10),param_2,param_3,param_4);
        iVar3 = *(int *)(iVar3 + 4);
      }
      if (iVar3 == param_1 + 0xc) break;
      uVar1 = *(uint *)(iVar3 + 0x18);
    }
  }
  _lock_done(param_1);
  return CONCAT44(param_2,param_1);
}

