/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b464c */

int FUN_001b464c(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = _objc_msgSend(param_3,PTR_s_conformsTo__001f9238,&DAT_001fdf5c);
  if (cVar1 == '\0') {
    uVar2 = _object_getClassName(param_3);
    _IOLog("KeyMap setDelegate: new delegate [%s] does not implement KeyMapDelegate protocol.\n",
           uVar2);
  }
  else {
    *(undefined4 *)(param_1 + 0x4f8) = param_3;
  }
  return param_1;
}

