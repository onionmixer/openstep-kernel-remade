/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013074c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_0013074c(void)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  int unaff_EBX;
  int unaff_EBP;
  
  while( true ) {
    *(undefined4 *)(unaff_EBP + -0x30) = 0x186ba;
    *(undefined4 *)(unaff_EBP + -0x2c) = 1;
    *(undefined4 *)(unaff_EBP + -0x28) = 2;
    *(int *)(unaff_EBP + -0x20) = unaff_EBP + -0x18;
    *(code **)(unaff_EBP + -0x1c) = _xdr_bp_getfile_arg;
    *(int *)(unaff_EBP + -0x40) = unaff_EBP + -0x44;
    *(int *)(unaff_EBP + -0x38) = unaff_EBP + -0x10;
    *(code **)(unaff_EBP + -0x34) = _xdr_bp_getfile_res;
    iVar2 = _clntkudp_callit_addr
                      (unaff_EBX,5,_xdr_rmtcall_args,unaff_EBP + -0x30,_xdr_rmtcallres,
                       unaff_EBP + -0x40,*(undefined4 *)(unaff_EBP + -0x50),
                       *(undefined4 *)(unaff_EBP + -0x4c));
    (**(code **)(*(int *)(unaff_EBX + 4) + 0x10))();
    if ((iVar2 != 5) ||
       (*(int *)(unaff_EBP + -0x54) = *(int *)(unaff_EBP + -0x54) + 1,
       4 < *(int *)(unaff_EBP + -0x54))) break;
    _DAT_001e59da = 0x6f00;
    unaff_EBX = _clntkudp_create(&DAT_001e59d8,100000,2,5);
    if (unaff_EBX == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_pmap_rmtcall__clntkudp_create_fa_001dc746);
    }
  }
  if (iVar2 == 0) {
    _strcpy(*(char **)(unaff_EBP + 0xc),*(char **)(unaff_EBP + -0x10));
    _strcpy(*(char **)(unaff_EBP + 0x14),*(char **)(unaff_EBP + -4));
  }
  _kfree(*(undefined4 *)(unaff_EBP + -0x10));
  _kfree(*(undefined4 *)(unaff_EBP + -4),0x100);
  if (iVar2 == 0) {
    _bcopy((void *)(unaff_EBP + -8),(void *)(unaff_EBP + -0x48),4);
    if (((**(char **)(unaff_EBP + 0xc) == '\0') || (**(char **)(unaff_EBP + 0x14) == '\0')) ||
       (*(int *)(unaff_EBP + -0x48) == 0)) {
      iVar3 = 0x16;
    }
    else if (*(int *)(unaff_EBP + -0xc) == 1) {
      _bzero(*(void **)(unaff_EBP + 0x10),0x10);
      puVar1 = *(undefined2 **)(unaff_EBP + 0x10);
      *puVar1 = 2;
      *(undefined4 *)(puVar1 + 2) = *(undefined4 *)(unaff_EBP + -0x48);
      _printf(s_NFS_mounting___s__from__s__s_001dc91d,*(undefined4 *)(unaff_EBP + 8),
              *(undefined4 *)(unaff_EBP + 0xc));
      iVar3 = 0;
    }
    else {
      _printf(s_getfile__unknown_address_type__d_001dc8fb);
      iVar3 = 0x2b;
    }
  }
  else {
    iVar3 = 0x3c;
    if (iVar2 != 5) {
      iVar3 = iVar2;
    }
  }
  return iVar3;
}

