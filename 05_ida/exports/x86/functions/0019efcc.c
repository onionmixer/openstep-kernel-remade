/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19efcc. */
int __cdecl sub_19EFCC(int a1)
{
  _DWORD *v1; // ebx
  char *v3; // edx
  char *v4; // edi
  int i; // esi
  char *v6; // [esp+Ch] [ebp-4h]

  v1 = *(_DWORD **)(a1 + 28); /*0x19efd8*/
  if ( *v1 == 3 ) /*0x19efe0*/
  {
    v3 = (char *)v1[49]; /*0x19eff4*/
    v4 = (char *)v1[53]; /*0x19effa*/
    for ( i = v1[50]; i; --i ) /*0x19f008*/
    {
      v6 = v3; /*0x19f015*/
      memmove(v4, v3, v1[51]); /*0x19f018*/
      v4 += v1[4]; /*0x19f01d*/
      v3 = &v6[v1[51]]; /*0x19f023*/
    }
    IOFree(v1[49], v1[52]); /*0x19f03d*/
    return 0; /*0x19f042*/
  }
  else
  {
    IOLog(aFramebufferBog); /*0x19efe8*/
    return -1; /*0x19efed*/
  }
}
