/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c90a8 */

int FUN_001c90a8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_14;
  undefined4 local_10;
  undefined8 local_c;
  
  iVar2 = _objc_msgSend(param_1,PTR_s__insertKeyNoRehash_value__001f9d3c,param_3,param_4);
  if (iVar2 == 0) {
    if (*(uint *)(param_1 + 0x10) < *(uint *)(param_1 + 4)) {
      uVar3 = _objc_msgSend(param_1,PTR_s_zone_001f9d4c,PTR_s__initBare___001f9d54,
                            *(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),
                            *(undefined4 *)(param_1 + 0x10));
      uVar3 = _objc_msgSend(PTR_s_HashTable_001f9d74,PTR_s_allocFromZone__001f9d58,uVar3);
      iVar2 = _objc_msgSend(uVar3);
      *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(param_1 + 4);
      *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(param_1 + 0x14);
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x10) + 1;
      *(undefined4 *)(param_1 + 4) = 0;
      uVar3 = _objc_msgSend(param_1,PTR_s_zone_001f9d4c,*(undefined4 *)(param_1 + 0x10),8);
      uVar3 = _NXZoneCalloc(uVar3);
      *(undefined4 *)(param_1 + 0x14) = uVar3;
      local_c = _objc_msgSend(iVar2,PTR_s_initState_001f9324);
      while( true ) {
        cVar1 = _objc_msgSend(iVar2,PTR_s_nextState_key_value__001f9328,&local_c,&local_10,&local_14
                             );
        if (cVar1 == '\0') break;
        _objc_msgSend(param_1,PTR_s_insertKey_value__001f9288,local_10,local_14);
      }
      _objc_msgSend(iVar2,PTR_s_free_001f921c);
    }
    iVar2 = 0;
  }
  return iVar2;
}

