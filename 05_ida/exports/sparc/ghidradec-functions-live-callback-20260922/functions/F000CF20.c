
/* WARNING: Removing unreachable block (ram,0xf000d1f8) */
/* WARNING: Removing unreachable block (ram,0xf000d084) */
/* WARNING: Removing unreachable block (ram,0xf000d06c) */
/* WARNING: Removing unreachable block (ram,0xf000cf8c) */
/* WARNING: Removing unreachable block (ram,0xf000cf78) */
/* WARNING: Removing unreachable block (ram,0xf000d050) */
/* WARNING: Removing unreachable block (ram,0xf000d078) */
/* WARNING: Removing unreachable block (ram,0xf000d08c) */
/* WARNING: Removing unreachable block (ram,0xf000d2cc) */
/* WARNING: Removing unreachable block (ram,0xf000cf3c) */

undefined8 _wait1(uint param_1,int param_2,uint *param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  int iVar4;
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
  bool bVar6;
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
  iVar1 = (int)*(char *)(dword_F0133DDC + 0x38);
  if (iVar1 < 0) {
    _thread_wait_result();
    if (iVar1 - 2U < 2) {
      if ((_active_u[0x4f] >> (*(char *)(*_active_u + 0x17) - 1U & 0x1f) & 1U) != 0) {
        _unix_syscall_return(4);
      }
      *(undefined *)(dword_F0133DDC + 0x39) = 2;
      _unix_syscall_return(0);
    }
    else {
      *(undefined *)(dword_F0133DDC + 0x38) = 0;
    }
  }
  else {
    *(undefined4 *)(dword_F0133DDC + 0x58) = 0;
  }
  iVar1 = *_active_u;
  iVar4 = *(int *)(iVar1 + 0x48);
  if (iVar4 == 0) {
    iVar4 = *(int *)(iVar1 + 0x80);
  }
  else {
    do {
      if ((param_4 == 0) || (param_4 == *(sword *)(iVar4 + 0x30))) {
        *(int *)(dword_F0133DDC + 0x58) = *(int *)(dword_F0133DDC + 0x58) + 1;
        if (*(int *)(iVar4 + 0x68) == 0) {
          if ((*(int *)(iVar4 + 0x7c) == 0) || (*(int *)(iVar4 + 0x7c) == iVar1)) {
            *(int *)(dword_F0133DDC + 0x30) = (int)*(sword *)(iVar4 + 0x30);
            *param_3 = (uint)*(word *)(iVar4 + 0x34);
            *(undefined2 *)(iVar4 + 0x34) = 0;
            if (param_2 == 0) {
loc_F000D058:
              bVar6 = *(int *)(iVar4 + 0x38) == 0;
            }
            else {
              bVar6 = *(int *)(iVar4 + 0x38) == 0;
              if (!bVar6) {
                _memcpy(param_2,*(int *)(iVar4 + 0x38),0x48);
                goto loc_F000D058;
              }
            }
            if (!bVar6) {
              _ruadd(_active_u + 0x6d);
              _kfree(*(undefined4 *)(iVar4 + 0x38),0x48);
              *(undefined4 *)(iVar4 + 0x38) = 0;
            }
            _leavepgrp(iVar4);
            _delete_posix_proc(iVar4);
            *(undefined *)(iVar4 + 0x13) = 0;
            *(undefined2 *)(iVar4 + 0x30) = 0;
            iVar1 = *(int *)(iVar4 + 8);
            *(undefined2 *)(iVar4 + 0x32) = 0;
            **(int **)(iVar4 + 0xc) = iVar1;
            if (iVar1 != 0) {
              *(undefined4 *)(*(int *)(iVar4 + 8) + 0xc) = *(undefined4 *)(iVar4 + 0xc);
            }
            *(int *)(iVar4 + 8) = _freeproc;
            _freeproc = iVar4;
            if (*(int *)(iVar4 + 0x50) != 0) {
              *(undefined4 *)(*(int *)(iVar4 + 0x50) + 0x4c) = *(undefined4 *)(iVar4 + 0x4c);
            }
            if (*(int *)(iVar4 + 0x4c) == 0) {
              iVar1 = *(int *)(iVar4 + 0x44);
            }
            else {
              *(undefined4 *)(*(int *)(iVar4 + 0x4c) + 0x50) = *(undefined4 *)(iVar4 + 0x50);
              iVar1 = *(int *)(iVar4 + 0x44);
            }
            if (*(int *)(iVar1 + 0x48) == iVar4) {
              *(undefined4 *)(iVar1 + 0x48) = *(undefined4 *)(iVar4 + 0x4c);
              *(undefined4 *)(iVar4 + 0x44) = 0;
            }
            else {
              *(undefined4 *)(iVar4 + 0x44) = 0;
            }
            *(undefined4 *)(iVar4 + 0x50) = 0;
            *(undefined4 *)(iVar4 + 0x4c) = 0;
            *(undefined4 *)(iVar4 + 0x48) = 0;
            *(undefined4 *)(iVar4 + 0x18) = 0;
            *(undefined4 *)(iVar4 + 0x24) = 0;
            *(undefined4 *)(iVar4 + 0x20) = 0;
            *(undefined4 *)(iVar4 + 0x1c) = 0;
            *(undefined2 *)(iVar4 + 0x2e) = 0;
            *(undefined4 *)(iVar4 + 0x28) = 0;
            *(undefined *)(iVar4 + 0x17) = 0;
            uVar5 = 0;
            goto locret_F000D2D4;
          }
          iVar4 = *(int *)(iVar4 + 0x4c);
        }
        else if (*(int *)(*(int *)(iVar4 + 0x68) + 0x44) < 1) {
          iVar4 = *(int *)(iVar4 + 0x4c);
        }
        else if (*(char *)(iVar4 + 0x13) == '\x06') {
          uVar2 = *(uint *)(iVar4 + 0x28);
          if ((uVar2 & 0x20) == 0) {
            if ((uVar2 & 0x10) == 0) {
              if ((param_1 & 2) == 0) {
                iVar4 = *(int *)(iVar4 + 0x4c);
                goto loc_F000D1A8;
              }
              iVar3 = *(int *)(iVar4 + 0x7c);
            }
            else {
              iVar3 = *(int *)(iVar4 + 0x7c);
            }
            if (iVar3 == 0) goto loc_F000D24C;
            if (iVar3 == iVar1) {
              uVar2 = uVar2 | 0x20;
              goto loc_F000D250;
            }
            iVar4 = *(int *)(iVar4 + 0x4c);
          }
          else {
            iVar4 = *(int *)(iVar4 + 0x4c);
          }
        }
        else {
          iVar4 = *(int *)(iVar4 + 0x4c);
        }
      }
      else {
        iVar4 = *(int *)(iVar4 + 0x4c);
      }
loc_F000D1A8:
    } while (iVar4 != 0);
    iVar4 = *(int *)(iVar1 + 0x80);
  }
  if (iVar4 == 0) {
loc_F000D28C:
    iVar1 = *(int *)(dword_F0133DDC + 0x58);
  }
  else {
    *(int *)(dword_F0133DDC + 0x58) = *(int *)(dword_F0133DDC + 0x58) + 1;
    if (*(int *)(iVar4 + 0x68) == 0) {
      *(undefined4 *)(iVar4 + 0x7c) = 0;
      *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xffffffef;
      _wakeup(*(undefined4 *)(iVar4 + 0x44));
      uVar5 = 0;
      goto locret_F000D2D4;
    }
    if ((*(int *)(*(int *)(iVar4 + 0x68) + 0x44) < 1) || (*(char *)(iVar4 + 0x13) != '\x06'))
    goto loc_F000D28C;
    uVar2 = *(uint *)(iVar4 + 0x28);
    if ((uVar2 & 0x20) == 0) {
      if ((uVar2 & 0x10) == 0) {
        if ((param_1 & 2) == 0) {
          iVar1 = *(int *)(dword_F0133DDC + 0x58);
          goto loc_F000D290;
        }
loc_F000D24C:
        uVar2 = uVar2 | 0x20;
      }
      else {
        uVar2 = uVar2 | 0x20;
      }
loc_F000D250:
      *(uint *)(iVar4 + 0x28) = uVar2;
      *(int *)(dword_F0133DDC + 0x30) = (int)*(sword *)(iVar4 + 0x30);
      iVar1 = (int)*(char *)(iVar4 + 0x17);
      if (iVar1 == 0) {
        iVar1 = *(int *)(iVar4 + 0x3c);
      }
      *param_3 = iVar1 << 8 | 0x7f;
      uVar5 = 0;
      goto locret_F000D2D4;
    }
    iVar1 = *(int *)(dword_F0133DDC + 0x58);
  }
loc_F000D290:
  if (iVar1 == 0) {
    uVar5 = 10;
  }
  else {
    uVar5 = 0;
    if ((param_1 & 1) == 0) {
      *(undefined *)(dword_F0133DDC + 0x38) = 0xff;
      _sleep_with_continuation(*_active_u,0x1e,param_5);
    }
    else {
      *(undefined4 *)(dword_F0133DDC + 0x30) = 0;
    }
  }
locret_F000D2D4:
  return CONCAT44(param_2,uVar5);
}

