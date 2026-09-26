/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00190f90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00190f90(int *param_1,uint param_2,uint param_3,uint param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  
  param_1[5] = param_1[5] - param_4;
  param_1[4] = param_1[4] - param_3;
  if ((_kernel_pmap != param_1) &&
     (puVar3 = (uint *)(*param_1 + ((-_section_size & param_2) >> 0x16) * 4), (*puVar3 & 1) != 0)) {
    piVar1 = *(int **)(_pg_desc_tbl + 0xc +
                      (((*puVar3 & 0xfffff000) - __pg_first_phys >> 0xc) >>
                      ((char)_ptes_per_vm_page - 1U & 0x1f)) * 0x14);
    if (*(ushort *)((int)piVar1 + 0x1a) < param_4) {
                    /* WARNING: Subroutine does not return */
      _panic(s_pmap_deallocate_mappings_unwire_001e25c5);
    }
    *(short *)((int)piVar1 + 0x1a) = *(short *)((int)piVar1 + 0x1a) - (short)param_4;
    if (*(ushort *)(piVar1 + 6) < param_3) {
                    /* WARNING: Subroutine does not return */
      _panic(s_pmap_deallocate_mappings_001e25e5);
    }
    param_3._0_2_ = (short)piVar1[6] - (short)param_3;
    *(short *)(piVar1 + 6) = (short)param_3;
    if ((param_5 != 0) && (iVar2 = _ptes_per_vm_page, (short)param_3 == 0)) {
      while (0 < iVar2) {
        *(byte *)puVar3 = (byte)*puVar3 & 0xfe;
        puVar3 = puVar3 + 1;
        iVar2 = iVar2 + -1;
      }
      *(int *)(*piVar1 + 4) = piVar1[1];
      *(int *)piVar1[1] = *piVar1;
      __pt_active_count = __pt_active_count + -1;
      *piVar1 = (int)&_pt_free_queue;
      piVar1[1] = (int)DAT_001f7adc;
      *(int **)piVar1[1] = piVar1;
      __pt_free_count = __pt_free_count + 1;
      DAT_001f7adc = piVar1;
    }
  }
  return;
}

