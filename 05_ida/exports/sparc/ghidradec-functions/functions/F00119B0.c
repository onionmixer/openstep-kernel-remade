
/* WARNING: Removing unreachable block (ram,0xf0011a38) */
/* WARNING: Removing unreachable block (ram,0xf0011edc) */
/* WARNING: Removing unreachable block (ram,0xf0011e84) */
/* WARNING: Removing unreachable block (ram,0xf0011e6c) */
/* WARNING: Removing unreachable block (ram,0xf0011ccc) */
/* WARNING: Removing unreachable block (ram,0xf0011ca4) */
/* WARNING: Removing unreachable block (ram,0xf0011c5c) */
/* WARNING: Removing unreachable block (ram,0xf0011c2c) */
/* WARNING: Removing unreachable block (ram,0xf0011c10) */
/* WARNING: Removing unreachable block (ram,0xf0011bb8) */
/* WARNING: Removing unreachable block (ram,0xf0011b44) */
/* WARNING: Removing unreachable block (ram,0xf00119f4) */
/* WARNING: Removing unreachable block (ram,0xf0011ba8) */
/* WARNING: Removing unreachable block (ram,0xf0011bd4) */
/* WARNING: Removing unreachable block (ram,0xf0011c24) */
/* WARNING: Removing unreachable block (ram,0xf0011c54) */
/* WARNING: Removing unreachable block (ram,0xf0011c74) */
/* WARNING: Removing unreachable block (ram,0xf0011cbc) */
/* WARNING: Removing unreachable block (ram,0xf0011e48) */
/* WARNING: Removing unreachable block (ram,0xf0011e74) */
/* WARNING: Removing unreachable block (ram,0xf0011e9c) */
/* WARNING: Removing unreachable block (ram,0xf0011a30) */
/* WARNING: Removing unreachable block (ram,0xf0011a68) */
/* WARNING: Removing unreachable block (ram,0xf00119d8) */

