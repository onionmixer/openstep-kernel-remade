
/* WARNING: Removing unreachable block (ram,0xf009955c) */
/* WARNING: Removing unreachable block (ram,0xf00994e4) */
/* WARNING: Removing unreachable block (ram,0xf00995c0) */
/* WARNING: Removing unreachable block (ram,0xf00994cc) */

undefined8 _bp_iom_map(uint *param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  uint *puVar5;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar6;
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
  _iom_ptefind(param_2,param_4);
  if (param_2 == (uint *)0x0) {
    _panic(aBpIomMapBadIop);
    uVar1 = *param_1;
  }
  else {
    uVar1 = *param_1;
  }
  uVar3 = _kernel_pmap;
  if ((uVar1 & 0x10) != 0) {
    uVar3 = *(undefined4 *)(*(int *)(*(int *)(param_1[0xb] + 0x68) + 0xc) + 0x24);
  }
  uVar2 = param_1[8];
  puVar5 = (uint *)((int)register0x00000038 + -0xc);
  uVar4 = param_1[5] + (uVar2 & 0xfff) + 0xfff >> 0xc;
  uVar1 = 0;
  if (uVar4 != 0) {
    do {
      _pmap_getpte(uVar3,uVar2,puVar5);
      uVar1 = *puVar5;
      bVar6 = _cache == 0;
      *param_2 = uVar1;
      if (bVar6) {
        *param_2 = uVar1 & 0xffffff7f;
      }
      if ((_vac != 0) &&
         (((DAT_f0112a98._0_4_ == 0 || (_dvma_incoherent._0_4_ != 0)) && ((*param_2 & 0x80) != 0))))
      {
        _pmap_vacflush(*puVar5 >> 8);
        *param_2 = *param_2 & 0xffffff7f;
      }
      uVar1 = uVar4 - 1;
      param_2 = param_2 + 1;
      uVar2 = uVar2 + 0x1000;
      uVar4 = uVar1;
    } while (0 < (int)uVar1);
  }
  *param_2 = 0;
  return CONCAT44(param_2,uVar1);
}
