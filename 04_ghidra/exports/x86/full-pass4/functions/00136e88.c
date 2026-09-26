/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00136e88 */

void FUN_00136e88(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)0x0;
  for (puVar2 = DAT_001e5a1c;
      (puVar2 != (undefined4 *)0x0 && ((puVar2[1] != param_1 || (puVar2[2] != param_2))));
      puVar2 = (undefined4 *)*puVar2) {
    puVar1 = puVar2;
  }
  *param_3 = puVar1;
  return;
}

