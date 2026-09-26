/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1af194. */
int __cdecl -[IODisplay getCharValues:forParameter:count:](
        IODisplay *self,
        SEL a2,
        char *__dst,
        char *a4,
        unsigned int *a5)
{
  id v5; // eax
  id v6; // edx
  unsigned int v7; // edi
  char *__src; // [esp+Ch] [ebp-Ch]
  objc_super v10; // [esp+10h] [ebp-8h] BYREF

  v5 = -[IODirectDevice deviceDescription](self, sel_deviceDescription); /*0x1af1b3*/
  v6 = objc_msgSend(v5, sel_configTable); /*0x1af1c3*/
  if ( v6 /*0x1af1f8*/
    && (__src = (char *)objc_msgSend(v6, sel_valueForStringKey_, a4)) != nullptr
    && (v7 = strlen(__src) + 1, *a5 >= v7) )
  {
    strcpy(__dst, __src); /*0x1af202*/
    *a5 = v7; /*0x1af207*/
    return 0; /*0x1af209*/
  }
  else
  {
    v10.receiver = self; /*0x1af21f*/
    v10.super_class = (Class)stru_1FA3D4.super_class; /*0x1af227*/
    return -[IODevice getCharValues:forParameter:count:](&v10, sel_getCharValues_forParameter_count_, __dst, a4, a5); /*0x1af22e*/
  }
}
