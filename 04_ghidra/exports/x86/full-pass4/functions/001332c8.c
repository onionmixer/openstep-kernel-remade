/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001332c8 */

int FUN_001332c8(byte *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  size_t sVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  undefined4 *puVar10;
  int *piVar11;
  undefined4 *puVar12;
  uint local_11c;
  int local_118;
  int local_114;
  int local_110;
  int local_100;
  int local_fc;
  int local_f8;
  int local_e8;
  undefined1 local_e4 [28];
  int local_c8;
  undefined1 local_c4 [36];
  undefined4 local_a0 [8];
  int local_80;
  int local_7c;
  uint local_78;
  uint local_74;
  int local_70 [8];
  int local_50;
  int local_4c;
  int local_48;
  undefined1 local_44 [64];
  
  piVar1 = *(int **)(param_1 + 0x40);
  iVar2 = piVar1[0xc];
  local_118 = (**(code **)(piVar1[7] + 0x80))(piVar1);
  if ((*param_1 & 1) == 0) {
    sVar5 = *(short *)(iVar2 + 0x62);
    if (sVar5 == 0) {
      local_11c = *(int *)(iVar2 + 0x98) - local_118 * *(int *)(param_1 + 0x24);
      if (*(uint *)(param_1 + 0x14) < local_11c) {
        local_11c = *(uint *)(param_1 + 0x14);
      }
      if ((int)local_11c < 0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_do_bio__write_count_<_0_001dcb58);
      }
      local_114 = *(int *)(param_1 + 0x20);
      local_118 = local_118 * *(int *)(param_1 + 0x24);
      uVar3 = *(undefined4 *)(iVar2 + 0x70);
      do {
        uVar8 = *(uint *)(*(int *)(piVar1[9] + 0x128) + 0x20);
        if ((int)local_11c < (int)uVar8) {
          uVar8 = local_11c;
        }
        local_70[0] = local_114;
        puVar10 = (undefined4 *)(piVar1[0xc] + 0x40);
        puVar12 = local_a0;
        for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar12 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar12 = puVar12 + 1;
        }
        local_80 = local_118;
        local_7c = local_118;
        local_78 = uVar8;
        local_74 = uVar8;
        iVar7 = _rfscall(*(undefined4 *)(piVar1[9] + 0x128),8,_xdr_writeargs,local_a0,_xdr_attrstat,
                         &local_e8,uVar3);
        if ((iVar7 == 0) && (iVar7 = local_e8, local_e8 == 0x46)) {
          _btrash(piVar1);
          _nfs_invalidate_caches(piVar1);
        }
        local_11c = local_11c - uVar8;
        local_114 = local_114 + uVar8;
        local_118 = local_118 + uVar8;
        if (iVar7 != 0) goto LAB_001336b7;
      } while (local_11c != 0);
      _nfs_attrcache(piVar1,local_e4);
LAB_001336b7:
      if (iVar7 == 0x1c) {
        _printf(s_NFS_write_error__on_host__s_remo_001dcabc,*(int *)(piVar1[9] + 0x128) + 0x34);
      }
      else if (iVar7 < 0x1d) {
        if (iVar7 != 0) {
LAB_001336f0:
          _printf(s_NFS_write_error__d_on_host__s_fh_001dcaf1,iVar7,
                  *(int *)(piVar1[9] + 0x128) + 0x34);
          FUN_00131898(piVar1[0xc] + 0x40);
          _printf(&DAT_001dcb13);
        }
      }
      else if (iVar7 != 0x45) goto LAB_001336f0;
      sVar5 = (short)iVar7;
      *(short *)(param_1 + 0x1c) = sVar5;
      iVar7 = (int)sVar5;
      if ((param_1[1] & 1) != 0) {
        *(short *)(iVar2 + 0x62) = sVar5;
      }
    }
    else {
      *(short *)(param_1 + 0x1c) = sVar5;
      iVar7 = (int)sVar5;
    }
LAB_00133756:
    if (iVar7 == 0) goto LAB_0013377a;
  }
  else {
    local_f8 = *(int *)(param_1 + 0x20);
    local_fc = local_118 * *(int *)(param_1 + 0x24);
    local_100 = *(int *)(param_1 + 0x14);
    uVar3 = *(undefined4 *)(iVar2 + 0x70);
    while( true ) {
      local_110 = *(int *)(*(int *)(piVar1[9] + 0x128) + 0x1c);
      if (local_100 < local_110) {
        local_110 = local_100;
      }
      local_7c = local_f8;
      piVar9 = (int *)(piVar1[0xc] + 0x40);
      piVar11 = local_70;
      for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
        *piVar11 = *piVar9;
        piVar9 = piVar9 + 1;
        piVar11 = piVar11 + 1;
      }
      local_50 = local_fc;
      local_48 = local_110;
      local_4c = local_110;
      iVar6 = _rfscall(*(undefined4 *)(piVar1[9] + 0x128),6,_xdr_readargs,local_70,_xdr_rdresult,
                       &local_c8,uVar3);
      iVar7 = local_c8;
      if (iVar6 != 0) break;
      if (local_c8 == 0x46) {
        _printf(s_NFS_read_error_ESTALE_to_host__1_001dcb19,*(int *)(piVar1[9] + 0x128) + 0x34);
        _bcopy((void *)(piVar1[0xc] + 0x40),&local_e8,0x20);
        uVar8 = 0;
        do {
          _printf((char *)&PTR_DAT_001dcb15,*(undefined4 *)(local_e4 + uVar8 * 4 + -4));
          uVar8 = uVar8 + 1;
        } while (uVar8 < 8);
        _printf(&DAT_001dcb40);
        _btrash(piVar1);
        _nfs_invalidate_caches(piVar1);
      }
      iVar6 = iVar7;
      if (iVar7 != 0) break;
      local_100 = local_100 - local_80;
      local_f8 = local_f8 + local_80;
      local_fc = local_fc + local_80;
      if ((local_100 == 0) || (local_110 != local_80)) break;
    }
    *(int *)(param_1 + 0x28) = local_100;
    if (iVar6 == 0) {
      _nattr_to_vattr(piVar1,local_c4,local_44);
    }
    *(short *)(param_1 + 0x1c) = (short)iVar6;
    iVar7 = (int)(short)iVar6;
    if (iVar7 == 0) {
      sVar4 = *(size_t *)(param_1 + 0x28);
      if (sVar4 != 0) {
        _bzero((void *)((*(int *)(param_1 + 0x14) - sVar4) + *(int *)(param_1 + 0x20)),sVar4);
      }
      if ((*(int *)(param_1 + 0x28) != *(int *)(param_1 + 0x14)) ||
         ((uint)(local_118 * *(int *)(param_1 + 0x24)) < *(uint *)(iVar2 + 0x98)))
      goto LAB_00133756;
      iVar7 = -0x62;
    }
  }
  if (iVar7 != -0x62) {
    *param_1 = *param_1 | 4;
    iVar2 = *piVar1;
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x34) == 0)) {
      *(int *)(iVar2 + 0x34) = iVar7;
    }
  }
LAB_0013377a:
  _biodone(param_1);
  return iVar7;
}

