
/* WARNING: Removing unreachable block (ram,0xf0024900) */
/* WARNING: Removing unreachable block (ram,0xf00248a0) */
/* WARNING: Removing unreachable block (ram,0xf00248f8) */
/* WARNING: Removing unreachable block (ram,0xf00249bc) */
/* WARNING: Removing unreachable block (ram,0xf002487c) */

undefined8 _brelse(uint *param_1,undefined4 param_2)

{
  uint *puVar1;
  uint uVar2;
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
  if ((*param_1 & 0x40) != 0) {
    _wakeup(param_1);
  }
  if ((_bfreelist & 0x40) != 0) {
    _bfreelist = _bfreelist & 0xffffffbf;
    _wakeup(&_bfreelist);
  }
  if ((*param_1 & 0x400200) == 0x400000) {
    *param_1 = *param_1 | 0x10000;
    uVar2 = *param_1;
  }
  else {
    uVar2 = *param_1;
  }
  puVar1 = (uint *)0x20000;
  if ((uVar2 & 4) != 0) {
    puVar1 = (uint *)(uVar2 & 0xfffffffb);
    if ((uVar2 & 0x20000) == 0) {
      puVar1 = param_1;
      sub_F0025690(param_1);
    }
    else {
      *param_1 = (uint)puVar1;
    }
  }
  _splusclock();
  if ((int)param_1[6] < 1) {
    puVar3 = unk_F0133EAC;
  }
  else {
    uVar2 = *param_1;
    if ((uVar2 & 0x10004) == 0) {
      if ((uVar2 & 0x20000) == 0) {
        if ((uVar2 & 0x80) == 0) {
          puVar3 = unk_F0133E24;
        }
        else {
          puVar3 = unk_F0133E68;
        }
      }
      else {
        puVar3 = (undefined *)&_bfreelist;
      }
      *(uint **)(*(int *)((int)puVar3 + 0x10) + 0xc) = param_1;
      param_1[4] = *(uint *)((int)puVar3 + 0x10);
      *(uint **)((int)puVar3 + 0x10) = param_1;
      param_1[3] = (uint)puVar3;
      goto loc_F00249A8;
    }
    puVar3 = unk_F0133E68;
  }
  *(uint **)(*(int *)(puVar3 + 0xc) + 0x10) = param_1;
  param_1[3] = *(uint *)(puVar3 + 0xc);
  *(uint **)(puVar3 + 0xc) = param_1;
  param_1[4] = (uint)puVar3;
loc_F00249A8:
  *param_1 = *param_1 & 0xffbffe37;
  _splx(puVar1);
  return CONCAT44(param_2,param_1);
}

