
/* WARNING: Removing unreachable block (ram,0xf00552dc) */
/* WARNING: Removing unreachable block (ram,0xf005529c) */
/* WARNING: Removing unreachable block (ram,0xf00552fc) */
/* WARNING: Removing unreachable block (ram,0xf0055320) */
/* WARNING: Removing unreachable block (ram,0xf00552bc) */

undefined8 _ipc_kmsg_get(int param_1,uint param_2,int param_3,int *param_4)

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
  undefined4 uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar1 = _ipc_kmsg_cache;
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
  if (((param_2 < 0x18) || ((param_2 & 3) != 0)) || (0 < param_3)) {
    uVar2 = 0x10000008;
    goto locret_F0055340;
  }
  if (param_2 < 0xed) {
    if (_ipc_kmsg_cache == 0) {
      iVar1 = 0x100;
      _kalloc();
      if (iVar1 == 0) goto loc_F00552D0;
      *(undefined4 *)(iVar1 + 8) = 0x100;
      goto loc_F00552EC;
    }
    _ipc_kmsg_cache = 0;
  }
  else {
    iVar1 = param_2 + 0x14;
    _kalloc();
    if (iVar1 == 0) {
loc_F00552D0:
      uVar2 = 0x1000000d;
      goto locret_F0055340;
    }
    *(uint *)(iVar1 + 8) = param_2 + 0x14;
loc_F00552EC:
    *(undefined4 *)(iVar1 + 0xc) = 0;
  }
  *(undefined4 *)(iVar1 + 0x10) = 0;
  _copyinmsg(param_1,iVar1 + 0x14,param_2 + param_3);
  if (param_1 == 0) {
    *(int *)(iVar1 + 0x10) = param_3;
    *(uint *)(iVar1 + 0x18) = param_2;
    *param_4 = iVar1;
    uVar2 = 0;
  }
  else {
    if (*(int *)(iVar1 + 8) < 1) {
      _ipc_kmsg_free(iVar1);
    }
    else {
      _kfree(iVar1);
    }
    uVar2 = 0x10000002;
  }
locret_F0055340:
  return CONCAT44(param_2,uVar2);
}

