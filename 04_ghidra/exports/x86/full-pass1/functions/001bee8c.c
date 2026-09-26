/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bee8c */

undefined4 _Event_server(int param_1,int param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  *(undefined1 *)(param_2 + 3) = 1;
  *(undefined4 *)(param_2 + 4) = 0x20;
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(int *)(param_2 + 0x14) = *(int *)(param_1 + 0x14) + 100;
  *(undefined4 *)(param_2 + 0x18) = 0x10012002;
  *(undefined4 *)(param_2 + 0x1c) = 0xfffffed1;
  if ((*(int *)(param_1 + 0x14) - 31000U < 9) &&
     (pcVar1 = *(code **)(*(int *)(param_1 + 0x14) * 4 + 0x1b7cf0), pcVar1 != (code *)0x0)) {
    (*pcVar1)(param_1,param_2);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

