
/* WARNING: Removing unreachable block (ram,0xf004fb4c) */

undefined8 sub_F004F98C(int param_1,int param_2,uint param_3,int *param_4,int *param_5)

{
  uint uVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  uint uVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  *param_5 = param_1;
  if (param_1 == 0) {
    uVar4 = 0;
  }
  else {
    uVar3 = *(uint *)(param_2 + 4);
    uVar2 = *(uint *)(param_2 + 8);
    do {
      if (((param_3 & 1) == 0) || (*(int *)(param_1 + 0xc) == *(int *)(param_2 + 0xc))) {
        if ((param_3 & 2) == 0) {
          uVar1 = *(uint *)(param_1 + 8);
        }
        else {
          if (*(int *)(param_1 + 0xc) == *(int *)(param_2 + 0xc)) goto loc_F004FA4C;
          uVar1 = *(uint *)(param_1 + 8);
        }
        if ((uVar1 != 0xffffffff) && (uVar1 < uVar3)) {
loc_F004FA28:
          if ((((param_3 & 1) == 0) || (uVar2 == 0xffffffff)) || (*(uint *)(param_1 + 4) <= uVar2))
          goto loc_F004FA4C;
          uVar4 = 0;
          goto locret_F004FB64;
        }
        if (uVar2 == 0xffffffff) {
          uVar1 = *(uint *)(param_1 + 4);
        }
        else {
          if (uVar2 < *(uint *)(param_1 + 4)) goto loc_F004FA28;
          uVar1 = *(uint *)(param_1 + 4);
        }
        if ((uVar1 == uVar3) && (*(uint *)(param_1 + 8) == uVar2)) {
          uVar4 = 1;
          goto locret_F004FB64;
        }
        if (uVar3 < uVar1) {
          uVar1 = *(uint *)(param_1 + 4);
        }
        else if (uVar2 == 0xffffffff) {
          uVar1 = *(uint *)(param_1 + 4);
        }
        else {
          if ((uVar2 <= *(uint *)(param_1 + 8)) || (*(uint *)(param_1 + 8) == 0xffffffff)) {
            uVar4 = 2;
            goto locret_F004FB64;
          }
          uVar1 = *(uint *)(param_1 + 4);
        }
        if (uVar1 < uVar3) {
loc_F004FAE4:
          uVar1 = *(uint *)(param_1 + 4);
        }
        else {
          if (uVar2 == 0xffffffff) {
            uVar4 = 3;
            goto locret_F004FB64;
          }
          if (*(uint *)(param_1 + 8) == 0xffffffff) goto loc_F004FAE4;
          if (*(uint *)(param_1 + 8) <= uVar2) {
            uVar4 = 3;
            goto locret_F004FB64;
          }
          uVar1 = *(uint *)(param_1 + 4);
        }
        if (uVar1 < uVar3) {
          if ((uVar3 <= *(uint *)(param_1 + 8)) || (*(uint *)(param_1 + 8) == 0xffffffff)) {
            uVar4 = 4;
            goto locret_F004FB64;
          }
          uVar1 = *(uint *)(param_1 + 4);
        }
        else {
          uVar1 = *(uint *)(param_1 + 4);
        }
        if (((uVar3 < uVar1) && (uVar2 != 0xffffffff)) &&
           ((uVar2 < *(uint *)(param_1 + 8) || (*(uint *)(param_1 + 8) == 0xffffffff)))) {
          uVar4 = 5;
          goto locret_F004FB64;
        }
        _panic(aLfFindoverlapD);
      }
      else {
loc_F004FA4C:
        *param_4 = param_1 + 0x14;
        param_1 = *(int *)(param_1 + 0x14);
        *param_5 = param_1;
      }
    } while (param_1 != 0);
    uVar4 = 0;
  }
locret_F004FB64:
  return CONCAT44(param_2,uVar4);
}

