
/* WARNING: Removing unreachable block (ram,0xf0057898) */
/* WARNING: Removing unreachable block (ram,0xf00577fc) */
/* WARNING: Removing unreachable block (ram,0xf0057704) */
/* WARNING: Removing unreachable block (ram,0xf00576fc) */
/* WARNING: Removing unreachable block (ram,0xf0057710) */
/* WARNING: Removing unreachable block (ram,0xf0057840) */
/* WARNING: Removing unreachable block (ram,0xf00578b0) */
/* WARNING: Removing unreachable block (ram,0xf00576dc) */

undefined8 _ipc_kmsg_copyin_compat_from_kernel(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  uint uVar11;
  undefined4 unaff_l3;
  uint *puVar12;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar13;
  undefined4 unaff_l6;
  uint uVar14;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint *puVar15;
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
  *(undefined4 *)((int)register0x00000038 + -0x20) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(param_1 + 0x1c);
  iVar7 = *(int *)(param_1 + 0x20);
  *(int *)((int)register0x00000038 + -0x14) = iVar7;
  uVar2 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)((int)register0x00000038 + -0x10) = uVar2;
  *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 0x28);
  _ipc_object_copyin_from_kernel(uVar2,0x13);
  if ((iVar7 != 0) && (iVar7 != -1)) {
    _ipc_object_copyin_from_kernel(iVar7,0x14);
  }
  uVar3 = 0x13;
  _ipc_object_copyin_type();
  iVar4 = 0x14;
  _ipc_object_copyin_type();
  *(uint *)(param_1 + 0x14) = uVar3 | iVar4 << 8;
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)((int)register0x00000038 + -0x1c);
  *(undefined4 *)(param_1 + 0x1c) = uVar2;
  *(int *)(param_1 + 0x20) = iVar7;
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)((int)register0x00000038 + -0x18);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)((int)register0x00000038 + -0xc);
  puVar8 = (uint *)(param_1 + 0x2c);
  if (*(char *)((int)register0x00000038 + -0x1d) == '\0') {
    puVar15 = (uint *)(param_1 + *(int *)(param_1 + 0x18) + 0x14);
    bVar1 = false;
    if (puVar8 < puVar15) {
      uVar3 = *puVar8;
      while( true ) {
        uVar11 = uVar3 >> 2 & 1;
        if (uVar11 == 0) {
          uVar14 = (uint)*(byte *)puVar8;
          uVar6 = uVar3 >> 0x10 & 0xff;
          uVar13 = uVar3 >> 4 & 0xfff;
          puVar9 = puVar8 + 1;
        }
        else {
          uVar14 = (uint)*(word *)(puVar8 + 1);
          uVar6 = (uint)*(word *)((int)puVar8 + 6);
          uVar13 = puVar8[2];
          puVar9 = puVar8 + 3;
        }
        *puVar8 = *puVar8 & 0xfffffffe;
        if (uVar11 != 0) {
          *(byte *)puVar8 = 0;
          *(byte *)((int)puVar8 + 1) = 0;
          *puVar8 = *puVar8 & 0xffff000f;
        }
        uVar5 = uVar13;
        .umul(uVar13,uVar6);
        if ((uVar3 >> 3 & 1) == 0) {
          puVar12 = (uint *)*puVar9;
          bVar1 = true;
          puVar10 = puVar9 + 1;
        }
        else {
          puVar10 = (uint *)((int)puVar9 + ((uVar5 + 7 >> 3) + 3 & 0xfffffffc));
          puVar12 = puVar9;
        }
        if (uVar14 - 5 < 2) {
          uVar3 = uVar14;
          _ipc_object_copyin_type();
          if (uVar11 == 0) {
            *(byte *)puVar8 = (byte)uVar3;
          }
          else {
            *(sword *)(puVar8 + 1) = (sword)uVar3;
          }
          uVar11 = 0;
          if (uVar13 != 0) {
            iVar7 = 0;
            do {
              iVar4 = *(int *)(iVar7 + (int)puVar12);
              if ((((iVar4 != 0) && (iVar4 != -1)) &&
                  (_ipc_object_copyin_from_kernel(iVar4,uVar14), uVar3 == 0x10)) &&
                 (_ipc_port_check_circularity(iVar4,uVar2), iVar4 != 0)) {
                *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x40000000;
              }
              uVar11 = uVar11 + 1;
              iVar7 = iVar7 + 4;
            } while (uVar11 < uVar13);
          }
          bVar1 = true;
        }
        if (puVar15 <= puVar10) break;
        uVar3 = *puVar10;
        puVar8 = puVar10;
      }
    }
    if (bVar1) {
      *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x80000000;
    }
  }
  return CONCAT44(uVar2,param_1);
}
