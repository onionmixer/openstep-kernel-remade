
/* WARNING: Removing unreachable block (ram,0xf0054fec) */
/* WARNING: Removing unreachable block (ram,0xf0054fa4) */
/* WARNING: Removing unreachable block (ram,0xf0055004) */
/* WARNING: Removing unreachable block (ram,0xf0054f10) */

undefined8 _ipc_kmsg_clean_body(uint *param_1,uint *param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar8;
  undefined4 unaff_l6;
  uint uVar9;
  undefined4 unaff_l7;
  uint *puVar10;
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
  do {
    while( true ) {
      while( true ) {
        if (param_2 <= param_1) {
          return CONCAT44(param_2,param_1);
        }
        uVar2 = *param_1;
        uVar8 = uVar2 >> 3 & 1;
        if ((uVar2 & 4) == 0) {
          uVar9 = (uint)*(byte *)param_1;
          uVar6 = uVar2 >> 0x10 & 0xff;
          uVar2 = uVar2 >> 4 & 0xfff;
          param_1 = param_1 + 1;
        }
        else {
          uVar9 = (uint)*(word *)(param_1 + 1);
          uVar6 = (uint)*(word *)((int)param_1 + 6);
          uVar2 = param_1[2];
          param_1 = param_1 + 3;
        }
        uVar3 = uVar2;
        .umul(uVar2,uVar6);
        bVar1 = uVar9 - 0x10 < 6;
        uVar6 = uVar3 + 7 >> 3;
        if (bVar1) {
          if (uVar8 == 0) {
            puVar10 = (uint *)*param_1;
          }
          else {
            for (puVar4 = param_1 + uVar2; puVar10 = param_1, param_2 < puVar4; puVar4 = puVar4 + -1
                ) {
              uVar2 = uVar2 - 1;
            }
          }
          uVar3 = 0;
          if (uVar2 != 0) {
            iVar7 = 0;
            do {
              iVar5 = *(int *)(iVar7 + (int)puVar10);
              if ((iVar5 != 0) && (iVar5 != -1)) {
                _ipc_object_destroy(iVar5,uVar9);
              }
              uVar3 = uVar3 + 1;
              iVar7 = iVar7 + 4;
            } while (uVar3 < uVar2);
          }
        }
        if (uVar8 == 0) break;
        param_1 = (uint *)((int)param_1 + (uVar6 + 3 & 0xfffffffc));
      }
      if (uVar6 != 0) break;
loc_F005500C:
      param_1 = param_1 + 1;
    }
    if (!bVar1) {
      _vm_deallocate(_ipc_soft_map,*param_1,uVar6);
      goto loc_F005500C;
    }
    _kfree(*param_1,uVar6);
    param_1 = param_1 + 1;
  } while( true );
}
