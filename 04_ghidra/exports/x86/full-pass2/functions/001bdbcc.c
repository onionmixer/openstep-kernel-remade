/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bdbcc */

void _audio_snd_reply_illegal_msg
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  *(undefined4 *)(param_1 + 0x14) = 0x13a;
  *(undefined4 *)(param_1 + 4) = 0x24;
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x10) = param_3;
  *(undefined4 *)(param_1 + 0x18) = DAT_001e53c8;
  *(short *)(param_1 + 0x1a) =
       (short)CONCAT31((uint3)((byte)((ushort)*(undefined2 *)(param_1 + 0x1a) >> 8) & 0xf0),2);
  *(undefined4 *)(param_1 + 0x1c) = param_4;
  *(undefined4 *)(param_1 + 0x20) = param_5;
  return;
}

