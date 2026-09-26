/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00106508 */

undefined4 _waitpgrp(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  int iVar5;
  int local_10;
  uint local_8;
  
  piVar1 = *(int **)(DAT_001e875c + 0x24);
  local_10 = 0;
  while( true ) {
    for (iVar5 = *(int *)(*_active_u + 0x48); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x4c)) {
      if (*piVar1 == (int)*(short *)(iVar5 + 0x2e)) {
        local_10 = local_10 + 1;
        if (*(int *)(iVar5 + 0x68) == 0) {
          *(int *)(DAT_001e875c + 0x60) = (int)*(short *)(iVar5 + 0x30);
          uVar4 = _copyout(iVar5 + 0x34,piVar1[1],4);
          *(undefined1 *)(DAT_001e875c + 0x68) = uVar4;
          if (*(char *)(DAT_001e875c + 0x68) != '\0') {
            return 0;
          }
          *(undefined2 *)(iVar5 + 0x34) = 0;
          if (*(int *)(iVar5 + 0x38) != 0) {
            _ruadd(_active_u + 0x6e,*(int *)(iVar5 + 0x38));
            _kfree(*(undefined4 *)(iVar5 + 0x38),0x48);
            *(undefined4 *)(iVar5 + 0x38) = 0;
          }
          _leavepgrp(iVar5);
          _delete_posix_proc(iVar5);
          *(undefined1 *)(iVar5 + 0x13) = 0;
          *(undefined2 *)(iVar5 + 0x30) = 0;
          *(undefined2 *)(iVar5 + 0x32) = 0;
          iVar2 = *(int *)(iVar5 + 8);
          **(int **)(iVar5 + 0xc) = iVar2;
          if (iVar2 != 0) {
            *(undefined4 *)(*(int *)(iVar5 + 8) + 0xc) = *(undefined4 *)(iVar5 + 0xc);
          }
          *(int *)(iVar5 + 8) = _freeproc;
          _freeproc = iVar5;
          if (*(int *)(iVar5 + 0x50) != 0) {
            *(undefined4 *)(*(int *)(iVar5 + 0x50) + 0x4c) = *(undefined4 *)(iVar5 + 0x4c);
          }
          if (*(int *)(iVar5 + 0x4c) != 0) {
            *(undefined4 *)(*(int *)(iVar5 + 0x4c) + 0x50) = *(undefined4 *)(iVar5 + 0x50);
          }
          if (*(int *)(*(int *)(iVar5 + 0x44) + 0x48) == iVar5) {
            *(undefined4 *)(*(int *)(iVar5 + 0x44) + 0x48) = *(undefined4 *)(iVar5 + 0x4c);
          }
          *(undefined4 *)(iVar5 + 0x44) = 0;
          *(undefined4 *)(iVar5 + 0x50) = 0;
          *(undefined4 *)(iVar5 + 0x4c) = 0;
          *(undefined4 *)(iVar5 + 0x48) = 0;
          *(undefined4 *)(iVar5 + 0x18) = 0;
          *(undefined4 *)(iVar5 + 0x24) = 0;
          *(undefined4 *)(iVar5 + 0x20) = 0;
          *(undefined4 *)(iVar5 + 0x1c) = 0;
          *(undefined4 *)(iVar5 + 0x28) = 0;
          *(undefined1 *)(iVar5 + 0x17) = 0;
          return 0;
        }
        if ((((0 < *(int *)(*(int *)(iVar5 + 0x68) + 0x44)) && (*(char *)(iVar5 + 0x13) == '\x06'))
            && (uVar3 = *(uint *)(iVar5 + 0x28), (uVar3 & 0x20) == 0)) &&
           ((((uVar3 & 0x10) != 0 || ((*(byte *)(piVar1 + 2) & 2) != 0)) &&
            ((*(uint *)(iVar5 + 0x7c) == 0 || (*(uint *)(iVar5 + 0x7c) == *_active_u)))))) {
          *(uint *)(iVar5 + 0x28) = uVar3 | 0x20;
          *(int *)(DAT_001e875c + 0x60) = (int)*(short *)(iVar5 + 0x30);
          if (*(char *)(iVar5 + 0x17) == '\0') {
            iVar5 = *(int *)(iVar5 + 0x3c);
          }
          else {
            iVar5 = (int)*(char *)(iVar5 + 0x17);
          }
          local_8 = iVar5 << 8 | 0x7f;
          iVar5 = piVar1[1];
          goto LAB_001066d0;
        }
      }
    }
    if (local_10 == 0) {
      *(undefined1 *)(DAT_001e875c + 0x68) = 10;
      return 0;
    }
    if ((*(byte *)(piVar1 + 2) & 1) != 0) break;
    iVar5 = _set_label((int *)(DAT_001e875c + 0x28));
    if (iVar5 != 0) {
      if (((int)_active_u[0x50] >> (*(char *)(*_active_u + 0x17) - 1U & 0x1f) & 1U) == 0) {
        *(undefined1 *)(DAT_001e875c + 0x69) = 2;
      }
      else {
        *(undefined1 *)(DAT_001e875c + 0x68) = 4;
      }
      return 0;
    }
    _sleep(*_active_u);
  }
  local_8 = 0;
  *(undefined4 *)(DAT_001e875c + 0x60) = 0;
  iVar5 = piVar1[1];
LAB_001066d0:
  uVar4 = _copyout(&local_8,iVar5,4);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar4;
  return 0;
}

