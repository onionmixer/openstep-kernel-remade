/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b18a0 */

undefined4
FUN_001b18a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  void *pvVar2;
  
  iVar1 = _objc_msgSend(param_1,PTR_s_specialKeyPort__001f99f0,param_3);
  if ((iVar1 != 0) && (pvVar2 = (void *)_IOMalloc(0x38), pvVar2 != (void *)0x0)) {
    _bcopy(&DAT_001d5d90,pvVar2,0x38);
    *(int *)((int)pvVar2 + 0x10) = iVar1;
    *(undefined4 *)((int)pvVar2 + 0x1c) = param_3;
    *(undefined4 *)((int)pvVar2 + 0x24) = param_4;
    *(undefined4 *)((int)pvVar2 + 0x2c) = param_5;
    *(undefined4 *)((int)pvVar2 + 0x34) = param_6;
    _objc_msgSend(param_1,PTR_s_sendIOThreadAsyncMsg_to_with__001f99e8,
                  PTR_s__performSpecialKeyMsg__001f99ec,param_1,pvVar2);
  }
  return param_1;
}

