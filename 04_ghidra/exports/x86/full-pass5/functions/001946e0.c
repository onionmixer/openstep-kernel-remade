/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001946e0 */

undefined4 _eisa_present(void)

{
  int iVar1;
  
  if (DAT_001e7744 == 0) {
    iVar1 = _strncmp((char *)0xfffd9,&DAT_001e2c54,4);
    if (iVar1 == 0) {
      DAT_001e2c50 = 1;
    }
    DAT_001e7744 = 1;
  }
  return DAT_001e2c50;
}

