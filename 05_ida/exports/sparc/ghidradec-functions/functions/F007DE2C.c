
/* WARNING: Removing unreachable block (ram,0xf007deac) */
/* WARNING: Removing unreachable block (ram,0xf007dea0) */
/* WARNING: Removing unreachable block (ram,0xf007df10) */
/* WARNING: Removing unreachable block (ram,0xf007de88) */

undefined8 sub_F007DE2C(int *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
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
  if ((((param_1[1] != 0x28) || (*param_1 < 0)) || (param_1[6] != dword_F0111280)) ||
     (param_1[8] != dword_F0111284)) {
    param_2[7] = 0xfffffed0;
    goto locret_F007DF60;
  }
  uVar1 = param_1[2];
  _convert_port_to_space();
  uVar3 = uVar1;
  _mach_port_extract_right();
  param_2[7] = uVar3;
  _space_deallocate(uVar1);
  if (param_2[7] != 0) goto locret_F007DF60;
  param_2[1] = 0x28;
  iVar2 = *(int *)((int)register0x00000038 + -0xc);
  param_2[8] = dword_F0111288;
  if ((iVar2 == 0x10) && (param_1[3] != 0)) {
    if (param_1[3] != -1) {
      uVar3 = param_2[9];
      if (uVar3 != 0) {
        if (uVar3 == 0xffffffff) {
          iVar2 = *(int *)((int)register0x00000038 + -0xc);
          goto loc_F007DF34;
        }
        _ipc_port_check_circularity();
        if (uVar3 != 0) {
          *param_2 = *param_2 | 0x40000000;
        }
      }
      goto loc_F007DF30;
    }
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
  }
  else {
loc_F007DF30:
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
  }
loc_F007DF34:
  *(char *)(param_2 + 8) = (char)iVar2;
  if (iVar2 - 0x10U < 6) {
    *param_2 = *param_2 | 0x80000000;
  }
locret_F007DF60:
  return CONCAT44(param_2,param_1);
}
