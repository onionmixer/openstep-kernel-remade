
/* WARNING: Removing unreachable block (ram,0xf00428c8) */
/* WARNING: Removing unreachable block (ram,0xf00428a0) */
/* WARNING: Removing unreachable block (ram,0xf0042888) */
/* WARNING: Removing unreachable block (ram,0xf00428b4) */
/* WARNING: Removing unreachable block (ram,0xf00428f0) */
/* WARNING: Removing unreachable block (ram,0xf004287c) */

undefined8 _xdr_authkern(int *param_1,undefined4 param_2)

{
  sword sVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  sword *psVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  iVar3 = *param_1;
  iVar4 = *(int *)(_active_u + 0x1c);
  *(undefined **)((int)register0x00000038 + -0x54) = _hostname;
  sVar1 = *(sword *)(*(int *)(_active_u + 0x1c) + 4);
  psVar5 = (sword *)(iVar4 + 10);
  *(int *)((int)register0x00000038 + -0x58) = (int)*(sword *)(iVar4 + 2);
  *(int *)((int)register0x00000038 + -0x5c) = (int)sVar1;
  if (iVar3 == 0) {
    *(undefined4 *)((int)register0x00000038 + -0x60) = 0;
    do {
      sVar1 = *psVar5;
      iVar3 = *(int *)((int)register0x00000038 + -0x60);
      if (sVar1 == -1) break;
      psVar5 = psVar5 + 1;
      *(int *)((int)register0x00000038 + iVar3 * 4 + -0x48) = (int)sVar1;
      iVar3 = iVar3 + 1;
      *(int *)((int)register0x00000038 + -0x60) = iVar3;
    } while (iVar3 < 0x10);
    _getthetime((undefined *)((int)register0x00000038 + -0x50));
    piVar2 = param_1;
    _xdr_u_long(param_1,(undefined *)((int)register0x00000038 + -0x50));
    if ((((piVar2 != (int *)0x0) &&
         (piVar2 = param_1, _xdr_string(param_1,(undefined *)((int)register0x00000038 + -0x54),0xff)
         , piVar2 != (int *)0x0)) &&
        (piVar2 = param_1, _xdr_int(param_1,(undefined *)((int)register0x00000038 + -0x58)),
        piVar2 != (int *)0x0)) &&
       (piVar2 = param_1, _xdr_int(param_1,(undefined *)((int)register0x00000038 + -0x5c)),
       piVar2 != (int *)0x0)) {
      _xdr_array(param_1,(undefined *)((int)register0x00000038 + -0x48),
                 (undefined *)((int)register0x00000038 + -0x60),0x10,4,_xdr_int);
      uVar6 = 1;
      if (param_1 != (int *)0x0) goto locret_F0042908;
    }
  }
  uVar6 = 0;
locret_F0042908:
  return CONCAT44(param_2,uVar6);
}

