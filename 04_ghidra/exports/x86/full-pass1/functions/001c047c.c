/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c047c */

void FUN_001c047c(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int local_8;
  
  if ((*(int *)(param_1 + 4) == 0x18) && (*(char *)(param_1 + 3) == '\x01')) {
    local_8 = 0x100;
    uVar1 = _audio_port_to_device(*(undefined4 *)(param_1 + 0xc),param_2 + 0x24,&local_8);
    iVar2 = __NXAudioGetDataEncodings(uVar1);
    *(int *)(param_2 + 0x1c) = iVar2;
    if (iVar2 == 0) {
      *(undefined4 *)(param_2 + 0x20) = 0x11002002;
      *(ushort *)(param_2 + 0x22) = *(ushort *)(param_2 + 0x22) & 0xf000 | (ushort)local_8 & 0xfff;
      *(undefined1 *)(param_2 + 3) = 1;
      *(int *)(param_2 + 4) = local_8 * 4 + 0x24;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

