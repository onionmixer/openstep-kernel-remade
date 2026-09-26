/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016943e */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0016943e(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int unaff_EBP;
  uint uVar6;
  undefined8 uVar7;
  
  if ((int **)DAT_001e7248 == &DAT_001e7248) {
    piVar4 = (int *)0x0;
  }
  else {
    *(int ***)(*DAT_001e7248 + 4) = &DAT_001e7248;
    piVar4 = DAT_001e7248;
    DAT_001e7248 = (int *)*DAT_001e7248;
  }
  piVar4[2] = *(int *)(unaff_EBP + 8);
  piVar4[3] = *(int *)(unaff_EBP + 0xc);
  piVar4[4] = 0;
  iVar1 = *(int *)(unaff_EBP + 0x14);
  piVar4[5] = *(int *)(unaff_EBP + 0x10);
  piVar4[6] = iVar1;
  for (piVar3 = DAT_001e7258;
      (((int **)piVar3 != &DAT_001e7258 && ((uint)piVar3[6] <= (uint)piVar4[6])) &&
      ((piVar3[6] != piVar4[6] || ((uint)piVar3[5] <= (uint)piVar4[5])))); piVar3 = (int *)*piVar3)
  {
    if ((piVar4[5] == piVar3[5]) && (piVar4[6] == piVar3[6])) goto LAB_001694cc;
  }
  piVar3 = (int *)piVar3[1];
LAB_001694cc:
  *piVar4 = *piVar3;
  piVar4[1] = (int)piVar3;
  *(int **)(*piVar3 + 4) = piVar4;
  *piVar3 = (int)piVar4;
  piVar4[7] = 2;
  if (DAT_001e7258 == piVar4) {
    uVar7 = _clock_value();
    uVar5 = (uint)((ulonglong)uVar7 >> 0x20);
    if (((uint)piVar4[6] < uVar5) || ((uVar5 == piVar4[6] && ((uint)piVar4[5] < (uint)uVar7)))) {
      uVar5 = 0;
    }
    else {
      *(uint *)(unaff_EBP + -8) = (uint)uVar7;
      *(uint *)(unaff_EBP + -0xc) = uVar5;
      puVar2 = (undefined4 *)_timer_attributes();
      *(undefined4 *)(unaff_EBP + -0x14) = *puVar2;
      *(undefined4 *)(unaff_EBP + -0x10) = puVar2[1];
      uVar5 = piVar4[5] - *(uint *)(unaff_EBP + -8);
      uVar6 = (piVar4[6] - *(int *)(unaff_EBP + -0xc)) -
              (uint)((uint)piVar4[5] < *(uint *)(unaff_EBP + -8));
      if ((*(uint *)(unaff_EBP + -0x10) < uVar6) ||
         ((*(uint *)(unaff_EBP + -0x10) == uVar6 && (*(uint *)(unaff_EBP + -0x14) < uVar5)))) {
        uVar5 = *(uint *)(unaff_EBP + -0x14);
      }
    }
    _set_timer(0,uVar5);
  }
  LOCK();
  DAT_001e7244 = 0;
  UNLOCK();
  _splx();
  return;
}

