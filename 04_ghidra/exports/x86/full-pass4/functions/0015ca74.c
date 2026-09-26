/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015ca74 */

int _load_machfile(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_18 [5];
  
  iVar1 = *(int *)(*(int *)(_active_threads + 0xc) + 0xc);
  uVar2 = *(undefined4 *)(iVar1 + 0x24);
  _pmap_reference(uVar2);
  uVar2 = _vm_map_create(uVar2,*(undefined4 *)(iVar1 + 0x14),*(undefined4 *)(iVar1 + 0x18),
                         *(undefined4 *)(iVar1 + 0x20));
  if (param_5 == (undefined4 *)0x0) {
    param_5 = local_18;
  }
  _memset(param_5,0,0x14);
  *param_5 = 0;
  iVar3 = FUN_0015cb1c(param_1,uVar2,param_2,param_3,param_4,0,0,param_5);
  if (iVar3 == 0) {
    *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc) = uVar2;
    _vm_map_deallocate(iVar1);
    iVar3 = 0;
  }
  else {
    _vm_map_deallocate(uVar2);
  }
  return iVar3;
}

