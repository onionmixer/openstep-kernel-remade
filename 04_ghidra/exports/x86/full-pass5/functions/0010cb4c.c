/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010cb4c */

void _harderr(int param_1,undefined4 param_2)

{
  _printf(s__s_d_c__hard_error_sn_d_001dac8d,param_2,(*(ushort *)(param_1 + 0x1e) & 0xf8) >> 3,
          (*(ushort *)(param_1 + 0x1e) & 7) + 0x61,*(undefined4 *)(param_1 + 0x24));
  return;
}

