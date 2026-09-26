
/* WARNING: Removing unreachable block (ram,0xf002aba8) */
/* WARNING: Removing unreachable block (ram,0xf002abc4) */
/* WARNING: Removing unreachable block (ram,0xf002ab74) */
/* WARNING: Removing unreachable block (ram,0xf002ab54) */
/* WARNING: Removing unreachable block (ram,0xf002aae4) */
/* WARNING: Removing unreachable block (ram,0xf002aa88) */
/* WARNING: Removing unreachable block (ram,0xf002aa44) */
/* WARNING: Removing unreachable block (ram,0xf002ab40) */
/* WARNING: Removing unreachable block (ram,0xf002a9e4) */
/* WARNING: Removing unreachable block (ram,0xf002a9b4) */
/* WARNING: Removing unreachable block (ram,0xf002a9ec) */
/* WARNING: Removing unreachable block (ram,0xf002aa34) */
/* WARNING: Removing unreachable block (ram,0xf002aa6c) */
/* WARNING: Removing unreachable block (ram,0xf002aacc) */
/* WARNING: Removing unreachable block (ram,0xf002ab0c) */
/* WARNING: Removing unreachable block (ram,0xf002ab6c) */
/* WARNING: Removing unreachable block (ram,0xf002ab94) */
/* WARNING: Removing unreachable block (ram,0xf002abd0) */
/* WARNING: Removing unreachable block (ram,0xf002abb4) */
/* WARNING: Removing unreachable block (ram,0xf002a980) */

undefined8 sub_F002A97C(uint *param_1,undefined4 param_2,sword *param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  byte *pbVar4;
  byte bVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar6;
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
  puVar1 = param_1;
  _if_private();
  uVar6 = puVar1[5];
  if (*param_3 == 0) {
    _bcopy(param_3 + 1,(undefined *)((int)register0x00000038 + -0x26),6);
    DAT_f010c26c._0_2_ = param_3[7];
    if (DAT_f010c26c._0_2_ == 0x806) {
      _nb_write(param_2,0,2,&unk_F010C278);
      puVar1 = param_1;
      _if_private();
      if ((*puVar1 & 1) == 0) {
        *(byte *)((int)register0x00000038 + -0x20) =
             *(byte *)((int)register0x00000038 + -0x20) & 0x7f;
      }
      else {
        *(undefined *)((int)register0x00000038 + -0x1a) = 0x82;
        *(undefined *)((int)register0x00000038 + -0x19) = 0x70;
        *(byte *)((int)register0x00000038 + -0x20) =
             *(byte *)((int)register0x00000038 + -0x20) | 0x80;
      }
    }
  }
  else {
    if (*param_3 != 2) {
      _nb_free(param_2);
      uVar6 = 0x2f;
      goto locret_F002ABDC;
    }
    *(undefined4 *)((int)register0x00000038 + -0x2c) = *(undefined4 *)(param_3 + 2);
    puVar1 = param_1;
    _if_private();
    *(uint *)((int)register0x00000038 + -0x34) = puVar1[4];
    puVar1 = param_1;
    _if_private(param_1);
    puVar2 = param_1;
    _arpresolve(param_1,puVar1 + 2,(undefined *)((int)register0x00000038 + -0x34),param_2,
                (undefined *)((int)register0x00000038 + -0x2c),
                (undefined *)((int)register0x00000038 + -0x26),
                (undefined *)((int)register0x00000038 + -0x30));
    if (puVar2 == (uint *)0x0) {
      uVar6 = 0;
      goto locret_F002ABDC;
    }
    puVar1 = param_1;
    _if_private();
    bVar5 = *(byte *)((int)register0x00000038 + -0x20);
    if ((*puVar1 & 1) == 0) {
loc_F002AB24:
      bVar5 = bVar5 & 0x7f;
loc_F002AB28:
      *(byte *)((int)register0x00000038 + -0x20) = bVar5;
    }
    else {
      if (*(char *)((int)register0x00000038 + -0x26) < '\0') {
        *(undefined *)((int)register0x00000038 + -0x1a) = 0xc2;
        *(undefined *)((int)register0x00000038 + -0x19) = 0x70;
        bVar5 = *(byte *)((int)register0x00000038 + -0x20) | 0x80;
        goto loc_F002AB28;
      }
      puVar1 = param_1;
      _if_private();
      uVar3 = puVar1[1];
      if ((*(byte *)((int)register0x00000038 + -0x26) & 0x80) == 0) {
        _NXHashGet(uVar3,(undefined *)((int)register0x00000038 + -0x26));
        pbVar4 = (byte *)0x0;
        if (uVar3 != 0) {
          pbVar4 = (byte *)(uVar3 + 0xc);
        }
        if (pbVar4 == (byte *)0x0) {
          bVar5 = *(byte *)((int)register0x00000038 + -0x20);
          goto loc_F002AB24;
        }
        _bcopy(pbVar4,(undefined *)((int)register0x00000038 + -0x1a),*pbVar4 & 0x1f);
        bVar5 = *(byte *)((int)register0x00000038 + -0x20) | 0x80;
        goto loc_F002AB28;
      }
    }
    DAT_f010c26c._0_2_ = 0x800;
  }
  _nb_grow_top(param_2,8);
  _nb_write(param_2,0,8,unk_F010C266);
  puVar1 = param_1;
  _if_private();
  *(undefined *)((int)register0x00000038 + -0x28) = *(undefined *)(puVar1 + 6);
  *(undefined *)((int)register0x00000038 + -0x27) = 0x40;
  _if_output(uVar6,param_2,(undefined *)((int)register0x00000038 + -0x28));
  if (uVar6 == 0) {
    puVar1 = param_1;
    _if_opackets(param_1);
    _if_opackets_set(param_1,(int)puVar1 + 1);
  }
  else {
    puVar1 = param_1;
    _if_oerrors(param_1);
    _if_oerrors_set(param_1,(int)puVar1 + 1);
  }
locret_F002ABDC:
  return CONCAT44(param_2,uVar6);
}
