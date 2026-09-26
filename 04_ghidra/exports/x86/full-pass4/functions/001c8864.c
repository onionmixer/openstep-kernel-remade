/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c8864 */

void _IOFreeLow(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar3 = _dmaBufQueue;
  while( true ) {
    if ((undefined4 **)puVar3 == &_dmaBufQueue) {
      _IOLog("IOFreeLow: buf 0x%x not found\n",param_1);
      return;
    }
    if (*(int *)*puVar3 == param_1) break;
    puVar3 = (undefined4 *)puVar3[1];
  }
  puVar1 = (undefined4 *)puVar3[1];
  puVar2 = (undefined4 *)puVar3[2];
  puVar4 = &_dmaBufQueue;
  if ((undefined4 **)puVar1 != &_dmaBufQueue) {
    puVar4 = puVar1 + 1;
  }
  puVar4[1] = puVar2;
  puVar4 = &_dmaBufQueue;
  if ((undefined4 **)puVar2 != &_dmaBufQueue) {
    puVar4 = puVar2 + 1;
  }
  *puVar4 = puVar1;
  _dma_buf_free(*puVar3);
  _IOFree(*puVar3,8);
  _IOFree(puVar3,0xc);
  return;
}

