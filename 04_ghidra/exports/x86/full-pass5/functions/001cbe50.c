/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cbe50 */

undefined4 _NXUniqueStringWithLength(void *param_1,size_t param_2)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined1 local_104 [256];
  
  if ((int)(param_2 + 1) < 0x101) {
    puVar1 = local_104;
  }
  else {
    puVar1 = _malloc(param_2 + 1);
  }
  _memmove(puVar1,param_1,param_2);
  puVar1[param_2] = 0;
  uVar2 = _NXUniqueString(puVar1);
  if (0x100 < (int)(param_2 + 1)) {
    _free(puVar1);
  }
  return uVar2;
}

