
/* WARNING: Removing unreachable block (ram,0xf004380c) */
/* WARNING: Removing unreachable block (ram,0xf00437c4) */
/* WARNING: Removing unreachable block (ram,0xf00437ec) */
/* WARNING: Removing unreachable block (ram,0xf0043758) */

undefined8 _getport_loop(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar5;
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
  iVar5 = 0;
  while (iVar2 = param_1, _pmap_kgetport(param_1,param_2,param_3,param_4), 0 < iVar2) {
    puVar3 = aPortmapperNotR_0;
    if ((*(uint *)(_active_threads + 0x18c) & 3) != 0) goto loc_F004380C;
    iVar4 = *_active_u;
    uVar1 = *(uint *)(iVar4 + 0x18) | *(uint *)(*(int *)(_active_threads + 0x84) + 0x4c);
    if ((uVar1 != 0) &&
       (((*(uint *)(iVar4 + 0x28) & 0x10) != 0 ||
        ((uVar1 & ~(*(uint *)(iVar4 + 0x20) | *(uint *)(iVar4 + 0x1c))) != 0)))) {
      iVar4 = 0;
      _issig();
      puVar3 = aPortmapperNotR_0;
      if (iVar4 != 0) goto loc_F004380C;
    }
    iVar5 = iVar5 + 1;
    if (iVar5 == 1) {
      _printf(aPortmapperNotR);
    }
  }
  if (iVar5 != 0) {
    puVar3 = aPortmapperOk;
loc_F004380C:
    _printf(puVar3);
  }
  return CONCAT44(param_2,iVar2);
}
