
/* WARNING: Removing unreachable block (ram,0xf00da40c) */
/* WARNING: Removing unreachable block (ram,0xf00da3b0) */
/* WARNING: Removing unreachable block (ram,0xf00da310) */
/* WARNING: Removing unreachable block (ram,0xf00da33c) */
/* WARNING: Removing unreachable block (ram,0xf00da3e0) */
/* WARNING: Removing unreachable block (ram,0xf00da45c) */
/* WARNING: Removing unreachable block (ram,0xf00da2fc) */

undefined8
-[AudioChannel enqueueDescriptor:dataFormat:channelCount:](int param_1,undefined4 param_2)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint *puVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar8;
  uint uVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar10;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),paLock);
  uVar1 = *(uint *)(param_1 + 0xc);
  uVar9 = 0;
  _objc_msgSend(uVar1,paCount_0);
  if ((uVar1 == 0) || (puVar2 = *(uint **)(param_1 + 0x2c), (uint *)(param_1 + 0x2c) == puVar2)) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x10),paUnlock);
  }
  else {
    puVar7 = (uint *)puVar2[2];
    puVar6 = (undefined4 *)puVar2[3];
    puVar3 = puVar7;
    if ((uint *)(param_1 + 0x2c) != puVar7) {
      puVar3 = puVar7 + 2;
    }
    puVar3[1] = (uint)puVar6;
    puVar4 = puVar6 + 2;
    if ((undefined4 *)(param_1 + 0x2c) == puVar6) {
      puVar4 = puVar6;
    }
    uVar8 = 0;
    *puVar4 = puVar7;
    if (uVar1 != 0) {
      uVar5 = *(uint *)(param_1 + 0xc);
      while( true ) {
        _objc_msgSend(uVar5,paObjectat,uVar8);
        _objc_msgSend();
        if (uVar9 < uVar5) {
          uVar9 = uVar5;
        }
        uVar8 = uVar8 + 1;
        if (uVar1 <= uVar8) break;
        uVar5 = *(uint *)(param_1 + 0xc);
      }
    }
    _objc_msgSend(*(undefined4 *)(param_1 + 0x10),paUnlock);
    if (uVar9 != 0) {
      *puVar2 = uVar9;
      _vac_flush(puVar2[1],uVar9);
      uVar9 = param_1 + 0x24;
      if (uVar9 == *(uint *)(param_1 + 0x24)) {
        *(uint **)(param_1 + 0x24) = puVar2;
        *(uint **)(param_1 + 0x28) = puVar2;
        puVar2[2] = uVar9;
        puVar2[3] = uVar9;
      }
      else {
        uVar1 = *(uint *)(param_1 + 0x28);
        puVar2[3] = uVar1;
        puVar2[2] = uVar9;
        *(uint **)(param_1 + 0x28) = puVar2;
        *(uint **)(uVar1 + 8) = puVar2;
      }
      uVar10 = 1;
      *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
      goto locret_F00DA49C;
    }
    uVar9 = *(uint *)(param_1 + 0x2c);
    if (param_1 + 0x2cU == uVar9) {
      *(uint **)(param_1 + 0x2c) = puVar2;
      *(uint **)(param_1 + 0x30) = puVar2;
      puVar2[2] = uVar9;
      puVar2[3] = uVar9;
    }
    else {
      puVar2[3] = param_1 + 0x2cU;
      puVar2[2] = uVar9;
      *(uint **)(param_1 + 0x2c) = puVar2;
      *(uint **)(uVar9 + 0xc) = puVar2;
    }
  }
  uVar10 = 0;
locret_F00DA49C:
  return CONCAT44(param_2,uVar10);
}
