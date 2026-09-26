
/* WARNING: Removing unreachable block (ram,0xf00b2e24) */
/* WARNING: Removing unreachable block (ram,0xf00b2df4) */
/* WARNING: Removing unreachable block (ram,0xf00b2e0c) */
/* WARNING: Removing unreachable block (ram,0xf00b2e4c) */
/* WARNING: Removing unreachable block (ram,0xf00b2de4) */

undefined8 sub_F00B2DB8(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  code *pcVar4;
  int *piVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar6;
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
  piVar6 = (int *)param_2[3];
  if ((int *)param_2[3] != (int *)0x0) goto locret_F00B2E8C;
  if (dword_F011DDA0 != 0) {
    _printf(aCheckingS,param_1[3]);
  }
  iVar1 = *param_2;
  _strcmp(iVar1,&aSd);
  iVar2 = param_1[3];
  if (iVar1 == 0) {
    _strcmp(iVar2,&aSr);
    if (iVar2 != 0) {
      iVar2 = param_1[3];
      goto loc_F00B2E24;
    }
    pcVar3 = (char *)param_2[1];
  }
  else {
loc_F00B2E24:
    _strcmp(iVar2,*param_2);
    piVar6 = (int *)0x0;
    if (iVar2 != 0) goto locret_F00B2E8C;
    pcVar3 = (char *)param_2[1];
  }
  piVar6 = param_1;
  if (*pcVar3 == '\0') {
    param_2[3] = (int)param_1;
  }
  else {
    pcVar4 = (code *)*param_1;
    _path_getmatchfunc();
    if (pcVar4 == (code *)0x0) {
      pcVar4 = _obio_match;
    }
    piVar5 = param_1;
    (*pcVar4)(param_1,param_2[1]);
    if (piVar5 == (int *)0x0) {
      param_2[3] = 0;
      piVar6 = (int *)0x0;
    }
    else {
      param_2[3] = (int)param_1;
    }
  }
locret_F00B2E8C:
  return CONCAT44(param_2,piVar6);
}

