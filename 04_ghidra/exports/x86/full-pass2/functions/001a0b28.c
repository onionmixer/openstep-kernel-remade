/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a0b28 */

bool FUN_001a0b28(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = _objc_msgSend(param_3,PTR_s_conformsTo__001f9238,&DAT_001fdda4);
  if (cVar1 != '\0') {
    *(undefined4 *)(param_1 + 0x128) = param_3;
  }
  else {
    uVar2 = _object_getClassName(param_3);
    _IOLog(s_PCPointer_setEventTarget__new_ta_001e4ad2,uVar2);
  }
  return cVar1 != '\0';
}

