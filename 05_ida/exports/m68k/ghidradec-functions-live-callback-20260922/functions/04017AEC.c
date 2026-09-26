
undefined4 _brelse(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
  
  if ((*param_1 & 0x40) != 0) {
    _wakeup(param_1);
  }
  if ((_bfreelist & 0x40) != 0) {
    _bfreelist = _bfreelist & 0xffffffbf;
    _wakeup(&_bfreelist);
  }
  if ((*param_1 & 0x400200) == 0x400000) {
    *param_1 = *param_1 | 0x10000;
  }
  uVar2 = *param_1;
  if ((uVar2 & 4) != 0) {
    if ((uVar2 & 0x20000) == 0) {
      uVar2 = sub_4018584(param_1);
    }
    else {
      *param_1 = uVar2 & 0xfffffffb;
    }
  }
  uVar2 = uVar2 & 0xffff0000;
  if ((int)param_1[6] < 1) {
    dword_40B58B0[4] = (uint)param_1;
    param_1[3] = (uint)dword_40B58B0;
    dword_40B58B0 = param_1;
    param_1[4] = (uint)&DAT_40b58a4;
  }
  else {
    uVar1 = *param_1;
    uVar2 = uVar1 & 0x10004;
    if (uVar2 == 0) {
      if ((uVar1 & 0x20000) == 0) {
        puVar3 = unk_40B581C;
        if ((char)uVar1 < '\0') {
          puVar3 = (undefined *)&unk_40B5860;
        }
      }
      else {
        puVar3 = (undefined *)&_bfreelist;
      }
      *(uint **)(*(int *)((int)puVar3 + 0x10) + 0xc) = param_1;
      param_1[4] = *(uint *)((int)puVar3 + 0x10);
      *(uint **)((int)puVar3 + 0x10) = param_1;
      param_1[3] = (uint)puVar3;
    }
    else {
      dword_40B586C[4] = (uint)param_1;
      param_1[3] = (uint)dword_40B586C;
      dword_40B586C = param_1;
      param_1[4] = (uint)&unk_40B5860;
    }
  }
  uVar1 = *param_1 & 0xffbffe37;
  *param_1 = uVar1;
  return CONCAT22((sword)(uVar2 >> 0x10),(word)(byte)(((int)uVar1 < 0) << 3 | (uVar1 == 0) << 2));
}

