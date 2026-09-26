/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00185be8 */

void _kdp_exception_ack(char *param_1,uint param_2)

{
  if (((7 < param_2) && (*param_1 == -0x73)) && (DAT_001f66b6 == param_1[1])) {
    DAT_001f66b8 = 0;
    DAT_001f66b6 = param_1[1] + '\x01';
  }
  return;
}

