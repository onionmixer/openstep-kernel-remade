/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ccda0 */

void FUN_001ccda0(undefined4 *param_1,char param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *local_10;
  undefined8 local_c;
  
  if (param_1[8] != 0) {
    uVar1 = _objc_getClasses();
    local_c = _NXInitHashState(uVar1);
LAB_001ccdd4:
    iVar2 = _NXNextHashState(uVar1,&local_c,&local_10);
    puVar3 = local_10;
    if (iVar2 != 0) {
      while (puVar3 != (undefined4 *)0x0) {
        if (puVar3 == param_1) {
          FUN_001cd7ec(local_10);
          if (param_2 != '\0') {
            FUN_001cd7ec(*local_10);
          }
          break;
        }
        if ((undefined4 *)*puVar3 == param_1) {
          FUN_001cd7ec(local_10);
          puVar3 = (undefined4 *)0x0;
        }
        else if ((*(byte *)(puVar3 + 4) & 4) == 0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          puVar3 = (undefined4 *)puVar3[1];
        }
      }
      goto LAB_001ccdd4;
    }
  }
  return;
}

