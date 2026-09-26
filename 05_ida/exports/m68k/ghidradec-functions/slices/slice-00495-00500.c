/* GHIDRADEC_FUNCTION index=495 start=0x4017a26 */

void _bwrite(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  *param_1 = uVar1 & 0xfffffdf8;
  if ((uVar1 & 0x200) == 0) {
    *(int *)(_active_u + 0x196) = *(int *)(_active_u + 0x196) + 1;
  }
  if ((int)param_1[6] < (int)param_1[5]) {
                    /* WARNING: Subroutine does not return */
    _panic(&aBwrite);
  }
  (**(code **)(*(int *)(param_1[0x10] + 0x1c) + 0x54))(param_1);
  if ((uVar1 & 0x100) == 0) {
    _biowait(param_1);
    _brelse(param_1);
  }
  else if ((uVar1 & 0x200) != 0) {
    *(word *)((int)param_1 + 2) = *(word *)((int)param_1 + 2) | 0x80;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=496 start=0x4017aa6 */

void _bdwrite(int param_1)

{
  if ((*(byte *)(param_1 + 2) & 2) == 0) {
    *(int *)(_active_u + 0x196) = *(int *)(_active_u + 0x196) + 1;
  }
  *(word *)(param_1 + 2) = *(word *)(param_1 + 2) | 0x202;
  _brelse(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=497 start=0x4017ad2 */

void _bawrite(int param_1)

{
  *(word *)(param_1 + 2) = *(word *)(param_1 + 2) | 0x100;
  _bwrite(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=498 start=0x4017aec */

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
/* GHIDRADEC_FUNCTION index=499 start=0x4017c06 */

undefined4 _incore(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = param_2;
  if (param_2 < 0) {
    iVar2 = param_2 + 7;
  }
  iVar2 = (param_1 + (iVar2 >> 3) & 0xfU) * 0xc;
  puVar1 = *(undefined **)(_bufhash + iVar2 + 4);
  while( true ) {
    if (_bufhash + iVar2 == puVar1) {
      return 0;
    }
    if (((param_2 == *(int *)(puVar1 + 0x24)) && (param_1 == *(int *)(puVar1 + 0x40))) &&
       ((puVar1[1] & 1) == 0)) break;
    puVar1 = *(undefined **)(puVar1 + 4);
  }
  return 1;
}

