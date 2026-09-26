
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
