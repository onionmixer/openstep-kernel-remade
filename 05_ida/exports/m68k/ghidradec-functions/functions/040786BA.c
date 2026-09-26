
undefined4
_od_cmd(word param_1,undefined2 param_2,undefined4 param_3,int param_4,int param_5,
       undefined *param_6,int param_7,int param_8,int param_9,int param_10)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar2 = (sword)(word)(((uint)param_1 << 0x18) >> 0x1b) * 0xda;
  iVar5 = *(int *)(DAT_40c3f32 + iVar2 + 0x44);
  puVar1 = (uint *)(DAT_40c3f32 + iVar2);
  if (param_10 == 0) {
    while ((*puVar1 & 8) != 0) {
      *puVar1 = *puVar1 | 0x40;
      _sleep(puVar1,0x14);
    }
  }
  *puVar1 = 9;
  *(undefined2 *)(DAT_40c3f32 + iVar2 + 0x6a) = param_2;
  if (param_9 == 0) {
    *(word *)(unk_40C3FA0 + iVar2) = *(word *)(unk_40C3FA0 + iVar2) | 0x80;
  }
  if ((param_7 != 0) && ((*(byte *)(param_7 + 7) & 1) != 0)) {
    DAT_40c3f32[iVar2 + 0x6c] = *(undefined *)(param_7 + 8);
    DAT_40c3f32[iVar2 + 0x6d] = *(undefined *)(param_7 + 9);
    *(word *)(unk_40C3FA0 + iVar2) = *(word *)(unk_40C3FA0 + iVar2) | 0x100;
  }
  *(int *)(DAT_40c3f32 + iVar2 + 0x3c) = param_10;
  *(word *)(DAT_40c3f32 + iVar2 + 0x1e) = param_1;
  *(undefined4 *)(DAT_40c3f32 + iVar2 + 0x24) = param_3;
  iVar5 = *(int *)(iVar5 + 0x5c);
  iVar5 = iVar5 * ((param_5 + -1 + iVar5) / iVar5);
  *(int *)(DAT_40c3f32 + iVar2 + 0x14) = iVar5;
  *(int *)(DAT_40c3f32 + iVar2 + 0x20) = param_4;
  if ((param_7 != 0) && (param_4 != 0)) {
    iVar3 = _useracc(param_4,iVar5,0);
    if (iVar3 == 0) {
      return 0xe;
    }
    *puVar1 = *puVar1 | 0x10;
    *(undefined4 *)(DAT_40c3f32 + iVar2 + 0x2c) =
         *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x34);
    *(word *)(*(int *)(DAT_40c3f32 + iVar2 + 0x2c) + 0x2a) =
         *(word *)(*(int *)(DAT_40c3f32 + iVar2 + 0x2c) + 0x2a) | 0x800;
    _vslock(param_4,iVar5);
  }
  _odstrategy(puVar1);
  if (_active_threads == 0) {
    iVar3 = 0;
    do {
      _delay(1);
      if ((*puVar1 & 2) != 0) break;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 10000000);
    if (iVar3 == 10000000) {
      dword_40C3DA8 = dword_40C3DA8 | 0x200000;
      _odintr(_od_ctrl);
    }
  }
  else {
    _biowait(puVar1);
  }
  *(word *)(unk_40C3FA0 + iVar2) = *(word *)(unk_40C3FA0 + iVar2) & 0xfe7f;
  if ((param_7 != 0) && (param_4 != 0)) {
    _vsunlock(param_4,iVar5,(*puVar1 & 1) != 0);
    *(word *)(*(int *)(DAT_40c3f32 + iVar2 + 0x2c) + 0x2a) =
         *(word *)(*(int *)(DAT_40c3f32 + iVar2 + 0x2c) + 0x2a) & 0xf7ff;
  }
  if ((param_10 == 0) && (*puVar1 = *puVar1 & 0xfffffff7, (*puVar1 & 0x40) != 0)) {
    _wakeup(puVar1);
  }
  if ((*puVar1 & 4) == 0) {
    if (param_8 != 0) {
      *(undefined4 *)(param_8 + 2) = *(undefined4 *)(DAT_40c3f32 + iVar2 + 0x28);
    }
    uVar4 = 0;
  }
  else {
    if (param_6 != (undefined *)0x0) {
      *param_6 = (char)*(undefined2 *)(DAT_40c3f32 + iVar2 + 0x1c);
    }
    uVar4 = 5;
  }
  return uVar4;
}
