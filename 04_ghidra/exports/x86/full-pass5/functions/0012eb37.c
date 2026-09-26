/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012eb37 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0012eb37(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int unaff_EBP;
  
  (**(code **)(*(int *)(*(int *)**(undefined4 **)(unaff_EBP + -0xc) + 0x20) + 0x10))();
  iVar3 = *(int *)(*(int *)(unaff_EBP + 8) + 0x5c);
  while ((iVar4 = _MAXCLIENTS, 1 < iVar3 || (iVar3 < 0))) {
    _printf(s_authget__unknown_authflavor__d_001dc2cc);
    iVar3 = 0;
  }
  *(int *)(unaff_EBP + -0x10) = _MAXCLIENTS;
  do {
    iVar3 = _nextunixvictim * 8;
    *(undefined **)(unaff_EBP + -0x14) = &_unixauthtab + iVar3;
    _nextunixvictim = _nextunixvictim + 1;
    _nextunixvictim = _nextunixvictim % *(uint *)(unaff_EBP + -0x10);
    if (*(short *)(&_unixauthtab + iVar3) == 0) {
      iVar4 = *(int *)(unaff_EBP + -0x14);
      if (*(int *)(iVar4 + 4) == 0) {
        uVar2 = _authkern_create();
        *(undefined4 *)(iVar4 + 4) = uVar2;
      }
      *(undefined2 *)(&_unixauthtab + iVar3) = 1;
      uVar2 = *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 4);
      goto LAB_0012ec04;
    }
    iVar4 = iVar4 + -1;
  } while (0 < iVar4);
  uVar2 = _authkern_create();
LAB_0012ec04:
  puVar1 = *(undefined4 **)(unaff_EBP + -0xc);
  *(undefined4 *)*puVar1 = uVar2;
  if (*(int *)*puVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_clget__null_auth_001dc320);
  }
  **(int **)(unaff_EBP + -4) = **(int **)(unaff_EBP + -4) + 1;
  if ((*(byte *)(*(int *)(unaff_EBP + 8) + 0x14) & 5) == 5) {
    _clntkudp_interruptable(**(undefined4 **)(unaff_EBP + -0xc));
  }
  return **(undefined4 **)(unaff_EBP + -0xc);
}

