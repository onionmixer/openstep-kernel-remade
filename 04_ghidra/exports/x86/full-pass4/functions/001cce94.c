/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cce94 */

void _class_removeMethods(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (*(undefined4 **)(param_1 + 0x1c) == param_2) {
    *(undefined4 *)(param_1 + 0x1c) = *param_2;
  }
  else {
    puVar1 = *(undefined4 **)(param_1 + 0x1c);
    for (puVar2 = (undefined4 *)**(undefined4 **)(param_1 + 0x1c); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      if (puVar2 == param_2) {
        *puVar1 = *puVar2;
        break;
      }
      puVar1 = puVar2;
    }
  }
  FUN_001ccda0(param_1,0);
  return;
}

