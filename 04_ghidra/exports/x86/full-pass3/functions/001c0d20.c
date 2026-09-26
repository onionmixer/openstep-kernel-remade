/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c0d20 */

undefined4 *
FUN_001c0d20(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            byte param_5,byte param_6,byte param_7)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)_IOMalloc(0x18);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = *param_3;
    puVar1[1] = param_4;
    *(byte *)(puVar1 + 5) =
         *(byte *)(puVar1 + 5) & 0xc5 | (param_5 & 1) << 3 | (param_6 & 1) << 4 | (param_7 & 1) << 5
    ;
    iVar2 = _dma_xfer(puVar1,param_3);
    if (iVar2 == 0) {
      _IOFree(puVar1,0x18);
      puVar1 = (undefined4 *)0x0;
    }
  }
  return puVar1;
}

