/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00182578 */

undefined4 _kern_IOUnloadDriver(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    uVar1 = 0xfffffd3f;
  }
  else {
    iVar2 = _objc_msgSend(PTR_s_IOConfigTable_001f9d90,PTR_s_newForConfigData__001f937c,param_2);
    uVar1 = _objc_msgSend(iVar2,PTR_s_valueForStringKey__001f9308,s_Driver_Name_001e10e1);
    iVar3 = _objc_getClass(uVar1);
    if (iVar3 == 0) {
      _IOLog(s_IOUnloadDriver__Couldn_t_find_cl_001e10ed,uVar1);
      if (iVar2 != 0) {
        _objc_msgSend(iVar2,PTR_s_free_001f921c);
      }
      uVar1 = 0xfffffd3e;
    }
    else {
      _objc_msgSend(iVar3,PTR_s_unregisterClass__001f9380,iVar3);
      if (iVar2 != 0) {
        _objc_msgSend(iVar2,PTR_s_free_001f921c);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}

