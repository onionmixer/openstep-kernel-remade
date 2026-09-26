
/* WARNING: Removing unreachable block (ram,0xf003d7f8) */
/* WARNING: Removing unreachable block (ram,0xf003d7c4) */
/* WARNING: Removing unreachable block (ram,0xf003d7a8) */
/* WARNING: Removing unreachable block (ram,0xf003d7b8) */
/* WARNING: Removing unreachable block (ram,0xf003d7d0) */
/* WARNING: Removing unreachable block (ram,0xf003d808) */
/* WARNING: Removing unreachable block (ram,0xf003d794) */

undefined8 _rlock_timeout(int param_1,undefined4 param_2)

{
  word wVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  wVar1 = *(word *)(param_1 + 0x60);
  if ((wVar1 & 1) != 0) {
    iVar4 = *(int *)(param_1 + 0x68);
    while( true ) {
      if (iVar4 == _active_threads) break;
      uVar5 = 1;
      if ((wVar1 & 0x20) != 0) {
        _rlockretimeout._0_4_ = _rlockretimeout._0_4_ + 1;
        goto locret_F003D848;
      }
      uVar2 = wVar1 | 2;
      *(sword *)(param_1 + 0x60) = (sword)uVar2;
      _splusclock();
      uVar5 = param_2;
      umul(param_2,_hz);
      _timeout(sub_F003D710,param_1,uVar5);
      _sleep(param_1,10);
      pcVar3 = sub_F003D710;
      _untimeout(sub_F003D710,param_1);
      if (pcVar3 == (code *)0x0) {
        _rlocktimeout._0_4_ = _rlocktimeout._0_4_ + 1;
        *(word *)(param_1 + 0x60) = *(word *)(param_1 + 0x60) | 0x20;
        _splx(uVar2);
        uVar5 = 1;
        goto locret_F003D848;
      }
      _splx(uVar2);
      wVar1 = *(word *)(param_1 + 0x60);
      if ((wVar1 & 1) == 0) break;
      iVar4 = *(int *)(param_1 + 0x68);
    }
  }
  uVar5 = 0;
  *(int *)(param_1 + 0x68) = _active_threads;
  *(sword *)(param_1 + 0x6c) = *(sword *)(param_1 + 0x6c) + 1;
  *(word *)(param_1 + 0x60) = *(word *)(param_1 + 0x60) | 1;
locret_F003D848:
  return CONCAT44(param_2,uVar5);
}

