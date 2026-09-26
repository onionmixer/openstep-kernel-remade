/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010afc4 */

int _setitimer(int param_1,itimerval *param_2,itimerval *param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  int *piVar6;
  undefined1 uVar7;
  int iVar8;
  undefined4 uVar9;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar1 = *(uint **)(DAT_001e875c + 0x24);
  iVar2 = *_active_u;
  if (*puVar1 < 3) {
    uVar3 = puVar1[1];
    iVar8 = 0;
    if (puVar1[2] != 0) {
      puVar1[1] = puVar1[2];
      iVar8 = DAT_001e875c;
      puVar4 = *(uint **)(DAT_001e875c + 0x24);
      if (*puVar4 < 3) {
        uVar9 = _splclock();
        uVar5 = *puVar4;
        if (uVar5 == 0) {
          do {
            local_28 = _mtime[1];
            local_2c = _mtime[2];
          } while (*_mtime != local_2c);
          iVar8 = *_active_u;
          local_24 = *(int *)(iVar8 + 0x54);
          local_20 = *(int *)(iVar8 + 0x58);
          local_1c = *(int *)(iVar8 + 0x5c);
          local_18 = *(int *)(iVar8 + 0x60);
          if ((local_1c != 0) || (local_18 != 0)) {
            if ((local_1c < local_2c) || ((local_2c == local_1c && (local_18 < local_28)))) {
              local_18 = 0;
              local_1c = 0;
            }
            else {
              _timevalsub(&local_1c,&local_2c);
            }
          }
        }
        else {
          local_24 = _active_u[uVar5 * 4 + 0x80];
          local_20 = _active_u[uVar5 * 4 + 0x81];
          local_1c = _active_u[uVar5 * 4 + 0x82];
          local_18 = _active_u[uVar5 * 4 + 0x83];
        }
        _splx(uVar9);
        uVar7 = _copyout(&local_24,puVar4[1],0x10);
        iVar8 = DAT_001e875c;
        *(undefined1 *)(DAT_001e875c + 0x68) = uVar7;
      }
      else {
        *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
      }
    }
    if (uVar3 != 0) {
      uVar7 = _copyin(uVar3,&local_14,0x10);
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar7;
      iVar8 = DAT_001e875c;
      if (*(char *)(DAT_001e875c + 0x68) == '\0') {
        iVar8 = _itimerfix(&local_c);
        if ((iVar8 == 0) && (iVar8 = _itimerfix(&local_14), iVar8 == 0)) {
          uVar9 = _splclock();
          piVar6 = _active_u;
          uVar3 = *puVar1;
          if (uVar3 == 0) {
            do {
              local_30 = _mtime[1];
              local_34 = _mtime[2];
            } while (*_mtime != local_34);
            _untimeout(_realitexpire,iVar2);
            if ((local_c != 0) || (local_8 != 0)) {
              _timevaladd(&local_c,&local_34);
              _hzto(&local_c);
              _timeout(0x10b250);
            }
            *(int *)(iVar2 + 0x54) = local_14;
            *(int *)(iVar2 + 0x58) = local_10;
            *(int *)(iVar2 + 0x5c) = local_c;
            *(int *)(iVar2 + 0x60) = local_8;
          }
          else {
            _active_u[uVar3 * 4 + 0x80] = local_14;
            piVar6[uVar3 * 4 + 0x81] = local_10;
            piVar6[uVar3 * 4 + 0x82] = local_c;
            piVar6[uVar3 * 4 + 0x83] = local_8;
          }
          iVar8 = _splx(uVar9);
        }
        else {
          iVar8 = DAT_001e875c;
          *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
        }
      }
    }
  }
  else {
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
    iVar8 = iVar2;
  }
  return iVar8;
}

