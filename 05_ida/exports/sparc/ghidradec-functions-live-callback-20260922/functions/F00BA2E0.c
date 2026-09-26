
/* WARNING: Removing unreachable block (ram,0xf00ba3dc) */
/* WARNING: Removing unreachable block (ram,0xf00ba3fc) */
/* WARNING: Removing unreachable block (ram,0xf00ba3f0) */
/* WARNING: Removing unreachable block (ram,0xf00ba338) */
/* WARNING: Removing unreachable block (ram,0xf00ba354) */
/* WARNING: Removing unreachable block (ram,0xf00ba3b0) */
/* WARNING: Removing unreachable block (ram,0xf00ba3c4) */
/* WARNING: Removing unreachable block (ram,0xf00ba458) */
/* WARNING: Removing unreachable block (ram,0xf00ba2e8) */

undefined8 _zsstart(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar6;
  int iVar7;
  undefined4 unaff_l3;
  int iVar8;
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
  iVar8 = *(int *)(param_1 + 0x34);
  iVar7 = *(int *)(iVar8 + 0x18);
  iVar1 = param_1;
  _spltty();
  uVar4 = *(uint *)(param_1 + 0x40);
  if ((uVar4 & 0x129) != 0) goto loc_F00BA458;
  iVar2 = *(int *)(param_1 + 0x18);
  if (iVar2 <= *(sword *)(_ttlowat + (*(byte *)(param_1 + 0x4a) & 0x1f) * 2)) {
    if ((uVar4 & 0x40) != 0) {
      *(uint *)(param_1 + 0x40) = uVar4 & 0xffffffbf;
      _wakeup(param_1 + 0x18);
    }
    if (*(int *)(param_1 + 0x2c) != 0) {
      _selwakeup(*(int *)(param_1 + 0x2c),*(uint *)(param_1 + 0x40) & 0x1000);
      *(undefined4 *)(param_1 + 0x2c) = 0;
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xffffefff;
    }
    iVar2 = *(int *)(param_1 + 0x18);
  }
  if (iVar2 == 0) goto loc_F00BA458;
  if (*(sword *)(iVar7 + 0x118) < 1) {
    uVar4 = param_1 + 0x18;
    if ((*(uint *)(param_1 + 0x3c) & 0x200020) != 0) {
      _ndqb(uVar4,0);
loc_F00BA3FC:
      _splzs();
      *(undefined4 *)(iVar7 + 0x114) = *(undefined4 *)(param_1 + 0x1c);
      *(sword *)(iVar7 + 0x118) = (sword)uVar4;
      *(sword *)(iVar7 + 0x11a) = (sword)uVar4;
      pbVar5 = *(byte **)(iVar8 + 0x10);
      if ((*pbVar5 & 4) == 0) {
        uVar4 = *(uint *)(param_1 + 0x40);
      }
      else {
        pbVar3 = *(byte **)(iVar7 + 0x114);
        *(byte **)(iVar7 + 0x114) = pbVar3 + 1;
        pbVar5[2] = *pbVar3;
        *(sword *)(iVar7 + 0x118) = *(sword *)(iVar7 + 0x118) + -1;
        uVar4 = *(uint *)(param_1 + 0x40);
      }
      goto loc_F00BA450;
    }
    uVar6 = param_1 + 0x18;
    uVar4 = uVar6;
    _ndqb(uVar6,0x80);
    if (uVar4 != 0) goto loc_F00BA3FC;
    _getc(uVar6);
    _timeout(_ttrstrt,param_1,(uVar6 & 0x7f) + 6);
    uVar4 = *(uint *)(param_1 + 0x40) | 1;
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x40);
loc_F00BA450:
    uVar4 = uVar4 | 0x20;
  }
  *(uint *)(param_1 + 0x40) = uVar4;
loc_F00BA458:
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}

