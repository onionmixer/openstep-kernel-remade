/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c0560 */

void FUN_001c0560(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if ((0x400 < *(int *)(param_1 + 4) - 0x420U) || (*(char *)(param_1 + 3) != '\x01')) {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
    return;
  }
  if ((*(uint *)(param_1 + 0x18) & 0x3000ffff) == 0x10002002) {
    uVar3 = *(ushort *)(param_1 + 0x1a) & 0xfff;
    iVar2 = uVar3 * 4;
    if ((*(int *)(param_1 + 4) == iVar2 + 0x420) &&
       (iVar2 = iVar2 + param_1, *(int *)(iVar2 + 0x1c) == 0x11002002)) {
      uVar1 = _audio_port_to_stream
                        (*(undefined4 *)(param_1 + 0xc),param_1 + 0x1c,uVar3,iVar2 + 0x20);
      uVar1 = __NXAudioSetStreamParameters(uVar1);
      *(undefined4 *)(param_2 + 0x1c) = uVar1;
      goto LAB_001c05ee;
    }
  }
  *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
LAB_001c05ee:
  if (*(int *)(param_2 + 0x1c) == 0) {
    *(undefined1 *)(param_2 + 3) = 1;
    *(undefined4 *)(param_2 + 4) = 0x20;
  }
  return;
}

