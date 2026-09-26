/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018abd0 */

void FUN_0018abd0(void)

{
  segment_command_64 *psVar1;
  int iVar2;
  
  psVar1 = _getsegbyname(s___DATA_001e19f0);
  if (psVar1 != (segment_command_64 *)0x0) {
    for (iVar2 = _firstsect(psVar1); iVar2 != 0; iVar2 = _nextsect(psVar1,iVar2)) {
      if ((*(byte *)(iVar2 + 0x38) & 1) != 0) {
        _bzero(*(void **)(iVar2 + 0x20),*(size_t *)(iVar2 + 0x24));
      }
    }
  }
  return;
}

