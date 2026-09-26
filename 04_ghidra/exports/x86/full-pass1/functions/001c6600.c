/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c6600 */

undefined4 FUN_001c6600(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _objc_msgSend(param_1,PTR_s__shmem_001f95d8);
  iVar1 = _ev_try_lock(iVar1 + 4);
  if (iVar1 != 0) {
    uVar2 = _objc_msgSend(param_1,PTR_s__shmem_001f95d8);
    uVar2 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610,uVar2);
    _objc_msgSend(param_1,PTR_s__sysHideCursor_shmem__001f95a8,uVar2);
    iVar1 = _objc_msgSend(param_1,PTR_s__shmem_001f95d8);
    _ev_unlock(iVar1 + 4);
  }
  return param_1;
}

