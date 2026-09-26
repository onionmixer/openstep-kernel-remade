
/* WARNING: Removing unreachable block (ram,0xf0055eb8) */
/* WARNING: Removing unreachable block (ram,0xf005612c) */
/* WARNING: Removing unreachable block (ram,0xf0056100) */
/* WARNING: Removing unreachable block (ram,0xf00560bc) */
/* WARNING: Removing unreachable block (ram,0xf0056084) */
/* WARNING: Removing unreachable block (ram,0xf0056004) */
/* WARNING: Removing unreachable block (ram,0xf0055ff0) */
/* WARNING: Removing unreachable block (ram,0xf0056068) */
/* WARNING: Removing unreachable block (ram,0xf00560a8) */
/* WARNING: Removing unreachable block (ram,0xf00560e0) */
/* WARNING: Removing unreachable block (ram,0xf0055f28) */
/* WARNING: Removing unreachable block (ram,0xf005617c) */
/* WARNING: Removing unreachable block (ram,0xf0056198) */
/* WARNING: Removing unreachable block (ram,0xf0055e64) */

undefined8 _ipc_kmsg_copyin(int param_1,uint param_2,int param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  uint uVar5;
  uint *puVar6;
  undefined4 unaff_l1;
  uint *puVar7;
  uint *puVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  uint uVar9;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint *puVar10;
  undefined4 unaff_i3;
  uint *puVar11;
  uint uVar12;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar13;
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
  *(uint *)((int)register0x00000038 + -0x14) = param_2;
  iVar2 = param_1 + 0x14;
  _ipc_kmsg_copyin_header(iVar2,*(undefined4 *)((int)register0x00000038 + -0x14),param_4);
  if (iVar2 == 0) {
    bVar13 = false;
    if (*(int *)(param_1 + 0x14) < 0) {
      *(undefined4 *)((int)register0x00000038 + -0x1c) = *(undefined4 *)(param_1 + 0x1c);
      puVar10 = (uint *)(param_1 + *(int *)(param_1 + 0x18) + 0x14);
      puVar6 = (uint *)(param_1 + 0x2c);
      while (puVar7 = puVar6, puVar7 < puVar10) {
        if ((uint)((int)puVar10 - (int)puVar7) < 4) goto loc_F0055F24;
        uVar12 = *puVar7 >> 2 & 1;
        if (uVar12 == 0) {
          uVar3 = *puVar7;
        }
        else {
          if ((uint)((int)puVar10 - (int)puVar7) < 0xc) goto loc_F0055F24;
          uVar3 = *puVar7;
        }
        uVar5 = uVar3 >> 3 & 1;
        uVar9 = uVar3 >> 1 & 1;
        if (uVar12 == 0) {
          param_2 = (uint)*(byte *)puVar7;
          uVar4 = uVar3 >> 0x10 & 0xff;
          uVar3 = uVar3 >> 4 & 0xfff;
          puVar8 = puVar7 + 1;
        }
        else {
          param_2 = (uint)*(word *)(puVar7 + 1);
          uVar4 = (uint)*(word *)((int)puVar7 + 6);
          uVar3 = puVar7[2];
          puVar8 = puVar7 + 3;
        }
        bVar1 = param_2 - 0x10 < 6;
        if ((bVar1) && (uVar4 != 0x20)) {
loc_F0055FE8:
          _ipc_kmsg_clean_partial(param_1,puVar7,0,0);
          iVar2 = 0x1000000f;
          goto locret_F00561FC;
        }
        uVar4 = *puVar7;
        if (uVar12 != 0) {
          if ((uVar4 & 0xfffffff0) != 0) goto loc_F0055FE8;
          uVar4 = *puVar7;
        }
        if (((uVar4 & 1) != 0) || ((uVar9 != 0 && (uVar5 != 0)))) goto loc_F0055FE8;
        uVar4 = uVar3;
        umul();
        puVar6 = (uint *)(uVar4 + 7 >> 3);
        if (uVar5 == 0) {
          if ((uint)((int)puVar10 - (int)puVar8) < 4) goto loc_F0055F24;
          uVar5 = *puVar8;
          if (puVar6 != (uint *)0x0) {
            if (bVar1) {
              puVar11 = puVar6;
              _kalloc();
              if (puVar11 != (uint *)0x0) {
                iVar2 = param_3;
                _copyinmap(param_3,uVar5,puVar11,puVar6);
                if ((iVar2 == 0) &&
                   ((uVar9 == 0 ||
                    (iVar2 = param_3, _vm_deallocate(param_3,uVar5,puVar6), iVar2 == 0))))
                goto loc_F0056114;
                _kfree(puVar11,puVar6);
              }
            }
            else {
              iVar2 = param_3;
              _vm_move(param_3,uVar5,_ipc_soft_map,puVar6,uVar9,
                       (undefined *)((int)register0x00000038 + -0xc));
              puVar11 = *(uint **)((int)register0x00000038 + -0xc);
              if (iVar2 == 0) goto loc_F0056114;
            }
            _ipc_kmsg_clean_partial(param_1,puVar7,0,0);
            iVar2 = 0x1000000c;
            goto locret_F00561FC;
          }
          puVar11 = (uint *)0x0;
loc_F0056114:
          *puVar8 = (uint)puVar11;
          puVar6 = puVar8 + 1;
          bVar13 = true;
        }
        else {
          uVar5 = (uint)((int)puVar6 + 3) & 0xfffffffc;
          if ((uint)((int)puVar10 - (int)puVar8) < uVar5) {
loc_F0055F24:
            _ipc_kmsg_clean_partial(param_1,puVar7,0,0);
            iVar2 = 0x10000008;
            goto locret_F00561FC;
          }
          puVar6 = (uint *)((int)puVar8 + uVar5);
          puVar11 = puVar8;
        }
        if (bVar1) {
          uVar5 = param_2;
          _ipc_object_copyin_type();
          if (uVar12 == 0) {
            *(byte *)puVar7 = (byte)uVar5;
          }
          else {
            *(sword *)(puVar7 + 1) = (sword)uVar5;
          }
          uVar12 = 0;
          if (uVar3 != 0) {
            do {
              uVar9 = *puVar11;
              if ((uVar9 != 0) &&
                 (iVar2 = *(int *)((int)register0x00000038 + -0x14), uVar9 != 0xffffffff)) {
                _ipc_object_copyin(iVar2,uVar9,param_2,
                                   (undefined *)((int)register0x00000038 + -0x10));
                if (iVar2 != 0) {
                  _ipc_kmsg_clean_partial(param_1,puVar7,1,uVar12);
                  iVar2 = 0x1000000a;
                  goto locret_F00561FC;
                }
                uVar9 = *(uint *)((int)register0x00000038 + -0x10);
                if (uVar5 == 0x10) {
                  _ipc_port_check_circularity
                            (uVar9,*(undefined4 *)((int)register0x00000038 + -0x1c));
                  bVar13 = uVar9 != 0;
                  uVar9 = *(uint *)((int)register0x00000038 + -0x10);
                  if (bVar13) {
                    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x40000000;
                    uVar9 = *(uint *)((int)register0x00000038 + -0x10);
                  }
                }
                *puVar11 = uVar9;
              }
              uVar12 = uVar12 + 1;
              puVar11 = puVar11 + 1;
            } while (uVar12 < uVar3);
          }
          bVar13 = true;
        }
      }
      if (bVar13) {
        iVar2 = 0;
      }
      else {
        *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0x7fffffff;
        iVar2 = 0;
      }
    }
    else {
      iVar2 = 0;
    }
  }
locret_F00561FC:
  return CONCAT44(param_2,iVar2);
}

