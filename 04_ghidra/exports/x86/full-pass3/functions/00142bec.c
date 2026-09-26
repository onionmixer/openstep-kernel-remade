/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00142bec */

bool _badblock(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x24);
  if (uVar1 <= param_2) {
    _printf(s_bad_block__d__001de0c7,param_2);
    _fserr(param_1,s_bad_block_001de0d6);
  }
  return uVar1 <= param_2;
}

