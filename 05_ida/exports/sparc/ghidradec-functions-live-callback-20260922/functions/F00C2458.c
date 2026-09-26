
/* WARNING: Removing unreachable block (ram,0xf00c2624) */
/* WARNING: Removing unreachable block (ram,0xf00c2600) */
/* WARNING: Removing unreachable block (ram,0xf00c25d0) */
/* WARNING: Removing unreachable block (ram,0xf00c25b4) */
/* WARNING: Removing unreachable block (ram,0xf00c25e0) */
/* WARNING: Removing unreachable block (ram,0xf00c2610) */
/* WARNING: Removing unreachable block (ram,0xf00c2630) */
/* WARNING: Removing unreachable block (ram,0xf00c24d4) */

undefined8 _msopen(uint param_1,int param_2)

{
  undefined4 uVar1;
  sword sVar4;
  sword *psVar2;
  undefined4 uVar3;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  undefined4 unaff_l0;
  int iVar8;
  undefined4 unaff_l1;
  undefined *puVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar10;
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
  iVar6 = 0;
  puVar5 = _msdata;
  do {
    iVar6 = iVar6 + 1;
    if (*(int *)(puVar5 + 0x18) == param_2) goto loc_F00C2618;
    puVar5 = puVar5 + 0x34;
  } while (iVar6 < 1);
  iVar6 = 0;
  puVar5 = _msdata;
  iVar10 = 0;
  do {
    if (*(int *)(puVar5 + 0x18) == 0) {
      iVar8 = (int)(sword)param_1;
      iVar6 = iVar8;
      _zsopen(iVar8,1);
      if (iVar6 != 0) goto locret_F00C2638;
      iVar7 = ((param_1 & 0xffff) >> 8) * 0x2c;
      iVar6 = iVar8;
      (**(code **)(DAT_f011ca00 + iVar7))
                (iVar8,0x40067408,(undefined *)((int)register0x00000038 + -0x10),0);
      puVar9 = (undefined *)0x0;
      if (iVar6 == 0) {
        *(undefined2 *)((int)register0x00000038 + -0xc) = 0xe0;
        *(undefined *)((int)register0x00000038 + -0xf) = 0xc;
        *(undefined *)((int)register0x00000038 + -0x10) = 0xc;
        (**(code **)(DAT_f011ca00 + iVar7))
                  (iVar8,0x80067409,(undefined *)((int)register0x00000038 + -0x10),0);
        iVar6 = iVar8;
        if (iVar8 == 0) {
          *(undefined2 *)(puVar5 + 0x20) = 0;
          *(int *)(puVar5 + 0x18) = param_2;
          *(undefined4 *)(puVar5 + 0x24) = 0xc;
          *(undefined4 *)(puVar5 + 0x28) = 1;
          *(undefined4 *)(puVar5 + 0x30) = 0;
          iVar6 = 0;
          if (*(int *)(_msdata + iVar10) != 0) goto locret_F00C2638;
          sVar4 = (sword)_MS_BUF_BYTES;
          *(sword *)(puVar5 + 4) = sVar4;
          psVar2 = (sword *)(int)sVar4;
          _kalloc();
          if (psVar2 != (sword *)0x0) {
            _bzero(psVar2,(int)*(sword *)(puVar5 + 4));
            iVar6 = *(sword *)(puVar5 + 4) + -0x10;
            udiv(iVar6,0xc);
            *psVar2 = (sword)iVar6 + 1;
            uVar1 = _msjitterrate;
            uVar3 = _hz;
            *(sword **)(_msdata + iVar10) = psVar2;
            div(uVar3,uVar1);
            _msjittertimeout = uVar3;
            sub_F00C2698(puVar5);
loc_F00C2618:
            iVar6 = 0;
            goto locret_F00C2638;
          }
          iVar6 = 0x16;
          puVar9 = puVar5;
        }
      }
      _bzero(puVar9,0x34);
      _bzero(puVar9,0x18);
      goto locret_F00C2638;
    }
    puVar5 = puVar5 + 0x34;
    iVar6 = iVar6 + 1;
    iVar10 = iVar10 + 0x34;
  } while (iVar6 < 1);
  iVar6 = 0x10;
locret_F00C2638:
  return CONCAT44(param_2,iVar6);
}

