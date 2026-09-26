/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c6670 */

undefined4
FUN_001c6670(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  puVar2 = (undefined4 *)_objc_msgSend(param_1,PTR_s__shmem_001f95d8);
  iVar3 = _ev_try_lock(puVar2 + 1);
  if (iVar3 != 0) {
    *puVar2 = param_4;
    puVar2[7] = *param_3;
    cVar1 = *(char *)(puVar2 + 2);
    *(char *)(puVar2 + 2) = *(char *)(puVar2 + 2) + '\x01';
    if (cVar1 == '\0') {
      uVar4 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610,puVar2);
      _objc_msgSend(param_1,PTR_s__VGARemoveCursor_shmem__001f95b0,uVar4);
    }
    if (*(char *)((int)puVar2 + 9) != '\0') {
      *(undefined1 *)((int)puVar2 + 9) = 0;
      if (*(char *)(puVar2 + 2) != '\0') {
        *(char *)(puVar2 + 2) = *(char *)(puVar2 + 2) + -1;
      }
    }
    if (*(char *)((int)puVar2 + 10) != '\0') {
      uVar4 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610,puVar2);
      _objc_msgSend(param_1,PTR_s__checkShield_shmem__001f95a0,uVar4);
    }
    cVar1 = *(char *)(puVar2 + 2);
    if ((cVar1 != '\0') && (*(char *)(puVar2 + 2) = cVar1 + -1, cVar1 == '\x01')) {
      uVar4 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610,puVar2);
      _objc_msgSend(param_1,PTR_s__displayCursor_shmem__001f95ac,uVar4);
    }
    _ev_unlock(puVar2 + 1);
  }
  return param_1;
}

