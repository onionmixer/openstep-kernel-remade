
/* WARNING: Removing unreachable block (ram,0xf00b8374) */
/* WARNING: Removing unreachable block (ram,0xf00b8440) */
/* WARNING: Removing unreachable block (ram,0xf00b83b4) */
/* WARNING: Removing unreachable block (ram,0xf00b82bc) */
/* WARNING: Removing unreachable block (ram,0xf00b82a0) */
/* WARNING: Removing unreachable block (ram,0xf00b8270) */
/* WARNING: Removing unreachable block (ram,0xf00b828c) */
/* WARNING: Removing unreachable block (ram,0xf00b82b4) */
/* WARNING: Removing unreachable block (ram,0xf00b82e8) */
/* WARNING: Removing unreachable block (ram,0xf00b8424) */
/* WARNING: Removing unreachable block (ram,0xf00b8368) */
/* WARNING: Removing unreachable block (ram,0xf00b8380) */
/* WARNING: Removing unreachable block (ram,0xf00b8268) */

undefined8
sub_F00B8244(int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  uVar4 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  if ((_scsi_options & 2) != 0) {
    _printf(aMakeDeviceSD,param_4,param_5);
  }
  piVar1 = (int *)0x20;
  _kalloc();
  if (piVar1 == (int *)0x0) {
    uVar5 = 0;
  }
  else {
    _bzero(piVar1,0x20);
    piVar1[1] = (int)param_1;
    *(sword *)(piVar1 + 2) = (sword)param_6;
    *(char *)((int)piVar1 + 10) = (char)uVar4;
    iVar2 = 0x38;
    _kalloc();
    piVar1[3] = iVar2;
    if (iVar2 != 0) {
      _bzero();
      uVar5 = 8;
      _kalloc();
      *(undefined4 *)(piVar1[3] + 0x1c) = uVar5;
      iVar2 = piVar1[3];
      if (*(int *)(iVar2 + 0x1c) != 0) {
        _bzero(*(int *)(iVar2 + 0x1c),8);
        *(int *)piVar1[3] = param_2;
        iVar2 = piVar1[3];
        if (*(int *)(param_2 + 8) != 0) {
          *(int *)(iVar2 + 4) = *(int *)(param_2 + 8);
          iVar2 = piVar1[3];
        }
        *(int *)(param_2 + 8) = iVar2;
        *(undefined4 *)(piVar1[3] + 0xc) = param_4;
        *(undefined4 *)(piVar1[3] + 0x2c) = param_5;
        **(uint **)(piVar1[3] + 0x1c) = *param_1 >> 8 & 0xf;
        piVar3 = piVar1;
        (**(code **)(param_3 + 4))();
        if (-1 < (int)piVar3) {
          if (*(char *)(piVar1 + 7) != '\0') {
            _printf(aSDAtSDTargetDL,param_4,param_5,*(undefined4 *)(param_2 + 0xc),
                    *(undefined4 *)(param_2 + 0x2c),param_6,uVar4);
            (**(code **)(param_3 + 8))(piVar1);
          }
          if (_sd_root != (int *)0x0) {
            iVar2 = *_sd_root;
            piVar3 = _sd_root;
            while (iVar2 != 0) {
              piVar3 = (int *)*piVar3;
              iVar2 = *piVar3;
            }
            *piVar3 = (int)piVar1;
            piVar1 = _sd_root;
          }
          _sd_root = piVar1;
          uVar4 = _scsi_ncmds_per_dev;
          if ((code *)param_1[6] == _scsi_std_pktalloc) {
            iVar2 = _nscsi_devices + 1;
            .umul(iVar2,_scsi_ncmds_per_dev);
            uVar5 = 1;
            if (_scsi_ncmds < iVar2) {
              _scsi_addcmds(uVar4);
              uVar5 = 1;
            }
          }
          else {
            uVar5 = 1;
          }
          goto locret_F00B844C;
        }
        *(undefined4 *)(param_2 + 8) = *(undefined4 *)(piVar1[3] + 4);
        _kfree(*(undefined4 *)(piVar1[3] + 0x1c),8);
        iVar2 = piVar1[3];
      }
      _kfree(iVar2,0x38);
    }
    _kfree(piVar1,0x20);
    uVar5 = 0;
  }
locret_F00B844C:
  return CONCAT44(param_2,uVar5);
}
