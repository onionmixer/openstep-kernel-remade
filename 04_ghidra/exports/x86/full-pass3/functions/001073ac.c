/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001073ac */

void _pidhash_enter(int param_1)

{
  uint uVar1;
  
  uVar1 = *(ushort *)(param_1 + 0x30) & 0x3f;
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(&_pidhash + uVar1 * 4);
  *(int *)(&_pidhash + uVar1 * 4) = param_1;
  return;
}

