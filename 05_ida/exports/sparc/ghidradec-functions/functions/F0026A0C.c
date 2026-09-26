
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
