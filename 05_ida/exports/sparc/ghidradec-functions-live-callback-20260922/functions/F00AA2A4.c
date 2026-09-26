
/* WARNING: Removing unreachable block (ram,0xf00aa340) */
/* WARNING: Removing unreachable block (ram,0xf00aa300) */
/* WARNING: Removing unreachable block (ram,0xf00aa3c4) */
/* WARNING: Removing unreachable block (ram,0xf00aa2c0) */
/* WARNING: Removing unreachable block (ram,0xf00aa390) */
/* WARNING: Removing unreachable block (ram,0xf00aa450) */
/* WARNING: Removing unreachable block (ram,0xf00aa328) */
/* WARNING: Removing unreachable block (ram,0xf00aa36c) */
/* WARNING: Removing unreachable block (ram,0xf00aa2b8) */

undefined8 _allocbuf(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  iVar2 = param_2 + -1 + _page_size;
  udiv(iVar2,_page_size);
  umul();
  uVar1 = unk_F0133EB8._0_4_;
  iVar5 = *(int *)(param_1 + 0x18);
  if (iVar2 == iVar5) {
    *(int *)(param_1 + 0x14) = param_2;
  }
  else if (iVar2 < iVar5) {
    if ((undefined *)unk_F0133EB8._0_4_ == unk_F0133EAC) {
      *(int *)(param_1 + 0x14) = param_2;
    }
    else {
      _spltty();
      *(undefined4 *)(*(int *)(uVar1 + 0x10) + 0xc) = *(undefined4 *)(uVar1 + 0xc);
      *(undefined4 *)(*(int *)(uVar1 + 0xc) + 0x10) = *(undefined4 *)(uVar1 + 0x10);
      *(uint *)uVar1 = *(uint *)uVar1 | 8;
      _splx();
      _pagemove(*(int *)(param_1 + 0x20) + iVar2,*(undefined4 *)(uVar1 + 0x20),
                *(int *)(param_1 + 0x18) - iVar2);
      *(int *)(uVar1 + 0x18) = *(int *)(param_1 + 0x18) - iVar2;
      *(int *)(param_1 + 0x18) = iVar2;
      *(undefined4 *)(uVar1 + 0x14) = 0;
      *(uint *)uVar1 = *(uint *)uVar1 | 0x10000;
      _brelse();
      *(int *)(param_1 + 0x14) = param_2;
    }
  }
  else if (iVar5 < iVar2) {
    do {
      puVar3 = *(uint **)(param_1 + 0x18);
      uVar6 = iVar2 - (int)puVar3;
      _getnewbuf();
      uVar4 = puVar3[6];
      if ((int)uVar4 <= (int)uVar6) {
        uVar6 = uVar4;
      }
      _pagemove(puVar3[8] + (uVar4 - uVar6),*(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x18),
                uVar6);
      *(uint *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + uVar6;
      uVar6 = puVar3[6] - uVar6;
      puVar3[6] = uVar6;
      if ((int)uVar6 < (int)puVar3[5]) {
        puVar3[5] = uVar6;
      }
      if ((int)puVar3[6] < 1) {
        *(uint *)(puVar3[2] + 4) = puVar3[1];
        *(uint *)(puVar3[1] + 8) = puVar3[2];
        puVar3[1] = (uint)DAT_f0133eb0._0_4_;
        puVar3[2] = (uint)unk_F0133EAC;
        DAT_f0133eb0._0_4_[2] = (uint)puVar3;
        DAT_f0133eb0._0_4_ = puVar3;
        *(undefined2 *)((int)puVar3 + 0x1e) = 0xffff;
        *(undefined2 *)(puVar3 + 7) = 0;
        *puVar3 = *puVar3 | 0x10000;
      }
      _brelse(puVar3);
    } while (*(int *)(param_1 + 0x18) < iVar2);
    *(int *)(param_1 + 0x14) = param_2;
  }
  else {
    *(int *)(param_1 + 0x14) = param_2;
  }
  return CONCAT44(param_2,1);
}

