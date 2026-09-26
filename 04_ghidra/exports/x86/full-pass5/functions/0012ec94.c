/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012ec94 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0012ec94(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBP;
  
  (**(code **)(*(int *)(**(int **)(unaff_EBP + -8) + 0x20) + 0x10))();
  iVar1 = *(int *)(*(int *)(unaff_EBP + 8) + 0x5c);
  while ((iVar3 = _MAXCLIENTS, 1 < iVar1 || (iVar1 < 0))) {
    _printf(s_authget__unknown_authflavor__d_001dc2cc);
    iVar1 = 0;
  }
  *(int *)(unaff_EBP + -0x14) = _MAXCLIENTS;
  do {
    iVar1 = _nextunixvictim * 8;
    *(undefined **)(unaff_EBP + -0x10) = &_unixauthtab + iVar1;
    _nextunixvictim = _nextunixvictim + 1;
    _nextunixvictim = _nextunixvictim % *(uint *)(unaff_EBP + -0x14);
    if (*(short *)(&_unixauthtab + iVar1) == 0) {
      iVar3 = *(int *)(unaff_EBP + -0x10);
      if (*(int *)(iVar3 + 4) == 0) {
        uVar2 = _authkern_create();
        *(undefined4 *)(iVar3 + 4) = uVar2;
      }
      *(undefined2 *)(&_unixauthtab + iVar1) = 1;
      iVar1 = *(int *)(*(int *)(unaff_EBP + -0x10) + 4);
      goto LAB_0012ed40;
    }
    iVar3 = iVar3 + -1;
  } while (0 < iVar3);
  iVar1 = _authkern_create();
LAB_0012ed40:
  **(int **)(unaff_EBP + -8) = iVar1;
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_clget__null_auth_001dc344);
  }
  if ((*(byte *)(*(int *)(unaff_EBP + 8) + 0x14) & 5) == 5) {
    _clntkudp_interruptable(*(undefined4 *)(unaff_EBP + -8));
  }
  return *(undefined4 *)(unaff_EBP + -8);
}

