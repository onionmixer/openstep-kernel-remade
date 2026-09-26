
/* WARNING: Removing unreachable block (ram,0xf001d808) */
/* WARNING: Removing unreachable block (ram,0xf001d750) */
/* WARNING: Removing unreachable block (ram,0xf001d7a0) */
/* WARNING: Removing unreachable block (ram,0xf001d858) */
/* WARNING: Removing unreachable block (ram,0xf001d730) */

undefined8 _m_clalloc(uint param_1,undefined2 *param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 unaff_i1;
  undefined2 *puVar5;
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
  uVar1 = param_1;
  .umul(param_1,_page_size);
  puVar3 = _mb_map;
  _kmem_mb_alloc(_mb_map,uVar1 + _page_mask & ~_page_mask);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else if (param_2 == (undefined2 *)0x1) {
    iVar2 = 0;
    .umul(param_1,_page_size);
    param_1 = param_1 >> 10;
    if (param_1 != 0) {
      do {
        puVar4 = puVar3;
        puVar4[1] = 0;
        iVar2 = iVar2 + 1;
        *puVar4 = _mclfree;
        puVar3 = puVar4 + 0x100;
        DAT_f0134afc._0_4_ = DAT_f0134afc._0_4_ + 1;
        _mclfree = puVar4;
      } while (iVar2 < (int)param_1);
    }
    DAT_f0134af4._0_4_ = DAT_f0134af4._0_4_ + param_1;
  }
  else if ((int)param_2 < 2) {
    if (param_2 == (undefined2 *)0x0) {
      .umul(param_1,_page_size);
      param_1 = param_1 >> 7;
      if (param_1 != 0) {
        puVar3[1] = 0;
        puVar4 = puVar3;
        puVar5 = (undefined2 *)((int)puVar3 + 10);
        while( true ) {
          *puVar5 = 1;
          param_2 = puVar5 + 0x40;
          puVar3 = puVar4 + 0x20;
          param_1 = param_1 - 1;
          DAT_f0134b0e._0_2_ = DAT_f0134b0e._0_2_ + 1;
          _mbstat._0_4_ = _mbstat._0_4_ + 1;
          _m_free(puVar4);
          if ((int)param_1 < 1) break;
          *(undefined4 *)(puVar5 + 0x3d) = 0;
          puVar4 = puVar3;
          puVar5 = param_2;
        }
      }
    }
  }
  else if (param_2 == (undefined2 *)0x2) {
    DAT_f0134af4._4_4_ = DAT_f0134af4._4_4_ + param_1;
  }
  return CONCAT44(param_2,puVar3);
}
