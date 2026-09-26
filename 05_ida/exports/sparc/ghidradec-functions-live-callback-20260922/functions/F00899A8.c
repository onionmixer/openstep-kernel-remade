
/* WARNING: Removing unreachable block (ram,0xf00899ec) */
/* WARNING: Removing unreachable block (ram,0xf0089a58) */
/* WARNING: Removing unreachable block (ram,0xf0089a80) */
/* WARNING: Removing unreachable block (ram,0xf00899b4) */

undefined8 sub_F00899A8(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
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
  uVar7 = 0;
  _lock_read(param_1);
  iVar6 = *(int *)(param_1 + 0x10);
  if (iVar6 == param_1 + 0xc) {
loc_F0089A80:
    _lock_done(param_1);
    return CONCAT44(param_2,uVar7);
  }
  uVar1 = *(uint *)(iVar6 + 0x18);
  do {
    if ((uVar1 & 0xa0000000) == 0) {
      uVar1 = *(uint *)(iVar6 + 8);
      if (param_3 < uVar1) {
        iVar6 = *(int *)(iVar6 + 4);
      }
      else {
        uVar3 = *(uint *)(iVar6 + 0xc);
        if (param_2 < uVar3) {
          iVar2 = *(int *)(iVar6 + 0x10);
          if (param_2 < uVar1) {
            param_2 = uVar1;
          }
          uVar5 = param_3;
          if (uVar3 <= param_3) {
            uVar5 = uVar3;
          }
          iVar4 = (*(int *)(iVar6 + 0x14) + param_2) - uVar1;
          sub_F0089CA0(iVar2,iVar4,(iVar4 + uVar5) - param_2);
          if (iVar2 != 0) goto loc_F0089A70;
          iVar6 = *(int *)(iVar6 + 4);
        }
        else {
          iVar6 = *(int *)(iVar6 + 4);
        }
      }
    }
    else {
      iVar2 = *(int *)(iVar6 + 0x10);
      sub_F00899A8(iVar2,param_2,param_3);
      if (iVar2 == 5) {
loc_F0089A70:
        uVar7 = 5;
        iVar6 = *(int *)(iVar6 + 4);
      }
      else {
        iVar6 = *(int *)(iVar6 + 4);
      }
    }
    if (iVar6 == param_1 + 0xc) goto loc_F0089A80;
    uVar1 = *(uint *)(iVar6 + 0x18);
  } while( true );
}

