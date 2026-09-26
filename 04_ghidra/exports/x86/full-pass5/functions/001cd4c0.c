/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cd4c0 */

uint _class_lookupMethod(int param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  if (param_2 == 0) {
    _objc_msgSend(param_1,PTR_s_error__001f9d20,"invalid selector %s",0);
  }
  iVar2 = *(int *)(param_1 + 0x20) + 8;
  uVar3 = param_2;
  while( true ) {
    uVar3 = **(uint **)(param_1 + 0x20) & uVar3;
    if (*(int *)(iVar2 + uVar3 * 4) == 0) {
      uVar3 = __class_lookupMethodAndLoadCache(param_1,param_2);
      return uVar3;
    }
    puVar1 = *(uint **)(iVar2 + uVar3 * 4);
    if (*puVar1 == param_2) break;
    uVar3 = uVar3 + 1;
  }
  return puVar1[2];
}

