
sqword _unp_scan(undefined4 *param_1,code *param_2)

{
  sword sVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  uint uVar5;
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
  do {
    while( true ) {
      if (param_1 == (undefined4 *)0x0) {
        return ZEXT48(param_2) << 0x20;
      }
      if (param_1 != (undefined4 *)0x0) break;
loc_F0023288:
      param_1 = (undefined4 *)param_1[0x1f];
    }
    sVar1 = *(sword *)((int)param_1 + 10);
    puVar3 = param_1;
loc_F0023224:
    if (sVar1 != 0xc) {
      puVar3 = (undefined4 *)*puVar3;
loc_F002327C:
      if (puVar3 == (undefined4 *)0x0) goto loc_F0023288;
      sVar1 = *(sword *)((int)puVar3 + 10);
      goto loc_F0023224;
    }
    if ((int)*(sword *)(puVar3 + 2) == 0) {
      puVar3 = (undefined4 *)*puVar3;
      goto loc_F002327C;
    }
    iVar4 = 0;
    uVar5 = (uint)(int)*(sword *)(puVar3 + 2) >> 2;
    puVar3 = (undefined4 *)((int)puVar3 + puVar3[1]);
    if (uVar5 == 0) goto loc_F0023288;
    uVar2 = *puVar3;
    while( true ) {
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 1;
      (*param_2)(uVar2);
      if ((int)uVar5 <= iVar4) break;
      uVar2 = *puVar3;
    }
    param_1 = (undefined4 *)param_1[0x1f];
  } while( true );
}
