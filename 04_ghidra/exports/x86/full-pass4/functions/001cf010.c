/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cf010 */

void __objc_add_category(undefined4 *param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  piVar1 = (int *)_objc_getClass(param_1[1]);
  if (piVar1 == (int *)0x0) {
    __objc_inform("unable to add category %s...\n",*param_1);
    uVar2 = param_1[1];
    pcVar3 = "class `%s\' not linked into application\n";
  }
  else {
    if (param_1[2] != 0) {
      *(int *)param_1[2] = piVar1[7];
      piVar1[7] = param_1[2];
    }
    if (param_1[3] != 0) {
      *(undefined4 *)param_1[3] = *(undefined4 *)(*piVar1 + 0x1c);
      *(undefined4 *)(*piVar1 + 0x1c) = param_1[3];
    }
    if ((param_2 < 5) || (param_1[4] == 0)) goto LAB_001cf0ba;
    if (4 < *(int *)(*piVar1 + 0xc)) {
      *(int *)param_1[4] = piVar1[9];
      piVar1[9] = param_1[4];
      *(undefined4 *)(*piVar1 + 0x24) = param_1[4];
      goto LAB_001cf0ba;
    }
    __objc_inform("unable to add protocols from category %s...\n",*param_1);
    uVar2 = param_1[1];
    pcVar3 = "class `%s\' must be recompiled\n";
  }
  __objc_inform(pcVar3,uVar2);
LAB_001cf0ba:
  uVar2 = _objc_getClass(param_1[1]);
  __objc_flush_caches(uVar2);
  return;
}

