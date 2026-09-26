
/* WARNING: Removing unreachable block (ram,0xf00b3458) */
/* WARNING: Removing unreachable block (ram,0xf00b3418) */
/* WARNING: Removing unreachable block (ram,0xf00b33e8) */
/* WARNING: Removing unreachable block (ram,0xf00b3330) */
/* WARNING: Removing unreachable block (ram,0xf00b32e4) */
/* WARNING: Removing unreachable block (ram,0xf00b32c0) */
/* WARNING: Removing unreachable block (ram,0xf00b3314) */
/* WARNING: Removing unreachable block (ram,0xf00b33cc) */
/* WARNING: Removing unreachable block (ram,0xf00b33f4) */
/* WARNING: Removing unreachable block (ram,0xf00b3444) */
/* WARNING: Removing unreachable block (ram,0xf00b3478) */
/* WARNING: Removing unreachable block (ram,0xf00b3274) */

undefined8 _devi_to_path(int *param_1,undefined4 param_2)

{
  code *pcVar1;
  char cVar2;
  undefined6 *puVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 unaff_l0;
  int *piVar6;
  undefined4 unaff_l1;
  int *piVar7;
  int *piVar8;
  undefined4 unaff_l3;
  char cVar9;
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
  iVar5 = 0;
  piVar6 = param_1;
  if (*(char *)param_1 != '\0') {
    cVar9 = *(char *)param_1;
    do {
      if (cVar9 < ':') goto loc_F00B3258;
      piVar6 = (int *)((int)piVar6 + 1);
      cVar9 = *(char *)piVar6;
    } while (cVar9 != '\0');
  }
  cVar9 = *(char *)piVar6;
loc_F00B3258:
  cVar2 = *(char *)piVar6;
  while ((cVar9 != '\0' && ((byte)(cVar2 - 0x30U) < 10))) {
    umul(iVar5,10);
    *(char *)piVar6 = '\0';
    piVar6 = (int *)((int)piVar6 + 1);
    cVar9 = *(char *)piVar6;
    iVar5 = iVar5 + -0x30 + (int)cVar2;
    cVar2 = *(char *)piVar6;
  }
  cVar9 = '\0';
  if (*(char *)piVar6 != '\0') {
    cVar9 = *(char *)piVar6;
  }
  piVar6 = param_1;
  _path_findnodebyname(param_1,iVar5,_top_devinfo);
  if (dword_F011DDA0 != 0) {
    _printf(aPathToDeviPath,piVar6);
  }
  *(char *)param_1 = '\0';
  if (piVar6 != (int *)0x0) {
    if (dword_F011DDA0 == 0) {
      piVar7 = (int *)*piVar6;
    }
    else {
      _printf(aPathToDeviDevi,piVar6[3],*piVar6);
      piVar7 = (int *)*piVar6;
    }
    if (piVar7 != (int *)0x0) {
      do {
        pcVar1 = (code *)*piVar6;
        _path_getencodefunc();
        if (pcVar1 == (code *)0x0) {
          pcVar1 = _obio_encode_reg;
        }
        piVar8 = piVar6;
        (*pcVar1)(piVar6,(undefined *)((int)register0x00000038 + -0x208));
        if (piVar8 != (int *)0xffffffff) {
          if (piVar8 < (int *)0x80000000) {
            cVar2 = *(char *)((int)register0x00000038 + -0x208);
            if (piVar8 == (int *)0x0) {
              *(char *)param_1 = '\0';
              goto locret_F00B3480;
            }
loc_F00B33B4:
            if (cVar2 == '\0') {
              puVar3 = &aSS_4;
              puVar4 = (undefined *)piVar6[3];
loc_F00B33E8:
              _sprintf((undefined *)((int)register0x00000038 + -0x108),puVar3,puVar4,param_1);
            }
            else {
              _sprintf((undefined *)((int)register0x00000038 + -0x108),aSSS,piVar6[3],
                       (undefined *)((int)register0x00000038 + -0x208),param_1);
            }
          }
          else {
            cVar2 = *(char *)((int)register0x00000038 + -0x208);
            if (piVar8 != (int *)0xfffffffe) goto loc_F00B33B4;
            if (cVar2 != '\0') {
              puVar3 = &aSS_3;
              puVar4 = (undefined *)((int)register0x00000038 + -0x208);
              goto loc_F00B33E8;
            }
          }
          _strcpy(param_1,(undefined *)((int)register0x00000038 + -0x108));
          if (dword_F011DDA0 != 0) {
            _printf(aNameS,param_1);
          }
        }
        piVar8 = (int *)*piVar7;
        piVar6 = piVar7;
        piVar7 = piVar8;
      } while (piVar8 != (int *)0x0);
    }
    if (cVar9 != 0) {
      piVar6 = param_1;
      _strlen(param_1);
      _sprintf((char *)((int)param_1 + (int)piVar6),&aC_1,(int)cVar9);
    }
    if (dword_F011DDA0 != 0) {
      _printf(aNameS_0,param_1);
    }
  }
locret_F00B3480:
  return CONCAT44(param_2,param_1);
}

