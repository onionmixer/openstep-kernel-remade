/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012fb98 */

void _rflush(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = &_rtable;
  do {
    for (iVar1 = *piVar2; iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      if (((-1 < *(char *)(iVar1 + 0x10)) && ((*(byte *)(*(int *)(iVar1 + 0x30) + 0xc) & 1) == 0))
         && ((param_1 == 0 || (*(int *)(iVar1 + 0x30) == param_1)))) {
        _sync_vp(iVar1 + 0xc);
      }
    }
    piVar2 = piVar2 + 1;
  } while (piVar2 < &_unixauthtab);
  return;
}

