/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00109500 */

void _sigstack(void)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar1 = *(int **)(DAT_001e875c + 0x24);
  iVar2 = piVar1[1];
  if (iVar2 != 0) {
    uVar3 = _copyout(_active_u + 0x148,iVar2,8);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar3;
    if (*(char *)(DAT_001e875c + 0x68) != '\0') {
      return;
    }
  }
  iVar2 = *piVar1;
  if (iVar2 != 0) {
    uVar3 = _copyin(iVar2,&local_c,8);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar3;
    iVar2 = _active_u;
    if (*(char *)(DAT_001e875c + 0x68) == '\0') {
      *(undefined4 *)(_active_u + 0x148) = local_c;
      *(undefined4 *)(iVar2 + 0x14c) = local_8;
    }
  }
  return;
}

