/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017dea5 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0017dea5(void)

{
  int *piVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  byte bVar6;
  int iVar7;
  uint uVar8;
  uint unaff_EBX;
  uint uVar9;
  int unaff_EBP;
  int unaff_ESI;
  
  do {
    if ((int)unaff_EBX < *(int *)(unaff_ESI + 0x24)) {
      *(uint *)(unaff_ESI + 0x24) = unaff_EBX;
    }
    uVar9 = unaff_EBX;
    if ((int)unaff_EBX < 0) {
      uVar9 = unaff_EBX + 7;
    }
    bVar6 = (char)unaff_EBX + (char)((int)uVar9 >> 3) * -8 & 0x1f;
    pbVar2 = (byte *)(((int)uVar9 >> 3) + *(int *)(unaff_ESI + 0x10));
    *pbVar2 = *pbVar2 & ((byte)(-2 << bVar6) | (byte)(0xfffffffe >> 0x20 - bVar6));
    *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0x18) + 1;
    _lock_done();
    do {
      iVar4 = DAT_001e0e58;
      uVar9 = *(uint *)(*(int *)(*(int *)(unaff_EBP + -0x44) + 8) + *(int *)(unaff_EBP + -0x50) * 4)
      ;
      if ((char)uVar9 != '\0') {
        iVar7 = 0;
        if (0 < DAT_001e0e58) {
          *(undefined4 **)(unaff_EBP + -0x60) = &DAT_001e72d4;
          do {
            if ((char)**(uint **)(unaff_EBP + -0x60) == (char)uVar9) {
              uVar3 = **(uint **)(unaff_EBP + -0x60);
              uVar8 = uVar3 >> 8;
              if (uVar8 < uVar9 >> 8) {
                uVar8 = uVar9 >> 8;
              }
              **(uint **)(unaff_EBP + -0x60) = uVar3 & 0xff | uVar8 << 8;
              goto LAB_0017df57;
            }
            *(int *)(unaff_EBP + -0x60) = *(int *)(unaff_EBP + -0x60) + 4;
            iVar7 = iVar7 + 1;
          } while (iVar7 < iVar4);
        }
        (&DAT_001e72d4)[DAT_001e0e58] = uVar9;
        DAT_001e0e58 = DAT_001e0e58 + 1;
      }
LAB_0017df57:
      *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + -0x50) + 1;
      if (*(int *)(*(int *)(unaff_EBP + -0x44) + 0x10) <= *(int *)(unaff_EBP + -0x50)) {
        if (0 < *(int *)(*(int *)(unaff_EBP + -0x44) + 0x10)) {
          _kfree(*(undefined4 *)(*(int *)(unaff_EBP + -0x44) + 8));
        }
        piVar1 = (int *)(*(int *)(unaff_EBP + -0x4c) + 0xc);
        *piVar1 = *piVar1 + -1;
        *(undefined4 *)(unaff_EBP + -0x48) = 0;
        if (DAT_001e0e58 <= *(int *)(unaff_EBP + -0x48)) goto LAB_0017e0e7;
        *(int *)(unaff_EBP + -0x5c) = unaff_EBP + -0x40;
        goto LAB_0017dfc0;
      }
      uVar9 = *(uint *)(*(int *)(*(int *)(unaff_EBP + -0x44) + 8) + *(int *)(unaff_EBP + -0x50) * 4)
      ;
    } while ((char)uVar9 == '\0');
    unaff_ESI = *(int *)(&DAT_001e7294 + (uVar9 & 0xff) * 4);
    unaff_EBX = uVar9 >> 8;
    *(int *)(unaff_EBP + -0x60) = unaff_ESI + 0x34;
    _lock_write();
    if (*(int *)(unaff_ESI + 0x14) <= (int)unaff_EBX) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vnode_pager_deallocpage_001e0e72);
    }
  } while( true );
LAB_0017dfc0:
  uVar9 = (&DAT_001e72d4)[*(int *)(unaff_EBP + -0x48)];
  iVar4 = *(int *)(&DAT_001e7294 + (uVar9 & 0xff) * 4);
  *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(iVar4 + 8);
  uVar9 = uVar9 >> 8;
  if ((*(int *)(iVar4 + 0x20) <= (int)uVar9) && (_swapfs_enabled == 0)) {
    _lock_write();
    do {
      uVar3 = uVar9 - 1;
      if ((int)uVar3 < 0) goto LAB_0017e032;
      uVar8 = uVar3;
      if ((int)uVar3 < 0) {
        uVar8 = uVar9 + 6;
      }
      *(int *)(unaff_EBP + -0x58) = (int)*(char *)(((int)uVar8 >> 3) + *(int *)(iVar4 + 0x10));
      uVar9 = uVar3;
    } while ((*(uint *)(unaff_EBP + -0x58) >> (uVar3 + ((int)uVar8 >> 3) * -8 & 0x1f) & 1) == 0);
    *(uint *)(iVar4 + 0x20) = uVar3;
LAB_0017e032:
    iVar7 = *(int *)(iVar4 + 0x20) + 1;
    if (((*(int *)(iVar4 + 0x1c) != 0) && (*(int *)(iVar4 + 0x1c) < iVar7)) &&
       ((uint)(iVar7 << ((byte)_page_shift & 0x1f)) <=
        *(uint *)(**(int **)(unaff_EBP + -0x60) + 0x14))) {
      _vattr_null();
      *(int *)(unaff_EBP + -0x28) = iVar7 << ((byte)_page_shift & 0x1f);
      uVar5 = *(undefined4 *)(_active_u + 0x1c);
      piVar1 = *(int **)(unaff_EBP + -0x60);
      *(undefined4 *)(_active_u + 0x1c) = *(undefined4 *)(*piVar1 + 0x30);
      iVar7 = (**(code **)(piVar1[7] + 0x18))
                        (piVar1,*(undefined4 *)(unaff_EBP + -0x5c),*(undefined4 *)(*piVar1 + 0x30));
      if (iVar7 != 0) {
        _printf(s_vnode_deallocpage__error_truncat_001e0eeb,*(undefined4 *)(iVar4 + 0x28));
      }
      *(undefined4 *)(_active_u + 0x1c) = uVar5;
    }
    _lock_done();
  }
  *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + 1;
  if (DAT_001e0e58 <= *(int *)(unaff_EBP + -0x48)) {
LAB_0017e0e7:
    _zfree(_vstruct_zone);
    return;
  }
  goto LAB_0017dfc0;
}

