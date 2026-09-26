/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a4730. */
int __cdecl +[IODevice driverKitVersionForDriverNamed:](id a1, SEL a2, char *__src)
{
  unsigned int v3; // kr04_4
  unsigned int v4; // kr08_4
  SEL Uid; // esi
  int v7; // esi
  char *__dst; // [esp+Ch] [ebp-Ch]
  char *__dsta; // [esp+Ch] [ebp-Ch]
  Class Class; // [esp+14h] [ebp-4h]

  v3 = strlen(__src) + 1; /*0x1a4746*/
  __dst = (char *)IOMalloc(v3 + 7); /*0x1a4755*/
  if ( !__dst ) /*0x1a475d*/
    return -1; /*0x1a475d*/
  strcpy(__dst, __src); /*0x1a4767*/
  strcat(__dst, "Version"); /*0x1a4772*/
  Class = objc_getClass(__dst); /*0x1a477d*/
  IOFree((int)__dst, v3 + 7); /*0x1a4782*/
  if ( !Class ) /*0x1a478e*/
    return -1; /*0x1a478e*/
  v4 = strlen(__src) + 1; /*0x1a479b*/
  __dsta = (char *)IOMalloc(v4 + 19); /*0x1a47aa*/
  if ( !__dsta ) /*0x1a47b2*/
    return -1; /*0x1a47b4*/
  strcpy(__dsta, "driverKitVersionFor"); /*0x1a47cc*/
  strcat(__dsta, __src); /*0x1a47d6*/
  Uid = sel_getUid(__dsta); /*0x1a47e1*/
  if ( (unsigned __int8)-[objc_class respondsTo:](Class, sel_respondsTo_, Uid) ) /*0x1a47f3*/
    v7 = (int)-[objc_class perform:](Class, sel_perform_, Uid); /*0x1a4809*/
  else
    v7 = -1; /*0x1a4810*/
  IOFree((int)__dsta, v4 + 19); /*0x1a481a*/
  return v7; /*0x1a4824*/
}
