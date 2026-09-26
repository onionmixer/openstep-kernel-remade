/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b3798 */

uint _EventCoalesceDisplayCmd(uint param_1,uint param_2)

{
  if ((int)param_1 < 4) {
    param_1 = (uint)(char)(&DAT_001d5dc8)[(param_2 & 3) * 4 + (param_1 & 3)];
  }
  return param_1;
}

