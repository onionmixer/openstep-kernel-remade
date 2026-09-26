/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00135544 */

void _clntkudp_init(int param_1,uint *param_2,uint param_3,short *param_4)

{
  uint *puVar1;
  
  puVar1 = *(uint **)(param_1 + 8);
  puVar1[4] = param_3;
  puVar1[6] = *param_2;
  puVar1[7] = param_2[1];
  puVar1[8] = param_2[2];
  puVar1[9] = param_2[3];
  puVar1[0x1d] = (uint)param_4;
  *param_4 = *param_4 + 1;
  *puVar1 = *puVar1 & 0x18;
  return;
}

