/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00190f24 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00190f24(int *param_1,uint param_2,int param_3)

{
  short *psVar1;
  int iVar2;
  uint *puVar3;
  
  param_1[4] = param_1[4] + 1;
  if (param_3 != 0) {
    param_1[5] = param_1[5] + 1;
  }
  if ((_kernel_pmap != param_1) &&
     (puVar3 = (uint *)(((-_section_size & param_2) >> 0x16) * 4 + *param_1), (*puVar3 & 1) != 0)) {
    iVar2 = *(int *)(_pg_desc_tbl + 0xc +
                    (((*puVar3 & 0xfffff000) - __pg_first_phys >> 0xc) >>
                    ((char)_ptes_per_vm_page - 1U & 0x1f)) * 0x14);
    psVar1 = (short *)(iVar2 + 0x18);
    *psVar1 = *psVar1 + 1;
    if (param_3 != 0) {
      psVar1 = (short *)(iVar2 + 0x1a);
      *psVar1 = *psVar1 + 1;
    }
  }
  return;
}

