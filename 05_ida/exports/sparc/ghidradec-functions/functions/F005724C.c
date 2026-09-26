
/* WARNING: Removing unreachable block (ram,0xf0057384) */
/* WARNING: Removing unreachable block (ram,0xf00575c8) */
/* WARNING: Removing unreachable block (ram,0xf005759c) */
/* WARNING: Removing unreachable block (ram,0xf0057558) */
/* WARNING: Removing unreachable block (ram,0xf0057520) */
/* WARNING: Removing unreachable block (ram,0xf00574a0) */
/* WARNING: Removing unreachable block (ram,0xf00572d4) */
/* WARNING: Removing unreachable block (ram,0xf00572c0) */
/* WARNING: Removing unreachable block (ram,0xf005734c) */
/* WARNING: Removing unreachable block (ram,0xf0057504) */
/* WARNING: Removing unreachable block (ram,0xf0057544) */
/* WARNING: Removing unreachable block (ram,0xf005757c) */
/* WARNING: Removing unreachable block (ram,0xf00573ec) */
/* WARNING: Removing unreachable block (ram,0xf005761c) */
/* WARNING: Removing unreachable block (ram,0xf0057638) */
/* WARNING: Removing unreachable block (ram,0xf0057290) */

undefined8 _ipc_kmsg_copyin_compat(int param_1,uint param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 unaff_l0;
  int iVar7;
  uint *puVar8;
  undefined4 unaff_l1;
  uint *puVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  uint uVar13;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar14;
  undefined4 unaff_i3;
  uint *puVar15;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar16;
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
  *(undefined4 *)((int)register0x00000038 + -0x20) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = *(undefined4 *)(param_1 + 0x18);
  uVar4 = *(undefined4 *)(param_1 + 0x1c);
  *(uint *)((int)register0x00000038 + -0x3c) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x18) = uVar4;
  iVar7 = *(int *)(param_1 + 0x20);
  *(int *)((int)register0x00000038 + -0x14) = iVar7;
  uVar4 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)((int)register0x00000038 + -0x10) = uVar4;
  iVar2 = *(int *)((int)register0x00000038 + -0x3c);
  *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 0x28);
  _ipc_object_copyin_header
            (iVar2,uVar4,(undefined *)((int)register0x00000038 + -0x24),
             (undefined *)((int)register0x00000038 + -0x28));
  if (iVar2 == 0) {
    iVar2 = *(int *)((int)register0x00000038 + -0x3c);
    if (iVar7 == 0) {
      *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
      *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
    }
    else {
      _ipc_object_copyin_header
                (iVar2,iVar7,(undefined *)((int)register0x00000038 + -0x2c),
                 (undefined *)((int)register0x00000038 + -0x30));
      if (iVar2 != 0) {
        _ipc_object_destroy(*(undefined4 *)((int)register0x00000038 + -0x24),
                            *(undefined4 *)((int)register0x00000038 + -0x28));
        uVar4 = 0x10000009;
        goto locret_F0057698;
      }
    }
    *(uint *)(param_1 + 0x14) =
         *(uint *)((int)register0x00000038 + -0x28) | *(int *)((int)register0x00000038 + -0x30) << 8
    ;
    uVar5 = *(undefined4 *)((int)register0x00000038 + -0x24);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)((int)register0x00000038 + -0x1c);
    uVar4 = *(undefined4 *)((int)register0x00000038 + -0x2c);
    *(undefined4 *)(param_1 + 0x1c) = uVar5;
    *(undefined4 *)(param_1 + 0x20) = uVar4;
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)((int)register0x00000038 + -0x18);
    *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)((int)register0x00000038 + -0xc);
    bVar16 = false;
    if (*(char *)((int)register0x00000038 + -0x1d) == '\0') {
      puVar15 = (uint *)(param_1 + *(int *)(param_1 + 0x18) + 0x14);
      puVar9 = (uint *)(param_1 + 0x2c);
      while (puVar11 = puVar9, puVar11 < puVar15) {
        if ((uint)((int)puVar15 - (int)puVar11) < 4) {
loc_F00573E8:
          _ipc_kmsg_clean_partial(param_1,puVar11,0,0);
          uVar4 = 0x10000008;
          goto locret_F0057698;
        }
        uVar10 = *puVar11 >> 2 & 1;
        if (uVar10 == 0) {
          uVar3 = *puVar11;
        }
        else {
          if ((uint)((int)puVar15 - (int)puVar11) < 0xc) goto loc_F00573E8;
          uVar3 = *puVar11;
        }
        param_2 = uVar3 >> 1 & 1;
        if (uVar10 == 0) {
          uVar14 = (uint)*(byte *)puVar11;
          uVar6 = uVar3 >> 0x10 & 0xff;
          uVar13 = uVar3 >> 4 & 0xfff;
          puVar12 = puVar11 + 1;
        }
        else {
          uVar14 = (uint)*(word *)(puVar11 + 1);
          uVar6 = (uint)*(word *)((int)puVar11 + 6);
          uVar13 = puVar11[2];
          puVar12 = puVar11 + 3;
        }
        bVar1 = uVar14 - 5 < 2;
        if ((bVar1) && (uVar6 != 0x20)) {
          _ipc_kmsg_clean_partial(param_1,puVar11,0,0);
          uVar4 = 0x1000000f;
          goto locret_F0057698;
        }
        *puVar11 = *puVar11 & 0xfffffffe;
        if (uVar10 != 0) {
          *(byte *)puVar11 = 0;
          *(byte *)((int)puVar11 + 1) = 0;
          *puVar11 = *puVar11 & 0xffff000f;
        }
        uVar6 = uVar13;
        .umul();
        puVar9 = (uint *)(uVar6 + 7 >> 3);
        if ((uVar3 >> 3 & 1) == 0) {
          if ((uint)((int)puVar15 - (int)puVar12) < 4) goto loc_F00573E8;
          uVar3 = *puVar12;
          if (puVar9 != (uint *)0x0) {
            if (bVar1) {
              puVar8 = puVar9;
              _kalloc();
              if (puVar8 != (uint *)0x0) {
                iVar2 = param_3;
                _copyinmap(param_3,uVar3,puVar8,puVar9);
                if ((iVar2 == 0) &&
                   ((param_2 == 0 ||
                    (iVar2 = param_3, _vm_deallocate(param_3,uVar3,puVar9), iVar2 == 0))))
                goto loc_F00575B0;
                _kfree(puVar8,puVar9);
              }
            }
            else {
              iVar2 = param_3;
              _vm_move(param_3,uVar3,_ipc_soft_map,puVar9,param_2,
                       (undefined *)((int)register0x00000038 + -0x34));
              puVar8 = *(uint **)((int)register0x00000038 + -0x34);
              if (iVar2 == 0) goto loc_F00575B0;
            }
            _ipc_kmsg_clean_partial(param_1,puVar11,0,0);
            uVar4 = 0x1000000c;
            goto locret_F0057698;
          }
          puVar8 = (uint *)0x0;
loc_F00575B0:
          *puVar12 = (uint)puVar8;
          puVar9 = puVar12 + 1;
          bVar16 = true;
        }
        else {
          uVar3 = (uint)((int)puVar9 + 3) & 0xfffffffc;
          if ((uint)((int)puVar15 - (int)puVar12) < uVar3) goto loc_F00573E8;
          puVar9 = (uint *)((int)puVar12 + uVar3);
          puVar8 = puVar12;
        }
        if (bVar1) {
          uVar3 = uVar14;
          _ipc_object_copyin_type();
          if (uVar10 == 0) {
            *(byte *)puVar11 = (byte)uVar3;
          }
          else {
            *(sword *)(puVar11 + 1) = (sword)uVar3;
          }
          uVar10 = 0;
          if (uVar13 != 0) {
            do {
              uVar6 = *puVar8;
              if ((uVar6 != 0) &&
                 (iVar2 = *(int *)((int)register0x00000038 + -0x3c), uVar6 != 0xffffffff)) {
                _ipc_object_copyin_compat
                          (iVar2,uVar6,uVar14,param_2,(undefined *)((int)register0x00000038 + -0x38)
                          );
                if (iVar2 != 0) {
                  _ipc_kmsg_clean_partial(param_1,puVar11,1,uVar10);
                  uVar4 = 0x1000000a;
                  goto locret_F0057698;
                }
                uVar6 = *(uint *)((int)register0x00000038 + -0x38);
                if (uVar3 == 0x10) {
                  _ipc_port_check_circularity
                            (uVar6,*(undefined4 *)((int)register0x00000038 + -0x24));
                  bVar16 = uVar6 != 0;
                  uVar6 = *(uint *)((int)register0x00000038 + -0x38);
                  if (bVar16) {
                    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x40000000;
                    uVar6 = *(uint *)((int)register0x00000038 + -0x38);
                  }
                }
                *puVar8 = uVar6;
              }
              uVar10 = uVar10 + 1;
              puVar8 = puVar8 + 1;
            } while (uVar10 < uVar13);
          }
          bVar16 = true;
        }
      }
      if (bVar16) {
        *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x80000000;
      }
      uVar4 = 0;
    }
    else {
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0x10000003;
  }
locret_F0057698:
  return CONCAT44(param_2,uVar4);
}
