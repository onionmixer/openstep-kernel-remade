
/* WARNING: Removing unreachable block (ram,0xf00551f0) */
/* WARNING: Removing unreachable block (ram,0xf005513c) */
/* WARNING: Removing unreachable block (ram,0xf00550dc) */
/* WARNING: Removing unreachable block (ram,0xf00550e8) */
/* WARNING: Removing unreachable block (ram,0xf00551a4) */
/* WARNING: Removing unreachable block (ram,0xf00551dc) */
/* WARNING: Removing unreachable block (ram,0xf00550b4) */

undefined8 _ipc_kmsg_clean_partial(uint param_1,uint *param_2,int param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  uint uVar5;
  uint *puVar6;
  undefined4 unaff_l1;
  uint uVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  uint uVar8;
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
  uVar5 = *(uint *)(param_1 + 0x14);
  _ipc_object_destroy(*(undefined4 *)(param_1 + 0x1c),uVar5 & 0xff);
  iVar2 = *(int *)(param_1 + 0x20);
  if ((iVar2 != 0) && (iVar2 != -1)) {
    _ipc_object_destroy(iVar2,(uVar5 & 0xff00) >> 8);
  }
  _ipc_kmsg_clean_body(param_1 + 0x2c,param_2);
  if (param_3 != 0) {
    uVar5 = *param_2;
    uVar8 = uVar5 >> 3 & 1;
    if ((uVar5 & 4) == 0) {
      uVar7 = (uint)*(byte *)param_2;
      uVar4 = uVar5 >> 0x10 & 0xff;
      uVar5 = uVar5 >> 4 & 0xfff;
      param_2 = param_2 + 1;
    }
    else {
      uVar7 = (uint)*(word *)(param_2 + 1);
      uVar4 = (uint)*(word *)((int)param_2 + 6);
      uVar5 = param_2[2];
      param_2 = param_2 + 3;
    }
    umul(uVar5,uVar4);
    bVar1 = 5 < uVar7 - 0x10;
    uVar5 = uVar5 + 7 >> 3;
    if (!bVar1) {
      puVar6 = param_2;
      if (uVar8 == 0) {
        puVar6 = (uint *)*param_2;
      }
      param_1 = 0;
      if (param_4 != 0) {
        iVar2 = 0;
        do {
          iVar3 = *(int *)(iVar2 + (int)puVar6);
          if ((iVar3 != 0) && (iVar3 != -1)) {
            _ipc_object_destroy(iVar3,uVar7);
          }
          param_1 = param_1 + 1;
          iVar2 = iVar2 + 4;
        } while (param_1 < param_4);
      }
    }
    if ((uVar8 == 0) && (uVar5 != 0)) {
      if (bVar1) {
        _vm_deallocate(_ipc_soft_map,*param_2,uVar5);
      }
      else {
        _kfree(*param_2,uVar5);
      }
    }
  }
  return CONCAT44(param_2,param_1);
}

