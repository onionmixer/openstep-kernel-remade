/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017db54 */

void _vnode_pager_truncate(uint param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined1 local_44 [24];
  int local_2c;
  
  iVar1 = *(int *)(&DAT_001e7294 + (param_1 & 0xff) * 4);
  piVar2 = *(int **)(iVar1 + 8);
  if ((*(int *)(iVar1 + 0x20) <= (int)(param_1 >> 8)) && (_swapfs_enabled == 0)) {
    _lock_write(iVar1 + 0x34);
    uVar5 = param_1 >> 8;
    do {
      uVar4 = uVar5 - 1;
      if ((int)uVar4 < 0) goto LAB_0017dbc0;
      uVar6 = uVar4;
      if ((int)uVar4 < 0) {
        uVar6 = uVar5 + 6;
      }
      uVar5 = uVar4;
    } while (((uint)(int)*(char *)(((int)uVar6 >> 3) + *(int *)(iVar1 + 0x10)) >>
              (uVar4 + ((int)uVar6 >> 3) * -8 & 0x1f) & 1) == 0);
    *(uint *)(iVar1 + 0x20) = uVar4;
LAB_0017dbc0:
    iVar7 = *(int *)(iVar1 + 0x20) + 1;
    if (((*(int *)(iVar1 + 0x1c) != 0) && (*(int *)(iVar1 + 0x1c) < iVar7)) &&
       ((uint)(iVar7 << ((byte)_page_shift & 0x1f)) <= *(uint *)(*piVar2 + 0x14))) {
      _vattr_null(local_44);
      local_2c = iVar7 << ((byte)_page_shift & 0x1f);
      uVar3 = *(undefined4 *)(_active_u + 0x1c);
      *(undefined4 *)(_active_u + 0x1c) = *(undefined4 *)(*piVar2 + 0x30);
      iVar7 = (**(code **)(piVar2[7] + 0x18))(piVar2,local_44,*(undefined4 *)(*piVar2 + 0x30));
      if (iVar7 != 0) {
        _printf(s_vnode_deallocpage__error_truncat_001e0eeb,*(undefined4 *)(iVar1 + 0x28),iVar7);
      }
      *(undefined4 *)(_active_u + 0x1c) = uVar3;
    }
    _lock_done(iVar1 + 0x34);
  }
  return;
}

