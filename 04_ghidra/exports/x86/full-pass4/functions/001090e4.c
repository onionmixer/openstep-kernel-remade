/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001090e4 */

void _fd_shutdown(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = _file_list;
  while (puVar3 = puVar2, (undefined4 **)puVar3 != &_file_list) {
    puVar2 = (undefined4 *)*puVar3;
    sVar1 = *(short *)((int)puVar3 + 0xe);
    while (0 < sVar1) {
      _closef(puVar3);
      sVar1 = *(short *)((int)puVar3 + 0xe);
    }
  }
  return;
}

