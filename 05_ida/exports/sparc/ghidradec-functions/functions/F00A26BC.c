
/* WARNING: Removing unreachable block (ram,0xf00a2794) */
/* WARNING: Removing unreachable block (ram,0xf00a2714) */
/* WARNING: Removing unreachable block (ram,0xf00a27c4) */
/* WARNING: Removing unreachable block (ram,0xf00a26ec) */

undefined8 _pmap_alloc_kseg_entry(int param_1,undefined4 param_2,undefined param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
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
  dword_F013DF5C = dword_F013DF5C + 1;
  iVar5 = param_1;
  if (dword_F013DE48 != 0) {
    puVar1 = &_kseg_semi_active;
    _del_first_pool();
    if ((puVar1 == (undefined8 *)0x0) || (*(sword *)((int)puVar1 + 0x1e) == 0)) {
      _panic(aPmapAllocKsegE_2);
      iVar5 = *(int *)(puVar1 + 3);
    }
    else {
      iVar5 = *(int *)(puVar1 + 3);
    }
    iVar3 = *(word *)((int)puVar1 + 0x1c) - 1;
    *(sword *)((int)puVar1 + 0x1e) = *(sword *)((int)puVar1 + 0x1e) + -1;
    if (iVar3 != -1) {
      puVar4 = (undefined *)(iVar5 + 0xd);
      do {
        if (*(int *)(puVar4 + -5) == 0) {
          *(int *)(puVar4 + -5) = param_1;
          puVar4[2] = 0;
          *(undefined4 *)(puVar4 + 3) = 0;
          *(undefined4 *)(puVar4 + 7) = 0;
          *(undefined4 *)(puVar4 + 0xb) = 0;
          *(undefined4 *)(puVar4 + 0xf) = 0;
          *(undefined4 *)(puVar4 + 0x13) = 0;
          *(undefined4 *)(puVar4 + 0x17) = param_2;
          puVar2 = &_kseg_semi_active;
          if (*(sword *)((int)puVar1 + 0x1e) == 0) {
            puVar2 = &_kseg_active;
          }
          _add_pool(puVar2,puVar1);
          *puVar4 = param_3;
          DAT_f013de84._0_4_ = DAT_f013de84._0_4_ + 1;
          goto locret_F00A27CC;
        }
        puVar4 = puVar4 + 0x28;
        iVar3 = iVar3 + -1;
        iVar5 = iVar5 + 0x28;
      } while (iVar3 != -1);
    }
  }
  _panic(aPmapAllocKsegE_1);
locret_F00A27CC:
  return CONCAT44(param_2,iVar5);
}
