/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x121060. */
int __cdecl if_handle_input(int a1, int a2, int a3)
{
  _DWORD *v3; // ebx
  int (__cdecl *v4)(_DWORD *, int, int, int); // eax

  v3 = (_DWORD *)ifnet; /*0x12106c*/
  if ( ifnet ) /*0x121074*/
  {
    while ( 1 ) /*0x121078*/
    {
      v4 = (int (__cdecl *)(_DWORD *, int, int, int))v3[15]; /*0x121078*/
      if ( v4 ) /*0x12107d*/
      {
        if ( v3[5] && !v4(v3, a1, a2, a3) ) /*0x12108c*/
          return 0; /*0x1210ac*/
      }
      v3 = (_DWORD *)v3[23]; /*0x121095*/
      if ( !v3 ) /*0x12109a*/
        goto LABEL_6; /*0x12109a*/
    }
  }
  else
  {
LABEL_6:
    nb_free(a2); /*0x12109c*/
    return 47; /*0x1210a2*/
  }
}
