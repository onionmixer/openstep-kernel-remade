
/* WARNING: Removing unreachable block (ram,0xf00f00c8) */
/* WARNING: Removing unreachable block (ram,0xf00f0098) */
/* WARNING: Removing unreachable block (ram,0xf00eff44) */
/* WARNING: Removing unreachable block (ram,0xf00eff3c) */
/* WARNING: Removing unreachable block (ram,0xf00f0090) */
/* WARNING: Removing unreachable block (ram,0xf00f00c0) */
/* WARNING: Removing unreachable block (ram,0xf00efe68) */
/* WARNING: Removing unreachable block (ram,0xf00efedc) */
/* WARNING: Removing unreachable block (ram,0xf00efee4) */

undefined8 sub_F00EFE48(uint *param_1,undefined4 param_2)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  code *pcVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar7;
  uint uVar8;
  undefined4 unaff_l3;
  uint *puVar9;
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
  puVar9 = (uint *)param_1[8];
  if (puVar9 == (uint *)_emptyCache) {
    __cache_create(param_1);
    puVar9 = param_1;
  }
  else {
    if (dword_F012F0D4 == 0) {
      puVar1 = (uint *)*puVar9;
    }
    else {
      if ((param_1[4] & 0x40) == 0) {
        puVar9[1] = 0;
        uVar4 = 0;
        if (*puVar9 != 0xffffffff) {
          iVar5 = 0;
          do {
            iVar5 = *(int *)((int)puVar9 + iVar5 + 8);
            if (iVar5 != 0) {
              iVar2 = uVar4 << 2;
              if (*(code **)(iVar5 + 8) == __objc_msgForward) {
                _NXDefaultMallocZone();
                _NXDefaultMallocZone();
                (**(code **)(iVar2 + 8))();
              }
              puVar9[uVar4 + 2] = 0;
            }
            uVar4 = uVar4 + 1;
            iVar5 = uVar4 * 4;
          } while (uVar4 < *puVar9 + 1);
        }
        param_1[4] = param_1[4] | 0x40;
        goto locret_F00F00DC;
      }
      param_1[4] = param_1[4] & 0xffffffbf;
      puVar1 = (uint *)*puVar9;
    }
    uVar8 = (int)((int)puVar1 + 1) * 2;
    _NXDefaultMallocZone();
    puVar3 = puVar1;
    _NXDefaultMallocZone();
    (*(code *)puVar1[1])();
    *puVar3 = uVar8 - 1;
    puVar3[1] = 0;
    uVar4 = 0;
    if (uVar8 != 0) {
      do {
        uVar7 = uVar4 + 1;
        puVar3[uVar4 + 2] = 0;
        uVar4 = uVar7;
      } while (uVar7 < uVar8);
    }
    uVar4 = *puVar9;
    if (dword_F012F0D0 == 0) {
      uVar8 = 0;
      if (uVar4 != 0xffffffff) {
        iVar5 = 0;
        do {
          puVar1 = *(uint **)((int)puVar9 + iVar5 + 8);
          if (puVar1 != (uint *)0x0) {
            uVar4 = *puVar3 & *puVar1;
            if (puVar3[uVar4 + 2] == 0) {
              puVar3[uVar4 + 2] = (uint)puVar1;
            }
            else {
              do {
                uVar4 = uVar4 + 1 & *puVar3;
              } while (puVar3[uVar4 + 2] != 0);
              puVar3[uVar4 + 2] = puVar9[uVar8 + 2];
            }
            puVar3[1] = puVar3[1] + 1;
          }
          uVar8 = uVar8 + 1;
          iVar5 = uVar8 * 4;
        } while (uVar8 < *puVar9 + 1);
      }
      uVar4 = param_1[4] | 0x20;
      param_1[4] = uVar4;
    }
    else {
      uVar8 = 0;
      if (uVar4 != 0xffffffff) {
        uVar4 = 0;
        do {
          iVar5 = *(int *)((int)puVar9 + uVar4 + 8);
          if ((iVar5 != 0) && (pcVar6 = *(code **)(iVar5 + 8), pcVar6 == __objc_msgForward)) {
            _NXDefaultMallocZone();
            _NXDefaultMallocZone();
            (**(code **)(pcVar6 + 8))();
          }
          uVar8 = uVar8 + 1;
          uVar4 = uVar8 * 4;
        } while (uVar8 < *puVar9 + 1);
      }
    }
    param_1[8] = (uint)puVar3;
    _NXDefaultMallocZone();
    _NXDefaultMallocZone();
    (**(code **)(uVar4 + 8))();
    puVar9 = puVar3;
  }
locret_F00F00DC:
  return CONCAT44(param_2,puVar9);
}

