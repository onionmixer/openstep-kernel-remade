/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016df30 */

bool _exc_server(int param_1,int param_2)

{
  bool bVar1;
  
  *(undefined1 *)(param_2 + 3) = 1;
  *(undefined4 *)(param_2 + 4) = 0x20;
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(int *)(param_2 + 0x14) = *(int *)(param_1 + 0x14) + 100;
  *(undefined4 *)(param_2 + 0x18) = 0x10012002;
  *(undefined4 *)(param_2 + 0x1c) = 0xfffffed1;
  bVar1 = *(int *)(param_1 + 0x14) == 0x960;
  if (bVar1) {
    FUN_0016df98(param_1,param_2);
  }
  return bVar1;
}

