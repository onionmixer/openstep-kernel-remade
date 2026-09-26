
/* WARNING: Removing unreachable block (ram,0xf00eca2c) */
/* WARNING: Removing unreachable block (ram,0xf00ec9b4) */
/* WARNING: Removing unreachable block (ram,0xf00eca60) */
/* WARNING: Removing unreachable block (ram,0xf00ec970) */

undefined8 sub_F00EC96C(undefined4 *****param_1,int param_2)

{
  undefined4 *****pppppuVar1;
  int iVar2;
  undefined4 ****ppppuVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  undefined4 *****pppppuVar5;
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
  bool bVar6;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined4 ****appppuStack_c [3];
  
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
  pppppuVar5 = param_1;
  _current_thread_EXTERNAL();
  puVar4 = unk_F012F048;
  pppppuVar1 = DAT_f012f058;
  while (pppppuVar1 != pppppuVar5) {
    puVar4 = *(undefined **)((int)puVar4 + 0x14);
    if ((undefined4 *****)puVar4 == (undefined4 *****)0x0) {
      sub_F00EC878();
      puVar4 = (undefined *)pppppuVar5;
      break;
    }
    pppppuVar1 = *(undefined4 ******)((int)puVar4 + 0x10);
  }
  pppppuVar5 = *(undefined4 ******)puVar4;
  bVar6 = pppppuVar5 == (undefined4 *****)0x0;
  if (pppppuVar5 != param_1) {
    do {
      if (bVar6) break;
      bVar6 = false;
      if ((((uint)pppppuVar5 & 1) == 0) &&
         (bVar6 = ((uint)pppppuVar5 & 1) == 0, pppppuVar5 <= appppuStack_c)) {
        __NXLogError(aExceptionHandl);
                    /* WARNING: Subroutine does not return */
        _abort();
      }
      if (bVar6) {
        pppppuVar5 = (undefined4 *****)pppppuVar5[0x1d];
      }
      else {
        pppppuVar5 = (undefined4 *****)
                     (*(undefined4 *****)((int)puVar4 + 4))[(((int)pppppuVar5 + -1) / 2) * 3];
      }
      bVar6 = pppppuVar5 == (undefined4 *****)0x0;
    } while (pppppuVar5 != param_1);
    bVar6 = pppppuVar5 == (undefined4 *****)0x0;
  }
  if (bVar6) {
locret_F00ECB44:
    return CONCAT44(param_2,param_1);
  }
  if (param_2 == 0) {
    __NXLogError(aExceptionHandl);
  }
  pppppuVar1 = *(undefined4 ******)puVar4;
  pppppuVar5 = (undefined4 *****)puVar4;
  do {
    if (((uint)pppppuVar1 & 1) == 0) {
      if (param_2 == 0) {
        ppppuVar3 = pppppuVar1[0x1d];
        goto loc_F00ECB34;
      }
      appppuStack_c[0] = pppppuVar1 + 0x1d;
    }
    else {
      iVar2 = ((int)pppppuVar1 + -1) / 2;
      appppuStack_c[0] = *(undefined4 *****)((int)puVar4 + 4) + iVar2 * 3;
      if (param_2 == 0) {
        if (pppppuVar1 != param_1) {
          (*(code *)appppuStack_c[0][1])(appppuStack_c[0][2],1,0,0);
        }
        *(undefined4 *****)((int)puVar4 + 0xc) =
             (undefined4 ****)
             (((int)appppuStack_c[0] - (int)*(undefined4 *****)((int)puVar4 + 4)) * -0x55555555 >> 2
             );
        ppppuVar3 = (undefined4 ****)*appppuStack_c[0];
      }
      else {
        if (pppppuVar1 != param_1) goto loc_F00ECB3C;
        ppppuVar3 = (undefined4 ****)(*(undefined4 *****)((int)puVar4 + 4))[iVar2 * 3];
      }
loc_F00ECB34:
      *pppppuVar5 = ppppuVar3;
      appppuStack_c[0] = pppppuVar5;
    }
loc_F00ECB3C:
    if (pppppuVar1 == param_1) goto locret_F00ECB44;
    pppppuVar1 = (undefined4 *****)*appppuStack_c[0];
    pppppuVar5 = (undefined4 *****)appppuStack_c[0];
  } while( true );
}

