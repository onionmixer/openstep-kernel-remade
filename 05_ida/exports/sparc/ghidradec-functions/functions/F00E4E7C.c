
/* WARNING: Removing unreachable block (ram,0xf00e4f0c) */
/* WARNING: Removing unreachable block (ram,0xf00e4ee4) */
/* WARNING: Removing unreachable block (ram,0xf00e4ebc) */
/* WARNING: Removing unreachable block (ram,0xf00e4ed0) */
/* WARNING: Removing unreachable block (ram,0xf00e4ef8) */
/* WARNING: Removing unreachable block (ram,0xf00e4f20) */
/* WARNING: Removing unreachable block (ram,0xf00e4ea0) */

undefined8 _sparcfbConfigDisplay(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined6 *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  if ((undefined4 *)_sparcfbs == (undefined4 *)0x0) {
    _sparcfbs = _fakeshmem;
    _bzero(_fakeshmem,0x448);
    *(undefined4 *)_sparcfbs = 0xabbaabba;
  }
  puVar1 = aCgfourteen;
  _find_node();
  if (puVar1 == (undefined *)0x0) {
loc_F00E4EE4:
    puVar3 = &aCgsix;
    _find_node();
    if (puVar3 != (undefined6 *)0x0) {
      iVar2 = 0;
      _cg6ConfigDisplay(0,puVar3);
      if (iVar2 == 0) goto loc_F00E4F34;
    }
    puVar1 = aSunwTcx;
    _find_node();
    uVar4 = 0xfffffd40;
    if (puVar1 == (undefined *)0x0) goto locret_F00E4F38;
    iVar2 = 0;
    _s24ConfigDisplay(0,puVar1);
    uVar4 = 0xfffffd40;
    if (iVar2 != 0) goto locret_F00E4F38;
  }
  else {
    iVar2 = 0;
    _cg14ConfigDisplay(0,puVar1);
    if (iVar2 != 0) goto loc_F00E4EE4;
  }
loc_F00E4F34:
  uVar4 = 0;
locret_F00E4F38:
  return CONCAT44(param_2,uVar4);
}
