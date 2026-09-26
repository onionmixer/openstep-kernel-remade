/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001810b8 */

int FUN_001810b8(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_10;
  int local_c;
  undefined *local_8;
  
  local_c = param_1;
  local_8 = PTR_s_Object_001f9fc8;
  _objc_msgSendSuper(&local_c,PTR_s_init_001f924c);
  *(undefined4 *)(param_1 + 4) = param_3;
  *(undefined4 *)(param_1 + 8) = 0;
  uVar1 = _objc_msgSend(PTR_s_HashTable_001f9d74,PTR_s_alloc_001f9210,
                        PTR_s_initKeyDesc_valueDesc__001f9304,&DAT_001e0ff5,&DAT_001e0ff3);
  uVar1 = _objc_msgSend(uVar1);
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = _objc_msgSend(PTR_s_HashTable_001f9d74,PTR_s_alloc_001f9210,
                        PTR_s_initKeyDesc_valueDesc__001f9304,&DAT_001e0ff9,&DAT_001e0ff7);
  uVar1 = _objc_msgSend(uVar1);
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  uVar1 = _objc_msgSend(PTR_s_List_001f9d80,PTR_s_alloc_001f9210,PTR_s_init_001f924c);
  uVar1 = _objc_msgSend(uVar1);
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  iVar2 = _objc_msgSend(*(undefined4 *)(param_1 + 4),PTR_s_valueForStringKey__001f9308,
                        s_Bus_Type_001e0ffb);
  uVar1 = _objc_msgSend(PTR_s_KernBus_001f9d8c,PTR_s_lookupBusClassWithName__001f930c,iVar2);
  *(undefined4 *)(param_1 + 0x18) = uVar1;
  iVar3 = _objc_msgSend(*(undefined4 *)(param_1 + 4),PTR_s_valueForStringKey__001f9308,
                        s_Bus_ID_001e1004);
  if (iVar3 != 0) {
    iVar4 = FUN_00180f48(iVar3,0,&local_10);
    if (iVar4 != 0) {
      *(undefined4 *)(param_1 + 0x20) = local_10;
    }
  }
  uVar1 = _objc_msgSend(PTR_s_KernBus_001f9d8c,PTR_s_lookupBusInstanceWithName_busId__001f9310,iVar2
                        ,*(undefined4 *)(param_1 + 0x20));
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  if (iVar3 != 0) {
    _objc_msgSend(*(undefined4 *)(param_1 + 4),PTR_s_freeString__001f9314,iVar3);
  }
  if (iVar2 != 0) {
    _objc_msgSend(*(undefined4 *)(param_1 + 4),PTR_s_freeString__001f9314,iVar2);
  }
  return param_1;
}

