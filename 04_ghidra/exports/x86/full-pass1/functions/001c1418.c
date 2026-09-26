/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c1418 */

undefined4 FUN_001c1418(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  if (puVar1[1] == 0) {
    uVar2 = _objc_msgSend(param_1,PTR_s__delegate_001f9c08,PTR_s_resourcesForKey__001f9344,
                          "DMA Channels",puVar1 + 1);
    uVar2 = _objc_msgSend(uVar2);
    uVar2 = _objc_msgSend(param_1,PTR_s__fetchItemList_returnedNum__001f9c04,uVar2);
    *puVar1 = uVar2;
  }
  return puVar1[1];
}

