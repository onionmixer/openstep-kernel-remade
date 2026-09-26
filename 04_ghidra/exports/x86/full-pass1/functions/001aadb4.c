/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aadb4 */

void FUN_001aadb4(int param_1)

{
  if (DAT_001e8700 == 0) {
    DAT_001e8708 = _objc_msgSend(param_1,PTR_s_methodFor__001f9470,
                                 PTR_s_receivePacket_length_timeout__001f9b04);
    DAT_001e870c = _objc_msgSend(param_1,PTR_s_methodFor__001f9470,PTR_s_sendPacket_length__001f9b00
                                );
    if ((DAT_001e8708 != 0) && (DAT_001e870c != 0)) {
      DAT_001e8700 = param_1;
    }
  }
  return;
}

