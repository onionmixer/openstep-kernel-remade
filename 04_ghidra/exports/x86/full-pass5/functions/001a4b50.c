/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a4b50 */

int FUN_001a4b50(undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4,
                char *param_5)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  undefined4 local_8;
  
  _objc_msgSend(DAT_001e8674,PTR_s_lock_001f9220);
  iVar1 = FUN_001a3d58(param_3,&local_8);
  _objc_msgSend(DAT_001e8674,PTR_s_unlock_001f9474);
  if (iVar1 == 0) {
    sVar3 = 0x50;
    pcVar2 = (char *)_objc_msgSend(local_8,PTR_s_deviceKind_001f9cc4);
    _strncpy(param_4,pcVar2,sVar3);
    sVar3 = 0x50;
    pcVar2 = (char *)_objc_msgSend(local_8,PTR_s_name_001f9228);
    _strncpy(param_5,pcVar2,sVar3);
  }
  return iVar1;
}

