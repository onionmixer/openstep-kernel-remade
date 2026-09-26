/* GHIDRADEC_FUNCTION index=550 start=0xf00269c4 */

/* WARNING: Removing unreachable block (ram,0xf00269f0) */
/* WARNING: Removing unreachable block (ram,0xf00269fc) */
/* WARNING: Removing unreachable block (ram,0xf00269d4) */

undefined8
_lookupname(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined4 param_5)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined *puVar1;
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
  puVar1 = (undefined *)((int)register0x00000038 + -0x18);
  _pn_get(param_1,param_2,puVar1);
  if (param_1 == (undefined *)0x0) {
    param_1 = puVar1;
    _lookuppn(puVar1,param_3,param_4,param_5);
    _pn_free(puVar1);
  }
  return CONCAT44(puVar1,param_1);
}
/* GHIDRADEC_FUNCTION index=551 start=0xf0026a0c */

/* WARNING: Removing unreachable block (ram,0xf0026fd0) */
/* WARNING: Removing unreachable block (ram,0xf0026f90) */
/* WARNING: Removing unreachable block (ram,0xf0026fa4) */
/* WARNING: Removing unreachable block (ram,0xf0026c34) */
/* WARNING: Removing unreachable block (ram,0xf0027000) */
/* WARNING: Removing unreachable block (ram,0xf0026dac) */
/* WARNING: Removing unreachable block (ram,0xf0026e9c) */
/* WARNING: Removing unreachable block (ram,0xf0026e7c) */
/* WARNING: Removing unreachable block (ram,0xf0026e44) */
/* WARNING: Removing unreachable block (ram,0xf0026cac) */
/* WARNING: Removing unreachable block (ram,0xf0026b34) */
/* WARNING: Removing unreachable block (ram,0xf0026a68) */
/* WARNING: Removing unreachable block (ram,0xf0026afc) */
/* WARNING: Removing unreachable block (ram,0xf0026b54) */
/* WARNING: Removing unreachable block (ram,0xf0026cd8) */
/* WARNING: Removing unreachable block (ram,0xf0026e70) */
/* WARNING: Removing unreachable block (ram,0xf0026e88) */
/* WARNING: Removing unreachable block (ram,0xf0026ddc) */
/* WARNING: Removing unreachable block (ram,0xf0026ff8) */
/* WARNING: Removing unreachable block (ram,0xf0026d7c) */
/* WARNING: Removing unreachable block (ram,0xf0026f28) */
/* WARNING: Removing unreachable block (ram,0xf0026f84) */
/* WARNING: Removing unreachable block (ram,0xf0026fc0) */
/* WARNING: Removing unreachable block (ram,0xf0026fd8) */
/* WARNING: Removing unreachable block (ram,0xf0026a60) */

undefined8 _lookuppn(int param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  word wVar2;
  sword sVar3;
  char *pcVar4;
  undefined4 unaff_l0;
  undefined *puVar5;
  undefined4 unaff_l1;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int iVar9;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar10;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar11;
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
  iVar9 = 0;
  iVar6 = _active_u[0x57];
  *(sword *)(iVar6 + 6) = *(sword *)(iVar6 + 6) + 1;
loc_F0026A38:
  *(undefined *)((int)register0x00000038 + -0x108) = 0;
  if (*(int *)(param_1 + 8) == 0) {
loc_F0026AC4:
    iVar10 = 2;
    if ((*(uint *)(*_active_u + 0x14) & 0x4000) != 0) goto locret_F0027008;
  }
  else {
    if (**(char **)(param_1 + 4) != '/') {
      if ((*(int *)(param_1 + 8) != 0) && (**(char **)(param_1 + 4) != '\0')) {
        iVar1 = *(int *)(iVar6 + 0x28);
        goto loc_F0026AE4;
      }
      goto loc_F0026AC4;
    }
    _vn_rele(iVar6);
    _pn_skipslash(param_1);
    iVar6 = _active_u[0x58];
    if (_active_u[0x58] == 0) {
      iVar6 = _rootdir;
    }
    *(sword *)(iVar6 + 6) = *(sword *)(iVar6 + 6) + 1;
  }
  while( true ) {
    iVar1 = *(int *)(iVar6 + 0x28);
loc_F0026AE4:
    iVar8 = 0;
    iVar10 = 0x14;
    iVar7 = iVar6;
    if (iVar1 != 2) goto loc_F0026FEC;
    puVar5 = (undefined *)((int)register0x00000038 + -0x108);
    iVar10 = param_1;
    _pn_getcomponent(param_1,puVar5,0);
    bVar11 = true;
    if (iVar10 != 0) goto loc_F0026FF0;
    if (*(char *)((int)register0x00000038 + -0x108) == '\0') break;
    _strcmp(puVar5,&unk_F010C130);
    if (puVar5 != (undefined *)0x0) {
      iVar6 = *(int *)(iVar6 + 0x10);
loc_F0026C60:
      do {
        iVar8 = 0;
        if (iVar6 == 0) goto loc_F0026D20;
        iVar10 = iVar7;
        (**(code **)(*(int *)(iVar7 + 0x1c) + 0x1c))(iVar7,0x40,_active_u[7]);
        bVar11 = true;
        if (iVar10 != 0) goto loc_F0026FF0;
        iVar10 = *(int *)(iVar7 + 0x10);
        while( true ) {
          if (iVar10 == 0) goto loc_F0026D20;
          iVar6 = iVar10 + 0x20;
          _strncmp(iVar6,(undefined *)((int)register0x00000038 + -0x108),0xff);
          if (iVar6 == 0) break;
          iVar10 = *(int *)(iVar10 + 0x120);
        }
        if ((*(uint *)(iVar10 + 0xc) & 2) == 0) {
          (**(code **)(*(int *)(iVar10 + 4) + 8))
                    (iVar10,(undefined *)((int)register0x00000038 + -0x10c));
          bVar11 = true;
          if (iVar10 != 0) goto loc_F0026FF0;
          iVar8 = *(int *)((int)register0x00000038 + -0x10c);
          goto loc_F0026EAC;
        }
        *(uint *)(iVar10 + 0xc) = *(uint *)(iVar10 + 0xc) | 4;
        _sleep(iVar10,0x1b);
        iVar6 = *(int *)(iVar7 + 0x10);
      } while( true );
    }
    do {
      iVar1 = _active_u[0x58];
      iVar6 = iVar7;
      if (iVar7 == iVar1) break;
      if ((((iVar7 != 0) && (iVar1 != 0)) && (*(int *)(iVar7 + 0x1c) == *(int *)(iVar1 + 0x1c))) &&
         (iVar1 = iVar7, (**(code **)(*(int *)(iVar7 + 0x1c) + 0x6c))(), iVar1 != 0)) {
        sVar3 = *(sword *)(iVar7 + 6);
        goto loc_F0026C50;
      }
      if (iVar7 == _rootdir) break;
      if (iVar7 == 0) {
loc_F0026C0C:
        wVar2 = *(word *)(iVar7 + 4);
      }
      else if (_rootdir == 0) {
        wVar2 = *(word *)(iVar7 + 4);
      }
      else {
        if (*(int *)(iVar7 + 0x1c) == *(int *)(_rootdir + 0x1c)) {
          (**(code **)(*(int *)(iVar7 + 0x1c) + 0x6c))();
          if (iVar6 == 0) goto loc_F0026C0C;
          sVar3 = *(sword *)(iVar7 + 6);
          goto loc_F0026C50;
        }
        wVar2 = *(word *)(iVar7 + 4);
      }
      if ((wVar2 & 1) == 0) {
        iVar6 = *(int *)(iVar7 + 0x10);
        goto loc_F0026C60;
      }
      iVar6 = *(int *)(*(int *)(iVar7 + 0x24) + 8);
      *(sword *)(iVar6 + 6) = *(sword *)(iVar6 + 6) + 1;
      _vn_rele(iVar7);
      iVar7 = iVar6;
    } while (*(int *)(iVar6 + 0xc) != 0);
    sVar3 = *(sword *)(iVar6 + 6);
    iVar7 = iVar6;
loc_F0026C50:
    *(sword *)(iVar7 + 6) = sVar3 + 1;
    iVar8 = iVar7;
loc_F0026EAC:
    iVar6 = *(int *)(param_1 + 8);
loc_F0026EB0:
    if (iVar6 == 0) {
loc_F0026F18:
      iVar1 = *(int *)(param_1 + 8);
      iVar6 = iVar8;
    }
    else {
      iVar6 = iVar8;
      if ((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) {
        iVar1 = *(int *)(param_1 + 8);
      }
      else {
        for (pcVar4 = *(char **)(param_1 + 4); *pcVar4 == '/'; pcVar4 = pcVar4 + 1) {
        }
        if (*pcVar4 == '\0') {
          if (*(int *)(iVar8 + 0x28) == 2) {
            **(undefined **)(param_1 + 4) = 0;
            *(undefined4 *)(param_1 + 8) = 0;
            goto loc_F0026F18;
          }
          iVar1 = *(int *)(param_1 + 8);
        }
        else {
          iVar1 = *(int *)(param_1 + 8);
        }
      }
    }
    if (iVar1 == 0) {
      _pn_set(param_1,(undefined *)((int)register0x00000038 + -0x108));
      if (param_3 == (int *)0x0) {
        _vn_rele(iVar7);
      }
      else {
        if (iVar7 == iVar6) {
loc_F0026F84:
          _vn_rele(iVar7);
          goto loc_F0026F90;
        }
        if (iVar7 == 0) {
          *param_3 = 0;
        }
        else if (iVar6 == 0) {
          *param_3 = iVar7;
        }
        else if (*(int *)(iVar7 + 0x1c) == *(int *)(iVar6 + 0x1c)) {
          iVar9 = iVar7;
          (**(code **)(*(int *)(iVar7 + 0x1c) + 0x6c))(iVar7,iVar6);
          if (iVar9 != 0) goto loc_F0026F84;
          *param_3 = iVar7;
        }
        else {
          *param_3 = iVar7;
        }
      }
      if (param_4 == (int *)0x0) {
loc_F0026FC0:
        _vn_rele(iVar6);
      }
      else {
        *param_4 = iVar6;
      }
      goto loc_F0026FC8;
    }
    _pn_skipslash(param_1);
    _vn_rele(iVar7);
  }
  if (param_3 == (int *)0x0) {
    _pn_set(param_1,&unk_F010C128);
    if (param_4 == (int *)0x0) goto loc_F0026FC0;
    *param_4 = iVar6;
    goto loc_F0026FC8;
  }
loc_F0026F90:
  iVar10 = 0x11;
  _vn_rele(iVar6);
  goto locret_F0027008;
loc_F0026D20:
  iVar10 = iVar7;
  (**(code **)(*(int *)(iVar7 + 0x1c) + 0x20))
            (iVar7,(undefined *)((int)register0x00000038 + -0x108),
             (undefined *)((int)register0x00000038 + -0x10c),_active_u[7],param_1,0);
  iVar8 = *(int *)((int)register0x00000038 + -0x10c);
  if (iVar10 == 0) {
    while( true ) {
      iVar6 = *(int *)(iVar8 + 0xc);
      while( true ) {
        if (iVar6 == 0) {
          if (*(int *)(iVar8 + 0x28) != 5) {
            iVar6 = *(int *)(param_1 + 8);
            goto loc_F0026EB0;
          }
          if ((param_2 != 1) && (*(int *)(param_1 + 8) == 0)) goto loc_F0026F18;
          iVar9 = iVar9 + 1;
          iVar10 = 0x3e;
          if (0x14 < iVar9) goto loc_F0026FEC;
          puVar5 = (undefined *)((int)register0x00000038 + -0x120);
          iVar10 = iVar8;
          sub_F0027010(iVar8,(undefined *)((int)register0x00000038 + -0x108),iVar7,puVar5);
          bVar11 = iVar8 == 0;
          if (iVar10 != 0) goto loc_F0026FF0;
          if (*(int *)((int)register0x00000038 + -0x118) == 0) {
            _pn_set(puVar5,&unk_F010C138);
          }
          iVar10 = param_1;
          _pn_combine(param_1,puVar5);
          _pn_free(puVar5);
          bVar11 = iVar8 == 0;
          if (iVar10 != 0) goto loc_F0026FF0;
          _vn_rele(iVar8);
          iVar6 = iVar7;
          goto loc_F0026A38;
        }
        if ((*(uint *)(iVar6 + 0xc) & 2) == 0) break;
        *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) | 4;
        _sleep(iVar6,0x1b);
        iVar6 = *(int *)(iVar8 + 0xc);
      }
      iVar10 = *(int *)(iVar8 + 0xc);
      (**(code **)(*(int *)(iVar10 + 4) + 8))
                (iVar10,(undefined *)((int)register0x00000038 + -0x10c));
      bVar11 = iVar8 == 0;
      if (iVar10 != 0) break;
      _vn_rele(iVar8);
      iVar8 = *(int *)((int)register0x00000038 + -0x10c);
    }
    goto loc_F0026FF0;
  }
  iVar8 = 0;
  if (((*(int *)(param_1 + 8) == 0) && (param_3 != (int *)0x0)) && (iVar10 != 0xd)) {
    _pn_set(param_1,(undefined *)((int)register0x00000038 + -0x108));
    *param_3 = iVar7;
    if (param_4 != (int *)0x0) {
      *param_4 = 0;
    }
loc_F0026FC8:
    iVar10 = 0;
  }
  else {
loc_F0026FEC:
    bVar11 = iVar8 == 0;
loc_F0026FF0:
    if (!bVar11) {
      _vn_rele(iVar8);
    }
    _vn_rele(iVar7);
  }
locret_F0027008:
  return CONCAT44(param_2,iVar10);
}
/* GHIDRADEC_FUNCTION index=552 start=0xf0027298 */

