
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _pmap_enter(int *param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint *puVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  int in_FS_OFFSET;
  undefined4 local_14;
  undefined4 *local_10;
  uint local_8;
  
  if (param_1 != (int *)0x0) {
    if (param_4 == 0) {
      uVar7 = param_2 + _page_size;
      uVar2 = _splvm();
      if (((param_1 == _kernel_pmap) || (param_1[6] != 0)) &&
         (__tlb_stat = __tlb_stat + 1, uVar6 = param_2, uVar7 - param_2 <= _page_size)) {
        for (; uVar6 < uVar7; uVar6 = uVar6 + 0x1000) {
          if (param_1 == _kernel_pmap) {
            invlpg(uVar6);
          }
          else {
            invlpg(in_FS_OFFSET + uVar6);
          }
        }
        _DAT_001f7af4 = _DAT_001f7af4 + 1;
      }
      while (param_2 < uVar7) {
        uVar6 = _section_size + -1 + param_2 + _page_size & -_section_size;
        if (uVar7 < uVar6) {
          uVar6 = uVar7;
        }
        FUN_0018f7f8(param_1,param_2,uVar6,1);
        param_2 = uVar6;
      }
      _splx(uVar2);
    }
    else {
      local_10 = (undefined4 *)0x0;
LAB_0019075c:
      local_14 = _splvm();
      while ((puVar3 = (uint *)((param_2 >> 0x16) * 4 + *param_1), (*puVar3 & 1) == 0 ||
             (puVar3 = (uint *)((param_2 >> 10 & 0xffc) + (*puVar3 & 0xfffff000)),
             puVar3 == (uint *)0x0))) {
        _splx(local_14);
        FUN_00190cfc(param_1,param_2);
        local_14 = _splvm();
      }
      if ((*puVar3 & 1) == 0) {
LAB_00190998:
        if ((_vm_first_phys <= param_3) && (param_3 < _vm_last_phys)) {
          puVar1 = (undefined4 *)
                   (_pg_desc_tbl +
                   ((param_3 - __pg_first_phys >> 0xc) >> ((char)_ptes_per_vm_page - 1U & 0x1f)) *
                   0x14);
          if (puVar1[1] == 0) {
            puVar1[2] = param_2;
            puVar1[1] = param_1;
            *puVar1 = 0;
          }
          else {
            if (local_10 == (undefined4 *)0x0) goto code_r0x001909f6;
            local_10[2] = param_2;
            local_10[1] = param_1;
            *local_10 = *puVar1;
            *puVar1 = local_10;
            local_10 = (undefined4 *)0x0;
          }
        }
        FUN_00190f24(param_1,param_2,param_5);
        if (_kernel_pmap == param_1) {
          bVar5 = *(byte *)(&_kernel_prot_codes + param_4);
        }
        else {
          bVar5 = *(byte *)(&_user_prot_codes + param_4);
        }
        local_8 = (byte)((bVar5 & 3) * '\x02') | 1 | param_3 & 0xfffff000;
        iVar4 = _ptes_per_vm_page;
        if (param_5 != 0) {
          local_8 = local_8 | 0x200;
        }
        while (0 < iVar4) {
          *puVar3 = local_8;
          local_8 = local_8 & 0xfff | (local_8 & 0xfffff000) + 0x1000;
          puVar3 = puVar3 + 1;
          iVar4 = iVar4 + -1;
        }
      }
      else {
        if (param_3 != (*puVar3 & 0xfffff000)) {
          if (((param_1 == _kernel_pmap) || (param_1[6] != 0)) &&
             (__tlb_stat = __tlb_stat + 1, uVar7 = param_2,
             (param_2 + _page_size) - param_2 <= _page_size)) {
            for (; uVar7 < param_2 + _page_size; uVar7 = uVar7 + 0x1000) {
              if (param_1 == _kernel_pmap) {
                invlpg(uVar7);
              }
              else {
                invlpg(in_FS_OFFSET + uVar7);
              }
            }
            _DAT_001f7af4 = _DAT_001f7af4 + 1;
          }
          FUN_0018f7f8(param_1,param_2,param_2 + _page_size,0);
          goto LAB_00190998;
        }
        if (param_5 == 0) {
          if ((*puVar3 & 0x200) != 0) {
            FUN_001910e4(param_1,param_2);
          }
        }
        else if ((*puVar3 & 0x200) == 0) {
          FUN_0019108c(param_1,param_2);
        }
        if (_kernel_pmap == param_1) {
          bVar5 = *(byte *)(&_kernel_prot_codes + param_4);
        }
        else {
          bVar5 = *(byte *)(&_user_prot_codes + param_4);
        }
        local_8 = (byte)((bVar5 & 3) * '\x02') | 1 | param_3 & 0xfffff000;
        if (param_5 != 0) {
          local_8 = local_8 | 0x200;
        }
        uVar7 = param_2 + _page_size;
        iVar4 = _ptes_per_vm_page;
        if (((param_1 == _kernel_pmap) || (param_1[6] != 0)) &&
           (__tlb_stat = __tlb_stat + 1, uVar7 - param_2 <= _page_size)) {
          for (; param_2 < uVar7; param_2 = param_2 + 0x1000) {
            if (param_1 == _kernel_pmap) {
              invlpg(param_2);
            }
            else {
              invlpg(in_FS_OFFSET + param_2);
            }
          }
          _DAT_001f7af4 = _DAT_001f7af4 + 1;
        }
        while (0 < iVar4) {
          if ((*puVar3 & 0x40) != 0) {
            local_8 = local_8 | 0x40;
          }
          *puVar3 = local_8;
          local_8 = local_8 & 0xfff | (local_8 & 0xfffff000) + 0x1000;
          puVar3 = puVar3 + 1;
          iVar4 = iVar4 + -1;
        }
      }
      _splx(local_14);
      if (local_10 != (undefined4 *)0x0) {
        _zfree(_pv_entry_zone,local_10);
      }
    }
  }
  return;
code_r0x001909f6:
  _splx(local_14);
  local_10 = (undefined4 *)_zalloc(_pv_entry_zone);
  goto LAB_0019075c;
}

