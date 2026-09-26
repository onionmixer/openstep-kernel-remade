/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018f69c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _pmap_destroy(uint *param_1)

{
  uint uVar1;
  ushort uVar2;
  int *piVar3;
  byte bVar4;
  undefined4 uVar5;
  uint *puVar6;
  int iVar7;
  
  if (param_1 != (uint *)0x0) {
    uVar5 = _splvm();
    puVar6 = param_1 + 3;
    do {
      do {
      } while (*puVar6 != 0);
      LOCK();
      uVar1 = *puVar6;
      *puVar6 = 1;
      UNLOCK();
    } while (uVar1 == 1);
    uVar1 = param_1[2];
    param_1[2] = uVar1 - 1;
    LOCK();
    param_1[3] = 0;
    UNLOCK();
    _splx(uVar5);
    if (uVar1 == 1) {
      uVar1 = *param_1;
      puVar6 = (uint *)((uVar1 >> 0x16) * 4 + *_kernel_pmap);
      if ((((*puVar6 & 1) == 0) ||
          (puVar6 = (uint *)((uVar1 >> 10 & 0xffc) + (*puVar6 & 0xfffff000)), puVar6 == (uint *)0x0)
          ) || ((*puVar6 & 1) == 0)) {
        iVar7 = 0;
      }
      else {
        iVar7 = (uVar1 & 0xfff) + (*puVar6 & 0xfffff000);
      }
      iVar7 = _pg_desc_tbl +
              (((uint)(iVar7 - __pg_first_phys) >> 0xc) >> ((char)_ptes_per_vm_page - 1U & 0x1f)) *
              0x14;
      piVar3 = *(int **)(iVar7 + 0xc);
      uVar2 = *(ushort *)(piVar3 + 6);
      *(short *)(piVar3 + 6) = (short)piVar3[6] + -1;
      if (_ptes_per_vm_page == uVar2) {
        *piVar3 = (int)_pd_free_queue;
        piVar3[1] = (int)&_pd_free_queue;
        *(int **)(*piVar3 + 4) = piVar3;
        __pd_free_count = __pd_free_count + 1;
        _pd_free_queue = piVar3;
      }
      bVar4 = (byte)(*param_1 - *(int *)(iVar7 + 8) >> 0xc) & 0x1f;
      *(byte *)(piVar3 + 7) =
           *(byte *)(piVar3 + 7) & ((byte)(-2 << bVar4) | (byte)(0xfffffffe >> 0x20 - bVar4));
      _zfree(_pmap_zone,param_1);
    }
  }
  return;
}

