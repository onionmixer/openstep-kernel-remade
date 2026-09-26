/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010ab88 */

void _rqinit(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = &_qs;
  iVar2 = 0;
  do {
    *(undefined4 **)((int)&DAT_001e9504 + iVar2) = puVar1;
    *puVar1 = puVar1;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + 8;
  } while ((int)puVar1 < 0x1e95f9);
  return;
}

