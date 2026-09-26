
/* WARNING: Removing unreachable block (ram,0xf0074f70) */
/* WARNING: Removing unreachable block (ram,0xf0074f30) */
/* WARNING: Removing unreachable block (ram,0xf0074edc) */
/* WARNING: Removing unreachable block (ram,0xf0074e88) */
/* WARNING: Removing unreachable block (ram,0xf0074e30) */
/* WARNING: Removing unreachable block (ram,0xf0074e1c) */
/* WARNING: Removing unreachable block (ram,0xf0074ddc) */
/* WARNING: Removing unreachable block (ram,0xf0074dbc) */
/* WARNING: Removing unreachable block (ram,0xf0074f84) */
/* WARNING: Removing unreachable block (ram,0xf0074d34) */
/* WARNING: Removing unreachable block (ram,0xf0074c70) */
/* WARNING: Removing unreachable block (ram,0xf0074ba0) */
/* WARNING: Removing unreachable block (ram,0xf0074bf8) */
/* WARNING: Removing unreachable block (ram,0xf0074cb8) */
/* WARNING: Removing unreachable block (ram,0xf0074c9c) */
/* WARNING: Removing unreachable block (ram,0xf0074b78) */
/* WARNING: Removing unreachable block (ram,0xf0074c20) */
/* WARNING: Removing unreachable block (ram,0xf0074bc8) */
/* WARNING: Removing unreachable block (ram,0xf0074c80) */
/* WARNING: Removing unreachable block (ram,0xf0074f7c) */
/* WARNING: Removing unreachable block (ram,0xf0074d78) */
/* WARNING: Removing unreachable block (ram,0xf0074dc8) */
/* WARNING: Removing unreachable block (ram,0xf0074df8) */
/* WARNING: Removing unreachable block (ram,0xf0074e28) */
/* WARNING: Removing unreachable block (ram,0xf0074e48) */
/* WARNING: Removing unreachable block (ram,0xf0074ec0) */
/* WARNING: Removing unreachable block (ram,0xf0074f14) */
/* WARNING: Removing unreachable block (ram,0xf0074f58) */
/* WARNING: Removing unreachable block (ram,0xf0074f98) */
/* WARNING: Removing unreachable block (ram,0xf0074b64) */

