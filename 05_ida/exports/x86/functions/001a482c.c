/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a482c. */
int __cdecl -[IODevice getIntValues:forParameter:count:](
        IODevice *self,
        SEL a2,
        unsigned int *a3,
        char *a4,
        unsigned int *a5)
{
  id v5; // eax
  unsigned int v6; // eax
  id v7; // eax
  int *v9; // [esp+Ch] [ebp-8h] BYREF
  int *v10; // [esp+10h] [ebp-4h] BYREF

  if ( !strcmp(a4, "IOUnit") ) /*0x1a4847*/
  {
    *a3 = self->_unit; /*0x1a4854*/
LABEL_10:
    *a5 = 1; /*0x1a48d3*/
    return 0; /*0x1a48de*/
  }
  if ( !strcmp(a4, "IOBlockMajor") ) /*0x1a4867*/
  {
    v5 = -[Object class](self, sel_class); /*0x1a487a*/
    if ( !sub_1A3E30((int)v5, &v10) ) /*0x1a4883*/
    {
      v6 = v10[2]; /*0x1a488f*/
LABEL_9:
      *a3 = v6; /*0x1a48ce*/
      goto LABEL_10; /*0x1a48d1*/
    }
  }
  else if ( !strcmp(a4, "IOCharacterMajor") ) /*0x1a48a3*/
  {
    v7 = -[Object class](self, sel_class); /*0x1a48b6*/
    if ( !sub_1A3E30((int)v7, &v9) ) /*0x1a48bf*/
    {
      v6 = v9[3]; /*0x1a48cb*/
      goto LABEL_9; /*0x1a48cb*/
    }
  }
  return -711; /*0x1a48e8*/
}
