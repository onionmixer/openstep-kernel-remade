/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cd92c. */
int __cdecl sub_1CD92C(char *a1, char a2)
{
  char *v2; // eax
  int v3; // ecx
  char v5; // dl

  v2 = a1; /*0x1cd934*/
  v3 = 0; /*0x1cd93d*/
  if ( *a1 ) /*0x1cd941*/
  {
    while ( 1 ) /*0x1cd948*/
    {
      if ( !v3 && *v2 == a2 ) /*0x1cd951*/
        return v2 - a1; /*0x1cd955*/
      v5 = *v2; /*0x1cd958*/
      if ( *v2 == 91 ) /*0x1cd95d*/
      {
LABEL_16:
        ++v3; /*0x1cd988*/
        goto LABEL_17; /*0x1cd988*/
      }
      if ( *v2 <= 91 ) /*0x1cd95f*/
        break; /*0x1cd95f*/
      if ( v5 == 123 ) /*0x1cd973*/
        goto LABEL_16; /*0x1cd973*/
      if ( v5 <= 123 ) /*0x1cd975*/
      {
        if ( v5 != 93 ) /*0x1cd97a*/
          goto LABEL_17; /*0x1cd97a*/
LABEL_15:
        --v3; /*0x1cd985*/
        goto LABEL_17; /*0x1cd986*/
      }
      if ( v5 == 125 ) /*0x1cd983*/
        goto LABEL_15; /*0x1cd983*/
LABEL_17:
      if ( !*++v2 ) /*0x1cd98a*/
        goto LABEL_18; /*0x1cd98d*/
    }
    if ( v5 == 40 ) /*0x1cd964*/
      goto LABEL_16; /*0x1cd964*/
    if ( v5 != 41 ) /*0x1cd969*/
      goto LABEL_17; /*0x1cd969*/
    goto LABEL_15; /*0x1cd969*/
  }
LABEL_18:
  _NXLogError("Object: SubTypeUntil: end of type encountered prematurely\n");
  return 0; /*0x1cd99e*/
}
