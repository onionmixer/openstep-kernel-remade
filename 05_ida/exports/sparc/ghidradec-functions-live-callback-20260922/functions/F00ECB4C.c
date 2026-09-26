
/* WARNING: Removing unreachable block (ram,0xf00ecbec) */
/* WARNING: Removing unreachable block (ram,0xf00ecb90) */
/* WARNING: Removing unreachable block (ram,0xf00ecbd8) */
/* WARNING: Removing unreachable block (ram,0xf00ecc10) */
/* WARNING: Removing unreachable block (ram,0xf00ecb50) */

undefined8 __NXAddAltHandler(uint *param_1,undefined4 param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  puVar1 = param_1;
  _current_thread_EXTERNAL();
  puVar4 = unk_F012F048;
  puVar2 = DAT_f012f058;
  do {
    if (puVar2 == puVar1) {
loc_F00ECB9C:
      uVar5 = *(uint *)((int)puVar4 + 0xc);
      if (uVar5 == *(uint *)((int)puVar4 + 8)) {
        if (*(undefined **)((int)puVar4 + 4) == unk_F012EF88) {
          *(uint *)((int)puVar4 + 8) = uVar5 + 1;
          uVar5 = (uVar5 + 1) * 0xc;
          _malloc();
          *(uint *)((int)puVar4 + 4) = uVar5;
          _bcopy(unk_F012EF88,uVar5,0xc0);
          uVar5 = *(uint *)((int)puVar4 + 0xc);
        }
        else {
          uVar5 = *(uint *)((int)puVar4 + 8);
          *(uint *)((int)puVar4 + 8) = uVar5 + 1;
          uVar3 = *(uint *)((int)puVar4 + 4);
          _realloc(uVar3,(uVar5 + 1) * 0xc);
          *(uint *)((int)puVar4 + 4) = uVar3;
          uVar5 = *(uint *)((int)puVar4 + 0xc);
        }
      }
      *(uint *)((int)puVar4 + 0xc) = uVar5 + 1;
      iVar6 = uVar5 * 0xc + *(uint *)((int)puVar4 + 4);
      *(uint *)(uVar5 * 0xc + *(uint *)((int)puVar4 + 4)) = *(uint *)puVar4;
      *(uint *)puVar4 = (int)((iVar6 - *(uint *)((int)puVar4 + 4)) * -0x55555555) >> 1 | 1;
      *(uint **)(iVar6 + 4) = param_1;
      *(undefined4 *)(iVar6 + 8) = param_2;
      return CONCAT44(param_2,*(uint *)puVar4);
    }
    puVar4 = *(undefined **)((int)puVar4 + 0x14);
    if ((uint *)puVar4 == (uint *)0x0) {
      sub_F00EC878();
      puVar4 = (undefined *)puVar1;
      goto loc_F00ECB9C;
    }
    puVar2 = *(uint **)((int)puVar4 + 0x10);
  } while( true );
}

