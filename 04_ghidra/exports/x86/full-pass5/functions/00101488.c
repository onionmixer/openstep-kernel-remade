/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00101488 */

void _bcopy16(undefined2 *param_1,undefined2 *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  
  if ((int)param_3 < 0x10) {
    for (; param_3 != 0; param_3 = param_3 - 1) {
      *(undefined1 *)param_2 = *(undefined1 *)param_1;
      param_1 = (undefined2 *)((int)param_1 + 1);
      param_2 = (undefined2 *)((int)param_2 + 1);
    }
  }
  else {
    if (((uint)param_1 & 3) != 0) {
      iVar1 = 4 - ((uint)param_1 & 3);
      puVar3 = param_1;
      puVar4 = param_2;
      for (iVar2 = iVar1; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined1 *)puVar4 = *(undefined1 *)puVar3;
        puVar3 = (undefined2 *)((int)puVar3 + 1);
        puVar4 = (undefined2 *)((int)puVar4 + 1);
      }
      param_3 = param_3 - iVar1;
      param_2 = (undefined2 *)((int)param_2 + iVar1);
      param_1 = (undefined2 *)((int)param_1 + iVar1);
    }
    puVar3 = param_1;
    puVar4 = param_2;
    for (iVar2 = (int)param_3 >> 1; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    if ((param_3 & 1) != 0) {
      *(undefined1 *)((param_3 & 0xfffffffe) + (int)param_2) =
           *(undefined1 *)((param_3 & 0xfffffffe) + (int)param_1);
    }
  }
  return;
}

