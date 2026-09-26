/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00102eec */

void _bhinit(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined *puVar3;
  
  puVar3 = &_bufhash;
  iVar2 = 0;
  puVar1 = &DAT_001e8884;
  do {
    puVar1[1] = puVar3;
    *puVar1 = puVar3;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 3;
    puVar3 = puVar3 + 0xc;
  } while (iVar2 < 0x10);
  return;
}

