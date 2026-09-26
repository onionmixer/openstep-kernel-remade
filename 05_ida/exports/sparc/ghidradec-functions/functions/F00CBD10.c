
/* WARNING: Removing unreachable block (ram,0xf00cbd88) */
/* WARNING: Removing unreachable block (ram,0xf00cbe1c) */
/* WARNING: Removing unreachable block (ram,0xf00cbe38) */
/* WARNING: Removing unreachable block (ram,0xf00cbe64) */
/* WARNING: Removing unreachable block (ram,0xf00cbe88) */
/* WARNING: Removing unreachable block (ram,0xf00cbe48) */
/* WARNING: Removing unreachable block (ram,0xf00cbdd0) */
/* WARNING: Removing unreachable block (ram,0xf00cbdb4) */
/* WARNING: Removing unreachable block (ram,0xf00cbe9c) */
/* WARNING: Removing unreachable block (ram,0xf00cbd20) */
/* WARNING: Removing unreachable block (ram,0xf00cbde8) */

undefined8 -[IOEthernet commandRequestOccurred](uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined6 *puVar3;
  undefined4 unaff_l0;
  undefined4 uVar4;
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
  uVar1 = *(undefined4 *)(param_1 + 300);
  uVar4 = 0;
  _objc_msgSend(uVar1,paOper_0);
  switch(uVar1) {
  case :
    if (*(char *)(param_1 + 0x128) == '\0') {
      uVar2 = param_1;
      _objc_msgSend(param_1,paResetandenable,1);
      if ((uVar2 & 0xff) == 0) {
        uVar4 = 5;
        goto loc_F00CBE90;
      }
      uVar1 = *(undefined4 *)(param_1 + 300);
    }
    else {
      uVar1 = *(undefined4 *)(param_1 + 300);
    }
    break;
  case :
    _objc_msgSend(param_1,paResetandenable,0);
    uVar1 = *(undefined4 *)(param_1 + 300);
    break;
  :
    goto def_F00CBD44;
  case :
    uVar1 = *(undefined4 *)(param_1 + 300);
    puVar3 = paDone;
    _objc_msgSend(uVar1,paDone,0);
    _IOExitThread();
    return CONCAT44(puVar3,uVar1);
  case :
    uVar2 = param_1;
    _objc_msgSend(param_1,paEnablepromiscu);
    if ((uVar2 & 0xff) == 0) {
      *(undefined *)(param_1 + 0x129) = 0;
      uVar4 = 1;
    }
    else {
      *(undefined *)(param_1 + 0x129) = 1;
    }
    goto loc_F00CBE90;
  case :
    _objc_msgSend(param_1,paDisablepromisc);
    *(undefined *)(param_1 + 0x129) = 0;
loc_F00CBE90:
    uVar1 = *(undefined4 *)(param_1 + 300);
    break;
  case :
    _objc_msgSend(param_1,paAddmulticastad,param_1 + 0x13c);
    _objc_msgSend(param_1,paEnablemulticas_0);
    uVar1 = *(undefined4 *)(param_1 + 300);
    break;
  case :
    _objc_msgSend(param_1,paRemovemulticas,param_1 + 0x13c);
    if (param_1 + 0x144 == *(int *)(param_1 + 0x144)) {
      _objc_msgSend(param_1,paDisablemultica_0);
      goto loc_F00CBE90;
    }
    uVar1 = *(undefined4 *)(param_1 + 300);
  }
  _objc_msgSend(uVar1,paDone,uVar4);
def_F00CBD44:
  return CONCAT44(param_2,param_1);
}
