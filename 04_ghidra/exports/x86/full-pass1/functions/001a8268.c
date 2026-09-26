/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a8268 */

int FUN_001a8268(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
  iVar4 = 0;
  iVar1 = _objc_msgSend(param_3,PTR_s_count_001f92d8);
  if (0 < iVar1) {
    iVar4 = _IOMalloc(iVar1 * 8);
    iVar3 = 0;
    if (0 < iVar1) {
      do {
        uVar2 = _objc_msgSend(param_3,PTR_s_objectAt__001f92e8,iVar3,PTR_s_range_001f9278);
        uVar5 = _objc_msgSend(uVar2);
        *(int *)(iVar4 + iVar3 * 8) = (int)uVar5;
        *(int *)(iVar4 + 4 + iVar3 * 8) = (int)((ulonglong)uVar5 >> 0x20);
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar1);
    }
  }
  *param_4 = iVar1;
  return iVar4;
}

