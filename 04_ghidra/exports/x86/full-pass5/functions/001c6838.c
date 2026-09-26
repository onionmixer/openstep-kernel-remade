/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c6838 */

undefined4 FUN_001c6838(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_8;
  
  iVar3 = 0;
  if (param_3 == 0) {
    iVar3 = _objc_msgSend(param_1,PTR_s_mapMemoryRange_to_findSpace_cach_001f95e0,0,&local_8,1,1);
  }
  else {
    uVar1 = _current_task_EXTERNAL(1,1);
    iVar2 = __KernBusMemoryCreateMapping(param_3,param_4,&local_8,uVar1);
    if (iVar2 != 0) {
      iVar3 = -0x2bd;
      goto LAB_001c6894;
    }
  }
  if (iVar3 == 0) {
    return local_8;
  }
LAB_001c6894:
  uVar1 = _objc_msgSend(param_1,PTR_s_stringFromReturn__001f9490,iVar3);
  _IOLog("IOSVGADisplay/mapFrameBuffer: Can\'t map memory (%s)\n",uVar1);
  return 0;
}

