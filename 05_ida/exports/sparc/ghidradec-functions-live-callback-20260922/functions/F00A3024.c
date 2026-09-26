
undefined8 _init_context_table(void)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar4;
  undefined4 unaff_i1;
  undefined8 *puVar5;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  uVar1 = _nctxs;
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
  DAT_f013e10c = &_lru_context;
  _lru_context._0_4_ = &_lru_context;
  uVar4 = 1;
  puVar5 = (undefined8 *)&DAT_f013e000;
  puVar3 = _context_table;
  if (1 < _nctxs) {
    do {
      puVar2 = (undefined8 *)((int)puVar3 + 0xc);
      *(undefined4 *)((int)puVar3 + 0x14) = 0;
      puVar5 = puVar2;
      if (_lru_context._0_4_ != &_lru_context) {
        *(undefined8 **)((int)_lru_context._0_4_ + 4) = puVar2;
        puVar5 = DAT_f013e10c;
      }
      DAT_f013e10c = puVar5;
      *(undefined8 **)puVar2 = _lru_context._0_4_;
      *(undefined8 **)(puVar3 + 2) = &_lru_context;
      uVar4 = uVar4 + 1;
      puVar5 = &_lru_context;
      puVar3 = puVar2;
      _lru_context._0_4_ = puVar2;
    } while (uVar4 < uVar1);
  }
  return CONCAT44(puVar5,uVar4);
}

