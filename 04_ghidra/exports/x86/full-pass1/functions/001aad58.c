/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aad58 */

void _en_recv_pkt(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  *param_2 = 0;
  if (DAT_001e8700 != 0) {
    (*DAT_001e8708)(DAT_001e8700,PTR_s_receivePacket_length_timeout__001f9b04,param_1,param_2,
                    param_3);
  }
  return;
}

