
/* WARNING: Removing unreachable block (ram,0xf006dcfc) */
/* WARNING: Removing unreachable block (ram,0xf006dd5c) */
/* WARNING: Removing unreachable block (ram,0xf006dcb0) */

undefined8 sub_F006DC90(undefined4 param_1,undefined4 param_2)

{
  undefined (*pauVar1) [9];
  undefined *puVar2;
  undefined4 unaff_l0;
  undefined (**ppauVar3) [9];
  undefined4 unaff_l1;
  undefined (**ppauVar4) [9];
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
  ppauVar4 = (undefined (**) [9])0x0;
  ppauVar3 = &_miniMonCommands;
  pauVar1 = _miniMonCommands;
  while (pauVar1 != (undefined (*) [9])0x0) {
    pauVar1 = *ppauVar3;
    sub_F006DC24(pauVar1,param_1);
    if ((pauVar1 == (undefined (*) [9])0x0) &&
       (bVar5 = ppauVar4 != (undefined (**) [9])0x0, ppauVar4 = ppauVar3, bVar5)) {
      puVar2 = aAmbiguousComma;
      goto loc_F006DD5C;
    }
    ppauVar3 = ppauVar3 + 3;
    pauVar1 = *ppauVar3;
  }
  ppauVar3 = &_miniMonMDCommands;
  pauVar1 = _miniMonMDCommands;
  do {
    if (pauVar1 == (undefined (*) [9])0x0) {
      if (ppauVar4 == (undefined (**) [9])0x0) {
        puVar2 = aInvalidCommand;
loc_F006DD5C:
        param_1 = 1;
        _safe_prf(puVar2);
      }
      else {
        (*(code *)ppauVar4[1])(param_1);
      }
      return CONCAT44(param_2,param_1);
    }
    pauVar1 = *ppauVar3;
    sub_F006DC24(pauVar1,param_1);
    if ((pauVar1 == (undefined (*) [9])0x0) &&
       (bVar5 = ppauVar4 != (undefined (**) [9])0x0, ppauVar4 = ppauVar3, bVar5)) {
      puVar2 = aAmbiguousComma_0;
      goto loc_F006DD5C;
    }
    ppauVar3 = ppauVar3 + 3;
    pauVar1 = *ppauVar3;
  } while( true );
}

