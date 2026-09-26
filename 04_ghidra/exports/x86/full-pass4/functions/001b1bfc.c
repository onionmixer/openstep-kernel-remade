/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b1bfc */

undefined4 FUN_001b1bfc(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = _objc_msgSend(*param_3,PTR_s_respondsTo__001f9464,param_3[1]);
  if (cVar1 == '\0') {
    uVar2 = _sel_getName(param_3[1]);
    uVar2 = _object_getClassName(*param_3,uVar2);
    uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,uVar2);
    _IOLog("%s: _doPerformInIOThread: [%s] does not respond to SEL [%s]\n",uVar2);
    uVar2 = 0xfffffd41;
  }
  else {
    _objc_msgSend(*param_3,PTR_s_perform_with__001f923c,param_3[1],param_3[2]);
    uVar2 = 0;
  }
  return uVar2;
}

