/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018fd2c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _pmap_copy_on_write(uint param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  byte bVar3;
  int *piVar4;
  undefined4 uVar5;
  uint *puVar6;
  int iVar7;
  byte bVar8;
  int *piVar9;
  uint uVar10;
  byte *pbVar11;
  int in_FS_OFFSET;
  
  if ((_vm_first_phys <= param_1) && (param_1 < _vm_last_phys)) {
    uVar5 = _splvm();
    puVar1 = (undefined4 *)
             (_pg_desc_tbl +
             ((param_1 - __pg_first_phys >> 0xc) >> ((char)_ptes_per_vm_page - 1U & 0x1f)) * 0x14);
    if (puVar1[1] != 0) {
      for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
        piVar4 = (int *)puVar1[1];
        uVar10 = puVar1[2];
        piVar9 = piVar4 + 3;
        do {
          do {
          } while (*piVar9 != 0);
          LOCK();
          iVar7 = *piVar9;
          *piVar9 = 1;
          UNLOCK();
        } while (iVar7 == 1);
        puVar6 = (uint *)((uVar10 >> 0x16) * 4 + *piVar4);
        if ((((*puVar6 & 1) == 0) ||
            (pbVar11 = (byte *)((uVar10 >> 10 & 0xffc) + (*puVar6 & 0xfffff000)),
            pbVar11 == (byte *)0x0)) || ((*pbVar11 & 1) == 0)) {
                    /* WARNING: Subroutine does not return */
          _panic(s_pmap_copy_on_write_001e2593);
        }
        uVar2 = _page_size + uVar10;
        if (((piVar4 == _kernel_pmap) || (piVar4[6] != 0)) &&
           (__tlb_stat = __tlb_stat + 1, uVar2 - uVar10 <= _page_size)) {
          for (; uVar10 < uVar2; uVar10 = uVar10 + 0x1000) {
            if (piVar4 == _kernel_pmap) {
              invlpg(uVar10);
            }
            else {
              invlpg(in_FS_OFFSET + uVar10);
            }
          }
          _DAT_001f7af4 = _DAT_001f7af4 + 1;
        }
        iVar7 = _ptes_per_vm_page;
        if (((*pbVar11 & 6) == 6) || ((*pbVar11 & 6) == 2)) {
          while (0 < iVar7) {
            bVar3 = *pbVar11;
            bVar8 = (byte)DAT_001f7b04;
            if (_kernel_pmap == piVar4) {
              bVar8 = (byte)DAT_001f7a84;
            }
            *pbVar11 = bVar3 & 0xf9 | (bVar8 & 3) * '\x02';
            *pbVar11 = *pbVar11 & 0xfe | bVar3 & 1;
            pbVar11 = pbVar11 + 4;
            iVar7 = iVar7 + -1;
          }
        }
        LOCK();
        piVar4[3] = 0;
        UNLOCK();
      }
    }
    _splx(uVar5);
  }
  return;
}

