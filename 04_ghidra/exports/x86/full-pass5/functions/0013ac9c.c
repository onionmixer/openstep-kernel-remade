/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013ac9c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0013ac9c(int param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  byte bVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined4 uVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  int local_5c;
  uint local_c;
  uint local_8;
  
  iVar3 = *(int *)(param_1 + 0x30);
  puVar1 = (uint *)(iVar3 + 0x34);
  if ((*(byte *)(iVar3 + 0x79) & 1) != 0) {
    do {
      *(byte *)(iVar3 + 0x79) = *(byte *)(iVar3 + 0x79) | 2;
      _sleep(iVar3 + 0x79);
    } while ((*(byte *)(iVar3 + 0x79) & 1) != 0);
  }
  *(byte *)(iVar3 + 0x79) = *(byte *)(iVar3 + 0x79) | 1;
  if (_page_size != param_3) {
                    /* WARNING: Subroutine does not return */
    _panic(s_csize____PAGE_SIZE__shouldn_t_ha_001dd877);
  }
  if (param_4 < *(int *)(iVar3 + 0x38) * _page_size) {
LAB_0013ae8c:
    uVar12 = _compress_data_from_phys(param_2,_page_size,*(undefined4 *)(iVar3 + 0x70));
    if (_compress_window_size <= _compress_backoff_window) {
      bVar6 = _compress_backoff_cnt < _compress_threashold;
      if (bVar6) {
        __compress_backoff_off = __compress_backoff_off + 1;
        _compress_backoff_cnt = _compress_threashold;
      }
      else {
        __compress_backoff_on = __compress_backoff_on + 1;
        _compress_backoff_cnt = 0;
      }
      _compress_enable = (uint)!bVar6;
      _compress_backoff_window = 0;
    }
    if (_compress_enable == 0) {
      uVar12 = _page_size;
    }
    _compress_backoff_window = _compress_backoff_window + 1;
    *(int *)(&DAT_001e5a74 + (uVar12 / (_page_size >> 3)) * 4) =
         *(int *)(&DAT_001e5a74 + (uVar12 / (_page_size >> 3)) * 4) + 1;
    uVar12 = *puVar1 * (((*puVar1 - 1) + uVar12) / *puVar1);
    iVar8 = FUN_0013a61c(puVar1,param_4,uVar12,&local_8,&local_c);
    if (iVar8 == 0) {
      _printf(s_couldn_t_allocate_an_offset__001dd89d);
      iVar3 = *(int *)(param_1 + 0x30);
      bVar2 = *(byte *)(iVar3 + 0x79);
      *(byte *)(iVar3 + 0x79) = bVar2 & 0xfe;
      if ((bVar2 & 2) != 0) {
        *(byte *)(iVar3 + 0x79) = bVar2 & 0xfc;
        _wakeup(iVar3 + 0x79);
      }
      return 2;
    }
    if (uVar12 < _page_size) {
      uVar9 = local_8;
      if ((int)local_8 < 0) {
        uVar9 = local_8 + 0x1fff;
      }
      uVar10 = uVar12;
      if ((int)uVar12 < 0) {
        uVar10 = uVar12 + 0x3ff;
      }
      uVar11 = local_c;
      if ((int)local_c < 0) {
        uVar11 = local_c + 0x3ff;
      }
      if (1999 < _logswapindex) {
        _logswapindex = 0;
      }
      iVar7 = _logswapindex;
      iVar8 = _logswapindex * 0xc;
      (&_logswp)[_logswapindex * 3] = param_4;
      (&DAT_001ef304)[iVar7 * 3] = (int)uVar9 >> 0xd;
      (&DAT_001ef308)[iVar8] = (byte)(uVar10 >> 10) & 0xf | (&DAT_001ef308)[iVar8] & 0xf0;
      (&DAT_001ef308)[_logswapindex * 0xc] =
           (char)(uVar11 >> 10) << 4 | (&DAT_001ef308)[_logswapindex * 0xc] & 0xf;
      (&DAT_001ef309)[_logswapindex * 0xc] = 3;
      _logswapindex = _logswapindex + 1;
      puVar4 = *(undefined2 **)(iVar3 + 0x70);
      _DAT_001e5a44 = _DAT_001e5a44 + 1;
      local_5c._0_2_ = (undefined2)(local_8 >> 0xd);
      *puVar4 = (undefined2)local_5c;
      uVar9 = _page_size;
      if (local_8 == *(uint *)(iVar3 + 0x74)) {
        _DAT_001e5a48 = _DAT_001e5a48 + 1;
        _compress_backoff_cnt = _compress_backoff_cnt + 1;
        _bcopy(puVar4,(void *)(local_c + *(int *)(iVar3 + 0x68)),uVar12);
        if (*(uint *)(iVar3 + 0x60) == local_8) {
          __swpgotcha = __swpgotcha + 1;
          *(undefined4 *)(iVar3 + 0x60) = 0xffffffff;
          *(undefined1 *)(iVar3 + 100) = 0;
        }
        iVar8 = 0;
      }
      else {
        if (*(uint *)(iVar3 + 0x60) == local_8) {
          _DAT_001e5a4c = _DAT_001e5a4c + 1;
          _compress_backoff_cnt = _compress_backoff_cnt + 1;
          _bcopy(puVar4,(void *)(local_c + *(int *)(iVar3 + 0x58)),uVar12);
          *(undefined1 *)(iVar3 + 100) = 1;
        }
        else {
          if (*(uint *)(iVar3 + 0x74) != 0xffffffff) {
            _DAT_001e5a50 = _DAT_001e5a50 + 1;
            piVar13 = *(int **)(iVar3 + 0x3c);
            uVar5 = *(undefined4 *)(iVar3 + 0x6c);
            iVar8 = *(int *)(iVar3 + 0x74);
            uVar10 = _page_size + iVar8;
            if (*(uint *)(*piVar13 + 0x14) < uVar10) {
              *(uint *)(*piVar13 + 0x14) = uVar10;
            }
            iVar8 = (**(code **)(piVar13[7] + 0x78))(piVar13,uVar5,uVar9,iVar8);
            if (iVar8 != 0) {
              _printf(s_cannot_flush_output_cache__001dd82c);
              goto LAB_0013b2b4;
            }
          }
          *(uint *)(iVar3 + 0x74) = local_8;
          _bcopy(puVar4,(void *)(local_c + *(int *)(iVar3 + 0x68)),uVar12);
        }
        iVar8 = 0;
      }
      goto LAB_0013b2b4;
    }
    if (*(uint *)(iVar3 + 0x74) == local_8) {
      _DAT_001e5a54 = _DAT_001e5a54 + 1;
      *(undefined4 *)(iVar3 + 0x74) = 0xffffffff;
    }
    if (*(uint *)(iVar3 + 0x60) == local_8) {
      _DAT_001e5a58 = _DAT_001e5a58 + 1;
      *(undefined4 *)(iVar3 + 0x60) = 0xffffffff;
      *(undefined1 *)(iVar3 + 100) = 0;
    }
    _DAT_001e5a5c = _DAT_001e5a5c + 1;
    uVar9 = local_8;
    if ((int)local_8 < 0) {
      uVar9 = local_8 + 0x1fff;
    }
    if ((int)uVar12 < 0) {
      uVar12 = uVar12 + 0x3ff;
    }
    if ((int)local_c < 0) {
      local_c = local_c + 0x3ff;
    }
    if (1999 < _logswapindex) {
      _logswapindex = 0;
    }
    iVar7 = _logswapindex;
    iVar8 = _logswapindex * 0xc;
    (&_logswp)[_logswapindex * 3] = param_4;
    (&DAT_001ef304)[iVar7 * 3] = (int)uVar9 >> 0xd;
    (&DAT_001ef308)[iVar8] = (byte)(uVar12 >> 10) & 0xf | (&DAT_001ef308)[iVar8] & 0xf0;
    (&DAT_001ef308)[_logswapindex * 0xc] =
         (char)(local_c >> 10) << 4 | (&DAT_001ef308)[_logswapindex * 0xc] & 0xf;
    (&DAT_001ef309)[_logswapindex * 0xc] = 2;
    _logswapindex = _logswapindex + 1;
    piVar13 = *(int **)(iVar3 + 0x3c);
    if (*(uint *)(*piVar13 + 0x14) < param_3 + local_8) {
      *(uint *)(*piVar13 + 0x14) = param_3 + local_8;
    }
    local_5c = piVar13[7];
    param_4 = local_8;
  }
  else {
    if (_swapfs_cangrow == 1) {
      iVar8 = *(int *)(param_1 + 0x30);
      uVar12 = (*(int *)(iVar8 + 0x44) + 1) * _page_size;
      iVar7 = _kmem_mb_alloc(_swapfs_rem_map,_page_size);
      if (iVar7 == 0) {
LAB_0013adc8:
        _swapfs_cangrow = 0;
      }
      else {
        if (iVar7 != *(int *)(iVar8 + 0x44) * _page_size + *(int *)(iVar8 + 0x40)) {
                    /* WARNING: Subroutine does not return */
          _panic(s_swapfs_grow__bad_rem_001dd848);
        }
        *(uint *)(iVar8 + 0x38) = uVar12 >> 2;
        *(int *)(iVar8 + 0x44) = *(int *)(iVar8 + 0x44) + 1;
        if (*(int *)(iVar8 + 0x4c) * _page_size < *(uint *)(iVar8 + 0x38)) {
          iVar7 = _kmem_mb_alloc(_swapfs_bit_map,_page_size);
          if (iVar7 == 0) {
            iVar7 = *(int *)(iVar8 + 0x44);
            *(int *)(iVar8 + 0x44) = iVar7 + -1;
            *(uint *)(iVar8 + 0x38) = (iVar7 + -1) * _page_size >> 2;
            goto LAB_0013adc8;
          }
          if (iVar7 != _page_size * *(int *)(iVar8 + 0x4c) + *(int *)(iVar8 + 0x48)) {
                    /* WARNING: Subroutine does not return */
            _panic(s_swapfs_grow__bad_freelist_001dd85d);
          }
          *(int *)(iVar8 + 0x4c) = *(int *)(iVar8 + 0x4c) + 1;
        }
      }
    }
    if (param_4 < *(int *)(iVar3 + 0x38) * _page_size) goto LAB_0013ae8c;
    if (1999 < _logswapindex) {
      _logswapindex = 0;
    }
    iVar7 = _logswapindex;
    iVar8 = _logswapindex * 0xc;
    (&_logswp)[_logswapindex * 3] = param_4;
    (&DAT_001ef304)[iVar7 * 3] = param_4 >> 0xd;
    (&DAT_001ef308)[iVar8] = (&DAT_001ef308)[iVar8] & 0xf0 | 8;
    (&DAT_001ef308)[_logswapindex * 0xc] = (&DAT_001ef308)[_logswapindex * 0xc] & 0xf;
    (&DAT_001ef309)[_logswapindex * 0xc] = 1;
    _logswapindex = _logswapindex + 1;
    piVar13 = *(int **)(iVar3 + 0x3c);
    if (*(uint *)(*piVar13 + 0x14) < param_4 + param_3) {
      *(uint *)(*piVar13 + 0x14) = param_4 + param_3;
    }
    local_5c = piVar13[7];
  }
  iVar8 = (**(code **)(local_5c + 0x78))(piVar13,param_2,param_3,param_4);
LAB_0013b2b4:
  iVar3 = *(int *)(param_1 + 0x30);
  bVar2 = *(byte *)(iVar3 + 0x79);
  *(byte *)(iVar3 + 0x79) = bVar2 & 0xfe;
  if ((bVar2 & 2) != 0) {
    *(byte *)(iVar3 + 0x79) = bVar2 & 0xfc;
    _wakeup(iVar3 + 0x79);
  }
  return iVar8;
}

