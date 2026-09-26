/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cef90 */

void __objc_remove_category(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_objc_getClass(param_1[1]);
  if (puVar1 == (undefined4 *)0x0) {
    __objc_inform("unable to remove category %s...\n",*param_1);
    __objc_inform("class `%s\' not linked into application\n",param_1[1]);
  }
  else {
    if (param_1[2] != 0) {
      _class_removeMethods(puVar1,param_1[2]);
    }
    if (param_1[3] != 0) {
      _class_removeMethods(*puVar1,param_1[3]);
    }
    if ((4 < param_2) && (param_1[4] != 0)) {
      __class_removeProtocols(puVar1,param_1[4]);
    }
  }
  return;
}

