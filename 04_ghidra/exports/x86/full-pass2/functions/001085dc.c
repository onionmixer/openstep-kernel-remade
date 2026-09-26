/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001085dc */

int _getpriority(int param_1,id_t param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = DAT_001e875c;
  piVar1 = *(int **)(DAT_001e875c + 0x24);
  iVar4 = 0x15;
  iVar2 = *piVar1;
  if (iVar2 == 1) {
    if (piVar1[1] == 0) {
      piVar1[1] = (int)*(short *)(*_active_u + 0x2e);
    }
    if (_allproc != 0) {
      iVar2 = _allproc;
      do {
        if (((int)*(short *)(iVar2 + 0x2e) == piVar1[1]) && (*(char *)(iVar2 + 0x15) < iVar4)) {
          iVar4 = (int)*(char *)(iVar2 + 0x15);
        }
        iVar2 = *(int *)(iVar2 + 8);
      } while (iVar2 != 0);
    }
LAB_001086c4:
    iVar3 = DAT_001e875c;
    if (iVar4 == 0x15) {
      *(undefined1 *)(DAT_001e875c + 0x68) = 3;
    }
    else {
      *(int *)(DAT_001e875c + 0x60) = iVar4;
    }
  }
  else {
    if (iVar2 < 2) {
      if (iVar2 == 0) {
        if (piVar1[1] == 0) {
          iVar2 = *_active_u;
        }
        else {
          iVar2 = _pfind(piVar1[1]);
        }
        if (iVar2 != 0) {
          iVar4 = (int)*(char *)(iVar2 + 0x15);
        }
        goto LAB_001086c4;
      }
    }
    else if (iVar2 == 2) {
      if (piVar1[1] == 0) {
        piVar1[1] = (int)*(short *)(_active_u[7] + 2);
      }
      if (_allproc != 0) {
        iVar2 = _allproc;
        do {
          if (((int)*(short *)(iVar2 + 0x2c) == piVar1[1]) && (*(char *)(iVar2 + 0x15) < iVar4)) {
            iVar4 = (int)*(char *)(iVar2 + 0x15);
          }
          iVar2 = *(int *)(iVar2 + 8);
        } while (iVar2 != 0);
      }
      goto LAB_001086c4;
    }
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
  }
  return iVar3;
}

