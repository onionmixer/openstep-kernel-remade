
undefined4 _fd_attach_com(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  uint **ppuVar8;
  undefined *puStack_a0;
  uint *puStack_9c;
  int iStack_98;
  uint *puStack_94;
  uint *puStack_90;
  uint *puStack_8c;
  uint auStack_68 [2];
  uint auStack_60 [23];
  
  uVar1 = param_1[5];
  puVar2 = param_1 + 0x5a;
  if ((*(byte *)((int)param_1 + 0x179) & 2) != 0) {
    return 0;
  }
  *(undefined4 *)((int)param_1 + 0x17a) = 3;
  *(uint *)((int)param_1 + 0x176U) = *(uint *)((int)param_1 + 0x176U) & 0xfffffffe;
  iVar6 = 2;
  do {
    puStack_8c = param_1;
    puStack_90 = (uint *)0x406b814;
    iVar3 = _fd_recal();
    if (iVar3 == 0) break;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  if (iVar6 == 0) {
    *(undefined4 *)((int)param_1 + 0x17a) = 0;
    puStack_8c = (uint *)aFdRecalibrateF;
loc_406B9D6:
    puStack_90 = (uint *)0x406b9dc;
    _printf();
    return 5;
  }
  *puVar2 = 0;
  puStack_8c = auStack_60;
  puStack_90 = param_1;
  puStack_94 = (uint *)0x406b83e;
  iVar6 = _fd_get_status();
  if (iVar6 != 0) {
    puStack_8c = (uint *)aFdControllerIO;
    goto loc_406B9D6;
  }
  if ((auStack_60[0] & 0x8000000) == 0) {
    puStack_8c = (uint *)aFdNoDriveDetec;
    goto loc_406B9D6;
  }
  if ((auStack_60[0] & 0xc0000000) == 0) {
    puStack_8c = (uint *)aFdNoMediaDetec;
    goto loc_406B9D6;
  }
  if ((auStack_60[0] & 0x10000000) == 0) {
    *(uint *)((int)param_1 + 0x176U) = *(uint *)((int)param_1 + 0x176U) & 0xfffffffb;
  }
  else {
    *(uint *)((int)param_1 + 0x176U) = *(uint *)((int)param_1 + 0x176U) | 4;
  }
  *puVar2 = auStack_60[0] >> 0x1e;
  puVar7 = _fd_disk_info;
  if (_fd_disk_info._0_4_ != 0) {
    do {
      if (auStack_60[0] >> 0x1e == *(uint *)puVar7) break;
      puVar7 = (undefined *)((int)puVar7 + 0xe);
    } while (*(uint *)puVar7 != 0);
  }
  *puVar2 = *(uint *)puVar7;
  param_1[0x5b] = *(uint *)((int)puVar7 + 4);
  param_1[0x5c] = *(uint *)((int)puVar7 + 8);
  *(undefined2 *)(param_1 + 0x5d) = *(undefined2 *)((int)puVar7 + 0xc);
  *(undefined4 *)((int)param_1 + 0x182) = 1;
  *(int *)((int)param_1 + 0x17a) = *(int *)((int)param_1 + 0x172);
  if (*(int *)((int)param_1 + 0x172) != 0) {
    do {
      iVar6 = 2;
      do {
        puStack_8c = (uint *)0x0;
        puStack_90 = (uint *)0x1;
        puStack_94 = param_1;
        iStack_98 = 0x406b8d2;
        iVar3 = _fd_seek();
        if (iVar3 != 0) {
          puStack_8c = (uint *)aFdSeekFailed;
          goto loc_406B9D6;
        }
        puStack_8c = auStack_68;
        puStack_90 = (uint *)0x0;
        puStack_94 = param_1;
        iStack_98 = 0x406b8ea;
        iVar3 = _fd_readid();
        if (iVar3 == 0) goto loc_406B908;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      iVar3 = *(int *)((int)param_1 + 0x17a);
      *(int *)((int)param_1 + 0x17a) = iVar3 + -1;
    } while (iVar3 != 1);
loc_406B908:
    puStack_8c = *(uint **)((int)param_1 + 0x17a);
    if (puStack_8c != (uint *)0x0) {
      puStack_90 = param_1;
      puStack_94 = (uint *)0x406b94c;
      _fd_set_density_info();
      *(uint *)((int)param_1 + 0x176U) = *(uint *)((int)param_1 + 0x176U) | 1;
      puStack_94 = *(uint **)((int)param_1 + 0x17a);
      iStack_98 = 0x406b95c;
      piVar4 = (int *)_fd_get_sectsize_info();
      iVar3 = *piVar4;
      while (iVar3 != 0) {
        puStack_8c = (uint *)*piVar4;
        puStack_90 = param_1;
        puStack_94 = (uint *)0x406b974;
        _fd_set_sector_size();
        iVar6 = 0;
        iVar3 = 2;
        do {
          puStack_8c = (uint *)0x1;
          puStack_90 = (uint *)param_1[5];
          puStack_94 = (uint *)0x1;
          puStack_9c = param_1;
          puStack_a0 = (undefined *)0x406b998;
          iStack_98 = iVar6;
          iVar5 = _fd_raw_rw();
          if (iVar5 == 0) goto loc_406B9E0;
          iVar6 = param_1[99] + 1 + iVar6;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
        piVar4 = piVar4 + 3;
        iVar6 = 0;
        iVar3 = *piVar4;
      }
      if (iVar6 == 0) {
        puStack_8c = (uint *)aFdDiskUnreadab;
        puStack_90 = (uint *)0x406b9c8;
        _printf();
        *(uint *)((int)param_1 + 0x176U) = *(uint *)((int)param_1 + 0x176U) & 0xfffffffe;
        return 0;
      }
loc_406B9E0:
      puStack_8c = param_1;
      puStack_90 = (uint *)0x406b9e8;
      iVar6 = _fd_get_label();
      if (iVar6 == 0) {
        puStack_8c = param_1;
        puStack_90 = (uint *)0x406b9f6;
        _fd_setbratio();
        puStack_90 = (uint *)(uVar1 + 0xc);
        puStack_94 = (uint *)aDiskLabelS;
        iStack_98 = 0x406ba0a;
        _printf();
        iStack_98 = *(int *)((int)param_1 + 0x186);
        puStack_9c = (uint *)(*(int *)((int)param_1 + 0x16e) *
                              (uint)*(byte *)(param_1 + 0x5b) *
                              param_1[99] * *(int *)((int)param_1 + 0x186) >> 10);
        puStack_a0 = aDiskCapacityDK;
        _printf();
      }
      if ((*(byte *)((int)param_1 + 0x179) & 4) == 0) {
        return 0;
      }
      ppuVar8 = &puStack_8c;
      puStack_8c = (uint *)aDiskIsWritePro;
      goto loc_406BA48;
    }
  }
  puVar2 = *(uint **)((int)param_1 + 0x172);
  puStack_90 = (uint *)0x406b91a;
  puStack_8c = puVar2;
  piVar4 = (int *)_fd_get_sectsize_info();
  iVar6 = *piVar4;
  puStack_94 = param_1;
  iStack_98 = 0x406b928;
  puStack_90 = puVar2;
  _fd_set_density_info();
  puStack_9c = param_1;
  puStack_a0 = (undefined *)0x406b932;
  iStack_98 = iVar6;
  _fd_set_sector_size();
  *(uint *)((int)param_1 + 0x176U) = *(uint *)((int)param_1 + 0x176U) & 0xfffffffe;
  ppuVar8 = (uint **)&puStack_a0;
  puStack_a0 = aFdDiskUnformat;
loc_406BA48:
  *(undefined4 *)((int)ppuVar8 + -4) = 0x406ba4e;
  _printf();
  return 0;
}
