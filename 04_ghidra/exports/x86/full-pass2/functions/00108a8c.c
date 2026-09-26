/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00108a8c */

int _getrusage(int param_1,rusage *param_2)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar1 = *(int **)(DAT_001e875c + 0x24);
  iVar3 = *piVar1;
  if (iVar3 == -1) {
    iVar3 = _active_u + 0x1b8;
  }
  else {
    if (iVar3 != 0) {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
      return iVar3;
    }
    _thread_read_times(_active_threads,&local_c,&local_14);
    iVar3 = _active_u;
    *(undefined4 *)(_active_u + 0x170) = local_c;
    *(undefined4 *)(iVar3 + 0x174) = local_8;
    iVar3 = _active_u;
    *(undefined4 *)(_active_u + 0x178) = local_14;
    *(undefined4 *)(iVar3 + 0x17c) = local_10;
    iVar3 = _active_u + 0x170;
  }
  uVar2 = _copyout(iVar3,piVar1[1],0x48);
  iVar3 = DAT_001e875c;
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  return iVar3;
}

