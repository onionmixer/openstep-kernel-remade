/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cf570 */

void FUN_001cf570(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint local_8;
  
  iVar1 = _getsectdatafromheaderinfo(param_1,"__OBJC","__cls_refs",&local_8);
  if (iVar1 != 0) {
    for (uVar3 = 0; uVar3 < local_8 >> 2; uVar3 = uVar3 + 1) {
      uVar2 = _objc_lookUpClass(*(undefined4 *)(iVar1 + uVar3 * 4));
      *(undefined4 *)(iVar1 + uVar3 * 4) = uVar2;
    }
  }
  return;
}

