
/* WARNING: Removing unreachable block (ram,0xf005ebb0) */
/* WARNING: Removing unreachable block (ram,0xf005ec00) */
/* WARNING: Removing unreachable block (ram,0xf005eb70) */

undefined8 _ipc_table_fill(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  int iVar4;
  uint uVar5;
  uint uVar6;
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
  bool bVar7;
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
  .umul(param_3,param_4);
  uVar6 = 0;
  uVar3 = 1;
  uVar1 = _page_size;
  if (param_2 != 0) {
    iVar4 = 0;
    do {
      uVar1 = _page_size;
      if (_page_size <= uVar3) break;
      bVar7 = uVar6 < param_2;
      if (!bVar7) {
        uVar1 = uVar3;
        .udiv(uVar3,param_4);
        *(uint *)(iVar4 + param_1) = uVar1;
        iVar4 = iVar4 + 4;
        uVar6 = uVar6 + 1;
        bVar7 = uVar6 < param_2;
      }
      uVar3 = uVar3 << 1;
      uVar1 = _page_size;
    } while (bVar7);
  }
  do {
    if (param_2 <= uVar6) {
      return CONCAT44(param_2,param_1);
    }
    uVar5 = 0;
    iVar4 = uVar6 << 2;
    do {
      if (param_2 <= uVar6) break;
      if (param_3 <= uVar3) {
        uVar2 = uVar3;
        .udiv(uVar3,param_4);
        *(uint *)(iVar4 + param_1) = uVar2;
        iVar4 = iVar4 + 4;
        uVar6 = uVar6 + 1;
      }
      uVar5 = uVar5 + 1;
      uVar3 = uVar3 + uVar1;
    } while (uVar5 < 0xf);
    uVar1 = uVar1 << 1;
  } while( true );
}
