/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11c9a0. */
int __cdecl pn_get(int a1, int a2, int *a3)
{
  int v3; // eax
  int v4; // eax
  int v5; // ebx

  v3 = kalloc(0x400u); /*0x11c9b4*/
  *a3 = v3; /*0x11c9b9*/
  a3[1] = v3; /*0x11c9bb*/
  a3[2] = 0; /*0x11c9be*/
  if ( a2 ) /*0x11c9ca*/
    v4 = copystr(a1, a3[1], 1024, a3 + 2); /*0x11c9f2*/
  else
    v4 = copyinstr(a1, a3[1], 1024, a3 + 2); /*0x11c9da*/
  v5 = v4; /*0x11c9f7*/
  if ( !v4 && a3[2] == 1024 && *(_BYTE *)(a3[1] + 1023) ) /*0x11ca0c*/
    v5 = 63; /*0x11ca15*/
  --a3[2]; /*0x11ca1a*/
  if ( v5 ) /*0x11ca1f*/
    pn_free(a3); /*0x11ca22*/
  return v5; /*0x11ca2c*/
}
