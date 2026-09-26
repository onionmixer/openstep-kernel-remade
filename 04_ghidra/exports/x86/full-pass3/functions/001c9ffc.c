/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c9ffc */

void FUN_001c9ffc(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = _sel_getName(param_3);
  uVar2 = 0x2d;
  if ((*(byte *)(*param_1 + 0x10) & 2) != 0) {
    uVar2 = 0x2b;
  }
  _objc_msgSend(param_1,PTR_s_error__001f9d20,"does not recognize selector %c%s",uVar2,uVar1);
  return;
}

