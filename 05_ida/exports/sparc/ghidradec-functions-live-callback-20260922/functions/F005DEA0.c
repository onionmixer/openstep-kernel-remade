
/* WARNING: Removing unreachable block (ram,0xf005def0) */
/* WARNING: Removing unreachable block (ram,0xf005dec4) */
/* WARNING: Removing unreachable block (ram,0xf005dedc) */
/* WARNING: Removing unreachable block (ram,0xf005df5c) */
/* WARNING: Removing unreachable block (ram,0xf005dea8) */

undefined8 _ipc_space_create(uint *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  puVar1 = _ipc_space_zone;
  _zalloc();
  if (puVar1 == (undefined4 *)0x0) {
    uVar6 = 6;
  }
  else {
    iVar2 = *param_1 << 4;
    _ipc_table_alloc();
    if (iVar2 == 0) {
      _zfree(_ipc_space_zone,puVar1);
      uVar6 = 6;
    }
    else {
      uVar5 = *param_1;
      _bzero(iVar2,uVar5 << 4);
      uVar4 = 0;
      if (uVar5 != 0) {
        do {
          iVar3 = uVar4 * 0x10;
          *(undefined4 *)(iVar2 + iVar3) = 0xff000000;
          uVar4 = uVar4 + 1;
          *(uint *)(iVar2 + iVar3 + 8) = uVar4;
        } while (uVar4 < uVar5);
      }
      *(undefined4 *)(uVar5 * 0x10 + iVar2 + -8) = 0;
      *puVar1 = 0;
      puVar1[1] = 2;
      puVar1[2] = 0;
      puVar1[3] = 1;
      puVar1[4] = 0;
      puVar1[5] = iVar2;
      puVar1[6] = uVar5;
      puVar1[7] = param_1 + 1;
      _ipc_splay_tree_init(puVar1 + 8);
      puVar1[0xe] = 0;
      puVar1[0xf] = 0;
      puVar1[0x10] = 0;
      puVar1[0x11] = 0;
      *param_2 = puVar1;
      uVar6 = 0;
    }
  }
  return CONCAT44(param_2,uVar6);
}

