
/* WARNING: Removing unreachable block (ram,0xf001d380) */
/* WARNING: Removing unreachable block (ram,0xf001d388) */
/* WARNING: Removing unreachable block (ram,0xf001d378) */

undefined8 _domaininit(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  uint uVar2;
  code *pcVar3;
  undefined4 unaff_l0;
  uint uVar4;
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
  puVar1 = _inetdomain;
  DAT_f010c70c._0_4_ = _unixdomain;
  DAT_f010bbd4._0_4_ = _domains;
  _domains = _inetdomain;
  pcVar3 = (code *)DAT_f010c6f8._0_4_;
  while( true ) {
    if (pcVar3 == (code *)0x0) {
      uVar4 = *(uint *)(puVar1 + 0x14);
    }
    else {
      (*pcVar3)();
      uVar4 = *(uint *)(puVar1 + 0x14);
    }
    if (uVar4 < *(uint *)(puVar1 + 0x18)) {
      pcVar3 = *(code **)(uVar4 + 0x20);
      while( true ) {
        if (pcVar3 == (code *)0x0) {
          uVar2 = *(uint *)(puVar1 + 0x18);
        }
        else {
          (*pcVar3)();
          uVar2 = *(uint *)(puVar1 + 0x18);
        }
        if (uVar2 <= uVar4 + 0x30) break;
        pcVar3 = *(code **)(uVar4 + 0x50);
        uVar4 = uVar4 + 0x30;
      }
      puVar1 = *(undefined **)(puVar1 + 0x1c);
    }
    else {
      puVar1 = *(undefined **)(puVar1 + 0x1c);
    }
    if (puVar1 == (undefined *)0x0) break;
    pcVar3 = *(code **)(puVar1 + 8);
  }
  _null_init();
  _pffasttimo();
  _pfslowtimo();
  return CONCAT44(param_2,param_1);
}

