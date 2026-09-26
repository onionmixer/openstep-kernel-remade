/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x137fa0. */
int __cdecl xdr_string(XDR *a1, char **a2, unsigned int a3)
{
  char *v3; // ebx
  unsigned int v5; // edx
  unsigned __int32 v6; // edi
  xdr_op x_op; // eax
  int v8; // [esp+0h] [ebp-10h]
  int v9; // [esp+4h] [ebp-Ch]
  int v10; // [esp+8h] [ebp-8h]
  unsigned __int32 v11; // [esp+Ch] [ebp-4h] BYREF
  int savedregs; // [esp+10h] [ebp+0h]

  v3 = *a2; /*0x137faf*/
  if ( a1->x_op ) /*0x137fb1*/
  {
    if ( a1->x_op != XDR_FREE ) /*0x137fba*/
      goto LABEL_6; /*0x137fba*/
    if ( !v3 ) /*0x137fbe*/
      return 1; /*0x137fc5*/
  }
  v11 = strlen(*a2); /*0x137fdd*/
LABEL_6:
  if ( !xdr_u_long(a1, &v11) )
  {
    printf("xdr_string: size FAILED\n");
    return 0; /*0x137ffd*/
  }
  if ( a3 < v11 )
  {
    printf("xdr_string: bad size FAILED\n");
    return 0; /*0x138018*/
  }
  v5 = v11 + 1; /*0x138020*/
  if ( a1->x_op == XDR_DECODE )
  {
    if ( !v3 ) /*0x13803e*/
    {
      v3 = (char *)kalloc(v5); /*0x138046*/
      *a2 = v3; /*0x13804b*/
    }
    v3[v11] = 0; /*0x138053*/
  }
  else if ( a1->x_op )
  {
    if ( a1->x_op == XDR_FREE )
    {
      kfree((int)v3, v5); /*0x138106*/
      *a2 = nullptr; /*0x13810e*/
      return 1; /*0x138114*/
    }
    else
    {
      printf("xdr_string: bad op FAILED\n");
      return 0; /*0x138126*/
    }
  }
  if ( !v11 ) /*0x13805c*/
    return 1; /*0x13805c*/
  v6 = v11 & 3; /*0x138064*/
  if ( (v11 & 3) != 0 ) /*0x138067*/
    v6 = 4 - v6; /*0x138070*/
  x_op = a1->x_op; /*0x138072*/
  if ( a1->x_op == XDR_DECODE )
  {
    if ( !a1->x_ops->x_getbytes(a1, v3, v11) )
    {
      printf("xdr_opaque: decode FAILED\n");
      return 0; /*0x138101*/
    }
    if ( !v6 ) /*0x138096*/
      return 1; /*0x138096*/
    return ((int (__stdcall *)(XDR *, void *, unsigned __int32, int, int, int, unsigned __int32, int))a1->x_ops->x_getbytes)( /*0x1380a9*/
             a1,
             &unk_1E5A20,
             v6,
             v8,
             v9,
             v10,
             v11,
             savedregs);
  }
  else
  {
    if ( x_op )
    {
      if ( x_op == XDR_FREE ) /*0x1380ef*/
        return 1; /*0x1380ef*/
      printf("xdr_opaque: bad op FAILED\n");
      return 0; /*0x1380fa*/
    }
    if ( !a1->x_ops->x_putbytes(a1, v3, v11) )
    {
      printf("xdr_opaque: encode FAILED\n");
      return 0; /*0x1380cb*/
    }
    if ( !v6 ) /*0x1380d2*/
      return 1; /*0x1380d2*/
    return ((int (__stdcall *)(XDR *, void *, unsigned __int32, int, int, int, unsigned __int32, int))a1->x_ops->x_putbytes)( /*0x1380e5*/
             a1,
             &unk_1DD213,
             v6,
             v8,
             v9,
             v10,
             v11,
             savedregs);
  }
}