/* WARNING: Removing unreachable block (ram,0xf002729c) */

undefined8 _pn_alloc(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  uVar1 = 0x400;
  _kalloc();
  *param_1 = uVar1;
  param_1[1] = uVar1;
  param_1[2] = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=553 start=0xf00272b8 */

/* WARNING: Removing unreachable block (ram,0xf00272d8) */
/* WARNING: Removing unreachable block (ram,0xf00272f0) */
/* WARNING: Removing unreachable block (ram,0xf002733c) */
/* WARNING: Removing unreachable block (ram,0xf00272bc) */

undefined8 _pn_get(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool bVar2;
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
  _pn_alloc(param_3);
  if (param_2 == 0) {
    _copyinstr(param_1,*(undefined4 *)(param_3 + 4),0x400,param_3 + 8);
  }
  else {
    _copystr(param_1,*(undefined4 *)(param_3 + 4),0x400,param_3 + 8);
  }
  iVar1 = *(int *)(param_3 + 8);
  bVar2 = false;
  if ((param_1 == 0) && (bVar2 = true, iVar1 == 0x400)) {
    if (*(char *)(*(int *)(param_3 + 4) + 0x3ff) != '\0') {
      param_1 = 0x3f;
    }
    iVar1 = *(int *)(param_3 + 8);
    bVar2 = param_1 == 0;
  }
  *(int *)(param_3 + 8) = iVar1 + -1;
  if (!bVar2) {
    _pn_free(param_3);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=554 start=0xf002734c */

/* WARNING: Removing unreachable block (ram,0xf0027360) */

undefined8 _pn_set(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  param_1[1] = *param_1;
  uVar1 = param_2;
  _copystr(param_2,*param_1,0x400,param_1 + 2);
  param_1[2] = param_1[2] + -1;
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=555 start=0xf002737c */

/* WARNING: Removing unreachable block (ram,0xf00273b4) */
/* WARNING: Removing unreachable block (ram,0xf00273a4) */

undefined8 _pn_combine(int *param_1,int param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  uVar1 = 0x3f;
  if ((uint)(param_1[2] + *(int *)(param_2 + 8)) < 0x400) {
    _ovbcopy(param_1[1],*param_1 + *(int *)(param_2 + 8));
    _bcopy(*(undefined4 *)(param_2 + 4),*param_1,*(undefined4 *)(param_2 + 8));
    uVar1 = 0;
    param_1[2] = param_1[2] + *(int *)(param_2 + 8);
    param_1[1] = *param_1;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=556 start=0xf00273e0 */

/* WARNING: Removing unreachable block (ram,0xf0027410) */
/* WARNING: Removing unreachable block (ram,0xf00273e8) */

undefined8 _pn_append(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  iVar1 = param_2;
  _strlen();
  if ((uint)(*(int *)(param_1 + 8) + iVar1) < 0x400) {
    _bcopy(param_2,*(int *)(param_1 + 4) + *(int *)(param_1 + 8),iVar1 + 1);
    uVar2 = 0;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar1;
  }
  else {
    uVar2 = 0x3f;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=557 start=0xf0027438 */

undefined8 _pn_getcomponent(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar4;
  undefined4 unaff_i3;
  int iVar5;
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
  iVar4 = *(int *)(param_1 + 8);
  iVar5 = 0xff;
  pcVar2 = *(char **)(param_1 + 4);
  do {
    if (iVar4 < 1) {
      *(char **)(param_1 + 4) = pcVar2;
loc_F002748C:
      *(int *)(param_1 + 8) = iVar4;
      *param_2 = '\0';
      uVar3 = 0;
locret_F0027498:
      return CONCAT44(param_2,uVar3);
    }
    cVar1 = *pcVar2;
    if (cVar1 == '/') {
      *(char **)(param_1 + 4) = pcVar2;
      goto loc_F002748C;
    }
    iVar5 = iVar5 + -1;
    pcVar2 = pcVar2 + 1;
    if (iVar5 < 0) {
      uVar3 = 0x3f;
      goto locret_F0027498;
    }
    *param_2 = cVar1;
    iVar4 = iVar4 + -1;
    param_2 = param_2 + 1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=558 start=0xf00274a0 */

undefined8 _pn_skipslash(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  iVar1 = *(int *)(param_1 + 8);
  while ((iVar1 != 0 && (**(char **)(param_1 + 4) == '/'))) {
    *(char **)(param_1 + 4) = *(char **)(param_1 + 4) + 1;
    iVar1 = *(int *)(param_1 + 8) + -1;
    *(int *)(param_1 + 8) = iVar1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=559 start=0xf00274e8 */

/* WARNING: Removing unreachable block (ram,0xf00274f0) */

undefined8 _pn_free(undefined4 *param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  _kfree(*param_1,0x400);
  *param_1 = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=560 start=0xf0027504 */

/* WARNING: Removing unreachable block (ram,0xf0027540) */
/* WARNING: Removing unreachable block (ram,0xf0027518) */

undefined8 _chdir(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  uVar1 = **(undefined4 **)(dword_F0133DDC + 0x24);
  _chdirec(uVar1,(undefined *)((int)register0x00000038 + -0xc));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    _vn_rele(*(undefined4 *)(_active_u + 0x15c));
    *(undefined4 *)(_active_u + 0x15c) = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=561 start=0xf002755c */

/* WARNING: Removing unreachable block (ram,0xf0027580) */
/* WARNING: Removing unreachable block (ram,0xf00275b8) */
/* WARNING: Removing unreachable block (ram,0xf0027568) */

undefined8 _chroot(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar3;
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
  puVar3 = *(undefined4 **)(dword_F0133DDC + 0x24);
  iVar1 = dword_F0133DDC;
  _suser();
  if (iVar1 != 0) {
    uVar2 = *puVar3;
    _chdirec(uVar2,(undefined *)((int)register0x00000038 + -0xc));
    *(char *)(dword_F0133DDC + 0x38) = (char)uVar2;
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      if (*(int *)(_active_u + 0x160) != 0) {
        _vn_rele();
      }
      *(undefined4 *)(_active_u + 0x160) = *(undefined4 *)((int)register0x00000038 + -0xc);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=562 start=0xf00275d4 */

/* WARNING: Removing unreachable block (ram,0xf002763c) */
/* WARNING: Removing unreachable block (ram,0xf00275e8) */

undefined8 _chdirec(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  _lookupname(param_1,0,1,0,(undefined *)((int)register0x00000038 + -0xc));
  iVar1 = *(int *)((int)register0x00000038 + -0xc);
  if (param_1 == 0) {
    param_1 = 0x14;
    if (*(int *)(iVar1 + 0x28) == 2) {
      (**(code **)(*(int *)(iVar1 + 0x1c) + 0x1c))(iVar1,0x40,*(undefined4 *)(_active_u + 0x1c));
      param_1 = iVar1;
    }
    if (param_1 == 0) {
      *param_2 = *(undefined4 *)((int)register0x00000038 + -0xc);
    }
    else {
      _vn_rele(*(undefined4 *)((int)register0x00000038 + -0xc));
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=563 start=0xf0027654 */

/* WARNING: Removing unreachable block (ram,0xf00276b0) */
/* WARNING: Removing unreachable block (ram,0xf0027670) */

undefined8 _open(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 *puVar3;
  undefined4 unaff_l1;
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
  puVar3 = *(undefined4 **)(dword_F0133DDC + 0x24);
  iVar1 = (int)*(sword *)(*_active_u + 0x30);
  _get_posix_proc();
  *(uint *)(iVar1 + 0x18) =
       *(uint *)(iVar1 + 0x18) & 0xbfffffff | ((uint)puVar3[1] >> 4 & 1) << 0x1e;
  uVar2 = *puVar3;
  _copen(uVar2,puVar3[1] + 1,puVar3[2]);
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar2;
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & 0xbfffffff;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=564 start=0xf00276d4 */

/* WARNING: Removing unreachable block (ram,0xf00276ec) */

undefined8 _creat(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  uVar1 = **(undefined4 **)(dword_F0133DDC + 0x24);
  _copen(uVar1,0x602,(*(undefined4 **)(dword_F0133DDC + 0x24))[1]);
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=565 start=0xf0027704 */

/* WARNING: Removing unreachable block (ram,0xf002777c) */
/* WARNING: Removing unreachable block (ram,0xf0027758) */
/* WARNING: Removing unreachable block (ram,0xf0027788) */
/* WARNING: Removing unreachable block (ram,0xf0027708) */

undefined8 _copen(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar3;
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
  iVar1 = param_1;
  _falloc();
  if (iVar1 == 0) {
    param_1 = (int)*(char *)(dword_F0133DDC + 0x38);
  }
  else {
    iVar3 = *(int *)(dword_F0133DDC + 0x30);
    _vn_open(param_1,0,param_2,param_3 & ~(int)*(sword *)((int)_active_u + 0x16a) & 0xfffU,
             (undefined *)((int)register0x00000038 + -0xc));
    if (param_1 == 0) {
      *(uint *)(iVar1 + 8) = param_2 & 0xa000004b;
      if (((*(uint *)(*_active_u + 0x14) & 0x4000) != 0) &&
         (*(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x28) == 1)) {
        *(uint *)(iVar1 + 8) = param_2 & 0xa000004b | 0x40001000;
      }
      *(undefined2 *)(iVar1 + 0xc) = 1;
      iVar2 = *(int *)((int)register0x00000038 + -0xc);
      *(undefined **)(iVar1 + 0x14) = _vnodefops;
      *(int *)(iVar1 + 0x18) = iVar2;
      if (*(int *)(iVar2 + 0x28) == 8) {
        *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | param_2 & 4;
      }
      *(int *)(_active_u[0x53] + iVar3 * 4) = iVar1;
    }
    else {
      *(undefined4 *)(_active_u[0x53] + iVar3 * 4) = 0;
      _crfree(*(undefined4 *)(iVar1 + 0x20));
      *(undefined2 *)(iVar1 + 0xe) = 0;
      _free_file(iVar1);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=566 start=0xf0027830 */

/* WARNING: Removing unreachable block (ram,0xf002795c) */
/* WARNING: Removing unreachable block (ram,0xf002788c) */
/* WARNING: Removing unreachable block (ram,0xf0027984) */
/* WARNING: Removing unreachable block (ram,0xf0027878) */

undefined8 _mknod(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 *puVar3;
  undefined4 unaff_l1;
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
  puVar3 = *(undefined4 **)(dword_F0133DDC + 0x24);
  if ((puVar3[1] & 0xf000) == 0) {
    puVar3[1] = puVar3[1] | 0x8000;
  }
  uVar1 = puVar3[1] & 0xf000;
  if ((uVar1 == 0x1000) || (_suser(), uVar1 != 0)) {
    _vattr_null((undefined *)((int)register0x00000038 + -0x48));
    uVar2 = *(undefined4 *)(_mftovt_tab + ((int)(puVar3[1] & 0xf000) >> 0xd) * 4);
    *(undefined4 *)((int)register0x00000038 + -0x48) = uVar2;
    *(word *)((int)register0x00000038 + -0x44) =
         (word)puVar3[1] & 0xfff & ~*(word *)(_active_u + 0x16a);
    switch(uVar2) {
    case :
      *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
      break;
    case :
      *(undefined *)(dword_F0133DDC + 0x38) = 0x15;
      break;
    case :
    case :
    case :
    case :
      *(sword *)((int)register0x00000038 + -0x10) = (sword)puVar3[2];
    :
      uVar2 = *puVar3;
      _vn_create(uVar2,0,(undefined *)((int)register0x00000038 + -0x48),1,0,
                 (undefined *)((int)register0x00000038 + -0x4c));
      *(char *)(dword_F0133DDC + 0x38) = (char)uVar2;
      if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
        _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x4c));
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=567 start=0xf0027994 */

/* WARNING: Removing unreachable block (ram,0xf00279e8) */
/* WARNING: Removing unreachable block (ram,0xf0027a0c) */
/* WARNING: Removing unreachable block (ram,0xf00279a8) */

undefined8 _mkdir(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar2;
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
  puVar2 = *(undefined4 **)(dword_F0133DDC + 0x24);
  _vattr_null((undefined *)((int)register0x00000038 + -0x48));
  *(undefined4 *)((int)register0x00000038 + -0x48) = 2;
  *(word *)((int)register0x00000038 + -0x44) =
       (word)puVar2[1] & 0x1ff & ~*(word *)(_active_u + 0x16a);
  uVar1 = *puVar2;
  _vn_create(uVar1,0,(undefined *)((int)register0x00000038 + -0x48),1,0,
             (undefined *)((int)register0x00000038 + -0x4c));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x4c));
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=568 start=0xf0027a1c */

/* WARNING: Removing unreachable block (ram,0xf0027a34) */

undefined8 _link(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  uVar1 = **(undefined4 **)(dword_F0133DDC + 0x24);
  _vn_link(uVar1,(*(undefined4 **)(dword_F0133DDC + 0x24))[1],0);
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=569 start=0xf0027a4c */

/* WARNING: Removing unreachable block (ram,0xf0027a64) */

undefined8 _rename(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  uVar1 = **(undefined4 **)(dword_F0133DDC + 0x24);
  _vn_rename(uVar1,(*(undefined4 **)(dword_F0133DDC + 0x24))[1],0);
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=570 start=0xf0027a7c */

/* WARNING: Removing unreachable block (ram,0xf0027b90) */
/* WARNING: Removing unreachable block (ram,0xf0027b80) */
/* WARNING: Removing unreachable block (ram,0xf0027b20) */
/* WARNING: Removing unreachable block (ram,0xf0027ac8) */
/* WARNING: Removing unreachable block (ram,0xf0027b34) */
/* WARNING: Removing unreachable block (ram,0xf0027b88) */
/* WARNING: Removing unreachable block (ram,0xf0027aec) */
/* WARNING: Removing unreachable block (ram,0xf0027a98) */

undefined8 _symlink(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
  undefined4 unaff_l1;
  undefined4 *puVar5;
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
  puVar5 = *(undefined4 **)(dword_F0133DDC + 0x24);
  puVar4 = (undefined *)((int)register0x00000038 + -0x68);
  uVar1 = puVar5[1];
  _pn_get(uVar1,0,puVar4);
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    puVar2 = puVar4;
    _lookuppn(puVar4,0,(undefined *)((int)register0x00000038 + -0x6c),0);
    *(char *)(dword_F0133DDC + 0x38) = (char)puVar2;
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      if ((*(uint *)(*(int *)(*(int *)((int)register0x00000038 + -0x6c) + 0x24) + 0xc) & 1) == 0) {
        uVar1 = *puVar5;
        _pn_get(uVar1,0,(undefined *)((int)register0x00000038 + -0x58));
        *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
        _vattr_null((undefined *)((int)register0x00000038 + -0x48));
        *(undefined2 *)((int)register0x00000038 + -0x44) = 0x1ff;
        if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
          iVar3 = *(int *)((int)register0x00000038 + -0x6c);
          (**(code **)(*(int *)(iVar3 + 0x1c) + 0x40))
                    (iVar3,*(undefined4 *)((int)register0x00000038 + -100),
                     (undefined *)((int)register0x00000038 + -0x48),
                     *(undefined4 *)((int)register0x00000038 + -0x54),
                     *(undefined4 *)(_active_u + 0x1c));
          *(char *)(dword_F0133DDC + 0x38) = (char)iVar3;
          _pn_free((undefined *)((int)register0x00000038 + -0x58));
        }
      }
      else {
        *(undefined *)(dword_F0133DDC + 0x38) = 0x1e;
      }
      _pn_free((undefined *)((int)register0x00000038 + -0x68));
      _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x6c));
    }
    else {
      _pn_free(puVar4);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=571 start=0xf0027ba0 */

/* WARNING: Removing unreachable block (ram,0xf0027bb8) */

undefined8 _unlink(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  uVar1 = **(undefined4 **)(dword_F0133DDC + 0x24);
  _vn_remove(uVar1,0,0);
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=572 start=0xf0027bd0 */

/* WARNING: Removing unreachable block (ram,0xf0027be8) */

undefined8 _rmdir(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  uVar1 = **(undefined4 **)(dword_F0133DDC + 0x24);
  _vn_remove(uVar1,0,1);
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=573 start=0xf0027c00 */

/* WARNING: Removing unreachable block (ram,0xf0027ce4) */
/* WARNING: Removing unreachable block (ram,0xf0027d18) */
/* WARNING: Removing unreachable block (ram,0xf0027c14) */

undefined8 _getdirentries(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar4;
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
  puVar4 = *(undefined4 **)(dword_F0133DDC + 0x24);
  uVar1 = *puVar4;
  _getvnodefp(uVar1,(undefined *)((int)register0x00000038 + -0x2c));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    if ((*(uint *)(*(int *)((int)register0x00000038 + -0x2c) + 8) & 1) == 0) {
      *(undefined *)(dword_F0133DDC + 0x38) = 9;
    }
    else {
      uVar1 = puVar4[1];
      while( true ) {
        *(undefined4 *)((int)register0x00000038 + -0x28) = uVar1;
        iVar3 = *(int *)((int)register0x00000038 + -0x2c);
        *(undefined4 *)((int)register0x00000038 + -0x24) = puVar4[2];
        *(undefined **)((int)register0x00000038 + -0x20) =
             (undefined *)((int)register0x00000038 + -0x28);
        *(undefined4 *)((int)register0x00000038 + -0x1c) = 1;
        iVar2 = *(int *)(iVar3 + 0x1c);
        *(int *)((int)register0x00000038 + -0x18) = iVar2;
        *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
        *(undefined4 *)((int)register0x00000038 + -0xc) = puVar4[2];
        if (iVar2 < 0) break;
        iVar2 = *(int *)(iVar3 + 0x18);
        (**(code **)(*(int *)(iVar2 + 0x1c) + 0x3c))
                  (iVar2,(undefined *)((int)register0x00000038 + -0x20),
                   *(undefined4 *)(iVar3 + 0x20));
        *(char *)(dword_F0133DDC + 0x38) = (char)iVar2;
        if (puVar4[2] != *(int *)((int)register0x00000038 + -0xc)) goto loc_F0027CFC;
        *(undefined4 *)(*(int *)((int)register0x00000038 + -0x2c) + 0x1c) = 0xfffffc00;
        uVar1 = puVar4[1];
      }
      uVar1 = *(undefined4 *)(iVar3 + 0x18);
      _getfakedirentries(uVar1,(undefined *)((int)register0x00000038 + -0x20),
                         *(undefined4 *)(iVar3 + 0x20));
      *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
loc_F0027CFC:
      if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
        iVar2 = *(int *)((int)register0x00000038 + -0x2c) + 0x1c;
        _copyout(iVar2,puVar4[3],4);
        *(char *)(dword_F0133DDC + 0x38) = (char)iVar2;
        iVar2 = *(int *)((int)register0x00000038 + -0x2c);
        *(int *)(dword_F0133DDC + 0x30) = puVar4[2] - *(int *)((int)register0x00000038 + -0xc);
        *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)((int)register0x00000038 + -0x18);
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=574 start=0xf0027d50 */

/* WARNING: Removing unreachable block (ram,0xf0027ef4) */
/* WARNING: Removing unreachable block (ram,0xf0027e28) */
/* WARNING: Removing unreachable block (ram,0xf0027dec) */
/* WARNING: Removing unreachable block (ram,0xf0027e18) */
/* WARNING: Removing unreachable block (ram,0xf0027e40) */
/* WARNING: Removing unreachable block (ram,0xf0027f04) */
/* WARNING: Removing unreachable block (ram,0xf0027d98) */

undefined8 _getfakedirentries(int param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  uint uVar5;
  undefined4 unaff_l3;
  undefined4 *puVar6;
  int iVar7;
  undefined4 unaff_l4;
  uint uVar8;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar9;
  undefined4 *puVar10;
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
  iVar4 = *(int *)(param_1 + 0x10);
  if (iVar4 == 0) {
    puVar9 = (undefined4 *)0x0;
    goto locret_F0027F24;
  }
  puVar6 = *(undefined4 **)(param_2 + 0x14);
  uVar8 = 0xfffffc00 - *(int *)(param_2 + 8);
  if (puVar6 != (undefined4 *)0x0) {
    uVar5 = 0;
    if (uVar8 != 0) {
      do {
        puVar9 = (undefined4 *)0x0;
        if (iVar4 == 0) goto locret_F0027F24;
        uVar1 = iVar4 + 0x20;
        _strlen();
        *(sword *)((int)register0x00000038 + -0x10a) = (sword)uVar1;
        iVar3 = ((uVar1 & 0xffff) + 4 & 0xfffffffc) + 8;
        uVar1 = uVar5 & 0xfffffc00;
        uVar5 = uVar5 + iVar3;
        if (0x400 < uVar1 + iVar3) {
          uVar5 = uVar1 + 0x400;
        }
        iVar4 = *(int *)(iVar4 + 0x120);
      } while (uVar5 < uVar8);
    }
    puVar9 = (undefined4 *)0x0;
    if (iVar4 == 0) goto locret_F0027F24;
    puVar2 = puVar6;
    _kalloc();
    iVar3 = 0;
    puVar10 = puVar2;
    for (puVar9 = puVar6; iVar7 = 0, puVar9 != (undefined4 *)0x0;
        puVar9 = (undefined4 *)((int)puVar9 - uVar5)) {
      *puVar10 = 0xffffffff;
      iVar7 = iVar4 + 0x20;
      _strlen();
      *(sword *)((int)puVar10 + 6) = (sword)iVar7;
      _strcpy(puVar10 + 2,iVar4 + 0x20);
      iVar4 = *(int *)(iVar4 + 0x120);
      if (iVar4 == 0) {
        *(sword *)(puVar10 + 1) = (sword)(0x400U - iVar3);
        uVar5 = 0x400U - iVar3 & 0xffff;
        iVar7 = (int)puVar9 - uVar5;
        uVar8 = uVar8 + uVar5;
        break;
      }
      uVar5 = iVar4 + 0x20;
      _strlen();
      *(sword *)((int)register0x00000038 + -0x10a) = (sword)uVar5;
      if (((uVar5 & 0xffff) + 4 & 0xfffffffc) + iVar3 + 0x10 +
          (*(word *)((int)puVar10 + 6) + 4 & 0xfffffffc) < 0x401) {
        *(word *)(puVar10 + 1) = (*(word *)((int)puVar10 + 6) + 4 & 0xfffc) + 8;
        iVar3 = iVar3 + 8 + (*(word *)((int)puVar10 + 6) + 4 & 0xfffffffc);
      }
      else {
        *(sword *)(puVar10 + 1) = 0x400 - (sword)iVar3;
        iVar3 = 0;
      }
      uVar5 = (uint)*(word *)(puVar10 + 1);
      uVar8 = uVar8 + uVar5;
      puVar10 = (undefined4 *)((int)puVar10 + uVar5);
    }
    puVar9 = puVar2;
    _uiomove(puVar2,*(int *)(param_2 + 0x14) - iVar7,0,param_2);
    _kfree(puVar2,puVar6);
    if (puVar9 != (undefined4 *)0x0) goto locret_F0027F24;
    *(uint *)(param_2 + 8) = -(uVar8 + 0x400);
  }
  puVar9 = (undefined4 *)0x0;
locret_F0027F24:
  return CONCAT44(param_2,puVar9);
}
/* GHIDRADEC_FUNCTION index=575 start=0xf0027f2c */

/* WARNING: Removing unreachable block (ram,0xf0027f40) */

undefined8 _lseek(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 *puVar4;
  undefined4 unaff_l1;
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
  puVar4 = *(undefined4 **)(dword_F0133DDC + 0x24);
  uVar1 = *puVar4;
  _getvnodefp(uVar1,(undefined *)((int)register0x00000038 + -0xc));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    iVar3 = *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x18);
    if (*(int *)(iVar3 + 0x28) != 8) {
      iVar2 = puVar4[2];
      if (iVar2 == 1) {
        iVar3 = *(int *)((int)register0x00000038 + -0xc);
        if (((*(uint *)(*_active_u + 0x14) & 0x4000) != 0) &&
           (iVar3 = *(int *)((int)register0x00000038 + -0xc),
           *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c) + puVar4[1] < 0)) {
loc_F00280BC:
          *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
          goto locret_F00280F4;
        }
        *(int *)(iVar3 + 0x1c) = *(int *)(iVar3 + 0x1c) + puVar4[1];
      }
      else if (iVar2 < 2) {
        if (iVar2 == 0) {
          if ((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) {
            *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c) = puVar4[1];
          }
          else {
            if ((int)puVar4[1] < 0) goto loc_F00280BC;
            *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c) = puVar4[1];
          }
        }
        else {
loc_F00280D4:
          *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
        }
      }
      else {
        if (iVar2 != 2) goto loc_F00280D4;
        (**(code **)(*(int *)(iVar3 + 0x1c) + 0x14))
                  (iVar3,(undefined *)((int)register0x00000038 + -0x50),_active_u[7]);
        *(char *)(dword_F0133DDC + 0x38) = (char)iVar3;
        if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F00280F4;
        if ((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) {
          iVar3 = puVar4[1];
        }
        else {
          if (puVar4[1] + *(int *)((int)register0x00000038 + -0x38) < 0) {
            *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
            goto locret_F00280F4;
          }
          iVar3 = puVar4[1];
        }
        *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c) =
             iVar3 + *(int *)((int)register0x00000038 + -0x38);
      }
      *(undefined4 *)(dword_F0133DDC + 0x30) =
           *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c);
      goto locret_F00280F4;
    }
  }
  else if (*(char *)(dword_F0133DDC + 0x38) != '\x16') goto locret_F00280F4;
  *(undefined *)(dword_F0133DDC + 0x38) = 0x1d;
locret_F00280F4:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=576 start=0xf00280fc */

/* WARNING: Removing unreachable block (ram,0xf0028188) */
/* WARNING: Removing unreachable block (ram,0xf00281e8) */
/* WARNING: Removing unreachable block (ram,0xf002811c) */

undefined8 _access(undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined uVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  uint uVar7;
  undefined4 unaff_l1;
  undefined4 *puVar8;
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
  puVar8 = *(undefined4 **)(dword_F0133DDC + 0x24);
  uVar3 = *puVar8;
  _lookupname(uVar3,0,1,0,(undefined *)((int)register0x00000038 + -0xc));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar3;
  if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F002820C;
  iVar5 = *(int *)(_active_u + 0x1c);
  uVar1 = *(undefined2 *)(iVar5 + 2);
  uVar2 = *(undefined2 *)(iVar5 + 4);
  *(undefined2 *)(iVar5 + 2) = *(undefined2 *)(iVar5 + 6);
  *(undefined2 *)(*(int *)(_active_u + 0x1c) + 4) = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 8);
  uVar6 = puVar8[1];
  if (uVar6 != 0) {
    uVar7 = (uVar6 & 4) << 6;
    if ((uVar6 & 2) == 0) {
loc_F00281A8:
      if ((puVar8[1] & 1) != 0) {
        uVar7 = uVar7 | 0x40;
      }
      iVar5 = *(int *)((int)register0x00000038 + -0xc);
      (**(code **)(*(int *)(iVar5 + 0x1c) + 0x1c))(iVar5,uVar7,*(undefined4 *)(_active_u + 0x1c));
      uVar4 = (undefined)iVar5;
    }
    else {
      iVar5 = *(int *)((int)register0x00000038 + -0xc);
      _isrofile();
      if (iVar5 == 0) {
        uVar7 = uVar7 | 0x80;
        goto loc_F00281A8;
      }
      uVar4 = 0x1e;
    }
    *(undefined *)(dword_F0133DDC + 0x38) = uVar4;
  }
  _vn_rele(*(undefined4 *)((int)register0x00000038 + -0xc));
  *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2) = uVar1;
  *(undefined2 *)(*(int *)(_active_u + 0x1c) + 4) = uVar2;
locret_F002820C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=577 start=0xf0028214 */

/* WARNING: Removing unreachable block (ram,0xf0028224) */

undefined8 _stat(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  uVar1 = *(undefined4 *)(dword_F0133DDC + 0x24);
  _stat1(uVar1,1);
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=578 start=0xf002823c */

/* WARNING: Removing unreachable block (ram,0xf002824c) */

undefined8 _lstat(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  uVar1 = *(undefined4 *)(dword_F0133DDC + 0x24);
  _stat1(uVar1,0);
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=579 start=0xf0028264 */

/* WARNING: Removing unreachable block (ram,0xf00282a0) */
/* WARNING: Removing unreachable block (ram,0xf0028294) */
/* WARNING: Removing unreachable block (ram,0xf00282b8) */
/* WARNING: Removing unreachable block (ram,0xf002827c) */

undefined8 _stat1(int *param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined *puVar2;
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
  puVar1 = (undefined *)*param_1;
  _lookupname(puVar1,0,param_2,0,(undefined *)((int)register0x00000038 + -0x4c));
  puVar2 = (undefined *)((int)register0x00000038 + -0x48);
  if (puVar1 == (undefined *)0x0) {
    puVar1 = *(undefined **)((int)register0x00000038 + -0x4c);
    _vno_stat(puVar1,puVar2);
    _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x4c));
    if (puVar1 == (undefined *)0x0) {
      puVar1 = puVar2;
      _copyout(puVar2,param_1[1],0x40);
    }
  }
  return CONCAT44(puVar2,puVar1);
}
/* GHIDRADEC_FUNCTION index=580 start=0xf00282cc */

/* WARNING: Removing unreachable block (ram,0xf002837c) */
/* WARNING: Removing unreachable block (ram,0xf00282ec) */

undefined8 _readlink(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 *puVar4;
  undefined4 unaff_l1;
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
  puVar4 = *(undefined4 **)(dword_F0133DDC + 0x24);
  uVar1 = *puVar4;
  _lookupname(uVar1,0,0,0,(undefined *)((int)register0x00000038 + -0x2c));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    iVar3 = *(int *)((int)register0x00000038 + -0x2c);
    if (*(int *)(iVar3 + 0x28) == 5) {
      *(undefined4 *)((int)register0x00000038 + -0x10) = puVar4[1];
      *(undefined4 *)((int)register0x00000038 + -0xc) = puVar4[2];
      *(undefined **)((int)register0x00000038 + -0x28) =
           (undefined *)((int)register0x00000038 + -0x10);
      *(undefined4 *)((int)register0x00000038 + -0x24) = 1;
      *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
      *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
      *(undefined4 *)((int)register0x00000038 + -0x14) = puVar4[2];
      (**(code **)(*(int *)(iVar3 + 0x1c) + 0x44))
                (iVar3,(undefined *)((int)register0x00000038 + -0x28),
                 *(undefined4 *)(_active_u + 0x1c));
      uVar2 = (undefined)iVar3;
    }
    else {
      uVar2 = 0x16;
    }
    *(undefined *)(dword_F0133DDC + 0x38) = uVar2;
    _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x2c));
    *(int *)(dword_F0133DDC + 0x30) = puVar4[2] - *(int *)((int)register0x00000038 + -0x14);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=581 start=0xf00283a4 */

/* WARNING: Removing unreachable block (ram,0xf00283d4) */
/* WARNING: Removing unreachable block (ram,0xf00283b8) */

undefined8 _chmod(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 *puVar2;
  undefined4 unaff_l1;
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
  puVar2 = *(undefined4 **)(dword_F0133DDC + 0x24);
  _vattr_null((undefined *)((int)register0x00000038 + -0x48));
  *(word *)((int)register0x00000038 + -0x44) = (word)puVar2[1] & 0xfff;
  uVar1 = *puVar2;
  _namesetattr(uVar1,1,(undefined *)((int)register0x00000038 + -0x48));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=582 start=0xf00283ec */

/* WARNING: Removing unreachable block (ram,0xf0028418) */
/* WARNING: Removing unreachable block (ram,0xf0028400) */

undefined8 _fchmod(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 *puVar2;
  undefined4 unaff_l1;
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
  puVar2 = *(undefined4 **)(dword_F0133DDC + 0x24);
  _vattr_null((undefined *)((int)register0x00000038 + -0x48));
  *(word *)((int)register0x00000038 + -0x44) = (word)puVar2[1] & 0xfff;
  uVar1 = *puVar2;
  _fdsetattr(uVar1,(undefined *)((int)register0x00000038 + -0x48));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=583 start=0xf0028430 */

/* WARNING: Removing unreachable block (ram,0xf0028464) */
/* WARNING: Removing unreachable block (ram,0xf0028444) */

undefined8 _chown(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 *puVar2;
  undefined4 unaff_l1;
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
  puVar2 = *(undefined4 **)(dword_F0133DDC + 0x24);
  _vattr_null((undefined *)((int)register0x00000038 + -0x48));
  *(sword *)((int)register0x00000038 + -0x42) = (sword)puVar2[1];
  *(sword *)((int)register0x00000038 + -0x40) = (sword)puVar2[2];
  uVar1 = *puVar2;
  _namesetattr(uVar1,0,(undefined *)((int)register0x00000038 + -0x48));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=584 start=0xf002847c */

/* WARNING: Removing unreachable block (ram,0xf00284ac) */
/* WARNING: Removing unreachable block (ram,0xf0028490) */

undefined8 _fchown(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 *puVar2;
  undefined4 unaff_l1;
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
  puVar2 = *(undefined4 **)(dword_F0133DDC + 0x24);
  _vattr_null((undefined *)((int)register0x00000038 + -0x48));
  *(sword *)((int)register0x00000038 + -0x42) = (sword)puVar2[1];
  *(sword *)((int)register0x00000038 + -0x40) = (sword)puVar2[2];
  uVar1 = *puVar2;
  _fdsetattr(uVar1,(undefined *)((int)register0x00000038 + -0x48));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=585 start=0xf00284c4 */

/* WARNING: Removing unreachable block (ram,0xf0028500) */
/* WARNING: Removing unreachable block (ram,0xf0028530) */
/* WARNING: Removing unreachable block (ram,0xf00284dc) */

undefined8 _utimes(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar2;
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
  puVar2 = *(undefined4 **)(dword_F0133DDC + 0x24);
  uVar1 = puVar2[1];
  _copyin(uVar1,(undefined *)((int)register0x00000038 + -0x18),0x10);
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    _vattr_null((undefined *)((int)register0x00000038 + -0x58));
    *(undefined4 *)((int)register0x00000038 + -0x38) =
         *(undefined4 *)((int)register0x00000038 + -0x18);
    *(undefined4 *)((int)register0x00000038 + -0x34) =
         *(undefined4 *)((int)register0x00000038 + -0x14);
    *(undefined4 *)((int)register0x00000038 + -0x30) =
         *(undefined4 *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0x2c) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    uVar1 = *puVar2;
    _namesetattr(uVar1,1,(undefined *)((int)register0x00000038 + -0x58));
    *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=586 start=0xf0028548 */

/* WARNING: Removing unreachable block (ram,0xf00285d8) */
/* WARNING: Removing unreachable block (ram,0xf0028570) */
/* WARNING: Removing unreachable block (ram,0xf0028578) */
/* WARNING: Removing unreachable block (ram,0xf0028620) */
/* WARNING: Removing unreachable block (ram,0xf0028564) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf00285d8 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

int __utime(void)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_o0;
  undefined8 in_o0_1;
  undefined8 uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar4;
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
  undefined auStackX_0 [92];
  
  iVar1 = (int)((qword)in_o0_1 >> 0x20);
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
  puVar4 = *(undefined4 **)(dword_F0133DDC + 0x24);
  _get_posix_proc((int)*(sword *)(*_active_u + 0x30));
  _getthetime((undefined *)((int)register0x00000038 + -0x58));
  _vattr_null((undefined *)((int)register0x00000038 + -0x50));
  if (((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) || (puVar4[1] != 0)) {
    _copyin(iVar1,(int)in_o0_1,8);
    *(char *)(dword_F0133DDC + 0x38) = (char)((qword)in_o0_1 >> 0x20);
    if (*(char *)(dword_F0133DDC + 0x38) != '\0') {
      return iVar1;
    }
    *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
    *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
    *(undefined4 *)((int)register0x00000038 + -0x30) =
         *(undefined4 *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0x28) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  else {
    in_o0_1 = *(undefined8 *)((int)register0x00000038 + -0x58);
    uVar2 = (undefined4)((qword)in_o0_1 >> 0x20);
    *(undefined4 *)((int)register0x00000038 + -0x28) = uVar2;
    *(undefined4 *)((int)register0x00000038 + -0x30) = uVar2;
    *(int *)((int)register0x00000038 + -0x24) = (int)in_o0_1;
    *(int *)((int)register0x00000038 + -0x2c) = (int)in_o0_1;
    *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) | 0x80000000;
  }
  _namesetattr(*puVar4,(int)in_o0_1,(undefined *)((int)register0x00000038 + -0x50));
  extraout_o0 = (int)((qword)in_o0_1 >> 0x20);
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & 0x7fffffff;
  uVar3 = CONCAT44(extraout_o0,extraout_o0);
  if (((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) ||
     ((uVar3 = CONCAT44(extraout_o0,extraout_o0), extraout_o0 == 1 &&
      (uVar3 = 0xd00000001, puVar4[1] != 0)))) {
    uVar3 = CONCAT44((int)uVar3,(int)uVar3);
  }
  *(char *)(dword_F0133DDC + 0x38) = (char)((qword)uVar3 >> 0x20);
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=587 start=0xf002868c */

/* WARNING: Removing unreachable block (ram,0xf00286cc) */
/* WARNING: Removing unreachable block (ram,0xf00286b4) */

undefined8 _truncate(undefined4 param_1,undefined4 param_2)

{
  undefined uVar2;
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar3;
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
  puVar3 = *(undefined4 **)(dword_F0133DDC + 0x24);
  if ((int)puVar3[1] < 0) {
    uVar2 = 0x16;
  }
  else {
    _vattr_null((undefined *)((int)register0x00000038 + -0x48));
    *(undefined4 *)((int)register0x00000038 + -0x30) = puVar3[1];
    uVar1 = *puVar3;
    _namesetattr(uVar1,1,(undefined *)((int)register0x00000038 + -0x48));
    uVar2 = (undefined)uVar1;
  }
  *(undefined *)(dword_F0133DDC + 0x38) = uVar2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=588 start=0xf00286e4 */

/* WARNING: Removing unreachable block (ram,0xf002876c) */
/* WARNING: Removing unreachable block (ram,0xf002870c) */

undefined8 _ftruncate(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
  undefined4 *puVar4;
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
  puVar4 = *(undefined4 **)(dword_F0133DDC + 0x24);
  if ((int)puVar4[1] < 0) {
    uVar2 = 0x16;
  }
  else {
    uVar1 = *puVar4;
    _getvnodefp(uVar1,(undefined *)((int)register0x00000038 + -0xc));
    *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
    if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F00287A0;
    iVar3 = *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x18);
    if ((*(uint *)(*(int *)((int)register0x00000038 + -0xc) + 8) & 2) == 0) {
      *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
      goto locret_F00287A0;
    }
    if ((*(uint *)(*(int *)(iVar3 + 0x24) + 0xc) & 1) != 0) {
      *(undefined *)(dword_F0133DDC + 0x38) = 0x1e;
      goto locret_F00287A0;
    }
    _vattr_null((undefined *)((int)register0x00000038 + -0x50));
    *(undefined4 *)((int)register0x00000038 + -0x38) = puVar4[1];
    (**(code **)(*(int *)(iVar3 + 0x1c) + 0x18))
              (iVar3,(undefined *)((int)register0x00000038 + -0x50),
               *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x20));
    uVar2 = (undefined)iVar3;
  }
  *(undefined *)(dword_F0133DDC + 0x38) = uVar2;
locret_F00287A0:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=589 start=0xf00287a8 */

/* WARNING: Removing unreachable block (ram,0xf0028808) */
/* WARNING: Removing unreachable block (ram,0xf00287bc) */

undefined8 _namesetattr(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  _lookupname(param_1,0,param_2,0,(undefined *)((int)register0x00000038 + -0xc));
  iVar1 = *(int *)((int)register0x00000038 + -0xc);
  if (param_1 == 0) {
    param_1 = 0x1e;
    if ((*(uint *)(*(int *)(iVar1 + 0x24) + 0xc) & 1) == 0) {
      (**(code **)(*(int *)(iVar1 + 0x1c) + 0x18))(iVar1,param_3,*(undefined4 *)(_active_u + 0x1c));
      param_1 = iVar1;
    }
    _vn_rele(*(undefined4 *)((int)register0x00000038 + -0xc));
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=590 start=0xf0028818 */

/* WARNING: Removing unreachable block (ram,0xf0028820) */

undefined8 _fdsetattr(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  _getvnodefp(param_1,(undefined *)((int)register0x00000038 + -0xc));
  if (param_1 == 0) {
    iVar1 = *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x18);
    param_1 = 0x1e;
    if ((*(uint *)(*(int *)(iVar1 + 0x24) + 0xc) & 1) == 0) {
      (**(code **)(*(int *)(iVar1 + 0x1c) + 0x18))
                (iVar1,param_2,*(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x20));
      param_1 = iVar1;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=591 start=0xf0028874 */

/* WARNING: Removing unreachable block (ram,0xf002889c) */
/* WARNING: Removing unreachable block (ram,0xf0028888) */

undefined8 _fsync(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool bVar3;
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
  iVar1 = **(int **)(dword_F0133DDC + 0x24);
  _getvnodefp(iVar1,(undefined *)((int)register0x00000038 + -0xc));
  bVar3 = false;
  if (iVar1 == 0) {
    iVar1 = *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x18);
    _mfs_fsync();
    bVar3 = iVar1 == 0;
  }
  uVar2 = (undefined)iVar1;
  if (bVar3) {
    iVar1 = *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x18);
    (**(code **)(*(int *)(iVar1 + 0x1c) + 0x48))
              (iVar1,*(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x20));
    uVar2 = (undefined)iVar1;
  }
  *(undefined *)(dword_F0133DDC + 0x38) = uVar2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=592 start=0xf00288e0 */

undefined8 _umask(void)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar1;
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
  puVar1 = *(undefined4 **)(dword_F0133DDC + 0x24);
  *(int *)(dword_F0133DDC + 0x30) = (int)*(sword *)(_active_u + 0x16a);
  *(word *)(_active_u + 0x16a) = (word)*puVar1 & 0xfff;
  return CONCAT44(&dword_F0133DDC,puVar1);
}
/* GHIDRADEC_FUNCTION index=593 start=0xf0028918 */

/* WARNING: Removing unreachable block (ram,0xf002895c) */
/* WARNING: Removing unreachable block (ram,0xf0028944) */
/* WARNING: Removing unreachable block (ram,0xf0028968) */
/* WARNING: Removing unreachable block (ram,0xf002891c) */

undefined8 _vhangup(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  iVar1 = param_1;
  _suser();
  if ((iVar1 != 0) && (*(int *)(_active_u + 0x164) != 0)) {
    _forceclose((int)*(sword *)(_active_u + 0x168));
    _memcpy((undefined *)((int)register0x00000038 + -0x90),*(undefined4 *)(_active_u + 0x164),0x88);
    _gsignal((undefined *)((int)register0x00000038 + -0x90),1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=594 start=0xf0028978 */

undefined8 _forceclose(int param_1)

{
  sword sVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 *puVar3;
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
  puVar3 = _file_list;
  if ((undefined4 **)_file_list != &_file_list) {
    param_1 = (int)(sword)param_1;
    sVar1 = *(sword *)((int)_file_list + 0xe);
    while( true ) {
      if (sVar1 == 0) {
        puVar3 = (undefined4 *)*puVar3;
      }
      else if (*(sword *)(puVar3 + 3) == 1) {
        iVar2 = puVar3[6];
        if (iVar2 == 0) {
          puVar3 = (undefined4 *)*puVar3;
        }
        else if ((*(int *)(iVar2 + 0x28) == 4) || (*(int *)(iVar2 + 0x28) == 9)) {
          if (*(sword *)(iVar2 + 0x2c) == param_1) {
            puVar3[2] = puVar3[2] & 0xfffffffc;
            puVar3 = (undefined4 *)*puVar3;
          }
          else {
            puVar3 = (undefined4 *)*puVar3;
          }
        }
        else {
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        puVar3 = (undefined4 *)*puVar3;
      }
      if ((undefined4 **)puVar3 == &_file_list) break;
      sVar1 = *(sword *)((int)puVar3 + 0xe);
    }
  }
  return CONCAT44(puVar3,param_1);
}
/* GHIDRADEC_FUNCTION index=595 start=0xf0028a18 */

/* WARNING: Removing unreachable block (ram,0xf0028a1c) */

undefined8 _getvnodefp(int param_1,int *param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  _getf();
  if (param_1 == 0) {
    uVar1 = 9;
  }
  else {
    uVar1 = 0x16;
    if (*(sword *)(param_1 + 0xc) == 1) {
      *param_2 = param_1;
      uVar1 = 0;
    }
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=596 start=0xf0028a54 */

/* WARNING: Removing unreachable block (ram,0xf0028af0) */
/* WARNING: Removing unreachable block (ram,0xf0028afc) */
/* WARNING: Removing unreachable block (ram,0xf0028ad4) */

undefined8
_vn_rdwr(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
        undefined4 param_6)

{
  undefined4 unaff_l0;
  undefined4 uVar1;
  undefined4 unaff_l1;
  int *piVar2;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
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
  uVar1 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  piVar2 = *(int **)((int)register0x00000038 + 0x60);
  if (param_1 == 1) {
    if ((*(uint *)(*(int *)(param_2 + 0x24) + 0xc) & 1) != 0) {
      iVar3 = 0x1e;
      goto locret_F0028B5C;
    }
    *(undefined4 *)((int)register0x00000038 + -0x28) = param_3;
  }
  else {
    *(undefined4 *)((int)register0x00000038 + -0x28) = param_3;
  }
  *(undefined4 *)((int)register0x00000038 + -0x24) = param_4;
  *(undefined **)((int)register0x00000038 + -0x20) = (undefined *)((int)register0x00000038 + -0x28);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 1;
  *(qword *)((int)register0x00000038 + -0x18) = CONCAT44(param_5,param_6);
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_4;
  iVar3 = param_2;
  if ((*(int *)(param_2 + 0x28) == 1) && ((*(uint *)(*_active_u + 0x14) & 0x4000) == 0)) {
    _map_vnode(param_2);
    _mfs_io(param_2,(undefined *)((int)register0x00000038 + -0x20),param_1,uVar1,_active_u[7]);
    _unmap_vnode(param_2);
  }
  else {
    (**(code **)(*(int *)(param_2 + 0x1c) + 8))
              (param_2,(undefined *)((int)register0x00000038 + -0x20),param_1,uVar1,_active_u[7]);
  }
  if (piVar2 == (int *)0x0) {
    if ((*(int *)((int)register0x00000038 + -0xc) != 0) && (iVar3 == 0)) {
      iVar3 = 5;
    }
  }
  else {
    *piVar2 = *(int *)((int)register0x00000038 + -0xc);
  }
locret_F0028B5C:
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=597 start=0xf0028b64 */

/* WARNING: Removing unreachable block (ram,0xf0028b7c) */

undefined8 _vn_rele(int param_1,undefined4 param_2)

{
  sword sVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  if (*(sword *)(param_1 + 6) == 0) {
    _panic(&aVnRele);
    sVar1 = *(sword *)(param_1 + 6);
  }
  else {
    sVar1 = *(sword *)(param_1 + 6);
  }
  *(sword *)(param_1 + 6) = sVar1 + -1;
  if ((sword)(sVar1 + -1) == 0) {
    (**(code **)(*(int *)(param_1 + 0x1c) + 0x4c))(param_1,*(undefined4 *)(_active_u + 0x1c));
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=598 start=0xf0028bc0 */

/* WARNING: Removing unreachable block (ram,0xf0028dc8) */
/* WARNING: Removing unreachable block (ram,0xf0028c28) */
/* WARNING: Removing unreachable block (ram,0xf0028cb0) */
/* WARNING: Removing unreachable block (ram,0xf0028be8) */
/* WARNING: Removing unreachable block (ram,0xf0028d6c) */
/* WARNING: Removing unreachable block (ram,0xf0028ddc) */
/* WARNING: Removing unreachable block (ram,0xf0028c4c) */

undefined8
_vn_open(undefined *param_1,undefined4 param_2,uint param_3,undefined2 param_4,undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar4;
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
  bool bVar5;
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
  uVar4 = (param_3 & 1) << 8;
  if ((param_3 & 0x402) != 0) {
    uVar4 = uVar4 | 0x80;
  }
  if ((param_3 & 0x200) == 0) {
    _lookupname(param_1,param_2,1,0,(undefined *)((int)register0x00000038 + -0x4c));
    if (param_1 != (undefined *)0x0) goto locret_F0028DEC;
    if ((param_3 & 0x402) == 0) goto loc_F0028CD0;
    iVar2 = *(int *)(*(int *)((int)register0x00000038 + -0x4c) + 0x28);
    if (iVar2 == 2) {
      param_1 = (undefined *)0x15;
    }
    else if (((*(uint *)(*(int *)(*(int *)((int)register0x00000038 + -0x4c) + 0x24) + 0xc) & 1) == 0
             ) || (param_1 = (undefined *)0x1e, iVar2 - 3U < 2)) {
      if ((*(word *)(*(int *)((int)register0x00000038 + -0x4c) + 4) & 2) != 0) {
        _vnode_uncache(*(int *)((int)register0x00000038 + -0x4c));
        param_1 = (undefined *)0x1a;
        if ((*(word *)(*(int *)((int)register0x00000038 + -0x4c) + 4) & 2) != 0) goto loc_F0028DD0;
      }
loc_F0028CD0:
      param_1 = *(undefined **)((int)register0x00000038 + -0x4c);
      (**(code **)(*(int *)(param_1 + 0x1c) + 0x1c))
                (param_1,uVar4,*(undefined4 *)(_active_u + 0x1c));
      bVar5 = param_1 == (undefined *)0x0;
      iVar2 = *(int *)((int)register0x00000038 + -0x4c);
      if (!bVar5) goto loc_F0028DD4;
      iVar1 = *(int *)(iVar2 + 0x28);
      if ((*(uint *)(*(int *)(iVar2 + 0x24) + 0xc) & 8) == 0) goto loc_F0028D20;
      param_1 = (undefined *)0x1;
      if (1 < iVar1 - 3U) goto loc_F0028D1C;
    }
loc_F0028DD0:
    bVar5 = param_1 == (undefined *)0x0;
  }
  else {
    _vattr_null((undefined *)((int)register0x00000038 + -0x48));
    *(undefined4 *)((int)register0x00000038 + -0x48) = 1;
    *(undefined2 *)((int)register0x00000038 + -0x44) = param_4;
    if ((param_3 & 0x400) != 0) {
      *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
    }
    uVar3 = param_3 & 0x800;
    param_3 = param_3 & 0xfffff1ff;
    _vn_create(param_1,param_2,(undefined *)((int)register0x00000038 + -0x48),uVar3 != 0,uVar4,
               (undefined *)((int)register0x00000038 + -0x4c));
    iVar2 = *(int *)((int)register0x00000038 + -0x4c);
    if (param_1 != (undefined *)0x0) goto locret_F0028DEC;
loc_F0028D1C:
    iVar1 = *(int *)(iVar2 + 0x28);
loc_F0028D20:
    if (iVar1 == 6) {
      param_1 = (undefined *)0x2d;
      goto loc_F0028DD0;
    }
    param_1 = (undefined *)((int)register0x00000038 + -0x4c);
    (*(code *)**(undefined4 **)(iVar2 + 0x1c))(param_1,param_3,*(undefined4 *)(_active_u + 0x1c));
    bVar5 = false;
    if (param_1 == (undefined *)0x0) {
      if ((param_3 & 0x400) != 0) {
        _vattr_null((undefined *)((int)register0x00000038 + -0x90));
        *(undefined4 *)((int)register0x00000038 + -0x78) = 0;
        param_1 = *(undefined **)((int)register0x00000038 + -0x4c);
        param_3 = param_3 & 0xfffffbff;
        (**(code **)(*(int *)(param_1 + 0x1c) + 0x18))
                  (param_1,(undefined *)((int)register0x00000038 + -0x90),
                   *(undefined4 *)(_active_u + 0x1c));
      }
      bVar5 = param_1 == (undefined *)0x0;
      if ((param_1 == (undefined *)0x0) && (bVar5 = true, (param_3 & 0x40000000) == 0)) {
        bVar5 = true;
        if (*(int *)(*(int *)((int)register0x00000038 + -0x4c) + 0x28) == 1) {
          _map_vnode(*(int *)((int)register0x00000038 + -0x4c));
          goto loc_F0028DD0;
        }
      }
    }
  }
loc_F0028DD4:
  if (bVar5) {
    *param_5 = *(undefined4 *)((int)register0x00000038 + -0x4c);
  }
  else {
    _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x4c));
  }
locret_F0028DEC:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=599 start=0xf0028df4 */

/* WARNING: Removing unreachable block (ram,0xf0028fdc) */
/* WARNING: Removing unreachable block (ram,0xf0028edc) */
/* WARNING: Removing unreachable block (ram,0xf0028f20) */
/* WARNING: Removing unreachable block (ram,0xf0028e58) */
/* WARNING: Removing unreachable block (ram,0xf0028e6c) */
/* WARNING: Removing unreachable block (ram,0xf0028f3c) */
/* WARNING: Removing unreachable block (ram,0xf0028f70) */
/* WARNING: Removing unreachable block (ram,0xf0028fe4) */
/* WARNING: Removing unreachable block (ram,0xf0028e0c) */

undefined8
_vn_create(undefined *param_1,undefined4 param_2,int *param_3,int param_4,uint param_5,int *param_6)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  *param_6 = 0;
  _pn_get(param_1,param_2,(undefined *)((int)register0x00000038 + -0x18));
  if (param_1 != (undefined *)0x0) goto locret_F0028FEC;
  if ((param_4 == 1) && (*param_3 != 2)) {
    uVar2 = 0;
    piVar3 = (int *)0x0;
  }
  else {
    uVar2 = 1;
    piVar3 = param_6;
  }
  param_1 = (undefined *)((int)register0x00000038 + -0x18);
  _lookuppn(param_1,uVar2,(undefined *)((int)register0x00000038 + -0x1c),piVar3);
  if (param_1 != (undefined *)0x0) {
    _pn_free((undefined *)((int)register0x00000038 + -0x18));
    goto locret_F0028FEC;
  }
  if (*param_6 == 0) {
    iVar1 = *(int *)((int)register0x00000038 + -0x1c);
  }
  else {
    iVar1 = *(int *)((int)register0x00000038 + -0x1c);
    if (*(int *)(*param_6 + 0x28) == 6) {
      param_1 = (undefined *)0x2d;
      goto locret_F0028FEC;
    }
  }
  if ((*(uint *)(*(int *)(iVar1 + 0x24) + 0xc) & 1) == 0) {
loc_F0028EF0:
    if (param_4 == 0) {
      iVar1 = *param_6;
      if (iVar1 != 0) {
        if ((((param_5 & 0x80) != 0) && ((*(word *)(iVar1 + 4) & 2) != 0)) &&
           (_vnode_uncache(iVar1), (*(word *)(*param_6 + 4) & 2) != 0)) {
          param_1 = (undefined *)0x1a;
        }
        _vn_rele(*param_6);
      }
    }
  }
  else {
    iVar1 = *param_6;
    if (iVar1 == 0) {
      param_1 = (undefined *)0x1e;
    }
    else {
      if (*(int *)(iVar1 + 0x28) - 3U < 2) goto loc_F0028EF0;
      param_1 = (undefined *)0x1e;
      if (iVar1 != 0) {
        _vn_rele(iVar1);
        param_1 = (undefined *)0x1e;
      }
    }
  }
  if (param_1 == (undefined *)0x0) {
    param_1 = *(undefined **)((int)register0x00000038 + -0x1c);
    if (*param_3 == 2) {
      if (*param_6 == 0) {
        param_1 = *(undefined **)((int)register0x00000038 + -0x1c);
        (**(code **)(*(int *)(param_1 + 0x1c) + 0x34))
                  (param_1,*(undefined4 *)((int)register0x00000038 + -0x14),param_3,param_6,
                   *(undefined4 *)(_active_u + 0x1c));
      }
      else {
        param_1 = (undefined *)0x11;
        _vn_rele();
      }
    }
    else {
      (**(code **)(*(int *)(param_1 + 0x1c) + 0x24))
                (param_1,*(undefined4 *)((int)register0x00000038 + -0x14),param_3,param_4,param_5,
                 param_6,*(undefined4 *)(_active_u + 0x1c));
    }
  }
  _pn_free((undefined *)((int)register0x00000038 + -0x18));
  _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x1c));
locret_F0028FEC:
  return CONCAT44((undefined *)((int)register0x00000038 + -0x18),param_1);
}

