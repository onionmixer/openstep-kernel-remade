
/* WARNING: Removing unreachable block (ram,0xf009875c) */
/* WARNING: Removing unreachable block (ram,0xf009872c) */
/* WARNING: Removing unreachable block (ram,0xf00986d4) */
/* WARNING: Removing unreachable block (ram,0xf00986a0) */
/* WARNING: Removing unreachable block (ram,0xf009865c) */
/* WARNING: Removing unreachable block (ram,0xf0098664) */
/* WARNING: Removing unreachable block (ram,0xf00986ec) */
/* WARNING: Removing unreachable block (ram,0xf0098774) */
/* WARNING: Removing unreachable block (ram,0xf009864c) */

undefined8 _fill_node(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
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
  undefined auStackX_0 [92];
  undefined auStack_30 [48];
  
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
  iVar2 = param_1;
  _prom_childnode();
  while (puVar3 = (undefined *)((int)register0x00000038 + -0x30), iVar2 != 0) {
    _fill_node(iVar2);
    _prom_nextnode();
  }
  iVar2 = 0x27;
  do {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    bVar1 = 0 < iVar2;
    iVar2 = iVar2 + -1;
  } while (bVar1);
  iVar2 = param_1;
  _prom_getprop(param_1,&_psname,(undefined *)((int)register0x00000038 + -0x30));
  if (iVar2 != -1) {
    puVar3 = unk_F01133F8;
    iVar2 = unk_F01133F8._0_4_;
    while( true ) {
      _strncmp(iVar2,(undefined *)((int)register0x00000038 + -0x30),*(int *)((int)puVar3 + 4));
      if (iVar2 == 0) goto loc_f00986e8;
      puVar3 = (undefined *)((int)puVar3 + 0x14);
      if (unk_F01133F8 + 0x4f < puVar3) break;
      iVar2 = *(int *)puVar3;
    }
    puVar3 = (undefined *)((int)register0x00000038 + -0x30);
    iVar2 = 0x27;
    do {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
      bVar1 = 0 < iVar2;
      iVar2 = iVar2 + -1;
    } while (bVar1);
    iVar2 = param_1;
    _prom_getprop(param_1,_psdevtype,(undefined *)((int)register0x00000038 + -0x30));
    if (iVar2 == -1) goto locret_F009878C;
    puVar3 = unk_F0113448;
    iVar2 = unk_F0113448._0_4_;
    while (_strncmp(iVar2,(undefined *)((int)register0x00000038 + -0x30),*(int *)((int)puVar3 + 4)),
          iVar2 != 0) {
      puVar3 = (undefined *)((int)puVar3 + 0x14);
      if (unk_F0113448 + 0x27 < puVar3) goto locret_F009878C;
      iVar2 = *(int *)puVar3;
    }
    _fill_modinfo(param_1,puVar3);
  }
locret_F009878C:
  return CONCAT44(param_2,param_1);
loc_f00986e8:
  _fill_nodeinfo(param_1,puVar3);
  goto locret_F009878C;
}
