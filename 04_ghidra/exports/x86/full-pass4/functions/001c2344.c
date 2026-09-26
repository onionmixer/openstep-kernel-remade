/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c2344 */

undefined4 FUN_001c2344(int param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  void *pvVar3;
  size_t sVar4;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  if (puVar1[3] == 0) {
    pvVar2 = (void *)_IOMalloc(puVar1[2]);
    puVar1[3] = pvVar2;
    sVar4 = puVar1[2];
    pvVar3 = (void *)_objc_msgSend(*puVar1,PTR_s_data_001f9620);
    _bcopy(pvVar3,pvVar2,sVar4);
  }
  return puVar1[3];
}

