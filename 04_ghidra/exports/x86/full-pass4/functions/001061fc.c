/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001061fc */

undefined4 _wait1(uint param_1,undefined4 *param_2,uint *param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  if (*(char *)(DAT_001e875c + 0x68) < '\0') {
    iVar4 = _thread_wait_result();
    if (iVar4 - 2U < 2) {
      if ((_active_u[0x50] >> (*(char *)(*_active_u + 0x17) - 1U & 0x1f) & 1U) != 0) {
        _unix_syscall_return(4);
      }
      *(undefined1 *)(DAT_001e875c + 0x69) = 2;
      _unix_syscall_return(0);
    }
    else {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0;
    }
  }
  else {
    *(undefined4 *)(DAT_001e875c + 0x88) = 0;
  }
  iVar4 = *_active_u;
  for (iVar1 = *(int *)(iVar4 + 0x48); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x4c)) {
    if ((param_4 == 0) || (param_4 == *(short *)(iVar1 + 0x30))) {
      *(int *)(DAT_001e875c + 0x88) = *(int *)(DAT_001e875c + 0x88) + 1;
      if (*(int *)(iVar1 + 0x68) == 0) {
        if ((*(int *)(iVar1 + 0x7c) == 0) || (iVar4 == *(int *)(iVar1 + 0x7c))) {
          *(int *)(DAT_001e875c + 0x60) = (int)*(short *)(iVar1 + 0x30);
          *param_3 = (uint)*(ushort *)(iVar1 + 0x34);
          *(undefined2 *)(iVar1 + 0x34) = 0;
          if (param_2 == (undefined4 *)0x0) goto LAB_001062ee;
          if (*(undefined4 **)(iVar1 + 0x38) != (undefined4 *)0x0) {
            puVar6 = *(undefined4 **)(iVar1 + 0x38);
            for (iVar4 = 0x12; iVar4 != 0; iVar4 = iVar4 + -1) {
              *param_2 = *puVar6;
              puVar6 = puVar6 + 1;
              param_2 = param_2 + 1;
            }
LAB_001062ee:
            if (*(int *)(iVar1 + 0x38) != 0) {
              _ruadd(_active_u + 0x6e,*(int *)(iVar1 + 0x38));
              _kfree(*(undefined4 *)(iVar1 + 0x38),0x48);
              *(undefined4 *)(iVar1 + 0x38) = 0;
            }
          }
          _leavepgrp(iVar1);
          _delete_posix_proc(iVar1);
          *(undefined1 *)(iVar1 + 0x13) = 0;
          *(undefined2 *)(iVar1 + 0x30) = 0;
          *(undefined2 *)(iVar1 + 0x32) = 0;
          iVar4 = *(int *)(iVar1 + 8);
          **(int **)(iVar1 + 0xc) = iVar4;
          if (iVar4 != 0) {
            *(undefined4 *)(*(int *)(iVar1 + 8) + 0xc) = *(undefined4 *)(iVar1 + 0xc);
          }
          *(int *)(iVar1 + 8) = _freeproc;
          _freeproc = iVar1;
          if (*(int *)(iVar1 + 0x50) != 0) {
            *(undefined4 *)(*(int *)(iVar1 + 0x50) + 0x4c) = *(undefined4 *)(iVar1 + 0x4c);
          }
          if (*(int *)(iVar1 + 0x4c) != 0) {
            *(undefined4 *)(*(int *)(iVar1 + 0x4c) + 0x50) = *(undefined4 *)(iVar1 + 0x50);
          }
          if (*(int *)(*(int *)(iVar1 + 0x44) + 0x48) == iVar1) {
            *(undefined4 *)(*(int *)(iVar1 + 0x44) + 0x48) = *(undefined4 *)(iVar1 + 0x4c);
          }
          *(undefined4 *)(iVar1 + 0x44) = 0;
          *(undefined4 *)(iVar1 + 0x50) = 0;
          *(undefined4 *)(iVar1 + 0x4c) = 0;
          *(undefined4 *)(iVar1 + 0x48) = 0;
          *(undefined4 *)(iVar1 + 0x18) = 0;
          *(undefined4 *)(iVar1 + 0x24) = 0;
          *(undefined4 *)(iVar1 + 0x20) = 0;
          *(undefined4 *)(iVar1 + 0x1c) = 0;
          *(undefined2 *)(iVar1 + 0x2e) = 0;
          *(undefined4 *)(iVar1 + 0x28) = 0;
          *(undefined1 *)(iVar1 + 0x17) = 0;
          return 0;
        }
      }
      else if ((((0 < *(int *)(*(int *)(iVar1 + 0x68) + 0x44)) &&
                (*(char *)(iVar1 + 0x13) == '\x06')) &&
               (uVar2 = *(uint *)(iVar1 + 0x28), (uVar2 & 0x20) == 0)) &&
              ((((uVar2 & 0x10) != 0 || ((param_1 & 2) != 0)) &&
               ((*(int *)(iVar1 + 0x7c) == 0 || (iVar4 == *(int *)(iVar1 + 0x7c))))))) {
        *(uint *)(iVar1 + 0x28) = uVar2 | 0x20;
        *(int *)(DAT_001e875c + 0x60) = (int)*(short *)(iVar1 + 0x30);
        cVar3 = *(char *)(iVar1 + 0x17);
        if (cVar3 != '\0') goto LAB_001064a8;
        iVar4 = *(int *)(iVar1 + 0x3c);
        goto LAB_001064ab;
      }
    }
  }
  iVar4 = *(int *)(iVar4 + 0x80);
  if (iVar4 != 0) {
    *(int *)(DAT_001e875c + 0x88) = *(int *)(DAT_001e875c + 0x88) + 1;
    if (*(int *)(iVar4 + 0x68) == 0) {
      *(undefined4 *)(iVar4 + 0x7c) = 0;
      *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xffffffef;
      _wakeup(*(undefined4 *)(iVar4 + 0x44));
      return 0;
    }
    if ((((0 < *(int *)(*(int *)(iVar4 + 0x68) + 0x44)) && (*(char *)(iVar4 + 0x13) == '\x06')) &&
        (uVar2 = *(uint *)(iVar4 + 0x28), (uVar2 & 0x20) == 0)) &&
       (((uVar2 & 0x10) != 0 || ((param_1 & 2) != 0)))) {
      *(uint *)(iVar4 + 0x28) = uVar2 | 0x20;
      *(int *)(DAT_001e875c + 0x60) = (int)*(short *)(iVar4 + 0x30);
      cVar3 = *(char *)(iVar4 + 0x17);
      if (cVar3 == '\0') {
        iVar4 = *(int *)(iVar4 + 0x3c);
      }
      else {
LAB_001064a8:
        iVar4 = (int)cVar3;
      }
LAB_001064ab:
      *param_3 = iVar4 << 8 | 0x7f;
      return 0;
    }
  }
  if (*(int *)(DAT_001e875c + 0x88) == 0) {
    uVar5 = 10;
  }
  else if ((param_1 & 1) == 0) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 0xff;
    uVar5 = _sleep_with_continuation(*_active_u,0x1e,param_5);
  }
  else {
    *(undefined4 *)(DAT_001e875c + 0x60) = 0;
    uVar5 = 0;
  }
  return uVar5;
}

