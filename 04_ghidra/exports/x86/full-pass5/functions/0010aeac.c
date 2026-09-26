/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010aeac */

int _getitimer(int param_1,itimerval *param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int iVar5;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar5 = DAT_001e875c;
  puVar1 = *(uint **)(DAT_001e875c + 0x24);
  if (*puVar1 < 3) {
    uVar4 = _splclock();
    uVar2 = *puVar1;
    if (uVar2 == 0) {
      do {
        local_18 = _mtime[1];
        local_1c = _mtime[2];
      } while (*_mtime != local_1c);
      iVar5 = *_active_u;
      local_14 = *(int *)(iVar5 + 0x54);
      local_10 = *(int *)(iVar5 + 0x58);
      local_c = *(int *)(iVar5 + 0x5c);
      local_8 = *(int *)(iVar5 + 0x60);
      if ((local_c != 0) || (local_8 != 0)) {
        if ((local_c < local_1c) || ((local_1c == local_c && (local_8 < local_18)))) {
          local_8 = 0;
          local_c = 0;
        }
        else {
          _timevalsub(&local_c,&local_1c);
        }
      }
    }
    else {
      local_14 = _active_u[uVar2 * 4 + 0x80];
      local_10 = _active_u[uVar2 * 4 + 0x81];
      local_c = _active_u[uVar2 * 4 + 0x82];
      local_8 = _active_u[uVar2 * 4 + 0x83];
    }
    _splx(uVar4);
    uVar3 = _copyout(&local_14,puVar1[1],0x10);
    iVar5 = DAT_001e875c;
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar3;
  }
  else {
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
  }
  return iVar5;
}

