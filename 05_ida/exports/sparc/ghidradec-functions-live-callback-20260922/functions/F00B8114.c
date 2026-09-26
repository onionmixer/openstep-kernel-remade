
/* WARNING: Removing unreachable block (ram,0xf00b81d8) */
/* WARNING: Removing unreachable block (ram,0xf00b817c) */
/* WARNING: Removing unreachable block (ram,0xf00b820c) */
/* WARNING: Removing unreachable block (ram,0xf00b8130) */

undefined8 _scsi_config(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
  undefined4 unaff_l1;
  int *piVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  if (_scsi_spl < *param_1) {
    _scsi_spl = *param_1;
  }
  _scsi_rinit();
  piVar5 = &_scsi_conf;
  if (_scsi_conf != 0) {
    puVar4 = DAT_f011d30a;
    do {
      if (*piVar5 == *(int *)(param_2 + 0x20)) {
        iVar1 = *(int *)(param_2 + 0xc);
        _strcmp(iVar1,*(undefined4 *)(puVar4 + -6));
        if ((iVar1 == 0) && (*(int *)(param_2 + 0x2c) == (int)(char)puVar4[-2])) {
          uVar3 = (uint)(byte)puVar4[2];
          if ((0xf < uVar3) ||
             ((*(int **)(_scsibuscookies + uVar3 * 4) != (int *)0x0 &&
              (*(int **)(_scsibuscookies + uVar3 * 4) != param_1)))) {
            _printf(aSDIllegalScsiB,*(undefined4 *)(param_2 + 0xc));
            break;
          }
          *(int **)(_scsibuscookies + uVar3 * 4) = param_1;
          *(int *)(_scsibusctlrs + uVar3 * 4) = param_2;
          piVar2 = param_1;
          sub_F00B8244(param_1,param_2,*(undefined4 *)(puVar4 + -0xe),*(undefined4 *)(puVar4 + -10),
                       (int)(char)puVar4[1],(int)(char)puVar4[-1],(int)(char)*puVar4);
          if (piVar2 != (int *)0x0) {
            _nscsi_devices = _nscsi_devices + 1;
          }
        }
      }
      piVar5 = piVar5 + 6;
      puVar4 = puVar4 + 0x18;
    } while (*piVar5 != 0);
  }
  return CONCAT44(param_2,param_1);
}

