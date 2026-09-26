
void _hardclock(undefined4 param_1,uint param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined8 uVar6;
  int aiStack_20 [2];
  int aiStack_18 [2];
  uint uStack_10;
  int iStack_c;
  
  iVar3 = _active_threads;
  uVar6 = _clock_value(1);
  iStack_c = (uint)uVar6 - _last_hardclock._4_4_;
  uVar5 = (int)((qword)uVar6 >> 0x20) -
          ((uint)((uint)uVar6 < _last_hardclock._4_4_) + _last_hardclock._0_4_);
  uStack_10 = uVar5 / 1000;
  uVar4 = (undefined4)(CONCAT44(uVar5 % 1000,iStack_c) / 1000);
  _last_hardclock = uVar6;
  if ((param_2 & 0x2000) == 0) {
    if ((*_active_u != 0) && (_active_u[0x94] != 0)) {
      pbVar1 = (byte *)(*_active_u + 0x29);
      *pbVar1 = *pbVar1 | 0x20;
      _need_ast = _need_ast | 0x20;
      if (_need_ast != 0) {
        pbVar1 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
        *pbVar1 = *pbVar1 | 0x10;
      }
    }
    if ((*(int *)((int)_active_u + 0x20e) != 0) || (*(int *)((int)_active_u + 0x212) != 0)) {
      iVar2 = _itimerdecr((int)_active_u + 0x206,uVar4);
      if (iVar2 == 0) {
        _psignal(*_active_u,0x1a);
      }
    }
  }
  if ((*_active_u != 0) && (-1 < *(char *)(iVar3 + 0x4b))) {
    if (*(int *)((int)_active_u + 0x256) != 0x7fffffff) {
      _thread_read_times(iVar3,aiStack_18,aiStack_20);
      if (*(int *)((int)_active_u + 0x256) < aiStack_18[0] + aiStack_20[0] + 1) {
        _psignal(*_active_u,0x18);
        if (*(int *)((int)_active_u + 0x256) < *(int *)((int)_active_u + 0x25a)) {
          *(int *)((int)_active_u + 0x256) = *(int *)((int)_active_u + 0x256) + 5;
        }
      }
    }
    if ((*(int *)((int)_active_u + 0x21e) != 0) || (*(int *)((int)_active_u + 0x222) != 0)) {
      iVar3 = _itimerdecr((int)_active_u + 0x216,uVar4);
      if (iVar3 == 0) {
        _psignal(*_active_u,0x1b);
      }
    }
  }
  _gatherstats(param_1,param_2);
  return;
}
