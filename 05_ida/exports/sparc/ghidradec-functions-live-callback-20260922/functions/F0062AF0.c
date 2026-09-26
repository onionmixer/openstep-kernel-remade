
/* WARNING: Removing unreachable block (ram,0xf0062b78) */
/* WARNING: Removing unreachable block (ram,0xf0062bec) */
/* WARNING: Removing unreachable block (ram,0xf0062bd4) */
/* WARNING: Removing unreachable block (ram,0xf0062b5c) */
/* WARNING: Removing unreachable block (ram,0xf0062b98) */
/* WARNING: Removing unreachable block (ram,0xf0062bb4) */

undefined8
_mach_port_request_notification
          (int param_1,undefined4 param_2,int param_3,int param_4,int param_5,uint *param_6)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
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
  if (param_1 == 0) {
    iVar3 = 0x10;
    goto locret_F0062C04;
  }
  if (param_5 == -1) {
    iVar3 = 0x14;
    goto locret_F0062C04;
  }
  if (param_3 == 0x46) {
    _ipc_object_translate(param_1,param_2,1,(undefined *)((int)register0x00000038 + -0x14));
    iVar3 = param_1;
    if (param_1 == 0) {
      _ipc_port_nsrequest(*(undefined4 *)((int)register0x00000038 + -0x14),param_4,param_5,param_6);
      iVar3 = 0;
    }
    goto locret_F0062C04;
  }
  if (param_3 < 0x47) {
    if (param_3 != 0x45) {
      iVar3 = 0x12;
      goto locret_F0062C04;
    }
    iVar3 = 0x12;
    if ((param_4 != 0) ||
       (_ipc_object_translate(param_1,param_2,1,(undefined *)((int)register0x00000038 + -0xc)),
       iVar3 = param_1, param_1 != 0)) goto locret_F0062C04;
    _ipc_port_pdrequest(*(undefined4 *)((int)register0x00000038 + -0xc),param_5,
                        (undefined *)((int)register0x00000038 + -0x10));
    uVar1 = *(uint *)((int)register0x00000038 + -0x10);
    uVar2 = 0;
    if (uVar1 != 0) {
      if ((uVar1 & 1) == 0) {
        *param_6 = uVar1;
        goto loc_F0062C00;
      }
      _ipc_port_release_send(uVar1 & 0xfffffffe);
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
      uVar2 = *(uint *)((int)register0x00000038 + -0x10);
    }
    *param_6 = uVar2;
  }
  else {
    if (param_3 != 0x48) {
      iVar3 = 0x12;
      goto locret_F0062C04;
    }
    _ipc_right_dnrequest(param_1,param_2,param_4 != 0,param_5,param_6);
    iVar3 = param_1;
    if (param_1 != 0) goto locret_F0062C04;
  }
loc_F0062C00:
  iVar3 = 0;
locret_F0062C04:
  return CONCAT44(param_2,iVar3);
}

