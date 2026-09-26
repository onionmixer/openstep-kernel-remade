/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001816b4 */

undefined4 FUN_001816b4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined *puVar4;
  
  pcVar1 = (char *)_objc_msgSend(param_1,PTR_s_stringForKey__001f932c,param_3);
  if (pcVar1 != (char *)0x0) {
    pcVar2 = _strchr(pcVar1,0x2d);
    puVar4 = PTR_s__parseItemResourceByKey_value__001f9334;
    if (pcVar2 != (char *)0x0) {
      puVar4 = PTR_s__parseRangeResourceByKey_value__001f9330;
    }
    iVar3 = _objc_msgSend(param_1,puVar4,param_3,pcVar1);
    if (iVar3 == 0) {
      param_1 = 0;
    }
    else {
      _objc_msgSend(param_1,PTR_s_setResources_forKey__001f9338,iVar3,param_3);
    }
  }
  return param_1;
}

