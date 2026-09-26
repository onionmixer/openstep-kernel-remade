/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c9694 */

int FUN_001c9694(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = _objc_msgSend(param_1,PTR_s_class_001f9234,PTR_s_allocFromZone__001f9d58,param_3,
                        PTR_s_initCount__001f92dc,*(undefined4 *)(param_1 + 8));
  uVar1 = _objc_msgSend(uVar1);
  iVar2 = _objc_msgSend(uVar1);
  *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(param_1 + 8);
  _memmove(*(void **)(iVar2 + 4),*(void **)(param_1 + 4),*(int *)(param_1 + 8) * 4);
  return iVar2;
}

