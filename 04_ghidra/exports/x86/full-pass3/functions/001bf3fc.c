/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bf3fc */

undefined4 _audio_server(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_2 + 3) = 1;
  *(undefined4 *)(param_2 + 4) = 0x20;
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(int *)(param_2 + 0x14) = *(int *)(param_1 + 0x14) + 100;
  *(undefined4 *)(param_2 + 0x18) = 0x10012002;
  *(undefined4 *)(param_2 + 0x1c) = 0xfffffed1;
  if ((*(int *)(param_1 + 0x14) - 700U < 0x25) &&
     (*(code **)(&DAT_001d57c8 + *(int *)(param_1 + 0x14) * 4) != (code *)0x0)) {
    (**(code **)(&DAT_001d57c8 + *(int *)(param_1 + 0x14) * 4))(param_1,param_2);
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

