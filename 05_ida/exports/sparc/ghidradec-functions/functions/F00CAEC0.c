
/* WARNING: Removing unreachable block (ram,0xf00caf70) */
/* WARNING: Removing unreachable block (ram,0xf00caf04) */

undefined8
_IOAddToCdevsw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6)

{
  undefined *puVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
  undefined4 unaff_l1;
  int iVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 uVar4;
  undefined4 unaff_l5;
  undefined4 uVar5;
  undefined4 unaff_l6;
  undefined4 uVar6;
  undefined4 unaff_l7;
  undefined4 uVar7;
  undefined4 unaff_i0;
  int iVar8;
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
  uVar7 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  uVar6 = *(undefined4 *)((int)register0x00000038 + 100);
  puVar2 = _cdevsw;
  uVar5 = *(undefined4 *)((int)register0x00000038 + 0x68);
  iVar8 = 0;
  uVar4 = *(undefined4 *)((int)register0x00000038 + 0x6c);
  if (0 < _nchrdev) {
    do {
      puVar1 = puVar2;
      _memcmp(puVar2,&off_F012EC70,0x2c);
      if (puVar1 == (undefined *)0x0) break;
      iVar8 = iVar8 + 1;
      puVar2 = puVar2 + 0x2c;
    } while (iVar8 < _nchrdev);
  }
  iVar3 = iVar8 * 0x2c;
  puVar2 = _cdevsw + iVar3;
  if (-1 < iVar8) {
    if (_nchrdev <= iVar8) {
      iVar8 = -1;
      goto locret_F00CAFB8;
    }
    _memcmp(puVar2,&off_F012EC70,0x2c);
    if (puVar2 == (undefined *)0x0) {
      *(undefined4 *)(_cdevsw + iVar3) = param_1;
      *(undefined4 *)(_cdevsw + iVar3 + 4) = param_2;
      *(undefined4 *)(_cdevsw + iVar3 + 8) = param_3;
      *(undefined4 *)(_cdevsw + iVar3 + 0xc) = param_4;
      *(undefined4 *)(_cdevsw + iVar3 + 0x10) = param_5;
      *(undefined4 *)(_cdevsw + iVar3 + 0x14) = param_6;
      *(undefined4 *)(_cdevsw + iVar3 + 0x18) = uVar7;
      uVar7 = *(undefined4 *)((int)register0x00000038 + 0x60);
      *(undefined4 *)(_cdevsw + iVar3 + 0x20) = uVar6;
      *(undefined4 *)(_cdevsw + iVar3 + 0x24) = uVar5;
      *(undefined4 *)(_cdevsw + iVar3 + 0x28) = uVar4;
      *(undefined4 *)(_cdevsw + iVar3 + 0x1c) = uVar7;
      goto locret_F00CAFB8;
    }
  }
  iVar8 = -1;
locret_F00CAFB8:
  return CONCAT44(param_2,iVar8);
}
