/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c8dec */

undefined4 FUN_001c8dec(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 local_14;
  undefined4 local_10;
  undefined8 local_c;
  
  uVar2 = _objc_msgSend(param_1,PTR_s_class_001f9234,PTR_s_allocFromZone__001f9d58,param_3,
                        PTR_s_initKeyDesc_valueDesc_capacity__001f9d50,*(undefined4 *)(param_1 + 8),
                        *(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 4));
  uVar2 = _objc_msgSend(uVar2);
  uVar2 = _objc_msgSend(uVar2);
  local_c = _objc_msgSend(param_1,PTR_s_initState_001f9324);
  while( true ) {
    cVar1 = _objc_msgSend(param_1,PTR_s_nextState_key_value__001f9328,&local_c,&local_10,&local_14);
    if (cVar1 == '\0') break;
    _objc_msgSend(uVar2,PTR_s_insertKey_value__001f9288,local_10,local_14);
  }
  return uVar2;
}

