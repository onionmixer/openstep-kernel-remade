/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00129b90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _tcp_xmit_timer(int param_1)

{
  short sVar1;
  short sVar2;
  
  _DAT_001eed8c = _DAT_001eed8c + 1;
  sVar1 = *(short *)(param_1 + 0x60);
  if (sVar1 == 0) {
    *(short *)(param_1 + 0x60) = *(short *)(param_1 + 0x5a) << 3;
    *(short *)(param_1 + 0x62) = *(short *)(param_1 + 0x5a) * 2;
  }
  else {
    sVar2 = *(short *)(param_1 + 0x5a) - ((sVar1 >> 3) + 1);
    *(short *)(param_1 + 0x60) = sVar1 + sVar2;
    if ((short)(sVar1 + sVar2) < 1) {
      *(undefined2 *)(param_1 + 0x60) = 1;
    }
    if (sVar2 < 0) {
      sVar2 = -sVar2;
    }
    sVar1 = *(short *)(param_1 + 0x62) + (sVar2 - (*(short *)(param_1 + 0x62) >> 2));
    *(short *)(param_1 + 0x62) = sVar1;
    if (sVar1 < 1) {
      *(undefined2 *)(param_1 + 0x62) = 1;
    }
  }
  *(undefined2 *)(param_1 + 0x5a) = 0;
  *(undefined2 *)(param_1 + 0x12) = 0;
  sVar1 = (*(short *)(param_1 + 0x60) >> 3) + *(short *)(param_1 + 0x62);
  *(short *)(param_1 + 0x14) = sVar1;
  if ((int)sVar1 < (int)(uint)*(ushort *)(param_1 + 100)) {
    *(ushort *)(param_1 + 0x14) = *(ushort *)(param_1 + 100);
  }
  else if (0x80 < sVar1) {
    *(undefined2 *)(param_1 + 0x14) = 0x80;
  }
  *(undefined2 *)(param_1 + 0x6a) = 0;
  return;
}

