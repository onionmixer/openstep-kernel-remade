/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017dc74 */

/* WARNING: Removing unreachable block (ram,0x0017dd64) */
/* WARNING: Removing unreachable block (ram,0x0017deb6) */

void _vnode_dealloc(int param_1)

{
  int *piVar1;
  byte *pbVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint *local_64;
  uint local_58;
  uint local_54;
  int local_4c;
  undefined1 local_44 [24];
  int local_2c;
  
  do {
  } while (_vstruct_lock != 0);
  LOCK();
  UNLOCK();
  *(short *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + 1;
  LOCK();
  _vstruct_lock = 0;
  UNLOCK();
  puVar3 = *(undefined4 **)(param_1 + 0x14);
  DAT_001e0e58 = 0;
  if ((*(byte *)(param_1 + 0xc) & 1) == 0) {
    *(byte *)(puVar3 + 1) = *(byte *)(puVar3 + 1) & 0xfd;
    *(undefined4 *)*puVar3 = 0;
    _vn_rele(puVar3);
    goto LAB_0017dfa1;
  }
  iVar4 = *(int *)(param_1 + 4);
  iVar8 = *(int *)(param_1 + 0x10);
  if ((uint)(iVar8 * 4) < 0x41) {
    local_54 = 0;
    if (0 < iVar8) {
      do {
        uVar10 = *(uint *)(*(int *)(param_1 + 8) + local_54 * 4);
        if ((char)uVar10 != '\0') {
          iVar8 = *(int *)(&DAT_001e7294 + (uVar10 & 0xff) * 4);
          uVar9 = uVar10 >> 8;
          _lock_write(iVar8 + 0x34);
          if (*(int *)(iVar8 + 0x14) <= (int)uVar9) {
                    /* WARNING: Subroutine does not return */
            _panic(s_vnode_pager_deallocpage_001e0e72);
          }
          if ((int)uVar9 < *(int *)(iVar8 + 0x24)) {
            *(uint *)(iVar8 + 0x24) = uVar9;
          }
          bVar6 = (char)(uVar10 >> 8) + (char)((int)uVar9 >> 3) * -8 & 0x1f;
          pbVar2 = (byte *)(((int)uVar9 >> 3) + *(int *)(iVar8 + 0x10));
          *pbVar2 = *pbVar2 & ((byte)(-2 << bVar6) | (byte)(0xfffffffe >> 0x20 - bVar6));
          *(int *)(iVar8 + 0x18) = *(int *)(iVar8 + 0x18) + 1;
          _lock_done(iVar8 + 0x34);
        }
        uVar10 = *(uint *)(*(int *)(param_1 + 8) + local_54 * 4);
        if ((char)uVar10 != '\0') {
          iVar8 = 0;
          if (0 < DAT_001e0e58) {
            local_64 = &DAT_001e72d4;
            do {
              if ((char)*local_64 == (char)uVar10) {
                uVar9 = *local_64 >> 8;
                if (uVar9 < uVar10 >> 8) {
                  uVar9 = uVar10 >> 8;
                }
                *local_64 = *local_64 & 0xff | uVar9 << 8;
                goto LAB_0017df57;
              }
              local_64 = local_64 + 1;
              iVar8 = iVar8 + 1;
            } while (iVar8 < DAT_001e0e58);
          }
          (&DAT_001e72d4)[DAT_001e0e58] = uVar10;
          DAT_001e0e58 = DAT_001e0e58 + 1;
        }
LAB_0017df57:
        local_54 = local_54 + 1;
      } while ((int)local_54 < *(int *)(param_1 + 0x10));
    }
    if (0 < *(int *)(param_1 + 0x10)) {
      iVar8 = *(int *)(param_1 + 0x10) << 2;
      goto LAB_0017df76;
    }
  }
  else {
    local_54 = 0;
    if (iVar8 - 1U >> 4 != 0xffffffff) {
      do {
        if (*(int *)(*(int *)(param_1 + 8) + local_54 * 4) != 0) {
          local_58 = 0;
          do {
            uVar10 = *(uint *)(*(int *)(*(int *)(param_1 + 8) + local_54 * 4) + local_58 * 4);
            if ((char)uVar10 != '\0') {
              iVar8 = *(int *)(&DAT_001e7294 + (uVar10 & 0xff) * 4);
              uVar9 = uVar10 >> 8;
              _lock_write(iVar8 + 0x34);
              if (*(int *)(iVar8 + 0x14) <= (int)uVar9) {
                    /* WARNING: Subroutine does not return */
                _panic(s_vnode_pager_deallocpage_001e0e72);
              }
              if ((int)uVar9 < *(int *)(iVar8 + 0x24)) {
                *(uint *)(iVar8 + 0x24) = uVar9;
              }
              bVar6 = (char)(uVar10 >> 8) + (char)((int)uVar9 >> 3) * -8 & 0x1f;
              pbVar2 = (byte *)(((int)uVar9 >> 3) + *(int *)(iVar8 + 0x10));
              *pbVar2 = *pbVar2 & ((byte)(-2 << bVar6) | (byte)(0xfffffffe >> 0x20 - bVar6));
              *(int *)(iVar8 + 0x18) = *(int *)(iVar8 + 0x18) + 1;
              _lock_done(iVar8 + 0x34);
            }
            uVar10 = *(uint *)(*(int *)(*(int *)(param_1 + 8) + local_54 * 4) + local_58 * 4);
            if ((char)uVar10 != '\0') {
              iVar8 = 0;
              if (0 < DAT_001e0e58) {
                local_64 = &DAT_001e72d4;
                do {
                  if ((char)*local_64 == (char)uVar10) {
                    uVar9 = *local_64 >> 8;
                    if (uVar9 < uVar10 >> 8) {
                      uVar9 = uVar10 >> 8;
                    }
                    *local_64 = *local_64 & 0xff | uVar9 << 8;
                    goto LAB_0017de07;
                  }
                  local_64 = local_64 + 1;
                  iVar8 = iVar8 + 1;
                } while (iVar8 < DAT_001e0e58);
              }
              (&DAT_001e72d4)[DAT_001e0e58] = uVar10;
              DAT_001e0e58 = DAT_001e0e58 + 1;
            }
LAB_0017de07:
            local_58 = local_58 + 1;
          } while (local_58 < 0x10);
          _kfree(*(undefined4 *)(*(int *)(param_1 + 8) + local_54 * 4),0x40);
        }
        local_54 = local_54 + 1;
      } while (local_54 < (*(int *)(param_1 + 0x10) - 1U >> 4) + 1);
    }
    iVar8 = (*(int *)(param_1 + 0x10) - 1U >> 4) * 4 + 4;
LAB_0017df76:
    _kfree(*(undefined4 *)(param_1 + 8),iVar8);
  }
  piVar1 = (int *)(iVar4 + 0xc);
  *piVar1 = *piVar1 + -1;
LAB_0017dfa1:
  local_4c = 0;
  if (0 < DAT_001e0e58) {
    do {
      iVar4 = *(int *)(&DAT_001e7294 + ((&DAT_001e72d4)[local_4c] & 0xff) * 4);
      piVar1 = *(int **)(iVar4 + 8);
      uVar10 = (uint)(&DAT_001e72d4)[local_4c] >> 8;
      if ((*(int *)(iVar4 + 0x20) <= (int)uVar10) && (_swapfs_enabled == 0)) {
        _lock_write(iVar4 + 0x34);
        do {
          uVar9 = uVar10 - 1;
          if ((int)uVar9 < 0) goto LAB_0017e032;
          uVar7 = uVar9;
          if ((int)uVar9 < 0) {
            uVar7 = uVar10 + 6;
          }
          uVar10 = uVar9;
        } while (((uint)(int)*(char *)(((int)uVar7 >> 3) + *(int *)(iVar4 + 0x10)) >>
                  (uVar9 + ((int)uVar7 >> 3) * -8 & 0x1f) & 1) == 0);
        *(uint *)(iVar4 + 0x20) = uVar9;
LAB_0017e032:
        iVar8 = *(int *)(iVar4 + 0x20) + 1;
        if (((*(int *)(iVar4 + 0x1c) != 0) && (*(int *)(iVar4 + 0x1c) < iVar8)) &&
           ((uint)(iVar8 << ((byte)_page_shift & 0x1f)) <= *(uint *)(*piVar1 + 0x14))) {
          _vattr_null(local_44);
          local_2c = iVar8 << ((byte)_page_shift & 0x1f);
          uVar5 = *(undefined4 *)(_active_u + 0x1c);
          *(undefined4 *)(_active_u + 0x1c) = *(undefined4 *)(*piVar1 + 0x30);
          iVar8 = (**(code **)(piVar1[7] + 0x18))(piVar1,local_44,*(undefined4 *)(*piVar1 + 0x30));
          if (iVar8 != 0) {
            _printf(s_vnode_deallocpage__error_truncat_001e0eeb,*(undefined4 *)(iVar4 + 0x28),iVar8)
            ;
          }
          *(undefined4 *)(_active_u + 0x1c) = uVar5;
        }
        _lock_done(iVar4 + 0x34);
      }
      local_4c = local_4c + 1;
    } while (local_4c < DAT_001e0e58);
  }
  _zfree(_vstruct_zone,param_1);
  return;
}

