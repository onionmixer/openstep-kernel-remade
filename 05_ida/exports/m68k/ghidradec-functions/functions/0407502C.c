
undefined4 _odopen(word param_1,uint param_2)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  word wVar7;
  undefined4 uVar6;
  
  uVar3 = (param_1 & 0xff) >> 3;
  uVar2 = param_1 & 7;
  iVar4 = uVar3 * 0xda;
  if (uVar3 == 0x1f) {
loc_40751CC:
    uVar6 = 0;
  }
  else {
    if ((uVar3 < 0x20) && ((dword_40C3DA8 & 0x400000) != 0)) {
      if ((unk_40C3FA0[iVar4 + 1] & 0x20) != 0) {
        do {
          *(word *)(unk_40C3FA0 + iVar4) = *(word *)(unk_40C3FA0 + iVar4) | 0x10;
          _sleep(unk_40C3FA0 + iVar4,0x14);
        } while ((unk_40C3FA0[iVar4 + 1] & 0x20) != 0);
      }
      if (*(sword *)(unk_40C3FA0 + iVar4) < 0) {
loc_4075126:
        if (((param_2 & 4) != 0) && ((unk_40C3FA0[iVar4] & 0x20) == 0)) {
          return 0x23;
        }
        pcVar1 = *(code **)(_cdevsw + (uint)(param_1 >> 8) * 0x2c);
        iVar5 = 0x100;
        if (pcVar1 == _odopen) {
          iVar5 = 1;
        }
        *(word *)(DAT_40c3f76 + iVar4 + 0x22) =
             *(word *)(DAT_40c3f76 + iVar4 + 0x22) | (word)(iVar5 << uVar2);
        *(undefined2 *)(DAT_40c3f76 + iVar4 + 0x20) =
             *(undefined2 *)(*(int *)(_active_u + 0x1a) + 6);
        if ((0 < *(int *)(*(int *)(DAT_40c3f76 + iVar4) + uVar2 * 0x2e + 0xc2)) ||
           (*(code **)(_cdevsw + (uint)(param_1 >> 8) * 0x2c) == _odopen)) goto loc_40751CC;
        if (pcVar1 != _odopen) {
          wVar7 = ~(word)(0x100 << uVar2);
        }
        else {
          wVar7 = (word)(-2 << uVar2) | (word)(0xfffffffe >> 0x20 - uVar2);
        }
        *(word *)(DAT_40c3f76 + iVar4 + 0x22) = *(word *)(DAT_40c3f76 + iVar4 + 0x22) & wVar7;
      }
      else {
        if ((param_2 & 4) != 0) {
          return 0x23;
        }
        _od_empty = uVar3 + 1;
        iVar5 = _od_make_empty();
        if (-1 < iVar5) {
          if ((_od_requested == 0) && (_od_spinup == 0)) {
            _od_requested = 1;
            _wakeup(&_od_requested);
          }
          while (0 < _od_empty) {
            _sleep(&_od_empty,0x14);
          }
          if (-1 < _od_empty) goto loc_4075126;
        }
      }
    }
    uVar6 = 6;
  }
  return uVar6;
}
