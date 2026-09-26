
/* WARNING: Removing unreachable block (ram,0xf00cae70) */
/* WARNING: Removing unreachable block (ram,0xf00cae04) */

undefined8
_IOAddToCdevswAt(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  undefined *puVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 uVar4;
  undefined8 in_l4_5;
  undefined8 uVar5;
  undefined4 unaff_l6;
  undefined4 uVar6;
  undefined4 unaff_l7;
  undefined4 uVar7;
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
    *(int *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)in_l4_5 >> 0x20);
    *(int *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = (int)in_l4_5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  uVar4 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  uVar5 = *(undefined8 *)((int)register0x00000038 + 0x60);
  uVar6 = *(undefined4 *)((int)register0x00000038 + 0x68);
  uVar7 = *(undefined4 *)((int)register0x00000038 + 0x6c);
  if (param_1 == -1) {
    puVar3 = _cdevsw;
    param_1 = 0;
    iVar1 = 0;
    if (0 < _nchrdev) {
      do {
        puVar2 = puVar3;
        _memcmp(puVar3,&off_F012EC70,0x2c);
        if (puVar2 == (undefined *)0x0) break;
        param_1 = param_1 + 1;
        puVar3 = puVar3 + 0x2c;
      } while (param_1 < _nchrdev);
      goto loc_F00CAE28;
    }
  }
  else {
loc_F00CAE28:
    iVar1 = param_1 << 1;
  }
  iVar1 = (iVar1 * 4 + param_1 * 3) * 4;
  puVar3 = _cdevsw + iVar1;
  if (-1 < param_1) {
    if (_nchrdev <= param_1) {
      param_1 = -1;
      goto locret_F00CAEB8;
    }
    _memcmp(puVar3,&off_F012EC70,0x2c);
    if (puVar3 == (undefined *)0x0) {
      *(undefined4 *)(_cdevsw + iVar1) = param_2;
      *(undefined4 *)(_cdevsw + iVar1 + 4) = param_3;
      *(undefined4 *)(_cdevsw + iVar1 + 8) = param_4;
      *(undefined4 *)(_cdevsw + iVar1 + 0xc) = param_5;
      *(undefined4 *)(_cdevsw + iVar1 + 0x10) = param_6;
      *(undefined4 *)(_cdevsw + iVar1 + 0x14) = uVar4;
      *(int *)(_cdevsw + iVar1 + 0x18) = (int)((qword)uVar5 >> 0x20);
      *(int *)(_cdevsw + iVar1 + 0x1c) = (int)uVar5;
      *(undefined4 *)(_cdevsw + iVar1 + 0x20) = uVar6;
      *(undefined4 *)(_cdevsw + iVar1 + 0x24) = uVar7;
      *(undefined4 *)(_cdevsw + iVar1 + 0x28) = *(undefined4 *)((int)register0x00000038 + 0x70);
      goto locret_F00CAEB8;
    }
  }
  param_1 = -1;
locret_F00CAEB8:
  return CONCAT44(param_2,param_1);
}