undefined8 _issig(int param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  int iVar6;
  uint uVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar8;
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
  iVar6 = *_active_u;
  if (_master_cpu != 0) {
    _panic(aIssigNotOnMast);
  }
  do {
    do {
    } while (*(int *)(iVar6 + 0x70) != 0);
    piVar5 = (int *)(iVar6 + 0x70);
    _simple_lock_try();
  } while (piVar5 == (int *)0x0);
  iVar2 = *(int *)(iVar6 + 0x74);
  do {
    if (iVar2 == 0) {
      if (*(int *)(iVar6 + 0x78) == 0) {
        param_2 = &_active_u;
loc_F0011AB8:
        do {
loc_F0011ABC:
          if (*(char *)(dword_F0133DDC + 0x48) != '\0') {
            *(uint *)(dword_F0133DDC + 0x4c) =
                 *(uint *)(dword_F0133DDC + 0x4c) |
                 1 << (*(char *)(dword_F0133DDC + 0x48) - 1U & 0x1f);
            *(undefined *)(dword_F0133DDC + 0x48) = 0;
          }
          iVar2 = dword_F0133DDC;
          uVar8 = (*(uint *)(dword_F0133DDC + 0x4c) | *(uint *)(iVar6 + 0x18)) &
                  ~*(uint *)(iVar6 + 0x1c);
          uVar7 = *(uint *)(iVar6 + 0x28) & 0x10;
          if (uVar7 == 0) {
            uVar8 = uVar8 & ~*(uint *)(iVar6 + 0x20);
          }
          if ((*(uint *)(iVar6 + 0x28) & 0x1000) != 0) {
            uVar8 = uVar8 & 0xffccffff;
          }
          if (uVar8 == 0) {
            *(undefined *)(iVar6 + 0x17) = 0;
            uVar8 = 0;
            *(undefined *)(dword_F0133DDC + 0x48) = 0;
            goto def_F0011DF0;
          }
          if ((param_1 != 0) && (uVar7 != 0)) goto loc_F0011F04;
          _ffs();
          cVar1 = (char)uVar8;
          uVar7 = 1 << (cVar1 - 1U & 0x1f);
          if ((uVar7 & 0x1ef8) == 0) {
            uVar3 = *(uint *)(iVar6 + 0x18);
          }
          else {
            *(char *)(iVar2 + 0x48) = cVar1;
            *(uint *)(dword_F0133DDC + 0x4c) = *(uint *)(dword_F0133DDC + 0x4c) & ~uVar7;
            uVar3 = *(uint *)(iVar6 + 0x18);
          }
          *(char *)(iVar6 + 0x17) = cVar1;
          *(uint *)(iVar6 + 0x18) = uVar3 & ~uVar7;
          if ((*(uint *)(iVar6 + 0x28) & 0x1010) != 0x10) goto loc_F0011D70;
          _psignal(*(undefined4 *)(iVar6 + 0x44),0x14);
          *(int *)(iVar6 + 0x6c) = _active_threads;
          _pcb_synch();
          piVar5 = *(int **)(iVar6 + 0x68);
          do {
            do {
            } while (*piVar5 != 0);
            piVar4 = piVar5;
            _simple_lock_try();
          } while (piVar4 == (int *)0x0);
          iVar2 = piVar5[0x11];
          piVar5[0x11] = iVar2 + 1;
          *piVar5 = 0;
          if (iVar2 + 1 == 1) {
            _task_hold(piVar5);
            *(undefined4 *)(iVar6 + 0x74) = 1;
            *(undefined4 *)(iVar6 + 0x70) = 0;
            _task_dowait(piVar5,1);
            _thread_hold(_active_threads);
          }
          else {
            *(undefined4 *)(iVar6 + 0x74) = 1;
            *(undefined4 *)(iVar6 + 0x70) = 0;
          }
          *(undefined *)(iVar6 + 0x13) = 6;
          *(uint *)(iVar6 + 0x28) = *(uint *)(iVar6 + 0x28) & 0xffffffdf;
          _wakeup(*(undefined4 *)(iVar6 + 0x44));
          _thread_block();
          do {
            do {
            } while (*(int *)(iVar6 + 0x70) != 0);
            piVar5 = (int *)(iVar6 + 0x70);
            _simple_lock_try();
          } while (piVar5 == (int *)0x0);
          *(undefined4 *)(iVar6 + 0x74) = 0;
          uVar8 = (uint)*(char *)(iVar6 + 0x17);
          if (0x20 < (int)uVar8) {
            _clear_wait(_active_threads,2,0);
            *(int *)(iVar6 + 0x78) = _active_threads;
            *(undefined4 *)(iVar6 + 0x70) = 0;
            _task_hold(*(undefined4 *)(_active_threads + 0xc));
            _task_dowait(*(undefined4 *)(_active_threads + 0xc),0);
                    /* WARNING: Subroutine does not return */
            _exit(uVar8 - 0x20);
          }
          if ((*(uint *)(_active_threads + 0x18c) & 3) != 0) goto loc_F0011F04;
          if ((*(uint *)(iVar6 + 0x28) & 0x10) != 0) goto loc_F0011D24;
          if ((uVar7 & 0x1ef8) == 0) {
            uVar8 = *(uint *)(iVar6 + 0x18);
loc_F0011D60:
            *(uint *)(iVar6 + 0x18) = uVar8 | uVar7;
          }
          else {
loc_F0011D4C:
            *(uint *)(dword_F0133DDC + 0x4c) = *(uint *)(dword_F0133DDC + 0x4c) | uVar7;
          }
        } while( true );
      }
      iVar2 = *(int *)(iVar6 + 0x78);
    }
    else {
      iVar2 = *(int *)(iVar6 + 0x78);
    }
    *(undefined4 *)(iVar6 + 0x70) = 0;
    if (iVar2 != 0) {
      uVar8 = 0;
      if (_active_threads == iVar2) goto locret_F0011F14;
      _thread_hold();
    }
    _thread_block();
    if ((*(uint *)(_active_threads + 0x18c) & 3) != 0) {
loc_F0011F08:
      uVar8 = 1;
locret_F0011F14:
      return CONCAT44(param_2,uVar8);
    }
    do {
      do {
      } while (*(int *)(iVar6 + 0x70) != 0);
      piVar5 = (int *)(iVar6 + 0x70);
      _simple_lock_try();
    } while (piVar5 == (int *)0x0);
    iVar2 = *(int *)(iVar6 + 0x74);
  } while( true );
loc_F0011D24:
  if (uVar8 == 0) goto loc_F0011ABC;
  uVar7 = 1 << (*(char *)(iVar6 + 0x17) - 1U & 0x1f);
  if ((*(uint *)(iVar6 + 0x1c) & uVar7) != 0) {
    if ((uVar7 & 0x1ef8) != 0) goto loc_F0011D4C;
    uVar8 = *(uint *)(iVar6 + 0x18);
    goto loc_F0011D60;
  }
loc_F0011D70:
  iVar2 = _active_u[uVar8 + 0xc];
  if (iVar2 == 1) {
    uVar7 = *(uint *)(iVar6 + 0x28);
  }
  else {
    if (iVar2 < 2) {
      if (iVar2 != 0) goto def_F0011DF0;
      if (*(sword *)(iVar6 + 0x32) == 0) {
        *(undefined *)(dword_F0133DDC + 0x48) = 0;
        *(uint *)(dword_F0133DDC + 0x4c) = *(uint *)(dword_F0133DDC + 0x4c) & ~uVar7;
        goto loc_F0011AB8;
      }
      switch(uVar8) {
      case :
      case :
      case :
      case :
      case :
        goto loc_F0011AB8;
      case :
        uVar7 = *(uint *)(iVar6 + 0x28);
        break;
      case :
      case :
      case :
        if (*(int *)(iVar6 + 0x44) == _init_proc) {
          _psignal(iVar6,9);
          goto loc_F0011ABC;
        }
        uVar7 = *(uint *)(iVar6 + 0x28);
        break;
      :
def_F0011DF0:
        *(undefined4 *)(iVar6 + 0x70) = 0;
        goto locret_F0011F14;
      }
      if ((uVar7 & 0x10) == 0) {
        _psignal(*(undefined4 *)(iVar6 + 0x44),0x14);
        _stop(iVar6);
        *(undefined4 *)(iVar6 + 0x74) = 1;
        *(undefined4 *)(iVar6 + 0x70) = 0;
        _thread_block();
        do {
          do {
          } while (*(int *)(iVar6 + 0x70) != 0);
          piVar5 = (int *)(iVar6 + 0x70);
          _simple_lock_try();
        } while (piVar5 == (int *)0x0);
        *(undefined4 *)(iVar6 + 0x74) = 0;
        if ((*(uint *)(_active_threads + 0x18c) & 3) != 0) {
loc_F0011F04:
          *(undefined4 *)(iVar6 + 0x70) = 0;
          goto loc_F0011F08;
        }
      }
      goto loc_F0011ABC;
    }
    if (iVar2 != 3) goto def_F0011DF0;
    uVar7 = *(uint *)(iVar6 + 0x28);
  }
  if ((uVar7 & 0x10) == 0) {
    _printf(&aIssig);
  }
  goto loc_F0011ABC;
}
