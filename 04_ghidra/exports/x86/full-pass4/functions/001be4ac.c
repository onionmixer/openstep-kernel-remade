/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001be4ac */

void _audio_convertLinear8ToMulaw8(byte *param_1,undefined1 *param_2,int param_3)

{
  byte bVar1;
  undefined1 uVar2;
  
  while (param_3 = param_3 + -1, param_3 != -1) {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = _audio_shortToMulaw((int)(short)((ushort)bVar1 << 8));
    *param_2 = uVar2;
  }
  return;
}

