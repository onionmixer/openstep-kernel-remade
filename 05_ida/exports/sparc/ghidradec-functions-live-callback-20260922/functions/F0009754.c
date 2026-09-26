
/* WARNING: Removing unreachable block (ram,0xf0009840) */
/* WARNING: Removing unreachable block (ram,0xf00097c4) */
/* WARNING: Removing unreachable block (ram,0xf0009898) */
/* WARNING: Removing unreachable block (ram,0xf00097b4) */

undefined8 _binit(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
  int iVar7;
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
  puVar1 = &_bfreelist;
  puVar5 = &dword_F0133DE4;
  do {
    puVar5[3] = puVar1;
    puVar5[2] = puVar1;
    puVar5[1] = puVar1;
    *puVar5 = puVar1;
    *puVar1 = 0x40000;
    iVar3 = _bufpages;
    iVar6 = _nbuf;
    puVar1 = puVar1 + 0x11;
    puVar5 = puVar5 + 0x11;
  } while (puVar1 < &_buf);
  iVar7 = 0;
  iVar2 = _bufpages;
  div(_bufpages,_nbuf);
  rem(iVar3,iVar6);
  if (0 < iVar6) {
    param_2 = 0x10008;
    iVar6 = 0;
    do {
      puVar1 = (undefined4 *)(_buf + iVar6);
      *(undefined2 *)((int)puVar1 + 0x1e) = 0xffff;
      iVar4 = _buffers;
      puVar1[5] = 0;
      puVar1[8] = iVar4 + iVar7 * 0x2000;
      iVar4 = iVar2;
      if (iVar7 < iVar3) {
        iVar4 = iVar2 + 1;
      }
      umul(iVar4,_page_size);
      puVar1[6] = iVar4;
      puVar1[0xf] = 0;
      if (puVar1[6] == 0) {
        puVar1[1] = DAT_f0133eb0._0_4_;
        puVar1[2] = unk_F0133EAC;
        DAT_f0133eb0._0_4_[2] = puVar1;
        DAT_f0133eb0._0_4_ = puVar1;
      }
      else {
        puVar1[1] = DAT_f0133e6c._0_4_;
        puVar1[2] = unk_F0133E68;
        *(undefined4 **)(DAT_f0133e6c._0_4_ + 8) = puVar1;
        DAT_f0133e6c._0_4_ = puVar1;
      }
      puVar1[0x10] = 0;
      *puVar1 = 0x10008;
      _brelse(puVar1);
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 0x44;
    } while (iVar7 < _nbuf);
  }
  return CONCAT44(param_2,iVar3);
}

