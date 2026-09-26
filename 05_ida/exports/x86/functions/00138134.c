/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x138134. */
int __cdecl xdr_array(XDR *a1, char **a2, unsigned int *a3, unsigned int a4, unsigned int a5, xdrproc_t a6)
{
  char *v6; // esi
  unsigned int v8; // edi
  unsigned int i; // ebx
  size_t v10; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  v6 = *a2; /*0x138143*/
  v11 = 1; /*0x138145*/
  if ( !xdr_u_int(a1, a3) )
  {
    printf("xdr_array: size FAILED\n");
    return 0; /*0x138169*/
  }
  v8 = *a3; /*0x138170*/
  if ( a4 < *a3 && a1->x_op != XDR_FREE )
  {
    printf("xdr_array: bad size FAILED\n");
    return 0; /*0x13818b*/
  }
  v10 = v8 * a5; /*0x138196*/
  if ( v6 ) /*0x13819b*/
    goto LABEL_13; /*0x13819b*/
  if ( a1->x_op != XDR_DECODE ) /*0x1381a5*/
  {
    if ( a1->x_op != XDR_FREE ) /*0x1381aa*/
      goto LABEL_13; /*0x1381aa*/
    return 1; /*0x1381b9*/
  }
  if ( !v8 ) /*0x1381b2*/
    return 1; /*0x1381b2*/
  v6 = (char *)kalloc(v10); /*0x1381c5*/
  *a2 = v6; /*0x1381ca*/
  bzero(v6, v10); /*0x1381d1*/
LABEL_13:
  for ( i = 0; i < v8; ++i ) /*0x1381dd*/
  {
    if ( !v11 ) /*0x1381e4*/
      break; /*0x1381e4*/
    v11 = a6(a1, v6, -1u); /*0x1381f2*/
    v6 += a5; /*0x1381f5*/
  }
  if ( a1->x_op == XDR_FREE ) /*0x138206*/
  {
    kfree((int)*a2, v10); /*0x138212*/
    *a2 = nullptr; /*0x13821a*/
  }
  return v11; /*0x138226*/
}
