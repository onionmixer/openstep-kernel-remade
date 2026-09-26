
/* WARNING: Removing unreachable block (ram,0xf0099358) */
/* WARNING: Removing unreachable block (ram,0xf009930c) */
/* WARNING: Removing unreachable block (ram,0xf00992e8) */

undefined8 _buscheck(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  uint uVar4;
  uint *puVar5;
  undefined4 unaff_l3;
  uint uVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar7;
  undefined4 unaff_l6;
  undefined4 uVar8;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
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
  uVar8 = _kernel_pmap;
  if ((*param_1 & 0x10) != 0) {
    uVar8 = *(undefined4 *)(*(int *)(*(int *)(param_1[0xb] + 0x68) + 0xc) + 0x24);
  }
  uVar7 = 0xffffffff;
  uVar3 = 0xffffffff;
  uVar4 = 0xffffffff;
  uVar1 = param_1[8];
  puVar5 = (uint *)((int)register0x00000038 + -0xc);
  uVar6 = param_1[5] + (uVar1 & 0xfff) + 0xfff >> 0xc;
  if (uVar6 != 0) {
    do {
      _pmap_getpte(uVar8,uVar1,puVar5);
      uVar2 = *puVar5;
      if (uVar4 == 0xffffffff) {
        uVar3 = uVar2 >> 8;
        if ((uVar2 & 3) != 2) {
loc_F0099340:
          uVar7 = 0xffffffff;
          break;
        }
        uVar4 = uVar3;
        _bustype();
        uVar7 = uVar3;
        if (uVar4 == 2) {
          uVar7 = 0;
        }
        uVar3 = uVar3 + 1;
      }
      else {
        if ((uVar2 & 3) != 2) {
          uVar7 = 0xffffffff;
          break;
        }
        uVar2 = uVar2 >> 8;
        _bustype();
        if (uVar4 != uVar2) {
          uVar7 = 0xffffffff;
          break;
        }
        if (uVar4 == 2) {
          uVar3 = uVar3 + 1;
        }
        else {
          bVar9 = *puVar5 >> 8 != uVar3;
          uVar3 = uVar3 + 1;
          if (bVar9) goto loc_F0099340;
        }
      }
      uVar6 = uVar6 - 1;
      uVar1 = uVar1 + 0x1000;
    } while (0 < (int)uVar6);
  }
  return CONCAT44(param_2,uVar7);
}
