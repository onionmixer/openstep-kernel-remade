/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c6764 */

undefined4
FUN_001c6764(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)_objc_msgSend(param_1,PTR_s__shmem_001f95d8);
  iVar2 = _ev_try_lock(puVar1 + 1);
  if (iVar2 != 0) {
    *puVar1 = param_4;
    puVar1[7] = *param_3;
    if (*(char *)((int)puVar1 + 10) != '\0') {
      uVar3 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610,puVar1);
      _objc_msgSend(param_1,PTR_s__checkShield_shmem__001f95a0,uVar3);
    }
    uVar3 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610,puVar1);
    _objc_msgSend(param_1,PTR_s__sysShowCursor_shmem__001f95a4,uVar3);
    _ev_unlock(puVar1 + 1);
  }
  return param_1;
}

