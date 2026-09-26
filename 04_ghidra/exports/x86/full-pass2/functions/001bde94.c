/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bde94 */

void _audio_snd_reply_ret_formats
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  *(undefined4 *)(param_1 + 0x14) = 0x140;
  *(undefined4 *)(param_1 + 4) = 0x30;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x18) = DAT_001e53c8;
  *(short *)(param_1 + 0x1a) =
       (short)CONCAT31((uint3)((byte)((ushort)*(undefined2 *)(param_1 + 0x1a) >> 8) & 0xf0),5);
  *(undefined4 *)(param_1 + 0x1c) = param_3;
  *(undefined4 *)(param_1 + 0x20) = param_4;
  *(undefined4 *)(param_1 + 0x24) = param_5;
  *(undefined4 *)(param_1 + 0x28) = param_6;
  *(undefined4 *)(param_1 + 0x2c) = param_7;
  return;
}

