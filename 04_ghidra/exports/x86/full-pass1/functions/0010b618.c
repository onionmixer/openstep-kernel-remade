/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010b618 */

void _sethostid(long param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  iVar2 = _suser();
  if (iVar2 != 0) {
    _hostid = *puVar1;
  }
  return;
}

