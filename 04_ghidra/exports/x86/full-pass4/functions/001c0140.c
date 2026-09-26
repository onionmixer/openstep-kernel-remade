/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c0140 */

void FUN_001c0140(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if ((0x400 < *(int *)(param_1 + 4) - 0x428U) || (*(char *)(param_1 + 3) != '\0')) {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
    return;
  }
  if ((*(int *)(param_1 + 0x18) == 0x10012006) &&
     ((*(uint *)(param_1 + 0x20) & 0x3000ffff) == 0x10002002)) {
    uVar3 = *(ushort *)(param_1 + 0x22) & 0xfff;
    iVar2 = uVar3 * 4;
    if ((*(int *)(param_1 + 4) == iVar2 + 0x428) &&
       (iVar2 = iVar2 + param_1, *(int *)(iVar2 + 0x24) == 0x11002002)) {
      uVar1 = _audio_port_to_device
                        (*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x1c),
                         param_1 + 0x24,uVar3,iVar2 + 0x28);
      uVar1 = __NXAudioSetDeviceParameters(uVar1);
      *(undefined4 *)(param_2 + 0x1c) = uVar1;
      goto LAB_001c01e5;
    }
  }
  *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
LAB_001c01e5:
  if (*(int *)(param_2 + 0x1c) == 0) {
    *(undefined1 *)(param_2 + 3) = 1;
    *(undefined4 *)(param_2 + 4) = 0x20;
  }
  return;
}

