/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00173fbc */

int _kmem_suballoc(int param_1,int *param_2,int *param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int local_8;
  
  uVar3 = param_4 + _page_mask & ~_page_mask;
  _vm_object_reference(_vm_submap_object);
  local_8 = *(int *)(param_1 + 0x14);
  iVar1 = _vm_map_find(param_1,_vm_submap_object,0,&local_8,uVar3,1);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_kmem_suballoc_1_001e0a16);
  }
  _pmap_reference(*(undefined4 *)(param_1 + 0x24));
  iVar1 = _vm_map_create(*(undefined4 *)(param_1 + 0x24),local_8,uVar3 + local_8,param_5);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_kmem_suballoc_2_001e0a26);
  }
  iVar2 = _vm_map_submap(param_1,local_8,uVar3 + local_8,iVar1);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_kmem_suballoc_3_001e0a36);
  }
  *param_2 = local_8;
  *param_3 = uVar3 + local_8;
  return iVar1;
}

