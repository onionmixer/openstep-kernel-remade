/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00181554 */

undefined4 FUN_00181554(int param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  bool bVar7;
  
  iVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0xc),PTR_s_removeKey__001f92a0,param_3);
  if (iVar1 != 0) {
    iVar4 = 0xb;
    bVar7 = true;
    pcVar6 = s_IRQ_Levels_001e0fe8;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar7 = *param_3 == *pcVar6;
      param_3 = param_3 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (bVar7) {
      for (uVar5 = 0; uVar2 = _objc_msgSend(iVar1,PTR_s_count_001f92d8), uVar5 < uVar2;
          uVar5 = uVar5 + 1) {
        uVar3 = _objc_msgSend(iVar1,PTR_s_objectAt__001f92e8,uVar5);
        _objc_msgSend(*(undefined4 *)(param_1 + 0x14),PTR_s_removeObject__001f92cc,uVar3);
      }
    }
    _objc_msgSend(iVar1,PTR_s_freeObjects_001f92ec);
    _objc_msgSend(iVar1,PTR_s_free_001f921c);
  }
  return 0;
}

