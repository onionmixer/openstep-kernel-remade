/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013acea */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_0013acea(void)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int unaff_EBP;
  uint uVar7;
  uint *unaff_EDI;
  int *piVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  if (*(uint *)(unaff_EBP + 0x14) < unaff_EDI[1] * _page_size) {
LAB_0013ae8c:
    uVar7 = _compress_data_from_phys(*(undefined4 *)(unaff_EBP + 0xc),_page_size);
    if (_compress_window_size <= _compress_backoff_window) {
      bVar2 = _compress_backoff_cnt < _compress_threashold;
      if (bVar2) {
        __compress_backoff_off = __compress_backoff_off + 1;
        _compress_backoff_cnt = _compress_threashold;
      }
      else {
        __compress_backoff_on = __compress_backoff_on + 1;
        _compress_backoff_cnt = 0;
      }
      _compress_enable = (uint)!bVar2;
      _compress_backoff_window = 0;
    }
    if (_compress_enable == 0) {
      uVar7 = _page_size;
    }
    _compress_backoff_window = _compress_backoff_window + 1;
    *(uint *)(unaff_EBP + -0x58) = _page_size >> 3;
    *(int *)(&DAT_001e5a74 + (uVar7 / *(uint *)(unaff_EBP + -0x58)) * 4) =
         *(int *)(&DAT_001e5a74 + (uVar7 / *(uint *)(unaff_EBP + -0x58)) * 4) + 1;
    uVar7 = *unaff_EDI * (((*unaff_EDI - 1) + uVar7) / *unaff_EDI);
    iVar4 = FUN_0013a61c();
    if (iVar4 == 0) {
      _printf(s_couldn_t_allocate_an_offset__001dd89d);
      iVar4 = *(int *)(*(int *)(unaff_EBP + 8) + 0x30);
      bVar1 = *(byte *)(iVar4 + 0x79);
      *(byte *)(iVar4 + 0x79) = bVar1 & 0xfe;
      if ((bVar1 & 2) != 0) {
        *(byte *)(iVar4 + 0x79) = bVar1 & 0xfc;
        _wakeup();
      }
      return 2;
    }
    if (uVar7 < _page_size) {
      iVar4 = *(int *)(unaff_EBP + -4);
      if (iVar4 < 0) {
        iVar4 = iVar4 + 0x1fff;
      }
      *(int *)(unaff_EBP + -0x40) = iVar4 >> 0xd;
      uVar5 = uVar7;
      if ((int)uVar7 < 0) {
        uVar5 = uVar7 + 0x3ff;
      }
      uVar6 = *(uint *)(unaff_EBP + -8);
      if ((int)uVar6 < 0) {
        uVar6 = uVar6 + 0x3ff;
      }
      if (1999 < _logswapindex) {
        _logswapindex = 0;
      }
      iVar3 = _logswapindex;
      iVar4 = _logswapindex * 0xc;
      *(int *)(unaff_EBP + -0x5c) = iVar4;
      (&_logswp)[iVar3 * 3] = *(undefined4 *)(unaff_EBP + 0x14);
      (&DAT_001ef304)[iVar3 * 3] = *(undefined4 *)(unaff_EBP + -0x40);
      (&DAT_001ef308)[*(int *)(unaff_EBP + -0x5c)] =
           (byte)(uVar5 >> 10) & 0xf | (&DAT_001ef308)[iVar4] & 0xf0;
      (&DAT_001ef308)[_logswapindex * 0xc] =
           (char)(uVar6 >> 10) << 4 | (&DAT_001ef308)[_logswapindex * 0xc] & 0xf;
      (&DAT_001ef309)[_logswapindex * 0xc] = 3;
      _logswapindex = _logswapindex + 1;
      *(uint *)(unaff_EBP + -0x44) = unaff_EDI[0xf];
      *(uint *)(unaff_EBP + -0x48) = *(uint *)(unaff_EBP + -4);
      *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(unaff_EBP + -8);
      _DAT_001e5a44 = _DAT_001e5a44 + 1;
      *(uint *)(unaff_EBP + -0x58) = *(uint *)(unaff_EBP + -4) >> 0xd;
      **(undefined2 **)(unaff_EBP + -0x44) = *(undefined2 *)(unaff_EBP + -0x58);
      if (*(uint *)(unaff_EBP + -0x48) == unaff_EDI[0x10]) {
        _DAT_001e5a48 = _DAT_001e5a48 + 1;
        _compress_backoff_cnt = _compress_backoff_cnt + 1;
        _bcopy(*(void **)(unaff_EBP + -0x44),(void *)(*(int *)(unaff_EBP + -0x4c) + unaff_EDI[0xd]),
               uVar7);
        if (unaff_EDI[0xb] == *(uint *)(unaff_EBP + -0x48)) {
          __swpgotcha = __swpgotcha + 1;
          unaff_EDI[0xb] = 0xffffffff;
          *(undefined1 *)(unaff_EDI + 0xc) = 0;
        }
        iVar4 = 0;
      }
      else {
        if (unaff_EDI[0xb] == *(uint *)(unaff_EBP + -0x48)) {
          _DAT_001e5a4c = _DAT_001e5a4c + 1;
          _compress_backoff_cnt = _compress_backoff_cnt + 1;
          _bcopy(*(void **)(unaff_EBP + -0x44),(void *)(*(int *)(unaff_EBP + -0x4c) + unaff_EDI[9]),
                 uVar7);
          *(undefined1 *)(unaff_EDI + 0xc) = 1;
        }
        else {
          if (unaff_EDI[0x10] != 0xffffffff) {
            _DAT_001e5a50 = _DAT_001e5a50 + 1;
            *(uint *)(unaff_EBP + -0x5c) = unaff_EDI[2];
            *(uint *)(unaff_EBP + -0x50) = unaff_EDI[0xe];
            uVar6 = _page_size;
            *(uint *)(unaff_EBP + -0x54) = _page_size;
            uVar5 = unaff_EDI[0x10];
            iVar4 = **(int **)(unaff_EBP + -0x5c);
            *(int *)(unaff_EBP + -0x58) = iVar4;
            if (*(uint *)(iVar4 + 0x14) < uVar6 + uVar5) {
              *(uint *)(iVar4 + 0x14) = uVar6 + uVar5;
            }
            *(undefined4 *)(unaff_EBP + -0x58) = *(undefined4 *)(*(int *)(unaff_EBP + -0x5c) + 0x1c)
            ;
            iVar4 = (**(code **)(*(int *)(unaff_EBP + -0x58) + 0x78))
                              (*(undefined4 *)(unaff_EBP + -0x5c),*(undefined4 *)(unaff_EBP + -0x50)
                               ,*(undefined4 *)(unaff_EBP + -0x54));
            if (iVar4 != 0) {
              _printf(s_cannot_flush_output_cache__001dd82c);
              goto LAB_0013b2b4;
            }
          }
          unaff_EDI[0x10] = *(uint *)(unaff_EBP + -0x48);
          _bcopy(*(void **)(unaff_EBP + -0x44),
                 (void *)(*(int *)(unaff_EBP + -0x4c) + unaff_EDI[0xd]),uVar7);
        }
        iVar4 = 0;
      }
      goto LAB_0013b2b4;
    }
    uVar5 = *(uint *)(unaff_EBP + -4);
    if (unaff_EDI[0x10] == uVar5) {
      _DAT_001e5a54 = _DAT_001e5a54 + 1;
      unaff_EDI[0x10] = 0xffffffff;
    }
    if (unaff_EDI[0xb] == uVar5) {
      _DAT_001e5a58 = _DAT_001e5a58 + 1;
      unaff_EDI[0xb] = 0xffffffff;
      *(undefined1 *)(unaff_EDI + 0xc) = 0;
    }
    _DAT_001e5a5c = _DAT_001e5a5c + 1;
    iVar4 = *(int *)(unaff_EBP + -4);
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0x1fff;
    }
    *(int *)(unaff_EBP + -0x3c) = iVar4 >> 0xd;
    if ((int)uVar7 < 0) {
      uVar7 = uVar7 + 0x3ff;
    }
    uVar5 = *(uint *)(unaff_EBP + -8);
    if ((int)uVar5 < 0) {
      uVar5 = uVar5 + 0x3ff;
    }
    if (1999 < _logswapindex) {
      _logswapindex = 0;
    }
    iVar3 = _logswapindex;
    iVar4 = _logswapindex * 0xc;
    *(int *)(unaff_EBP + -0x5c) = iVar4;
    (&_logswp)[iVar3 * 3] = *(undefined4 *)(unaff_EBP + 0x14);
    (&DAT_001ef304)[iVar3 * 3] = *(undefined4 *)(unaff_EBP + -0x3c);
    (&DAT_001ef308)[*(int *)(unaff_EBP + -0x5c)] =
         (byte)(uVar7 >> 10) & 0xf | (&DAT_001ef308)[iVar4] & 0xf0;
    (&DAT_001ef308)[_logswapindex * 0xc] =
         (char)(uVar5 >> 10) << 4 | (&DAT_001ef308)[_logswapindex * 0xc] & 0xf;
    (&DAT_001ef309)[_logswapindex * 0xc] = 2;
    _logswapindex = _logswapindex + 1;
    piVar8 = (int *)unaff_EDI[2];
    uVar7 = *(int *)(unaff_EBP + 0x10) + *(int *)(unaff_EBP + -4);
    if (*(uint *)(*piVar8 + 0x14) < uVar7) {
      *(uint *)(*piVar8 + 0x14) = uVar7;
    }
    *(int *)(unaff_EBP + -0x58) = piVar8[7];
    uVar10 = *(undefined4 *)(unaff_EBP + 0x10);
    uVar9 = *(undefined4 *)(unaff_EBP + 0xc);
  }
  else {
    if (_swapfs_cangrow == 1) {
      iVar4 = *(int *)(*(int *)(unaff_EBP + 8) + 0x30);
      uVar7 = (*(int *)(iVar4 + 0x44) + 1) * _page_size;
      iVar3 = _kmem_mb_alloc(_swapfs_rem_map);
      if (iVar3 == 0) {
LAB_0013adc8:
        _swapfs_cangrow = 0;
      }
      else {
        if (iVar3 != *(int *)(iVar4 + 0x44) * _page_size + *(int *)(iVar4 + 0x40)) {
                    /* WARNING: Subroutine does not return */
          _panic(s_swapfs_grow__bad_rem_001dd848);
        }
        *(uint *)(iVar4 + 0x38) = uVar7 >> 2;
        *(int *)(iVar4 + 0x44) = *(int *)(iVar4 + 0x44) + 1;
        if (*(int *)(iVar4 + 0x4c) * _page_size < *(uint *)(iVar4 + 0x38)) {
          iVar3 = _kmem_mb_alloc(_swapfs_bit_map);
          if (iVar3 == 0) {
            iVar3 = *(int *)(iVar4 + 0x44);
            *(int *)(unaff_EBP + -0x58) = iVar3;
            *(int *)(iVar4 + 0x44) = iVar3 + -1;
            *(uint *)(iVar4 + 0x38) = (*(int *)(unaff_EBP + -0x58) + -1) * _page_size >> 2;
            goto LAB_0013adc8;
          }
          if (iVar3 != _page_size * *(int *)(iVar4 + 0x4c) + *(int *)(iVar4 + 0x48)) {
                    /* WARNING: Subroutine does not return */
            _panic(s_swapfs_grow__bad_freelist_001dd85d);
          }
          *(int *)(iVar4 + 0x4c) = *(int *)(iVar4 + 0x4c) + 1;
        }
      }
    }
    if (*(uint *)(unaff_EBP + 0x14) < unaff_EDI[1] * _page_size) goto LAB_0013ae8c;
    uVar7 = *(uint *)(unaff_EBP + 0x14);
    if (1999 < _logswapindex) {
      _logswapindex = 0;
    }
    iVar3 = _logswapindex;
    iVar4 = _logswapindex * 0xc;
    *(int *)(unaff_EBP + -0x5c) = iVar4;
    (&_logswp)[iVar3 * 3] = *(undefined4 *)(unaff_EBP + 0x14);
    (&DAT_001ef304)[iVar3 * 3] = uVar7 >> 0xd;
    (&DAT_001ef308)[*(int *)(unaff_EBP + -0x5c)] = (&DAT_001ef308)[iVar4] & 0xf0 | 8;
    iVar4 = _logswapindex;
    *(int *)(unaff_EBP + -0x58) = _logswapindex * 3;
    (&DAT_001ef308)[iVar4 * 0xc] = (&DAT_001ef308)[iVar4 * 0xc] & 0xf;
    (&DAT_001ef309)[_logswapindex * 0xc] = 1;
    _logswapindex = _logswapindex + 1;
    piVar8 = (int *)unaff_EDI[2];
    uVar7 = *(int *)(unaff_EBP + 0x14) + *(int *)(unaff_EBP + 0x10);
    if (*(uint *)(*piVar8 + 0x14) < uVar7) {
      *(uint *)(*piVar8 + 0x14) = uVar7;
    }
    *(int *)(unaff_EBP + -0x58) = piVar8[7];
    uVar10 = *(undefined4 *)(unaff_EBP + 0x10);
    uVar9 = *(undefined4 *)(unaff_EBP + 0xc);
  }
  iVar4 = (**(code **)(*(int *)(unaff_EBP + -0x58) + 0x78))(piVar8,uVar9,uVar10);
LAB_0013b2b4:
  iVar3 = *(int *)(*(int *)(unaff_EBP + 8) + 0x30);
  bVar1 = *(byte *)(iVar3 + 0x79);
  *(byte *)(unaff_EBP + -0x5c) = bVar1;
  *(byte *)(iVar3 + 0x79) = bVar1 & 0xfe;
  if ((*(byte *)(unaff_EBP + -0x5c) & 2) != 0) {
    *(byte *)(iVar3 + 0x79) = *(byte *)(unaff_EBP + -0x5c) & 0xfc;
    *(int *)(unaff_EBP + -0x58) = iVar3 + 0x79;
    _wakeup();
  }
  return iVar4;
}