undefined8 _thread_halt(uint param_1,int param_2)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  code *pcVar5;
  code *pcVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  uVar7 = _active_threads;
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
  pcVar5 = (code *)DAT_f0134000;
  if (param_1 == _active_threads) {
    puVar1 = aThreadHaltTryi;
    _panic(aThreadHaltTryi);
    pcVar5 = (code *)puVar1;
  }
  if (param_2 == 0) {
    _splusclock();
    if (param_1 < uVar7) {
      do {
        do {
        } while (*(int *)(param_1 + 0x20) != 0);
        piVar4 = (int *)(param_1 + 0x20);
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      do {
        do {
        } while (*(int *)(uVar7 + 0x20) != 0);
        piVar4 = (int *)(uVar7 + 0x20);
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      uVar2 = *(uint *)(param_1 + 0x4c);
    }
    else {
      do {
        do {
        } while (*(int *)(uVar7 + 0x20) != 0);
        piVar4 = (int *)(uVar7 + 0x20);
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      do {
        do {
        } while (*(int *)(param_1 + 0x20) != 0);
        piVar4 = (int *)(param_1 + 0x20);
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      uVar2 = *(uint *)(param_1 + 0x4c);
    }
    if ((uVar2 & 0x10) == 0) {
      if ((*(uint *)(uVar7 + 0x18c) & 1) != 0) {
        _thread_wakeup_prim(uVar7 + 0x48,0,2);
        *(undefined4 *)(param_1 + 0x20) = 0;
        *(undefined4 *)(uVar7 + 0x20) = 0;
        _splx(pcVar5);
        uVar7 = 5;
        goto locret_F0074FA0;
      }
      *(undefined4 *)(uVar7 + 0x20) = 0;
      iVar3 = *(int *)(param_1 + 0x40);
loc_F0074CF4:
      uVar7 = *(uint *)(param_1 + 0x4c);
      *(int *)(param_1 + 0x40) = iVar3 + 1;
      *(uint *)(param_1 + 0x4c) = uVar7 | 2;
      if ((*(uint *)(param_1 + 0x18c) & 1) == 0) {
loc_F0074DAC:
        uVar7 = *(uint *)(param_1 + 0x18c);
      }
      else {
        if ((uVar7 & 0x10) == 0) {
          *(undefined4 *)(param_1 + 0x48) = 1;
          while (_thread_sleep(param_1 + 0x48,param_1 + 0x20,1),
                (*(uint *)(param_1 + 0x4c) & 0x10) == 0) {
            if ((*(int *)(_active_threads + 0x44) != 0) && (param_2 == 0)) {
              _splx(pcVar5);
              _thread_release(param_1);
              uVar7 = 5;
              goto locret_F0074FA0;
            }
            do {
              do {
              } while (*(int *)(param_1 + 0x20) != 0);
              piVar4 = (int *)(param_1 + 0x20);
              _simple_lock_try();
            } while (piVar4 == (int *)0x0);
            uVar7 = *(uint *)(param_1 + 0x18c);
            if ((uVar7 & 1) == 0) goto loc_F0074DB4;
            if ((*(uint *)(param_1 + 0x4c) & 0x10) != 0) goto loc_F0074DAC;
            *(undefined4 *)(param_1 + 0x48) = 1;
          }
          goto loc_F0074F98;
        }
        uVar7 = *(uint *)(param_1 + 0x18c);
      }
loc_F0074DB4:
      *(uint *)(param_1 + 0x18c) = uVar7 | 1;
      while( true ) {
        *(undefined4 *)(param_1 + 0x20) = 0;
        _splx(pcVar5);
        uVar7 = param_1;
        _thread_dowait(param_1,param_2);
        if (uVar7 != 0) break;
        _clear_wait(param_1,2,1);
        if ((*(uint *)(param_1 + 0x4c) & 0x10) != 0) {
          uVar7 = 0;
          goto locret_F0074FA0;
        }
        pcVar6 = *(code **)(param_1 + 0x34);
        if ((pcVar6 == _mach_msg_continue) || (pcVar6 == _mach_msg_receive_continue)) {
          uVar7 = param_1;
          _mach_msg_interrupt();
          pcVar5 = (code *)0xf009bc00;
          if (uVar7 == 0) {
            pcVar6 = *(code **)(param_1 + 0x34);
            goto loc_F0074EA0;
          }
loc_F0074EC0:
          _splusclock();
          do {
            do {
            } while (*(int *)(param_1 + 0x20) != 0);
            piVar4 = (int *)(param_1 + 0x20);
            _simple_lock_try();
          } while (piVar4 == (int *)0x0);
          *(undefined4 *)(param_1 + 0x20) = 0;
          *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x10;
          *(uint *)(param_1 + 0x18c) = *(uint *)(param_1 + 0x18c) & 0xfffffffe;
          goto loc_F0074F98;
        }
loc_F0074EA0:
        pcVar5 = (code *)0xf009bc00;
        if ((pcVar6 == _thread_exception_return) ||
           (pcVar5 = _thread_bootstrap_return, pcVar6 == _thread_bootstrap_return))
        goto loc_F0074EC0;
        _splusclock();
        do {
          do {
          } while (*(int *)(param_1 + 0x20) != 0);
          piVar4 = (int *)(param_1 + 0x20);
          _simple_lock_try();
        } while (piVar4 == (int *)0x0);
        if ((*(uint *)(param_1 + 0x4c) & 0xf) != 2) {
          _panic(aThreadHalt);
        }
        *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0xc;
        _thread_setrun(param_1,0);
      }
      uVar2 = uVar7;
      _splusclock();
      do {
        do {
        } while (*(int *)(param_1 + 0x20) != 0);
        piVar4 = (int *)(param_1 + 0x20);
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      *(uint *)(param_1 + 0x18c) = *(uint *)(param_1 + 0x18c) & 0xfffffffe;
      _thread_wakeup_prim(param_1 + 0x48,0,2);
      *(undefined4 *)(param_1 + 0x20) = 0;
      _splx(uVar2);
      _thread_release(param_1);
      goto locret_F0074FA0;
    }
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
    *(undefined4 *)(uVar7 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  else {
    _splusclock();
    do {
      do {
      } while (*(int *)(param_1 + 0x20) != 0);
      piVar4 = (int *)(param_1 + 0x20);
      _simple_lock_try();
    } while (piVar4 == (int *)0x0);
    if ((*(uint *)(param_1 + 0x4c) & 0x10) == 0) {
      iVar3 = *(int *)(param_1 + 0x40);
      goto loc_F0074CF4;
    }
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  }
loc_F0074F98:
  uVar7 = 0;
  _splx(pcVar5);
locret_F0074FA0:
  return CONCAT44(param_2,uVar7);
}

