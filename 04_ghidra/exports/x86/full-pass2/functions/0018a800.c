/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018a800 */

uint _fp_terminate(uint param_1)

{
  uint uVar1;
  uint in_CR0;
  
  uVar1 = DAT_001e75f8;
  if (param_1 == DAT_001e75f8) {
    DAT_001e75f8 = 0;
    uVar1 = in_CR0 | 8;
  }
  return uVar1;
}

