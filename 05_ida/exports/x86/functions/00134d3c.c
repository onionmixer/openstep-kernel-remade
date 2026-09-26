/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x134d3c. */
_BOOL4 __cdecl sub_134D3C(XDR *a1, int *a2)
{
  int *v2; // ebx
  char *v3; // ebx
  int v5; // [esp+Ch] [ebp-4h]

  if ( !sub_1341F8(a1, a2) ) /*0x134d57*/
    return 0; /*0x134d57*/
  if ( a1->x_op || !a2[19] ) /*0x134d66*/
    return xdr_bytes(a1, (char **)a2 + 18, (unsigned int *)a2 + 17, 0x2000u) != 0; /*0x134d6a*/
  v5 = splimp(); /*0x134d75*/
  v2 = (int *)mfree; /*0x134d78*/
  if ( mfree ) /*0x134d80*/
  {
    if ( *(_WORD *)(mfree + 10) ) /*0x134d82*/
      panic(aMget_15); /*0x134d8e*/
    *(_WORD *)(mfree + 10) = 1; /*0x134d96*/
    --word_1E917C[0]; /*0x134d9c*/
    ++word_1E917E; /*0x134da3*/
    mfree = *v2; /*0x134dac*/
    *v2 = 0; /*0x134db2*/
    v2[1] = 12; /*0x134db8*/
  }
  else
  {
    v2 = m_more(1, 1); /*0x134dcd*/
  }
  splx(v5); /*0x134dd6*/
  if ( v2 ) /*0x134de0*/
  {
    v3 = (char *)v2 + v2[1]; /*0x134df0*/
    *(_DWORD *)v3 = sub_134E98; /*0x134df3*/
    *((_DWORD *)v3 + 1) = 0; /*0x134df9*/
    *((_DWORD *)v3 + 2) = a2[20]; /*0x134e03*/
    *((_DWORD *)v3 + 3) = a2[19]; /*0x134e09*/
    *((_DWORD *)v3 + 4) = a2[18]; /*0x134e0f*/
    *((_DWORD *)v3 + 5) = a2[17]; /*0x134e15*/
    a1->x_public = v3; /*0x134e18*/
    if ( xdrmbuf_putbuf(a1, a2[18], a2[17], sub_134F7C, v3) ) /*0x134e2a*/
      return 1; /*0x134e34*/
    *((_DWORD *)v3 + 1) = 1; /*0x134e36*/
    return xdr_bytes(a1, (char **)a2 + 18, (unsigned int *)a2 + 17, 0x2000u) != 0; /*0x134e4b*/
  }
  printf("xdr_rrok: FAILED, can't get mbuf\n");
  return 0; /*0x134e61*/
}
