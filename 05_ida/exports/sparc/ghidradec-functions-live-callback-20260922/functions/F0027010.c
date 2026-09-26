
/* WARNING: Removing unreachable block (ram,0xf0027274) */
/* WARNING: Removing unreachable block (ram,0xf0027234) */
/* WARNING: Removing unreachable block (ram,0xf002719c) */
/* WARNING: Removing unreachable block (ram,0xf002717c) */
/* WARNING: Removing unreachable block (ram,0xf00270ec) */
/* WARNING: Removing unreachable block (ram,0xf0027054) */
/* WARNING: Removing unreachable block (ram,0xf0027028) */
/* WARNING: Removing unreachable block (ram,0xf00270d0) */
/* WARNING: Removing unreachable block (ram,0xf0027130) */
/* WARNING: Removing unreachable block (ram,0xf0027190) */
/* WARNING: Removing unreachable block (ram,0xf00271d0) */
/* WARNING: Removing unreachable block (ram,0xf0027268) */
/* WARNING: Removing unreachable block (ram,0xf0027288) */
/* WARNING: Removing unreachable block (ram,0xf002701c) */

undefined8 sub_F0027010(int *param_1,char *param_2,undefined4 param_3,int *param_4)

{
  char *pcVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
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
  _pn_alloc(param_4);
  pcVar1 = param_2;
  _dnlc_lookupSymLink(param_2,param_3);
  if (pcVar1 != (char *)0x0) {
    if (pcVar1[0x44] == '\0') {
      iVar2 = *param_4;
      goto loc_F0027068;
    }
    _bcopy(*(undefined4 *)(pcVar1 + 0x40),*param_4,(int)*(sword *)(pcVar1 + 0x46));
    param_4[2] = (int)*(sword *)(pcVar1 + 0x46);
    param_1 = (int *)0x0;
loc_F00270D8:
    *(undefined *)(*param_4 + param_4[2]) = 0;
    iVar2 = *param_4;
    while( true ) {
      _index(iVar2,0x24);
      bVar5 = param_1 == (int *)0x0;
      if (iVar2 == 0) break;
      if ((iVar2 == *param_4) || (*(char *)(iVar2 + -1) == '/')) {
        bVar5 = param_1 == (int *)0x0;
        if (iVar2 != 0) {
          _pn_alloc((undefined *)((int)register0x00000038 + -0x38));
          bVar5 = param_1 == (int *)0x0;
          if (param_4[2] == 0) goto loc_F0027260;
          param_2 = (char *)((int)register0x00000038 + -0x138);
          goto loc_F0027150;
        }
        break;
      }
      iVar2 = iVar2 + 1;
    }
    goto loc_F0027280;
  }
  iVar2 = *param_4;
loc_F0027068:
  *(int *)((int)register0x00000038 + -0x10) = iVar2;
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0x400;
  *(undefined **)((int)register0x00000038 + -0x28) = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0x24) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0x400;
  (**(code **)(param_1[7] + 0x44))
            (param_1,(undefined *)((int)register0x00000038 + -0x28),
             *(undefined4 *)(_active_u + 0x1c));
  param_4[2] = 0x400 - *(int *)((int)register0x00000038 + -0x14);
  if (param_1 == (int *)0x0) {
    _dnlc_enterSymLink(param_2,param_3,param_4);
    goto loc_F00270D8;
  }
  goto loc_F0027288;
loc_F0027150:
  do {
    if ((param_4[2] != 0) && (*(char *)param_4[1] == '/')) {
      param_1 = (int *)((int)register0x00000038 + -0x38);
      _pn_append(param_1,&unk_F010C140);
      if (param_1 != (int *)0x0) goto loc_F0027274;
      _pn_skipslash(param_4,*(undefined4 *)((int)register0x00000038 + -0x38));
    }
    param_1 = param_4;
    _pn_getcomponent(param_4,param_2);
    bVar5 = param_1 == (int *)0x0;
    if (!bVar5) goto loc_F0027260;
    pcVar1 = param_2;
    if (*(char *)((int)register0x00000038 + -0x138) != '$') goto loc_F0027234;
    puVar4 = _metalinks;
    iVar2 = _metalinks._0_4_;
    if (_metalinks._0_4_ == 0) {
loc_F00271F8:
      iVar2 = *(int *)puVar4;
    }
    else {
      while( true ) {
        puVar3 = (undefined *)((int)register0x00000038 + -0x137);
        _strcmp(puVar3,iVar2);
        if (puVar3 == (undefined *)0x0) break;
        puVar4 = (undefined *)((int)puVar4 + 0xc);
        if (*(int *)puVar4 == 0) goto loc_F00271F8;
        iVar2 = *(int *)puVar4;
      }
      iVar2 = *(int *)puVar4;
    }
    if (iVar2 == 0) {
      param_1 = (int *)0x2;
      break;
    }
    pcVar1 = *(char **)((int)puVar4 + 4);
    if (**(char **)((int)puVar4 + 4) == '\0') {
      param_1 = (int *)0x2;
      pcVar1 = *(char **)((int)puVar4 + 8);
      if (*(char **)((int)puVar4 + 8) != (char *)0x0) goto loc_F0027234;
    }
    else {
loc_F0027234:
      param_1 = (int *)((int)register0x00000038 + -0x38);
      _pn_append(param_1,pcVar1);
    }
    if (param_1 != (int *)0x0) goto loc_F0027274;
  } while (param_4[2] != 0);
  bVar5 = param_1 == (int *)0x0;
loc_F0027260:
  if (bVar5) {
    param_1 = param_4;
    _pn_set(param_4,*(undefined4 *)((int)register0x00000038 + -0x38));
  }
loc_F0027274:
  _pn_free((undefined *)((int)register0x00000038 + -0x38));
  bVar5 = param_1 == (int *)0x0;
loc_F0027280:
  if (bVar5) goto locret_F0027290;
loc_F0027288:
  _pn_free(param_4);
locret_F0027290:
  return CONCAT44(param_2,param_1);
}

