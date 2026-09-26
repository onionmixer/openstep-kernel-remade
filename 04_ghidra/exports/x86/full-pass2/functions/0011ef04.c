/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011ef04 */

void _if_down(int param_1)

{
  sockaddr *psVar1;
  
  *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0xbe;
  for (psVar1 = *(sockaddr **)(param_1 + 0x18); psVar1 != (sockaddr *)0x0;
      psVar1 = *(sockaddr **)(psVar1[2].sa_data + 2)) {
    _pfctlinput(0,psVar1);
  }
  _if_qflush(param_1 + 0x1c);
  return;
}

