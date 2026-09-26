/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010abec */

int _settimeofday(timeval *param_1,timezone *param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 local_c [8];
  
  iVar2 = 0;
  if (**(int **)(DAT_001e875c + 0x24) != 0) {
    uVar1 = _copyin(**(int **)(DAT_001e875c + 0x24),local_c,8);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar1;
    iVar2 = DAT_001e875c;
    if (*(char *)(DAT_001e875c + 0x68) == '\0') {
      iVar2 = _setthetime(local_c);
    }
  }
  return iVar2;
}

