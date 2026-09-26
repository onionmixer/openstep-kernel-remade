
/* WARNING: Removing unreachable block (ram,0xf00af1c0) */
/* WARNING: Removing unreachable block (ram,0xf00af188) */
/* WARNING: Removing unreachable block (ram,0xf00af150) */
/* WARNING: Removing unreachable block (ram,0xf00af1a8) */
/* WARNING: Removing unreachable block (ram,0xf00af170) */
/* WARNING: Removing unreachable block (ram,0xf00af128) */

undefined8 _prom_getidprom(char *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
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
  if (dword_F0131564 == 0) {
    uVar1 = 0;
    _prom_nextnode();
    if (uVar1 == 0xffffffff) {
      puVar3 = aPromGetidpromC;
    }
    else {
      uVar2 = uVar1;
      _prom_getproplen(uVar1,&aIdprom);
      if (uVar2 != 0xffffffff) {
        if (0x20 < uVar2) {
          _prom_printf(aPromGetidpromP,uVar2);
          iVar4 = 0;
          goto locret_F00AF1CC;
        }
        _prom_getprop(uVar1,&aIdprom_0,unk_F0131568);
        dword_F0131564 = uVar2;
        goto loc_F00AF1B8;
      }
      puVar3 = aMissingIdpromP;
    }
    iVar4 = 0;
    _prom_printf(puVar3);
  }
  else {
loc_F00AF1B8:
    _bcopy(unk_F0131568,param_1,param_2);
    iVar4 = (int)*param_1;
  }
locret_F00AF1CC:
  return CONCAT44(param_2,iVar4);
}

