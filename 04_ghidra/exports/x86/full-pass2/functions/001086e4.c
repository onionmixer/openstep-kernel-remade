/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001086e4 */

int _setpriority(int param_1,id_t param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = DAT_001e875c;
  piVar1 = (int *)DAT_001e875c[9];
  iVar5 = 0;
  piVar3 = (int *)*piVar1;
  if (piVar3 == (int *)0x1) {
    iVar2 = _allproc;
    if (piVar1[1] == 0) {
      piVar3 = (int *)(int)*(short *)(*_active_u + 0x2e);
      piVar1[1] = (int)piVar3;
      iVar2 = _allproc;
    }
    for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
      piVar3 = (int *)(int)*(short *)(iVar2 + 0x2e);
      if ((int *)piVar1[1] == piVar3) {
        piVar3 = (int *)_donice(iVar2,piVar1[2]);
        iVar5 = iVar5 + 1;
      }
    }
LAB_001087d4:
    piVar1 = DAT_001e875c;
    if (iVar5 == 0) {
      *(undefined1 *)(DAT_001e875c + 0x1a) = 3;
      piVar3 = piVar1;
    }
  }
  else {
    if ((int)piVar3 < 2) {
      if (piVar3 == (int *)0x0) {
        if (piVar1[1] == 0) {
          piVar3 = _active_u;
          piVar4 = (int *)*_active_u;
        }
        else {
          piVar3 = (int *)_pfind(piVar1[1]);
          piVar4 = piVar3;
        }
        if (piVar4 != (int *)0x0) {
          piVar3 = (int *)_donice(piVar4,piVar1[2]);
          iVar5 = 1;
        }
        goto LAB_001087d4;
      }
    }
    else if (piVar3 == (int *)0x2) {
      iVar2 = _allproc;
      if (piVar1[1] == 0) {
        piVar3 = (int *)(int)*(short *)(_active_u[7] + 2);
        piVar1[1] = (int)piVar3;
        iVar2 = _allproc;
      }
      for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
        piVar3 = (int *)(int)*(short *)(iVar2 + 0x2c);
        if ((int *)piVar1[1] == piVar3) {
          piVar3 = (int *)_donice(iVar2,piVar1[2]);
          iVar5 = iVar5 + 1;
        }
      }
      goto LAB_001087d4;
    }
    *(undefined1 *)(DAT_001e875c + 0x1a) = 0x16;
    piVar3 = piVar4;
  }
  return (int)piVar3;
}

