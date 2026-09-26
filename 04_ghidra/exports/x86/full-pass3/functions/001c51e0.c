/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c51e0 */

undefined4 FUN_001c51e0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_8;
  
  iVar4 = 0;
  iVar1 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
  uVar2 = *(uint *)(iVar1 + 0x60) & 0xc;
  if (uVar2 == 4) {
    uVar3 = 2;
  }
  else if ((uVar2 < 5) || (uVar2 != 8)) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  if (param_3 == 0) {
    iVar4 = _objc_msgSend(param_1,PTR_s_mapMemoryRange_to_findSpace_cach_001f95e0,0,&local_8,1,uVar3
                         );
  }
  else {
    uVar3 = _current_task_EXTERNAL(1,uVar3);
    iVar1 = __KernBusMemoryCreateMapping(param_3,param_4,&local_8,uVar3);
    if (iVar1 != 0) {
      iVar4 = -0x2bd;
      goto LAB_001c526f;
    }
  }
  if (iVar4 == 0) {
    return local_8;
  }
LAB_001c526f:
  uVar3 = _objc_msgSend(param_1,PTR_s_stringFromReturn__001f9490,iVar4);
  _IOLog("IOFrameBufferDisplay/mapFrameBuffer: Can\'t map memory (%s)\n",uVar3);
  return 0;
}

