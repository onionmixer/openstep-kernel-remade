/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1188d4. */
void __cdecl unp_disconnect(int *a1)
{
  int *v1; // ebx
  __int16 v2; // ax
  int *v3; // eax
  int *v4; // ebx

  v1 = (int *)a1[3]; /*0x1188dc*/
  if ( v1 ) /*0x1188e1*/
  {
    a1[3] = 0; /*0x1188e3*/
    v2 = *(_WORD *)*a1; /*0x1188ec*/
    if ( v2 == 1 ) /*0x1188f3*/
    {
      soisdisconnected(*a1); /*0x11893d*/
      v1[3] = 0; /*0x118942*/
      soisdisconnected(*v1); /*0x11894c*/
    }
    else if ( v2 == 2 ) /*0x1188f9*/
    {
      v3 = (int *)v1[4]; /*0x1188fb*/
      if ( v3 == a1 ) /*0x118900*/
      {
        v1[4] = a1[5]; /*0x118905*/
      }
      else
      {
        do /*0x118924*/
        {
          v4 = v3; /*0x11890c*/
          if ( !v3 ) /*0x118910*/
            panic(aUnpDisconnect); /*0x118917*/
          v3 = (int *)v3[5]; /*0x11891f*/
        }
        while ( v3 != a1 ); /*0x118924*/
        v4[5] = a1[5]; /*0x118929*/
      }
      a1[5] = 0; /*0x11892c*/
      *(_BYTE *)(*a1 + 6) &= ~2u; /*0x118935*/
    }
  }
}
