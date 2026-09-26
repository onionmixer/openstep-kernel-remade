/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019ec24 */

undefined4 * _FBAllocateConsole(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)_IOMalloc(0x20);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    iVar2 = _IOMalloc(0xe4);
    puVar1[7] = iVar2;
    if (iVar2 == 0) {
      _IOFree(puVar1,0x20);
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = FUN_0019efa8;
      puVar1[1] = FUN_0019df7c;
      puVar1[2] = FUN_0019efcc;
      puVar1[3] = FUN_0019e23c;
      puVar1[4] = FUN_0019e7cc;
      puVar1[5] = FUN_0019f050;
      puVar1[6] = FUN_0019f068;
      puVar3 = (undefined4 *)puVar1[7];
      for (iVar2 = 0x22; puVar3 = puVar3 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = *param_1;
        param_1 = param_1 + 1;
      }
      *(undefined4 *)puVar1[7] = 0;
    }
  }
  return puVar1;
}

