/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cd300 */

void __class_install_relationships(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  
  bVar2 = false;
  puVar1 = (undefined4 *)*param_1;
  puVar1[3] = param_2;
  if (param_1[1] != 0) {
    iVar3 = _objc_getClass(param_1[1]);
    if (iVar3 == 0) {
      bVar2 = true;
    }
    else {
      param_1[1] = iVar3;
    }
  }
  puVar4 = (undefined4 *)_objc_getClass(*puVar1);
  if (puVar4 == (undefined4 *)0x0) {
    bVar2 = true;
  }
  else {
    *puVar1 = *puVar4;
  }
  if (puVar1[1] == 0) {
    puVar1[1] = param_1;
  }
  else {
    puVar4 = (undefined4 *)_objc_getClass(puVar1[1]);
    if (puVar4 == (undefined4 *)0x0) {
      bVar2 = true;
    }
    else {
      puVar1[1] = *puVar4;
    }
  }
  if (param_1[8] == 0) {
    param_1[8] = (int)&_emptyCache;
  }
  if (puVar1[8] == 0) {
    puVar1[8] = &_emptyCache;
  }
  if (bVar2) {
    __objc_fatal("please link appropriate classes in your program");
  }
  return;
}

