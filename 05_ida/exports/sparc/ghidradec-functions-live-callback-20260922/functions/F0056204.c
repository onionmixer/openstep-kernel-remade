
/* WARNING: Removing unreachable block (ram,0xf00563b8) */
/* WARNING: Removing unreachable block (ram,0xf005630c) */
/* WARNING: Removing unreachable block (ram,0xf0056274) */
/* WARNING: Removing unreachable block (ram,0xf0056248) */
/* WARNING: Removing unreachable block (ram,0xf0056280) */
/* WARNING: Removing unreachable block (ram,0xf0056360) */
/* WARNING: Removing unreachable block (ram,0xf00563d0) */
/* WARNING: Removing unreachable block (ram,0xf005622c) */

undefined8 _ipc_kmsg_copyin_from_kernel(int param_1,uint *param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  int iVar2;
  uint *puVar3;
  int iVar4;
  undefined4 unaff_l1;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  undefined4 unaff_l3;
  uint uVar10;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar11;
  undefined4 unaff_l6;
  uint uVar12;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 uVar13;
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
  uVar13 = *(undefined4 *)(param_1 + 0x1c);
  uVar5 = *(uint *)(param_1 + 0x14);
  iVar2 = *(int *)(param_1 + 0x20);
  uVar10 = uVar5 & 0xff;
  uVar9 = (uVar5 & 0xff00) >> 8;
  _ipc_object_copyin_from_kernel(uVar13,uVar10);
  if ((iVar2 != 0) && (iVar2 != -1)) {
    _ipc_object_copyin_from_kernel(iVar2,uVar9);
  }
  if (uVar5 == 0x80000013) {
    *(undefined4 *)(param_1 + 0x14) = 0x80000011;
  }
  else {
    _ipc_object_copyin_type();
    _ipc_object_copyin_type();
    uVar10 = uVar5 & 0xffff0000 | uVar10 | uVar9 << 8;
    *(uint *)(param_1 + 0x14) = uVar10;
    if (-1 < (int)uVar10) goto locret_F0056408;
  }
  puVar6 = (uint *)(param_1 + 0x2c);
  param_2 = (uint *)(param_1 + *(int *)(param_1 + 0x18) + 0x14);
  if (puVar6 < param_2) {
    uVar10 = *puVar6;
    while( true ) {
      uVar9 = uVar10 >> 2 & 1;
      if (uVar9 == 0) {
        uVar12 = (uint)*(byte *)puVar6;
        uVar5 = uVar10 >> 0x10 & 0xff;
        uVar11 = uVar10 >> 4 & 0xfff;
        puVar7 = puVar6 + 1;
      }
      else {
        uVar12 = (uint)*(word *)(puVar6 + 1);
        uVar5 = (uint)*(word *)((int)puVar6 + 6);
        uVar11 = puVar6[2];
        puVar7 = puVar6 + 3;
      }
      uVar1 = uVar11;
      umul(uVar11,uVar5);
      if ((uVar10 >> 3 & 1) == 0) {
        puVar3 = (uint *)*puVar7;
        puVar8 = puVar7 + 1;
      }
      else {
        puVar8 = (uint *)((int)puVar7 + ((uVar1 + 7 >> 3) + 3 & 0xfffffffc));
        puVar3 = puVar7;
      }
      if (uVar12 - 0x10 < 6) {
        uVar10 = uVar12;
        _ipc_object_copyin_type();
        if (uVar9 == 0) {
          *(byte *)puVar6 = (byte)uVar10;
        }
        else {
          *(sword *)(puVar6 + 1) = (sword)uVar10;
        }
        uVar9 = 0;
        if (uVar11 != 0) {
          iVar2 = 0;
          do {
            iVar4 = *(int *)(iVar2 + (int)puVar3);
            if ((((iVar4 != 0) && (iVar4 != -1)) &&
                (_ipc_object_copyin_from_kernel(iVar4,uVar12), uVar10 == 0x10)) &&
               (_ipc_port_check_circularity(iVar4,uVar13), iVar4 != 0)) {
              *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x40000000;
            }
            uVar9 = uVar9 + 1;
            iVar2 = iVar2 + 4;
          } while (uVar9 < uVar11);
        }
      }
      if (param_2 <= puVar8) break;
      uVar10 = *puVar8;
      puVar6 = puVar8;
    }
  }
locret_F0056408:
  return CONCAT44(param_2,param_1);
}

