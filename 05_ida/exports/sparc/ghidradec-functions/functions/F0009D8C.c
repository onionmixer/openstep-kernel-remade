
/* WARNING: Removing unreachable block (ram,0xf0009f54) */
/* WARNING: Removing unreachable block (ram,0xf0009ee8) */
/* WARNING: Removing unreachable block (ram,0xf0009e6c) */
/* WARNING: Removing unreachable block (ram,0xf0009dc8) */
/* WARNING: Removing unreachable block (ram,0xf0009e50) */
/* WARNING: Removing unreachable block (ram,0xf0009eb8) */
/* WARNING: Removing unreachable block (ram,0xf0009f38) */
/* WARNING: Removing unreachable block (ram,0xf0009f60) */
/* WARNING: Removing unreachable block (ram,0xf0009d98) */

undefined8 _hardclock(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
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
  undefined auStackX_0 [92];
  
  iVar1 = _active_threads;
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
  iVar2 = 1;
  uVar4 = param_2;
  _clock_value();
  iVar5 = uVar4 - (uint)_last_hardclock;
  __udivdi3((iVar2 - (int)((qword)_last_hardclock >> 0x20)) - (uint)(uVar4 < (uint)_last_hardclock),
            iVar5,0,1000);
  _last_hardclock = CONCAT44(iVar2,uVar4);
  if ((param_2 & 0x40) == 0) {
    iVar2 = *_active_u;
    if ((iVar2 != 0) && (_active_u[0x96] != 0)) {
      *(uint *)(iVar2 + 0x28) = *(uint *)(iVar2 + 0x28) | 0x200000;
      _need_ast = _need_ast | 0x20;
    }
    if ((_active_u[0x85] != 0) || (_active_u[0x86] != 0)) {
      piVar3 = _active_u + 0x83;
      _itimerdecr(piVar3,iVar5);
      if (piVar3 == (int *)0x0) {
        _psignal(*_active_u,0x1a);
      }
    }
  }
  if ((*_active_u != 0) && ((*(uint *)(iVar1 + 0x4c) & 0x80) == 0)) {
    if ((_active_u[0x98] != 0x7fffffff) &&
       (_thread_read_times(iVar1,(undefined *)((int)register0x00000038 + -0x18),
                           (undefined *)((int)register0x00000038 + -0x10)),
       _active_u[0x98] <
       *(int *)((int)register0x00000038 + -0x10) + *(int *)((int)register0x00000038 + -0x18) + 1)) {
      _psignal(*_active_u,0x18);
      if (_active_u[0x98] < _active_u[0x99]) {
        _active_u[0x98] = _active_u[0x98] + 5;
      }
    }
    if ((_active_u[0x89] != 0) || (_active_u[0x8a] != 0)) {
      piVar3 = _active_u + 0x87;
      _itimerdecr(piVar3,iVar5);
      if (piVar3 == (int *)0x0) {
        _psignal(*_active_u,0x1b);
      }
    }
  }
  _gatherstats(param_1,param_2);
  return CONCAT44(param_2,param_1);
}
