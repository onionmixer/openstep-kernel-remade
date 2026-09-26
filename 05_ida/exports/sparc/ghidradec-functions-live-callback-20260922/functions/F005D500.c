
/* WARNING: Removing unreachable block (ram,0xf005d640) */
/* WARNING: Removing unreachable block (ram,0xf005d678) */
/* WARNING: Removing unreachable block (ram,0xf005d668) */
/* WARNING: Removing unreachable block (ram,0xf005d5f8) */

undefined8
_ipc_right_copyout(undefined4 param_1,int param_2,uint *param_3,uint param_4,int param_5,
                  undefined4 *param_6)

{
  undefined4 unaff_l0;
  uint uVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 unaff_i1;
  int iVar3;
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
  uVar1 = *param_3;
  if (param_4 == 0x11) {
    if ((uVar1 & 0x10000) == 0) {
      if ((uVar1 & 0x20000) != 0) goto loc_F005D5D4;
      *param_6 = 0;
      _ipc_hash_insert(param_1,param_6,param_2,param_3);
    }
    else {
      if ((uVar1 & 0xffff) == 0xfffe) {
        if (param_5 == 0) {
          *param_6 = 0;
          uVar2 = 0x13;
        }
        else {
          param_6[7] = param_6[7] + -1;
          param_6[1] = param_6[1] + -1;
          *param_6 = 0;
          uVar2 = 0;
        }
        goto locret_F005D684;
      }
      param_6[7] = param_6[7] + -1;
loc_F005D5D4:
      param_6[1] = param_6[1] + -1;
      *param_6 = 0;
    }
    *param_3 = (uVar1 | 0x10000) + 1;
  }
  else if (param_4 < 0x12) {
    if (param_4 == 0x10) {
      param_6[4] = param_2;
      iVar3 = param_6[3];
      param_6[3] = param_1;
      if ((uVar1 & 0x10000) == 0) {
        *param_6 = 0;
      }
      else {
        param_6[1] = param_6[1] + -1;
        *param_6 = 0;
        _ipc_hash_delete(param_1,param_6,param_2,param_3);
      }
      *param_3 = uVar1 | 0x20000;
      param_2 = iVar3;
      if (iVar3 != 0) {
        _ipc_object_release(iVar3);
        uVar2 = 0;
        goto locret_F005D684;
      }
    }
    else {
loc_F005D678:
      _panic(aIpcRightCopyou);
    }
  }
  else {
    if (param_4 != 0x12) goto loc_F005D678;
    *param_6 = 0;
    *param_3 = uVar1 | 0x40001;
  }
  uVar2 = 0;
locret_F005D684:
  return CONCAT44(param_2,uVar2);
}

