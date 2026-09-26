/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c0200 */

void FUN_001c0200(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  if ((*(int *)(param_1 + 4) - 0x1cU < 0x401) && (*(char *)(param_1 + 3) == '\x01')) {
    if (((*(uint *)(param_1 + 0x18) & 0x3000ffff) == 0x10002002) &&
       (uVar2 = *(ushort *)(param_1 + 0x1a) & 0xfff, *(int *)(param_1 + 4) == uVar2 * 4 + 0x1c)) {
      uVar1 = _audio_port_to_device
                        (*(undefined4 *)(param_1 + 0xc),param_1 + 0x1c,uVar2,param_2 + 0x24);
      uVar1 = __NXAudioGetDeviceParameters(uVar1);
      *(undefined4 *)(param_2 + 0x1c) = uVar1;
    }
    else {
      *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
    }
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined4 *)(param_2 + 0x20) = 0x11002002;
      *(undefined1 *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x424;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

